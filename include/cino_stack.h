/**************************************************
 * Module   :   cino_stack
 * Function :   Operations on cino-stack
 * Category :
 *              - stack_t
 **************************************************/

#ifndef _CINO_STACK_H_
#define _CINO_STACK_H_

#include "cino_utils.h"

/****************************************
 *               stack_t
 ****************************************/

typedef struct stack_t stack_t;

/**
 * @brief   Create cino-stack.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T, 
 *                         otherwise a default `compare_default` is applied.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T, 
 *                         otherwise a default `compare_default` is applied.
 * @return  Returns the pointer to cino-stack, or `NULL` if creation failed.
 */
stack_t *stack_create(data_type_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-stack.
 * @param stack cino-stack
 */
void stack_destroy(stack_t *stack);

/**
 * @brief   Determine if the cino-stack is empty.
 * @param stack cino-stack
 * @return  Returns `true` if the cino-stack is empty, otherwise returns `false`.
 */
bool stack_is_empty(const stack_t *stack);

/**
 * @brief   Get the number of elements in the cino-stack.
 * @param stack cino-stack
 * @return  Returns the number of elements in the cino-stack.
 */
size_t stack_size(const stack_t *stack);

/**
 * @brief   Clear all the elments in the cino-stack.
 * @param stack cino-stack
 * @return  Returns the modified cino-stack.
 */
stack_t *stack_clear(stack_t *stack);

/**
 * @brief   Push an elment to the cino-stack.
 * @param stack cino-stack
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-stack.
 */
stack_t *stack_push(stack_t *stack, T data);

/**
 * @brief   Pop an elment from the cino-stack.
 * @param stack cino-stack
 * @return  For primitive cino-stack, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T stack_pop(stack_t *stack);

/**
 * @brief   Peek the top elment in the cino-stack.
 * @param stack cino-stack
 * @return  For primitive cino-stack, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T stack_peek(stack_t *stack);

#endif