#include "coop_string.h"
#include "coop_str.h"

typedef struct string_t {
    char *string;
    size_t length;
    size_t capacity;
} string_t;

string_t *string_create(const char *str) {
    return_value_if_fail(str != NULL, NULL);

    string_t *string = (string_t *)malloc(sizeof(string_t));
    return_value_if_fail(string != NULL, NULL);

    size_t len = strlen(str);
    string->string = (char *)malloc(sizeof(char) * (len + 1));
    if (string->string == NULL) {
        free(string);
        return NULL;
    }

    strcpy(string->string, str);
    string->length = len;
    string->capacity = len + 1;
    return string;
}

void string_destroy(string_t *string) {
    return_if_fail(string != NULL);
    free(string->string);
    free(string);
}

/**
 * @brief Resize the string capacity.
 *        1. If the string length is less than half of the capacity, the capacity will be reduced to half.
 *        2. If the string length is greater than or equal to the capacity, the capacity will be increased to 1.5 times.
 * @param string string_t pointer
 * @return Returns false if the memory allocation fails, otherwise returns true.
 */
static bool __string_resize(string_t *string, size_t new_capacity) {
    return_value_if_fail(string != NULL, false);

    char *new_string = (char *)realloc(string->string, sizeof(char) * new_capacity);
    return_value_if_fail(new_string != NULL, false);
    string->string = new_string;
    string->capacity = new_capacity;
    return true;
}

string_t *string_clone(const string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string_create(string->string);
}

size_t string_length(const string_t *string) {
    return_value_if_fail(string != NULL, 0);
    return string->length;
}

bool string_is_empty(const string_t *string) {
    return_value_if_fail(string != NULL, true);
    return string->length == 0;
}

char string_char_at(const string_t *string, size_t index) {
    exit_if_fail(string != NULL);
    exit_if_fail(index >= 0 && index < string->length);
    return string->string[index];
}

string_t *string_set_char_at(string_t *string, size_t index, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(index >= 0 && index < string->length, string);

    string->string[index] = c;
    if (c == '\0') {
        string->length = index;
    }

    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t *string_clear(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string->string[0] = '\0';
    string->length = 0;
    __string_resize(string, 16);
    return string;
}

bool string_equal(const string_t *string1, const string_t *string2) {
    exit_if_fail(string1 != NULL && string2 != NULL);
    return str_equal(string1->string, string2->string);
}

bool string_equal_ignore_case(const string_t *string1, const string_t *string2) {
    exit_if_fail(string1 != NULL && string2 != NULL);
    return str_equal_ignore_case(string1->string, string2->string);
}

string_t *string_tolower(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_tolower(string->string);
    return string;
}

string_t *string_toupper(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_toupper(string->string);
    return string;
}

bool string_starts_with(const string_t *string, const char *prefix) {
    exit_if_fail(string != NULL && prefix != NULL);
    return str_starts_with(string->string, prefix);
}

bool string_ends_with(const string_t *string, const char *suffix) {
    exit_if_fail(string != NULL && suffix != NULL);
    return str_ends_with(string->string, suffix);
}

int string_index_of_char(const string_t *string, char c) {
    return_value_if_fail(string != NULL, -1);
    return str_index_of_char(string->string, c);
}

int string_index_of_string(const string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, -1);
    return str_index_of_string(string->string, str);
}

bool string_contains_string(const string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, false);
    return str_index_of_string(string->string, str) >= 0;
}

string_t *string_reverse(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_reverse(string->string);
    return string;
}

string_t *string_strip(string_t *string) {
    return_value_if_fail(string != NULL, NULL);

    str_strip(string->string);
    string->length = strlen(string->string);

    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t *string_substring(const string_t *string, int start, int end) {
    return_value_if_fail(string != NULL, NULL);

    char *substring = str_substring(string->string, start, end);
    return_value_if_fail(substring != NULL, NULL);

    string_t *new_string = string_create(substring);
    free(substring);
    return new_string;
}

size_t string_count_substring(const string_t *string, const char *substr) {
    return_value_if_fail(string != NULL && substr != NULL, 0);
    return str_count_substring(string->string, substr);
}

string_t *string_append_char(string_t *string, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(c != '\0', string);

    if (string->length + 1 >= string->capacity) {
        if (!__string_resize(string, string->capacity * 3 / 2 + 1)) {
            return string;
        }
    }

    string->string[string->length++] = c;
    string->string[string->length] = '\0';
    return string;
}

string_t *string_insert_char(string_t *string, size_t index, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(index >= 0 && index <= string->length, string);

    if (c == '\0') {
        string->string[index] = '\0';
        string->length = index;

        if (string->length < string->capacity / 2) {
            __string_resize(string, string->capacity / 2 + 1);
        }

        return string;
    }

    if (string->length + 1 >= string->capacity) {
        if (!__string_resize(string, string->capacity * 3 / 2 + 1)) {
            return string;
        }
    }

    str_insert_char(string->string, index, c);
    string->length++;
    return string;
}

string_t *string_concat(string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, string);

    size_t new_len = string->length + strlen(str);
    if (new_len + 1 >= string->capacity) {
        if (!__string_resize(string, new_len + 1)) {
            return string;
        }
    }

    strcat(string->string, str);
    string->length = new_len;
    return string;
}

string_t *string_insert_string(string_t *string, size_t index, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, string);
    return_value_if_fail(index >= 0 && index <= string->length, string);

    size_t new_len = string->length + strlen(str);
    if (new_len + 1 >= string->capacity) {
        if (!__string_resize(string, new_len + 1)) {
            return string;
        }
    }

    str_insert_string(string->string, index, str);
    string->length = new_len;
    return string;
}

string_t *string_remove_char(string_t *string, char c) {
    return_value_if_fail(string != NULL, NULL);

    str_remove_char(string->string, c);

    string->length = strlen(string->string);
    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t *string_remove_string(string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, NULL);

    str_remove_string(string->string, str);

    string->length = strlen(string->string);
    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t *string_replace_char(string_t *string, char old_char, char new_char) {
    return_value_if_fail(string != NULL, NULL);

    str_replace_char(string->string, old_char, new_char);

    string->length = strlen(string->string);
    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t *string_replace_string(string_t *string, const char *old_str, const char *new_str) {
    return_value_if_fail(string != NULL && old_str != NULL && new_str != NULL, string);

    str_replace_string(string->string, old_str, new_str);

    string->length = strlen(string->string);
    if (string->length < string->capacity / 2) {
        __string_resize(string, string->capacity / 2 + 1);
    }

    return string;
}

string_t **string_split(const string_t *string, const char *delimiter) {
    return_value_if_fail(string != NULL && delimiter != NULL, NULL);

    char **str_tokens = str_split(string->string, delimiter);
    return_value_if_fail(str_tokens != NULL, NULL);

    size_t count = 0;
    while (str_tokens[count] != NULL) {
        count++;
    }

    string_t **tokens = (string_t **)malloc(sizeof(string_t *) * (count + 1));
    return_value_if_fail(tokens != NULL, NULL);

    size_t i;
    for (i = 0; i < count; i++) {
        tokens[i] = string_create(str_tokens[i]);
        free(str_tokens[i]);
    }
    free(str_tokens);
    tokens[count] = NULL;

    return tokens;
}
