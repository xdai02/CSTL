/**************************************************
 * Module   :   cino_array
 * Function :   Operations on cino_array
 * Category :
 *              - array_int_t
 *              - array_double_t
 *              - array_t
 **************************************************/

#ifndef _CINO_ARRAY_H_
#define _CINO_ARRAY_H_

#include "cino_utils.h"

/****************************************
 *             array_int_t
 ****************************************/

typedef struct array_int_t array_int_t;

/**
 * @brief   Create cino-int-array.
 * @return  Returns the pointer to cino-int-array. Returns NULL if creation failed.
 */
array_int_t *array_int_create();

/**
 * @brief   Destroy cino-int-array.
 * @param array cino-int-array
 */
void array_int_destroy(array_int_t *array);

/**
 * @brief   Determine if the cino-int-array is empty.
 * @param array cino-int-array
 * @return  Returns true if the cino-int-array is empty, otherwise returns false.
 */
bool array_int_is_empty(const array_int_t *array);

/**
 * @brief   Get the number of elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the number of elements in the cino-int-array.
 */
int array_int_size(const array_int_t *array);

/**
 * @brief   Clear all the elments in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_clear(array_int_t *array);

/**
 * @brief   Get the value of the indexed component in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the value of the indexed component in the cino-int-array.
 */
int array_int_get(const array_int_t *array, int index);

/**
 * @brief   Update the value of the indexed component in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @param data  new element
 */
void array_int_set(array_int_t *array, int index, int data);

/**
 * @brief   Appends the specified element to the end of the cino-int-array.
 * @param array cino-int-array
 * @param data  new element
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_append(array_int_t *array, int data);

/**
 * @brief   Appends an int array to the end of the cino-int-array.
 * @param array     cino-int-array
 * @param arr       new element
 * @param arr_len   number of elements in the int array
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_extend(array_int_t *array, int *arr, int arr_len);

/**
 * @brief   Inserts the specified element at the specified position in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_insert(array_int_t *array, int index, int data);

/**
 * @brief   Removes the element at the specified position in the cino-int-array.
 * @param array cino-int-array
 * @param index index
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_remove(array_int_t *array, int index);

/**
 * @brief   Get the minimum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the minimum value.
 */
int array_int_min(const array_int_t *array);

/**
 * @brief   Get the maximum value in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the maximum value.
 */
int array_int_max(const array_int_t *array);

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
 */
int array_int_index_of(const array_int_t *array, int data);

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-int-array.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-int-array, or -1 if it does not contain the element.
 */
int array_int_last_index_of(const array_int_t *array, int data);

/**
 * @brief   Count the occurrences of the specified element.
 * @param array cino-int-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
 */
int array_int_count(const array_int_t *array, int data);

/**
 * @brief   Reverses the order of all elements in the cino-int-array.
 * @param array cino-int-array
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_reverse(array_int_t *array);

/**
 * @brief   Swap two elements at specified indices in the cino-int-array.
 * @param array     cino-int-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_swap(array_int_t *array, int index1, int index2);

/**
 * @brief   Sort the cino-int-array.
 * @param array     cino-int-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-int-array.
 */
array_int_t *array_int_sort(array_int_t *array, bool reverse);

/**
 * @brief   Get the iterator.
 * @param array cino-int-array
 * @return  Iterator.
 */
void *array_int_iter(array_int_t *array);

/**
 * @brief   Determine if the cino-int-array has the next iterator.
 * @param array cino-int-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_int_iter_has_next(const array_int_t *array);

/**
 * @brief   Get the next iterator.
 * @param array cino-int-array
 * @return  Returns the next iterator.
 */
void *array_int_iter_next(array_int_t *array);

/****************************************
 *            array_double_t
 ****************************************/

typedef struct array_double_t array_double_t;

/**
 * @brief   Create cino-double-array.
 * @return  Returns the pointer to cino-double-array. Returns NULL if creation failed.
 */
array_double_t *array_double_create();

/**
 * @brief   Destroy cino-double-array.
 * @param array cino-double-array
 */
void array_double_destroy(array_double_t *array);

/**
 * @brief   Determine if the cino-double-array is empty.
 * @param array cino-double-array
 * @return  Returns true if the cino-double-array is empty, otherwise returns false.
 */
bool array_double_is_empty(const array_double_t *array);

/**
 * @brief   Get the number of elements in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the number of elements in the cino-double-array.
 */
int array_double_size(const array_double_t *array);

/**
 * @brief   Clear all the elments in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_clear(array_double_t *array);

/**
 * @brief   Get the value of the indexed component in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the value of the indexed component in the cino-double-array.
 */
double array_double_get(const array_double_t *array, int index);

/**
 * @brief   Update the value of the indexed component in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @param data  new element
 */
