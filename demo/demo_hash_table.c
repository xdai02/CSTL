#include <stdio.h>
#include "coop.h"

int main() {
    hash_table_t *hash_table = hash_table_create(Integer_compare, Integer_delete, NULL, Integer_hash);

    hash_table_put(hash_table, Integer_new(1), "AAA");
    hash_table_put(hash_table, Integer_new(2), "BBB");

    hash_table_destroy(hash_table);
    return 0;
}
