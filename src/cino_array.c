#include "cino_array.h"

typedef struct iterator_t {
    void *iter;
    int iter_index;  // for generic array only
} iterator_t;

/****************************************
 *             array_int_t
 ****************************************/

typedef struct array_int_t {
    int *arr;
    size_t size;
    size_t capacity;
    iterator_t *iterator;
} array_int_t;

/**
 * @brief   Create cino-int-array.
 * @return  Returns the pointer to cino-int-array. Returns NULL if creation failed.
 */
array_int_t *array_int_create() {
    array_int_t *array = (array_int_t *)cino_alloc(sizeof(array_int_t));
    return_value_if_fail(array != NULL, NULL);
    array->iterator = (iterator_t *)cino_alloc(sizeof(iterator_t));
    call_and_return_value_if_fail(array->iterator != NULL, array_int_destroy(array), NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;  // not used in cino-int-array
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

    if (array->iterator) {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
        free(array->iterator);
        array->iterator = NULL;
    }

    if (array) {
        free(array);
        array = NULL;
    }
}

/**
 * @brief   Determine if the cino-int-array is empty.
 * @param array cino-int-array
 * @return  Returns true if the cino-int-array is empty, otherwise returns false.
 */
bool array_int_is_empty(const array_int_t *array) {
    return !array || array->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the number of elements in the cino-int-array.
 */
size_t array_int_size(const array_int_t *array) {
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
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;
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
        call_and_return_value_if_fail(array->arr != NULL, array_int_destroy(array), NULL);
        return array;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        array->arr = (int *)cino_realloc(array->arr, sizeof(int) * array->capacity, sizeof(int) * array->capacity * 2);
        call_and_return_value_if_fail(array->arr != NULL, array_int_destroy(array), NULL);
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
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
array_int_t *array_int_extend(array_int_t *array, int *arr, int arr_len) {
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
    if (!array) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    if (array->size == 0) {
        LOGGER(INFO, "Array is empty.");
        return STATUS_NOT_FOUND;
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
    if (!array) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    if (array->size == 0) {
        LOGGER(INFO, "Array is empty.");
        return STATUS_NOT_FOUND;
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
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int cmp_int_less(const void *data1, const void *data2) {
    int *p1 = (int *)data1;
    int *p2 = (int *)data2;
    return *p1 - *p2;
}

/**
 * @brief   Specify the rules for comparing two int values in descending order.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is less than the second value
 *              - negative if the first value is greater than the second value
 */
static int cmp_int_greater(const void *data1, const void *data2) {
    int *p1 = (int *)data1;
    int *p2 = (int *)data2;
    return *p2 - *p1;
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
        qsort(array->arr, array->size, sizeof(int), cmp_int_greater);
    } else {
        qsort(array->arr, array->size, sizeof(int), cmp_int_less);
    }
    return array;
}

/**
 * @brief   Get the iterator.
 * @param array cino-int-array
 * @return  Returns the iterator.
 */
iter_t array_int_iter(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->size > 0) {
        array->iterator->iter = array->arr;
    } else {
        array->iterator->iter = NULL;
    }
    return array->iterator->iter;
}

/**
 * @brief   Determine if the cino-int-array has the next iterator.
 * @param array cino-int-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_int_iter_has_next(const array_int_t *array) {
    return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);
    return (void *)((byte_t *)array->iterator->iter + sizeof(int)) < (void *)(array->arr + array->size);
}

/**
 * @brief   Get the next iterator.
 * @param array cino-int-array
 * @return  Returns the next iterator.
 */
iter_t array_int_iter_next(array_int_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array_int_iter_has_next(array)) {
        byte_t *iter = (byte_t *)array->iterator->iter;
        iter += sizeof(int);
        array->iterator->iter = (void *)iter;
    } else {
        array->iterator->iter = NULL;
    }
    return array->iterator->iter;
}

/****************************************
 *            array_double_t
 ****************************************/

typedef struct array_double_t {
    double *arr;
    size_t size;
    size_t capacity;
    iterator_t *iterator;
} array_double_t;

/**
 * @brief   Create cino-double-array.
 * @return  Returns the pointer to cino-double-array. Returns NULL if creation failed.
 */
array_double_t *array_double_create() {
    array_double_t *array = (array_double_t *)cino_alloc(sizeof(array_double_t));
    return_value_if_fail(array != NULL, NULL);
    array->iterator = (iterator_t *)cino_alloc(sizeof(iterator_t));
    call_and_return_value_if_fail(array->iterator != NULL, array_double_destroy(array), NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;  // not used in cino-double-array
    return array;
}

/**
 * @brief   Destroy cino-double-array.
 * @param array cino-double-array
 */
void array_double_destroy(array_double_t *array) {
    return_if_fail(array != NULL);

    array->size = 0;
    array->capacity = 0;

    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }

    if (array->iterator) {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
        free(array->iterator);
        array->iterator = NULL;
    }

    if (array) {
        free(array);
        array = NULL;
    }
}

/**
 * @brief   Determine if the cino-double-array is empty.
 * @param array cino-double-array
 * @return  Returns true if the cino-double-array is empty, otherwise returns false.
 */
bool array_double_is_empty(const array_double_t *array) {
    return !array || array->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the number of elements in the cino-double-array.
 */
size_t array_double_size(const array_double_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

/**
 * @brief   Clear all the elments in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_clear(array_double_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    return array;
}

/**
 * @brief   Get the value of the indexed component in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the value of the indexed component in the cino-double-array.
 */
double array_double_get(const array_double_t *array, int index) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return STATUS_OUT_OF_BOUNDS;
    }
    return array->arr[index];
}

/**
 * @brief   Update the value of the indexed component in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @param data  new element
 */
void array_double_set(array_double_t *array, int index, double data) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return;
    }
    array->arr[index] = data;
}

/**
 * @brief   Expand and shrink the cino-double-array according to the size and capacity.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
static array_double_t *array_double_resize(array_double_t *array) {
    return_value_if_fail(array != NULL, NULL);

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;
        array->arr = (double *)cino_alloc(sizeof(double) * array->capacity);
        call_and_return_value_if_fail(array->arr != NULL, array_double_destroy(array), NULL);
        return array;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        array->arr = (double *)cino_realloc(array->arr, sizeof(double) * array->capacity, sizeof(double) * array->capacity * 2);
        call_and_return_value_if_fail(array->arr != NULL, array_double_destroy(array), NULL);
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
            array->arr = (double *)cino_realloc(array->arr, sizeof(double) * array->capacity, sizeof(double) * capacity);
            array->capacity = capacity;
        }
    }

    return array;
}

/**
 * @brief   Appends the specified element to the end of the cino-double-array.
 * @param array cino-double-array
 * @param data  new element
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_append(array_double_t *array, double data) {
    array_double_resize(array);
    return_value_if_fail(array != NULL, NULL);
    array->arr[array->size++] = data;
    return array;
}

/**
 * @brief   Appends an double array to the end of the cino-double-array.
 * @param array     cino-double-array
 * @param arr       new element
 * @param arr_len   number of elements in the double array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_extend(array_double_t *array, double *arr, int arr_len) {
    return_value_if_fail(arr != NULL && arr_len > 0, array);
    for (int i = 0; i < arr_len; i++) {
        array_double_resize(array);
        array->arr[array->size++] = arr[i];
    }
    return array;
}

/**
 * @brief   Inserts the specified element at the specified position in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_insert(array_double_t *array, int index, double data) {
    return_value_if_fail(index >= 0 && index <= array->size, array);

    array_double_resize(array);
    return_value_if_fail(array != NULL, NULL);

    for (int i = array->size - 1; i >= index; i--) {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[index] = data;
    array->size++;

    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_remove(array_double_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    for (int i = index + 1; i < array->size; i++) {
        array->arr[i - 1] = array->arr[i];
    }
    array->size--;

    array_double_resize(array);
    return array;
}

/**
 * @brief   Get the minimum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the minimum value.
 */
double array_double_min(const array_double_t *array) {
    if (!array) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    if (array->size == 0) {
        LOGGER(INFO, "Array is empty.");
        return STATUS_NOT_FOUND;
    }
    double min = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->arr[i] < min) {
            min = array->arr[i];
        }
    }
    return min;
}

