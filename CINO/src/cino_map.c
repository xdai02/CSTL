#include "cino_map.h"
#include "cino_string.h"
#include "cino_tree.h"

/****************************************
 *               map_t
 ****************************************/

typedef struct kv_pair_t {
    string_t *key;
    T value;
    destroy_t destroy;
} kv_pair_t;

typedef struct map_t {
    tree_t *tree;
    size_t size;
    destroy_t destroy;
} map_t;

/**
 * @brief   Create a key-value pair.
 * @param key       key only in string format
 * @param value     value
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `destroy_int` if the value is of type wrapper_int_t
 *                      - `destroy_double` if the value is of type wrapper_double_t
 *                      - `destroy_char` if the value is of type wrapper_char_t
 *                      - `destroy_t` interface if the value is of type T,
 *                         otherwise a default `destroy_default` is applied.
 * @return  Returns the pointer to the key-value pair, or `NULL` if creation failed.
 */
static kv_pair_t *kv_pair_create(const str_t key, T value, destroy_t destroy) {
    kv_pair_t *kv_pair = (kv_pair_t *)calloc(1, sizeof(kv_pair_t));
    return_value_if_fail(kv_pair != NULL, NULL);

    kv_pair->key = string_create(key);
    call_and_return_value_if_fail(kv_pair->key != NULL, free(kv_pair), NULL);
    kv_pair->value = value;
    kv_pair->destroy = destroy;

    return kv_pair;
}

/**
 * @brief   Specify the rules for comparing two kv_pair_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_kv_pair(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    kv_pair_t *kv_pair1 = (kv_pair_t *)data1;
    kv_pair_t *kv_pair2 = (kv_pair_t *)data2;
    string_t *string1 = kv_pair1->key;
    string_t *string2 = kv_pair2->key;
    return strncmp(string_get(string1), string_get(string2), max(string_length(string1), string_length(string2)));
}

/**
 * @brief   Specify the rules for destroying a single kv_pair_t element.
 * @param data  pointer to the element
 */
static void destroy_kv_pair(T data) {
    return_if_fail(data != NULL);
    kv_pair_t *kv_pair = (kv_pair_t *)data;
    string_destroy(kv_pair->key);
    kv_pair->destroy(kv_pair->value);
    free(kv_pair);
    kv_pair = NULL;
}

/**
 * @brief   Get the key of a key-value pair.
 * @param kv_pair   key-value pair
 * @return  key in string format.
 */
const str_t kv_pair_get_key(kv_pair_t *kv_pair) {
    return_value_if_fail(kv_pair != NULL, "");
    return string_get(kv_pair->key);
}

/**
 * @brief   Get the value of a key-value pair.
 * @param kv_pair   key-value pair
 * @return  value
 */
T kv_pair_get_value(kv_pair_t *kv_pair) {
    return_value_if_fail(kv_pair != NULL, NULL);
    return kv_pair->value;
}

/**
 * @brief   Create cino-map.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `destroy_int` if the value is of type wrapper_int_t
 *                      - `destroy_double` if the value is of type wrapper_double_t
 *                      - `destroy_char` if the value is of type wrapper_char_t
 *                      - `destroy_t` interface if the value is of type T,
 *                         otherwise a default `destroy_default` is applied.
 * @return  Returns the pointer to cino-map, or `NULL` if creation failed.
 */
map_t *map_create(destroy_t destroy) {
    map_t *map = (map_t *)calloc(1, sizeof(map_t));
    return_value_if_fail(map != NULL, NULL);

    map->tree = tree_create(DATA_TYPE_T, compare_kv_pair, destroy_kv_pair);
    call_and_return_value_if_fail(map->tree != NULL, free(map), NULL);

    map->size = 0;
    map->destroy = destroy ? destroy : destroy_default;
    return map;
}

/**
 * @brief   Destroy cino-map.
 * @param map   cino-map
 */
void map_destroy(map_t *map) {
    return_if_fail(map != NULL);

    map_clear(map);
    tree_destroy(map->tree);
    map->destroy = NULL;

    if (map) {
        free(map);
        map = NULL;
    }
}

/**
 * @brief   Determine if the cino-map is empty.
 * @param map   cino-map
 * @return  Returns `true` if the cino-map is empty, otherwise returns `false`.
 */
bool map_is_empty(const map_t *map) {
    return !map || map->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-map.
 * @param map   cino-map
 * @return  Returns the number of elements in the cino-map.
 */
size_t map_size(const map_t *map) {
    return_value_if_fail(map != NULL, 0);
    return map->size;
}

/**
 * @brief   Clear all the elments in the cino-map.
 * @param map   cino-map
 * @return  Returns the modified cino-map.
 */
map_t *map_clear(map_t *map) {
    return_value_if_fail(map != NULL, NULL);
    tree_clear(map->tree);
    map->size = 0;
    return map;
}

/**
 * @brief   Traverse cino-map.
 * @param map   cino-map
 * @param visit user-defined callback function for visiting a single element
 */
void map_foreach(map_t *map, visit_t visit) {
    return_if_fail(map != NULL && visit != NULL);
    tree_pre_order(map->tree, visit);
}

/**
 * @brief   Determine if the data can be found in the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @return  Returns `true` if the data is found, otherwise returns `false`.
 */
bool map_contains(map_t *map, const str_t key) {
    return_value_if_fail(map != NULL && strlen(key) > 0, false);
    kv_pair_t *kv_pair = kv_pair_create(key, NULL, map->destroy);
    bool found = tree_contains(map->tree, kv_pair);
    destroy_kv_pair(kv_pair);
    return found;
}

/**
 * @brief   Add a key-value pair to the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @param value value
 * @return  Returns the modified cino-map.
 */
map_t *map_add(map_t *map, const str_t key, T value) {
    return_value_if_fail(map != NULL && strlen(key) > 0, map);
    kv_pair_t *kv_pair = kv_pair_create(key, value, map->destroy);
    tree_insert(map->tree, kv_pair);
    map->size++;
    return map;
}

/**
 * @brief   Remove a key-value pair from the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @return  Returns the modified cino-map.
 */
map_t *map_remove(map_t *map, const str_t key) {
    return_value_if_fail(map != NULL && strlen(key) > 0, map);
    kv_pair_t *kv_pair = kv_pair_create(key, NULL, map->destroy);
    tree_remove(map->tree, kv_pair);
    map->size--;
    return map;
}