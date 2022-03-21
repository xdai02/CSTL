#include "cino_array.h"

/****************************************
 *             array_int_t
 ****************************************/

typedef struct array_int_t {
    int *arr;
    int size;
    int capacity;
} array_int_t;

/**
 * @brief   Create cino-int-array.
 * @return  Returns the pointer to cino-int-array. Returns NULL if the creation failed.
 */
array_int_t *array_int_create() {
    array_int_t *array = (array_int_t *)cino_alloc(sizeof(array_int_t));
    return_value_if_fail(array != NULL, NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    return array;
}

/**
 * @brief   Destroy cino-int-array.
 * @param array cino-int-array
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

/**
 * @brief   Determine if the cino-int-array is empty.
 * @param array cino-int-array
 * @return  Returns true if the cino-int-array is empty, otherwise retuens false.
 */
bool array_int_is_empty(const array_int_t *array) {
    return !array || array->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the number of elements in the cino-int-array.
 */
int array_int_size(const array_int_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

/**
 * @brief   Clear all the elments in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
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
 * @brief   Get the value of the indexed component in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the value of the indexed component in the cino-int-array.
 */
int array_int_get(const array_int_t *array, int index) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return STATUS_OUT_OF_BOUNDS;
    }
    return array->arr[index];
}

/**
 * @brief   Update the value of the indexed component in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @param data  new element
 */
void array_int_set(array_int_t *array, int index, int data) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return;
    }
    array->arr[index] = data;
}

/**
 * @brief   Expand and shrink the cino-int-array according to the size and capacity.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
 */
static array_int_t *array_int_resize(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;
        array->arr = (int *)cino_alloc(sizeof(int) * array->capacity);
        if (!array->arr) {
            array_int_destroy(array);
            return NULL;
        }
        return array;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        array->arr = (int *)cino_realloc(array->arr, sizeof(int) * array->capacity, sizeof(int) * array->capacity * 2);
        if (!array->arr) {
            array_int_destroy(array);
            return NULL;
        }
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size < array->capacity) {
        int cnt = 0;
        int capacity = array->capacity;
        while (capacity > array->size) {
            capacity /= EXPANSION;
            cnt++;
        }
        if (cnt > 1) {
            array->arr = (int *)cino_realloc(array->arr, sizeof(int) * array->capacity, sizeof(int) * capacity);
            array->capacity = capacity;
        }
    }

    return array;
}

/**
 * @brief   Appends the specified element to the end of the cino-int-array.
 * @param array cino-int-array
 * @param data  new element
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_append(array_int_t *array, int data) {
    array_int_resize(array);
    return_value_if_fail(array != NULL, NULL);
    array->arr[array->size++] = data;
    return array;
}

/**
 * @brief   Appends an int array to the end of the cino-int-array.
 * @param array     cino-int-array
 * @param arr       new element
 * @param arr_len   number of elements in the int array
 * @return  Returns the modified cino-int-array.
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
 * @brief   Inserts the specified element at the specified position in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_insert(array_int_t *array, int index, int data) {
    return_value_if_fail(index >= 0 && index <= array->size, array);

    array_int_resize(array);
    return_value_if_fail(array != NULL, NULL);

    for (int i = array->size - 1; i >= index; i--) {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[index] = data;
    array->size++;

    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @return  Returns the modified cino-int-array.
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
 * @brief   Get the minimum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the minimum value.
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
 * @brief   Get the maximum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the maximum value.
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
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
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
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
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
 * @brief   Count the occurrences of the specified element.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
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
 * @brief   Reverses the order of all elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
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
 * @brief   Swap two elements at specified indices in the cino-int-array.
 * @param array     cino-int-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_swap(array_int_t *array, int index1, int index2) {
    return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
    swap(array->arr[index1], array->arr[index2], int);
    return array;
}

/**
 * @brief   Specify the rules for comparing two int values in ascending order.
 * @param a pointer to the first value
 * @param b pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int cmp_int(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa - *pb;
}

/**
 * @brief   Specify the rules for comparing two int values in descending order.
 * @param a pointer to the first value
 * @param b pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is less than the second value
 *              - negative if the first value is greater than the second value
 */
static int cmp_int_reverse(const void *a, const void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pb - *pa;
}

/**
 * @brief   Sort the cino-int-array.
 * @param array     cino-int-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-int-array.
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
