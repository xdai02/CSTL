#include "set.h"
#include "red_black_tree.h"

struct set_t {
    red_black_tree_t *tree;
};

set_t *set_create(compare_t compare, destroy_t destroy) {
    return_value_if_fail(compare != NULL, NULL);

    set_t *set = (set_t *)malloc(sizeof(set_t));
    return_value_if_fail(set != NULL, NULL);

    set->tree = red_black_tree_create(compare, destroy);
    if (set->tree == NULL) {
        free(set);
        return NULL;
    }
    return set;
}

void set_destroy(set_t *set) {
    return_if_fail(set != NULL);
    red_black_tree_destroy(set->tree);
    free(set);
}

bool set_is_empty(const set_t *set) {
    return_value_if_fail(set != NULL, true);
    return red_black_tree_is_empty(set->tree);
}

size_t set_size(const set_t *set) {
    return_value_if_fail(set != NULL, 0);
    return red_black_tree_size(set->tree);
}

set_t *set_clear(set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    return red_black_tree_clear(set->tree);
}

bool set_contains(const set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, false);
    return red_black_tree_contains(set->tree, elem);
}

set_t *set_add(set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    return red_black_tree_insert(set->tree, elem);
}

set_t *set_remove(set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    return red_black_tree_remove(set->tree, elem);
}

