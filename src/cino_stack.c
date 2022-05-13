#include "cino_stack.h"
#include "cino_list.h"

/****************************************
 *               stack_t
 ****************************************/

typedef struct stack_t {
    list_t *list;
    data_type_t data_type;
    size_t size;
} stack_t;

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
stack_t *stack_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    stack_t *stack = (stack_t *)calloc(1, sizeof(stack_t));
    return_value_if_fail(stack != NULL, NULL);

    stack->list = list_create(data_type, compare, destroy);
    call_and_return_value_if_fail(stack->list != NULL, free(stack), NULL);

    stack->size = 0;
    stack->data_type = data_type;

    return stack;
}

/**
 * @brief   Destroy cino-stack.
 * @param stack cino-stack
 */
void stack_destroy(stack_t *stack) {
    return_if_fail(stack != NULL);

    stack_clear(stack);

    if (stack->list) {
        list_destroy(stack->list);
        stack->list = NULL;
    }

    if (stack) {
        free(stack);
        stack = NULL;
    }
}

/**
 * @brief   Determine if the cino-stack is empty.
 * @param stack cino-stack
 * @return  Returns `true` if the cino-stack is empty, otherwise returns `false`.
 */
bool stack_is_empty(const stack_t *stack) {
    return !stack || stack->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-stack.
 * @param stack cino-stack
 * @return  Returns the number of elements in the cino-stack.
 */
size_t stack_size(const stack_t *stack) {
    return_value_if_fail(stack != NULL, 0);
    return stack->size;
}

/**
 * @brief   Clear all the elments in the cino-stack.
 * @param stack cino-stack
 * @return  Returns the modified cino-stack.
 */
stack_t *stack_clear(stack_t *stack) {
    return_value_if_fail(stack != NULL, NULL);
    list_clear(stack->list);
    stack->size = 0;
    return stack;
}

/**
 * @brief   Push an elment to the cino-stack.
 * @param stack cino-stack
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-stack.
 */
stack_t *stack_push(stack_t *stack, T data) {
    return_value_if_fail(stack != NULL && data != NULL, stack);
    list_push_front(stack->list, data);
    stack->size++;
    return stack;
}

/**
 * @brief   Pop an elment from the cino-stack.
 * @param stack cino-stack
 * @return  For primitive cino-stack, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T stack_pop(stack_t *stack) {
    return_value_if_fail(stack != NULL && stack->size > 0, NULL);
    T data = list_pop_front(stack->list);
    stack->size--;
    return data;
}

/**
 * @brief   Peek the top elment in the cino-stack.
 * @param stack cino-stack
 * @return  For primitive cino-stack, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T stack_peek(stack_t *stack) {
    return_value_if_fail(stack != NULL && stack->size > 0, NULL);
    return list_get_front(stack->list);
}