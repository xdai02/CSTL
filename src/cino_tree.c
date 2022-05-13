#include "cino_tree.h"

/****************************************
 *               tree_t
 ****************************************/

typedef struct node_t {
    T data;
    int height;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} node_t;

typedef struct tree_t {
    node_t *root;
    data_type_t data_type;
    compare_t compare;
    destroy_t destroy;
} tree_t;

/**
 * @brief   Create a tree node.
 * @param data  data stored in the node
 * @return  Returns a pointer to the node, or `NULL` if it fails.
 */
static node_t *tree_node_create(T data) {
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;
    return node;
}

/**
 * @brief   Destroy the tree node.
 * @param tree  cino-tree
 * @param node  node to be destroyed
 */
static void tree_node_destroy(tree_t *tree, node_t *node) {
    return_if_fail(tree != NULL && node != NULL);
    tree->destroy(node->data);
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    free(node);
    node = NULL;
}

/**
 * @brief   Create cino-tree.
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
 * @return  Returns the pointer to cino-tree, or `NULL` if creation failed.
 */
tree_t *tree_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));
    return_value_if_fail(tree != NULL, NULL);
    tree->root = NULL;

    tree->data_type = data_type;
    tree->compare = compare ? compare : compare_default;
    tree->destroy = destroy ? destroy : destroy_default;

    return tree;
}

/**
 * @brief   Destroy cino-tree.
 * @param tree  cino-tree
 */
void tree_destroy(tree_t *tree) {
    return_if_fail(tree != NULL);

    tree_clear(tree);

    tree->compare = NULL;
    tree->destroy = NULL;

    if (tree) {
        free(tree);
        tree = NULL;
    }
}

/**
 * @brief   Determine if the cino-tree is empty.
 * @param tree  cino-tree
 * @return  Returns `true` if the cino-tree is empty, otherwise returns `false`.
 */
bool tree_is_empty(const tree_t *tree) {
    return !tree || !tree->root;
}

/**
 * @brief   Helper function for counting the number of elments in the cino-tree.
 * @param node  tree node
 */
static size_t tree_size_count(const node_t *node) {
    return_value_if_fail(node != NULL, 0);
    return tree_size_count(node->left) + tree_size_count(node->right) + 1;
}

/**
 * @brief   Get the number of elements in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the number of elements in the cino-tree.
 */
size_t tree_size(const tree_t *tree) {
    return_value_if_fail(tree != NULL, 0);
    return tree_size_count(tree->root);
}

/**
 * @brief   Helper function for clearing all the elments in the cino-tree.
 * @param tree  cino-tree
 * @param node  tree node
 */
static void tree_node_clear(tree_t *tree, node_t *node) {
    return_if_fail(tree != NULL && node != NULL);
    tree_node_clear(tree, node->left);
    tree_node_clear(tree, node->right);
    tree_node_destroy(tree, node);
}

/**
 * @brief   Clear all the elments in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_clear(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    tree_node_clear(tree, tree->root);
    tree->root = NULL;
    return tree;
}

/**
 * @brief   Helper function for pre-order trasersal.
 * @param node  tree node
 * @param visit User-defined callback function for visiting tree node
 */
static void pre_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    visit(node->data);
    pre_order(node->left, visit);
    pre_order(node->right, visit);
}

/**
 * @brief   Pre-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_pre_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    pre_order(tree->root, visit);
}

/**
 * @brief   Helper function for in-order trasersal.
 * @param node  tree node
 * @param visit User-defined callback function for visiting tree node
 */
static void in_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    in_order(node->left, visit);
    visit(node->data);
    in_order(node->right, visit);
}

/**
 * @brief   In-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_in_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    in_order(tree->root, visit);
}

/**
 * @brief   Helper function for post-order trasersal.
 * @param node  tree node
 * @param visit User-defined callback function for visiting tree node
 */
static void post_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    post_order(node->left, visit);
    post_order(node->right, visit);
    visit(node->data);
}

/**
 * @brief   Post-order trasersal.
 * @param tree  cino-tree
 * @param visit User-defined callback function for visiting tree node
 */
void tree_post_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    post_order(tree->root, visit);
}

/**
 * @brief   Get the minimum tree node.
 * @param root  root of cino-tree
 * @return  Returns the minimum tree node in the cino-tree.
 */
