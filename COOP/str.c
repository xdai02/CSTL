#include "str.h"

char *str_clear(char *str) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }
    str[0] = '\0';
    return str;
}

bool str_equal(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        Exception("NULL pointer exception");
    }
    return strcmp(s1, s2) == 0;
}

bool str_equal_ignore_case(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        Exception("NULL pointer exception");
    }
    return strcasecmp(s1, s2) == 0;
}

char *str_tolower(char *str) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    char *p = str;
    while (*p != '\0') {
        *p = tolower(*p);
        p++;
    }
    return str;
}

char *str_toupper(char *str) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    char *p = str;
    while (*p != '\0') {
        *p = toupper(*p);
        p++;
    }
    return str;
}

bool str_starts_with(const char *str, const char *prefix) {
    if (str == NULL || prefix == NULL) {
        Exception("NULL pointer exception");
    }

    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);
    if (str_len < prefix_len) {
        return false;
    }
    return strncmp(str, prefix, prefix_len) == 0;
}

bool str_ends_with(const char *str, const char *suffix) {
    if (str == NULL || suffix == NULL) {
        Exception("NULL pointer exception");
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (str_len < suffix_len) {
        return false;
    }
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}

int str_index_of_char(const char *str, char c) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    char *p = strchr(str, c);
    if (p == NULL) {
        return -1;
    }
    return p - str;
}

int str_index_of_string(const char *str, const char *substr) {
    if (str == NULL || substr == NULL) {
        Exception("NULL pointer exception");
    }

    char *p = strstr(str, substr);
    if (p == NULL) {
        return -1;
    }
    return p - str;
}

char *str_reverse(char *str) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    size_t len = strlen(str);
    size_t i;
    for (i = 0; i < len / 2; i++) {
        swap(str[i], str[len - i - 1], char);
    }

    return str;
}

char *str_trim(char *str) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

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

char *str_substring(const char *str, int start, int end) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    size_t len = strlen(str);
    if (start < 0 || start > len) {
        Exception("Index out of range exception");
    }
    if (end < 0 || end > len) {
        Exception("Index out of range exception");
    }

    size_t substr_len = end - start;
    char *substring = (char *)malloc(sizeof(char) * (substr_len + 1));
    if (substring == NULL) {
        Exception("Out of memory exception");
    }
    memcpy(substring, str + start, substr_len);
    substring[substr_len] = '\0';
    return substring;
}

int str_count_substring(const char *str, const char *substr) {
    if (str == NULL || substr == NULL) {
        Exception("NULL pointer exception");
    }

    int count = 0;
    char *p = strstr(str, substr);
    while (p != NULL) {
        count++;
        p = strstr(p + 1, substr);
    }
    return count;
}

char *str_append_char(char *str, char c) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    size_t len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
    return str;
}

char *str_insert_char(char *str, int index, char c) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

    size_t len = strlen(str);
    if (index < 0 || index > len) {
        Exception("Index out of range exception");
    }

    memmove(str + index + 1, str + index, len - index + 1);
    str[index] = c;
    return str;
}

char *str_insert_string(char *str, int index, const char *substr) {
    if (str == NULL || substr == NULL) {
        Exception("NULL pointer exception");
    }

    size_t len = strlen(str);
    size_t substr_len = strlen(substr);
    if (index < 0 || index > len) {
        Exception("Index out of range exception");
    }

    memmove(str + index + substr_len, str + index, len - index + 1);
    memcpy(str + index, substr, substr_len);
    return str;
}

char *str_remove_char(char *str, char c) {
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

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
    if (str == NULL || substr == NULL) {
        Exception("NULL pointer exception");
    }

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
    if (str == NULL) {
        Exception("NULL pointer exception");
    }

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
    if (str == NULL || old_str == NULL || new_str == NULL) {
        Exception("NULL pointer exception");
    }

    size_t old_str_len = strlen(old_str);
    size_t new_str_len = strlen(new_str);
    if (old_str_len == 0) {
        return str;
    }

    char *p = str;
    while ((p = strstr(p, old_str))) {
        memmove(p + new_str_len, p + old_str_len, strlen(p + old_str_len) + 1);
        memcpy(p, new_str, new_str_len);
        p += new_str_len;
    }

    return str;
}

char **str_split(const char *str, const char *delimiter) {
    if (str == NULL || delimiter == NULL) {
        Exception("NULL pointer exception");
    }

    char *temp = strdup(str);
    if (temp == NULL) {
        Exception("Out of memory exception");
    }

    size_t count = 0;
    char *token = strtok(temp, delimiter);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiter);
    }

    char **tokens = (char **)malloc(sizeof(char *) * (count + 1));
    if (tokens == NULL) {
        free(temp);
        Exception("Out of memory exception");
    }

    strcpy(temp, str);
    count = 0;
    token = strtok(temp, delimiter);
    while (token != NULL) {
        tokens[count] = strdup(token);
        if (tokens[count] == NULL) {
            for (size_t i = 0; i < count; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(temp);
            Exception("Out of memory exception");
        }
        count++;
        token = strtok(NULL, delimiter);
    }

    free(temp);
    tokens[count] = NULL;
    return tokens;
}
