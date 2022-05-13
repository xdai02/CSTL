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
 * @brief   Specify the rules for comparing two wrapper_int_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_int(const T data1, const T data2);

/**
 * @brief   Specify the rules for destroying a single wrapper_int_t element.
 * @param data  pointer to the element
 */
void destroy_int(T data);

/**
 * @brief   Wrapper type for double.
 */
typedef struct wrapper_double_t {
    double data;
} wrapper_double_t;

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
 * @brief   Specify the rules for comparing two wrapper_double_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_double(const T data1, const T data2);

/**
 * @brief   Specify the rules for destroying a single wrapper_double_t element.
 * @param data  pointer to the element
 */
void destroy_double(T data);

/**
 * @brief   Wrapper type for char.
 */
typedef struct wrapper_char_t {
    char data;
} wrapper_char_t;

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

/**
 * @brief   Specify the rules for comparing two wrapper_char_t values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_char(const T data1, const T data2);

/**
 * @brief   Specify the rules for destroying a single wrapper_char_t element.
 * @param data  pointer to the element
 */
void destroy_char(T data);

/**
 * @brief   Specify the default rule for comparing two values.
 * @param data1 pointer to the first value
 * @param data2 pointer to the second value
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
int compare_default(const T data1, const T data2);

/**
 * @brief   Specify the default rule for destroying a element.
 * @param data  pointer to the element
 */
void destroy_default(T data);

#endif