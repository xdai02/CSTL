/**************************************************
 * Module   :   cino_set
 * Function :   Operations on cino-set
 * Category :
 *              - set_t
 **************************************************/

#ifndef _CINO_SET_H_
#define _CINO_SET_H_

#include "cino_utils.h"

/****************************************
 *               set_t
 ****************************************/

typedef struct set_t set_t;

/**
 * @brief   Create cino-set.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-set. Set to `NULL` if it is a primitive cino-set.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-set. Set to `NULL` if it is a primitive cino-set.
 * @return  Returns the pointer to cino-set, or `NULL` if creation failed.
 */
set_t *set_create(data_type_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-set.
 * @param set   cino-set
 */
void set_destroy(set_t *set);

/**
 * @brief   Determine if the cino-set is empty.
 * @param set   cino-set
 * @return  Returns `true` if the cino-set is empty, otherwise returns `false`.
 */
bool set_is_empty(const set_t *set);

/**
 * @brief   Clear all the elments in the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_clear(set_t *set);

/**
 * @brief   Add an element to the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_add(set_t *set, T data);

/**
 * @brief   Removes an element from the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_remove(set_t *set, T data);

#endif