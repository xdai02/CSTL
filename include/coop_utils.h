#ifndef _COOP_UTILS_H_
#define _COOP_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

#define min(x, y) (((x) < (y)) ? (x) : (y))

#define max(x, y) (((x) > (y)) ? (x) : (y))

#define swap(a, b, type) \
    do {                 \
        type temp = (a); \
        (a) = (b);       \
        (b) = temp;      \
    } while (0)

#define Exception(msg)                                                           \
    do {                                                                         \
        fprintf(stderr, "%s:%d %s(): %s.\n", __FILE__, __LINE__, __func__, msg); \
        exit(EXIT_FAILURE);                                                      \
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