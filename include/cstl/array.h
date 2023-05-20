#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct array_t array_t;

/**
 * @brief Create an array_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created array_t object if successful, otherwise returns NULL.
 */
array_t *array_new(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy an array_t object.
 * @param array The array_t object.
 */
void array_delete(array_t *array);

/**
 * @brief Determine whether an array_t object is empty.
 * @param array The array_t object.
 * @return Returns true if the array_t object is empty, otherwise returns false.
 */
bool array_is_empty(const array_t *array);

/**
 * @brief Get the size of an array_t object.
 * @param array The array_t object.
 * @return Returns the size of the array_t object.
 */
size_t array_size(const array_t *array);

/**
 * @brief Traverse an array_t object.
 * @param array The array_t object.
 * @param visit Callback function for visiting a data item.
 */
void array_foreach(array_t *array, visit_t visit);

/**
 * @brief Clear an array_t object.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_clear(array_t *array);

/**
 * @brief Get the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @return Returns the element at the specified index of the array_t object.
 */
T array_get(const array_t *array, size_t index);

/**
 * @brief Set the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @param elem  The element.
 * @return Returns the modified array_t object.
 */
array_t *array_set(array_t *array, size_t index, T elem);

/**
 * @brief Append an element to the end of an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the modified array_t object.
 */
array_t *array_append(array_t *array, T elem);

/**
 * @brief Insert an element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified array_t object.
 */
array_t *array_insert(array_t *array, size_t index, T elem);

/**
 * @brief Remove the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @return Returns the removed element.
 * @note Caller MUST free the returned element (if applicable).
 */
T array_remove(array_t *array, size_t index);

/**
 * @brief Get the index of the specified element in an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the index of the specified element in the array_t object.
 */
size_t array_index_of(const array_t *array, T elem);

/**
 * @brief Check if an array_t object contains the specified element.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns true if the array_t object contains the specified element, otherwise returns false.
 */
bool array_contains(const array_t *array, T elem);

/**
 * @brief Count the number of occurrences of the specified element in an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the number of occurrences of the specified element in the array_t object.
 */
size_t array_count(const array_t *array, T elem);

/**
 * @brief Reverse an array_t object.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_reverse(array_t *array);

/**
 * @brief Sort an array_t object in ascending order.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_sort(array_t *array);

/**
 * @brief Create an iterator for an array_t object.
 * @param array The array_t object.
 * @return Returns the iterator for container.
 */
iterator_t *array_iterator_new(const array_t *array);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void array_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool array_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T array_iterator_next(iterator_t *iterator);

#endif
