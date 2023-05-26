#ifndef _STACK_H_
#define _STACK_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"

typedef struct stack_t stack_t;

/**
 * @brief Create a stack_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created stack_t object if successful, otherwise return NULL.
 */
stack_t *stack_new(destroy_t destroy);

/**
 * @brief Destroy a stack_t object.
 * @param stack The stack_t object.
 */
void stack_delete(stack_t *stack);

/**
 * @brief Determine whether a stack_t object is empty.
 * @param stack The stack_t object.
 * @return Returns true if the stack_t object is empty, otherwise returns false.
 */
bool stack_is_empty(const stack_t *stack);

/**
 * @brief Get the size of a stack_t object.
 * @param stack The stack_t object.
 * @return Returns the size of the stack_t object.
 */
size_t stack_size(const stack_t *stack);

/**
 * @brief Clear a stack_t object.
 * @param stack The stack_t object.
 * @return Returns the modified stack_t object.
 */
stack_t *stack_clear(stack_t *stack);

/**
 * @brief Push an element into the stack_t object.
 * @param stack The stack_t object.
 * @param elem The element.
 * @return Returns the modified stack_t object.
 */
stack_t *stack_push(stack_t *stack, T elem);

/**
 * @brief Pop an element from the stack_t object.
 * @param stack The stack_t object.
 * @return Returns the popped element.
 * @note Caller MUST free the returned element (if applicable).
 */
T stack_pop(stack_t *stack);

/**
 * @brief Get the top element of the stack_t object.
 * @param stack The stack_t object.
 * @return Returns the top element.
 */
T stack_peek(const stack_t *stack);

#endif
