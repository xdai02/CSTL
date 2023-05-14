#include "cstl/tree_map.h"
#include "cstl/red_black_tree.h"

struct tree_map_t {
    red_black_tree_t *tree;
    compare_t compare;
};

static compare_t __compare = NULL;

/**
 * @brief Private function for comparing two pair_t objects.
 * @param data1 The first pair_t object.
 * @param data2 The second pair_t object.
 * @return Returns negative value if the first element is less than the second element.
 *         Returns 0 if the first element is equal to the second element.
 *         Returns positive value if the first element is greater than the second element.
 */
static int __pair_compare(const T data1, const T data2) {
    pair_t *pair1 = (pair_t *)data1;
    pair_t *pair2 = (pair_t *)data2;
    return __compare(pair_get_key(pair1), pair_get_key(pair2));
}

/**
 * @brief Create a tree_map_t object.
 * @param compare Callback function for comparing two keys.
 * @return Returns the created tree_map_t object if successful, otherwise returns NULL.
 */
tree_map_t *tree_map_new(compare_t compare) {
    tree_map_t *map = NULL;

    return_value_if_fail(compare != NULL, NULL);

    map = (tree_map_t *)malloc(sizeof(tree_map_t));
    return_value_if_fail(map != NULL, NULL);

    __compare = compare;
    map->tree = red_black_tree_new(__pair_compare, (destroy_t)pair_delete);
    if (map->tree == NULL) {
        free(map);
        return NULL;
    }

    map->compare = compare;
    return map;
}

/**
 * @brief Destroy a tree_map_t object.
 * @param map The tree_map_t object.
 */
void tree_map_delete(tree_map_t *map) {
    return_if_fail(map != NULL);
    red_black_tree_delete(map->tree);
    free(map);
}

/**
 * @brief Determine whether a tree_map_t object is empty.
 * @param map The tree_map_t object.
 * @return Returns true if the tree_map_t object is empty, otherwise returns false.
 */
bool tree_map_is_empty(tree_map_t *map) {
    return_value_if_fail(map != NULL, true);
    return red_black_tree_is_empty(map->tree);
}

/**
 * @brief Get the size of a tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the size of the tree_map_t object.
 */
size_t tree_map_size(tree_map_t *map) {
    return_value_if_fail(map != NULL, 0);
    return red_black_tree_size(map->tree);
}

static visit_pair_t __visit = NULL;

/**
 * @brief Pirvate function for visiting a pair_t object.
 * @param pair The pair_t object.
 */
static void __visit_pair(T pair) {
    return_if_fail(pair != NULL);
    pair = (pair_t *)pair;
    __visit(pair);
}

/**
 * @brief Traverse a tree_map_t object.
 * @param map The tree_map_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void tree_map_foreach(tree_map_t *map, visit_pair_t visit) {
    return_if_fail(map != NULL && visit != NULL);
    __visit = visit;
    red_black_tree_foreach(map->tree, __visit_pair);
}

/**
 * @brief Clear a tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the modified tree_map_t object.
 */
tree_map_t *tree_map_clear(tree_map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    red_black_tree_clear(map->tree);
    return map;
}

/**
 * @brief Check if a tree_map_t object contains the specified key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns true if the tree_map_t object contains the specified key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool tree_map_contains(const tree_map_t *map, T key) {
    pair_t *pair = NULL;
    bool found = false;

    return_value_if_fail(map != NULL && key != NULL, false);

    pair = pair_new(key, NULL, NULL, NULL);
    found = red_black_tree_contains(map->tree, pair);
    pair_delete(pair);

    return found;
}

/**
 * @brief Put a key-value pair into a tree_map_t object.
 * @param map The tree_map_t object.
 * @param pair The pair_t object.
 * @return Returns the modified tree_map_t object.
 */
tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair) {
    return_value_if_fail(map != NULL && pair != NULL, map);

    if (red_black_tree_contains(map->tree, pair)) {
        red_black_tree_remove(map->tree, pair);
    }
    red_black_tree_insert(map->tree, pair);
    return map;
}

/**
 * @brief Remove a key-value pair from a tree_map_t object by given key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns the modified tree_map_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
tree_map_t *tree_map_remove(tree_map_t *map, T key) {
    pair_t *pair = NULL;

    return_value_if_fail(map != NULL && key != NULL, map);

    pair = pair_new(key, NULL, NULL, NULL);
    red_black_tree_remove(map->tree, pair);
    pair_delete(pair);

    return map;
}

/**
 * @brief Get the value of a key-value pair by given key.
 * @param map The tree_map_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T tree_map_get(const tree_map_t *map, T key) {
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

/**
 * @brief Create an iterator for an tree_map_t object.
 * @param map The tree_map_t object.
 * @return Returns the iterator for container.
 */
iterator_t *tree_map_iterator_new(const tree_map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    return red_black_tree_iterator_new(map->tree);
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void tree_map_iterator_delete(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    red_black_tree_iterator_delete(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool tree_map_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return red_black_tree_iterator_has_next(iterator);
}

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
T tree_map_iterator_next(iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, NULL);
    return red_black_tree_iterator_next(iterator);
}
