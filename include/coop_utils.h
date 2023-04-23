#ifndef _COOP_UTILS_H_
#define _COOP_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Boolean type for compatibility with standards before C99.
 */
typedef int bool;
#define true 1
#define false 0

/**
 * @brief A generic data type representing a pointer to any data type.
 *        It is an alias for void *.
 */
#define T void*

/**
 * @brief A generic function pointer type for comparing two data items.
 * @param data1 The first data item to be compared.
 * @param data2 The second data item to be compared.
 * @return Returns a negative integer if data1 < data2, 0 if data1 == data2, or a positive integer if data1 > data2.
 */
typedef int (*compare_t)(const T data1, const T data2);

/**
 * @brief A generic function pointer type for destroying a data item.
 * @param data The data item to be destroyed.
 */
typedef void (*destroy_t)(T data);

/**
 * @brief A generic function pointer type for visiting a data item.
 * @param data The data item to be visited.
 */
typedef void (*visit_t)(T data);

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

/**
 * @brief Returns the minimum of two numbers.
 * @param x The first number to be compared.
 * @param y The second number to be compared.
 * @return Returns the minimum of x and y.
 */
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * @brief Returns the maximum of two numbers.
 * @param x The first number to be compared.
 * @param y The second number to be compared.
 * @return Returns the maximum of x and y.
 */
#define max(x, y) (((x) > (y)) ? (x) : (y))

/**
 * @brief Swaps the values of two variables with the given type.
 * @param x The first variable to be swapped.
 * @param y The second variable to be swapped.
 * @param type The type of the variables to be swapped.
 */
#define swap(x, y, type) \
    do {                 \
        type temp = (x); \
        (x) = (y);       \
        (y) = temp;      \
    } while (0)

/**
 * @brief Compares two floating point numbers for equality within a certain tolerance.
 * @param f1 The first float number to be compared.
 * @param f2 The second float number to be compared.
 * @return Returns true if the absolute difference between f1 and f2 is less than
 *         FLT_EPSILON, false otherwise.
 */
bool float_equal(float f1, float f2);

/**
 * @brief Compares two double precision floating point numbers for equality within a certain tolerance.
 * @param d1 The first double number to be compared.
 * @param d2 The second double number to be compared.
 * @return Returns true if the absolute difference between d1 and d2 is less than
 *         DBL_EPSILON, false otherwise.
 */
bool double_equal(double d1, double d2);

/**
 * @brief Compares two long double precision floating point numbers for equality within a certain tolerance.
 * @param ld1 The first long double number to be compared.
 * @param ld2 The second long double number to be compared.
 * @return Returns true if the absolute difference between ld1 and ld2 is less than
 *         LDBL_EPSILON, false otherwise.
 */
bool long_double_equal(long double ld1, long double ld2);

#endif