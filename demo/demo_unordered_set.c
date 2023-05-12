#include <stdio.h>
#include "coop.h"

int main() {
    unordered_set_t *set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    unordered_set_t *set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (int i = 0; i < 10; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    for (int i = 5; i < 15; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    unordered_set_t *set3 = unordered_set_intersection(set1, set2);

    iterator_t *iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        Integer *integer = unordered_set_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    return 0;
}
