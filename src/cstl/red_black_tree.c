#include "cstl/red_black_tree.h"

typedef enum {
    RED,
    BLACK
} color_t;

typedef struct node_t {
    T key;
    color_t color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} node_t;

struct red_black_tree_t {
    node_t *root;
    size_t size;
    compare_t compare;
    destroy_t destroy;
};

/**
 * @brief Create a node_t object.
 * @param key The key.
 * @param color The color (RED/BLACK).
 * @param left The pointer to the left child.
 * @param right The pointer to the right child.
 * @param parent The pointer to the parent.
 * @return Returns the node_t object if create successfully, otherwise returns NULL.
 */
static node_t *__node_create(T key, color_t color, node_t *left, node_t *right, node_t *parent) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);

    node->key = key;
    node->color = color;
    node->left = left;
    node->right = right;
    node->parent = parent;
    return node;
}

/**
 * @brief Destroy a node_t object.
 * @param tree The red_black_tree_t object.
 * @param node The node_t object.
 */
static void __node_destroy(red_black_tree_t *tree, node_t *node) {
    return_if_fail(tree != NULL && node != NULL);
    __node_destroy(tree, node->left);
    __node_destroy(tree, node->right);
    if (tree->destroy != NULL) {
        tree->destroy(node->key);
    }
    free(node);
}

/**
 * @brief Get the color of the node.
 * @param node The node_t object.
 * @return Returns the color of the node. For NIL nodes, returns BLACK.
 */
static color_t __node_color(node_t *node) {
    return_value_if_fail(node != NULL, BLACK);
    return node->color;
}

/**
 * @brief Create a red_black_tree_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the red_black_tree_t object if create successfully, otherwise returns NULL.
 */
red_black_tree_t *red_black_tree_create(compare_t compare, destroy_t destroy) {
    red_black_tree_t *tree = NULL;

    return_value_if_fail(compare != NULL, NULL);

    tree = (red_black_tree_t *)malloc(sizeof(red_black_tree_t));
    return_value_if_fail(tree != NULL, NULL);

    tree->root = NULL;
    tree->size = 0;
    tree->compare = compare;
    tree->destroy = destroy;
    return tree;
}

/**
 * @brief Destroy a red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 */
void red_black_tree_destroy(red_black_tree_t *tree) {
    return_if_fail(tree != NULL);
    __node_destroy(tree, tree->root);
    free(tree);
}

/**
 * @brief Determine whether the red_black_tree_t object is empty.
 * @param tree The red_black_tree_t object.
 * @return Returns true if the red_black_tree_t object is empty, otherwise returns false.
 */
bool red_black_tree_is_empty(const red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, true);
    return tree->size == 0;
}

/**
 * @brief Get the number of nodes in the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @return Returns the number of nodes in the red_black_tree_t object.
 */
size_t red_black_tree_size(const red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, 0);
    return tree->size;
}

/**
 * @brief Clear the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @return Returns the modified red_black_tree_t object.
 */
