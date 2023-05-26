#ifndef _STR_H_
#define _STR_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"
#include "utils/c_str.h"

typedef struct string_t string_t;

/**
 * @brief Create a string_t object.
 * @param str The primitive string.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_new(const char *str);

/**
 * @brief Destroy the string_t object.
 * @param string The string_t object.
 */
void string_delete(string_t *string);

/**
 * @brief Clone a string_t object.
 * @param string The string_t object.
 * @return Returns a string_t pointer if the memory allocation succeeds, otherwise returns NULL.
 */
string_t *string_clone(const string_t *string);

/**
 * @brief Returns the length of the string_t object.
 * @param string The string_t object.
 * @return Returns the length of the string_t object.
 */
size_t string_length(const string_t *string);

/**
 * @brief Checks if the string_t object is empty.
 * @param string The string_t object.
 * @return Returns true if the string_t object is empty, otherwise returns false.
 */
bool string_is_empty(const string_t *string);

/**
 * @brief Get the primitive string.
 * @param string The string_t object.
 * @return Returns the primitive string.
 */
const char *string_get(const string_t *string);

/**
 * @brief Get the character at the specified index.
 * @param string The string_t object.
 * @param index The index.
 * @return Returns the character at the specified index.
 */
char string_char_at(const string_t *string, size_t index);

/**
 * @brief Set the character at the specified index.
 * @param string The string_t object.
 * @param index The index.
 * @param c The new character.
 * @return Returns the modified string_t object.
 */
string_t *string_set_char_at(string_t *string, size_t index, char c);

/**
 * @brief Clear the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_clear(string_t *string);

/**
 * @brief Checks if two string_t objects are equal.
 * @param s1 The first string_t object.
 * @param s2 The second string_t object.
 * @return Returns true if the two string_t object are equal, otherwise returns false.
 */
bool string_equal(const string_t *string1, const string_t *string2);

/**
 * @brief Checks if two string_t objects are equal, ignoring case.
 * @param string1 The first string_t object.
 * @param string2 The second string_t object.
 * @return Returns true if the two string_t objects are equal ignoring case, otherwise returns false.
 */
bool string_equal_ignore_case(const string_t *string1, const string_t *string2);

/**
 * @brief Compares two string_t objects.
 * @param string1 The first string_t object.
 * @param string2 The second string_t object.
 * @return Returns a negative integer if string1 < string2.
 *         Returns 0 if string1 == string2.
 *         Returns a positive integer if string1 > string2.
 */
int string_compare(const string_t *string1, const string_t *string2);

/**
 * @brief Returns the hash code of the given string_t object.
 * @param string The string_t object.
 * @return The hash code of the given string_t object.
 */
size_t string_hash(const string_t *string);

/**
 * @brief Convert the string_t object to lowercase.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_tolower(string_t *string);

/**
 * @brief Convert the string_t object to uppercase.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_toupper(string_t *string);

/**
 * @brief Checks if the string_t object starts with the specified prefix.
 * @param string The string_t object.
 * @param prefix The prefix.
 * @return Returns true if the string_t object starts with the specified prefix, otherwise returns false.
 */
bool string_starts_with(const string_t *string, const char *prefix);

/**
 * @brief Checks if the string_t object ends with the specified suffix.
 * @param string The string_t object.
 * @param suffix The suffix.
 * @return Returns true if the string_t object ends with the specified suffix, otherwise returns false.
 */
bool string_ends_with(const string_t *string, const char *suffix);

/**
 * @brief Returns the index of the first occurrence of the specified character in the string_t object.
 * @param string The string_t object.
 * @param c The target character.
 * @return Returns the index of the first occurrence of the specified character in the string_t object, or -1 if the character does not occur.
 */
int string_index_of_char(const string_t *string, char c);

/**
 * @brief Returns the index of the first occurrence of the specified substring in the string_t object, starting the search at the specified index.
 * @param string The string_t object.
 * @param str The target substring.
 * @return Returns the index of the first occurrence of the specified substring in the string_t object, starting the search at the specified index, or -1 if the substring does not occur.
 */
int string_index_of_string(const string_t *string, const char *str);

/**
 * @brief Checks if the string_t object contains the specified substring.
 * @param string The string_t object.
 * @param str The target substring.
 * @return Returns true if the string_t object contains the specified substring, otherwise returns false.
 */
bool string_contains_string(const string_t *string, const char *str);

/**
 * @brief Reverse the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_reverse(string_t *string);

/**
 * @brief Remove the leading and trailing whitespace characters from the string_t object.
 * @param string The string_t object.
 * @return Returns the modified string_t object.
 */
string_t *string_strip(string_t *string);

/**
 * @brief Get the substring of the specified string_t object.
 * @param string The string_t object.
 * @param start The start index of the substring (inclusive).
 * @param end The end index of the substring (exclusive).
 * @return The substring of the specified string.
 * @note Caller MUST free the returned string.
 */
char *string_substring(const string_t *string, int start, int end);

/**
 * @brief Count the number of occurrences of the specified substring in the string_t object.
 * @param string The string_t object.
 * @param substr The target substring.
 * @return The number of occurrences of the specified substring in the string_t object.
 */
size_t string_count_substring(const string_t *string, const char *substr);

/**
 * @brief Append the specified character to the end of the string_t object.
 * @param string The string_t object.
 * @param c The appended character.
 * @return Returns the modified string_t object.
 */
string_t *string_append_char(string_t *string, char c);

/**
 * @brief Insert the specified character to the specified index of the string_t object.
 * @param string The string_t object.
 * @param index The index to be inserted.
 * @param c The inserted character.
 * @return Returns the modified string_t object.
 */
string_t *string_insert_char(string_t *string, size_t index, char c);

/**
 * @brief Append the specified string to the end of the string_t object.
 * @param string The string_t object.
 * @param str The appended string.
 * @return Returns the modified string_t object.
 */
string_t *string_concat(string_t *string, const char *str);

/**
 * @brief Insert the specified substring to the specified index of the string_t object.
 * @param string The string_t object.
 * @param index The index to be inserted.
 * @param substr The inserted substring.
 * @return Returns the modified string_t object.
 */
string_t *string_insert_string(string_t *string, size_t index, const char *str);

/**
 * @brief Removes all occurrences of the specified character from the string_t object.
 * @param string The string_t object.
 * @param c The removed character.
 * @return Returns the modified string_t object.
 */
string_t *string_remove_char(string_t *string, char c);

/**
 * @brief Removes all occurrences of the specified substring from the string_t object.
 * @param string The string_t object.
 * @param substr The removed substring.
 * @return Returns the modified string_t object.
 */
string_t *string_remove_string(string_t *string, const char *str);

/**
 * @brief Replaces all occurrences of the specified character in the string_t object with the specified new character.
 * @param string The string_t object.
 * @param old_char The replaced character.
 * @param new_char The new character.
 * @return Returns the modified string_t object.
 */
string_t *string_replace_char(string_t *string, char old_char, char new_char);

/**
 * @brief Replaces all occurrences of the specified substring in the string_t object with the specified new substring.
 * @param string The string_t object.
 * @param old_str The replaced substring.
 * @param new_str The new substring.
 * @return Returns the modified string_t object.
 */
string_t *string_replace_string(string_t *string, const char *old_str, const char *new_str);

/**
 * @brief Splits the string_t object into an array of strings using the specified delimiter.
 * @param string The string_t object.
 * @param delimiter The delimiter.
 * @return An array of strings ends with NULL.
 * @note The returned array ends with NULL.
 * @note Caller MUST free the returned array.
 */
char **string_split(const string_t *string, const char *delimiter);

#endif
