#include "cino_tree.h"

/****************************************
 *               tree_t
 ****************************************/

typedef struct node_t {
    T data;
    struct node_t *left;
    struct node_t *right;
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

// TODO
void tree_destroy(tree_t *tree) {
    return_if_fail(tree != NULL);

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

// TODO
tree_t *tree_clear(tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);

    return tree;
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

tree_t *tree_insert(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, NULL);

    return_value_if_fail(!tree_contains(tree, data), tree);

    node_t *node = tree_node_create(NULL);
    return_value_if_fail(node != NULL, tree);

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;

    if (str_equal(tree->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)data;
        node->data = calloc(1, sizeof(int));
        call_and_return_value_if_fail(node->data != NULL, free(node), tree);
        *(int *)node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(tree->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)data;
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

    node_t *pre = tree->root;
    node_t *cur = tree->root;

    if (str_equal(tree->data_type, "int")) {
        int data = *(int *)node->data;
        while (cur) {
            pre = cur;
            int cur_data = *(int *)cur->data;
            if (data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        int pre_data = *(int *)pre->data;
        if (data < pre_data) {
            pre->left = node;
        } else {
            pre->right = node;
        }
    } else if (str_equal(tree->data_type, "double")) {
        double data = *(double *)node->data;
        while (cur) {
            pre = cur;
            double cur_data = *(double *)cur->data;
            if (data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        double pre_data = *(double *)pre->data;
        if (data < pre_data) {
            pre->left = node;
        } else {
            pre->right = node;
        }
    } else if (str_equal(tree->data_type, "T")) {
        while (cur) {
            pre = cur;
            if (tree->compare(node->data, cur->data) < 0) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (tree->compare(node->data, pre->data) < 0) {
            pre->left = node;
        } else {
            pre->right = node;
        }
    }

    return tree;
}

T tree_remove(tree_t *tree, T data) {
    return_value_if_fail(tree != NULL && data != NULL, tree);

    if (str_equal(tree->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;

        node_t *pre = tree->root;
        node_t *cur = tree->root;
        while (cur) {
            int cur_data = *(int *)cur->data;
            if (wrapper_int->data == cur_data) {
                break;
            }
            pre = cur;
            if (wrapper_int->data < cur_data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        // not found
        call_and_return_value_if_fail(cur != NULL, unwrap_int(wrapper_int), NULL);

        // remove leaf node
        if (!cur->left && !cur->right) {
            if (pre->left == cur) {
                pre->left = NULL;
            } else {
                pre->right = NULL;
            }

            int removed = *(int *)cur->data;
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
            cur->data = child->data;
            cur->left = NULL;
            cur->right = NULL;

            free(child);
            child = NULL;
            return wrap_int(removed);
        }
        // remove node with two children
        else {
            node_t *max = tree_max_node(tree);
            int removed = *(int *)cur->data;
            cur->data = max->data;
            free(max);
            max = NULL;
            // TODO: should known the parent

            return wrap_int(removed);
        }
    } else if (str_equal(tree->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
    } else if (str_equal(tree->data_type, "T")) {
    }

    return tree;
}
