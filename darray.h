#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct darray_t darray_t;

darray_t *darray_init(const char *data_type);
void darray_destroy(darray_t *darray);
int darray_size(darray_t *darray);

#endif