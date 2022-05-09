/**************************************************
 * Module   :   cino_queue
 * Function :   Operations on cino-queue
 * Category :
 *              - queue_t
 **************************************************/

#ifndef _CINO_QUEUE_H_
#define _CINO_QUEUE_H_

#include "cino_utils.h"

/****************************************
 *               queue_t
 ****************************************/

typedef struct queue_t queue_t;

/**
 * @brief   Create cino-queue.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - char
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-queue. Set to `NULL` if it is a primitive cino-queue.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-queue. Set to `NULL` if it is a primitive cino-queue.
 * @return  Returns the pointer to cino-queue, or `NULL` if creation failed.
 */
queue_t *queue_create(const str_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-queue.
 * @param queue cino-queue
 */
void queue_destroy(queue_t *queue);

/**
 * @brief   Determine if the cino-queue is empty.
 * @param queue cino-queue
 * @return  Returns `true` if the cino-queue is empty, otherwise returns `false`.
 */
bool queue_is_empty(const queue_t *queue);

/**
 * @brief   Get the number of elements in the cino-queue.
 * @param queue cino-queue
 * @return  Returns the number of elements in the cino-queue.
 */
size_t queue_size(const queue_t *queue);

/**
 * @brief   Clear all the elments in the cino-queue.
 * @param queue cino-queue
 * @return  Returns the modified cino-queue.
 */
queue_t *queue_clear(queue_t *queue);

/**
 * @brief   Enqueue an elment to the cino-queue.
 * @param queue cino-queue
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-queue.
 */
queue_t *queue_enqueue(queue_t *queue, T data);

/**
 * @brief   Dequeue an elment from the cino-queue.
 * @param queue cino-queue
 * @return  For primitive cino-queue, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T queue_dequeue(queue_t *queue);

/**
 * @brief   Get the front elment in the cino-queue.
 * @param queue cino-queue
 * @return  For primitive cino-queue, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T queue_get_front(queue_t *queue);

#endif