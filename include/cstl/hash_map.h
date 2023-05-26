#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"
#include "cstl/pair.h"
#include "iterator.h"

typedef struct hash_map_t hash_map_t;

/**
 * @brief Create a hash_map_t object.
 * @param compare Callback function for comparing two keys.
 * @param hash Callback function for hashing a key.
 * @return Returns the created hash_map_t object if successful, otherwise returns NULL.
 */
hash_map_t *hash_map_new(compare_t compare, hash_t hash);

/**
 * @brief Destroy a hash_map_t object.
 * @param map The hash_map_t object.
 */
void hash_map_delete(hash_map_t *map);

/**
 * @brief Determine whether a hash_map_t object is empty.
 * @param map The hash_map_t object.
 * @return Returns true if the hash_map_t object is empty, otherwise returns false.
 */
bool hash_map_is_empty(hash_map_t *map);

/**
 * @brief Get the size of a hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the size of the hash_map_t object.
 */
size_t hash_map_size(hash_map_t *map);

/**
 * @brief Traverse a hash_map_t object.
 * @param map The hash_map_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void hash_map_foreach(hash_map_t *map, visit_pair_t visit);

/**
 * @brief Clear a hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the modified hash_map_t object.
 */
hash_map_t *hash_map_clear(hash_map_t *map);

/**
 * @brief Check if a hash_map_t object contains the specified key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns true if the hash_map_t object contains the specified key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool hash_map_contains(const hash_map_t *map, T key);

/**
 * @brief Put a key-value pair into a hash_map_t object.
 * @param map The hash_map_t object.
 * @param pair The pair_t object.
 * @return Returns the modified hash_map_t object.
 */
hash_map_t *hash_map_put(hash_map_t *map, pair_t *pair);

/**
 * @brief Remove a key-value pair from a hash_map_t object by given key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns the modified hash_map_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
hash_map_t *hash_map_remove(hash_map_t *map, T key);

/**
 * @brief Get the value of a key-value pair by given key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T hash_map_get(const hash_map_t *map, T key);

/**
 * @brief Create an iterator for an hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the iterator for container.
 */
iterator_t *hash_map_iterator_new(const hash_map_t *map);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void hash_map_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool hash_map_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
T hash_map_iterator_next(iterator_t *iterator);

#endif
