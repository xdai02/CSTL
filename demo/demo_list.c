#include <stdio.h>
#include "coop.h"

// Callback function for printing an integer
void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_valueOf(integer));
}

// Callback function for tripling an integer
void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_valueOf(integer) * 3);
}

int main() {
    // Create a list of integers
    list_t *list = list_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Create an integer object
        Integer *integer = Integer_new(i);
        // Add the integer object to the list
        list_push_back(list, integer);
    }

    // Print the list
    list_foreach(list, Integer_print);
    printf("\n");

    // Triple the integers in the list
    list_foreach(list, Integer_triple);

    // Print the list
    list_foreach(list, Integer_print);
    printf("\n");

    // Destroy the list
    list_destroy(list);

    return 0;
}
