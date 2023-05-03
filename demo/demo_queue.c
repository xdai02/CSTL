#include <stdio.h>
#include "coop.h"

int main() {
    queue_t *queue = queue_create(Integer_delete);

    for (int i = 0; i < 10; i++) {
        queue_enqueue(queue, Integer_new(i));
    }

    while (!queue_is_empty(queue)) {
        Integer *integer = queue_dequeue(queue);
        printf("%d ", Integer_get(integer));
        Integer_delete(integer);
    }
    printf("\n");

    queue_destroy(queue);

    return 0;
}