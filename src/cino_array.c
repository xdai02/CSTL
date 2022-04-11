#include "cino_array.h"

/****************************************
 *               Iterator
 ****************************************/

typedef struct iterator_t {
    iter_t iter;     // points to the current element
    int iter_index;  // generic array use only
} iterator_t;

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t {
    T arr;
    str_t data_type;
    size_t size;
    size_t capacity;
    compare_t compare;
    iterator_t *iterator;
} array_t;

/**
 * @brief   Determine if the data type is support by cino-array.
 * @param data_type data type
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - T (generic)
 * @return  Returns the `true` if it is valid, otherwise returns `false`.
 */
static bool is_valid_data_type(const str_t data_type) {
    return_value_if_fail(data_type != NULL, false);

    const str_t data_types[] = {
        "int",
        "double",
        "T",  // generic
    };

    int data_types_len = array_len(data_types);
    for (int i = 0; i < data_types_len; i++) {
        if (str_equal(data_types[i], data_type)) {
            return true;
        }
    }
    return false;
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
static int cmp_int_asc(const T data1, const T data2) {
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
static int cmp_int_desc(const T data1, const T data2) {
    int *p1 = (int *)data1;
    int *p2 = (int *)data2;
    return *p2 - *p1;
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
static int cmp_double_asc(const T data1, const T data2) {
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
static int cmp_double_desc(const T data1, const T data2) {
    double *p1 = (double *)data1;
    double *p2 = (double *)data2;
    return *p2 > *p1 ? 1 : -1;
}

/**
 * @brief   Specify the default rules for comparing two values in ascending order.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int cmp_default(const T data1, const T data2) {
    return (byte_t *)data1 - (byte_t *)data2;
}

/**
 * @brief   Create cino-array.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-array. Set to `NULL` if it is a primitive cino-array.
 * @return  Returns the pointer to cino-array, or `NULL` if creation failed.
 */
array_t *array_create(const str_t data_type, compare_t compare) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    array_t *array = (array_t *)calloc(1, sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);

    array->iterator = (iterator_t *)calloc(1, sizeof(iterator_t));
    call_and_return_value_if_fail(array->iterator != NULL, array_destroy(array), NULL);

    array->data_type = (str_t)calloc(str_length(data_type) + 1, sizeof(char));
    call_and_return_value_if_fail(array->data_type != NULL, array_destroy(array), NULL);
    str_copy(array->data_type, data_type);

    if (!compare) {
        compare = cmp_default;
    }
    array->compare = compare;

    array->arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;

    return array;
}

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-array.
 * @param array cino-array
 */
void array_destroy(array_t *array) {
    return_if_fail(array != NULL);

    array->size = 0;
    array->capacity = 0;

    if (array->data_type) {
        free(array->data_type);
        array->data_type = NULL;
    }

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
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array->arr) {
        free(array->arr);
        array->arr = NULL;
    }

    if (array->iterator) {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }

    array->size = 0;
    array->capacity = 0;

    return array;
}

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive cino-array, this function returns a wrapper type of the
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T array_get(const array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);

    T data = NULL;

    if (str_equal(array->data_type, "int")) {
        int *arr = (int *)array->arr;
        data = (T)wrap_int(arr[index]);
    } else if (str_equal(array->data_type, "double")) {
        double *arr = (double *)array->arr;
        data = (T)wrap_double(arr[index]);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        data = (T)arr[index];
    }

    return data;
}

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-array, it is caller's responsibility to free
 *              the previous data before overwriting it.
 */
void array_set(array_t *array, int index, T data) {
    return_if_fail(array != NULL && index >= 0 && index < array->size && data != NULL);

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        int *arr = (int *)array->arr;
        arr[index] = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        double *arr = (double *)array->arr;
        arr[index] = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        arr[index] = data;
    }
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

    T p = NULL;

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;

        if (str_equal(array->data_type, "int")) {
            array->arr = calloc(array->capacity, sizeof(int));
        } else if (str_equal(array->data_type, "double")) {
            array->arr = calloc(array->capacity, sizeof(double));
        } else if (str_equal(array->data_type, "T")) {
            array->arr = calloc(array->capacity, sizeof(T));
        }

        return_value_if_fail(array->arr != NULL, STATUS_OUT_OF_MEMORY);
        return STATUS_OK;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        if (str_equal(array->data_type, "int")) {
            p = realloc(array->arr, sizeof(int) * array->capacity * EXPANSION);
        } else if (str_equal(array->data_type, "double")) {
            p = realloc(array->arr, sizeof(double) * array->capacity * EXPANSION);
        } else if (str_equal(array->data_type, "T")) {
            p = realloc(array->arr, sizeof(T) * array->capacity * EXPANSION);
        }

        return_value_if_fail(p != NULL, STATUS_OUT_OF_MEMORY);
        array->arr = p;
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
            if (str_equal(array->data_type, "int")) {
                array->arr = realloc(array->arr, sizeof(int) * capacity);
            } else if (str_equal(array->data_type, "double")) {
                array->arr = realloc(array->arr, sizeof(double) * capacity);
            } else if (str_equal(array->data_type, "T")) {
                array->arr = realloc(array->arr, sizeof(T) * capacity);
            }
            array->capacity = capacity;
        }
    }

    return STATUS_OK;
}

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @param array cino-array
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-array, it is caller's responsibility to free
 *              the previous data before overwriting it.
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, T data) {
    return_value_if_fail(array != NULL && data != NULL, array);

    status_t status = array_resize(array);
    return_value_if_fail(status == STATUS_OK, array);

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        int *arr = (int *)array->arr;
        arr[array->size++] = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        double *arr = (double *)array->arr;
        arr[array->size++] = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        arr[array->size++] = data;
    }

    return array;
}

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-array, it is caller's responsibility to free
 *              the previous data before overwriting it.
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, T data) {
    return_value_if_fail(array != NULL && index >= 0 && index <= array->size && data != NULL, array);

    status_t status = array_resize(array);
    return_value_if_fail(status == STATUS_OK, array);

    for (int i = array->size - 1; i >= index; i--) {
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            arr[i + 1] = arr[i];
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            arr[i + 1] = arr[i];
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            arr[i + 1] = arr[i];
        }
    }

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        int *arr = (int *)array->arr;
        arr[index] = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        double *arr = (double *)array->arr;
        arr[index] = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        arr[index] = data;
    }

    array->size++;
    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive cino-array, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T array_remove(array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    T removed = NULL;

    if (str_equal(array->data_type, "int")) {
        int *arr = (int *)array->arr;
        wrapper_int_t *wrapper_int = wrap_int(arr[index]);
        removed = (T)wrapper_int;
    } else if (str_equal(array->data_type, "double")) {
        double *arr = (double *)array->arr;
        wrapper_double_t *wrapper_double = wrap_double(arr[index]);
        removed = (T)wrapper_double;
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        removed = (T)arr[index];
    }

    for (int i = index + 1; i < array->size; i++) {
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            arr[i - 1] = arr[i];
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            arr[i - 1] = arr[i];
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            arr[i - 1] = arr[i];
        }
    }

    array->size--;
    array_resize(array);

    return removed;
}

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array cino-array
 * @return  Returns the minimum value in the cino-array, or `NULL` if conditions failed.
 *          For primitive cino-array, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T array_min(const array_t *array) {
    return_value_if_fail(array != NULL && array->size > 0, NULL);

    T min = NULL;

    if (str_equal(array->data_type, "int")) {
        int *arr = (int *)array->arr;
        int min_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }
        min = (T)wrap_int(min_val);
    } else if (str_equal(array->data_type, "double")) {
        double *arr = (double *)array->arr;
        double min_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }
        min = (T)wrap_double(min_val);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        T min_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->compare(arr[i], min_val) < 0) {
                min_val = arr[i];
            }
        }
        min = min_val;
    }

    return min;
}

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array cino-array
 * @return  Returns the maximum value in the cino-array, or `NULL` if conditions failed.
 *          For primitive cino-array, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T array_max(const array_t *array) {
    return_value_if_fail(array != NULL && array->size > 0, NULL);

    T max = NULL;

    if (str_equal(array->data_type, "int")) {
        int *arr = (int *)array->arr;
        int max_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        max = (T)wrap_int(max_val);
    } else if (str_equal(array->data_type, "double")) {
        double *arr = (double *)array->arr;
        double max_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        max = (T)wrap_double(max_val);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        T max_val = arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->compare(arr[i], max_val) > 0) {
                max_val = arr[i];
            }
        }
        max = max_val;
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

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;

    if (str_equal(array->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)context;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)context;
    }

    for (int i = 0; i < array->size; i++) {
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            if (arr[i] == wrapper_int->data) {
                index = i;
                break;
            }
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            if (equal_double(arr[i], wrapper_double->data)) {
                index = i;
                break;
            }
        } else if (str_equal(array->data_type, "T")) {
            match_t match = (match_t)context;
            void **arr = (void **)array->arr;
            if (match(arr[i])) {
                index = i;
                break;
            }
        }
    }

    if (str_equal(array->data_type, "int")) {
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        unwrap_double(wrapper_double);
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

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;

    if (str_equal(array->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)context;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)context;
    }

    for (int i = array->size - 1; i >= 0; i--) {
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            if (arr[i] == wrapper_int->data) {
                index = i;
                break;
            }
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            if (equal_double(arr[i], wrapper_double->data)) {
                index = i;
                break;
            }
        } else if (str_equal(array->data_type, "T")) {
            match_t match = (match_t)context;
            void **arr = (void **)array->arr;
            if (match(arr[i])) {
                index = i;
                break;
            }
        }
    }

    if (str_equal(array->data_type, "int")) {
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        unwrap_double(wrapper_double);
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

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;

    if (str_equal(array->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)context;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)context;
    }

    for (int i = 0; i < array->size; i++) {
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            if (arr[i] == wrapper_int->data) {
                cnt++;
            }
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            if (equal_double(arr[i], wrapper_double->data)) {
                cnt++;
            }
        } else if (str_equal(array->data_type, "T")) {
            match_t match = (match_t)context;
            void **arr = (void **)array->arr;
            if (match(arr[i])) {
                cnt++;
            }
        }
    }

    if (str_equal(array->data_type, "int")) {
        unwrap_int(wrapper_int);
    } else if (str_equal(array->data_type, "double")) {
        unwrap_double(wrapper_double);
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
        if (str_equal(array->data_type, "int")) {
            int *arr = (int *)array->arr;
            swap(arr[i], arr[j], int);
        } else if (str_equal(array->data_type, "double")) {
            double *arr = (double *)array->arr;
            swap(arr[i], arr[j], double);
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            swap(arr[i], arr[j], T);
        }
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

    if (str_equal(array->data_type, "int")) {
        int *arr = (int *)array->arr;
        swap(arr[index1], arr[index2], int);
    } else if (str_equal(array->data_type, "double")) {
        double *arr = (double *)array->arr;
        swap(arr[index1], arr[index2], double);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        swap(arr[index1], arr[index2], T);
    }

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

    if (str_equal(array->data_type, "int")) {
        qsort(array->arr, array->size, sizeof(int), reverse ? cmp_int_desc : cmp_int_asc);
    } else if (str_equal(array->data_type, "double")) {
        qsort(array->arr, array->size, sizeof(double), reverse ? cmp_double_desc : cmp_double_asc);
    } else if (str_equal(array->data_type, "T")) {
        void **arr = (void **)array->arr;
        quick_sort(arr, array->size, array->compare);
        if (reverse) {
            array_reverse(array);
        }
    }

    return array;
}

