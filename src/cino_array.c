#include "cino_array.h"

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t {
    T *arr;
    data_type_t data_type;
    size_t size;
    size_t capacity;
    compare_t compare;
    destroy_t destroy;
} array_t;

/**
 * @brief   Create cino-array.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
 * @return  Returns the pointer to cino-array, or `NULL` if creation failed.
 */
array_t *array_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    array_t *array = (array_t *)calloc(1, sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);
    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;

    array->data_type = data_type;
    array->compare = compare ? compare : compare_default;
    array->destroy = destroy ? destroy : destroy_default;

    return array;
}

/**
 * @brief   Destroy cino-array.
 * @param array cino-array
 */
void array_destroy(array_t *array) {
    return_if_fail(array != NULL);

    array_clear(array);

    array->compare = NULL;
    array->destroy = NULL;

    if (array) {
        free(array);
        array = NULL;
    }
}

/**
 * @brief   Determine if the cino-array is empty.
 * @param array cino-array
 * @return  Returns `true` if the cino-array is empty, otherwise returns `false`.
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
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    array_foreach(array, array->destroy, false);
    array->size = 0;
    array->capacity = 0;

    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }

    return array;
}

/**
 * @brief   Traverse cino-array.
 * @param array     cino-array
 * @param visit     user-defined callback function for visiting a single element
 * @param reverse   true = backward, false = forward
 */
void array_foreach(array_t *array, visit_t visit, bool backward) {
    return_if_fail(array != NULL && visit != NULL);

    if (!backward) {
        for (int i = 0; i < array->size; i++) {
            visit(array->arr[i]);
        }
    } else {
        for (int i = array->size - 1; i >= 0; i--) {
            visit(array->arr[i]);
        }
    }
}

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive elements, this function returns a wrapper type of the
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T array_get(const array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);
    return array->arr[index];
}

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 */
void array_set(array_t *array, int index, T data) {
    return_if_fail(array != NULL && index >= 0 && index < array->size && data != NULL);
    array->destroy(array->arr[index]);
    array->arr[index] = data;
}

/**
 * @brief   Expand or shrink the cino-array according to the size and capacity.
 * @param array cino-array
 * @return  Returns the status of resize:
 *              - STATUS_OK             : expand or shrink succeed
 *              - STATUS_BAD_PARAMETERS : invalid parameters
 *              - STATUS_OUT_OF_MEMORY  : memory allocation failed
 */
static status_t array_resize(array_t *array) {
    return_value_if_fail(array != NULL, STATUS_BAD_PARAMETERS);

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;
        array->arr = calloc(array->capacity, sizeof(T));
        return_value_if_fail(array->arr != NULL, STATUS_OUT_OF_MEMORY);
        return STATUS_OK;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        void *p = realloc(array->arr, sizeof(T) * array->capacity * EXPANSION);
        return_value_if_fail(p != NULL, STATUS_OUT_OF_MEMORY);
        array->arr = p;
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
            array->arr = realloc(array->arr, sizeof(T) * capacity);
            array->capacity = capacity;
        }
    }

    return STATUS_OK;
}

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @param array cino-array
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, T data) {
    return_value_if_fail(array != NULL && data != NULL, array);
    status_t status = array_resize(array);
    return_value_if_fail(status == STATUS_OK, array);
    array->arr[array->size++] = data;
    return array;
}

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, T data) {
    return_value_if_fail(array != NULL && index >= 0 && index <= array->size && data != NULL, array);

    status_t status = array_resize(array);
    return_value_if_fail(status == STATUS_OK, array);

    for (int i = array->size - 1; i >= index; i--) {
        array->arr[i + 1] = array->arr[i];
    }

    array->arr[index] = data;
    array->size++;

    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive cino-array, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T array_remove(array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    T removed = array->arr[index];
    for (int i = index + 1; i < array->size; i++) {
        array->arr[i - 1] = array->arr[i];
    }

    array->size--;
    array_resize(array);

    return removed;
}

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array cino-array
 * @return  Returns the minimum value in the cino-array, or `NULL` if the cino-array
 *          is empty.
 *          For primitive cino-array, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T array_min(const array_t *array) {
    return_value_if_fail(array != NULL && array->size > 0, NULL);

    T min = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->compare(array->arr[i], min) < 0) {
            min = array->arr[i];
        }
    }
    return min;
}

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array cino-array
 * @return  Returns the maximum value in the cino-array, or `NULL` if the cino-array
 *          is empty.
 *          For primitive cino-array, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T array_max(const array_t *array) {
    return_value_if_fail(array != NULL && array->size > 0, NULL);

    T max = array->arr[0];
    for (int i = 1; i < array->size; i++) {
        if (array->compare(array->arr[i], max) > 0) {
            max = array->arr[i];
        }
    }
    return max;
}

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-array.
 * @param array     cino-array
 * @param context   - For primitive cino-array, a wrapper type of the searching data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-array, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-array, or `-1` if not found.
 */
