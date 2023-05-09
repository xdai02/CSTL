#include <stdio.h>
#include "coop.h"

int main() {
    ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
    ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        ordered_set_add(set1, Integer_new(i));
    }

    for (int i = 5; i < 15; i++) {
        ordered_set_add(set2, Integer_new(i));
    }

    ordered_set_t *set3 = ordered_set_intersection(set1, set2);

    iterator_t *iterator = ordered_set_iterator_create(set3);
    while (ordered_set_iterator_has_next(iterator)) {
        Integer *integer = ordered_set_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    ordered_set_iterator_destroy(iterator);
    ordered_set_delete(set1);
    ordered_set_delete(set2);
    ordered_set_delete(set3);

    return 0;
}
