#ifndef _CINO_STRING_H_
#define _CINO_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cino_utils.h"

typedef struct string_t string_t;

string_t *string_create(const char *str);
void string_destroy(string_t *string);
const char *string_get(string_t *string);
int string_length(string_t *string);
void string_clear(string_t *string);

#endif