int array_index_of(const array_t *array, void *context) {
    return_value_if_fail(array != NULL && context != NULL, -1);

    int index = -1;
    int i = 0;

    if (array->data_type == DATA_TYPE_T) {
        for (i = 0; i < array->size; i++) {
            match_t match = (match_t)context;
            if (match(array->arr[i])) {
                index = i;
                break;
            }
        }
    } else {
        for (i = 0; i < array->size; i++) {
            if (array->compare(array->arr[i], context) == 0) {
                index = i;
                break;
            }
        }
        array->destroy(context);
    }

    return index;
}

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-array.
 * @param array     cino-array
 * @param context   - For primitive cino-array, a wrapper type of the searching data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-array, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-array, or `-1` if not found.
 */
int array_last_index_of(const array_t *array, void *context) {
    return_value_if_fail(array != NULL && context != NULL, -1);

    int index = -1;
    int i = 0;

    if (array->data_type == DATA_TYPE_T) {
        for (i = array->size - 1; i >= 0; i--) {
            match_t match = (match_t)context;
            if (match(array->arr[i])) {
                index = i;
                break;
            }
        }
    } else {
        for (i = array->size - 1; i >= 0; i--) {
            if (array->compare(array->arr[i], context) == 0) {
                index = i;
                break;
            }
        }
        array->destroy(context);
    }

    return index;
}

/**
 * @brief   Count the occurrences of the element matched.
 * @param array     cino-array
 * @param context   - For primitive cino-array, a wrapper type of the counting data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-array, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns occurrences of the element matched.
 */
int array_count(const array_t *array, void *context) {
    return_value_if_fail(array != NULL && context != NULL, 0);

    int cnt = 0;

    if (array->data_type == DATA_TYPE_T) {
        for (int i = array->size - 1; i >= 0; i--) {
            match_t match = (match_t)context;
            if (match(array->arr[i])) {
                cnt++;
            }
        }
    } else {
        for (int i = array->size - 1; i >= 0; i--) {
            if (array->compare(array->arr[i], context) == 0) {
                cnt++;
            }
        }
        array->destroy(context);
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
        swap(array->arr[i], array->arr[j], T);
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
    swap(array->arr[index1], array->arr[index2], T);
    return array;
}

/**
 * @brief   Parition function for quick sort.
 * @param arr       an array of pointers
 * @param start     start index of partition
 * @param end       end index of partition
 * @param compare   user-defined callback function for comparison
 * @return  Returns the index of the pivot.
 */
static int quick_sort_partition(T *arr, int start, int end, compare_t compare) {
    int i = start - 1;
    T pivot = arr[end];

    for (int j = start; j < end; j++) {
        if (compare(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j], T);
        }
    }

    swap(arr[i + 1], arr[end], T);
    return i + 1;
}

/**
 * @brief   Stack-based quick sort for cino-array.
 * @param arr       an array of pointers
 * @param size      number of elements in the array
 * @param compare   user-defined callback function for comparison
 */
static void quick_sort(T *arr, size_t size, compare_t compare) {
    int stack[size];
    memset(stack, 0x00, size * sizeof(int));

    int n = 0;
    stack[n++] = 0;
    stack[n++] = size - 1;

    while (n > 0) {
        int right = stack[--n];
        int left = stack[--n];

        int index = quick_sort_partition(arr, left, right, compare);
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
 * @param array     cino-array
 * @param reverse   true = descending, false = ascending
 * @return  Returns the modified cino-array.
 */
array_t *array_sort(array_t *array, bool reverse) {
    return_value_if_fail(array != NULL, NULL);
    quick_sort(array->arr, array->size, array->compare);
    if (reverse) {
        array_reverse(array);
    }
    return array;
}