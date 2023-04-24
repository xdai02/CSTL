#ifndef _COOP_STRING_H_
#define _COOP_STRING_H_

#include "coop_utils.h"

typedef struct string_t string_t;

/**
 * @brief Create a string_t object.
 * @param str The primitive string.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_create(const char *str);

/**
 * @brief Destroy the string_t object.
 * @param string string_t object.
 */
void string_destroy(string_t *string);

/**
 * @brief Clone a string_t object.
 * @param string string_t object.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_clone(const string_t *string);

/**
 * @brief Returns the length of the string.
 * @param string string_t object.
 * @return Returns the length of the string.
 */
size_t string_length(const string_t *string);

/**
 * @brief Checks if the string is empty.
 * @param string string_t object.
 * @return Returns true if the string is empty, otherwise returns false.
 */
bool string_is_empty(const string_t *string);

/**
 * @brief Get the primitive string.
 * @param string string_t object.
 * @return Returns the primitive string.
 */
const char *string_get(const string_t *string);

/**
 * @brief Get the character at the specified index.
 * @param string string_t object.
 * @param index The index.
 * @return Returns the character at the specified index.
 */
char string_char_at(const string_t *string, size_t index);

/**
 * @brief Set the character at the specified index.
 * @param string string_t object.
 * @param index The index.
 * @param c The new character.
 * @return Returns the modified string_t object.
 */
string_t *string_set_char_at(string_t *string, size_t index, char c);
string_t *string_clear(string_t *string);
bool string_equal(const string_t *string1, const string_t *string2);
bool string_equal_ignore_case(const string_t *string1, const string_t *string2);
string_t *string_tolower(string_t *string);
string_t *string_toupper(string_t *string);
bool string_starts_with(const string_t *string, const char *prefix);
bool string_ends_with(const string_t *string, const char *suffix);
int string_index_of_char(const string_t *string, char c);
int string_index_of_string(const string_t *string, const char *str);
bool string_contains_string(const string_t *string, const char *str);
string_t *string_reverse(string_t *string);
string_t *string_strip(string_t *string);
const char *string_substring(const string_t *string, int start, int end);
size_t string_count_substring(const string_t *string, const char *substr);
string_t *string_append_char(string_t *string, char c);
string_t *string_insert_char(string_t *string, size_t index, char c);
string_t *string_concat(string_t *string, const char *str);
string_t *string_insert_string(string_t *string, size_t index, const char *str);
string_t *string_remove_char(string_t *string, char c);
string_t *string_remove_string(string_t *string, const char *str);
string_t *string_replace_char(string_t *string, char old_char, char new_char);
string_t *string_replace_string(string_t *string, const char *old_str, const char *new_str);
string_t **string_split(const string_t *string, const char *delimiter);

#endif