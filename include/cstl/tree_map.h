#ifndef _TREE_MAP_H_
#define _TREE_MAP_H_

#include "utils/utils.h"
#include "cstl/pair.h"
#include "iterator.h"

typedef struct tree_map_t tree_map_t;

/**
 * @brief Create a tree_map_t object.
 * @param compare Callback function for comparing two keys.
 * @return Returns the created hash_table_t object if successful, otherwise returns NULL.
 */
tree_map_t *tree_map_new(compare_t compare);

/**
 * @brief Destroy a tree_map_t object.
 * @param map The tree_map_t object.
 */
void tree_map_delete(tree_map_t *map);

/**
 * @brief Determine whether a tree_map_t object is empty.
 * @param map The tree_map_t object.
 * @return Returns true if the tree_map_t object is empty, otherwise returns false.
 */
bool tree_map_is_empty(tree_map_t *map);

/**
 * @brief Get the size of a tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the size of the tree_map_t object.
 */
size_t tree_map_size(tree_map_t *map);

/**
 * @brief Traverse a tree_map_t object.
 * @param map The tree_map_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void tree_map_foreach(tree_map_t *map, visit_pair_t visit);

/**
 * @brief Clear a tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the modified tree_map_t object.
 */
tree_map_t *tree_map_clear(tree_map_t *map);

/**
 * @brief Check if a tree_map_t object contains the specified key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns true if the tree_map_t object contains the specified key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool tree_map_contains(const tree_map_t *map, T key);

/**
 * @brief Put a key-value pair into a tree_map_t object.
 * @param map The tree_map_t object.
 * @param pair The pair_t object.
 * @return Returns the modified tree_map_t object.
 */
tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair);

/**
 * @brief Remove a key-value pair from a tree_map_t object by given key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns the modified tree_map_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
tree_map_t *tree_map_remove(tree_map_t *map, T key);

/**
 * @brief Get the value of a key-value pair by given key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T tree_map_get(const tree_map_t *map, T key);

/**
 * @brief Create an iterator for an tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the iterator for container.
 */
iterator_t *tree_map_iterator_new(const tree_map_t *map);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void tree_map_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool tree_map_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
T tree_map_iterator_next(iterator_t *iterator);

#endif
