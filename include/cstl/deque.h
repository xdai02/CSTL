#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "utils.h"

typedef struct deque_t deque_t;

/**
 * @brief Create a deque_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created deque_t object if successful, otherwise return NULL.
 */
deque_t *deque_create(destroy_t destroy);

/**
 * @brief Destroy a deque_t object.
 * @param deque The deque_t object.
 */
void deque_destroy(deque_t *deque);

/**
 * @brief Determine whether a deque_t object is empty.
 * @param deque The deque_t object.
 * @return Returns true if the deque_t object is empty, otherwise returns false.
 */
bool deque_is_empty(const deque_t *deque);

/**
 * @brief Get the size of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the size of the deque_t object.
 */
size_t deque_size(const deque_t *deque);

/**
 * @brief Clear a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_clear(deque_t *deque);

/**
 * @brief Push an element to the front of a deque_t object.
 * @param deque The deque_t object.
 * @param elem The element.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_push_front(deque_t *deque, T elem);

/**
 * @brief Push an element to the back of a deque_t object.
 * @param deque The deque_t object.
 * @param elem The element.
 * @return Returns the modified deque_t object.
 */
deque_t *deque_push_back(deque_t *deque, T elem);

/**
 * @brief Pop an element from the front of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the popped element.
 */
T deque_pop_front(deque_t *deque);

/**
 * @brief Pop an element from the back of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the popped element.
 */
T deque_pop_back(deque_t *deque);

/**
 * @brief Get the front element of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the front element.
 */
T deque_get_front(const deque_t *deque);

/**
 * @brief Get the back element of a deque_t object.
 * @param deque The deque_t object.
 * @return Returns the front element.
 */
T deque_get_back(const deque_t *deque);

#endif
