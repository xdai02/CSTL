#ifndef _INTEGER_H_
#define _INTEGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Integer {
    int value;
} Integer;

Integer *Integer_new(int value);
int Integer_delete(Integer *integer);
int Integer_compareTo(Integer *integer, Integer *other);

#endif