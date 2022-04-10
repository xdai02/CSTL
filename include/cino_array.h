/**************************************************
 * Module   :   cino_array
 * Function :   Operations on cino-array
 * Category :
 *              - array_t
 **************************************************/

#ifndef _CINO_ARRAY_H_
#define _CINO_ARRAY_H_

#include "cino_utils.h"

/****************************************
 *               array_t
 ****************************************/

typedef struct array_t array_t;

/**
 * @brief   Create cino-array.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - T (generic)
 * @return  Returns the pointer to cino-array, or `NULL` if creation failed.
 */
array_t *array_create(const str_t data_type);

/**
 * @brief   Destroy cino-array.
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-array.
 * @param array cino-array
 */
void array_destroy(array_t *array);

/**
 * @brief   Determine if the cino-array is empty.
 * @param array cino-array
 * @return  Returns `true` if the cino-array is empty, otherwise returns `false`.
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
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-array.
 * @param array cino-array
 * @return  Returns the modified cino-array.
 */
array_t *array_clear(array_t *array);

/**
 * @brief   Get the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive cino-array, this function returns a wrapper type of the
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T array_get(const array_t *array, int index);

/**
 * @brief   Update the element of the indexed component in the cino-array.
 * @param array cino-array
 * @param index index
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-array, it is caller's responsibility to free
 *              the previous data before overwriting it.
 */
void array_set(array_t *array, int index, T data);

/**
 * @brief   Appends the specified element to the end of the cino-array.
 * @param array cino-array
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-array, it is caller's responsibility to free
 *              the previous data before overwriting it.
 * @return  Returns the modified cino-array.
 */
array_t *array_append(array_t *array, T data);

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
array_t *array_insert(array_t *array, int index, T data);

/**
 * @brief   Removes the element at the specified position in the cino-array.
 * @param array cino-array
 * @param index index
 * @return  For primitive cino-array, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T array_remove(array_t *array, int index);

/**
 * @brief   Get the minimum value in the cino-array.
 * @param array     cino-array
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-array. Set to `NULL` if it is a primitive cino-array.
 * @return  Returns the minimum value in the cino-array, or `NULL` if conditions failed.
 *          For primitive cino-array, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T array_min(const array_t *array, compare_t compare);

/**
 * @brief   Get the maximum value in the cino-array.
 * @param array     cino-array
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-array. Set to `NULL` it is a primitive cino-array.
 * @return  Returns the maximum value in the cino-array, or `NULL` if conditions failed.
 *          For primitive cino-array, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T array_max(const array_t *array, compare_t compare);

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
int array_index_of(const array_t *array, void *context);

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
int array_last_index_of(const array_t *array, void *context);

/**
 * @brief   Count the occurrences of the element matched.
 * @param array     cino-array
 * @param context   - For primitive cino-array, a wrapper type of the counting data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-array, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns occurrences of the element matched.
 */
int array_count(const array_t *array, void *context);

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
 * @param reverse   true = descending, false = ascending
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-array. Set to `NULL` if it is a primitive cino-array.
 * @return  Returns the modified cino-array.
 */
array_t *array_sort(array_t *array, bool reverse, compare_t compare);

/**
 * @brief   Get the begin iterator.
 * @param array cino-array
 * @return  Returns the begin iterator.
 */
iter_t array_iter_begin(array_t *array);

/**
 * @brief   Get the end iterator.
 * @param array cino-array
 * @return  Returns the end iterator.
 */
iter_t array_iter_end(array_t *array);

/**
 * @brief   Determine if the cino-array has previous iterator.
 * @param array cino-array
 * @return  Returns `true` if previous iterator exists, otherwise returns `false`.
 */
bool array_iter_has_prev(const array_t *array);

/**
 * @brief   Determine if the cino-array has next iterator.
 * @param array cino-array
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool array_iter_has_next(const array_t *array);

/**
 * @brief   Get the previous iterator.
 * @param array cino-array
 * @return  Returns the previous iterator.
 */
iter_t array_iter_prev(array_t *array);

/**
 * @brief   Get the next iterator.
 * @param array cino-array
 * @return  Returns the next iterator.
 */
iter_t array_iter_next(array_t *array);

#endif