/**
 * @brief   Get the begin iterator.
 * @param array cino-array
 * @return  Returns the begin iterator.
 */
iter_t array_iter_begin(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array->size > 0) {
        if (str_equal(array->data_type, "int") || str_equal(array->data_type, "double")) {
            array->iterator->iter = array->arr;
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            array->iterator->iter = arr[0];
            array->iterator->iter_index = 0;
        }
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }

    return array->iterator->iter;
}

/**
 * @brief   Get the end iterator.
 * @param array cino-array
 * @return  Returns the end iterator.
 */
iter_t array_iter_end(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array->size > 0) {
        if (str_equal(array->data_type, "int")) {
            array->iterator->iter = (iter_t)((byte_t *)array->arr + (array->size - 1) * sizeof(int));
        } else if (str_equal(array->data_type, "double")) {
            array->iterator->iter = (iter_t)((byte_t *)array->arr + (array->size - 1) * sizeof(double));
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            array->iterator->iter = arr[array->size - 1];
            array->iterator->iter_index = array->size - 1;
        }
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }

    return array->iterator->iter;
}

/**
 * @brief   Determine if the cino-array has previous iterator.
 * @param array cino-array
 * @return  Returns `true` if previous iterator exists, otherwise returns `false`.
 */
bool array_iter_has_prev(const array_t *array) {
    return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);

    if (str_equal(array->data_type, "int")) {
        return (void *)((byte_t *)array->iterator->iter - sizeof(int)) >= (void *)((int *)array->arr);
    } else if (str_equal(array->data_type, "double")) {
        return (void *)((byte_t *)array->iterator->iter - sizeof(double)) >= (void *)((double *)array->arr);
    } else if (str_equal(array->data_type, "T")) {
        return array->iterator->iter_index - 1 >= 0;
    }

    return false;
}

