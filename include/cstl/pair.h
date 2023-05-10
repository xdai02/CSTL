#ifndef _PAIR_H_
#define _PAIR_H_

#include "utils/utils.h"

typedef struct pair_t pair_t;

pair_t *pair_new(T key, T value, destroy_t destroy_key, destroy_t destroy_value);

void pair_delete(pair_t *pair);

T pair_get_key(const pair_t *pair);

T pair_get_value(const pair_t *pair);

pair_t *pair_set_key(pair_t *pair, T key);

pair_t *pair_set_value(pair_t *pair, T value);

#endif
