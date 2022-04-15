#include "cino_tree.h"

/****************************************
 *               tree_t
 ****************************************/

typedef struct node_t {
    T data;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} node_t;

typedef struct tree_t {
    node_t *root;
    str_t data_type;
    compare_t compare;
} tree_t;

/**
 * @brief   Determine if the data type is support by cino-tree.
 * @param data_type data type
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - T (generic)
 * @return  Returns the `true` if it is valid, otherwise returns `false`.
 */
static bool is_valid_data_type(const str_t data_type) {
    return_value_if_fail(data_type != NULL, false);

    const str_t data_types[] = {
        "int",
        "double",
        "T",  // generic
    };

    int data_types_len = array_len(data_types);
    for (int i = 0; i < data_types_len; i++) {
        if (str_equal(data_types[i], data_type)) {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Specify the default rules for comparing two values in ascending order.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int cmp_default(const T data1, const T data2) {
    return (byte_t *)data1 - (byte_t *)data2;
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
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-tree. Set to `NULL` if it is a primitive cino-tree.
 * @return  Returns the pointer to cino-tree, or `NULL` if creation failed.
 */
tree_t *tree_create(const str_t data_type, compare_t compare) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));
    return_value_if_fail(tree != NULL, NULL);

    tree->data_type = (str_t)calloc(str_length(data_type) + 1, sizeof(char));
    call_and_return_value_if_fail(tree->data_type != NULL, tree_destroy(tree), NULL);
    str_copy(tree->data_type, data_type);

    if (!compare) {
        compare = cmp_default;
    }
    tree->compare = compare;

    tree->root = NULL;
    return tree;
}

/**
 * @brief   Destroy cino-tree.
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-tree.
 * @param tree  cino-tree
 */
void tree_destroy(tree_t *tree) {
    return_if_fail(tree != NULL);

    tree_clear(tree);

    if (tree->data_type) {
        free(tree->data_type);
        tree->data_type = NULL;
    }

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
 * @param node  tree node
 */
static void tree_clear_post_order(node_t *node) {
    return_if_fail(node != NULL);
    tree_clear_post_order(node->left);
    tree_clear_post_order(node->right);
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
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-tree.
 * @param tree  cino-tree
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_clear(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    tree_clear_post_order(tree->root);
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
 * @param tree  cino-tree
 * @return  Returns the minimum tree node in the cino-tree.
 */
static node_t *tree_min_node(tree_t *tree) {
    return_value_if_fail(tree != NULL && tree->root != NULL, NULL);
    node_t *cur = tree->root;
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

/**
 * @brief   Get the maximum tree node.
 * @param tree  cino-tree
 * @return  Returns the maximum tree node in the cino-tree.
 */
static node_t *tree_max_node(tree_t *tree) {
    return_value_if_fail(tree != NULL && tree->root != NULL, NULL);
    node_t *cur = tree->root;
    while (cur && cur->right) {
        cur = cur->right;
    }
    return cur;
}

/**
 * @brief   Get the minimum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the minimum value in the cino-tree, or `NULL` if conditions failed.
 *          For primitive cino-tree, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T tree_min(tree_t *tree) {
    node_t *min = tree_min_node(tree);
    return_value_if_fail(min != NULL, NULL);

    if (str_equal(tree->data_type, "int")) {
        return wrap_int(*(int *)min->data);
    } else if (str_equal(tree->data_type, "double")) {
        return wrap_double(*(double *)min->data);
    } else {
        return min->data;
    }

    return NULL;
}

/**
 * @brief   Get the maximum value in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns the maximum value in the cino-tree, or `NULL` if conditions failed.
 *          For primitive cino-tree, a wrapper type of that primitive is returned. It is
 *          caller's responsibility to unwrap.
 */
T tree_max(tree_t *tree) {
    node_t *max = tree_max_node(tree);
    return_value_if_fail(max != NULL, NULL);

    if (str_equal(tree->data_type, "int")) {
        return wrap_int(*(int *)max->data);
    } else if (str_equal(tree->data_type, "double")) {
        return wrap_double(*(double *)max->data);
    } else {
        return max->data;
    }

    return NULL;
}

/**
 * @brief   Determine if the data can be found in the cino-tree.
 * @param tree  cino-tree
 * @return  Returns `true` if the data is found, otherwise returns `false`.
 */
bool tree_contains(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, false);

    bool found = false;

    if (str_equal(tree->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;

        node_t *cur = tree->root;
        while (cur) {
            int cur_data = *(int *)cur->data;
            if (wrapper_int->data == cur_data) {
                found = true;
                break;
            } else if (wrapper_int->data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        unwrap_int(wrapper_int);
    } else if (str_equal(tree->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;

        node_t *cur = tree->root;
        while (cur) {
            double cur_data = *(double *)cur->data;
            if (equal_double(wrapper_double->data, cur_data)) {
                found = true;
                break;
            } else if (wrapper_double->data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        unwrap_double(wrapper_double);
    } else if (str_equal(tree->data_type, "T")) {
        node_t *cur = tree->root;
        while (cur) {
            int cmp = tree->compare(data, cur->data);
            if (cmp == 0) {
                found = true;
                break;
            } else if (cmp < 0) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }

    return found;
}

/**
 * @brief   Get tree node by specific data.
 * @param tree  cino-tree
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns a pointer to the node found, or `NULL` if not found.
 */
static node_t *tree_node_get(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, NULL);

    node_t *cur = tree->root;
    while (cur) {
        if (str_equal(tree->data_type, "int")) {
            wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
            int cur_data = *(int *)cur->data;
            if (wrapper_int->data == cur_data) {
                return cur;
            } else if (wrapper_int->data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        } else if (str_equal(tree->data_type, "double")) {
            wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
            double cur_data = *(double *)cur->data;
            if (equal_double(wrapper_double->data, cur_data)) {
                return cur;
            } else if (wrapper_double->data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        } else if (str_equal(tree->data_type, "T")) {
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
        }
    }

    return NULL;
}

/**
 * @brief   Inserts the specified element to the cino-tree.
 * @param tree  cino-tree
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-tree, it is caller's responsibility to free
 *              the previous data before overwriting it.
 * @return  Returns the modified cino-tree.
 */
tree_t *tree_insert(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;
    if (str_equal(tree->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)data;
    } else if (str_equal(tree->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)data;
    }

    if (tree_contains(tree, data)) {
        if (str_equal(tree->data_type, "int")) {
            unwrap_int(wrapper_int);
        } else if (str_equal(tree->data_type, "double")) {
            unwrap_double(wrapper_double);
        }
        return NULL;
    }

    node_t *node = tree_node_create(NULL);
    return_value_if_fail(node != NULL, tree);

    if (str_equal(tree->data_type, "int")) {
        node->data = calloc(1, sizeof(int));
        call_and_return_value_if_fail(node->data != NULL, free(node), tree);
        *(int *)node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(tree->data_type, "double")) {
        node->data = calloc(1, sizeof(double));
        call_and_return_value_if_fail(node->data != NULL, free(node), tree);
        *(double *)node->data = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(tree->data_type, "T")) {
        node->data = data;
    }

    if (!tree->root) {
        tree->root = node;
        return tree;
    }

    node_t *cur = tree->root;
    node_t *parent = cur->parent;

    if (str_equal(tree->data_type, "int")) {
        int data = *(int *)node->data;
        while (cur) {
            parent = cur->parent;
            int cur_data = *(int *)cur->data;
            if (data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        int parent_data = *(int *)parent->data;
        if (data < parent_data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        node->parent = parent;
    } else if (str_equal(tree->data_type, "double")) {
        double data = *(double *)node->data;
        while (cur) {
            parent = cur;
            double cur_data = *(double *)cur->data;
            if (data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        double parent_data = *(double *)parent->data;
        if (data < parent_data) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        node->parent = parent;
    } else if (str_equal(tree->data_type, "T")) {
        while (cur) {
            parent = cur;
            if (tree->compare(node->data, cur->data) < 0) {
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
    }

    return tree;
}

/**
 * @brief   Removes the element from the cino-tree.
 * @param tree  cino-tree
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-tree, it is caller's responsibility to free
 *              the previous data before overwriting it.
 * @return  For primitive cino-array, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T tree_remove(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;
    if (str_equal(tree->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)data;
    } else if (str_equal(tree->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)data;
    }

    if (tree_contains(tree, data)) {
        if (str_equal(tree->data_type, "int")) {
            unwrap_int(wrapper_int);
        } else if (str_equal(tree->data_type, "double")) {
            unwrap_double(wrapper_double);
        }
        return NULL;
    }

    if (str_equal(tree->data_type, "int")) {
        node_t *cur = tree_node_get(tree, data);
        call_and_return_value_if_fail(cur != NULL, unwrap_int(wrapper_int), NULL);

        // remove root
        if (cur == tree->root) {
            int removed = *(int *)cur->data;
            free(cur->data);
            cur->data = NULL;
            free(cur);
            cur = NULL;
            tree->root = NULL;
            return wrap_int(removed);
        }
        // remove leaf node
        else if (!cur->left && !cur->right) {
            node_t *parent = cur->parent;
            if (parent->left == cur) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }

            int removed = *(int *)cur->data;
            free(cur->data);
            cur->data = NULL;
            free(cur);
            cur = NULL;
            return wrap_int(removed);
        }
        // remove node with only one child
        else if (cur->left || cur->right) {
            node_t *child = NULL;
            if (cur->left) {
                child = cur->left;
            } else {
                child = cur->right;
            }

            int removed = *(int *)cur->data;
            *(int *)cur->data = *(int *)child->data;
            cur->left = NULL;
            cur->right = NULL;

            free(child->data);
            child->data = NULL;
            free(child);
            child = NULL;
            return wrap_int(removed);
        }
        // remove node with two children
        else {
            node_t *max = tree_max_node(tree);

            int removed = *(int *)cur->data;
            *(int *)cur->data = *(int *)max->data;
            free(max->data);
            max->data = NULL;
            free(max);
            max = NULL;

            return wrap_int(removed);
        }
    } else if (str_equal(tree->data_type, "double")) {
        node_t *cur = tree_node_get(tree, data);
        call_and_return_value_if_fail(cur != NULL, unwrap_double(wrapper_double), NULL);

        // remove root
        if (cur == tree->root) {
            double removed = *(double *)cur->data;
            free(cur->data);
            cur->data = NULL;
            free(cur);
            cur = NULL;
            tree->root = NULL;
            return wrap_double(removed);
        }
        // remove leaf node
        else if (!cur->left && !cur->right) {
            node_t *parent = cur->parent;
            if (parent->left == cur) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }

            double removed = *(double *)cur->data;
            free(cur->data);
            cur->data = NULL;
            free(cur);
            cur = NULL;
            return wrap_double(removed);
        }
        // remove node with only one child
        else if (cur->left || cur->right) {
            node_t *child = NULL;
            if (cur->left) {
                child = cur->left;
            } else {
                child = cur->right;
            }

            double removed = *(double *)cur->data;
            *(double *)cur->data = *(double *)child->data;
            cur->left = NULL;
            cur->right = NULL;

            free(child->data);
            child->data = NULL;
            free(child);
            child = NULL;
            return wrap_double(removed);
        }
        // remove node with two children
        else {
            node_t *max = tree_max_node(tree);

            double removed = *(double *)cur->data;
            *(double *)cur->data = *(double *)max->data;
            free(max->data);
            max->data = NULL;
            free(max);
            max = NULL;

            return wrap_double(removed);
        }
    } else if (str_equal(tree->data_type, "T")) {
        node_t *cur = tree_node_get(tree, data);
        return_value_if_fail(cur != NULL, NULL);

        // remove root
        if (cur == tree->root) {
            T removed = cur->data;
            free(cur->data);
            cur->data = NULL;
            free(cur);
            cur = NULL;
            tree->root = NULL;
            return removed;
        }
        // remove leaf node
        else if (!cur->left && !cur->right) {
            node_t *parent = cur->parent;
            if (parent->left == cur) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }

            T removed = cur->data;
            free(cur);
            cur = NULL;
            return removed;
        }
        // remove node with only one child
        else if (cur->left || cur->right) {
            node_t *child = NULL;
            if (cur->left) {
                child = cur->left;
            } else {
                child = cur->right;
            }

            T removed = cur->data;
            cur->data = child->data;
            cur->left = NULL;
            cur->right = NULL;

            free(child);
            child = NULL;
            return removed;
        }
        // remove node with two children
        else {
            node_t *max = tree_max_node(tree);

            T removed = cur->data;
            cur->data = max->data;
            free(max);
            max = NULL;

            return removed;
        }
    }

    return tree;
}

/**
 * @brief   Update the element in the cino-tree.
 * @param tree      cino-tree
 * @param old_data  - For primitive data, a wrapper type of that primitive is needed.
 *                  This function will unwrap for you.
 *                  - For T (generic) cino-tree, it is caller's responsibility to free
 *                  the previous data before overwriting it.
 * @param new_data  - For primitive data, a wrapper type of that primitive is needed.
 *                  This function will unwrap for you.
 *                  - For T (generic) cino-tree, it is caller's responsibility to free
 *                  the previous data before overwriting it.
 */
void tree_set(tree_t *tree, T old_data, T new_data) {
    return_if_fail(tree != NULL && old_data != NULL && new_data != NULL);

    wrapper_int_t *old_wrapper_int = NULL;
    wrapper_double_t *old_wrapper_double = NULL;
    wrapper_int_t *new_wrapper_int = NULL;
    wrapper_double_t *new_wrapper_double = NULL;

    if (str_equal(tree->data_type, "int")) {
        old_wrapper_int = (wrapper_int_t *)old_data;
        new_wrapper_int = (wrapper_int_t *)new_data;
    } else if (str_equal(tree->data_type, "double")) {
        old_wrapper_double = (wrapper_double_t *)old_data;
        new_wrapper_double = (wrapper_double_t *)new_data;
    }

    if (!tree_contains(tree, old_data)) {
        if (str_equal(tree->data_type, "int")) {
            unwrap_int(old_wrapper_int);
            unwrap_int(new_wrapper_int);
        } else if (str_equal(tree->data_type, "double")) {
            unwrap_double(old_wrapper_double);
            unwrap_double(new_wrapper_double);
        }
        return;
    }

    if (str_equal(tree->data_type, "int")) {
        node_t *cur = tree_node_get(tree, old_data);
        if (!cur) {
            unwrap_int(old_wrapper_int);
            unwrap_int(new_wrapper_int);
            return;
        }
        *(int *)cur->data = new_wrapper_int->data;
    } else if (str_equal(tree->data_type, "double")) {
        node_t *cur = tree_node_get(tree, old_data);
        if (!cur) {
            unwrap_double(old_wrapper_double);
            unwrap_double(new_wrapper_double);
            return;
        }
        *(double *)cur->data = new_wrapper_double->data;
    } else if (str_equal(tree->data_type, "T")) {
        node_t *cur = tree_node_get(tree, old_data);
        cur->data = new_data;
    }
}