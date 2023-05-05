#ifndef _SET_H_
#define _SET_H_

#include "utils.h"
#include "iterator.h"

typedef struct set_t set_t;

/**
 * @brief Create a set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created set_t object if successful, otherwise returns NULL.
 */
set_t *set_create(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy an set_t object.
 * @param set The set_t object.
 */
void set_destroy(set_t *set);

/**
 * @brief Determine whether an set_t object is empty.
 * @param set The set_t object.
 * @return Returns true if the set_t object is empty, otherwise returns false.
 */
bool set_is_empty(const set_t *set);

/**
 * @brief Get the size of an set_t object.
 * @param arsetay The set_t object.
 * @return Returns the size of the set_t object.
 */
size_t set_size(const set_t *set);

/**
 * @brief Clear an set_t object.
 * @param set The set_t object.
 * @return Returns the modified set_t object.
 */
set_t *set_clear(set_t *set);

/**
 * @brief Check if an set_t object contains the specified element.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns true if the set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter key (if applicable).
 */
bool set_contains(const set_t *set, T elem);

/**
 * @brief Add an element to the set_t object.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns the modified set_t object.
 */
set_t *set_add(set_t *set, T elem);

/**
 * @brief Remove the element from the set_t object.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns the modified set_t object.
 * @note Caller MUST free the parameter elem (if applicable).
 */
set_t *set_remove(set_t *set, T elem);

/**
 * @brief Get the union of two set_t objects.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the union of two set_t objects.
 * @note Caller MUST destroy the returned union set_t object.
 */
set_t *set_union(const set_t *set1, const set_t *set2);

/**
 * @brief Set the intersection of two set_t objects.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the intersection of two set_t objects.
 * @note Caller MUST destroy the returned intersection set_t object.
 */
set_t *set_intersection(const set_t *set1, const set_t *set2);

/**
 * @brief Get the difference of two set_t objects.
 *        A - B
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the difference of two set_t objects.
 * @note Caller MUST destroy the returned difference set_t object.
 */
set_t *set_difference(const set_t *set1, const set_t *set2);

/**
 * @brief Get the symmetric difference of two set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the symmetric difference of two set_t objects.
 * @note Caller MUST destroy the returned symmetric difference set_t object.
 */
set_t *set_symmetric_difference(const set_t *set1, const set_t *set2);

/**
 * @brief Determine if two set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns true if two set_t objects are disjoint, otherwise returns false.
 */
bool set_is_disjoint(const set_t *set1, const set_t *set2);

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool set_is_subset(const set_t *set1, const set_t *set2);

/**
 * @brief Create an iterator for an set_t object.
 * @param set The set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *set_iterator_create(const set_t *set);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void set_iterator_destroy(iterator_t *iterator);

/**
 * @brief Traverse an set_t object.
 * @param set The set_t object.
 * @param visit Callback function for visiting a data item.
 */
void set_foreach(set_t *set, visit_t visit);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool set_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T set_iterator_next(iterator_t *iterator);

#endif
