#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "utils.h"

typedef struct deque_t deque_t;

deque_t *deque_create(destroy_t destroy);
void deque_destroy(deque_t *deque);
bool deque_is_empty(const deque_t *deque);
size_t deque_size(const deque_t *deque);
deque_t *deque_clear(deque_t *deque);
deque_t *deque_push_front(deque_t *deque, T elem);
deque_t *deque_push_back(deque_t *deque, T elem);
T deque_pop_front(deque_t *deque);
T deque_pop_back(deque_t *deque);
T deque_get_front(const deque_t *deque);
T deque_get_back(const deque_t *deque);

#endif
