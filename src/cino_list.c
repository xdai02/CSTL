#include "cino_list.h"

/****************************************
 *               list_t
 ****************************************/

typedef enum data_type_t {
    DATA_TYPE_INT,
    DATA_TYPE_DOUBLE,
    DATA_TYPE_CHAR,
    DATA_TYPE_T,
} data_type_t;

typedef struct node_t {
    T data;
    struct node_t *prev;
    struct node_t *next;
} node_t;

typedef struct list_t {
    node_t *head;
    node_t *tail;
    data_type_t data_type;
    size_t size;
    compare_t compare;
    destroy_t destroy;
} list_t;

/**
 * @brief   Determine if the data type is support by cino-list.
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
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
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
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
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
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
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
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    return (byte_t *)data1 - (byte_t *)data2;
}

/**
 * @brief   Specify the rules for destroying a single int element.
 * @param data  pointer to the element
 */
static void destroy_int(T data) {
    return_if_fail(data != NULL);
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    unwrap_int(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single double element.
 * @param data  pointer to the element
 */
static void destroy_double(T data) {
    return_if_fail(data != NULL);
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    unwrap_double(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single char element.
 * @param data  pointer to the element
 */
static void destroy_char(T data) {
    return_if_fail(data != NULL);
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
 *                      - char
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-list. Set to `NULL` if it is a primitive cino-list.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-list. Set to `NULL` if it is a primitive cino-list.
 * @return  Returns the pointer to cino-list, or `NULL` if creation failed.
 */
list_t *list_create(const str_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    list_t *list = (list_t *)calloc(1, sizeof(list_t));
    return_value_if_fail(list != NULL, NULL);

    list->size = 0;

    if (str_equal(data_type, "int")) {
        list->data_type = DATA_TYPE_INT;
        list->compare = compare_int;
        list->destroy = destroy_int;
    } else if (str_equal(data_type, "double")) {
        list->data_type = DATA_TYPE_DOUBLE;
        list->compare = compare_double;
        list->destroy = destroy_double;
    } else if (str_equal(data_type, "char")) {
        list->data_type = DATA_TYPE_CHAR;
        list->compare = compare_char;
        list->destroy = destroy_char;
    } else if (str_equal(data_type, "T")) {
        list->data_type = DATA_TYPE_T;
        list->compare = compare ? compare : compare_default;
        list->destroy = destroy ? destroy : destroy_default;
    }

    list->head = list_node_create(NULL);
    call_and_return_value_if_fail(list->head != NULL, list_destroy(list), NULL);
    list->tail = list_node_create(NULL);
    call_and_return_value_if_fail(list->tail != NULL, list_destroy(list), NULL);

    list->head->next = list->tail;
    list->tail->prev = list->head;

    return list;
}

/**
 * @brief   Destroy cino-list.
 * @param list  cino-list
 */
void list_destroy(list_t *list) {
    return_if_fail(list != NULL);

    list_clear(list);

    list->destroy = NULL;
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
 * @param list  cino-list
 * @return  Returns the modified cino-list.
 */
list_t *list_clear(list_t *list) {
    return_value_if_fail(list != NULL, NULL);

    while (!list_is_empty(list)) {
        T data = list_pop_front(list);
        list->destroy(data);
    }

    list->size = 0;

    if (list->head) {
        free(list->head);
        list->head = NULL;
    }

    if (list->tail) {
        free(list->tail);
        list->tail = NULL;
    }

    return list;
}

/**
 * @brief   Traverse cino-list.
 * @param list      cino-list
 * @param visit     user-defined callback function for visiting a single element
 * @param reverse   true = backward, false = forward
 */
void list_foreach(list_t *list, visit_t visit, bool backward) {
    return_if_fail(list != NULL && visit != NULL);

    if (!backward) {
        node_t *cur = list->head;
        while (cur && cur->next && cur->next != list->tail) {
            cur = cur->next;
            visit(cur->data);
        }
    } else {
        node_t *cur = list->tail;
        while (cur && cur->prev && cur->prev != list->head) {
            cur = cur->prev;
            visit(cur->data);
        }
    }
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
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get_front(const list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);
    return list->head->next->data;
}

/**
 * @brief   Get the last element in the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the last
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get_back(const list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);
    return list->tail->prev->data;
}

/**
 * @brief   Get the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get(const list_t *list, int index) {
    return_value_if_fail(list != NULL && index >= 0 && index < list->size, NULL);
    node_t *node = list_get_node(list, index);
    return node->data;
}

/**
 * @brief   Update the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 */
void list_set(list_t *list, int index, T data) {
    return_if_fail(list != NULL && index >= 0 && index < list->size);
    node_t *node = list_get_node(list, index);
    list->destroy(node->data);
    node->data = data;
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
    int i = 0;

    if (list->data_type == DATA_TYPE_T) {
        match_t match = (match_t)context;
        node_t *cur = list->head;
        while (cur && cur->next && cur->next != list->tail) {
            cur = cur->next;
            if (match(cur->data)) {
                index = i;
                break;
            }
            i++;
        }
    } else {
        node_t *cur = list->head;
        while (cur && cur->next && cur->next != list->tail) {
            cur = cur->next;
            if (list->compare(cur->data, context) == 0) {
                index = i;
                break;
            }
            i++;
        }
        list->destroy(context);
    }

    return index;
}

/**
 * @brief   Inserts the specified element at the beginning of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-list.
 */
list_t *list_push_front(list_t *list, T data) {
    return_value_if_fail(list != NULL && data != NULL, list);
    return list_insert(list, 0, data);
}

/**
 * @brief   Inserts the specified element at the end of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed
 * @return  Returns the modified cino-list.
 */
list_t *list_push_back(list_t *list, T data) {
    return_value_if_fail(list != NULL && data != NULL, list);
    return list_insert(list, list->size, data);
}

/**
 * @brief   Removes the first element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_pop_front(list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);
    return list_remove(list, 0);
}

/**
 * @brief   Removes the last element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_pop_back(list_t *list) {
    return_value_if_fail(list != NULL && list->size > 0, NULL);
    return list_remove(list, list->size - 1);
}

/**
 * @brief   Inserts the specified element at the indexed location of the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-list.
 */
list_t *list_insert(list_t *list, int index, T data) {
    return_value_if_fail(list != NULL && index >= 0 && index <= list->size && data != NULL, list);

    node_t *new_node = list_node_create(data);
    return_value_if_fail(new_node != NULL, list);

    if (index == list->size) {
        new_node->next = list->tail;
        new_node->prev = list->tail->prev;
        list->tail->prev = new_node;
        new_node->prev->next = new_node;
    } else {
        node_t *cur_node = list_get_node(list, index);
        new_node->prev = cur_node->prev;
        new_node->next = cur_node;
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
    }

    list->size++;
    return list;
}

/**
 * @brief   Removes the indexed element from the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T list_remove(list_t *list, int index) {
    return_value_if_fail(list != NULL && index >= 0 && index < list->size && list->size > 0, NULL);

    node_t *node = list_get_node(list, index);
    T removed = node->data;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;

    free(node);
    node = NULL;

    list->size--;
    return removed;
}