#include "cino_string.h"

typedef struct string_t {
    str_t string;
    size_t length;
} string_t;

/**
 * @brief   Create cino-string.
 * @param str   string
 * @return  Returns the pointer to cino-string. Returns NULL if the creation failed.
 */
string_t *string_create(const str_t str) {
    string_t *string = (string_t *)cino_alloc(sizeof(string_t));
    return_value_if_fail(string != NULL, NULL);

    string->length = str ? str_length(str) : 0;
    string->string = (str_t)cino_alloc((string->length + 1) * sizeof(char));
    call_and_return_value_if_fail(string->string != NULL, string_destroy(string), NULL);

    str_copy(string->string, str);
    return string;
}

/**
 * @brief   Destroy cino-string.
 * @param string    cino-string
 */
void string_destroy(string_t *string) {
    return_if_fail(string != NULL);

    string->length = 0;

    if (string->string) {
        free(string->string);
        string->string = NULL;
    }

    if (string) {
        free(string);
        string = NULL;
    }
}

/**
 * @brief   Get the string literal.
 * @param string    cino-string
 * @return  String literal.
 */
const str_t string_get(const string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string->string;
}

/**
 * @brief   Set the string value.
 * @param string    cino-string
 * @param str       string literal
 * @return  Returns the modified cino-string.
 */
string_t *string_set(string_t *string, const str_t str) {
    return_value_if_fail(string != NULL, NULL);
    call_and_return_value_if_fail(str != NULL, string_clear(string), string);

    size_t str_len = str_length(str);
    if (string->length != str_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string->length + 1), sizeof(char) * (str_len + 1));
        if (!string->string) {
            string_destroy(string);
            return NULL;
        }
    }

    str_copy(string->string, str);
    string->length = str_len;
    return string;
}

/**
 * @brief   Returns the length of the cino-string.
 * @param str   cino-string
 * @return  Returns the length of the cino-string. Returns 0 if cino-string is NULL.
 */
size_t string_length(const string_t *string) {
    return_value_if_fail(string != NULL, 0);
    return string->length;
}

/**
 * @brief   Reset cino-string with '\0'.
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_clear(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string->length = 0;
    string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string->length + 1), sizeof(char) * (string->length + 1));
    str_clear(string->string, string->length + 1);
    return string;
}

/**
 * @brief   Determine if two cino-strings are equal.
 * @param s1    cino-string 1
 * @param s2    cino-string 2
 * @return  Returns true if two cino-strings are equal, otherwise returns false.
 */
bool string_equal(const string_t *s1, const string_t *s2) {
    return_value_if_fail(s1 != NULL && s2 != NULL, false);
    return str_equal(s1->string, s2->string);
}

/**
 * @brief   Determine if two cino-strings are equal, ignoring case considerations.
 * @param s1    cino-string 1
 * @param s2    cino-string 2
 * @return  Returns true if two cino-strings are equal ignoring case considerations, otherwise
 *          returns false.
 */
bool string_equal_ignore_case(const string_t *s1, const string_t *s2) {
    return_value_if_fail(s1 != NULL && s2 != NULL, false);
    return str_equal_ignore_case(s1->string, s2->string);
}

/**
 * @brief   Converts all of the characters to lower case
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_to_lower(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_to_lower(string->string);
    return string;
}

/**
 * @brief   Converts all of the characters to upper case
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_to_upper(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_to_upper(string->string);
    return string;
}

/**
 * @brief   Tests if the cino-string starts with the specified prefix.
 * @param string    cino-string
 * @param prefix    prefix string
 * @return  Returns true if the cino-string starts with the specified prefix, otherwise
 *          returns false.
 */
bool string_starts_with(const string_t *string, const str_t prefix) {
    if (!string) {
        return false;
    }
    return str_starts_with(string->string, prefix);
}

/**
 * @brief   Tests if the cino-string ends with the specified suffix.
 * @param string    cino-string
 * @param suffix    suffix string
 * @return  Returns true if the cino-string ends with the specified suffix, otherwise
 *          returns false.
 */
bool string_ends_with(const string_t *string, const str_t postfix) {
    if (!string) {
        return false;
    }
    return str_ends_with(string->string, postfix);
}

/**
 * @brief   cino-string copy.
 * @param destination   destination cino-string
 * @param source        source cino-string
 * @return  Returns the destination cino-string.
 */
string_t *string_copy(string_t *destination, const string_t *source) {
    return_value_if_fail(destination != NULL, NULL);
    call_and_return_value_if_fail(source != NULL, string_clear(destination), destination);
    string_set(destination, source->string);
    return destination;
}

/**
 * @brief   cino-string concatenate.
 * @param destination   destination cino-string
 * @param source        source cino-string
 * @return  Returns destination cino-string.
 */
string_t *string_concat(string_t *destination, const string_t *source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);

    destination->string = (str_t)cino_realloc(destination->string, sizeof(char) * (destination->length + 1), sizeof(char) * (destination->length + source->length + 1));
    if (!destination->string) {
        string_destroy(destination);
        return NULL;
    }

    str_concat(destination->string, source->string);
    destination->length += source->length;
    return destination;
}

