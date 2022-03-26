#include "cino_array.h"

/****************************************
 *               Iterator
 ****************************************/

typedef struct iterator_t {
    void *iter;      // points to the current element
    int iter_index;  // generic array use only
} iterator_t;

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t {
    int *i_arr;     // cino-int-array
    double *d_arr;  // cino-double-array
    T *t_arr;       // cino-array
    str_t data_type;
    size_t size;
    size_t capacity;
    iterator_t *iterator;
} array_t;

/**
 * @brief   Validate data type
 * @param data_type data type
 *                  valid data type includes:
 *                      1. int
 *                      2. double
 *                      3. T (generic)
 * @return  Returns `true` if the data type is supported, otherwise returns `false`.
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
 * @brief   Create cino-array.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      1. int
 *                      2. double
 *                      3. T (for generic)
 * @return  Returns the pointer to cino-array. Returns NULL if creation failed.
 */
array_t *array_create(const str_t data_type) {
    if (!is_valid_data_type(data_type)) {
        LOGGER(ERROR, "Data type '%s' not defined.", data_type);
        return NULL;
    }

    array_t *array = (array_t *)cino_alloc(sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);

    array->iterator = (iterator_t *)cino_alloc(sizeof(iterator_t));
    call_and_return_value_if_fail(array->iterator != NULL, array_destroy(array), NULL);

    array->data_type = (str_t)cino_alloc(sizeof(char) * (str_length(data_type) + 1));
    call_and_return_value_if_fail(array->data_type != NULL, array_destroy(array), NULL);
    str_copy(array->data_type, data_type);

    array->i_arr = NULL;
    array->d_arr = NULL;
    array->t_arr = NULL;
    array->size = 0;
    array->capacity = 0;
    array->iterator->iter = NULL;
    array->iterator->iter_index = -1;

    return array;
}

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before calling 
 *          this function, if it is a generic cino-array.
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

    if (array->i_arr) {
        free(array->i_arr);
        array->i_arr = NULL;
    }

    if (array->d_arr) {
        free(array->d_arr);
        array->d_arr = NULL;
    }

    if (array->t_arr) {
        free(array->t_arr);
        array->t_arr = NULL;
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
 * @note    It is caller's responsibility to free all the elements before calling 
 *          this function, if it is a generic cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    if (array->i_arr) {
        free(array->i_arr);
        array->i_arr = NULL;
    }

    if (array->d_arr) {
        free(array->d_arr);
        array->d_arr = NULL;
    }

    if (array->t_arr) {
        free(array->t_arr);
        array->t_arr = NULL;
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
 * @param index index
 * @return  For primitive type cino-array, this function returns a wrapper type of 
 *          the primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T array_get(const array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);

    if (str_equal(array->data_type, "int")) {
        return (T)wrap_int(array->i_arr[index]);
    } else if (str_equal(array->data_type, "double")) {
        return (T)wrap_double(array->d_arr[index]);
    } else if (str_equal(array->data_type, "T")) {
        return array->t_arr[index];
    }

    return NULL;
}

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @note    1. For primitive type data, a wrapper type of that primitive is needed. 
 *          This function will not unwrap or free the wrapper. It is caller's 
 *          responsibility to unwrap.
 *          2. For generic type cino-array, it is caller's responsibility to free
 *          the previous data before overwriting it.
 * @param array cino-array
 * @param index index
 * @param data  new element in wrapper
 */
void array_set(array_t *array, int index, T data) {
    if (!array || index < 0 || index >= array->size) {
        LOGGER(ERROR, "Index out of bounds.");
        return;
    }
    if (!data) {
        LOGGER(ERROR, "Null pointer exception.");
        return;
    }

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        array->i_arr[index] = wrapper_int->data;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        array->d_arr[index] = wrapper_double->data;
    } else if (str_equal(array->data_type, "T")) {
        array->t_arr[index] = data;
    }
}

