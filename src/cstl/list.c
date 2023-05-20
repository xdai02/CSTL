#include "cstl/list.h"

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

/**
 * @brief Create a node_t object.
 * @param elem The element.
 * @return Returns the created node_t object if successful, otherwise returns NULL.
 */
static node_t *__node_new(T elem) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = elem;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/**
 * @brief Create a list_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created list_t object if successful, otherwise returns NULL.
 */
list_t *list_new(compare_t compare, destroy_t destroy) {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    return_value_if_fail(list != NULL, NULL);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->compare = compare;
    list->destroy = destroy;

    return list;
}

/**
 * @brief Destroy a list_t object.
 * @param list The list_t object.
 */
void list_delete(list_t *list) {
    return_if_fail(list != NULL);
    list_clear(list);
    free(list);
}

/**
 * @brief Determine whether the list_t object is empty.
 * @param list The list_t object.
 * @return Returns true if the list_t object is empty, otherwise returns false.
 */
bool list_is_empty(const list_t *list) {
    return_value_if_fail(list != NULL, true);
    return list->size == 0;
}

/**
 * @brief Get the size of the list_t object.
 * @param list The list_t object.
 * @return Returns the size of the list_t object.
 */
size_t list_size(const list_t *list) {
    return_value_if_fail(list != NULL, 0);
    return list->size;
}

/**
 * @brief Traverse the list_t object.
 * @param list The list_t object.
 * @param visit Callback function for visiting a data item.
 */
void list_foreach(list_t *list, visit_t visit) {
    node_t *node = NULL;
    return_if_fail(list != NULL && visit != NULL);
    node = list->head;
    while (node != NULL) {
        visit(node->data);
        node = node->next;
    }
}

/**
 * @brief Clear the list_t object.
 * @param list The list_t object.
 * @return Returns the modified list_t object.
 */
list_t *list_clear(list_t *list) {
    node_t *node = NULL;
    node_t *next_node = NULL;

    return_value_if_fail(list != NULL, NULL);

    node = list->head;
    while (node != NULL) {
        next_node = node->next;
        if (list->destroy != NULL) {
            list->destroy(node->data);
        }
        free(node);
        node = next_node;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * @brief Get the specified node_t object.
 * @param list The list_t object.
 * @param index The index.
 * @return Returns the specified node_t object if successful, otherwise returns NULL.
 */
static node_t *__node_get(const list_t *list, size_t index) {
    node_t *node = NULL;
    size_t i = 0;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(index >= 0 && index < list->size, NULL);

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

    return node;
}

/**
 * @brief Get the element at the specified index of a list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @return Returns the element at the specified index of the list_t object.
 */
T list_get(const list_t *list, size_t index) {
    node_t *node = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(index >= 0 && index < list->size, NULL);

    node = __node_get(list, index);
    return_value_if_fail(node != NULL, NULL);
    return node->data;
}

/**
 * @brief Set the element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_set(list_t *list, size_t index, T elem) {
    node_t *node = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(index >= 0 && index < list->size, list);
    return_value_if_fail(elem != NULL, list);

    node = __node_get(list, index);
    return_value_if_fail(node != NULL, list);

    if (list->destroy != NULL) {
        list->destroy(node->data);
    }

    node->data = elem;
    return list;
}

/**
 * @brief Get the index of the specified element in the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the index of the specified element if found, otherwise returns -1.
 */
int list_index_of(const list_t *list, T elem) {
    node_t *node = NULL;
    int index = 0;

    return_value_if_fail(list != NULL && elem != NULL, -1);
    return_value_if_fail(list->compare != NULL, -1);

    node = list->head;
    while (node != NULL) {
        if (list->compare(node->data, elem) == 0) {
            return index;
        }

        index++;
        node = node->next;
    }

    return -1;
}

/**
 * @brief Determine whether the list_t object contains the specified element.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns true if the list_t object contains the specified element, otherwise returns false.
 */
bool list_contains(const list_t *list, T elem) {
    return_value_if_fail(list != NULL && elem != NULL, false);
    return list_index_of(list, elem) != -1;
}

/**
 * @brief Count the number of occurrences of the specified element in the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the number of occurrences of the specified element.
 */
size_t list_count(const list_t *list, T elem) {
    size_t count = 0;
    node_t *node = NULL;

    return_value_if_fail(list != NULL && elem != NULL, 0);
    return_value_if_fail(list->compare != NULL, 0);

    node = list->head;
    while (node != NULL) {
        if (list->compare(node->data, elem) == 0) {
            count++;
        }
        node = node->next;
    }
    return count;
}

/**
 * @brief Get the first element of the list_t object.
 * @param list The list_t object.
 * @return Returns the first element if successful, otherwise returns NULL.
 */
T list_get_front(const list_t *list) {
    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(list->size > 0, NULL);
    return list->head->data;
}

/**
 * @brief Get the last element of the list_t object.
 * @param list The list_t object.
 * @return Returns the last element if successful, otherwise returns NULL.
 */
T list_get_back(const list_t *list) {
    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(list->size > 0, NULL);
    return list->tail->data;
}

/**
 * @brief Insert the specified element at the beginning of the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_push_front(list_t *list, T elem) {
    node_t *node = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(elem != NULL, list);

    node = __node_new(elem);
    return_value_if_fail(node != NULL, list);

    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->size++;
    return list;
}

/**
 * @brief Insert the specified element at the end of the list_t object.
 * @param list The list_t object.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_push_back(list_t *list, T elem) {
    node_t *node = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(elem != NULL, list);

    node = __node_new(elem);
    return_value_if_fail(node != NULL, list);

    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
    return list;
}

/**
 * @brief Remove the first element of the list_t object.
 * @param list The list_t object.
 * @return Returns the removed element if successful, otherwise returns NULL.
 * @note Caller MUST free the returned element (if applicable).
 */
T list_pop_front(list_t *list) {
    node_t *node = NULL;
    T elem = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(list->size > 0, NULL);

    node = list->head;
    elem = node->data;

    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = node->next;
        list->head->prev = NULL;
    }

    free(node);
    list->size--;
    return elem;
}

/**
 * @brief Remove the last element of the list_t object.
 * @param list The list_t object.
 * @return Returns the removed element if successful, otherwise returns NULL.
 * @note Caller MUST free the returned element (if applicable).
 */
T list_pop_back(list_t *list) {
    node_t *node = NULL;
    T elem = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(list->size > 0, NULL);

    node = list->tail;
    elem = node->data;

    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = node->prev;
        list->tail->next = NULL;
    }

    free(node);
    list->size--;
    return elem;
}