/**
 * @brief   Removes leading and trailing whitespaces.
 * @param string    cino-string
 * @return  Returns a cino-string with any leading and trailing whitespace removed.
 */
string_t *string_trim(string_t *string) {
    return_value_if_fail(string != NULL, NULL);

    str_trim(string->string);
    string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string->length + 1), sizeof(char) * (str_length(string->string) + 1));
    string->length = str_length(string->string);

    return string;
}

/**
 * @brief   Append a char to the cino-string.
 * @param string    cino-string
 * @param c         char
 * @return  Returns the modified cino-string.
 */
string_t *string_append_char(string_t *string, char c) {
    return_value_if_fail(string != NULL, NULL);

    if (c != '\0') {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string->length + 1), sizeof(char) * (string->length + 2));
        if (!string->string) {
            string_destroy(string);
            return NULL;
        }
    }

    str_append_char(string->string, c);
    string->length = str_length(string->string);
    return string;
}

/**
 * @brief   Insert a char into the cino-string.
 * @param string    cino-string
 * @param index     insert position
 * @param c         char
 * @return  Returns the modified cino-string.
 */
string_t *string_insert_char(string_t *string, int index, char c) {
    return_value_if_fail(string != NULL && index >= 0 && index <= string->length, string);

    size_t new_len = string->length + 1;

    string->string = (str_t)cino_realloc(string->string, sizeof(char) * new_len, sizeof(char) * (new_len + 1));
    if (!string->string) {
        string_destroy(string);
        return NULL;
    }

    str_insert_char(string->string, index, c);

    string->length = str_length(string->string);
    if (string->length < new_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (new_len + 1), sizeof(char) * (string->length + 1));
    }

    return string;
}

/**
 * @brief   Insert a string into the cino-string.
 * @param string    cino-string
 * @param index     insert position
 * @param substr    inserted string
 * @return  Returns the modified cino-string.
 */
string_t *string_insert_string(string_t *string, int index, const str_t substr) {
    return_value_if_fail(string != NULL && index >= 0 && index <= string_length(string) && substr != NULL, string);

    size_t string_len = string->length;
    size_t substr_len = str_length(substr);

    string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string_len + 1), sizeof(char) * (string_len + substr_len + 1));
    if (!string->string) {
        string_destroy(string);
        return NULL;
    }

    str_insert_string(string->string, index, substr);

    string->length = str_length(string->string);
    if (string->length < string_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string_len + substr_len + 1), sizeof(char) * (string->length + 1));
    }

    return string;
}

/**
 * @brief   Count the number of substring occurrences.
 * @param string    cino-string
 * @param substr    substring
 * @return  The number of substring occurrences.
 */
int string_count_substring(const string_t *string, const str_t substr) {
    return_value_if_fail(string != NULL && substr != NULL, 0);
    return str_count_substring(string->string, substr);
}

/**
 * @brief   Replacing all occurrences of old char with new char.
 * @param string    cino-string
 * @param old_char  old char
 * @param new_char  new char
 * @return  Returns the modified cino-string.
 */
string_t *string_replace_char(string_t *string, char old_char, char new_char) {
    return_value_if_fail(string != NULL, NULL);

    size_t string_len = string->length;
    str_replace_char(string->string, old_char, new_char);

    string->length = str_length(string->string);
    if (string->length < string_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string_len + 1), sizeof(char) * (string->length + 1));
    }

    return string;
}

/**
 * @brief   Replacing all occurrences of old string with new string.
 * @param string    cino-string
 * @param old_str   old string
 * @param new_str   new string
 * @return  Returns the modified cino-string.
 */
string_t *string_replace(string_t *string, const str_t old_str, const str_t new_str) {
    return_value_if_fail(string != NULL && old_str != NULL && new_str != NULL, string);

    size_t old_str_len = str_length(old_str);
    size_t new_str_len = str_length(new_str);

    int replace_cnt = string_count_substring(string, old_str);

    size_t new_len = string->length + replace_cnt * (new_str_len - old_str_len);
    new_len = new_len < string->length ? string->length : new_len;

    string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string->length + 1), sizeof(char) * (new_len + 1));
    if (!string->string) {
        string_destroy(string);
        return NULL;
    }

    str_replace(string->string, old_str, new_str);

    string->length = str_length(string->string);
    if (string->length < new_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (new_len + 1), sizeof(char) * (string->length + 1));
    }

    return string;
}

/**
 * @brief   Removing all occurrences of the given substring.
 * @param string    cino-string
 * @param substr    string to be removed
 * @return  Returns the modified cino-string.
 */
string_t *string_remove(string_t *string, const str_t substr) {
    return_value_if_fail(string != NULL && substr != NULL, string);

    size_t string_len = string->length;
    str_remove(string->string, substr);
    string->length = str_length(string->string);

    if (string->length < string_len) {
        string->string = (str_t)cino_realloc(string->string, sizeof(char) * (string_len + 1), sizeof(char) * (string->length + 1));
    }

    return string;
}