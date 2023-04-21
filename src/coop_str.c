#include "coop_str.h"

char *str_clear(char *str) {
    return_value_if_fail(str != NULL, NULL);
    str[0] = '\0';
    return str;
}

bool str_equal(const char *s1, const char *s2) {
    exit_if_fail(s1 != NULL && s2 != NULL);
    return strcmp(s1, s2) == 0;
}

bool str_equal_ignore_case(const char *s1, const char *s2) {
    exit_if_fail(s1 != NULL && s2 != NULL);

    while (*s1 && *s2) {
        if (toupper(*s1) != toupper(*s2)) {
            return false;
        }
        s1++;
        s2++;
    }
    return *s1 == '\0' && *s2 == '\0';
}

char *str_tolower(char *str) {
    return_value_if_fail(str != NULL, NULL);

    char *p = str;
    while (*p != '\0') {
        *p = tolower(*p);
        p++;
    }
    return str;
}

char *str_toupper(char *str) {
    return_value_if_fail(str != NULL, NULL);

    char *p = str;
    while (*p != '\0') {
        *p = toupper(*p);
        p++;
    }
    return str;
}

bool str_starts_with(const char *str, const char *prefix) {
    exit_if_fail(str != NULL && prefix != NULL);

    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);
    return_value_if_fail(prefix_len <= str_len, false);
    return strncmp(str, prefix, prefix_len) == 0;
}

bool str_ends_with(const char *str, const char *suffix) {
    exit_if_fail(str != NULL && suffix != NULL);

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    return_value_if_fail(suffix_len <= str_len, false);
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}

int str_index_of_char(const char *str, char c) {
    return_value_if_fail(str != NULL, -1);
    char *p = strchr(str, c);
    return_value_if_fail(p != NULL, -1);
    return p - str;
}

int str_index_of_string(const char *str, const char *substr) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    size_t substr_len = strlen(substr);
    return_value_if_fail(substr_len > 0, -1);

    char *p = strstr(str, substr);
    return_value_if_fail(p != NULL, -1);
    return p - str;
}

bool str_contains_string(const char *str, const char *substr) {
    return_value_if_fail(str != NULL && substr != NULL, false);

    size_t substr_len = strlen(substr);
    return_value_if_fail(substr_len > 0, false);

    return strstr(str, substr) != NULL;
}

char *str_reverse(char *str) {
    return_value_if_fail(str != NULL, NULL);

    size_t len = strlen(str);
    size_t i;
    for (i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1], char);
    }

    return str;
}

char *str_strip(char *str) {
    return_value_if_fail(str != NULL, NULL);

    char *start = str;
    while (isspace(*start)) {
        start++;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    if (*str == '\0') {
        return str;
    }

    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    end[1] = '\0';

    return str;
}

char *str_substring(const char *str, size_t start, size_t end) {
    return_value_if_fail(str != NULL, NULL);

    size_t len = strlen(str);
    return_value_if_fail(start >= 0 && start <= len, NULL);
    return_value_if_fail(end >= 0 && end <= len, NULL);
    return_value_if_fail(start <= end, NULL);

    size_t substr_len = end - start;
    char *substring = (char *)malloc(sizeof(char) * (substr_len + 1));
    return_value_if_fail(substring != NULL, NULL);

    memcpy(substring, str + start, substr_len);
    substring[substr_len] = '\0';
    return substring;
}

size_t str_count_substring(const char *str, const char *substr) {
    return_value_if_fail(str != NULL && substr != NULL, 0);

    size_t substr_len = strlen(substr);
    return_value_if_fail(substr_len > 0, 0);

    size_t count = 0;
    char *p = strstr(str, substr);
    while (p != NULL) {
        count++;
        p = strstr(p + 1, substr);
    }
    return count;
}

char *str_append_char(char *str, char c) {
    return_value_if_fail(str != NULL, NULL);

    size_t len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
    return str;
}

char *str_insert_char(char *str, size_t index, char c) {
    return_value_if_fail(str != NULL, NULL);

    size_t len = strlen(str);
    return_value_if_fail(index >= 0 && index <= len, str);

    memmove(str + index + 1, str + index, len - index + 1);
    str[index] = c;
    return str;
}

char *str_insert_string(char *str, size_t index, const char *substr) {
    return_value_if_fail(str != NULL && substr != NULL, str);

    size_t len = strlen(str);
    size_t substr_len = strlen(substr);
    return_value_if_fail(index >= 0 && index <= len, str);

    memmove(str + index + substr_len, str + index, len - index + 1);
    memcpy(str + index, substr, substr_len);
    return str;
}

char *str_remove_char(char *str, char c) {
    return_value_if_fail(str != NULL, NULL);

    char *p = str;
    while (*p != '\0') {
        if (*p == c) {
            memmove(p, p + 1, strlen(p + 1) + 1);
        } else {
            p++;
        }
    }
    return str;
}

char *str_remove_string(char *str, const char *substr) {
    return_value_if_fail(str != NULL && substr != NULL, str);

    size_t substr_len = strlen(substr);
    char *p = str;
    while (*p != '\0') {
        if (strncmp(p, substr, substr_len) == 0) {
            memmove(p, p + substr_len, strlen(p + substr_len) + 1);
        } else {
            p++;
        }
    }

    return str;
}

char *str_replace_char(char *str, char old_char, char new_char) {
    return_value_if_fail(str != NULL, NULL);

    char *p = str;
    while (*p != '\0') {
        if (*p == old_char) {
            *p = new_char;
        }
        p++;
    }
    return str;
}

char *str_replace_string(char *str, const char *old_str, const char *new_str) {
    return_value_if_fail(str != NULL && old_str != NULL && new_str != NULL, str);

    size_t old_str_len = strlen(old_str);
    size_t new_str_len = strlen(new_str);
    return_value_if_fail(old_str_len > 0, str);

    char *p = str;
    while ((p = strstr(p, old_str))) {
        memmove(p + new_str_len, p + old_str_len, strlen(p + old_str_len) + 1);
        memcpy(p, new_str, new_str_len);
        p += new_str_len;
    }

    return str;
}

char **str_split(const char *str, const char *delimiter) {
    return_value_if_fail(str != NULL && delimiter != NULL, NULL);

    char *temp = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    return_value_if_fail(temp != NULL, NULL);
    strcpy(temp, str);

    size_t count = 0;
    char *token = strtok(temp, delimiter);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }

    char **tokens = (char **)malloc(sizeof(char *) * (count + 1));
    if (tokens == NULL) {
        free(temp);
        return NULL;
    }

    strcpy(temp, str);
    count = 0;
    token = strtok(temp, delimiter);
    while (token != NULL) {
        tokens[count] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
        if (tokens[count] == NULL) {
            size_t i;
            for (i = 0; i < count; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(temp);
            return NULL;
        }
        strcpy(tokens[count], token);

        count++;
        token = strtok(NULL, delimiter);
    }

    free(temp);
    tokens[count] = NULL;
    return tokens;
}
