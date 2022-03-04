#include "cino_string.h"

typedef struct string_t
{
    char *string;
    int length;
} string_t;

string_t *string_create(const char *str)
{
    return_value_if_fail(str != NULL, NULL);

    string_t *string = (string_t *)malloc(sizeof(string_t));
    return_value_if_fail(string != NULL, NULL);

    string->length = strlen(str);

    string->string = (char *)malloc(sizeof(char) * (string->length + 1));
    call_and_return_value_if_fail(string->string != NULL, string_destroy(string), NULL);

    memset(string->string, '\0', string->length + 1);
    strncpy(string->string, str, string->length);
    string->string[string->length] = '\0';

    return string;
}

void string_destroy(string_t *string)
{
    return_if_fail(string != NULL);

    string->length = 0;

    if (string->string)
    {
        free(string->string);
        string->string = NULL;
    }

    if (string)
    {
        free(string);
        string = NULL;
    }
}

const char *string_get(string_t *string)
{
    return_value_if_fail(string != NULL, NULL);
    return string->string;
}

int string_length(string_t *string)
{
    return_value_if_fail(string != NULL, 0);
    return string->length;
}

void string_clear(string_t *string)
{
    return_if_fail(string != NULL);
    
    string->length = 0;
    string->string = (char *)realloc(string->string, sizeof(char) * (string->length + 1));
    call_and_return_if_fail(string->string != NULL, string_destroy(string), NULL);
    memset(string->string, '\0', string->length + 1);
}