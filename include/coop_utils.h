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

#define arr_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

#define Exception(msg)                                                           \
    do {                                                                         \
        fprintf(stderr, "%s:%d %s(): %s.\n", __FILE__, __LINE__, __func__, msg); \
        exit(EXIT_FAILURE);                                                      \
    } while (0)

bool float_equal(float f1, float f2);
bool double_equal(double d1, double d2);
bool long_double_equal(long double ld1, long double ld2);

#endif