/**
 * @brief   Expand or shrink the cino-array according to the size and capacity.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
static array_t *array_resize(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    void *p = NULL;

    // first allocation
    if (array->capacity == 0) {
        array->capacity = 1;

        if (str_equal(array->data_type, "int")) {
            array->i_arr = (int *)cino_alloc(sizeof(int) * array->capacity);
            p = array->i_arr;
        } else if (str_equal(array->data_type, "double")) {
            array->d_arr = (double *)cino_alloc(sizeof(double) * array->capacity);
            p = array->d_arr;
        } else if (str_equal(array->data_type, "T")) {
            array->t_arr = (T *)cino_alloc(sizeof(T) * array->capacity);
            p = array->t_arr;
        }
        call_and_return_value_if_fail(p != NULL, array_destroy(array), NULL);

        return array;
    }

    const int EXPANSION = 2;  // coefficient of expansion

    // expand
    if (array->size >= array->capacity) {
        if (str_equal(array->data_type, "int")) {
            array->i_arr = (int *)cino_realloc(array->i_arr, sizeof(int) * array->capacity, sizeof(int) * array->capacity * 2);
            p = array->i_arr;
        } else if (str_equal(array->data_type, "double")) {
            array->d_arr = (double *)cino_realloc(array->d_arr, sizeof(double) * array->capacity, sizeof(double) * array->capacity * 2);
            p = array->d_arr;
        } else if (str_equal(array->data_type, "T")) {
            array->t_arr = (T *)cino_realloc(array->t_arr, sizeof(T) * array->capacity, sizeof(T) * array->capacity * 2);
            p = array->t_arr;
        }
        call_and_return_value_if_fail(p != NULL, array_destroy(array), NULL);
        array->capacity *= EXPANSION;
    }
    // shrink
    else if (array->size <= array->capacity / EXPANSION) {
        size_t capacity = array->capacity / EXPANSION;
        if (capacity > 0) {
            if (str_equal(array->data_type, "int")) {
                array->i_arr = (int *)cino_realloc(array->i_arr, sizeof(int) * array->capacity, sizeof(int) * capacity);
            } else if (str_equal(array->data_type, "double")) {
                array->d_arr = (double *)cino_realloc(array->d_arr, sizeof(double) * array->capacity, sizeof(double) * capacity);
            } else if (str_equal(array->data_type, "T")) {
                array->t_arr = (T *)cino_realloc(array->t_arr, sizeof(T) * array->capacity, sizeof(T) * capacity);
            }
            array->capacity = capacity;
        }
    }

    return array;
}

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @note    1. For primitive type data, a wrapper type of that primitive is needed. 
 *          This function will not unwrap or free the wrapper. It is caller's 
 *          responsibility to unwrap.
 *          2. For generic type cino-array, it is caller's responsibility to make 
 *          sure that the inserted element is on the heap.
 * @param array cino-array
 * @param data  new element in wrapper
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, T data) {
    array_resize(array);
    return_value_if_fail(array != NULL, NULL);

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        array->i_arr[array->size++] = wrapper_int->data;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        array->d_arr[array->size++] = wrapper_double->data;
    } else if (str_equal(array->data_type, "T")) {
        array->t_arr[array->size++] = data;
    }

    return array;
}

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @note    1. For primitive type data, a wrapper type of that primitive is needed. 
 *          This function will not unwrap or free the wrapper. It is caller's 
 *          responsibility to unwrap.
 *          2. For generic type cino-array, it is caller's responsibility to make 
 *          sure that the inserted element is on the heap.
 * @param array cino-array
 * @param index index
 * @param data  new element in wrapper
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, T data) {
    return_value_if_fail(index >= 0 && index <= array->size, array);

    array_resize(array);
    return_value_if_fail(array != NULL, NULL);

    for (int i = array->size - 1; i >= index; i--) {
        if (str_equal(array->data_type, "int")) {
            array->i_arr[i + 1] = array->i_arr[i];
        } else if (str_equal(array->data_type, "double")) {
            array->d_arr[i + 1] = array->d_arr[i];
        } else if (str_equal(array->data_type, "T")) {
            array->t_arr[i + 1] = array->t_arr[i];
        }
    }

    if (str_equal(array->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        array->i_arr[index] = wrapper_int->data;
    } else if (str_equal(array->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        array->d_arr[index] = wrapper_double->data;
    } else if (str_equal(array->data_type, "T")) {
        array->t_arr[index] = data;
    }

    array->size++;
    return array;
}

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @note    This function just removes the element from the cino-array. It is caller's 
 *          responsibility to free the removed element, if it is a generic cino-array.
 * @param array cino-array
 * @param index index
 * @return  Returns the modified cino-array.
 */
