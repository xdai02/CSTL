#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "utils/utils.h"
#include "iterator.h"

typedef struct hash_table_t hash_table_t;

hash_table_t *hash_table_create(compare_t compare, destroy_t destroy_key, destroy_t destroy_value, hash_t hash);
void hash_table_destroy(hash_table_t *hash_table);
bool hash_table_is_empty(const hash_table_t *hash_table);
size_t hash_table_size(const hash_table_t *hash_table);
hash_table_t *hash_table_clear(hash_table_t *hash_table);
hash_table_t *hash_table_put(hash_table_t *hash_table, T key, T value);
hash_table_t *hash_table_remove(hash_table_t *hash_table, T key);
T hash_table_get(const hash_table_t *hash_table, T key);

#endif