/**
 * @brief   Get the maximum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the maximum value.
 */
double array_double_max(const array_double_t *array) {
    if (!array) {
        LOGGER(ERROR, "Access to null object.");
        return STATUS_BAD_PARAMETERS;
    }
    if (array->size == 0) {
        LOGGER(INFO, "Array is empty.");
        return STATUS_NOT_FOUND;
    }
    double max = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->arr[i] > max) {
            max = array->arr[i];
        }
    }
    return max;
}

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_index_of(const array_double_t *array, double data) {
    return_value_if_fail(array != NULL, -1);
    for (int i = 0; i < array->size; i++) {
        if (equal_double(array->arr[i], data)) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_last_index_of(const array_double_t *array, double data) {
    return_value_if_fail(array != NULL, -1);
    for (int i = array->size - 1; i >= 0; i--) {
        if (equal_double(array->arr[i], data)) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief   Count the occurrences of the specified element.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
 */
int array_double_count(const array_double_t *array, double data) {
    return_value_if_fail(array != NULL, 0);
    int cnt = 0;
    for (int i = 0; i < array->size; i++) {
        if (equal_double(array->arr[i], data)) {
            cnt++;
        }
    }
    return cnt;
}

/**
 * @brief   Reverses the order of all elements in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_reverse(array_double_t *array) {
    return_value_if_fail(array != NULL, NULL);
    int i = 0;
    int j = array->size - 1;
    while (i < j) {
        swap(array->arr[i], array->arr[j], double);
        i++;
        j--;
    }
    return array;
}

/**
 * @brief   Swap two elements at specified indices in the cino-double-array.
 * @param array     cino-double-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_swap(array_double_t *array, int index1, int index2) {
    return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
    swap(array->arr[index1], array->arr[index2], double);
    return array;
}

/**
 * @brief   Specify the rules for comparing two double values in ascending order.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int cmp_double_less(const void *data1, const void *data2) {
    double *p1 = (double *)data1;
    double *p2 = (double *)data2;
    return *p1 > *p2 ? 1 : -1;
}

/**
 * @brief   Specify the rules for comparing two double values in descending order.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is less than the second value
 *              - negative if the first value is greater than the second value
 */
static int cmp_double_greater(const void *data1, const void *data2) {
    double *p1 = (double *)data1;
    double *p2 = (double *)data2;
    return *p2 > *p1 ? 1 : -1;
}

/**
 * @brief   Sort the cino-double-array.
 * @param array     cino-double-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_sort(array_double_t *array, bool reverse) {
    return_value_if_fail(array != NULL, NULL);
    if (reverse) {
        qsort(array->arr, array->size, sizeof(double), cmp_double_greater);
    } else {
        qsort(array->arr, array->size, sizeof(double), cmp_double_less);
    }
    return array;
}

/**
 * @brief   Get the iterator.
 * @param array cino-double-array
 * @return  Returns the iterator.
 */
iter_t array_double_iter(array_double_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->size > 0) {
        array->iterator->iter = array->arr;
    } else {
        array->iterator->iter = NULL;
    }
    return array->iterator->iter;
}

/**
 * @brief   Determine if the cino-double-array has the next iterator.
 * @param array cino-double-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_double_iter_has_next(const array_double_t *array) {
    return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);
    return (void *)((byte_t *)array->iterator->iter + sizeof(double)) < (void *)(array->arr + array->size);
}

/**
 * @brief   Get the next iterator.
 * @param array cino-double-array
 * @return  Returns the next iterator.
 */
iter_t array_double_iter_next(array_double_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array_double_iter_has_next(array)) {
        byte_t *iter = (byte_t *)array->iterator->iter;
        iter += sizeof(double);
        array->iterator->iter = (void *)iter;
    } else {
        array->iterator->iter = NULL;
    }
    return array->iterator->iter;
}

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t {
    void **arr;
    size_t size;
    size_t capacity;
    iterator_t *iterator;
} array_t;

/**
 * @brief   Create cino-array.
 * @return  Returns the pointer to cino-array. Returns NULL if creation failed.
 */
array_t *array_create() {
    array_t *array = (array_t *)cino_alloc(sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);
    array->iterator = (iterator_t *)cino_alloc(sizeof(iterator_t));
    call_and_return_value_if_fail(array->iterator != NULL, array_destroy(array), NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;
    return array;
}

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before
 *          calling this function.
 * @param array cino-array
 */
void array_destroy(array_t *array) {
    return_if_fail(array != NULL);

    array->size = 0;
    array->capacity = 0;

    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }

    if (array->iterator) {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
        free(array->iterator);
        array->iterator = NULL;
    }

    if (array) {
        free(array);
        array = NULL;
    }
}

/**
 * @brief   Determine if the cino-array is empty.
 * @param array cino-array
 * @return  Returns true if the cino-array is empty, otherwise returns false.
 */
bool array_is_empty(const array_t *array) {
    return !array || array->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-array.
 * @param array cino-array
 * @return  Returns the number of elements in the cino-array.
 */
size_t array_size(const array_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

/**
 * @brief   Clear all the elments in the cino-array.
 * @note    This function just removes all the elements from the cino-array.It is
 *          caller's responsibility to free the removed elements.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;
    return array;
}

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @param array cino-array
 * @return  Returns a pointer to the indexed component in the cino-array.
 */
void *array_get(const array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);
    return array->arr[index];
}

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @note    It is caller's responsibility to free the previous data before
 *          overwriting it.
 * @param array cino-array
 * @param index index
 * @param data  new element
 */
void array_set(array_t *array, int index, void *data) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return;
    }
    array->arr[index] = data;
}

/**
 * @brief   Expand and shrink the cino-array according to the size and capacity.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
static array_t *array_resize(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;
        array->arr = (void **)cino_alloc(sizeof(void *) * array->capacity);
        call_and_return_value_if_fail(array->arr != NULL, array_destroy(array), NULL);
        return array;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        array->arr = (void **)cino_realloc(array->arr, sizeof(void *) * array->capacity, sizeof(void *) * array->capacity * 2);
        call_and_return_value_if_fail(array->arr != NULL, array_destroy(array), NULL);
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
            array->arr = (void **)cino_realloc(array->arr, sizeof(void *) * array->capacity, sizeof(void *) * capacity);
            array->capacity = capacity;
        }
    }

    return array;
}

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @note    It is caller's responsibility to make sure that the inserted element
 *          is on the heap.
 * @param array cino-array
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, void *data) {
    array_resize(array);
    return_value_if_fail(array != NULL, NULL);
    array->arr[array->size++] = data;
    return array;
}

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @note    It is caller's responsibility to make sure that the inserted element
 *          is on the heap.
 * @param array cino-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, void *data) {
    return_value_if_fail(index >= 0 && index <= array->size, array);

    array_resize(array);
    return_value_if_fail(array != NULL, NULL);

    for (int i = array->size - 1; i >= index; i--) {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[index] = data;
    array->size++;

    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @note    This function just removes the element from the cino-array.It is
 *          caller's responsibility to free the removed element.
 * @param array cino-array
 * @param index index
 * @return  Returns the modified cino-array.
 */
array_t *array_remove(array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    for (int i = index + 1; i < array->size; i++) {
        array->arr[i - 1] = array->arr[i];
    }
    array->size--;

    array_resize(array);
    return array;
}

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the minimum value.
 */
void *array_min(const array_t *array, compare_t cmp) {
    return_value_if_fail(array != NULL && cmp != NULL, NULL);

    if (array->size == 0) {
        return NULL;
    }

    void *min = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (cmp(array->arr[i], min) < 0) {
            min = array->arr[i];
        }
    }

    return min;
}

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the maximum value.
 */
