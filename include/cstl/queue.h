#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "utils/utils.h"

typedef struct queue_t queue_t;

/**
 * @brief Create a queue_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created queue_t object if successful, otherwise return NULL.
 */
queue_t *queue_create(destroy_t destroy);

/**
 * @brief Destroy a queue_t object.
 * @param queue The queue_t object.
 */
void queue_destroy(queue_t *queue);

/**
 * @brief Determine whether a queue_t object is empty.
 * @param queue The queue_t object.
 * @return Returns true if the queue_t object is empty, otherwise returns false.
 */
bool queue_is_empty(const queue_t *queue);

/**
 * @brief Get the size of a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the size of the queue_t object.
 */
size_t queue_size(const queue_t *queue);

/**
 * @brief Clear a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_clear(queue_t *queue);

/**
 * @brief Enqueue an element to a queue_t object.
 * @param queue The queue_t object.
 * @param elem The element.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_enqueue(queue_t *queue, T elem);

/**
 * @brief Dequeue an element from a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the dequeued element.
 */
T queue_dequeue(queue_t *queue);

/**
 * @brief Get the front element of a queue_t object.
 * @param queue The queue_t object.
 * @return Returns the front element.
 */
T queue_peek(const queue_t *queue);

#endif
