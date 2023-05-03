#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

typedef enum {
    RED,
    BLACK
} color_t;

typedef struct node_t {
    int key;
    color_t color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} node_t;

typedef struct red_black_tree_t {
    node_t *root;
    size_t size;
} red_black_tree_t;

static node_t *__node_create(int key, color_t color, node_t *left, node_t *right, node_t *parent) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);

    node->key = key;
    node->color = color;
    node->left = left;
    node->right = right;
    node->parent = parent;
    return node;
}

static void __destroy_node(node_t *node) {
    return_if_fail(node != NULL);
    __destroy_node(node->left);
    __destroy_node(node->right);
    free(node);
}

red_black_tree_t *red_black_tree_create() {
    red_black_tree_t *tree = (red_black_tree_t *)malloc(sizeof(red_black_tree_t));
    return_value_if_fail(tree != NULL, NULL);

    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void red_black_tree_destroy(red_black_tree_t *tree) {
    return_if_fail(tree != NULL);
    __destroy_node(tree->root);
    free(tree);
}

bool red_black_tree_is_empty(const red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, true);
    return tree->size == 0;
}

size_t red_black_tree_size(const red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, 0);
    return tree->size;
}

red_black_tree_t *red_black_tree_clear(red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    __destroy_node(tree->root);
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

static void __inorder(node_t *node) {
    return_if_fail(node != NULL);

    __inorder(node->left);
    printf("%d ", node->key);
    __inorder(node->right);
}

void red_black_tree_inorder(red_black_tree_t *tree) {
    return_if_fail(tree != NULL);
    __inorder(tree->root);
    printf("\n");
}

static node_t *__grandparent(node_t *node) {
    return_value_if_fail(node != NULL && node->parent != NULL, NULL);
    return node->parent->parent;
}

static node_t *__uncle(node_t *node) {
    node_t *grandparent = __grandparent(node);
    return_value_if_fail(grandparent != NULL, NULL);
    if (node->parent == grandparent->left) {
        return grandparent->right;
    } else {
        return grandparent->left;
    }
}

static void __left_rotate(red_black_tree_t *tree, node_t *x) {
    return_if_fail(tree != NULL && x != NULL);

    node_t *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == NULL) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

static void __right_rotate(red_black_tree_t *tree, node_t *x) {
    return_if_fail(tree != NULL && x != NULL);

    node_t *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == NULL) {
        tree->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

static void __insert_fixup(red_black_tree_t *tree, node_t *node) {
    return_if_fail(tree != NULL && node != NULL);

    while (node->parent != NULL && node->parent->color == RED) {
        node_t *uncle = __uncle(node);
        if (uncle != NULL && uncle->color == RED) {
            node->parent->color = BLACK;
            uncle->color = BLACK;
            __grandparent(node)->color = RED;
            node = __grandparent(node);
        } else {
            node_t *grandparent = __grandparent(node);

            if (node == node->parent->right && node->parent == grandparent->left) {
                __left_rotate(tree, node->parent);
                node = node->left;
            } else if (node == node->parent->left && node->parent == grandparent->right) {
                __right_rotate(tree, node->parent);
                node = node->right;
            }

            node->parent->color = BLACK;
            grandparent->color = RED;
            if (node == node->parent->left) {
                __right_rotate(tree, grandparent);
            } else {
                __left_rotate(tree, grandparent);
            }
        }
    }

    tree->root->color = BLACK;
}

red_black_tree_t *red_black_tree_insert(red_black_tree_t *tree, int key) {
    return_value_if_fail(tree != NULL, NULL);

    node_t *node = __node_create(key, RED, NULL, NULL, NULL);
    return_value_if_fail(node != NULL, tree);

    if (tree->root == NULL) {
        tree->root = node;
    } else {
        node_t *current = tree->root;
        node_t *parent = NULL;

        while (current != NULL) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                free(node);
                return tree;
            }
        }

        node->parent = parent;
        if (key < parent->key) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    __insert_fixup(tree, node);
    tree->size++;
    return tree;
}

int main() {
    red_black_tree_t *tree = red_black_tree_create();

    srand(time(NULL));
    const int N = 10000;
    int num[N];
    for (int i = 0; i < N; i++) {
        num[i] = rand() % N;
        printf("%d, ", num[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        red_black_tree_insert(tree, num[i]);
    }

    red_black_tree_inorder(tree);

    printf("size = %d\n", (int)red_black_tree_size(tree));
    printf("empty = %d\n", red_black_tree_is_empty(tree));

    red_black_tree_clear(tree);
    printf("size = %d\n", (int)red_black_tree_size(tree));
    printf("empty = %d\n", red_black_tree_is_empty(tree));

    red_black_tree_destroy(tree);

    return 0;
}