array_t *array_remove(array_t *array, int index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    for (int i = index + 1; i < array->size; i++) {
        if (str_equal(array->data_type, "int")) {
            array->i_arr[i - 1] = array->i_arr[i];
        } else if (str_equal(array->data_type, "double")) {
            array->d_arr[i - 1] = array->d_arr[i];
        } else if (str_equal(array->data_type, "T")) {
            array->t_arr[i - 1] = array->t_arr[i];
        }
    }
    array->size--;

    array_resize(array);
    return array;
}

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array     cino-array
 * @param compare   User-defined callback function for comparison, only for T (generic) 
 *                  cino-array. Set to `NULL` if the elements in the cino-array are 
 *                  primitive.
 * @return  Returns the minimum value in the cino-array, or `NULL` if conditions failed. 
 *          For primitive data, a wrapper type of that primitive is returned. It is 
 *          caller's responsibility to unwrap.
 */
T array_min(const array_t *array, compare_t compare) {
    if (!array) {
        LOGGER(ERROR, "Null pointer exception.");
        return NULL;
    }
    if (array->size == 0) {
        LOGGER(ERROR, "Empty object.");
        return NULL;
    }

    if (str_equal(array->data_type, "int")) {
        int min = array->i_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->i_arr[i] < min) {
                min = array->i_arr[i];
            }
        }
        return wrap_int(min);
    } else if (str_equal(array->data_type, "double")) {
        double min = array->d_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->d_arr[i] < min) {
                min = array->d_arr[i];
            }
        }
        return wrap_double(min);
    } else if (str_equal(array->data_type, "T")) {
        if (!compare) {
            LOGGER(WARNING, "Compare rule is not defined.");
            return NULL;
        }
        T min = array->t_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (compare(array->t_arr[i], min) < 0) {
                min = array->t_arr[i];
            }
        }
        return min;
    }

    return NULL;
}

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array     cino-array
 * @param compare   User-defined callback function for comparison, only for T (generic) 
 *                  cino-array. Set to `NULL` if the elements in the cino-array are 
 *                  primitive.
 * @return  Returns the maximum value in the cino-array, or `NULL` if conditions failed. 
 *          For primitive data, a wrapper type of that primitive is returned. It is 
 *          caller's responsibility to unwrap.
 */
T array_max(const array_t *array, compare_t compare) {
    if (!array) {
        LOGGER(ERROR, "Null pointer exception.");
        return NULL;
    }
    if (array->size == 0) {
        LOGGER(ERROR, "Empty object.");
        return NULL;
    }

    if (str_equal(array->data_type, "int")) {
        int max = array->i_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->i_arr[i] > max) {
                max = array->i_arr[i];
            }
        }
        return wrap_int(max);
    } else if (str_equal(array->data_type, "double")) {
        double max = array->d_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (array->d_arr[i] > max) {
                max = array->d_arr[i];
            }
        }
        return wrap_double(max);
    } else if (str_equal(array->data_type, "T")) {
        if (!compare) {
            LOGGER(WARNING, "Compare rule is not defined.");
            return NULL;
        }
        T max = array->t_arr[0];
        for (int i = 1; i < array->size; i++) {
            if (compare(array->t_arr[i], max) > 0) {
                max = array->t_arr[i];
            }
        }
        return max;
    }

    return NULL;
}

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-array.
 * @note    This function is for primitive type cino-array ONLY.
 *          For T (generic) cino-array, please refer to `array_find()`.
 * @param array cino-array
 * @param data  element in wrapper
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-array, or `-1` if not found.
 */
int array_index_of(const array_t *array, T data) {
    return_value_if_fail(array != NULL, -1);

    for (int i = 0; i < array->size; i++) {
        if (str_equal(array->data_type, "int")) {
            wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
            if (array->i_arr[i] == wrapper_int->data) {
                return i;
            }
        } else if (str_equal(array->data_type, "double")) {
            wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
            if (equal_double(array->d_arr[i], wrapper_double->data)) {
                return i;
            }
        }
    }

    return -1;
}

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-array.
 * @note    This function is for primitive type cino-array ONLY.
 *          For T (generic) cino-array, please refer to `array_find()`.
 * @param array cino-array
 * @param data  element in wrapper
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-array, or `-1` if not found.
 */
int array_last_index_of(const array_t *array, T data) {
    return_value_if_fail(array != NULL, -1);

    for (int i = array->size - 1; i >= 0; i--) {
        if (str_equal(array->data_type, "int")) {
            wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
            if (array->i_arr[i] == wrapper_int->data) {
                return i;
            }
        } else if (str_equal(array->data_type, "double")) {
            wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
            if (equal_double(array->d_arr[i], wrapper_double->data)) {
                return i;
            }
        }
    }

    return -1;
}

