#include "cstl/tree_map.h"
#include "cstl/red_black_tree.h"

struct tree_map_t {
    red_black_tree_t *tree;
    compare_t compare;
};

tree_map_t *tree_map_new(compare_t compare, destroy_t destroy) {
    tree_map_t *map = NULL;

    return_value_if_fail(compare != NULL, NULL);

    map = (tree_map_t *)malloc(sizeof(tree_map_t));
    return_valueif_fail(map != NULL, NULL);

    map->tree = red_black_tree_new(compare, destroy);
    if (map->tree == NULL) {
        free(map);
        return NULL;
    }

    map->compare = compare;
    return map;
}

void tree_map_delete(tree_map_t *map) {
    return_if_fail(map != NULL);
    red_black_tree_delete(map->tree);
    free(map);
}

bool tree_map_is_empty(tree_map_t *map) {
    return_value_if_fail(map != NULL, true);
    return red_black_tree_is_empty(map->tree);
}

size_t tree_map_size(tree_map_t *map) {
    return_value_if_fail(map != NULL, 0);
    return red_black_tree_size(map->tree);
}

static visit_pair_t __visit = NULL;

static void __visit_pair(T pair) {
    return_if_fail(pair != NULL);
    pair = (pair_t *)pair;
    __visit(pair);
}

void tree_map_foreach(tree_map_t *map, visit_pair_t visit) {
    return_if_fail(map != NULL && visit != NULL);
    __visit = visit;
    red_black_tree_foreach(map->tree, __visit_pair);
}

tree_map_t *tree_map_clear(tree_map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    red_black_tree_clear(map->tree);
    return map;
}

tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair) {
    return_value_if_fail(map != NULL && pair != NULL, map);
    red_black_tree_insert(map->tree, pair);
    return map;
}

/* @note */
tree_map_t *tree_map_remove(tree_map_t *map, T key) {
    return_value_if_fail(map != NULL && key != NULL, map);
    red_black_tree_remove(map->tree, key);
    return map;
}

/* @note */
T tree_map_get(tree_map_t *map, T key) {
    iterator_t *iterator = NULL;
    pair_t *pair;

    return_value_if_fail(map != NULL && key != NULL, NULL);

    iterator = red_black_tree_iterator_new(map->tree);
    return_value_if_fail(iterator != NULL, NULL);

    while (red_black_tree_iterator_has_next(iterator)) {
        pair = (pair_t *)red_black_tree_iterator_next(iterator);
        if (map->compare(pair_get_key(pair), key) == 0) {
            red_black_tree_iterator_delete(iterator);
            return pair_get_value(pair);
        }
    }

    red_black_tree_iterator_delete(iterator);
    return NULL;
}