red_black_tree_t *red_black_tree_clear(red_black_tree_t *tree) {
    return_value_if_fail(tree != NULL, NULL);
    __node_destroy(tree, tree->root);
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

/**
 * @brief Checks whether the red_black_tree_t object contains the key.
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns true if the red_black_tree_t object contains the key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool red_black_tree_contains(const red_black_tree_t *tree, T key) {
    node_t *node = NULL;
    int cmp;

    return_value_if_fail(tree != NULL, false);
    return_value_if_fail(tree->compare != NULL, false);

    node = tree->root;
    while (node != NULL) {
        cmp = tree->compare(key, node->key);
        if (cmp < 0) {
            node = node->left;
        } else if (cmp > 0) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}

/**
 * @brief Traverse the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @param visit Callback function for visiting a data item.
 */
void red_black_tree_foreach(red_black_tree_t *tree, visit_t visit) {
    iterator_t *iterator = NULL;
    T key = NULL;

    return_if_fail(tree != NULL && visit != NULL);

    iterator = red_black_tree_iterator_create(tree);
    return_if_fail(iterator != NULL);

    while (red_black_tree_iterator_has_next(iterator)) {
        key = red_black_tree_iterator_next(iterator);
        visit(key);
    }

    red_black_tree_iterator_destroy(iterator);
}

/**
 * @brief Get the grandparent node of a node.
 * @param node The node_t object.
 * @return Returns the grandparent node of a node. If not exists, returns NULL.
 */
static node_t *__grandparent(node_t *node) {
    return_value_if_fail(node != NULL && node->parent != NULL, NULL);
    return node->parent->parent;
}

/**
 * @brief Get the uncle node of a node.
 * @param node The node_t object.
 * @return Returns the uncle node of a node. If not exists, returns NULL.
 */
static node_t *__uncle(node_t *node) {
    node_t *grandparent = __grandparent(node);
    return_value_if_fail(grandparent != NULL, NULL);
    if (node->parent == grandparent->left) {
        return grandparent->right;
    } else {
        return grandparent->left;
    }
}

/**
 * @brief Perform a left rotation on a node.
 * @param tree The red_black_tree_t object.
 * @param x The node to perform a left rotation on.
 */
static void __left_rotate(red_black_tree_t *tree, node_t *x) {
    node_t *y = NULL;

    return_if_fail(tree != NULL && x != NULL);

    y = x->right;
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

/**
 * @brief Perform a right rotation on a node.
 * @param tree The red_black_tree_t object.
 * @param x The node to perform a right rotation on.
 */
static void __right_rotate(red_black_tree_t *tree, node_t *x) {
    node_t *y = NULL;

    return_if_fail(tree != NULL && x != NULL);

    y = x->left;
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

/**
 * @brief Fix the red-black tree after insertion to maintain its properties.
 * @param tree The red_black_tree_t object.
 * @param node The newly inserted node.
 */
static void __insert_fixup(red_black_tree_t *tree, node_t *node) {
    node_t *uncle = NULL;
    node_t *grandparent = NULL;

    return_if_fail(tree != NULL && node != NULL);

    while (node->parent != NULL && node->parent->color == RED) {
        uncle = __uncle(node);
        if (uncle != NULL && uncle->color == RED) {
            node->parent->color = BLACK;
            uncle->color = BLACK;
            __grandparent(node)->color = RED;
            node = __grandparent(node);
        } else {
            grandparent = __grandparent(node);

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

/**
 * @brief Inserts a key into the red-black tree.
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns the modified red_black_tree_t object.
 */
red_black_tree_t *red_black_tree_insert(red_black_tree_t *tree, T key) {
    node_t *node = NULL;
    node_t *current = NULL;
    node_t *parent = NULL;
    int cmp;

    return_value_if_fail(tree != NULL && key != NULL, tree);
    return_value_if_fail(tree->compare != NULL, tree);

    node = __node_create(key, RED, NULL, NULL, NULL);
    return_value_if_fail(node != NULL, tree);

    if (tree->root == NULL) {
        tree->root = node;
    } else {
        current = tree->root;
        parent = NULL;

        while (current != NULL) {
            parent = current;
            cmp = tree->compare(key, current->key);
            if (cmp < 0) {
                current = current->left;
            } else if (cmp > 0) {
                current = current->right;
            } else {
                __node_destroy(tree, node);
                return tree;
            }
        }

        node->parent = parent;
        cmp = tree->compare(key, parent->key);
        if (cmp < 0) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    __insert_fixup(tree, node);
    tree->size++;
    return tree;
}

/**
 * @brief Get the minimum node in the red_black_tree_t object.
 * @param node The node_t object.
 * @return Returns the minimum node if exists, otherwise returns NULL.
 */
static node_t *__min_node(const node_t *node) {
    node_t *min_node = NULL;

    return_value_if_fail(node != NULL, NULL);

    min_node = (node_t *)node;
    while (min_node->left != NULL) {
        min_node = min_node->left;
    }
    return min_node;
}

/**
 * @brief Transplant a node in the red-black tree.
 * @param tree The red_black_tree_t object.
 * @param u The node to replace.
 * @param v The node to replace u with.
 */
static void __transplant(red_black_tree_t *tree, node_t *u, node_t *v) {
    return_if_fail(tree != NULL && u != NULL);

    if (u->parent == NULL) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != NULL) {
        v->parent = u->parent;
    }
}

/**
 * @brief Fix the red-black tree after removal to maintain its properties.
 * @param tree The red_black_tree_t object.
 * @param x The node to fix up.
 */
static void __remove_fixup(red_black_tree_t *tree, node_t *x) {
    node_t *w = NULL;

    return_if_fail(tree != NULL && x != NULL);

    while (x != tree->root && __node_color(x) == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w == NULL) {
                break;
            }

            if (__node_color(w) == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                __left_rotate(tree, x->parent);
                w = x->parent->right;
            }

            if (w == NULL) {
                break;
            }

            if (__node_color(w->left) == BLACK && __node_color(w->right) == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (__node_color(w->right) == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    __right_rotate(tree, w);
                    w = x->parent->right;
                }

                w->color = __node_color(x->parent);
                x->parent->color = BLACK;
                w->right->color = BLACK;
                __left_rotate(tree, x->parent);
                x = tree->root;
            }
        } else {
            w = x->parent->left;
            if (w == NULL) {
                break;
            }

            if (__node_color(w) == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                __right_rotate(tree, x->parent);
                w = x->parent->left;
            }

            if (w == NULL) {
                break;
            }

            if (__node_color(w->right) == BLACK && __node_color(w->left) == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (__node_color(w->left) == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    __left_rotate(tree, w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                __right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }

    x->color = BLACK;
}

/**
 * @brief Removes a key from the red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @param key The key.
 * @return Returns the modified red_black_tree_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
red_black_tree_t *red_black_tree_remove(red_black_tree_t *tree, T key) {
    node_t *x = NULL;
    node_t *y = NULL;
    node_t *z = NULL;
    color_t y_original_color;
    int cmp;

    return_value_if_fail(tree != NULL && key != NULL, tree);
    return_value_if_fail(tree->compare != NULL, tree);

    z = tree->root;
    while (z != NULL) {
        cmp = tree->compare(key, z->key);
        if (cmp < 0) {
            z = z->left;
        } else if (cmp > 0) {
            z = z->right;
        } else {
            break;
        }
    }

    /* key not found */
    return_value_if_fail(z != NULL, tree);

    y = z;
    y_original_color = y->color;

    if (z->left == NULL) {
        x = z->right;
        __transplant(tree, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        __transplant(tree, z, z->left);
    } else {
        y = __min_node(z->right);
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) {
            if (x != NULL) {
                x->parent = y;
            }
        } else {
            __transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        __transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK) {
        __remove_fixup(tree, x);
    }

    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    __node_destroy(tree, z);

    tree->size--;
    return tree;
}

/**
 * @brief Get the successor of a node.
 * @param node The node_t object.
 * @return Returns the successor of a node if exists, otherwise returns NULL.
 */
static node_t *__successor(node_t *node) {
    node_t *successor = NULL;

    return_value_if_fail(node != NULL, NULL);

    if (node->right != NULL) {
        return __min_node(node->right);
    }

    successor = node->parent;
    while (successor != NULL && node == successor->right) {
        node = successor;
        successor = successor->parent;
    }
    return successor;
}

/**
 * @brief Create an iterator for an red_black_tree_t object.
 * @param tree The red_black_tree_t object.
 * @return Returns the iterator for container.
 */
iterator_t *red_black_tree_iterator_create(const red_black_tree_t *tree) {
    iterator_t *iterator = NULL;

    return_value_if_fail(tree != NULL, NULL);

    iterator = (iterator_t *)malloc(sizeof(iterator_t));
    return_value_if_fail(iterator != NULL, NULL);

    iterator->container = (void *)tree;
    iterator->current = __min_node(tree->root);
    return iterator;
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void red_black_tree_iterator_destroy(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    free(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool red_black_tree_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return iterator->current != NULL;
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T red_black_tree_iterator_next(iterator_t *iterator) {
    T elem = NULL;

    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(red_black_tree_iterator_has_next(iterator), NULL);

    elem = ((node_t *)iterator->current)->key;
    iterator->current = __successor(iterator->current);
    return elem;
}
