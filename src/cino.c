#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cino.h"

int main(int argc, char *argv[])
{
    string_t *s = string_create("Hello World");

    printf("[%s]\n", string_get(s));
    printf("=%d\n", string_length(s));

    string_destroy(s);

    return 0;
}