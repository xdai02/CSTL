#include "deque.h"
#include "list.h"
#include "utils.h"

struct deque_t {
    list_t *list;
};

deque_t *deque_create(destroy_t destroy) {
    deque_t *deque = (deque_t *)malloc(sizeof(deque_t));
    return_value_if_fail(deque != NULL, NULL);

    deque->list = list_create(NULL, destroy);
    if (deque->list == NULL) {
        free(deque);
        return NULL;
    }

    return deque;
}

void deque_destroy(deque_t *deque) {
    return_if_fail(deque != NULL);
    list_destroy(deque->list);
    free(deque);
}

bool deque_is_empty(const deque_t *deque) {
    return_value_if_fail(deque != NULL, true);
    return list_is_empty(deque->list);
}

size_t deque_size(const deque_t *deque) {
    return_value_if_fail(deque != NULL, 0);
    return list_size(deque->list);
}

deque_t *deque_clear(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    list_clear(deque->list);
    return deque;
}

deque_t *deque_push_front(deque_t *deque, T elem) {
    return_value_if_fail(deque != NULL, NULL);
    list_push_front(deque->list, elem);
    return deque;
}

deque_t *deque_push_back(deque_t *deque, T elem) {
    return_value_if_fail(deque != NULL, NULL);
    list_push_back(deque->list, elem);
    return deque;
}

T deque_pop_front(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_pop_front(deque->list);
}

T deque_pop_back(deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_pop_back(deque->list);
}

T deque_get_front(const deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_get_front(deque->list);
}

T deque_get_back(const deque_t *deque) {
    return_value_if_fail(deque != NULL, NULL);
    return list_get_back(deque->list);
}