void *array_max(const array_t *array, compare_t cmp) {
    return_value_if_fail(array != NULL && cmp != NULL, NULL);

    if (array->size == 0) {
        return NULL;
    }

    void *max = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (cmp(array->arr[i], max) > 0) {
            max = array->arr[i];
        }
    }

    return max;
}

/**
 * @brief   Find the first element that satisfies the comparison strategy.
 * @param array cino-array
 * @param match user-defined callback function for matching
 * @return  Returns the found element, or NULL if not found.
 */
void *array_find(const array_t *array, match_t match) {
    return_value_if_fail(array != NULL && match != NULL, NULL);
    for (int i = 0; i < array->size; i++) {
        if (match(array->arr[i])) {
            return array->arr[i];
        }
    }
    return NULL;
}

/**
 * @brief   Count the occurrences of the element matched.
 * @param array cino-array
 * @param match user-defined callback function for matching
 * @return  Returns occurrences of the element matched.
 */
int array_count(const array_t *array, match_t match) {
    return_value_if_fail(array != NULL && match != NULL, 0);
    int cnt = 0;
    for (int i = 0; i < array->size; i++) {
        if (match(array->arr[i])) {
            cnt++;
        }
    }
    return cnt;
}

/**
 * @brief   Reverses the order of all elements in the cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_reverse(array_t *array) {
    return_value_if_fail(array != NULL, NULL);
    int i = 0;
    int j = array->size - 1;
    while (i < j) {
        swap(array->arr[i], array->arr[j], void *);
        i++;
        j--;
    }
    return array;
}

/**
 * @brief   Swap two elements at specified indices in the cino-array.
 * @param array     cino-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-array.
 */
