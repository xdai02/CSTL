/**************************************************
 * Module   :   cino_map
 * Function :   Operations on cino-map
 * Category :
 *              - map_t
 **************************************************/

#ifndef _CINO_MAP_H_
#define _CINO_MAP_H_

#include "cino_utils.h"

/****************************************
 *               map_t
 ****************************************/

typedef struct kv_pair_t kv_pair_t;
typedef struct map_t map_t;

/**
 * @brief   Get the key of a key-value pair.
 * @param kv_pair   key-value pair
 * @return  key in string format.
 */
const str_t kv_pair_get_key(kv_pair_t *kv_pair);

/**
 * @brief   Get the value of a key-value pair.
 * @param kv_pair   key-value pair
 * @return  value
 */
T kv_pair_get_value(kv_pair_t *kv_pair);

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
map_t *map_create(destroy_t destroy);

/**
 * @brief   Destroy cino-map.
 * @param map   cino-map
 */
void map_destroy(map_t *map);

/**
 * @brief   Determine if the cino-map is empty.
 * @param map   cino-map
 * @return  Returns `true` if the cino-map is empty, otherwise returns `false`.
 */
bool map_is_empty(const map_t *map);

/**
 * @brief   Get the number of elements in the cino-map.
 * @param map   cino-map
 * @return  Returns the number of elements in the cino-map.
 */
size_t map_size(const map_t *map);

/**
 * @brief   Clear all the elments in the cino-map.
 * @param map   cino-map
 * @return  Returns the modified cino-map.
 */
map_t *map_clear(map_t *map);

/**
 * @brief   Traverse cino-map.
 * @param map   cino-map
 * @param visit user-defined callback function for visiting a single element
 */
void map_foreach(map_t *map, visit_t visit);

/**
 * @brief   Determine if the data can be found in the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @return  Returns `true` if the data is found, otherwise returns `false`.
 */
bool map_contains(map_t *map, const str_t key);

/**
 * @brief   Add a key-value pair to the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @param value value
 * @return  Returns the modified cino-map.
 */
map_t *map_add(map_t *map, const str_t key, T value);

/**
 * @brief   Remove a key-value pair from the cino-map.
 * @param map   cino-map
 * @param key   key only in string format
 * @return  Returns the modified cino-map.
 */
map_t *map_remove(map_t *map, const str_t key);

#endif