/**
 * @brief   Find the first element that satisfies the matching rule.
 * @note    This function is for T (generic) cino-array ONLY.
 *          For primitive type cino-array, please refer to `array_index_of()` and 
 *          `array_last_last_of()`.
 * @param array cino-array
 * @param match user-defined callback function for matching
 * @return  Returns the found element, or NULL if not found.
 */
T array_find(const array_t *array, match_t match) {
    return_value_if_fail(array != NULL && match != NULL, NULL);
    
    for (int i = 0; i < array->size; i++) {
        if (match(array->t_arr[i])) {
            return array->t_arr[i];
        }
    }

    return NULL;
}

// /**
//  * @brief   Count the occurrences of the specified element.
//  * @param array cino-int-array
//  * @param data  element
//  * @return  Returns the occurrences of the specified element.
//  */
// int array_int_count(const array_t *array, int data) {
//     return_value_if_fail(array != NULL, 0);
//     int cnt = 0;
//     for (int i = 0; i < array->size; i++) {
//         if (array->i_arr[i] == data) {
//             cnt++;
//         }
//     }
//     return cnt;
// }


// /**
//  * @brief   Count the occurrences of the specified element.
//  * @param array cino-double-array
//  * @param data  element
//  * @return  Returns the occurrences of the specified element.
//  */
// int array_double_count(const array_t *array, double data) {
//     return_value_if_fail(array != NULL, 0);
//     int cnt = 0;
//     for (int i = 0; i < array->size; i++) {
//         if (equal_double(array->d_arr[i], data)) {
//             cnt++;
//         }
//     }
//     return cnt;
// }

// /**
//  * @brief   Count the occurrences of the element matched.
//  * @param array cino-array
//  * @param match user-defined callback function for matching
//  * @return  Returns occurrences of the element matched.
//  */
// int array_count(const array_t *array, match_t match) {
//     return_value_if_fail(array != NULL && match != NULL, 0);
//     int cnt = 0;
//     for (int i = 0; i < array->size; i++) {
//         if (match(array->t_arr[i])) {
//             cnt++;
//         }
//     }
//     return cnt;
// }

// /**
//  * @brief   Reverses the order of all elements in the cino-int-array.
//  * @param array cino-int-array
//  * @return  Returns the modified cino-int-array.
//  */
// array_t *array_int_reverse(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     int i = 0;
//     int j = array->size - 1;
//     while (i < j) {
//         swap(array->i_arr[i], array->i_arr[j], int);
//         i++;
//         j--;
//     }
//     return array;
// }

// /**
//  * @brief   Swap two elements at specified indices in the cino-int-array.
//  * @param array     cino-int-array
//  * @param index1    index 1
//  * @param index2    index 2
//  * @return  Returns the modified cino-int-array.
//  */
// array_t *array_int_swap(array_t *array, int index1, int index2) {
//     return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
//     swap(array->i_arr[index1], array->i_arr[index2], int);
//     return array;
// }

// /**
//  * @brief   Specify the rules for comparing two int values in ascending order.
//  * @param data1 pointer to the first value
//  * @param data2 pointer to the second value
//  * @return  Returns
//  *              - 0 if two values are equal
//  *              - positive if the first value is greater than the second value
//  *              - negative if the first value is less than the second value
//  */
// static int cmp_int_less(const void *data1, const void *data2) {
//     int *p1 = (int *)data1;
//     int *p2 = (int *)data2;
//     return *p1 - *p2;
// }

// /**
//  * @brief   Specify the rules for comparing two int values in descending order.
//  * @param data1 pointer to the first value
//  * @param data2 pointer to the second value
//  * @return  Returns
//  *              - 0 if two values are equal
//  *              - positive if the first value is less than the second value
//  *              - negative if the first value is greater than the second value
//  */
// static int cmp_int_greater(const void *data1, const void *data2) {
//     int *p1 = (int *)data1;
//     int *p2 = (int *)data2;
//     return *p2 - *p1;
// }

// /**
//  * @brief   Sort the cino-int-array.
//  * @param array     cino-int-array
//  * @param reverse   true for descending, false for ascending
//  * @return  Returns the modified cino-int-array.
//  */
// array_t *array_int_sort(array_t *array, bool reverse) {
//     return_value_if_fail(array != NULL, NULL);
//     if (reverse) {
//         qsort(array->i_arr, array->size, sizeof(int), cmp_int_greater);
//     } else {
//         qsort(array->i_arr, array->size, sizeof(int), cmp_int_less);
//     }
//     return array;
// }

