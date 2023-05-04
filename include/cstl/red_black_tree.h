#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#include "utils.h"

typedef struct red_black_tree_t red_black_tree_t;

/**
 * @brief Create a red_black_tree_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the red_black_tree_t object if create successfully, otherwise returns NULL.
 */
red_black_tree_t *red_black_tree_create(compare_t compare, destroy_t destroy);

/**
 * @brief Destroy a red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 */
void red_black_tree_destroy(red_black_tree_t *tree);

/**
 * @brief Determine whether the red_black_tree_t object is empty.
 * @param tree The red_black_tree_t object.
 * @return Returns true if the red_black_tree_t object is empty, otherwise returns false.
 */
bool red_black_tree_is_empty(const red_black_tree_t *tree);

/**
 * @brief Get the number of nodes in the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @return Returns the number of nodes in the red_black_tree_t object.
 */
size_t red_black_tree_size(const red_black_tree_t *tree);

/**
 * @brief Clear the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @return Returns the modified red_black_tree_t object.
 */
red_black_tree_t *red_black_tree_clear(red_black_tree_t *tree);

/**
 * @brief Checks whether the red_black_tree_t object contains the key.
 * @note Caller must free the parameter key (if applicable).
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns true if the red_black_tree_t object contains the key, otherwise returns false.
 */
bool red_black_tree_contains(const red_black_tree_t *tree, T key)

/**
 * @brief Traverse the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @param visit Callback function for visiting a data item.
 */
void red_black_tree_foreach(red_black_tree_t *tree, visit_t visit);

/**
 * @brief Inserts a key into the red-black tree.
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns the modified red_black_tree_t object.
 */
red_black_tree_t *red_black_tree_insert(red_black_tree_t *tree, T key);

/**
 * @brief Removes a key from the red_black_tree_t object.
 * @note Caller must free the parameter key (if applicable).
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns the modified red_black_tree_t object.
 */
red_black_tree_t *red_black_tree_remove(red_black_tree_t *tree, T key);

#endif
