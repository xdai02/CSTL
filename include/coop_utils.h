#ifndef _COOP_UTILS_H_
#define _COOP_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

#define exit_if_fail(expr)  \
    if (!(expr)) {          \
        exit(EXIT_FAILURE); \
    }

typedef void *T;

#define bool int
#define true 1
#define false 0

#define min(x, y) (((x) < (y)) ? (x) : (y))

#define max(x, y) (((x) > (y)) ? (x) : (y))

#define swap(a, b, type) \
    do {                 \
        type temp = (a); \
        (a) = (b);       \
        (b) = temp;      \
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

typedef int (*compare_t)(const void *data1, const void *data2);

typedef void (*destroy_t)(void *data);

typedef void (*visit_t)(void *data);

typedef bool (*match_t)(const void *data);

#endif