// /**
//  * @brief   Get the iterator.
//  * @param array cino-int-array
//  * @return  Returns the iterator.
//  */
// iter_t array_int_iter(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array->size > 0) {
//         array->iterator->iter = array->i_arr;
//     } else {
//         array->iterator->iter = NULL;
//     }
//     return array->iterator->iter;
// }

// /**
//  * @brief   Determine if the cino-int-array has the next iterator.
//  * @param array cino-int-array
//  * @return  Returns `true` if next iterator exists, otherwise returns `false`.
//  */
// bool array_int_iter_has_next(const array_t *array) {
//     return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);
//     return (void *)((byte_t *)array->iterator->iter + sizeof(int)) < (void *)(array->i_arr + array->size);
// }

// /**
//  * @brief   Get the next iterator.
//  * @param array cino-int-array
//  * @return  Returns the next iterator.
//  */
// iter_t array_int_iter_next(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array_int_iter_has_next(array)) {
//         byte_t *iter = (byte_t *)array->iterator->iter;
//         iter += sizeof(int);
//         array->iterator->iter = (void *)iter;
//     } else {
//         array->iterator->iter = NULL;
//     }
//     return array->iterator->iter;
// }


// /**
//  * @brief   Reverses the order of all elements in the cino-double-array.
//  * @param array cino-double-array
//  * @return  Returns the modified cino-double-array.
//  */
// array_t *array_double_reverse(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     int i = 0;
//     int j = array->size - 1;
//     while (i < j) {
//         swap(array->d_arr[i], array->d_arr[j], double);
//         i++;
//         j--;
//     }
//     return array;
// }

// /**
//  * @brief   Swap two elements at specified indices in the cino-double-array.
//  * @param array     cino-double-array
//  * @param index1    index 1
//  * @param index2    index 2
//  * @return  Returns the modified cino-double-array.
//  */
// array_t *array_double_swap(array_t *array, int index1, int index2) {
//     return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
//     swap(array->d_arr[index1], array->d_arr[index2], double);
//     return array;
// }

// /**
//  * @brief   Specify the rules for comparing two double values in ascending order.
//  * @param data1 pointer to the first value
//  * @param data2 pointer to the second value
//  * @return  Returns
//  *              - 0 if two values are equal
//  *              - positive if the first value is greater than the second value
//  *              - negative if the first value is less than the second value
//  */
// static int cmp_double_less(const void *data1, const void *data2) {
//     double *p1 = (double *)data1;
//     double *p2 = (double *)data2;
//     return *p1 > *p2 ? 1 : -1;
// }

// /**
//  * @brief   Specify the rules for comparing two double values in descending order.
//  * @param data1 pointer to the first value
//  * @param data2 pointer to the second value
//  * @return  Returns
//  *              - 0 if two values are equal
//  *              - positive if the first value is less than the second value
//  *              - negative if the first value is greater than the second value
//  */
// static int cmp_double_greater(const void *data1, const void *data2) {
//     double *p1 = (double *)data1;
//     double *p2 = (double *)data2;
//     return *p2 > *p1 ? 1 : -1;
// }

// /**
//  * @brief   Sort the cino-double-array.
//  * @param array     cino-double-array
//  * @param reverse   true for descending, false for ascending
//  * @return  Returns the modified cino-double-array.
//  */
// array_t *array_double_sort(array_t *array, bool reverse) {
//     return_value_if_fail(array != NULL, NULL);
//     if (reverse) {
//         qsort(array->d_arr, array->size, sizeof(double), cmp_double_greater);
//     } else {
//         qsort(array->d_arr, array->size, sizeof(double), cmp_double_less);
//     }
//     return array;
// }

// /**
//  * @brief   Get the iterator.
//  * @param array cino-double-array
//  * @return  Returns the iterator.
//  */
// iter_t array_double_iter(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array->size > 0) {
//         array->iterator->iter = array->d_arr;
//     } else {
//         array->iterator->iter = NULL;
//     }
//     return array->iterator->iter;
// }

// /**
//  * @brief   Determine if the cino-double-array has the next iterator.
//  * @param array cino-double-array
//  * @return  Returns `true` if next iterator exists, otherwise returns `false`.
//  */
// bool array_double_iter_has_next(const array_t *array) {
//     return_value_if_fail(array != NULL && array->iterator->iter != NULL, false);
//     return (void *)((byte_t *)array->iterator->iter + sizeof(double)) < (void *)(array->d_arr + array->size);
// }

