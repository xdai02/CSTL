#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "utils.h"

typedef struct queue_t queue_t;

/**
 * @brief Create a queue_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Return the created queue_t object if successful, otherwise return NULL.
 */
queue_t *queue_create(destroy_t destroy);

/**
 * @brief Destroy an queue_t object.
 * @param queue The queue_t object.
 */
void queue_destroy(queue_t *queue);

/**
 * @brief Determine whether an queue_t object is empty.
 * @param queue The queue_t object.
 * @return Returns true if the queue_t object is empty, otherwise returns false.
 */
bool queue_is_empty(const queue_t *queue);

/**
 * @brief Get the size of an queue_t object.
 * @param queue The queue_t object.
 * @return Returns the size of the queue_t object.
 */
size_t queue_size(const queue_t *queue);

/**
 * @brief Clear an queue_t object.
 * @param queue The queue_t object.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_clear(queue_t *queue);

/**
 * @brief Enqueue an element to an queue_t object.
 * @param queue The queue_t object.
 * @param elem The element.
 * @return Returns the modified queue_t object.
 */
queue_t *queue_enqueue(queue_t *queue, T elem);

/**
 * @brief Dequeue an element from an queue_t object.
 * @param queue The queue_t object.
 * @return Returns the popped element.
 */
T queue_dequeue(queue_t *queue);

/**
 * @brief Get the front element of an queue_t object.
 * @param queue The queue_t object.
 * @return Returns the front element.
 */
T queue_get_front(const queue_t *queue);

/**
 * @brief Get the back element of an queue_t object.
 * @param queue The queue_t object.
 * @return Returns the back element.
 */
T queue_get_back(const queue_t *queue);

#endif
