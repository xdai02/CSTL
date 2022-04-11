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
    // compare_t compare;
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

static node_t *tree_node_create(T data) {
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree_t *tree_create(const str_t data_type) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));
    return_value_if_fail(tree != NULL, NULL);

    tree->data_type = (str_t)calloc(str_length(data_type) + 1, sizeof(char));
    call_and_return_value_if_fail(tree->data_type != NULL, tree_destroy(tree), NULL);
    str_copy(tree->data_type, data_type);

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

tree_t *tree_insert(tree_t *tree, T data, compare_t compare) {
    return_value_if_fail(tree != NULL && data != NULL, NULL);

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
        call_and_return_value_if_fail(compare != NULL, free(node), tree);
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
            if (compare(node->data, cur->data) < 0) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (compare(node->data, pre->data) < 0) {
            pre->left = node;
        } else {
            pre->right = node;
        }
    }

    return tree;
}