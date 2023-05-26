#ifndef _HASH_SET_H_
#define _HASH_SET_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"
#include "iterator.h"

typedef struct hash_set_t hash_set_t;

/**
 * @brief Create a hash_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @param hash Callback function for hashing a data item.
 * @return Returns the created hash_set_t object if successful, otherwise returns NULL.
 */
hash_set_t *hash_set_new(compare_t compare, destroy_t destroy, hash_t hash);

/**
 * @brief Destroy a hash_set_t object.
 * @param set The hash_set_t object.
 */
void hash_set_delete(hash_set_t *set);

/**
 * @brief Determine whether a hash_set_t object is empty.
 * @param set The hash_set_t object.
 * @return Returns true if the hash_set_t object is empty, otherwise returns false.
 */
bool hash_set_is_empty(const hash_set_t *set);

/**
 * @brief Get the size of a hash_set_t object.
 * @param set The hash_set_t object.
 * @return Returns the size of the hash_set_t object.
 */
size_t hash_set_size(const hash_set_t *set);

/**
 * @brief Traverse a hash_set_t object.
 * @param set The hash_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void hash_set_foreach(hash_set_t *set, visit_t visit);

/**
 * @brief Clear a hash_set_t object.
 * @param set The hash_set_t object.
 * @return Returns the modified hash_set_t object.
 */
hash_set_t *hash_set_clear(hash_set_t *set);

/**
 * @brief Check if a hash_set_t object contains the specified element.
 * @param set The hash_set_t object.
 * @param elem The element.
 * @return Returns true if the hash_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool hash_set_contains(const hash_set_t *set, T elem);

/**
 * @brief Add an element to the hash_set_t object.
 * @param set The hash_set_t object.
 * @param elem The element.
 * @return Returns the modified hash_set_t object.
 */
hash_set_t *hash_set_add(hash_set_t *set, T elem);

/**
 * @brief Remove the element from the hash_set_t object.
 * @param set The hash_set_t object.
 * @param elem The element.
 * @return Returns the modified hash_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
hash_set_t *hash_set_remove(hash_set_t *set, T elem);

/**
 * @brief Get the union of two hash_set_t objects.
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns the union of two hash_set_t objects.
 * @note Caller MUST destroy the returned union hash_set_t object.
 */
hash_set_t *hash_set_union(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Get the intersection of two hash_set_t objects.
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns the intersection of two hash_set_t objects.
 * @note Caller MUST destroy the returned intersection hash_set_t object.
 */
hash_set_t *hash_set_intersection(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Get the difference of two hash_set_t objects.
 *        A - B
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns the difference of two hash_set_t objects.
 * @note Caller MUST destroy the returned difference hash_set_t object.
 */
hash_set_t *hash_set_difference(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Get the symmetric difference of two hash_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns the symmetric difference of two hash_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference hash_set_t object.
 */
hash_set_t *hash_set_symmetric_difference(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Determine if two hash_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns true if two hash_set_t objects are disjoint, otherwise returns false.
 */
bool hash_set_is_disjoint(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first hash_set_t object.
 * @param set2 The second hash_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool hash_set_is_subset(const hash_set_t *set1, const hash_set_t *set2);

/**
 * @brief Create an iterator for a hash_set_t object.
 * @param set The hash_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *hash_set_iterator_new(const hash_set_t *set);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void hash_set_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool hash_set_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T hash_set_iterator_next(iterator_t *iterator);

#endif
