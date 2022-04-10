#include "cino_list.h"

/****************************************
 *               Iterator
 ****************************************/

typedef struct iterator_t {
    iter_t iter;  // points to the current element
} iterator_t;

/****************************************
 *               list_t
 ****************************************/

typedef struct node_t {
    T data;
    struct node_t *prev;
    struct node_t *next;
} node_t;

typedef struct list_t {
    node_t *head;
    node_t *tail;
    str_t data_type;
    size_t size;
    iterator_t *iterator;
} list_t;

/**
 * @brief   Determine if the data type is support by cino-list.
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
 * @brief   Create a list node by given data.
 * @param data  data
 * @return  Returns the created node.
 */
static node_t *list_node_create(T data) {
    node_t *node = (node_t *)calloc(1, sizeof(node_t));
    return_value_if_fail(node != NULL, NULL);
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/**
 * @brief   Create cino-list.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - T (generic)
 * @return  Returns the pointer to cino-list, or `NULL` if creation failed.
 */
list_t *list_create(const str_t data_type) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    list_t *list = (list_t *)calloc(1, sizeof(list_t));
    return_value_if_fail(list != NULL, NULL);

    list->iterator = (iterator_t *)calloc(1, sizeof(iterator_t));
    call_and_return_value_if_fail(list->iterator != NULL, list_destroy(list), NULL);

    list->data_type = (str_t)calloc(str_length(data_type) + 1, sizeof(char));
    call_and_return_value_if_fail(list->data_type != NULL, list_destroy(list), NULL);
    str_copy(list->data_type, data_type);

    list->head = list_node_create(NULL);
    call_and_return_value_if_fail(list->head != NULL, list_destroy(list), NULL);
    list->tail = list_node_create(NULL);
    call_and_return_value_if_fail(list->tail != NULL, list_destroy(list), NULL);

    list->head->next = list->tail;
    list->tail->prev = list->head;

    list->size = 0;
    list->iterator->iter = NULL;

    return list;
}

/**
 * @brief   Destroy cino-list.
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-list.
 * @param list  cino-list
 */
void list_destroy(list_t *list) {
    return_if_fail(list != NULL);

    while (!list_is_empty(list)) {
        T data = list_pop_front(list);
        if (str_equal(list->data_type, "int") || str_equal(list->data_type, "double")) {
            free(data);
            data = NULL;
        }
    }

    if (list->data_type) {
        free(list->data_type);
        list->data_type = NULL;
    }

    if (list->head) {
        free(list->head);
        list->head = NULL;
    }

    if (list->tail) {
        free(list->tail);
        list->tail = NULL;
    }

    if (list->iterator) {
        list->iterator->iter = NULL;
        free(list->iterator);
        list->iterator = NULL;
    }

    if (list) {
        free(list);
        list = NULL;
    }
}

/**
 * @brief   Determine if the cino-list is empty.
 * @param list  cino-list
 * @return  Returns `true` if the cino-list is empty, otherwise returns `false`.
 */
