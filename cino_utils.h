#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Determine if `expr` is true, return if fails
 */
#define return_if_fail(expr) \
    if (!(expr))             \
    {                        \
        return;              \
    }

/**
 * @brief Determine if `expr` is true, return `ret` if fails
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr))                        \
    {                                   \
        return (ret);                   \
    }

/**
 * @brief Determine if `expr` is true, call `func` and return if fails
 */
#define call_and_return_if_fail(expr, func, ret) \
    if (!(expr))                                 \
    {                                            \
        func;                                    \
        return;                                  \
    }

/**
 * @brief Determine if `expr` is true, call `func` and return `ret` if fails
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr))                                       \
    {                                                  \
        func;                                          \
        return (ret);                                  \
    }

/**
 * @brief Get the length of a C array
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

#endif