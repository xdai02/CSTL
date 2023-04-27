#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Returns from the current function immediately if the given expression `expr` is false.
 *        This is useful when you want to ensure that a certain condition is met
 *        before proceeding with the rest of the function.
 * @param expr The expression to be evaluated.
 */
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

/**
 * @brief Returns the specific value from the current function immediately if the given expression `expr` is false.
 *        This is useful when you want to ensure that a certain condition is met
 *        before proceeding with the rest of the function.
 * @param expr The expression to be evaluated.
 * @param ret The value to be returned.
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

/**
 * @brief Terminates the program immediately with the `EXIT_FAILURE` status if the given expression `expr` is false.
 *        This is useful when you want to ensure that a certain condition is met
 *        before proceeding with the rest of the function.
 * @param expr The expression to be evaluated.
 */
#define exit_if_fail(expr)  \
    if (!(expr)) {          \
        exit(EXIT_FAILURE); \
    }

#endif
