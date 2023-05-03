#include <stdio.h>
#include "coop.h"

int main() {
    stack_t *stack = stack_create(Integer_delete);

    for (int i = 0; i < 10; i++) {
        stack_push(stack, Integer_new(i));
    }

    while (!stack_is_empty(stack)) {
        Integer *integer = stack_pop(stack);
        printf("%d ", Integer_get(integer));
        Integer_delete(integer);
    }
    printf("\n");

    stack_destroy(stack);

    return 0;
}