bool list_is_empty(const list_t *list) {
    return !list || list->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-list.
 * @param list  cino-list
 * @return  Returns the number of elements in the cino-list.
 */
size_t list_size(const list_t *list) {
    return_value_if_fail(list != NULL, 0);
    return list->size;
}

/**
 * @brief   Clear all the elments in the cino-list.
 * @note    It is caller's responsibility to free all the elements before calling
 *          this function, if it is a T (generic) cino-list.
 * @param list  cino-list
 * @return  Returns the modified cino-list.
 */
list_t *list_clear(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    while (!list_is_empty(list)) {
        T data = list_pop_front(list);
        if (str_equal(list->data_type, "int") || str_equal(list->data_type, "double")) {
            free(data);
            data = NULL;
        }
    }

    if (list->head) {
        free(list->head);
        list->head = NULL;
    }

    if (list->tail) {
        free(list->tail);
        list->tail = NULL;
    }

    if (list->iterator) {
        list->iterator->iter = NULL;
    }

    return list;
}

/**
 * @brief   Get the node in the cino-list by index.
 * @param list  cino-list
 * @param index index
 * @return  Returns a pointer points to the indexed node.
 */
static node_t *list_get_node(const list_t *list, int index) {
    return_value_if_fail(list != NULL && index >= 0 && index < list->size, NULL);

    node_t *node = NULL;

    if (index <= list->size / 2) {
        node = list->head->next;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    } else {
        node = list->tail->prev;
        for (int i = 0; i < list->size - index - 1; i++) {
            node = node->prev;
        }
    }

    return node;
}

/**
 * @brief   Get the first element in the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the first
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_get_front(const list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);

    if (str_equal(list->data_type, "int")) {
        return (T)wrap_int(*(int *)list->head->next->data);
    } else if (str_equal(list->data_type, "double")) {
        return (T)wrap_double(*(double *)list->head->next->data);
    } else if (str_equal(list->data_type, "T")) {
        return list->head->next->data;
    }

    return NULL;
}

/**
 * @brief   Get the last element in the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the last
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_get_back(const list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);

    if (str_equal(list->data_type, "int")) {
        return (T)wrap_int(*(int *)list->tail->prev->data);
    } else if (str_equal(list->data_type, "double")) {
        return (T)wrap_double(*(double *)list->tail->prev->data);
    } else if (str_equal(list->data_type, "T")) {
        return list->tail->prev->data;
    }

    return NULL;
}

/**
 * @brief   Get the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_get(const list_t *list, int index) {
    return_value_if_fail(list != NULL && index >= 0 && index < list->size, NULL);

    node_t *node = list_get_node(list, index);
    if (str_equal(list->data_type, "int")) {
        return (T)wrap_int(*(int *)node->data);
    } else if (str_equal(list->data_type, "double")) {
        return (T)wrap_double(*(double *)node->data);
    } else if (str_equal(list->data_type, "T")) {
        return node->data;
    }

    return NULL;
}

/**
 * @brief   Update the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  - For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 *              - For T (generic) cino-list, it is caller's responsibility to free
 *              the previous data before overwriting it.
 */
void list_set(list_t *list, int index, T data) {
    return_if_fail(list != NULL && index >= 0 && index < list->size);

    node_t *node = list_get_node(list, index);
    if (str_equal(list->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        *(int *)node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(list->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        *(double *)node->data = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(list->data_type, "T")) {
        node->data = data;
    }
}

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-list.
 * @param list      cino-list
 * @param context   - For primitive cino-list, a wrapper type of the searching data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-list, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-list, or `-1` if not found.
 */
int list_index_of(const list_t *list, void *context) {
    return_value_if_fail(list != NULL && context != NULL, -1);

    int index = -1;

    wrapper_int_t *wrapper_int = NULL;
    wrapper_double_t *wrapper_double = NULL;

    if (str_equal(list->data_type, "int")) {
        wrapper_int = (wrapper_int_t *)context;
    } else if (str_equal(list->data_type, "double")) {
        wrapper_double = (wrapper_double_t *)context;
    }

    node_t *current = list->head;
    int i = 0;
    while (current && current->next && current->next != list->tail) {
        current = current->next;

        if (str_equal(list->data_type, "int")) {
            if (*(int *)current->data == wrapper_int->data) {
                index = i;
                break;
            }
        } else if (str_equal(list->data_type, "double")) {
            if (*(double *)current->data == wrapper_double->data) {
                index = i;
                break;
            }
        } else if (str_equal(list->data_type, "T")) {
            match_t match = (match_t)context;
            if (match(current->data)) {
                index = i;
                break;
            }
        }

        i++;
    }

    if (str_equal(list->data_type, "int")) {
        unwrap_int(wrapper_int);
    } else if (str_equal(list->data_type, "double")) {
        unwrap_double(wrapper_double);
    }

    return index;
}

/**
 * @brief   Inserts the specified element at the beginning of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 * @return  Returns the modified cino-list.
 */
list_t *list_push_front(list_t *list, T data) {
    return_value_if_fail(list != NULL && data != NULL, list);

    node_t *node = list_node_create(NULL);
    return_value_if_fail(node != NULL, list);

    if (str_equal(list->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        node->data = calloc(1, sizeof(int));
        call_and_return_value_if_fail(node->data != NULL, free(node), list);
        *(int *)node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(list->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        node->data = calloc(1, sizeof(double));
        call_and_return_value_if_fail(node->data != NULL, free(node), list);
        *(double *)node->data = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(list->data_type, "T")) {
        node->data = data;
    }

    node->prev = list->head;
    node->next = list->head->next;
    list->head->next = node;
    node->next->prev = node;

    list->size++;
    return list;
}

/**
 * @brief   Inserts the specified element at the end of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 * @return  Returns the modified cino-list.
 */
list_t *list_push_back(list_t *list, T data) {
    return_value_if_fail(list != NULL && data != NULL, list);

    node_t *node = list_node_create(NULL);
    return_value_if_fail(node != NULL, list);

    if (str_equal(list->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        node->data = calloc(1, sizeof(int));
        call_and_return_value_if_fail(node->data != NULL, free(node), list);
        *(int *)node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(list->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        node->data = calloc(1, sizeof(double));
        call_and_return_value_if_fail(node->data != NULL, free(node), list);
        *(double *)node->data = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(list->data_type, "T")) {
        node->data = data;
    }

    node->next = list->tail;
    node->prev = list->tail->prev;
    list->tail->prev = node;
    node->prev->next = node;

    list->size++;
    return list;
}

/**
 * @brief   Removes the first element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_pop_front(list_t *list) {
    return_value_if_fail(list != NULL && !list_is_empty(list), NULL);

    T removed = NULL;

    node_t *node = list->head->next;

    if (str_equal(list->data_type, "int")) {
        int *data = (int *)node->data;
        wrapper_int_t *wrapper_int = wrap_int(*data);
        removed = (T)wrapper_int;
    } else if (str_equal(list->data_type, "double")) {
        double *data = (double *)node->data;
        wrapper_double_t *wrapper_double = wrap_double(*data);
        removed = (T)wrapper_double;
    } else if (str_equal(list->data_type, "T")) {
        removed = node->data;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;

    if (str_equal(list->data_type, "int") || str_equal(list->data_type, "double")) {
        if (node->data) {
            free(node->data);
            node->data = NULL;
        }
    }
    free(node);
    node = NULL;

    list->size--;
    return removed;
}

/**
 * @brief   Removes the last element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_pop_back(list_t *list) {
    return_value_if_fail(list != NULL && !list_is_empty(list), NULL);

    T removed = NULL;

    node_t *node = list->tail->prev;

    if (str_equal(list->data_type, "int")) {
        int *data = (int *)node->data;
        wrapper_int_t *wrapper_int = wrap_int(*data);
        removed = (T)wrapper_int;
    } else if (str_equal(list->data_type, "double")) {
        double *data = (double *)node->data;
        wrapper_double_t *wrapper_double = wrap_double(*data);
        removed = (T)wrapper_double;
    } else if (str_equal(list->data_type, "T")) {
        removed = node->data;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;

    if (str_equal(list->data_type, "int") || str_equal(list->data_type, "double")) {
        if (node->data) {
            free(node->data);
            node->data = NULL;
        }
    }
    free(node);
    node = NULL;

    list->size--;
    return removed;
}

/**
 * @brief   Inserts the specified element at the indexed location of the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 *              This function will unwrap for you.
 * @return  Returns the modified cino-list.
 */
list_t *list_insert(list_t *list, int index, T data) {
    return_value_if_fail(list != NULL && index >= 0 && index <= list->size && data != NULL, list);

    node_t *node = list_get_node(list, index);
    if (!node) {
        list_push_back(list, data);
        return list;
    }

    node_t *new_node = list_node_create(NULL);
    return_value_if_fail(new_node != NULL, list);

    if (str_equal(list->data_type, "int")) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)data;
        new_node->data = calloc(1, sizeof(int));
        call_and_return_value_if_fail(new_node->data != NULL, free(new_node), list);
        *(int *)new_node->data = wrapper_int->data;
        unwrap_int(wrapper_int);
    } else if (str_equal(list->data_type, "double")) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)data;
        new_node->data = calloc(1, sizeof(double));
        call_and_return_value_if_fail(new_node->data != NULL, free(new_node), list);
        *(double *)new_node->data = wrapper_double->data;
        unwrap_double(wrapper_double);
    } else if (str_equal(list->data_type, "T")) {
        new_node->data = data;
    }

    new_node->prev = node->prev;
    new_node->next = node;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;

    list->size++;
    return list;
}

/**
 * @brief   Removes the indexed element from the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap to get the primitive.
 */
T list_remove(list_t *list, int index) {
    return_value_if_fail(list != NULL && index >= 0 && index < list->size && !list_is_empty(list), NULL);

    T removed = NULL;

    node_t *node = list_get_node(list, index);

    if (str_equal(list->data_type, "int")) {
        int *data = (int *)node->data;
        wrapper_int_t *wrapper_int = wrap_int(*data);
        removed = (T)wrapper_int;
    } else if (str_equal(list->data_type, "double")) {
        double *data = (double *)node->data;
        wrapper_double_t *wrapper_double = wrap_double(*data);
        removed = (T)wrapper_double;
    } else if (str_equal(list->data_type, "T")) {
        removed = node->data;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;

    if (str_equal(list->data_type, "int") || str_equal(list->data_type, "double")) {
        if (node->data) {
            free(node->data);
            node->data = NULL;
        }
    }
    free(node);
    node = NULL;

    list->size--;
    return removed;
}

/**
 * @brief   Get the begin iterator.
 * @param list cino-list
 * @return  Returns the begin iterator.
 */
iter_t list_iter_begin(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    iter_t data = NULL;
    node_t *node = list->head->next;

    if (node == list->tail) {
        list->iterator->iter = NULL;
    } else {
        list->iterator->iter = (iter_t)node;
        data = (iter_t)node->data;
    }

    return data;
}

/**
 * @brief   Get the end iterator.
 * @param list cino-list
 * @return  Returns the end iterator.
 */
iter_t list_iter_end(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    iter_t data = NULL;
    node_t *node = list->tail->prev;

    if (node == list->head) {
        list->iterator->iter = NULL;
    } else {
        list->iterator->iter = (iter_t)node;
        data = (iter_t)node->data;
    }

    return data;
}

/**
 * @brief   Determine if exists the previous iterator.
 * @param list cino-list
 * @return  Returns `true` if previous iterator exists, otherwise returns `false`.
 */
bool list_iter_has_prev(const list_t *list) {
    return_value_if_fail(list != NULL && list->iterator->iter != NULL, false);
    node_t *node = (node_t *)list->iterator->iter;
    return node->prev && node->prev != list->head;
}

/**
 * @brief   Determine if exists the next iterator.
 * @param list cino-list
 * @return  Returns `true` if next iterator exists, otherwise returns `false`.
 */
bool list_iter_has_next(const list_t *list) {
    return_value_if_fail(list != NULL && list->iterator->iter != NULL, false);
    node_t *node = (node_t *)list->iterator->iter;
    return node->next && node->next != list->tail;
}

/**
 * @brief   Get the previous iterator.
 * @param list cino-list
 * @return  Returns the previous iterator.
 */
iter_t list_iter_prev(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    iter_t data = NULL;

    if (list_iter_has_prev(list)) {
        node_t *node = (node_t *)list->iterator->iter;
        list->iterator->iter = (iter_t)node->prev;
        data = (iter_t)node->prev->data;
    } else {
        list->iterator->iter = NULL;
    }

    return data;
}

/**
 * @brief   Get the next iterator.
 * @param list cino-list
 * @return  Returns the next iterator.
 */
iter_t list_iter_next(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    iter_t data = NULL;

    if (list_iter_has_next(list)) {
        node_t *node = (node_t *)list->iterator->iter;
        list->iterator->iter = (iter_t)node->next;
        data = (iter_t)node->next->data;
    } else {
        list->iterator->iter = NULL;
    }

    return data;
}