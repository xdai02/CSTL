#ifndef _SET_H_
#define _SET_H_

#include "utils.h"
#include "iterator.h"

typedef struct set_t set_t;

set_t *set_create(compare_t compare, destroy_t destroy);
void set_destroy(set_t *set);
bool set_is_empty(const set_t *set);
size_t set_size(const set_t *set);
set_t *set_clear(set_t *set);
bool set_contains(const set_t *set, T elem);
set_t *set_add(set_t *set, T elem);
set_t *set_remove(set_t *set, T elem);

#endif
