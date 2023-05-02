#include "queue.h"
#include "list.h"
#include "utils.h"

struct queue_t {
    list_t *list;
};

queue_t *queue_create(destroy_t destroy) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    return_value_if_fail(queue != NULL, NULL);

    queue->list = list_create(NULL, destroy);
    if (queue->list == NULL) {
        free(queue);
        return NULL;
    }

    return queue;
}

void queue_destroy(queue_t *queue) {
    return_if_fail(queue != NULL);
    list_destroy(queue->list);
    free(queue);
}

bool queue_is_empty(const queue_t *queue) {
    return_value_if_fail(queue != NULL, true);
    return list_is_empty(queue->list);
}

size_t queue_size(const queue_t *queue) {
    return_value_if_fail(queue != NULL, 0);
    return list_size(queue->list);
}

queue_t *queue_clear(queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    list_clear(queue->list);
    return queue;
}

queue_t *queue_enqueue(queue_t *queue, T elem) {
    return_value_if_fail(queue != NULL, NULL);
    list_push_back(queue->list, elem);
    return queue;
}

T queue_dequeue(queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    return list_pop_front(queue->list);
}

T queue_get_front(const queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    return list_get_front(queue->list);
}

T queue_get_back(const queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    return list_get_back(queue->list);
}
