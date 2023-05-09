#ifndef _ORDERED_SET_H_
#define _ORDERED_SET_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct ordered_set_t ordered_set_t;

/**
 * @brief Create an ordered_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created ordered_set_t object if successful, otherwise returns NULL.
 */
ordered_set_t *ordered_set_new(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy an ordered_set_t object.
 * @param set The ordered_set_t object.
 */
void ordered_set_delete(ordered_set_t *set);

/**
 * @brief Determine whether an ordered_set_t object is empty.
 * @param set The ordered_set_t object.
 * @return Returns true if the ordered_set_t object is empty, otherwise returns false.
 */
bool ordered_set_is_empty(const ordered_set_t *set);

/**
 * @brief Get the size of an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the size of the ordered_set_t object.
 */
size_t ordered_set_size(const ordered_set_t *set);

/**
 * @brief Traverse an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void ordered_set_foreach(ordered_set_t *set, visit_t visit);

/**
 * @brief Clear an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the modified ordered_set_t object.
 */
ordered_set_t *ordered_set_clear(ordered_set_t *set);

/**
 * @brief Check if an ordered_set_t object contains the specified element.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns true if the ordered_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool ordered_set_contains(const ordered_set_t *set, T elem);

/**
 * @brief Add an element to the ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns the modified ordered_set_t object.
 */
ordered_set_t *ordered_set_add(ordered_set_t *set, T elem);

/**
 * @brief Remove the element from the ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns the modified ordered_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
ordered_set_t *ordered_set_remove(ordered_set_t *set, T elem);

/**
 * @brief Get the union of two ordered_set_t objects.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the union of two ordered_set_t objects.
 * @note Caller MUST destroy the returned union ordered_set_t object.
 */
ordered_set_t *ordered_set_union(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Get the intersection of two ordered_set_t objects.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the intersection of two ordered_set_t objects.
 * @note Caller MUST destroy the returned intersection ordered_set_t object.
 */
ordered_set_t *ordered_set_intersection(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Get the difference of two ordered_set_t objects.
 *        A - B
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the difference of two ordered_set_t objects.
 * @note Caller MUST destroy the returned difference ordered_set_t object.
 */
ordered_set_t *ordered_set_difference(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Get the symmetric difference of two ordered_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the symmetric difference of two ordered_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference ordered_set_t object.
 */
ordered_set_t *ordered_set_symmetric_difference(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Determine if two ordered_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns true if two ordered_set_t objects are disjoint, otherwise returns false.
 */
bool ordered_set_is_disjoint(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool ordered_set_is_subset(const ordered_set_t *set1, const ordered_set_t *set2);

/**
 * @brief Create an iterator for an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *ordered_set_iterator_new(const ordered_set_t *set);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void ordered_set_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool ordered_set_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T ordered_set_iterator_next(iterator_t *iterator);

#endif
