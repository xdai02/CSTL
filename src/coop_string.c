#include "coop_string.h"
#include "coop_utils.h"

struct string_t {
    char *string;
    size_t length;
    size_t capacity;
};

/**
 * @brief Create a string_t object.
 * @param str The primitive string.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_create(const char *str) {
    string_t *string = NULL;
    size_t len;

    return_value_if_fail(str != NULL, NULL);

    string = (string_t *)malloc(sizeof(string_t));
    return_value_if_fail(string != NULL, NULL);

    len = strlen(str);
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

/**
 * @brief Destroy the string_t object.
 * @param string The string_t object.
 */
void string_destroy(string_t *string) {
    return_if_fail(string != NULL);
    free(string->string);
    free(string);
}

/**
 * @brief Resizes the string capacity to the specified capacity.
 * @param string The string_t object.
 * @param new_capacity The new capacity.
 * @return Returns false if the memory allocation fails, otherwise returns true.
 */
static bool __string_resize_to(string_t *string, size_t new_capacity) {
    char *new_string = NULL;

    return_value_if_fail(string != NULL, false);

    new_string = (char *)realloc(string->string, sizeof(char) * new_capacity);
    return_value_if_fail(new_string != NULL, false);
    string->string = new_string;
    string->capacity = new_capacity;
    return true;
}

/**
 * @brief Resizes the string capacity.
 *        1. If the length of the string is 0, the capacity is set to 16.
 *        2. If the length of the string is less than half of the capacity, the capacity is reduced by half.
 *        3. If the length of the string is greater than or equal to the capacity, the capacity is increased by half.
 * @param string The string_t object.
 * @return Returns false if the memory allocation fails, otherwise returns true.
 */
static bool __string_resize(string_t *string) {
    const int INITIAL_CAPACITY = 16;
    size_t new_capacity;

    return_value_if_fail(string != NULL, false);

    if (string->length == 0) {
        new_capacity = INITIAL_CAPACITY;
    } else if (string->length < string->capacity / 2) {
        new_capacity = string->capacity / 2 + 1;
    } else if (string->length + 1 >= string->capacity) {
        new_capacity = string->capacity * 3 / 2 + 1;
    } else {
        return true;
    }

    return __string_resize_to(string, new_capacity);
}

/**
 * @brief Clone a string_t object.
 * @param string The string_t object.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_clone(const string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string_create(string->string);
}

/**
 * @brief Returns the length of the string_t object.
 * @param string The string_t object.
 * @return Returns the length of the string_t object.
 */
size_t string_length(const string_t *string) {
    return_value_if_fail(string != NULL, 0);
    return string->length;
}

/**
 * @brief Checks if the string_t object is empty.
 * @param string The string_t object.
 * @return Returns true if the string_t object is empty, otherwise returns false.
 */
bool string_is_empty(const string_t *string) {
    return_value_if_fail(string != NULL, true);
    return string->length == 0;
}

/**
 * @brief Get the primitive string.
 * @param string The string_t object.
 * @return Returns the primitive string.
 */
const char *string_get(const string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string->string;
}

/**
 * @brief Get the character at the specified index.
 * @param string The string_t object.
 * @param index The index.
 * @return Returns the character at the specified index.
 */
char string_char_at(const string_t *string, size_t index) {
    exit_if_fail(string != NULL);
    exit_if_fail(index >= 0 && index < string->length);
    return string->string[index];
}

/**
 * @brief Set the character at the specified index.
 * @param string The string_t object.
 * @param index The index.
 * @param c The new character.
 * @return Returns the modified string_t object.
 */
string_t *string_set_char_at(string_t *string, size_t index, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(index >= 0 && index < string->length, string);

    string->string[index] = c;
    if (c == '\0') {
        string->length = index;
    }
    __string_resize(string);
    return string;
}

/**
 * @brief Clear the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_clear(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string->string[0] = '\0';
    string->length = 0;
    __string_resize(string);
    return string;
}

/**
 * @brief Checks if two string_t objects are equal.
 * @param s1 The first string_t object.
 * @param s2 The second string_t object.
 * @return Returns true if the two string_t object are equal, otherwise returns false.
 */
bool string_equal(const string_t *string1, const string_t *string2) {
    exit_if_fail(string1 != NULL && string2 != NULL);
    return str_equal(string1->string, string2->string);
}

