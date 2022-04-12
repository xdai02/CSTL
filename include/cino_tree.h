/**************************************************
 * Module   :   cino_map
 * Function :   Operations on cino-map
 * Category :
 *              - map_t
 **************************************************/

#ifndef _CINO_TREE_H_
#define _CINO_TREE_H_

#include "cino_utils.h"

/****************************************
 *               tree_t
 ****************************************/

typedef struct tree_t tree_t;

tree_t *tree_create(const str_t data_type, compare_t compare);

void tree_destroy(tree_t *tree);

bool tree_is_empty(const tree_t *tree);

tree_t *tree_clear(tree_t *tree);

tree_t *tree_insert(tree_t *tree, T data);

#endif