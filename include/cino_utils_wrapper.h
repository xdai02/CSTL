/**************************************************
 * Module   :   cino_utils_wrapper
 * Function :   Wrapper type for primitives
 * Category :
 *              - Wrapper
 **************************************************/

#ifndef _CINO_UTILS_WRAPPER_H_
#define _CINO_UTILS_WRAPPER_H_

#include "cino_utils_basic.h"
#include "cino_utils_logger.h"

/****************************************
 *               Wrapper
 ****************************************/

/**
 * @brief   Wrapper type for int.
 */
typedef struct wrapper_int_t {
    int data;
} wrapper_int_t;

/**
 * @brief   Wrapper type for double.
 */
typedef struct wrapper_double_t {
    double data;
} wrapper_double_t;

/**
 * @brief   Wrapper type for char.
 */
typedef struct wrapper_char_t {
    char data;
} wrapper_char_t;

/**
 * @brief   Get the wrapper type for int
 * @param data  int value
 * @return  Returns the wrapper type for int, or `NULL` if fails.
 */
wrapper_int_t *wrap_int(int data);

/**
 * @brief   Unwrap and free wrapper_int_t.
 * @param wrapper   wrapper_int_t
 * @return  Returns the primitive int data.
 */
int unwrap_int(wrapper_int_t *wrapper);

/**
 * @brief   Get the wrapper type for double
 * @param data  double value
 * @return  Returns the wrapper type for double, or `NULL` if fails.
 */
wrapper_double_t *wrap_double(double data);

/**
 * @brief   Unwrap and free wrapper_double_t.
 * @param wrapper   wrapper_double_t
 * @return  Returns the primitive double data.
 */
double unwrap_double(wrapper_double_t *wrapper);

/**
 * @brief   Get the wrapper type for char
 * @param data  char value
 * @return  Returns the wrapper type for char, or `NULL` if fails.
 */
wrapper_char_t *wrap_char(char data);

/**
 * @brief   Unwrap and free wrapper_char_t.
 * @param wrapper   wrapper_char_t
 * @return  Returns the primitive char data.
 */
char unwrap_char(wrapper_char_t *wrapper);

#endif