/**
 * @brief Checks if two string_t objects are equal, ignoring case.
 * @param string1 The first string_t object.
 * @param string2 The second string_t object.
 * @return Returns true if the two string_t objects are equal ignoring case, otherwise returns false.
 */
bool string_equal_ignore_case(const string_t *string1, const string_t *string2) {
    exit_if_fail(string1 != NULL && string2 != NULL);
    return str_equal_ignore_case(string1->string, string2->string);
}

/**
 * @brief Convert the string_t object to lowercase.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_tolower(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_tolower(string->string);
    return string;
}

/**
 * @brief Convert the string_t object to uppercase.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_toupper(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_toupper(string->string);
    return string;
}

/**
 * @brief Checks if the string_t object starts with the specified prefix.
 * @param string The string_t object.
 * @param prefix The prefix.
 * @return Returns true if the string_t object starts with the specified prefix, otherwise returns false.
 */
bool string_starts_with(const string_t *string, const char *prefix) {
    exit_if_fail(string != NULL && prefix != NULL);
    return str_starts_with(string->string, prefix);
}

/**
 * @brief Checks if the string_t object ends with the specified suffix.
 * @param string The string_t object.
 * @param suffix The suffix.
 * @return Returns true if the string_t object ends with the specified suffix, otherwise returns false.
 */
bool string_ends_with(const string_t *string, const char *suffix) {
    exit_if_fail(string != NULL && suffix != NULL);
    return str_ends_with(string->string, suffix);
}

/**
 * @brief Returns the index of the first occurrence of the specified character in the string_t object.
 * @param string The string_t object.
 * @param c The target character.
 * @return Returns the index of the first occurrence of the specified character in the string_t object, or -1 if the character does not occur.
 */
int string_index_of_char(const string_t *string, char c) {
    return_value_if_fail(string != NULL, -1);
    return str_index_of_char(string->string, c);
}

/**
 * @brief Returns the index of the first occurrence of the specified substring in the string_t object, starting the search at the specified index.
 * @param string The string_t object.
 * @param str The target substring.
 * @return Returns the index of the first occurrence of the specified substring in the string_t object, starting the search at the specified index, or -1 if the substring does not occur.
 */
int string_index_of_string(const string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, -1);
    return str_index_of_string(string->string, str);
}

/**
 * @brief Checks if the string_t object contains the specified substring.
 * @param string The string_t object.
 * @param str The target substring.
 * @return Returns true if the string_t object contains the specified substring, otherwise returns false.
 */
bool string_contains_string(const string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, false);
    return str_index_of_string(string->string, str) >= 0;
}

/**
 * @brief Reverse the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_reverse(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_reverse(string->string);
    return string;
}

/**
 * @brief Remove the leading and trailing whitespace characters from the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_strip(string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    str_strip(string->string);
    string->length = strlen(string->string);
    __string_resize(string);
    return string;
}

/**
 * @brief Get the substring of the specified string_t object.
 * @param string The string_t object.
 * @param start The start index of the substring (inclusive).
 * @param end The end index of the substring (exclusive).
 * @return The substring of the specified string.
 * @note The returned string must be freed by the caller.
 */
char *string_substring(const string_t *string, int start, int end) {
    return_value_if_fail(string != NULL, NULL);
    return str_substring(string->string, start, end);
}

/**
 * @brief Count the number of occurrences of the specified substring in the string_t object.
 * @param string The string_t object.
 * @param substr The target substring.
 * @return The number of occurrences of the specified substring in the string_t object.
 */
size_t string_count_substring(const string_t *string, const char *substr) {
    return_value_if_fail(string != NULL && substr != NULL, 0);
    return str_count_substring(string->string, substr);
}

/**
 * @brief Append the specified character to the end of the string_t object.
 * @param string The string_t object.
 * @param c The appended character.
 * @return Returns the modified string_t object.
 */
string_t *string_append_char(string_t *string, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(c != '\0', string);
    return_value_if_fail(__string_resize(string), string);
    string->string[string->length++] = c;
    string->string[string->length] = '\0';
    return string;
}

/**
 * @brief Insert the specified character to the specified index of the string_t object.
 * @param string The string_t object.
 * @param index The index to be inserted.
 * @param c The inserted character.
 * @return Returns the modified string_t object.
 */
