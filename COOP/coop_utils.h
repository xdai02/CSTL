#ifndef _COOP_UTILS_H_
#define _COOP_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

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

void *malloc_s(size_t size);
void *calloc_s(size_t count, size_t size);
void *realloc_s(void *ptr, size_t new_size);

#endif