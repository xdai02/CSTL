#ifndef _STR_H_
#define _STR_H_

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Clear the string.
 * @param str The string to be cleared.
 * @return The cleared string.
 */
char *str_clear(char *str);

/**
 * @brief Checks if two strings are equal.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return Returns true if the two strings are equal, otherwise returns false.
 */
bool str_equal(const char *s1, const char *s2);

/**
 * @brief Checks if two strings are equal, ignoring case.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return Returns true if the two strings are equal ignoring case, otherwise returns false.
 */
bool str_equal_ignore_case(const char *s1, const char *s2);

/**
 * @brief Convert the string to lowercase.
 * @param str The string to be converted.
 * @return The converted string.
 */
char *str_tolower(char *str);

/**
 * @brief Convert the string to uppercase.
 * @param str The string to be converted.
 * @return The converted string.
 */
char *str_toupper(char *str);

/**
 * @brief Checks if the string starts with the specified prefix.
 * @param str The string to be checked.
 * @param prefix The prefix to be checked.
 * @return Returns true if the string starts with the specified prefix, otherwise returns false.
 */
bool str_starts_with(const char *str, const char *prefix);

/**
 * @brief Checks if the string ends with the specified suffix.
 * @param str The string to be checked.
 * @param suffix The suffix to be checked.
 * @return Returns true if the string ends with the specified suffix, otherwise returns false.
 */
bool str_ends_with(const char *str, const char *suffix);

/**
 * @brief Returns the index of the first occurrence of the specified character in the string.
 * @param str The string to be searched.
 * @param c The target character.
 * @return The index of the first occurrence of the specified character in the string.
 */
int str_index_of_char(const char *str, char c);

/**
 * @brief Returns the index of the first occurrence of the specified substring in the string.
 * @param str The string to be searched.
 * @param substr The target substring.
 * @return The index of the first occurrence of the specified substring in the string.
 */
int str_index_of_string(const char *str, const char *substr);

/**
 * @brief Checks if the string contains the specified substring.
 * @param str The string to be checked.
 * @param substr The target substring.
 * @return Returns true if the string contains the specified substring, otherwise returns false.
 */
bool str_contains_string(const char *str, const char *substr);

/**
 * @brief Reverse the string.
 * @param str The string to be reversed.
 * @return The reversed string.
 */
char *str_reverse(char *str);

/**
 * @brief Remove the leading and trailing whitespace characters from the string.
 * @param str The string to be stripped.
 * @return The stripped string.
 */
char *str_strip(char *str);

/**
 * @brief Get the substring of the specified string.
 * @param str The string to be sliced.
 * @param start The start index of the substring (inclusive).
 * @param end The end index of the substring (exclusive).
 * @return The substring of the specified string.
 * @note The returned string must be freed by the caller.
 */
char *str_substring(const char *str, size_t start, size_t end);

/**
 * @brief Count the number of occurrences of the specified substring in the string.
 * @param str The string to be searched.
 * @param substr The target substring.
 * @return The number of occurrences of the specified substring in the string.
 */
size_t str_count_substring(const char *str, const char *substr);

/**
 * @brief Append the specified character to the end of the string.
 * @param str The string to be appended.
 * @param c The appended character.
 * @return The string after appending.
 */
char *str_append_char(char *str, char c);

/**
 * @brief Insert the specified character to the specified index of the string.
 * @param str The string to be inserted.
 * @param index The index to be inserted.
 * @param c The inserted character.
 * @return The string after inserting.
 */
char *str_insert_char(char *str, size_t index, char c);

/**
 * @brief Insert the specified substring to the specified index of the string.
 * @param str The string to be inserted.
 * @param index The index to be inserted.
 * @param substr The inserted substring.
 * @return The string after inserting.
 */
char *str_insert_string(char *str, size_t index, const char *substr);

/**
 * @brief Removes all occurrences of the specified character from the string.
 * @param str The string to be removed.
 * @param c The removed character.
 * @return The string after removing.
 */
char *str_remove_char(char *str, char c);

/**
 * @brief Removes all occurrences of the specified substring from the string.
 * @param str The string to be removed.
 * @param substr The removed substring.
 * @return The string after removing.
 */
char *str_remove_string(char *str, const char *substr);

/**
 * @brief Replaces all occurrences of the specified character in the string with the specified new character.
 * @param str The string to be replaced.
 * @param old_char The replaced character.
 * @param new_char The new character.
 * @return The string after replacing.
 */
char *str_replace_char(char *str, char old_char, char new_char);

/**
 * @brief Replaces all occurrences of the specified substring in the string with the specified new substring.
 * @param str The string to be replaced.
 * @param old_str The replaced substring.
 * @param new_str The new substring.
 * @return The string after replacing.
 */
char *str_replace_string(char *str, const char *old_str, const char *new_str);

/**
 * @brief Splits the string into a list of strings using the specified delimiter.
 * @param str The string to be split.
 * @param delimiter The delimiter.
 * @return A list of strings ends with NULL.
 * @note The returned list ends with NULL.
 * @note The returned list must be freed by the caller.
 */
char **str_split(const char *str, const char *delimiter);

#endif