/**
 * @brief   Determine if the cino-array has next iterator.
 * @param array cino-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_iter_has_next(const array_t *array) {
    return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);

    if (str_equal(array->data_type, "int")) {
        return (void *)((byte_t *)array->iterator->iter + sizeof(int)) < (void *)((int *)array->arr + array->size);
    } else if (str_equal(array->data_type, "double")) {
        return (void *)((byte_t *)array->iterator->iter + sizeof(double)) < (void *)((double *)array->arr + array->size);
    } else if (str_equal(array->data_type, "T")) {
        return array->iterator->iter_index + 1 < array->size;
    }

    return false;
}

/**
 * @brief   Get the previous iterator.
 * @param array cino-array
 * @return  Returns the previous iterator.
 */
iter_t array_iter_prev(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array_iter_has_prev(array)) {
        byte_t *iter = NULL;
        if (str_equal(array->data_type, "int")) {
            iter = (byte_t *)array->iterator->iter;
            iter -= sizeof(int);
            array->iterator->iter = (iter_t)iter;
        } else if (str_equal(array->data_type, "double")) {
            iter = (byte_t *)array->iterator->iter;
            iter -= sizeof(double);
            array->iterator->iter = (iter_t)iter;
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            array->iterator->iter_index--;
            array->iterator->iter = arr[array->iterator->iter_index];
        }
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }

    return array->iterator->iter;
}

/**
 * @brief   Get the next iterator.
 * @param array cino-array
 * @return  Returns the next iterator.
 */
iter_t array_iter_next(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array_iter_has_next(array)) {
        byte_t *iter = NULL;
        if (str_equal(array->data_type, "int")) {
            iter = (byte_t *)array->iterator->iter;
            iter += sizeof(int);
            array->iterator->iter = (iter_t)iter;
        } else if (str_equal(array->data_type, "double")) {
            iter = (byte_t *)array->iterator->iter;
            iter += sizeof(double);
            array->iterator->iter = (iter_t)iter;
        } else if (str_equal(array->data_type, "T")) {
            void **arr = (void **)array->arr;
            array->iterator->iter_index++;
            array->iterator->iter = arr[array->iterator->iter_index];
        }
    } else {
        array->iterator->iter = NULL;
        array->iterator->iter_index = -1;
    }

    return array->iterator->iter;
}