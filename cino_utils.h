#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @brief   Determine if `expr` is true, return if fails
 */
#define return_if_fail(expr) \
    if (!(expr))             \
    {                        \
        return;              \
    }

/**
 * @brief   Determine if `expr` is true, return `ret` if fails
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr))                        \
    {                                   \
        return (ret);                   \
    }

/**
 * @brief   Determine if `expr` is true, call `func` and return if fails
 */
#define call_and_return_if_fail(expr, func, ret) \
    if (!(expr))                                 \
    {                                            \
        func;                                    \
        return;                                  \
    }

/**
 * @brief   Determine if `expr` is true, call `func` and return `ret` if fails
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr))                                       \
    {                                                  \
        func;                                          \
        return (ret);                                  \
    }

/**
 * @brief   Get the length of a C array
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

/**
 * @brief   Case insensitive string comparion
 * @param s1    :   string 1
 * @param s2    :   string 2
 * @return  Return `true` if `s1` is the same as `s2` ignoring case, 
 *          otherwise return `false`.
 */
bool equals_ignore_case(const char *s1, const char *s2);

/**
 * @brief   Convert string to boolean
 * @param str   :   string
 * @return  Return `false` if `str` is NULL, or strlen(str) == 0, or 
 *          `str` equals "false" ignoring case, otherwise return `true`.
 */
bool string_to_bool(const char *str);

/**
 * @brief   Convert boolean to string
 * @param val   :   boolean value
 * @return  Return "true" or "false" based on `val`.
 */
const char *bool_to_string(bool val);

#endif