// /**
//  * @brief   Get the next iterator.
//  * @param array cino-double-array
//  * @return  Returns the next iterator.
//  */
// iter_t array_double_iter_next(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array_double_iter_has_next(array)) {
//         byte_t *iter = (byte_t *)array->iterator->iter;
//         iter += sizeof(double);
//         array->iterator->iter = (void *)iter;
//     } else {
//         array->iterator->iter = NULL;
//     }
//     return array->iterator->iter;
// }





// /**
//  * @brief   Reverses the order of all elements in the cino-array.
//  * @param array cino-array
//  * @return  Returns the modified cino-array.
//  */
// array_t *array_reverse(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     int i = 0;
//     int j = array->size - 1;
//     while (i < j) {
//         swap(array->t_arr[i], array->t_arr[j], void *);
//         i++;
//         j--;
//     }
//     return array;
// }

// /**
//  * @brief   Swap two elements at specified indices in the cino-array.
//  * @param array     cino-array
//  * @param index1    index 1
//  * @param index2    index 2
//  * @return  Returns the modified cino-array.
//  */
// array_t *array_swap(array_t *array, int index1, int index2) {
//     return_value_if_fail(array != NULL && index1 >= 0 && index1 < array->size && index2 >= 0 && index2 < array->size && index1 != index2, array);
//     swap(array->t_arr[index1], array->t_arr[index2], void *);
//     return array;
// }

// /**
//  * @brief   Parition function for quick sort.
//  * @param arr       an array of pointers
//  * @param start     start index of partition
//  * @param end       end index of partition
//  * @param compare   user-defined callback function for comparison
//  * @return  Returns the index of the pivot.
//  */
// static int quick_sort_partition(void **arr, int start, int end, compare_t compare) {
//     int i = start - 1;
//     void *pivot = arr[end];

//     for (int j = start; j < end; j++) {
//         if (compare(arr[j], pivot) < 0) {
//             i++;
//             swap(arr[i], arr[j], void *);
//         }
//     }

//     swap(arr[i + 1], arr[end], void *);
//     return i + 1;
// }

// /**
//  * @brief   Stack-based quick sort for cino-array.
//  * @param arr       an array of pointers
//  * @param size      number of elements in the array
//  * @param compare   user-defined callback function for comparison
//  */
// static void quick_sort(void **arr, size_t size, compare_t compare) {
//     int stack[size];
//     memset(stack, 0x00, size * sizeof(int));

//     int n = 0;
//     stack[n++] = 0;
//     stack[n++] = size - 1;

//     while (n > 0) {
//         int right = stack[--n];
//         int left = stack[--n];

//         int index = quick_sort_partition(arr, left, right, compare);
//         if (index - 1 > left) {
//             stack[n++] = left;
//             stack[n++] = index - 1;
//         }
//         if (index + 1 < right) {
//             stack[n++] = index + 1;
//             stack[n++] = right;
//         }
//     }
// }

// /**
//  * @brief   Sort the cino-array.
//  * @param array     cino-array
//  * @param compare   user-defined callback function for comparison
//  * @return  Returns the modified cino-array.
//  */
// array_t *array_sort(array_t *array, compare_t compare) {
//     return_value_if_fail(array != NULL, NULL);
//     quick_sort(array->t_arr, array->size, compare);
//     return array;
// }

// /**
//  * @brief   Get the iterator.
//  * @param array cino-array
//  * @return  Returns the iterator.
//  */
// iter_t array_iter(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array->size > 0) {
//         array->iterator->iter = array->t_arr[0];
//         array->iterator->iter_index = 0;
//     } else {
//         array->iterator->iter = NULL;
//         array->iterator->iter_index = -1;
//     }
//     return array->iterator->iter;
// }

// /**
//  * @brief   Determine if the cino-array has the next iterator.
//  * @param array cino-array
//  * @return  Returns `true` if next iterator exists, otherwise returns `false`.
//  */
// bool array_iter_has_next(const array_t *array) {
//     return_value_if_fail(array != NULL && array->iterator->iter != NULL && array->iterator->iter_index >= 0, false);
//     return array->iterator->iter_index + 1 < array->size;
// }

// /**
//  * @brief   Get the next iterator.
//  * @param array cino-array
//  * @return  Returns the next iterator.
//  */
// iter_t array_iter_next(array_t *array) {
//     return_value_if_fail(array != NULL, NULL);
//     if (array_iter_has_next(array)) {
//         array->iterator->iter_index++;
//         array->iterator->iter = array->t_arr[array->iterator->iter_index];
//     } else {
//         array->iterator->iter = NULL;
//         array->iterator->iter_index = -1;
//     }
//     return array->iterator->iter;
// }