#include <stdio.h>
#include "coop.h"

int main() {
    tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
    tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    for (int i = 5; i < 15; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    tree_set_t *set3 = tree_set_intersection(set1, set2);

    iterator_t *iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        Integer *integer = tree_set_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    return 0;
}
