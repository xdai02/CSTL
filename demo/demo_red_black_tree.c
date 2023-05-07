#include <stdio.h>
#include "coop.h"

int main() {
    red_black_tree_t *tree = red_black_tree_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }

    iterator_t *iterator = red_black_tree_iterator_create(tree);
    while (red_black_tree_iterator_has_next(iterator)) {
        Integer *integer = red_black_tree_iterator_next(iterator);
        printf("%d ", Integer_get(integer));
    }
    printf("\n");

    red_black_tree_iterator_destroy(iterator);
    red_black_tree_destroy(tree);

    return 0;
}
