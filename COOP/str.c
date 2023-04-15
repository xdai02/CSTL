#include "str.h"

/**
 * @brief
 * @param str
 * @return char*
 */
char *str_clear(char *str) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }
    str[0] = '\0';
    return str;
}

bool str_equal(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }
    return strcmp(s1, s2) == 0;
}

bool str_equal_ignore_case(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }
    return strcasecmp(s1, s2) == 0;
}

char *str_tolower(char *str) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (str_len < suffix_len) {
        return false;
    }
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}

char *str_append_char(char *str, char c) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
    return str;
}

char *str_insert_char(char *str, int index, char c) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(str);
    if (index < 0 || index > len) {
        fprintf(stderr, "%s(): Index %d out of range.\n", __func__, index);
        exit(EXIT_FAILURE);
    }

    memmove(str + index + 1, str + index, len - index + 1);
    str[index] = c;
    return str;
}

char *str_insert_string(char *str, int index, const char *substr) {
    if (str == NULL || substr == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(str);
    size_t substr_len = strlen(substr);
    if (index < 0 || index > len) {
        fprintf(stderr, "%s(): Index %d out of range.\n", __func__, index);
        exit(EXIT_FAILURE);
    }

    memmove(str + index + substr_len, str + index, len - index + 1);
    memcpy(str + index, substr, substr_len);
    return str;
}

char *str_replace_char(char *str, char old_char, char new_char) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t old_str_len = strlen(old_str);
    size_t new_str_len = strlen(new_str);
    if (old_str_len == 0) {
        return str;
    }

    char *src = str;
    char *dst = str;
    char *found;

    while ((found = strstr(src, old_str)) != NULL) {
        size_t chars_to_copy = found - src;
        memcpy(dst, src, chars_to_copy);
        dst += chars_to_copy;
        src += chars_to_copy;

        memcpy(dst, new_str, new_str_len);
        src += old_str_len;
        dst += new_str_len;
    }

    strcpy(dst, src);

    return str;
}

char *str_substring(const char *str, int start, int end) {
    if (str == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(str);
    if (start < 0 || start > len) {
        fprintf(stderr, "%s(): Index %d out of range.\n", __func__, start);
        exit(EXIT_FAILURE);
    }
    if (end < 0 || end > len) {
        fprintf(stderr, "%s(): Index %d out of range.\n", __func__, end);
        exit(EXIT_FAILURE);
    }

    size_t substr_len = end - start;
    char *substring = (char *)malloc_s(sizeof(char) * (substr_len + 1));
    memcpy(substring, str + start, substr_len);
    substring[substr_len] = '\0';
    return substring;
}

int str_count_substring(const char *str, const char *substr) {
    if (str == NULL || substr == NULL) {
        fprintf(stderr, "%s(): NULL pointer exception.\n", __func__);
        exit(EXIT_FAILURE);
    }

    int count = 0;
    char *p = strstr(str, substr);
    while (p != NULL) {
        count++;
        p = strstr(p + 1, substr);
    }
    return count;
}
