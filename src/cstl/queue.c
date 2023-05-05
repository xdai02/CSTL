#include "queue.h"
#include "list.h"

struct queue_t {
    list_t *list;
};

/**
 * @brief Create a queue_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created queue_t object if successful, otherwise return NULL.
 */
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

/**
 * @brief Destroy a queue_t object.
 * @param queue The queue_t object.
 */
void queue_destroy(queue_t *queue) {
    return_if_fail(queue != NULL);
    list_destroy(queue->list);
    free(queue);
}

/**
 * @brief Determine whether a queue_t object is empty.
 * @param queue The queue_t object.
 * @return Returns true if the queue_t object is empty, otherwise returns false.
 */
bool queue_is_empty(const queue_t *queue) {
    return_value_if_fail(queue != NULL, true);
    return list_is_empty(queue->list);
}

/**
 * @brief Get the size of a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the size of the queue_t object.
 */
size_t queue_size(const queue_t *queue) {
    return_value_if_fail(queue != NULL, 0);
    return list_size(queue->list);
}

/**
 * @brief Clear a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_clear(queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    list_clear(queue->list);
    return queue;
}

/**
 * @brief Enqueue an element to a queue_t object.
 * @param queue The queue_t object.
 * @param elem The element.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_enqueue(queue_t *queue, T elem) {
    return_value_if_fail(queue != NULL, NULL);
    list_push_back(queue->list, elem);
    return queue;
}

/**
 * @brief Dequeue an element from a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the dequeued element.
 */
T queue_dequeue(queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    return list_pop_front(queue->list);
}

/**
 * @brief Get the front element of a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the front element.
 */
T queue_peek(const queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    return list_get_front(queue->list);
}
