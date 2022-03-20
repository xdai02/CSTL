#include "cino_array.h"

/**
 * @brief cino int数组结构
 */
typedef struct array_int_t {
    int *arr;      // 数组
    int size;      // 元素个数
    int capacity;  // 容量
} array_int_t;

/****************************************
 *          cino int数组创建
 ****************************************/

/**
 * @brief   创建cino int数组
 * @return  返回构造好的cino int数组，失败返回NULL。
 */
array_int_t *array_int_create() {
    array_int_t *array = (array_int_t *)cino_alloc(sizeof(array_int_t));
    return_value_if_fail(array != NULL, NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    return array;
}

/****************************************
 *          cino int数组销毁
 ****************************************/

/**
 * @brief   销毁cino int数组
 * @param array    :   cino int数组
 */
void array_int_destroy(array_int_t *array) {
    return_if_fail(array != NULL);

    array->size = 0;
    array->capacity = 0;

    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }

    if (array) {
        free(array);
        array = NULL;
    }
}

/****************************************
 *          cino int数组操作
 ****************************************/

/**
 * @brief   判断cino int数组是否为空
 * @param array :   cino int数组
 * @return  空数组返回true，非空返回false。
 */
bool array_int_is_empty(const array_int_t *array) {
    return !array || array->size == 0;
}

/**
 * @brief   获取cino int数组元素个数
 * @param array :   cino int数组
 * @return  cino int数组元素个数
 */
int array_int_size(const array_int_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

/**
 * @brief   清空cino int数组
 * @param array :   cino int数组
 * @return  清空后的cino int数组
 */
array_int_t *array_int_clear(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }
    array->size = 0;
    array->capacity = 0;
    return array;
}

/**
 * @brief   获取cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @return  cino int数组指定下标元素
 */
int array_int_get(const array_int_t *array, int index) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return STATUS_OUT_OF_BOUNDS;
    }
    return array->arr[index];
}

/**
 * @brief   更新cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @param data  :   新元素
 */
void array_int_set(array_int_t *array, int index, int data) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return;
    }
    array->arr[index] = data;
}

/**
 * @brief   cino int数组扩容/收缩
 * @param array :   cino int数组
 * @return  返回扩容/收缩后的cino int数组。
 */
static array_int_t *array_int_resize(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);

    // 首次分配空间
    if (array->capacity == 0) {
        array->capacity = 1;
        array->arr = (int *)cino_alloc(sizeof(int) * array->capacity);
        if (!array->arr) {
            array_int_destroy(array);
            return NULL;
        }
        return array;
    }

    const int EXPANSION = 2;  // 扩容/收缩系数

    // 扩容
    if (array->size >= array->capacity) {
        array->arr = (int *)cino_realloc(array->arr, sizeof(int) * array->capacity, sizeof(int) * array->capacity * 2);
        if (!array->arr) {
            array_int_destroy(array);
            return NULL;
        }
        array->capacity *= EXPANSION;
    }
    // 收缩
    else if (array->size < array->capacity) {
        int cnt = 0;
        int capacity = array->capacity;
        while (capacity > array->size) {
            capacity /= EXPANSION;
            cnt++;
        }
        array->arr = (int *)cino_realloc(array->arr, sizeof(int) * array->capacity, sizeof(int) * capacity);
        array->capacity = capacity;
    }

    return array;
}

/**
 * @brief   cino int数组末尾追加元素
 * @param array :   cino int数组
 * @param data  :   新元素
 * @return  cino int数组
 */
array_int_t *array_int_append(array_int_t *array, int data) {
    array_int_resize(array);
    return_value_if_fail(array != NULL, NULL);
    array->arr[array->size++] = data;
    return array;
}

/**
 * @brief   cino int数组末尾追加数组
 * @param array     :   cino int数组
 * @param arr       :   追加数组
 * @param arr_len   :   追加数组元素个数
 * @return  cino int数组
 */
array_int_t *array_int_expend(array_int_t *array, int *arr, int arr_len) {
    return_value_if_fail(arr != NULL && arr_len > 0, array);
    for (int i = 0; i < arr_len; i++) {
        array_int_resize(array);
        array->arr[array->size++] = arr[i];
    }
    return array;
}

/**
 * @brief   在cino int数组指定位置插入元素
 * @param array :   cino int数组
 * @param pos   :   位置（从0开始）
 * @param data  :   新元素
 * @return  cino int数组
 */
array_int_t *array_int_insert(array_int_t *array, int pos, int data) {
    return_value_if_fail(pos >= 0 && pos <= array->size, array);

    array_int_resize(array);
    return_value_if_fail(array != NULL, NULL);

    for (int i = array->size - 1; i >= pos; i--) {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[pos] = data;
    array->size++;

    return array;
}

/**
 * @brief   删除cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @return  cino int数组
 */
array_int_t *array_int_remove(array_int_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    for (int i = index + 1; i < array->size; i++) {
        array->arr[i - 1] = array->arr[i];
    }
    array->size--;

    array_int_resize(array);
    return array;
}

/**
 * @brief   获取cino int数组最小值
 * @param array :   cino int数组
 * @return  cino int数组最小值
 */
int array_int_min(const array_int_t *array) {
    if (!array || !array->arr) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    int min = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->arr[i] < min) {
            min = array->arr[i];
        }
    }
    return min;
}

