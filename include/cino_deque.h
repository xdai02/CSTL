/**************************************************
 * Module   :   cino_deque
 * Function :   Operations on cino-deque
 * Category :
 *              - deque_t
 **************************************************/

#ifndef _CINO_DEQUE_H_
#define _CINO_DEQUE_H_

#include "cino_utils.h"

/****************************************
 *               deque_t
 ****************************************/

typedef struct deque_t deque_t;

/**
 * @brief   Create cino-deque.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-deque. Set to `NULL` if it is a primitive cino-deque.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-deque. Set to `NULL` if it is a primitive cino-deque.
 * @return  Returns the pointer to cino-deque, or `NULL` if creation failed.
 */
deque_t *deque_create(data_type_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-deque.
 * @param deque cino-deque
 */
void deque_destroy(deque_t *deque);

/**
 * @brief   Determine if the cino-deque is empty.
 * @param deque cino-deque
 * @return  Returns `true` if the cino-deque is empty, otherwise returns `false`.
 */
bool deque_is_empty(const deque_t *deque);

/**
 * @brief   Get the number of elements in the cino-deque.
 * @param deque cino-deque
 * @return  Returns the number of elements in the cino-deque.
 */
size_t deque_size(const deque_t *deque);

/**
 * @brief   Clear all the elments in the cino-deque.
 * @param deque cino-deque
 * @return  Returns the modified cino-deque.
 */
deque_t *deque_clear(deque_t *deque);

/**
 * @brief   Inserts the specified element at the beginning of the cino-deque.
 * @param deque cino-deque
 * @param data  For primitive data, a wrapper type of that primitive is needed
 * @return  Returns the modified cino-deque.
 */
deque_t *deque_push_front(deque_t *deque, T data);

/**
 * @brief   Removes the first element from the cino-deque.
 * @param deque cino-deque
 * @return  For primitive cino-deque, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T deque_pop_front(deque_t *deque);

/**
 * @brief   Get the first element in the cino-deque.
 * @param deque cino-deque
 * @return  For primitive cino-deque, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T deque_get_front(deque_t *deque);

/**
 * @brief   Inserts the specified element at the end of the cino-deque.
 * @param deque cino-deque
 * @param data  For primitive data, a wrapper type of that primitive is needed
 * @return  Returns the modified cino-deque.
 */
deque_t *deque_push_back(deque_t *deque, T data);

/**
 * @brief   Removes the last element from the cino-deque.
 * @param deque cino-deque
 * @return  For primitive cino-deque, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T deque_pop_back(deque_t *deque);

/**
 * @brief   Get the last element in the cino-deque.
 * @param deque cino-deque
 * @return  For primitive cino-deque, this function returns a wrapper type of the last
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T deque_get_back(deque_t *deque);

#endif