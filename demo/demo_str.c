#include <stdio.h>
#include "coop.h"

int main() {
    string_t *fruits = string_create("APPLE, Banana, cherry, DURIAN");

    char **tokens = string_split(fruits, ", ");

    // Convert all fruit names to lowercase.
    int i = 0;
    while (tokens[i] != NULL) {
        str_tolower(tokens[i]);
        printf("%s\n", tokens[i]);
        i++;
    }

    // Caller MUST free the memory for each generated token.
    i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);

    string_destroy(fruits);

    return 0;
}