static node_t *tree_min_node(node_t *root) {
    return_value_if_fail(root != NULL, NULL);
    node_t *cur = root;
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

/**
 * @brief   Get the maximum tree node.
 * @param root  root of cino-tree
 * @return  Returns the maximum tree node in the cino-tree.
 */
static node_t *tree_max_node(node_t *root) {
    return_value_if_fail(root != NULL, NULL);
    node_t *cur = root;
    while (cur && cur->right) {
        cur = cur->right;
    }
    return cur;
}

/**
 * @brief   Get the minimum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the minimum value in the cino-tree, or `NULL` if the cino-tree
 *          is empty.
 *          For primitive cino-tree, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T tree_min(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    node_t *min_node = tree_min_node(tree->root);
    return min_node ? min_node->data : NULL;
}

/**
 * @brief   Get the maximum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the maximum value in the cino-tree, or `NULL` if the cino-tree
 *          is empty.
 *          For primitive cino-tree, a wrapper type of that primitive is returned.
 *          Caller should use `->data` to get the primitive value, instead of unwrapping
 *          it.
 */
T tree_max(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    node_t *max_node = tree_max_node(tree->root);
    return max_node ? max_node->data : NULL;
}

/**
 * @brief   Search specific tree node by given data.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns a pointers to the node found, or `NULL` if not found.
 */
static node_t *tree_node_get(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, NULL);

    node_t *cur = tree->root;
    while (cur) {
        int cmp = tree->compare(data, cur->data);
        if (cmp == 0) {
            return cur;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return NULL;
}

/**
 * @brief   Determine if the data can be found in the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns `true` if the data is found, otherwise returns `false`. It is
 *          caller's responsibility to unwrap or free.
 */
bool tree_contains(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, false);
    return tree_node_get(tree, data) != NULL;
}

static int tree_height(node_t *node) {
    return_value_if_fail(node != NULL, 0);
    return node->height;
}

/**
 * @brief   Get the balance factor of a cino-tree node.
 * @param node  cino-tree node
 * @return  Returns the balance factor of a cino-tree node.
 */
static int tree_node_balance_factor(node_t *node) {
    return_value_if_fail(node != NULL, 0);
    return tree_height(node->left) - tree_height(node->right);
}

/**
 * @brief   Left-left rotation.
 * @param node  cino-tree node
 * @return  Returns the root of the subtree after rotation.
 */
static node_t *ll_rotation(node_t *node) {
    return_value_if_fail(node != NULL, NULL);

    node_t *sub_node = node->left;
    node->left = sub_node->right;
    if (node->left) {
        node->left->parent = node;
    }
    sub_node->right = node;
    sub_node->parent = node->parent;
    node->parent = sub_node;

    node->height = max(tree_height(node->left), tree_height(node->right)) + 1;
    sub_node->height = max(tree_height(sub_node->left), node->height) + 1;
    return sub_node;
}

/**
 * @brief   Right-right rotation.
 * @param node  cino-tree node
 * @return  Returns the root of the subtree after rotation.
 */
static node_t *rr_rotation(node_t *node) {
    return_value_if_fail(node != NULL, NULL);

    node_t *sub_node = node->right;
    node->right = sub_node->left;
    if (sub_node->left) {
        sub_node->left->parent = node;
    }
    sub_node->left = node;
    sub_node->parent = node->parent;
    node->parent = sub_node;

    node->height = max(tree_height(node->left), tree_height(node->right)) + 1;
    sub_node->height = max(node->height, tree_height(sub_node->right)) + 1;
    return sub_node;
}

/**
 * @brief   Left-right rotation.
 * @param node  cino-tree node
 * @return  Returns the root of the subtree after rotation.
 */
static node_t *lr_rotation(node_t *node) {
    return_value_if_fail(node != NULL, NULL);
    node->left = rr_rotation(node->left);
    return ll_rotation(node);
}

/**
 * @brief   Right-left rotation.
 * @param node  cino-tree node
 * @return  Returns the root of the subtree after rotation.
 */
static node_t *rl_rotation(node_t *node) {
    return_value_if_fail(node != NULL, NULL);
    node->right = ll_rotation(node->right);
    return rr_rotation(node);
}

/**
 * @brief   Helper function for inserting the specified element to the cino-tree.
 * @param tree  cino-tree
 * @param node  root node used for recursion
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified root node.
 */
static node_t *tree_node_insert(tree_t *tree, node_t *node, T data) {
    return_value_if_fail(tree != NULL && data != NULL, node);

    if (!node) {
        return tree_node_create(data);
    }

    int cmp = tree->compare(data, node->data);
    return_value_if_fail(cmp != 0, node);

    if (cmp < 0) {
        node_t *sub_node = tree_node_insert(tree, node->left, data);
        node->left = sub_node;
        sub_node->parent = node;
        if (tree_node_balance_factor(node) > 1) {
            if (tree->compare(data, node->left->data) < 0) {
                node = ll_rotation(node);
            } else {
                node = lr_rotation(node);
            }
        }
    } else {
        node_t *sub_node = tree_node_insert(tree, node->right, data);
        node->right = sub_node;
        sub_node->parent = node;
        if (tree_node_balance_factor(node) < -1) {
            if (tree->compare(data, node->right->data) > 0) {
                node = rr_rotation(node);
            } else {
                node = rl_rotation(node);
            }
        }
    }

    node->height = max(tree_height(node->left), tree_height(node->right)) + 1;
    return node;
}

/**
 * @brief   Inserts the specified element to the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_insert(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    // already exist
    call_and_return_value_if_fail(!tree_contains(tree, data), tree->destroy(data), tree);

    tree->root = tree_node_insert(tree, tree->root, data);
    return tree;
}

/**
 * @brief   Helper function for removing the specified element from the cino-tree.
 * @param tree  cino-tree
 * @param node  root node used for recursion
 * @param del   node to be removed
 * @return  Returns the modified root node.
 */
static node_t *tree_node_remove(tree_t *tree, node_t *node, node_t *del) {
    return_value_if_fail(tree != NULL && node != NULL && del != NULL, node);

    int cmp = tree->compare(del->data, node->data);

    if (cmp < 0) {
        node->left = tree_node_remove(tree, node->left, del);
        if (tree_node_balance_factor(node) < -1) {
            node_t *right_node = node->right;
            if (tree_height(right_node->left) > tree_height(right_node->right)) {
                node = rl_rotation(node);
            } else {
                node = rr_rotation(node);
            }
        }
    } else if (cmp > 0) {
        node->right = tree_node_remove(tree, node->right, del);
        if (tree_node_balance_factor(node) > 1) {
            node_t *left_node = node->left;
            if (tree_height(left_node->right) > tree_height(left_node->left)) {
                node = lr_rotation(node);
            } else {
                node = ll_rotation(node);
            }
        }
    } else {
        if (node->left && node->right) {
            if (tree_height(node->left) > tree_height(node->right)) {
                node_t *max_node = tree_max_node(node->left);
                tree->destroy(node->data);
                node->data = max_node->data;
                node->left = tree_node_remove(tree, node->left, max_node);
            } else {
                node_t *min_node = tree_min_node(node->right);
                tree->destroy(node->data);
                node->data = min_node->data;
                node->right = tree_node_remove(tree, node->right, min_node);
            }
        } else {
            node_t *removed = node;
            node = node->left ? node->left : node->right;
            if (node) {
                node->parent = removed->parent;
            }

            // determine if current node has already copied to its ancestor
            node_t *ancestor = removed->parent;
            bool found = false;
            while (ancestor) {
                if (tree->compare(removed->data, ancestor->data) == 0) {
                    found = true;
                }
                ancestor = ancestor->parent;
            }

            if (found) {
                removed->data = NULL;
            } else {
                tree->destroy(removed->data);
            }

            removed->data = NULL;

            tree_node_destroy(tree, removed);
        }
    }

    return node;
}

/**
 * @brief   Removes the element from the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_remove(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL, NULL);

    node_t *node = tree_node_get(tree, data);
    // not exist
    call_and_return_value_if_fail(node != NULL, tree->destroy(data), tree);

    tree->root = tree_node_remove(tree, tree->root, node);
    tree->destroy(data);
    return tree;
}

/**
 * @brief   Update the element in the cino-tree.
 * @param tree      cino-tree
 * @param old_data  For primitive data, a wrapper type of that primitive is needed.
 * @param new_data  For primitive data, a wrapper type of that primitive is needed.
 */
void tree_set(tree_t *tree, T old_data, T new_data) {
    return_if_fail(tree != NULL && old_data != NULL && new_data != NULL);

    node_t *node = tree_node_get(tree, old_data);

    // not found
    call_and_return_if_fail(node != NULL, tree->destroy(new_data));

    tree_remove(tree, old_data);
    tree_insert(tree, new_data);
}

/**
 * @brief   Helper function for inserting node into array by in-order trasersal.
 * @param array cino-array
 * @param node  tree node
 */
static void tree_node_array_insert(array_t *array, node_t *node) {
    return_if_fail(array != NULL && node != NULL);
    array_append(array, node->data);
    tree_node_array_insert(array, node->left);
    tree_node_array_insert(array, node->right);
}

/**
 * @brief   Create a cino-array containing all the references of nodes in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns a cino-array containing all the references of nodes.
 */
array_t *tree_node_array_create(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);

    array_t *array = array_create(tree->data_type, tree->compare, NULL);
    return_value_if_fail(array != NULL, NULL);

    tree_node_array_insert(array, tree->root);
    return array;
}

/**
 * @brief   Destroy the cino-array containing tree node references.
 * @param array cino-array
 */
void tree_node_array_destroy(array_t *array) {
    return_if_fail(array != NULL);
    array_destroy(array);
}