void array_double_set(array_double_t *array, int index, double data);

/**
 * @brief   Appends the specified element to the end of the cino-double-array.
 * @param array cino-double-array
 * @param data  new element
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_append(array_double_t *array, double data);

/**
 * @brief   Appends an double array to the end of the cino-double-array.
 * @param array     cino-double-array
 * @param arr       new element
 * @param arr_len   number of elements in the double array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_extend(array_double_t *array, double *arr, int arr_len);

/**
 * @brief   Inserts the specified element at the specified position in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_insert(array_double_t *array, int index, double data);

/**
 * @brief   Removes the element at the specified position in the cino-double-array.
 * @param array cino-double-array
 * @param index index
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_remove(array_double_t *array, int index);

/**
 * @brief   Get the minimum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the minimum value.
 */
double array_double_min(const array_double_t *array);

/**
 * @brief   Get the maximum value in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the maximum value.
 */
double array_double_max(const array_double_t *array);

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_index_of(const array_double_t *array, double data);

/**
 * @brief   Find the index of the last occurrence of the specified element in the
 *          cino-double-array.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the index of the last occurrence of the specified element in the
 *          cino-double-array, or -1 if it does not contain the element.
 */
int array_double_last_index_of(const array_double_t *array, double data);

/**
 * @brief   Count the occurrences of the specified element.
 * @param array cino-double-array
 * @param data  element
 * @return  Returns the occurrences of the specified element.
 */
int array_double_count(const array_double_t *array, double data);

/**
 * @brief   Reverses the order of all elements in the cino-double-array.
 * @param array cino-double-array
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_reverse(array_double_t *array);

/**
 * @brief   Swap two elements at specified indices in the cino-double-array.
 * @param array     cino-double-array
 * @param index1    index 1
 * @param index2    index 2
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_swap(array_double_t *array, int index1, int index2);

/**
 * @brief   Sort the cino-double-array.
 * @param array     cino-double-array
 * @param reverse   true for descending, false for ascending
 * @return  Returns the modified cino-double-array.
 */
array_double_t *array_double_sort(array_double_t *array, bool reverse);

/**
 * @brief   Get the iterator to the first element.
 * @param array cino-double-array
 * @return  Returns the begin iterator.
 */
void *array_double_iter_begin(array_double_t *array);

/**
 * @brief   Get the iterator to the past-the-last-element.
 * @param array cino-double-array
 * @return  Returns the end iterator.
 */
void *array_double_iter_end(array_double_t *array);

/**
 * @brief   Get the iterator to next element.
 * @param iter  iterator
 * @return  Returns the iterator to next element.
 */
void *array_double_iter_next(void *iter);

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t array_t;

/**
 * @brief   Create cino-array.
 * @return  Returns the pointer to cino-array. Returns NULL if creation failed.
 */
array_t *array_create();

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before
 *          calling this function.
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
int array_size(const array_t *array);

/**
 * @brief   Clear all the elments in the cino-array.
 * @note    This function just removes all the elements from the cino-array.It is
 *          caller's responsibility to free the removed elements.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array);

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @param array cino-array
 * @return  Returns a pointer to the indexed component in the cino-array.
 */
void *array_get(const array_t *array, int index);

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @note    It is caller's responsibility to free the previous data before
 *          overwriting it.
 * @param array cino-array
 * @param index index
 * @param data  new element
 */
void array_set(array_t *array, int index, void *data);

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @note    It is caller's responsibility to make sure that the inserted element
 *          is on the heap.
 * @param array cino-array
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, void *data);

/**
 * @brief   Inserts the specified element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  new element
 * @return  Returns the modified cino-array.
 */
array_t *array_insert(array_t *array, int index, void *data);

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @note    This function just removes the element from the cino-array.It is
 *          caller's responsibility to free the removed element.
 * @param array cino-array
 * @param index index
 * @return  Returns the modified cino-array.
 */
array_t *array_remove(array_t *array, int index);

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the minimum value.
 */
void *array_min(const array_t *array, compare_t cmp);

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the maximum value.
 */
void *array_max(const array_t *array, compare_t cmp);

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
 * @param array cino-array
 * @param cmp   user-defined callback function for comparison
 * @return  Returns the modified cino-array.
 */
array_t *array_sort(array_t *array, compare_t cmp);

/**
 * @brief   Get the iterator to the first element.
 * @param array cino-array
 * @return  Returns the begin iterator.
 */
void *array_iter_begin(array_t *array);

/**
 * @brief   Get the iterator to the past-the-last-element.
 * @param array cino-array
 * @return  Returns the end iterator.
 */
void *array_iter_end(array_t *array);

/**
 * @brief   Get the iterator to next element.
 * @param iter  iterator
 * @return  Returns the iterator to next element.
 */
void *array_iter_next(void *iter);

#endif