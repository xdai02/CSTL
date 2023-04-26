#ifndef _COOP_ARRAY_H_
#define _COOP_ARRAY_H_

#include "coop_utils.h"

typedef struct array_t array_t;

array_t *array_create(compare_t compare, destroy_t destroy);
void array_destroy(array_t *array);
void array_foreach(array_t *array, visit_t visit);
bool array_is_empty(const array_t *array);
size_t array_size(const array_t *array);
array_t *array_clear(array_t *array);
T array_get(const array_t *array, size_t index);
array_t *array_set(array_t *array, size_t index, T elem);
array_t *array_append(array_t *array, T elem);
array_t *array_insert(array_t *array, size_t index, T elem);
T array_remove(array_t *array, size_t index);
size_t array_index_of(const array_t *array, T elem);
bool array_contains(const array_t *array, T elem);
size_t array_count(const array_t *array, T elem);
array_t *array_reverse(array_t *array);
array_t *array_sort(array_t *array);

#endif
