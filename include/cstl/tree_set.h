#ifndef _TREE_SET_H_
#define _TREE_SET_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"
#include "iterator.h"

typedef struct tree_set_t tree_set_t;

/**
 * @brief Create a tree_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created tree_set_t object if successful, otherwise returns NULL.
 */
tree_set_t *tree_set_new(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy a tree_set_t object.
 * @param set The tree_set_t object.
 */
void tree_set_delete(tree_set_t *set);

/**
 * @brief Determine whether a tree_set_t object is empty.
 * @param set The tree_set_t object.
 * @return Returns true if the tree_set_t object is empty, otherwise returns false.
 */
bool tree_set_is_empty(const tree_set_t *set);

/**
 * @brief Get the size of a tree_set_t object.
 * @param set The tree_set_t object.
 * @return Returns the size of the tree_set_t object.
 */
size_t tree_set_size(const tree_set_t *set);

/**
 * @brief Traverse a tree_set_t object.
 * @param set The tree_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void tree_set_foreach(tree_set_t *set, visit_t visit);

/**
 * @brief Clear a tree_set_t object.
 * @param set The tree_set_t object.
 * @return Returns the modified tree_set_t object.
 */
tree_set_t *tree_set_clear(tree_set_t *set);

/**
 * @brief Check if a tree_set_t object contains the specified element.
 * @param set The tree_set_t object.
 * @param elem The element.
 * @return Returns true if the tree_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool tree_set_contains(const tree_set_t *set, T elem);

/**
 * @brief Add an element to the tree_set_t object.
 * @param set The tree_set_t object.
 * @param elem The element.
 * @return Returns the modified tree_set_t object.
 */
tree_set_t *tree_set_add(tree_set_t *set, T elem);

/**
 * @brief Remove the element from the tree_set_t object.
 * @param set The tree_set_t object.
 * @param elem The element.
 * @return Returns the modified tree_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
tree_set_t *tree_set_remove(tree_set_t *set, T elem);

/**
 * @brief Get the union of two tree_set_t objects.
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns the union of two tree_set_t objects.
 * @note Caller MUST destroy the returned union tree_set_t object.
 */
tree_set_t *tree_set_union(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Get the intersection of two tree_set_t objects.
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns the intersection of two tree_set_t objects.
 * @note Caller MUST destroy the returned intersection tree_set_t object.
 */
tree_set_t *tree_set_intersection(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Get the difference of two tree_set_t objects.
 *        A - B
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns the difference of two tree_set_t objects.
 * @note Caller MUST destroy the returned difference tree_set_t object.
 */
tree_set_t *tree_set_difference(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Get the symmetric difference of two tree_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns the symmetric difference of two tree_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference tree_set_t object.
 */
tree_set_t *tree_set_symmetric_difference(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Determine if two tree_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns true if two tree_set_t objects are disjoint, otherwise returns false.
 */
bool tree_set_is_disjoint(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first tree_set_t object.
 * @param set2 The second tree_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool tree_set_is_subset(const tree_set_t *set1, const tree_set_t *set2);

/**
 * @brief Create an iterator for a tree_set_t object.
 * @param set The tree_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *tree_set_iterator_new(const tree_set_t *set);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void tree_set_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool tree_set_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T tree_set_iterator_next(iterator_t *iterator);

#endif
