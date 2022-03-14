#include "cino_array.h"

/**
 * @brief cino数组结构
 */
typedef struct cino_array_t {
    void *arr;      // 数组
    int size;       // 元素个数
    int capacity;   // 容量
    int elem_size;  // 每个元素大小
} cino_array_t;

/****************************************
 *            cino数组创建
 ****************************************/

/**
 * @brief   创建cino数组
 * @param elem_size :   每个元素大小
 * @return  返回构造好的cino数组，失败返回NULL。
 */
cino_array_t *cino_array_create(int elem_size) {
    return_value_if_fail(elem_size > 0, NULL);
    cino_array_t *array = (cino_array_t *)cino_alloc(sizeof(cino_array_t));
    return_value_if_fail(array != NULL, NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->elem_size = elem_size;
    return array;
}

/****************************************
 *            cino数组销毁
 ****************************************/

/**
 * @brief   销毁cino数组
 * @param array    :   cino数组
 */
void cino_array_destroy(cino_array_t *array) {
    return_if_fail(array != NULL);

    array->size = 0;
    array->capacity = 0;
    array->elem_size = 0;

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
 *            cino数组操作
 ****************************************/

/**
 * @brief   获取cino数组元素个数
 * @param string    :   cino数组
 * @return  cino数组元素个数
 */
int cino_array_size(const cino_array_t *array) {
    return_value_if_fail(array != NULL && array->arr != NULL, 0);
    return array->size;
}

void cino_array_append(cino_array_t *array, void *data) {
    return_if_fail(array != NULL && data != NULL);

    // 首次分配空间
    if (!array->arr) {
        array->arr = cino_alloc(array->elem_size);
        return_if_fail(array->arr != NULL);
        array->capacity = 1;
    }

    // 翻倍扩容
    if (array->size == array->capacity) {
        array->arr = cino_realloc(array->arr, array->capacity * array->elem_size, array->capacity * array->elem_size * 2);
        call_and_return_if_fail(array->arr != NULL, cino_array_destroy(array));
        array->capacity *= 2;
    }

    array->arr[arr->size] = data;
    arr->size++;
}