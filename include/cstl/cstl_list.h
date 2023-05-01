#ifndef _CSTL_LIST_H_
#define _CSTL_LIST_H_

#include "utils.h"
#include "iterator.h"

typedef struct list_t list_t;

/**
 * @brief Create a list_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created list_t object if successful, otherwise returns NULL.
 */
list_t *list_create(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy a list_t object.
 * @param list The list_t object.
 */
void list_destroy(list_t *list);

/**
 * @brief Traverse the list_t object.
 * @param list The list_t object.
 * @param visit Callback function for visiting a data item.
 */
void list_foreach(list_t *list, visit_t visit);

/**
 * @brief Determine whether the list_t object is empty.
 * @param list The list_t object.
 * @return Returns true if the list_t object is empty, otherwise returns false.
 */
bool list_is_empty(const list_t *list);

/**
 * @brief Get the size of the list_t object.
 * @param list The list_t object.
 * @return Returns the size of the list_t object.
 */
size_t list_size(const list_t *list);

/**
 * @brief Clear the list_t object.
 * @param list The list_t object.
 * @return Returns the modified list_t object.
 */
list_t *list_clear(list_t *list);

/**
 * @brief Get the element at the specified index of a list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @return Returns the element at the specified index of the list_t object.
 */
T list_get(const list_t *list, size_t index);

/**
 * @brief Set the element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_set(list_t *list, size_t index, T elem);

/**
 * @brief Get the index of the specified element in the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the index of the specified element if found, otherwise returns -1.
 */
int list_index_of(const list_t *list, T elem);

/**
 * @brief Determine whether the list_t object contains the specified element.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns true if the list_t object contains the specified element, otherwise returns false.
 */
bool list_contains(const list_t *list, T elem);

/**
 * @brief Count the number of occurrences of the specified element in the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the number of occurrences of the specified element.
 */
size_t list_count(const list_t *list, T elem);

/**
 * @brief Get the first element of the list_t object.
 * @param list The list_t object.
 * @return Returns the first element if successful, otherwise returns NULL.
 */
T list_get_front(const list_t *list);

/**
 * @brief Get the last element of the list_t object.
 * @param list The list_t object.
 * @return Returns the last element if successful, otherwise returns NULL.
 */
T list_get_back(const list_t *list);

/**
 * @brief Insert the specified element at the beginning of the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_push_front(list_t *list, T elem);

/**
 * @brief Insert the specified element at the end of the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_push_back(list_t *list, T elem);

/**
 * @brief Remove the first element of the list_t object.
 * @param list The list_t object.
 * @return Returns the removed element if successful, otherwise returns NULL.
 */
T list_pop_front(list_t *list);

/**
 * @brief Remove the last element of the list_t object.
 * @param list The list_t object.
 * @return Returns the removed element if successful, otherwise returns NULL.
 */
T list_pop_back(list_t *list);

/**
 * @brief Insert the specified element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_insert(list_t *list, size_t index, T elem);

/**
 * @brief Removes the element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @return Returns the removed element if successful, otherwise returns NULL.
 */
T list_remove(list_t *list, size_t index);

/**
 * @brief Reverse the list_t object.
 * @param list The list_t object.
 * @return Returns the modified list_t object.
 */
list_t *list_reverse(list_t *list);

/**
 * @brief Create an iterator for an list_t object.
 * @param list The list_t object.
 * @return Returns the iterator for container.
 */
iterator_t *list_iterator_create(const list_t *list);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void list_iterator_destroy(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool list_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T list_iterator_next(iterator_t *iterator);

#endif