string_t *string_insert_char(string_t *string, size_t index, char c) {
    return_value_if_fail(string != NULL, NULL);
    return_value_if_fail(index >= 0 && index <= string->length, string);

    if (c == '\0') {
        string->string[index] = '\0';
        string->length = index;
        __string_resize(string);
        return string;
    }

    return_value_if_fail(__string_resize(string), string);
    str_insert_char(string->string, index, c);
    string->length++;
    return string;
}

/**
 * @brief Append the specified string to the end of the string_t object.
 * @param string The string_t object.
 * @param str The appended string.
 * @return Returns the modified string_t object.
 */
string_t *string_concat(string_t *string, const char *str) {
    size_t new_len;

    return_value_if_fail(string != NULL && str != NULL, string);

    new_len = string->length + strlen(str);
    if (new_len + 1 >= string->capacity) {
        return_value_if_fail(__string_resize_to(string, new_len + 1), string);
    }

    strcat(string->string, str);
    string->length = new_len;
    return string;
}

/**
 * @brief Insert the specified substring to the specified index of the string_t object.
 * @param string The string_t object.
 * @param index The index to be inserted.
 * @param substr The inserted substring.
 * @return Returns the modified string_t object.
 */
string_t *string_insert_string(string_t *string, size_t index, const char *str) {
    size_t new_len;

    return_value_if_fail(string != NULL && str != NULL, string);
    return_value_if_fail(index >= 0 && index <= string->length, string);

    new_len = string->length + strlen(str);
    if (new_len + 1 >= string->capacity) {
        return_value_if_fail(__string_resize_to(string, new_len + 1), string);
    }

    str_insert_string(string->string, index, str);
    string->length = new_len;
    return string;
}

/**
 * @brief Removes all occurrences of the specified character from the string_t object.
 * @param string The string_t object.
 * @param c The removed character.
 * @return Returns the modified string_t object.
 */
string_t *string_remove_char(string_t *string, char c) {
    return_value_if_fail(string != NULL, NULL);
    str_remove_char(string->string, c);
    string->length = strlen(string->string);
    __string_resize(string);
    return string;
}

/**
 * @brief Removes all occurrences of the specified substring from the string_t object.
 * @param string The string_t object.
 * @param substr The removed substring.
 * @return Returns the modified string_t object.
 */
string_t *string_remove_string(string_t *string, const char *str) {
    return_value_if_fail(string != NULL && str != NULL, NULL);
    str_remove_string(string->string, str);
    string->length = strlen(string->string);
    __string_resize(string);
    return string;
}

/**
 * @brief Replaces all occurrences of the specified character in the string_t object with the specified new character.
 * @param string The string_t object.
 * @param old_char The replaced character.
 * @param new_char The new character.
 * @return Returns the modified string_t object.
 */
string_t *string_replace_char(string_t *string, char old_char, char new_char) {
    return_value_if_fail(string != NULL, NULL);
    str_replace_char(string->string, old_char, new_char);
    string->length = strlen(string->string);
    __string_resize(string);
    return string;
}

/**
 * @brief Replaces all occurrences of the specified substring in the string_t object with the specified new substring.
 * @param string The string_t object.
 * @param old_str The replaced substring.
 * @param new_str The new substring.
 * @return Returns the modified string_t object.
 */
string_t *string_replace_string(string_t *string, const char *old_str, const char *new_str) {
    size_t old_str_len;
    size_t new_str_len;
    size_t len_diff;
    size_t occurences;
    size_t new_len;

    return_value_if_fail(string != NULL && old_str != NULL && new_str != NULL, string);

    old_str_len = strlen(old_str);
    new_str_len = strlen(new_str);
    len_diff = new_str_len - old_str_len;
    occurences = str_count_substring(string->string, old_str);
    new_len = string->length + occurences * len_diff;

    if (new_len + 1 >= string->capacity) {
        return_value_if_fail(__string_resize_to(string, new_len + 1), string);
    }

    str_replace_string(string->string, old_str, new_str);
    string->length = new_len;
    return string;
}

/**
 * @brief Splits the string_t object into an array of strings using the specified delimiter.
 * @param string The string_t object.
 * @param delimiter The delimiter.
 * @return An array of strings ends with NULL.
 * @note The returned array ends with NULL.
 * @note The returned array must be freed by the caller.
 */
char **string_split(const string_t *string, const char *delimiter) {
    return_value_if_fail(string != NULL && delimiter != NULL, NULL);
    return str_split(string->string, delimiter);
}
