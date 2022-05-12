#include "cino_queue.h"
#include "cino_list.h"

/****************************************
 *               queue_t
 ****************************************/

typedef struct queue_t {
    list_t *list;
    data_type_t data_type;
    size_t size;
} queue_t;

/**
 * @brief   Create cino-queue.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-queue. Set to `NULL` if it is a primitive cino-queue.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-queue. Set to `NULL` if it is a primitive cino-queue.
 * @return  Returns the pointer to cino-queue, or `NULL` if creation failed.
 */
queue_t *queue_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    queue_t *queue = (queue_t *)calloc(1, sizeof(queue_t));
    return_value_if_fail(queue != NULL, NULL);

    queue->list = list_create(data_type, compare, destroy);
    call_and_return_value_if_fail(queue->list != NULL, free(queue), NULL);

    queue->size = 0;

    if (data_type == DATA_TYPE_INT) {
        queue->data_type = DATA_TYPE_INT;
    } else if (data_type == DATA_TYPE_DOUBLE) {
        queue->data_type = DATA_TYPE_DOUBLE;
    } else if (data_type == DATA_TYPE_CHAR) {
        queue->data_type = DATA_TYPE_CHAR;
    } else if (data_type == DATA_TYPE_T) {
        queue->data_type = DATA_TYPE_T;
    }

    return queue;
}

/**
 * @brief   Destroy cino-queue.
 * @param queue cino-queue
 */
void queue_destroy(queue_t *queue) {
    return_if_fail(queue != NULL);

    queue_clear(queue);

    if (queue->list) {
        list_destroy(queue->list);
        queue->list = NULL;
    }

    if (queue) {
        free(queue);
        queue = NULL;
    }
}

/**
 * @brief   Determine if the cino-queue is empty.
 * @param queue cino-queue
 * @return  Returns `true` if the cino-queue is empty, otherwise returns `false`.
 */
bool queue_is_empty(const queue_t *queue) {
    return !queue || queue->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-queue.
 * @param queue cino-queue
 * @return  Returns the number of elements in the cino-queue.
 */
size_t queue_size(const queue_t *queue) {
    return_value_if_fail(queue != NULL, 0);
    return queue->size;
}

/**
 * @brief   Clear all the elments in the cino-queue.
 * @param queue cino-queue
 * @return  Returns the modified cino-queue.
 */
queue_t *queue_clear(queue_t *queue) {
    return_value_if_fail(queue != NULL, NULL);
    list_clear(queue->list);
    queue->size = 0;
    return queue;
}

/**
 * @brief   Enqueue an elment to the cino-queue.
 * @param queue cino-queue
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-queue.
 */
queue_t *queue_enqueue(queue_t *queue, T data) {
    return_value_if_fail(queue != NULL && data != NULL, queue);
    list_push_back(queue->list, data);
    queue->size++;
    return queue;
}

/**
 * @brief   Dequeue an elment from the cino-queue.
 * @param queue cino-queue
 * @return  For primitive cino-queue, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T queue_dequeue(queue_t *queue) {
    return_value_if_fail(queue != NULL && queue->size > 0, NULL);
    T data = list_pop_front(queue->list);
    queue->size--;
    return data;
}

/**
 * @brief   Get the front elment in the cino-queue.
 * @param queue cino-queue
 * @return  For primitive cino-queue, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T queue_get_front(queue_t *queue) {
    return_value_if_fail(queue != NULL && queue->size > 0, NULL);
    return list_get_front(queue->list);
}