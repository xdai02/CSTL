#include <stdio.h>
#include "coop.h"

void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

int main() {
    array_t *array = array_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        array_append(array, Integer_new(i));
    }

    array_foreach(array, Integer_print);
    printf("\n");

    array_foreach(array, Integer_triple);

    array_foreach(array, Integer_print);
    printf("\n");

    array_delete(array);

    return 0;
}
