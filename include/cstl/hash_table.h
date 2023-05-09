#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct pair_t {
    T key;
    T value;
} pair_t;

typedef struct hash_table_t hash_table_t;

/**
 * @brief Create a hash_table_t object.
 * @param compare Callback function for comparing two keys.
 * @param destroy_key Callback function for destroying a key.
 * @param destroy_value Callback function for destroying a value.
 * @param hash Callback function for hashing a key.
 * @return Returns the created hash_table_t object if successful, otherwise returns NULL.
 */
hash_table_t *hash_table_new(compare_t compare, destroy_t destroy_key, destroy_t destroy_value, hash_t hash);

/**
 * @brief Destroy a hash_table_t object.
 * @param hash_table The hash_table_t object.
 */
void hash_table_delete(hash_table_t *hash_table);

/**
 * @brief Determine whether a hash_table_t object is empty.
 * @param hash_table The hash_table_t object.
 * @return Returns true if the hash_table_t object is empty, otherwise returns false.
 */
bool hash_table_is_empty(const hash_table_t *hash_table);

/**
 * @brief Get the size of a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the size of the hash_table_t object.
 */
size_t hash_table_size(const hash_table_t *hash_table);

/**
 * @brief Traverse a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void hash_table_foreach(hash_table_t *hash_table, visit_pair_t visit);

/**
 * @brief Clear a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the modified hash_table_t object.
 */
hash_table_t *hash_table_clear(hash_table_t *hash_table);

/**
 * @brief Put a key-value pair into a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @param value The value.
 * @return Returns the modified hash_table_t object.
 */
hash_table_t *hash_table_put(hash_table_t *hash_table, T key, T value);

/**
 * @brief Remove a key-value pair from a hash_table_t object by given key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns the modified hash_table_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
hash_table_t *hash_table_remove(hash_table_t *hash_table, T key);

/**
 * @brief Get the value of a key-value pair by given key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T hash_table_get(const hash_table_t *hash_table, T key);

/**
 * @brief Create an iterator for a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the iterator for container.
 */
iterator_t *hash_table_iterator_new(const hash_table_t *hash_table);

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void hash_table_iterator_delete(iterator_t *iterator);

/**
 * @brief Determine whether an iterator has the next pair.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next pair, otherwise returns false.
 */
bool hash_table_iterator_has_next(const iterator_t *iterator);

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
pair_t *hash_table_iterator_next(iterator_t *iterator);

#endif
