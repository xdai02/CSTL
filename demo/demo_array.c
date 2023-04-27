#include <stdio.h>
#include "coop.h"

// Callback function for printing an integer
void Integer_print(void *data) {
    Integer *integer = (Integer *)data;
    printf("%d ", Integer_valueOf(integer));
}

int main() {
    // Create an array of integers
    array_t *array = array_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Create an integer object
        Integer *integer = Integer_new(i);
        // Add the integer object to the array
        array_append(array, integer);
    }

    // Print the array
    array_foreach(array, Integer_print);
    printf("\n");

    // Destroy the array
    array_destroy(array);

    return 0;
}