/**
 * @brief Insert the specified element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified list_t object.
 */
list_t *list_insert(list_t *list, size_t index, T elem) {
    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(index >= 0 && index <= list->size, list);
    return_value_if_fail(elem != NULL, list);

    if (index == 0) {
        list_push_front(list, elem);
    } else if (index == list->size) {
        list_push_back(list, elem);
    } else {
        node_t *node = NULL;
        node_t *new_node = NULL;

        node = __node_get(list, index);
        return_value_if_fail(node != NULL, list);

        new_node = __node_new(elem);
        return_value_if_fail(new_node != NULL, list);

        new_node->prev = node->prev;
        new_node->next = node;
        node->prev->next = new_node;
        node->prev = new_node;

        list->size++;
    }

    return list;
}

/**
 * @brief Removes the element at the specified position in the list_t object.
 * @param list The list_t object.
 * @param index The index.
 * @return Returns the removed element if successful, otherwise returns NULL.
 * @note Caller MUST free the returned element (if applicable).
 */
T list_remove(list_t *list, size_t index) {
    node_t *node = NULL;
    T elem = NULL;

    return_value_if_fail(list != NULL, NULL);
    return_value_if_fail(index >= 0 && index < list->size, NULL);

    if (index == 0) {
        return list_pop_front(list);
    } else if (index == list->size - 1) {
        return list_pop_back(list);
    } else {
        node = __node_get(list, index);
        return_value_if_fail(node != NULL, NULL);

        elem = node->data;
        node->prev->next = node->next;
        node->next->prev = node->prev;

        free(node);
        list->size--;
        return elem;
    }
}

/**
 * @brief Reverse the list_t object.
 * @param list The list_t object.
 * @return Returns the modified list_t object.
 */
list_t *list_reverse(list_t *list) {
    node_t *node = NULL;
    node_t *next = NULL;

    return_value_if_fail(list != NULL, NULL);

    node = list->head;
    while (node != NULL) {
        next = node->next;
        node->next = node->prev;
        node->prev = next;
        node = next;
    }

    node = list->head;
    list->head = list->tail;
    list->tail = node;

    return list;
}

/**
 * @brief Create an iterator for a list_t object.
 * @param list The list_t object.
 * @return Returns the iterator for container.
 */
iterator_t *list_iterator_new(const list_t *list) {
    iterator_t *iterator = NULL;

    return_value_if_fail(list != NULL, NULL);

    iterator = (iterator_t *)malloc(sizeof(iterator_t));
    return_value_if_fail(iterator != NULL, NULL);

    iterator->container = (void *)list;
    iterator->current = list->head;
    return iterator;
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void list_iterator_delete(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    free(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool list_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return iterator->current != NULL;
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T list_iterator_next(iterator_t *iterator) {
    T elem = NULL;

    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(list_iterator_has_next(iterator), NULL);

    elem = ((node_t *)iterator->current)->data;
    iterator->current = ((node_t *)iterator->current)->next;
    return elem;
}
