#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct hash_table_t hash_table_t;

/**
 * @brief Create a hash_table_t object.
 * @param compare Callback function for comparing two keys.
 * @param destroy_key Callback function for destroying a key.
 * @param destroy_value Callback function for destroying a value.
 * @param hash Callback function for hashing a key.
 * @return Returns the created hash_table_t object if successful, otherwise returns NULL.
 */
hash_table_t *hash_table_create(compare_t compare, destroy_t destroy_key, destroy_t destroy_value, hash_t hash);

/**
 * @brief Destroy a hash_table_t object.
 * @param hash_table The hash_table_t object.
 */
void hash_table_destroy(hash_table_t *hash_table);

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
hash_table_t *hash_table_put(hash_table_t *hash_table, T key, T value);
hash_table_t *hash_table_remove(hash_table_t *hash_table, T key);
T hash_table_get(const hash_table_t *hash_table, T key);

#endif
