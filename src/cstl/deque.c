#include "cstl/deque.h"
#include "cstl/list.h"

struct deque_t {
    list_t *list;
};

/**
 * @brief Create a deque_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created deque_t object if successful, otherwise return NULL.
 */
deque_t *deque_new(destroy_t destroy) {
    deque_t *deque = (deque_t *)malloc(sizeof(deque_t));
    return_value_if_fail(deque != NULL, NULL);

    deque->list = list_new(NULL, destroy);
    if (deque->list == NULL) {
        free(deque);
        return NULL;
    }

    return deque;
}

/**
 * @brief Destroy a deque_t object.
 * @param deque The deque_t object.
 */
void deque_delete(deque_t *deque) {
    return_if_fail(deque != NULL);
    list_delete(deque->list);
    free(deque);
}

/**
 * @brief Determine whether a deque_t object is empty.
 * @param deque The deque_t object.
 * @return Returns true if the deque_t object is empty, otherwise returns false.
 */
bool deque_is_empty(const deque_t *deque) {
    return_value_if_fail(deque != NULL, true);
    return list_is_empty(deque->list);
}

/**
 * @brief Get the size of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the size of the deque_t object.
 */
size_t deque_size(const deque_t *deque) {
    return_value_if_fail(deque != NULL, 0);
    return list_size(deque->list);
}

/**
 * @brief Clear a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_clear(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    list_clear(deque->list);
    return deque;
}

/**
 * @brief Push an element to the front of a deque_t object.
 * @param deque The deque_t object.
 * @param elem The element.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_push_front(deque_t *deque, T elem) {
    return_value_if_fail(deque != NULL, NULL);
    list_push_front(deque->list, elem);
    return deque;
}

/**
 * @brief Push an element to the back of a deque_t object.
 * @param deque The deque_t object.
 * @param elem The element.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_push_back(deque_t *deque, T elem) {
    return_value_if_fail(deque != NULL, NULL);
    list_push_back(deque->list, elem);
    return deque;
}

/**
 * @brief Pop an element from the front of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the popped element.
 */
T deque_pop_front(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_pop_front(deque->list);
}

/**
 * @brief Pop an element from the back of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the popped element.
 */
T deque_pop_back(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_pop_back(deque->list);
}

/**
 * @brief Get the front element of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the front element.
 */
T deque_get_front(const deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_get_front(deque->list);
}

/**
 * @brief Get the back element of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the front element.
 */
T deque_get_back(const deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_get_back(deque->list);
}
