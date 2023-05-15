#include "cstl/hash_map.h"
#include "cstl/hash_table.h"

struct hash_map_t {
    hash_table_t *hash_table;
};

/**
 * @brief Create a hash_map_t object.
 * @param compare Callback function for comparing two keys.
 * @param hash Callback function for hashing a key.
 * @return Returns the created hash_map_t object if successful, otherwise returns NULL.
 */
hash_map_t *hash_map_new(compare_t compare, hash_t hash) {
    hash_map_t *map = NULL;

    return_value_if_fail(compare != NULL, NULL);

    map = (hash_map_t *)malloc(sizeof(hash_map_t));
    return_value_if_fail(map != NULL, NULL);

    map->hash_table = hash_table_new(compare, hash);
    return map;
}

/**
 * @brief Destroy a hash_map_t object.
 * @param map The hash_map_t object.
 */
void hash_map_delete(hash_map_t *map) {
    return_if_fail(map != NULL);
    hash_table_delete(map->hash_table);
    free(map);
}

/**
 * @brief Determine whether a hash_map_t object is empty.
 * @param map The hash_map_t object.
 * @return Returns true if the hash_map_t object is empty, otherwise returns false.
 */
bool hash_map_is_empty(hash_map_t *map) {
    return_value_if_fail(map != NULL, true);
    return hash_table_is_empty(map->hash_table);
}

/**
 * @brief Get the size of a hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the size of the hash_map_t object.
 */
size_t hash_map_size(hash_map_t *map) {
    return_value_if_fail(map != NULL, 0);
    return hash_table_size(map->hash_table);
}

/**
 * @brief Traverse a hash_map_t object.
 * @param map The hash_map_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void hash_map_foreach(hash_map_t *map, visit_pair_t visit) {
    return_if_fail(map != NULL);
    hash_table_foreach(map->hash_table, visit);
}

/**
 * @brief Clear a hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the modified hash_map_t object.
 */
hash_map_t *hash_map_clear(hash_map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    hash_table_clear(map->hash_table);
    return map;
}

/**
 * @brief Check if a hash_map_t object contains the specified key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns true if the hash_map_t object contains the specified key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool hash_map_contains(const hash_map_t *map, T key) {
    return_value_if_fail(map != NULL && key != NULL, false);
    return hash_table_contains(map->hash_table, key);
}

/**
 * @brief Put a key-value pair into a hash_map_t object.
 * @param map The hash_map_t object.
 * @param pair The pair_t object.
 * @return Returns the modified hash_map_t object.
 */
hash_map_t *hash_map_put(hash_map_t *map, pair_t *pair) {
    return_value_if_fail(map != NULL && pair != NULL, map);
    hash_table_put(map->hash_table, pair);
    return map;
}

/**
 * @brief Remove a key-value pair from a hash_map_t object by given key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns the modified hash_map_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
hash_map_t *hash_map_remove(hash_map_t *map, T key) {
    return_value_if_fail(map != NULL && key != NULL, map);
    hash_table_remove(map->hash_table, key);
    return map;
}

/**
 * @brief Get the value of a key-value pair by given key.
 * @param map The hash_map_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T hash_map_get(const hash_map_t *map, T key) {
    return_value_if_fail(map != NULL && key != NULL, NULL);
    return hash_table_get(map->hash_table, key);
}

/**
 * @brief Create an iterator for an hash_map_t object.
 * @param map The hash_map_t object.
 * @return Returns the iterator for container.
 */
iterator_t *hash_map_iterator_new(const hash_map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    return hash_table_iterator_new(map->hash_table);
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void hash_map_iterator_delete(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    hash_table_iterator_delete(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool hash_map_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return hash_table_iterator_has_next(iterator);
}

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
T hash_map_iterator_next(iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, NULL);
    return hash_table_iterator_next(iterator);
}
