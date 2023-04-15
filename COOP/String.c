#include "String.h"
#include "coop_utils.h"

typedef struct String {
    char *str;
    int length;
} String;

String *newString(const char *str) {
    return_value_if_fail(str != NULL, NULL);
    String *s = (String *)malloc_s(sizeof(String));
    s->str = (char *)malloc_s(strlen(str) + 1);
    strcpy(s->str, str);
    s->length = strlen(str);
    return s;
}

void freeString(String *s) {
    return_if_fail(s != NULL);
    if (s->str != NULL) {
        free(s->str);
    }
    free(s);
}

