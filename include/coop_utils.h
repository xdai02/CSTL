#ifndef _COOP_UTILS_H_
#define _COOP_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

#define swap(a, b, type) \
    do {                 \
        type tmp = (a);  \
        (a) = (b);       \
        (b) = tmp;       \
    } while (0)

#define Exception(msg)                                                          \
    do {                                                                        \
        fprintf(stderr, "%s:%d %s(): %s.\n", __FILE__, __LINE__, __func__, msg); \
        exit(EXIT_FAILURE);                                                     \
    } while (0)

#endif