/**
 * @brief   获取cino int数组最大值
 * @param array :   cino int数组
 * @return  cino int数组最大值
 */
int array_int_max(const array_int_t *array) {
    if (!array || !array->arr) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    int max = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->arr[i] > max) {
            max = array->arr[i];
        }
    }
    return max;
}

/**
 * @brief   查找cino int数组指定元素首次出现下标
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素首次出现下标，未找到返回-1。
 */
int array_int_index_of(const array_int_t *array, int data) {
    return_value_if_fail(array != NULL, -1);
    for (int i = 0; i < array->size; i++) {
        if (array->arr[i] == data) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief   查找cino int数组指定元素最后一次出现下标
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素最后一次出现下标，未找到返回-1。
 */
int array_int_last_index_of(const array_int_t *array, int data) {
    return_value_if_fail(array != NULL, -1);
    for (int i = array->size - 1; i >= 0; i--) {
        if (array->arr[i] == data) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief   统计指定元素在cino int数组中出现次数
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素出现次数
 */
int array_int_count(const array_int_t *array, int data) {
    return_value_if_fail(array != NULL, 0);
    int cnt = 0;
    for (int i = 0; i < array->size; i++) {
        if (array->arr[i] == data) {
            cnt++;
        }
    }
    return cnt;
}

/**
 * @brief   反转cino int数组
 * @param array :   cino int数组
 * @return  反转后的cino int数组
 */
array_int_t *array_int_reverse(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);
    int i = 0;
    int j = array->size - 1;
    while (i < j) {
        swap(array->arr[i], array->arr[j], int);
        i++;
        j--;
    }
    return array;
}

/**
 * @brief   交换cino int数组中指定下标元素
 * @param array     :   cino int数组
 * @param index1    :   被交换元素下标
 * @param index2    :   被交换元素下标
 * @return  交换后的cino int数组
 */
array_int_t *array_int_swap(array_int_t *array, int index1, int index2) {
    return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
    swap(array->arr[index1], array->arr[index2], int);
    return array;
}

static int cmp_int(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa - *pb;
}

static int cmp_int_reverse(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pb - *pa;
}

/**
 * @brief   排序cino int数组
 * @param array     :   cino int数组
 * @param reverse   :   是否逆序
 * @return  排序后的cino int数组
 */
array_int_t *array_int_sort(array_int_t *array, bool reverse) {
    return_value_if_fail(array != NULL, NULL);
    if (reverse) {
        qsort(array->arr, array->size, sizeof(int), cmp_int_reverse);
    } else {
        qsort(array->arr, array->size, sizeof(int), cmp_int);
    }
    return array;
}

/****************************************
 *          cino int数组迭代器
 ****************************************/

// /****************************************
//  *              cino数组创建
//  ****************************************/

// /**
//  * @brief cino数组结构
//  */
// typedef struct array_t {
//     void **arr;     // 数组
//     int size;       // 元素个数
//     int capacity;   // 容量
//     size_t elem_size;  // 每个元素大小
// } array_t;

// /****************************************
//  *            cino数组创建
//  ****************************************/

// /**
//  * @brief   创建cino数组
//  * @param elem_size :   每个元素大小
//  * @return  返回构造好的cino数组，失败返回NULL。
//  */
// array_t *array_create(int elem_size) {
//     return_value_if_fail(elem_size > 0, NULL);
//     array_t *array = (array_t *)cino_alloc(sizeof(array_t));
//     return_value_if_fail(array != NULL, NULL);
//     array->arr = (void **)cino_alloc(sizeof(void *));
//     // TODO: call_and_return
//     array->size = 0;
//     array->capacity = 1;
//     array->elem_size = elem_size;
//     return array;
// }

// /****************************************
//  *            cino数组销毁
//  ****************************************/

// /**
//  * @brief   销毁cino数组
//  * @param array    :   cino数组
//  */
// void array_destroy(array_t *array) {
//     return_if_fail(array != NULL);

//     array->size = 0;
//     array->capacity = 0;
//     array->elem_size = 0;

//     if (array->arr) {
//         free(array->arr);
//         array->arr = NULL;
//     }

//     if (array) {
//         free(array);
//         array = NULL;
//     }
// }

// /****************************************
//  *            cino数组操作
//  ****************************************/

// /**
//  * @brief   获取cino数组元素个数
//  * @param array  :   cino数组
//  * @return  cino数组元素个数
//  */
// int array_size(const array_t *array) {
//     return_value_if_fail(array != NULL && array->arr != NULL, 0);
//     return array->size;
// }

// void *array_get(const array_t *array, int index) {
//     return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);
//     return array->arr[index];
// }

// void array_append(array_t *array, const void *data) {
//     return_if_fail(array != NULL && data != NULL);

//     // // 首次分配空间
//     // if (!array->arr) {
//     //     array->arr = cino_alloc(array->elem_size);
//     //     return_if_fail(array->arr != NULL);
//     //     array->capacity = 1;
//     // }

//     // 翻倍扩容
//     if (array->size == array->capacity) {
//         array->arr = cino_realloc(array->arr, array->capacity * sizeof(void *), array->capacity * sizeof(void *) * 2);
//         call_and_return_if_fail(array->arr != NULL, array_destroy(array));
//         array->capacity *= 2;
//     }

//     array->arr[array->size] = (void *)data;
//     array->size++;
// }