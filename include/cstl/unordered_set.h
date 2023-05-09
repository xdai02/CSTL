#ifndef _UNORDERED_SET_H_
#define _UNORDERED_SET_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct unordered_set_t unordered_set_t;

/**
 * @brief Create an unordered_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @param hash Callback function for hashing a data item.
 * @return Returns the created unordered_set_t object if successful, otherwise returns NULL.
 */
unordered_set_t *unordered_set_new(compare_t compare, destroy_t destroy, hash_t hash);

/**
 * @brief Destroy an unordered_set_t object.
 * @param set The unordered_set_t object.
 */
void unordered_set_delete(unordered_set_t *set);

/**
 * @brief Determine whether an unordered_set_t object is empty.
 * @param set The unordered_set_t object.
 * @return Returns true if the unordered_set_t object is empty, otherwise returns false.
 */
bool unordered_set_is_empty(const unordered_set_t *set);

/**
 * @brief Get the size of an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the size of the unordered_set_t object.
 */
size_t unordered_set_size(const unordered_set_t *set);

/**
 * @brief Traverse an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void unordered_set_foreach(unordered_set_t *set, visit_t visit);

/**
 * @brief Clear an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the modified unordered_set_t object.
 */
unordered_set_t *unordered_set_clear(unordered_set_t *set);

/**
 * @brief Check if an unordered_set_t object contains the specified element.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns true if the unordered_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool unordered_set_contains(const unordered_set_t *set, T elem);

/**
 * @brief Add an element to the unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns the modified unordered_set_t object.
 */
unordered_set_t *unordered_set_add(unordered_set_t *set, T elem);

/**
 * @brief Remove the element from the unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns the modified unordered_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
unordered_set_t *unordered_set_remove(unordered_set_t *set, T elem);

/**
 * @brief Get the union of two unordered_set_t objects.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the union of two unordered_set_t objects.
 * @note Caller MUST destroy the returned union unordered_set_t object.
 */
unordered_set_t *unordered_set_union(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Get the intersection of two unordered_set_t objects.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the intersection of two unordered_set_t objects.
 * @note Caller MUST destroy the returned intersection unordered_set_t object.
 */
unordered_set_t *unordered_set_intersection(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Get the difference of two unordered_set_t objects.
 *        A - B
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the difference of two unordered_set_t objects.
 * @note Caller MUST destroy the returned difference unordered_set_t object.
 */
unordered_set_t *unordered_set_difference(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Get the symmetric difference of two unordered_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the symmetric difference of two unordered_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference unordered_set_t object.
 */
unordered_set_t *unordered_set_symmetric_difference(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Determine if two unordered_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns true if two unordered_set_t objects are disjoint, otherwise returns false.
 */
bool unordered_set_is_disjoint(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool unordered_set_is_subset(const unordered_set_t *set1, const unordered_set_t *set2);

/**
 * @brief Create an iterator for an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *unordered_set_iterator_create(const unordered_set_t *set);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void unordered_set_iterator_destroy(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool unordered_set_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T unordered_set_iterator_next(iterator_t *iterator);

#endif
