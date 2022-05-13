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
 * @brief   Specify the rules for comparing two wrapper_int_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_int(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_int_t *wrapper1 = (wrapper_int_t *)data1;
    wrapper_int_t *wrapper2 = (wrapper_int_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the rules for destroying a single wrapper_int_t element.
 * @param data  pointer to the element
 */
void destroy_int(T data) {
    return_if_fail(data != NULL);
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    unwrap_int(wrapper);
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
 * @brief   Specify the rules for comparing two wrapper_double_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_double(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_double_t *wrapper1 = (wrapper_double_t *)data1;
    wrapper_double_t *wrapper2 = (wrapper_double_t *)data2;
    if (double_equal(wrapper1->data, wrapper2->data)) {
        return 0;
    }
    return wrapper1->data > wrapper2->data ? 1 : -1;
}

/**
 * @brief   Specify the rules for destroying a single wrapper_double_t element.
 * @param data  pointer to the element
 */
void destroy_double(T data) {
    return_if_fail(data != NULL);
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    unwrap_double(wrapper);
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

/**
 * @brief   Specify the rules for comparing two wrapper_char_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_char(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    wrapper_char_t *wrapper1 = (wrapper_char_t *)data1;
    wrapper_char_t *wrapper2 = (wrapper_char_t *)data2;
    return wrapper1->data - wrapper2->data;
}

/**
 * @brief   Specify the rules for destroying a single wrapper_char_t element.
 * @param data  pointer to the element
 */
void destroy_char(T data) {
    return_if_fail(data != NULL);
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    unwrap_char(wrapper);
}

/**
 * @brief   Specify the default rule for comparing two values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_default(const T data1, const T data2) {
    return_value_if_fail(data1 != NULL && data2 != NULL, STATUS_BAD_PARAMETERS);
    return (byte_t *)data1 - (byte_t *)data2;
}

/**
 * @brief   Specify the default rule for destroying a element.
 * @param data  pointer to the element
 */
void destroy_default(T data) {
    return;
}