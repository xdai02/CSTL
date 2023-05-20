#include <stdio.h>
#include "coop.h"

void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

int main() {
    heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        Integer *integer = Integer_new(randint(0, 100));
        heap_push(heap, integer);
    }

    while (!heap_is_empty(heap)) {
        Integer *integer = heap_pop(heap);
        Integer_print(integer);
        Integer_delete(integer);
    }
    printf("\n");

    heap_delete(heap);

    return 0;
}
