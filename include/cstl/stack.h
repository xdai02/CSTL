#ifndef _STACK_H_
#define _STACK_H_

#include "utils.h"

typedef struct stack_t stack_t;

stack_t *stack_create(destroy_t destroy);
void stack_destroy(stack_t *stack);
bool stack_is_empty(const stack_t *stack);
size_t stack_size(const stack_t *stack);
stack_t *stack_clear(stack_t *stack);
stack_t *stack_push(stack_t *stack, T elem);
T stack_pop(stack_t *stack);
T stack_peek(const stack_t *stack);

#endif
