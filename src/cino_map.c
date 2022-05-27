#include "cino_map.h"
#include "cino_string.h"
#include "cino_tree.h"

/****************************************
 *               map_t
 ****************************************/

typedef struct kv_pair {
    string_t *key;
    T value;
} kv_pair;

typedef struct map_t {
    tree_t *tree;
    size_t size;
    compare_t compare;
    destroy_t destroy;
} map_t;

/**
 * @brief   Create cino-map.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `destroy_int` if the data type is DATA_TYPE_INT
 *                      - `destroy_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `destroy_char` if the data type is DATA_TYPE_CHAR
 *                      - `destroy_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `destroy_default` is applied.
 * @return  Returns the pointer to cino-map, or `NULL` if creation failed.
 */
map_t *map_create(destroy_t destroy) {
    map_t *map = (map_t *)calloc(1, sizeof(map_t));
    return_value_if_fail(map != NULL, NULL);

    map->tree = tree_create(DATA_TYPE_T, NULL, destroy);
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

    map->compare = NULL;
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
