#ifndef _NUMERIC_H_
#define _NUMERIC_H_

#include "types.h"

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

#endif
