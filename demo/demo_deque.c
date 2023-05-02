#include <stdio.h>
#include "coop.h"

int main() {
    deque_t *deque = deque_create(Integer_delete);

    // Create a deque = [4, 3, 2, 1, 0, 0, 1, 2, 3, 4]
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, Integer_new(i));
        deque_push_back(deque, Integer_new(i));
    }

    Integer *integer;
    while (!deque_is_empty(deque)) {
        integer = deque_pop_front(deque);
        printf("%d ", Integer_valueOf(integer));
        Integer_delete(integer);

        integer = deque_pop_back(deque);
        printf("%d ", Integer_valueOf(integer));
        Integer_delete(integer);
    }
    printf("\n");

    return 0;
}