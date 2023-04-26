#include "coop_list.h"
#include "coop_utils.h"

typedef struct node_t {
    T data;
    struct node_t *prev;
    struct node_t *next;
} node_t;

struct list_t {
    node_t *head;
    node_t *tail;
    size_t size;
    compare_t compare;
    destroy_t destroy;
};

static node_t *node_create(T elem) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = elem;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

list_t *list_create(compare_t compare, destroy_t destroy) {
    list_t *list = NULL;

    return_value_if_fail(compare != NULL && destroy != NULL, NULL);

    list = (list_t *)malloc(sizeof(list_t));
    return_value_if_fail(list != NULL, NULL);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->compare = compare;
    list->destroy = destroy;

    return list;
}

void list_destroy(list_t *list) {
    return_if_fail(list != NULL);
    list_clear(list);
    free(list);
}

void list_foreach(list_t *list, visit_t visit) {
    node_t *node = NULL;
    return_if_fail(list != NULL && visit != NULL);
    node = list->head;
    while (node != NULL) {
        visit(node->data);
        node = node->next;
    }
}

bool list_is_empty(const list_t *list) {
    return_value_if_fail(list != NULL, true);
    return list->size == 0;
}

size_t list_size(const list_t *list) {
    return_value_if_fail(list != NULL, 0);
    return list->size;
}

list_t *list_clear(list_t *list) {
    return_value_if_fail(list != NULL, NULL);
    list_foreach(list, list->destroy);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

T list_get(const list_t *list, size_t index) {
    node_t *node = NULL;
    size_t i = 0;

    return_value_if_fail(list != NULL && index >= 0 && index < list->size, NULL);

    if (index <= list->size / 2) {
        node = list->head;
        for (i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = list->tail;
        for (i = list->size - 1; i > index; i--) {
            node = node->prev;
        }
    }

    return node->data;
}

list_t *list_set(list_t *list, size_t index, T elem) {
    node_t *node = NULL;
    size_t i = 0;

    return_if_fail(list != NULL && index >= 0 && index < list->size);

    if (index <= list->size / 2) {
        node = list->head;
        for (i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = list->tail;
        for (i = list->size - 1; i > index; i--) {
            node = node->prev;
        }
    }

    list->destroy(node->data);
    node->data = elem;
    return list;
}
