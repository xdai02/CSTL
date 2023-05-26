#include <stdio.h>
#include "cstl.h"

int main() {
    hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (int i = 0; i < 10; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    for (int i = 5; i < 15; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    hash_set_t *set3 = hash_set_intersection(set1, set2);

    iterator_t *iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        Integer *integer = hash_set_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    return 0;
}
