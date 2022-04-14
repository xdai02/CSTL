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

void tree_pre_order(tree_t *tree, visit_t visit);

void tree_in_order(tree_t *tree, visit_t visit);

void tree_post_order(tree_t *tree, visit_t visit);

T tree_min(tree_t *tree);

T tree_max(tree_t *tree);

bool tree_contains(tree_t *tree, T data);

tree_t *tree_insert(tree_t *tree, T data);

T tree_remove(tree_t *tree, T data);

void tree_set(tree_t *tree, T old_data, T new_data);

#endif