/**************************************************
 * Module   :   cino_utils_basic
 * Function :   Basic utilities and operations
 * Category :
 *              - Validity Check
 *              - Type Definition
 *              - Numeric Operation
 *              - Array Operation
 *              - Type Conversion
 **************************************************/

#ifndef _CINO_UTILS_BASIC_H_
#define _CINO_UTILS_BASIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/****************************************
 *            Validity Check
 ****************************************/

/**
 * @brief   Determine if the specified expression is true, return if it failed.
 */
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

/**
 * @brief   Determine if the specified expression is true, return the given value if
 *          it failed.
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

/**
 * @brief   Determine if the specified expression is true, call the specified function
 *          and return if it failed.
 */
#define call_and_return_if_fail(expr, func) \
    if (!(expr)) {                          \
        func;                               \
        return;                             \
    }

/**
 * @brief   Determine if the specified expression is true, call the specified function
 *          and return the given value if it failed.
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr)) {                                     \
        func;                                          \
        return (ret);                                  \
    }

/****************************************
 *            Type Definition
 ****************************************/

#define str_t char*  // str_t == char *

typedef char byte_t;  // byte_t == char

#define T void*  // T == void *

/****************************************
 *          Numeric Operation
 ****************************************/

/**
 * @brief   Returns the smaller of two values.
 */
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * @brief   Returns the greater of two values.
 */
#define max(x, y) (((x) > (y)) ? (x) : (y))

/**
 * @brief   Returns the negation of the value.
 */
#define negate(x) (0 - x)

/**
 * @brief   Swap two values of specified type.
 */
#define swap(x, y, type) \
    do {                 \
        type temp = x;   \
        x = y;           \
        y = temp;        \
    } while (0)

/**
 * @brief   Determine if two double values are equal.
 * @param x value 1
 * @param y value 2
 * @return  Returns true if two double values are equal, otherwise return false.
 */
bool double_equal(double x, double y);

/****************************************
 *          Array Operation
 ****************************************/

/**
 * @brief   Returns the number of elements in C array.
 */
#define arr_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

#define arr_reverse(arr, type)          \
    do {                                \
        int i = 0;                      \
        int j = arr_len(arr) - 1;       \
        while (i < j) {                 \
            swap(arr[i], arr[j], type); \
            i++;                        \
            j++;                        \
        }                               \
    } while (0)

/****************************************
 *            Type Conversion
 ****************************************/

/**
 * @brief   Convert string to boolean.
 * @param str   string
 * @return  Returns `false` if:
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. str_equal_ignore_case(str, "false")
 *              4. a string of zeroes
 *          Otherwise returns `true`.
 */
bool str_to_bool(const str_t str);

/**
 * @brief   Convert boolean to string.
 * @param val   boolean value
 * @return  Returns "true" if the boolean value is `true`, otherwise returns "false".
 */
const str_t bool_to_str(bool val);

/**
 * @brief   Convert string to char.
 * @param str   string
 * @return  Returns the first character of the string, or '\0' if string is NULL.
 */
char str_to_char(const str_t str);

/**
 * @brief   Convert char to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param c         char
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return  Returns the string after conversion.
 */
str_t char_to_str(char c, str_t str, size_t str_size);

/**
 * @brief   Convert string to int.
 * @param str   string
 * @return  Returns 0 if str == NULL, otherwise returns the result given by `atoi()`.
 */
int str_to_int(const str_t str);

/**
 * @brief   Convert int to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param val       int value
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return   Returns the string after conversion.
 */
str_t int_to_str(int val, str_t str, size_t str_size);

/**
 * @brief   Convert string to double.
 * @param str   string
 * @return  Returns 0.0 if str == NULL，otherwise returns the result given `atof()`.
 */
double str_to_double(const str_t str);

/**
 * @brief   Convert double to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param val           double value
 * @param precision     number of decimal places when rounding (default=2, max=16)
 * @param str           string used to store the result after conversion
 * @param str_size      sizeof(str)
 * @return  Returns the string after conversion.
 */
str_t double_to_str(double val, int precision, str_t str, size_t str_size);

#endif