array_t *array_swap(array_t *array, int index1, int index2) {
    return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
    swap(array->arr[index1], array->arr[index2], void *);
    return array;
}

/**
 * @brief   Parition function for quick sort.
 * @param arr   an array of pointers
 * @param start start index of partition
 * @param end   end index of partition
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the index of the pivot.
 */
static int quick_sort_partition(void **arr, int start, int end, compare_t cmp) {
    int i = start - 1;
    void *pivot = arr[end];

    for (int j = start; j < end; j++) {
        if (cmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j], void *);
        }
    }

    swap(arr[i + 1], arr[end], void *);
    return i + 1;
}

/**
 * @brief   Stack-based quick sort for cino-array.
 * @param arr   an array of pointers
 * @param size  number of elements in the array
 * @param cmp   user-defined callback function for comparison
 */
static void quick_sort(void **arr, size_t size, compare_t cmp) {
    int stack[size];
    memset(stack, 0x00, size * sizeof(int));

    int n = 0;
    stack[n++] = 0;
    stack[n++] = size - 1;

    while (n > 0) {
        int right = stack[--n];
        int left = stack[--n];

        int index = quick_sort_partition(arr, left, right, cmp);
        if (index - 1 > left) {
            stack[n++] = left;
            stack[n++] = index - 1;
        }
        if (index + 1 < right) {
            stack[n++] = index + 1;
            stack[n++] = right;
        }
    }
}

/**
 * @brief   Sort the cino-array.
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the modified cino-array.
 */
array_t *array_sort(array_t *array, compare_t cmp) {
    return_value_if_fail(array != NULL, NULL);
    quick_sort(array->arr, array->size, cmp);
    return array;
}

/**
 * @brief   Get the iterator.
 * @param array cino-array
 * @return  Returns the iterator.
 */
iter_t array_iter(array_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array->size > 0) {
        array->iterator->iter = array->arr[0];
        array->iterator->iter_index = 0;
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }
    return array->iterator->iter;
}

/**
 * @brief   Determine if the cino-array has the next iterator.
 * @param array cino-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_iter_has_next(const array_t *array) {
    return_value_if_fail(array != NULL && array->iterator->iter != NULL && array->iterator->iter_index >= 0, false);
    return array->iterator->iter_index + 1 < array->size;
}

/**
 * @brief   Get the next iterator.
 * @param array cino-array
 * @return  Returns the next iterator.
 */
iter_t array_iter_next(array_t *array) {
    return_value_if_fail(array != NULL, NULL);
    if (array_iter_has_next(array)) {
        array->iterator->iter_index++;
        array->iterator->iter = array->arr[array->iterator->iter_index];
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }
    return array->iterator->iter;
}