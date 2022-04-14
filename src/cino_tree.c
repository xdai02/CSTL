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

static node_t *tree_node_create(T data) {
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

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

bool tree_is_empty(const tree_t *tree) {
    return !tree || !tree->root;
}

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

tree_t *tree_clear(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    tree_clear_post_order(tree->root);
    tree->root = NULL;
    return tree;
}

static void pre_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    visit(node->data);
    pre_order(node->left, visit);
    pre_order(node->right, visit);
}

void tree_pre_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    pre_order(tree->root, visit);
}

static void in_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    in_order(node->left, visit);
    visit(node->data);
    in_order(node->right, visit);
}

void tree_in_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    in_order(tree->root, visit);
}

static void post_order(node_t *node, visit_t visit) {
    return_if_fail(node != NULL && visit != NULL);
    post_order(node->left, visit);
    post_order(node->right, visit);
    visit(node->data);
}

void tree_post_order(tree_t *tree, visit_t visit) {
    return_if_fail(tree != NULL && visit != NULL);
    post_order(tree->root, visit);
}

static node_t *tree_min_node(tree_t *tree) {
    return_value_if_fail(tree != NULL && tree->root != NULL, NULL);
    node_t *cur = tree->root;
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

static node_t *tree_max_node(tree_t *tree) {
    return_value_if_fail(tree != NULL && tree->root != NULL, NULL);
    node_t *cur = tree->root;
    while (cur && cur->right) {
        cur = cur->right;
    }
    return cur;
}

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
}