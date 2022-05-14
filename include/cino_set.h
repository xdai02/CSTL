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
 * @param compare   User-defined callback function for comparison.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
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
 * @brief   Get the number of elements in the cino-set.
 * @param set   cino-set
 * @return  Returns the number of elements in the cino-set.
 */
size_t set_size(const set_t *set);

/**
 * @brief   Clear all the elments in the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_clear(set_t *set);

/**
 * @brief   Traverse cino-set.
 * @param set   cino-set
 * @param visit user-defined callback function for visiting a single element
 */
void set_foreach(set_t *set, visit_t visit);

/**
 * @brief   Determine if the data can be found in the cino-set.
 * @param set   cino-set
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns `true` if the data is found, otherwise returns `false`. It is
 *          caller's responsibility to unwrap or free.
 */
bool set_contains(set_t *set, T data);

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

/**
 * @brief   Get the intersection of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the intersection cino-set, with all the element references.
 */
set_t *set_intersection(set_t *set1, set_t *set2);

/**
 * @brief   Get the union of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the union cino-set, with all the element references.
 */
set_t *set_union(set_t *set1, set_t *set2);

/**
 * @brief   Get the difference of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the difference cino-set, with all the element references.
 */
set_t *set_difference(set_t *set1, set_t *set2);

#endif