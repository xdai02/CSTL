#include <stdio.h>
#include "cstl.h"

int main() {
    queue_t *queue = queue_new(Integer_delete);

    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, Integer_new(i));
    }

    while (!queue_is_empty(queue)) {
        Integer *integer = queue_dequeue(queue);
        printf("%d ", Integer_get(integer));
        Integer_delete(integer);
    }
    printf("\n");

    queue_delete(queue);

    return 0;
}