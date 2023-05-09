#include "cstl/stack.h"
#include "cstl/array.h"

struct stack_t {
    array_t *array;
};

/**
 * @brief Create a stack_t object.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created stack_t object if successful, otherwise return NULL.
 */
stack_t *stack_new(destroy_t destroy) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    return_value_if_fail(stack != NULL, NULL);

    stack->array = array_new(NULL, destroy);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }

    return stack;
}

/**
 * @brief Destroy a stack_t object.
 * @param stack The stack_t object.
 */
void stack_delete(stack_t *stack) {
    return_if_fail(stack != NULL);
    array_delete(stack->array);
    free(stack);
}

/**
 * @brief Determine whether a stack_t object is empty.
 * @param stack The stack_t object.
 * @return Returns true if the stack_t object is empty, otherwise returns false.
 */
bool stack_is_empty(const stack_t *stack) {
    return_value_if_fail(stack != NULL, true);
    return array_is_empty(stack->array);
}

/**
 * @brief Get the size of a stack_t object.
 * @param stack The stack_t object.
 * @return Returns the size of the stack_t object.
 */
size_t stack_size(const stack_t *stack) {
    return_value_if_fail(stack != NULL, 0);
    return array_size(stack->array);
}

/**
 * @brief Clear a stack_t object.
 * @param stack The stack_t object.
 * @return Returns the modified stack_t object.
 */
stack_t *stack_clear(stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    array_clear(stack->array);
    return stack;
}

/**
 * @brief Push an element onto the stack_t object.
 * @param stack The stack_t object.
 * @param elem The element.
 * @return Returns the modified stack_t object.
 */
stack_t *stack_push(stack_t *stack, T elem) {
    return_value_if_fail(stack != NULL, NULL);
    array_append(stack->array, elem);
    return stack;
}

/**
 * @brief Pop an element from the stack_t object.
 * @param stack The stack_t object.
 * @return Returns the popped element.
 */
T stack_pop(stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    return array_remove(stack->array, array_size(stack->array) - 1);
}

/**
 * @brief Get the top element of the stack_t object.
 * @param stack The stack_t object.
 * @return Returns the top element.
 */
T stack_peek(const stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    return array_get(stack->array, array_size(stack->array) - 1);
}
