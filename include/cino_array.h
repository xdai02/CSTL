/**************************************************
 * Module   :   cino_array
 * Function :   Operations on cino-array
 * Category :
 *              - array_t
 *              - array_t
 *              - array_t
 **************************************************/

#ifndef _CINO_ARRAY_H_
#define _CINO_ARRAY_H_

#include "cino_utils.h"

/****************************************
 *             array_t
 ****************************************/

typedef struct array_t array_t;

/**
 * @brief   Create cino-array.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      1. int
 *                      2. double
 *                      3. T (for generic)
 * @return  Returns the pointer to cino-array. Returns NULL if creation failed.
 */
array_t *array_create(const str_t data_type);

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before
 *          calling this function, if it is a generic cino-array.
 * @param array cino-array
 */
void array_destroy(array_t *array);

/**
 * @brief   Determine if the cino-array is empty.
 * @param array cino-array
 * @return  Returns true if the cino-array is empty, otherwise returns false.
 */
bool array_is_empty(const array_t *array);

/**
 * @brief   Get the number of elements in the cino-array.
 * @param array cino-array
 * @return  Returns the number of elements in the cino-array.
 */
size_t array_size(const array_t *array);

/**
 * @brief   Clear all the elments in the cino-array.
 * @note    It is caller's responsibility to free all the elements before
 *          calling this function, if it is a generic cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array);

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @note    For non-generic type cino-array, this function returns a wrapper
 *          type of the primitive. It is caller's responsibility to unwrap
 *          to get the primitive.
 * @param array cino-array
 * @param index index
 * @return  Returns a pointer to the indexed component in the cino-array.
 */
T array_get(const array_t *array, int index);

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @note    1. For non-generic type data, a wrapper type of that primitive is
 *          needed. This function will not unwrap or free the wrapper. It is
 *          caller's responsibility to unwrap.
 *          2. For generic type cino-array, it is caller's responsibility to free
 *          the previous data before overwriting it.
 * @param array cino-array
 * @param index index
 * @param data  new element
 */
void array_set(array_t *array, int index, T data);

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @note    1. For non-generic type data, a wrapper type of that primitive is
 *          needed. This function will not unwrap or free the wrapper. It is
 *          caller's responsibility to unwrap.
 *          2. For generic type cino-array, it is caller's responsibility to
 *          make sure that the inserted element is on the heap.
 * @param array cino-array
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, T data);

/**
 * @brief   Inserts the specified element at the specified position in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-int-array.
 */
array_t *array_insert_int(array_t *array, int index, int data);

/**
 * @brief   Inserts the specified element at the specified position in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-double-array.
 */
array_t *array_insert_double(array_t *array, int index, double data);

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @note    It is caller's responsibility to make sure that the inserted element
 *          is on the heap.
 * @param array cino-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, T data);

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @note    This function just removes the element from the cino-array. It is
 *          caller's responsibility to free the removed element, if it is a
 *          generic cino-array.
 * @param array cino-array
 * @param index index
 * @return  Returns the modified cino-array.
 */
array_t *array_remove(array_t *array, int index);

/**
 * @brief   Get the minimum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the minimum value.
 */
int array_min_int(const array_t *array);

/**
 * @brief   Get the minimum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the minimum value.
 */
double array_min_double(const array_t *array);

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array     cino-array
 * @param compare   user-defined callback function for comparison
 * @return  Returns the minimum value.
 */
T array_min(const array_t *array, compare_t compare);

/**
 * @brief   Get the maximum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the maximum value.
 */
int array_max_int(const array_t *array);

/**
 * @brief   Get the maximum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the maximum value.
 */
double array_max_double(const array_t *array);

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array     cino-array
 * @param compare   user-defined callback function for comparison
 * @return  Returns the maximum value.
 */
T array_max(const array_t *array, compare_t compare);

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
 */
int array_int_index_of(const array_t *array, int data);

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
 */
int array_int_last_index_of(const array_t *array, int data);

/**
 * @brief   Count the occurrences of the specified element.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
 */
int array_int_count(const array_t *array, int data);

/**
 * @brief   Reverses the order of all elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
 */
array_t *array_int_reverse(array_t *array);

/**
 * @brief   Swap two elements at specified indices in the cino-int-array.
 * @param array     cino-int-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-int-array.
 */
array_t *array_int_swap(array_t *array, int index1, int index2);

/**
 * @brief   Sort the cino-int-array.
 * @param array     cino-int-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-int-array.
 */
array_t *array_int_sort(array_t *array, bool reverse);

/**
 * @brief   Get the iterator.
 * @param array cino-int-array
 * @return  Returns the iterator.
 */
iter_t array_int_iter(array_t *array);

/**
 * @brief   Determine if the cino-int-array has the next iterator.
 * @param array cino-int-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_int_iter_has_next(const array_t *array);

/**
 * @brief   Get the next iterator.
 * @param array cino-int-array
 * @return  Returns the next iterator.
 */
iter_t array_int_iter_next(array_t *array);

/****************************************
 *            array_t
 ****************************************/

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_index_of(const array_t *array, double data);

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_last_index_of(const array_t *array, double data);

/**
 * @brief   Count the occurrences of the specified element.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
 */
int array_double_count(const array_t *array, double data);

/**
 * @brief   Reverses the order of all elements in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
array_t *array_double_reverse(array_t *array);

/**
 * @brief   Swap two elements at specified indices in the cino-double-array.
 * @param array     cino-double-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-double-array.
 */
array_t *array_double_swap(array_t *array, int index1, int index2);

/**
 * @brief   Sort the cino-double-array.
 * @param array     cino-double-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-double-array.
 */
array_t *array_double_sort(array_t *array, bool reverse);

/**
 * @brief   Get the iterator.
 * @param array cino-double-array
 * @return  Returns the iterator.
 */
iter_t array_double_iter(array_t *array);

/**
 * @brief   Determine if the cino-double-array has the next iterator.
 * @param array cino-double-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_double_iter_has_next(const array_t *array);

/**
 * @brief   Get the next iterator.
 * @param array cino-double-array
 * @return  Returns the next iterator.
 */
iter_t array_double_iter_next(array_t *array);

/****************************************
 *               array_t
 ****************************************/

/**
 * @brief   Find the first element that satisfies the comparison strategy.
 * @param array cino-array
 * @param match user-defined callback function for matching
 * @return  Returns the found element, or NULL if not found.
 */
void *array_find(const array_t *array, match_t match);

/**
 * @brief   Count the occurrences of the element matched.
 * @param array cino-array
 * @param match user-defined callback function for matching
 * @return  Returns occurrences of the element matched.
 */
int array_count(const array_t *array, match_t match);

/**
 * @brief   Reverses the order of all elements in the cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_reverse(array_t *array);

/**
 * @brief   Swap two elements at specified indices in the cino-array.
 * @param array     cino-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-array.
 */
array_t *array_swap(array_t *array, int index1, int index2);

/**
 * @brief   Sort the cino-array.
 * @param array     cino-array
 * @param compare   user-defined callback function for comparison
 * @return  Returns the modified cino-array.
 */
array_t *array_sort(array_t *array, compare_t compare);

/**
 * @brief   Get the iterator.
 * @param array cino-array
 * @return  Returns the iterator.
 */
iter_t array_iter(array_t *array);

/**
 * @brief   Determine if the cino-array has the next iterator.
 * @param array cino-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_iter_has_next(const array_t *array);

/**
 * @brief   Get the next iterator.
 * @param array cino-array
 * @return  Returns the next iterator.
 */
iter_t array_iter_next(array_t *array);

#endif