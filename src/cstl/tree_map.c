#include "cstl/tree_map.h"
#include "cstl/red_black_tree.h"

struct tree_map_t {
    red_black_tree_t *tree;
    compare_t compare;
};

static compare_t __compare = NULL;

static int __pair_compare(const T data1, const T data2) {
    pair_t *pair1 = (pair_t *)data1;
    pair_t *pair2 = (pair_t *)data2;
    return __compare(pair_get_key(pair1), pair_get_key(pair2));
}

tree_map_t *tree_map_new(compare_t compare, destroy_t destroy) {
    tree_map_t *map = NULL;

    return_value_if_fail(compare != NULL, NULL);

    map = (tree_map_t *)malloc(sizeof(tree_map_t));
    return_value_if_fail(map != NULL, NULL);

    __compare = compare;
    map->tree = red_black_tree_new(__pair_compare, destroy);
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

    if (red_black_tree_contains(map->tree, pair)) {
        red_black_tree_remove(map->tree, pair);
    }
    red_black_tree_insert(map->tree, pair);
    return map;
}

/* @note */
tree_map_t *tree_map_remove(tree_map_t *map, T key) {
    pair_t *pair = NULL;

    return_value_if_fail(map != NULL && key != NULL, map);

    pair = pair_new(key, NULL, NULL, NULL);
    red_black_tree_remove(map->tree, pair);
    pair_delete(pair);

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
