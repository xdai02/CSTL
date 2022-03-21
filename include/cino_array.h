/**************************************************
 * Module   :   cino_array
 * Function :   Operations on cino_array
 * Category :
 *              - array_int_t
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
 * @return  Returns the pointer to cino-int-array. Returns NULL if the creation failed.
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
 * @return  Returns true if the cino-int-array is empty, otherwise retuens false.
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
array_int_t *array_int_expend(array_int_t *array, int *arr, int arr_len);

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

#endif