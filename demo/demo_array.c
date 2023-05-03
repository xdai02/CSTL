#include <stdio.h>
#include "coop.h"

// Callback function for printing an integer
void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

// Callback function for tripling an integer
void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

int main() {
    array_t *array = array_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        array_append(array, Integer_new(i));
    }

    // Print the array
    array_foreach(array, Integer_print);
    printf("\n");

    // Triple the integers in the array
    array_foreach(array, Integer_triple);

    array_foreach(array, Integer_print);
    printf("\n");

    array_destroy(array);

    return 0;
}
