#include "cino_stack.h"
#include "cino_list.h"

/****************************************
 *               stack_t
 ****************************************/

typedef enum data_type_t {
    DATA_TYPE_INT,
    DATA_TYPE_DOUBLE,
    DATA_TYPE_CHAR,
    DATA_TYPE_T,
} data_type_t;

typedef struct stack_t {
    list_t *list;
    data_type_t data_type;
    size_t size;
    compare_t compare;
    destroy_t destroy;
} array_t;

/**
 * @brief   Determine if the data type is supported by cino-stack.
 * @param data_type data type
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - char
 *                      - T (generic)
 * @return  Returns the `true` if it is valid, otherwise returns `false`.
 */
static bool is_valid_data_type(const str_t data_type) {
    return_value_if_fail(data_type != NULL, false);

    const str_t data_types[] = {
        "int",
        "double",
        "char",
        "T",  // generic
    };

    int data_types_len = arr_len(data_types);
    for (int i = 0; i < data_types_len; i++) {
        if (str_equal(data_types[i], data_type)) {
            return true;
        }
    }
    return false;
}

/**
 * @brief   Specify the rules for comparing two int values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_int(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_int_t *wrapper1 = (wrapper_int_t *)data1;
    wrapper_int_t *wrapper2 = (wrapper_int_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the rules for comparing two double values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_double(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_double_t *wrapper1 = (wrapper_double_t *)data1;
    wrapper_double_t *wrapper2 = (wrapper_double_t *)data2;
    if (double_equal(wrapper1->data, wrapper2->data)) {
        return 0;
    }
    return wrapper1->data > wrapper2->data ? 1 : -1;
}

/**
 * @brief   Specify the rules for comparing two int values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_char(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_char_t *wrapper1 = (wrapper_char_t *)data1;
    wrapper_char_t *wrapper2 = (wrapper_char_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the default rules for comparing two values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
static int compare_default(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    return (byte_t *)data1 - (byte_t *)data2;
}

/**
 * @brief   Specify the rules for destroying a single int element.
 * @param data  pointer to the element
 */
static void destroy_int(T data) {
    return_if_fail(data != NULL);
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    unwrap_int(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single double element.
 * @param data  pointer to the element
 */
static void destroy_double(T data) {
    return_if_fail(data != NULL);
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    unwrap_double(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single char element.
 * @param data  pointer to the element
 */
static void destroy_char(T data) {
    return_if_fail(data != NULL);
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    unwrap_char(wrapper);
}

/**
 * @brief   Specify the rules for destroying a single element.
 * @param data  pointer to the element
 */
static void destroy_default(T data) {
    return;
}

/**
 * @brief   Create cino-stack.
 * @param data_type data type of each element
 *                  valid data type includes:
 *                      - int
 *                      - double
 *                      - char
 *                      - T (generic)
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-stack. Set to `NULL` if it is a primitive cino-stack.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-stack. Set to `NULL` if it is a primitive cino-stack.
 * @return  Returns the pointer to cino-stack, or `NULL` if creation failed.
 */
stack_t *stack_create(const str_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_data_type(data_type), NULL);

    stack_t *stack = (stack_t *)calloc(1, sizeof(stack_t));
    return_value_if_fail(stack != NULL, NULL);

    stack->list = list_create(data_type, compare, destroy);
    call_and_return_value_if_fail(stack->list != NULL, free(stack), NULL);

    stack->size = 0;

    if (str_equal(data_type, "int")) {
        stack->data_type = DATA_TYPE_INT;
        stack->compare = compare_int;
        stack->destroy = destroy_int;
    } else if (str_equal(data_type, "double")) {
        stack->data_type = DATA_TYPE_DOUBLE;
        stack->compare = compare_double;
        stack->destroy = destroy_double;
    } else if (str_equal(data_type, "char")) {
        stack->data_type = DATA_TYPE_CHAR;
        stack->compare = compare_char;
        stack->destroy = destroy_char;
    } else if (str_equal(data_type, "T")) {
        stack->data_type = DATA_TYPE_T;
        stack->compare = compare ? compare : compare_default;
        stack->destroy = destroy ? destroy : destroy_default;
    }

    return stack;
}

/**
 * @brief   Destroy cino-stack.
 * @param stack cino-stack
 */
void stack_destroy(stack_t *stack) {
    return_if_fail(stack != NULL);

    stack_clear(stack);

    stack->compare = NULL;
    stack->destroy = NULL;

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
 * @brief   Pop an elment from the cino-stack.
 * @param stack cino-stack
 * @return  For primitive cino-stack, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T stack_peek(stack_t *stack) {
    return_value_if_fail(stack != NULL && stack->size > 0, NULL);
    return list_get_front(stack->list);
}