/**************************************************
 * Module   :   cino_tree
 * Function :   Operations on cino-tree
 * Category :
 *              - tree_t
 **************************************************/

#ifndef _CINO_TREE_H_
#define _CINO_TREE_H_

#include "cino_utils.h"
#include "cino_array.h"

/****************************************
 *               tree_t
 ****************************************/

typedef struct tree_t tree_t;

/**
 * @brief   Create cino-tree.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-tree. Set to `NULL` if it is a primitive cino-tree.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-tree. Set to `NULL` if it is a primitive cino-tree.
 * @return  Returns the pointer to cino-tree, or `NULL` if creation failed.
 */
tree_t *tree_create(data_type_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-tree.
 * @param tree  cino-tree
 */
void tree_destroy(tree_t *tree);

/**
 * @brief   Determine if the cino-tree is empty.
 * @param tree  cino-tree
 * @return  Returns `true` if the cino-tree is empty, otherwise returns `false`.
 */
bool tree_is_empty(const tree_t *tree);

/**
 * @brief   Get the number of elements in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the number of elements in the cino-tree.
 */
size_t tree_size(const tree_t *tree);

/**
 * @brief   Clear all the elments in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_clear(tree_t *tree);

/**
 * @brief   Pre-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_pre_order(tree_t *tree, visit_t visit);

/**
 * @brief   In-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_in_order(tree_t *tree, visit_t visit);

/**
 * @brief   Post-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_post_order(tree_t *tree, visit_t visit);

/**
 * @brief   Get the minimum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the minimum value in the cino-tree, or `NULL` if the cino-tree
 *          is empty.
 *          For primitive cino-tree, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T tree_min(tree_t *tree);

/**
 * @brief   Get the maximum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the maximum value in the cino-tree, or `NULL` if the cino-tree
 *          is empty.
 *          For primitive cino-tree, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T tree_max(tree_t *tree);

/**
 * @brief   Determine if the data can be found in the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns `true` if the data is found, otherwise returns `false`. It is
 *          caller's responsibility to unwrap or free.
 */
bool tree_contains(tree_t *tree, T data);

/**
 * @brief   Inserts the specified element to the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_insert(tree_t *tree, T data);

/**
 * @brief   Removes the element from the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_remove(tree_t *tree, T data);

/**
 * @brief   Update the element in the cino-tree.
 * @param tree      cino-tree
 * @param old_data  For primitive data, a wrapper type of that primitive is needed.
 * @param new_data  For primitive data, a wrapper type of that primitive is needed.
 */
void tree_set(tree_t *tree, T old_data, T new_data);

/**
 * @brief   Create a cino-array containing all the references of nodes in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns a cino-array containing all the references of nodes.
 */
array_t *tree_node_array_create(tree_t *tree);

/**
 * @brief   Destroy the cino-array containing tree node references.
 * @param array cino-array
 */
void tree_node_array_destroy(array_t *array);

#endif