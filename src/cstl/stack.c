#include "stack.h"
#include "array.h"
#include "utils.h"

struct stack_t {
    array_t *array;
};

stack_t *stack_create(destroy_t destroy) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    return_value_if_fail(stack != NULL, NULL);

    stack->array = array_create(NULL, destroy);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }

    return stack;
}

void stack_destroy(stack_t *stack) {
    return_if_fail(stack != NULL);
    array_destroy(stack->array);
    free(stack);
}

bool stack_is_empty(const stack_t *stack) {
    return_value_if_fail(stack != NULL, true);
    return array_is_empty(stack->array);
}

size_t stack_size(const stack_t *stack) {
    return_value_if_fail(stack != NULL, 0);
    return array_size(stack->array);
}

stack_t *stack_clear(stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    array_clear(stack->array);
    return stack;
}

stack_t *stack_push(stack_t *stack, T elem) {
    return_value_if_fail(stack != NULL, NULL);
    array_append(stack->array, elem);
    return stack;
}

T stack_pop(stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    return array_remove(stack->array, array_size(stack->array) - 1);
}

T stack_peek(const stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    return array_get(stack->array, array_size(stack->array) - 1);
}
