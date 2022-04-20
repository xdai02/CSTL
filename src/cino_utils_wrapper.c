#include "cino_utils_wrapper.h"

/****************************************
 *               Wrapper
 ****************************************/

/**
 * @brief   Get the wrapper type for int
 * @param data  int value
 * @return  Returns the wrapper type for int, or `NULL` if fails.
 */
wrapper_int_t *wrap_int(int data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)calloc(1, sizeof(wrapper_int_t));
    return_value_if_fail(wrapper != NULL, NULL);
    wrapper->data = data;
    return wrapper;
}

/**
 * @brief   Unwrap and free wrapper_int_t.
 * @param wrapper   wrapper_int_t
 * @return  Returns the primitive int data.
 */
int unwrap_int(wrapper_int_t *wrapper) {
    if (!wrapper) {
        LOGGER(ERROR, "Null pointer exception.");
        return STATUS_BAD_PARAMETERS;
    }
    int data = wrapper->data;
    free(wrapper);
    wrapper = NULL;
    return data;
}

/**
 * @brief   Get the wrapper type for double
 * @param data  double value
 * @return  Returns the wrapper type for double, or `NULL` if fails.
 */
wrapper_double_t *wrap_double(double data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)calloc(1, sizeof(wrapper_double_t));
    return_value_if_fail(wrapper != NULL, NULL);
    wrapper->data = data;
    return wrapper;
}

/**
 * @brief   Unwrap and free wrapper_double_t.
 * @param wrapper   wrapper_double_t
 * @return  Returns the primitive double data.
 */
double unwrap_double(wrapper_double_t *wrapper) {
    if (!wrapper) {
        LOGGER(ERROR, "Null pointer exception.");
        return STATUS_BAD_PARAMETERS;
    }
    double data = wrapper->data;
    free(wrapper);
    wrapper = NULL;
    return data;
}

/**
 * @brief   Get the wrapper type for char
 * @param data  char value
 * @return  Returns the wrapper type for char, or `NULL` if fails.
 */
wrapper_char_t *wrap_char(char data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)calloc(1, sizeof(wrapper_char_t));
    return_value_if_fail(wrapper != NULL, NULL);
    wrapper->data = data;
    return wrapper;
}

/**
 * @brief   Unwrap and free wrapper_char_t.
 * @param wrapper   wrapper_char_t
 * @return  Returns the primitive char data.
 */
char unwrap_char(wrapper_char_t *wrapper) {
    if (!wrapper) {
        LOGGER(ERROR, "Null pointer exception.");
        return STATUS_BAD_PARAMETERS;
    }
    char data = wrapper->data;
    free(wrapper);
    wrapper = NULL;
    return data;
}