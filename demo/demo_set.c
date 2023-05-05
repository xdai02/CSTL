#include <stdio.h>
#include "coop.h"

int main() {
    set_t *set1 = set_create(Integer_compare, Integer_delete);
    set_t *set2 = set_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        set_add(set1, Integer_new(i));
    }

    for (int i = 5; i < 15; i++) {
        set_add(set2, Integer_new(i));
    }

    set_t *set3 = set_intersection(set1, set2);

    iterator_t *iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        Integer *integer = set_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    return 0;
}
