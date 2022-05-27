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

typedef struct map_t map_t;

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

#endif