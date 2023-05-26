#include <stdio.h>
#include "cstl.h"

void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

int main() {
    list_t *list = list_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        list_push_back(list, Integer_new(i));
    }

    list_foreach(list, Integer_print);
    printf("\n");

    list_foreach(list, Integer_triple);

    list_foreach(list, Integer_print);
    printf("\n");

    list_delete(list);

    return 0;
}
