#include "Integer.h"

Integer *Integer_new(int value) {
    Integer *integer = (Integer *)malloc(sizeof(Integer));
    if (integer == NULL) {
        Exception("Out of memory exception");
    }
    integer->value = value;
    return integer;
}

int Integer_delete(Integer *integer) {
    if (integer == NULL) {
        Exception("NULL pointer exception");
    }
    int value = integer->value;
    free(integer);
    return value;
}

int Integer_compareTo(Integer *integer, Integer *other) {
    if (integer == NULL || other == NULL) {
        Exception("NULL pointer exception");
    }
    return integer->value - other->value;
}