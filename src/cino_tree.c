#include "cino_tree.h"

/****************************************
 *               tree_t
 ****************************************/

typedef enum data_type_t {
    DATA_TYPE_INT,
    DATA_TYPE_DOUBLE,
    DATA_TYPE_CHAR,
    DATA_TYPE_T,
} data_type_t;

typedef struct node_t {
    T data;
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
 * @brief   Determine if the data type is support by cino-tree.
 * @param data_type data type
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - char
 *                      - T (generic)
 * @return  Returns the `true` if it is valid, otherwise returns `false`.
 */
static bool is_valid_data_type(const str_t data_type) {
    return_value_if_fail(data_type != NULL, false);

    const str_t data_types[] = {
        "int",
        "double",
        "char",
        "T",  // generic
    };

    int data_types_len = arr_len(data_types);
    for (int i = 0; i < data_types_len; i++) {
        if (str_equal(data_types[i], data_type)) {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Specify the rules for comparing two int values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_int(const T data1, const T data2) {
    wrapper_int_t *wrapper1 = (wrapper_int_t *)data1;
    wrapper_int_t *wrapper2 = (wrapper_int_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the rules for comparing two double values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_double(const T data1, const T data2) {
    wrapper_double_t *wrapper1 = (wrapper_double_t *)data1;
    wrapper_double_t *wrapper2 = (wrapper_double_t *)data2;
    if (double_equal(wrapper1->data, wrapper2->data)) {
        return 0;
    }
    return wrapper1->data > wrapper2->data ? 1 : -1;
}

/**
 * @brief   Specify the rules for comparing two int values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_char(const T data1, const T data2) {
    wrapper_char_t *wrapper1 = (wrapper_char_t *)data1;
    wrapper_char_t *wrapper2 = (wrapper_char_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the default rules for comparing two values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_default(const T data1, const T data2) {
    return (byte_t *)data1 - (byte_t *)data2;
}

/**
 * @brief   Specify the rules for destroying a single int element.
 * @param data  pointer to the element
 */
static void destroy_int(T data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    unwrap_int(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single double element.
 * @param data  pointer to the element
 */
static void destroy_double(T data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    unwrap_double(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single char element.
 * @param data  pointer to the element
 */
static void destroy_char(T data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    unwrap_char(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single element.
 * @param data  pointer to the element
 */
static void destroy_default(T data) {
    return;
}

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
    return node;
}

/**
 * @brief   Create cino-tree.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - char
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-tree. Set to `NULL` if it is a primitive cino-tree.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-array. Set to `NULL` if it is a primitive cino-array.
 * @return  Returns the pointer to cino-tree, or `NULL` if creation failed.
 */
tree_t *tree_create(const str_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));
    return_value_if_fail(tree != NULL, NULL);
    tree->root = NULL;

    if (str_equal(data_type, "int")) {
        tree->data_type = DATA_TYPE_INT;
        tree->compare = compare_int;
        tree->destroy = destroy_int;
    } else if (str_equal(data_type, "double")) {
        tree->data_type = DATA_TYPE_DOUBLE;
        tree->compare = compare_double;
        tree->destroy = destroy_double;
    } else if (str_equal(data_type, "char")) {
        tree->data_type = DATA_TYPE_CHAR;
        tree->compare = compare_char;
        tree->destroy = destroy_char;
    } else if (str_equal(data_type, "T")) {
        tree->data_type = DATA_TYPE_T;
        tree->compare = compare ? compare : compare_default;
        tree->destroy = destroy ? destroy : destroy_default;
    }

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
 * @brief   Helper function for clearing all the elments in the cino-tree.
 * @param tree  cino-tree
 * @param node  tree node
 */
static void tree_clear_post_order(tree_t *tree, node_t *node) {
    return_if_fail(tree != NULL && node != NULL);

    tree_clear_post_order(tree, node->left);
    tree_clear_post_order(tree, node->right);

    tree->destroy(node->data);
    free(node->data);
    node->data = NULL;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    free(node);
    node = NULL;
}

/**
 * @brief   Clear all the elments in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_clear(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    tree_clear_post_order(tree, tree->root);
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
 * @brief   Determine if the data can be found in the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns `true` if the data is found, otherwise returns `false`.
 */
bool tree_contains(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, false);

    node_t *cur = tree->root;
    while (cur) {
        int cmp = tree->compare(data, cur->data);
        if (cmp == 0) {
            break;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    tree->destroy(data);
    return cur != NULL;
}

/**
 * @brief   Inserts the specified element to the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_insert(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    node_t *node = tree_node_create(data);
    return_value_if_fail(node != NULL, tree);

    if (!tree->root) {
        tree->root = node;
        return tree;
    }

    node_t *cur = tree->root;
    node_t *parent = cur->parent;

    while (cur) {
        parent = cur;

        int cmp = tree->compare(node->data, cur->data);
        if (cmp == 0) {
            tree->destroy(cur->data);
            free(node);
            node = NULL;
            return tree;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (tree->compare(node->data, parent->data) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->parent = parent;

    return tree;
}

/**
 * @brief   Removes the element from the cino-tree.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_remove(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    node_t *cur = tree->root;
    while (cur) {
        int cmp = tree->compare(data, cur->data);
        if (cmp == 0) {
            break;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    // not found
    call_and_return_value_if_fail(cur != NULL, tree->destroy(data), tree);

    // remove root
    if (cur == tree->root) {
        tree->destroy(cur->data);
        free(cur);
        cur = NULL;
        tree->root = NULL;
    }
    // remove leaf node
    else if (!cur->left && !cur->right) {
        node_t *parent = cur->parent;
        if (parent->left == cur) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }

        tree->destroy(cur->data);
        free(cur);
        cur = NULL;
    }
    // remove node with only one child
    else if ((cur->left && !cur->right) || (!cur->left && cur->right)) {
        node_t *child = NULL;
        if (cur->left) {
            child = cur->left;
        } else {
            child = cur->right;
        }

        tree->destroy(cur->data);
        cur->data = child->data;
        cur->left = NULL;
        cur->right = NULL;
        child->parent = NULL;
        free(child);
        child = NULL;
    }
    // remove node with two children
    else {
        // get the min node of left subtree
        node_t *min_node = tree_min_node(cur->right);

        tree->destroy(cur->data);
        cur->data = min_node->data;
        min_node->parent = NULL;
        free(min_node);
        min_node = NULL;
    }

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

    node_t *cur = tree->root;
    while (cur) {
        int cmp = tree->compare(old_data, cur->data);
        if (cmp == 0) {
            break;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    // not found
    if (!cur) {
        tree->destroy(old_data);
        tree->destroy(new_data);
    }

    tree->destroy(cur->data);
    cur->data = new_data;
}