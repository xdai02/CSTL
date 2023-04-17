/**************************************************
 * Module   :   cino_utils_str
 * Function :   Basic string operations
 * Category :
 *              - String Operation
 **************************************************/

#ifndef _CINO_UTILS_STR_H_
#define _CINO_UTILS_STR_H_

#include "cino_utils_basic.h"

/****************************************
 *           String Operation
 ****************************************/

/**
 * @brief   Determine if two strings are equal.
 * @param s1    string 1
 * @param s2    string 2
 * @return  Returns true if two strings are equal, otherwise returns false.
 */
bool str_equal(const str_t s1, const str_t s2);

/**
 * @brief   Determine if two strings are equal, ignoring case considerations.
 * @param s1    string 1
 * @param s2    string 2
 * @return  Returns true if two strings are equal ignoring case considerations, otherwise
 *          returns false.
 */
bool str_equal_ignore_case(const str_t s1, const str_t s2);

/**
 * @brief   Converts all of the characters to lower case
 * @param str   string
 * @return  String in lower case.
 */
str_t str_to_lower(str_t str);

/**
 * @brief   Converts all of the characters to upper case
 * @param str   string
 * @return  String in upper case.
 */
str_t str_to_upper(str_t str);

/**
 * @brief   Tests if the string starts with the specified prefix.
 * @param str       string
 * @param prefix    prefix string
 * @return  Returns true if the string starts with the specified prefix, otherwise
 *          returns false.
 */
bool str_starts_with(const str_t str, const str_t prefix);

/**
 * @brief   Tests if the string ends with the specified suffix.
 * @param str       string
 * @param suffix    suffix string
 * @return  Returns true if the string ends with the specified suffix, otherwise
 *          returns false.
 */
bool str_ends_with(const str_t str, const str_t suffix);

/**
 * @brief   Reset string with '\0'.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param str       string
 * @param str_size  sizeof(str)
 */
void str_clear(str_t str, size_t str_size);

/**
 * @brief   Returns the length of the string.
 * @param str   string
 * @return  Returns the length of the string. Returns 0 if stirng is NULL.
 */
size_t str_length(const str_t str);

/**
 * @brief   String copy.
 * @note    It is caller's responsibility to ensure the validity of the passing strings.
 * @param destination   destination string
 * @param source        source string
 * @return  Returns destination string.
 */
str_t str_copy(str_t destination, const str_t source);

/**
 * @brief   String concatenate.
 * @note    It is caller's responsibility to ensure the validity of the passing strings.
 * @param destination   destination string
 * @param source        source string
 * @return  Returns destination string.
 */
str_t str_concat(str_t destination, const str_t source);

/**
 * @brief   Removes leading and trailing whitespaces.
 * @param str   string
 * @return  Returns a string with any leading and trailing whitespace removed.
 */
str_t str_trim(str_t str);

/**
 * @brief   Append a char to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param c     char
 * @return  Returns the modified string.
 */
str_t str_append_char(str_t str, char c);

/**
 * @brief   Append an int to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param val   int value
 * @return  Returns the modified string.
 */
str_t str_append_int(str_t str, int val);

/**
 * @brief   Append a double to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str       string
 * @param val       double value
 * @param precision number of decimal places when rounding (default=2, max=16)
 * @return  Returns the modified string.
 */
str_t str_append_double(str_t str, double val, int precision);

/**
 * @brief   Insert a char into the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param index insert position
 * @param c     char
 * @return  Returns the modified string.
 */
str_t str_insert_char(str_t str, int index, char c);

/**
 * @brief   Insert a string into the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str       string
 * @param index     insert position
 * @param substr    inserted string
 * @return  Returns the modified string.
 */
str_t str_insert_string(str_t str, int index, const str_t substr);

/**
 * @brief   Returns a substring [start, end].
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param str           string
 * @param start         start index
 * @param end           end index
 * @param substr        string used to store the substring
 * @param substr_size   sizeof(substr)
 * @return  Returns a substring [start, end].
 */
str_t str_substring(str_t str, int start, int end, str_t substr, size_t substr_size);

/**
 * @brief   Count the number of substring occurrences.
 * @param str       string
 * @param substr    substring
 * @return  The number of substring occurrences.
 */
int str_count_substring(const str_t str, const str_t substr);

/**
 * @brief   Replacing all occurrences of old char with new char.
 * @param str       string
 * @param old_char  old char
 * @param new_char  new char
 * @return  Returns the modified string.
 */
str_t str_replace_char(str_t str, char old_char, char new_char);

/**
 * @brief   Replacing all occurrences of old string with new string.
 * @param str       string
 * @param old_str   old string
 * @param new_str   new string
 * @return  Returns the modified string.
 */
str_t str_replace(str_t str, const str_t old_str, const str_t new_str);

/**
 * @brief   Removing all occurrences of the given substring.
 * @param str       string
 * @param substr    string to be removed
 * @return  Returns the modified string.
 */
str_t str_remove(str_t str, const str_t substr);

/**
 * @brief   Reverse the order of the string.
 * @param str   string
 * @return  Returns the modified string.
 */
str_t str_reverse(str_t str);

/**
 * @brief   Find the first occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the first occurrence of the specified
 *          character, or `-1` if the character is not found.
 */
int str_index_of_char(const str_t str, char c);

/**
 * @brief   Find the first occurrence of the specified character, starting the
 *          search at the specified index.
 * @param str   string
 * @param c     char
 * @param from  start index for searching
 * @return  Returns the index within the string of the first occurrence of the specified
 *          character, starting the search at the specified index, or `-1` if the
 *          character is not found.
 */
int str_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   Find the first occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the first occurrence of the specified
 *          substring, or `-1` if the substring is not found.
 */
int str_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   Find the first occurrence of the specified substring, starting the
 *          search at the specified index.
 * @param str       string
 * @param substr    substring
 * @param from      start index for searching
 * @return  Returns the index within the string of the first occurrence of the specified
 *          substring, starting the search at the specified index, or `-1` if the
 *          substring is not found.
 */
int str_index_of_substring_from(const str_t str, const str_t substr, int from);

/**
 * @brief   Find the last occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the last occurrence of the specified
 *          character, or `-1` if the character is not found.
 */
int str_last_index_of_char(const str_t str, char c);

/**
 * @brief   Find the last occurrence of the specified character, searching backward
 *          starting at the specified index.
 * @param str   string
 * @param c     char
 * @param from  start index for searching
 * @return  Returns the index within the string of the last occurrence of the specified
 *          character, searching backward starting at the specified index, or `-1` if the
 *          character is not found.
 */
int str_last_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   Find the last occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the last occurrence of the specified
 *          substring, or `-1` if the substring is not found.
 */
int str_last_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   Find the last occurrence of the specified substring, searching backward
 *          starting at the specified index.
 * @param str       string
 * @param substr    substring
 * @param from  start index for searching
 * @return  Returns the index within the string of the last occurrence of the specified
 *          substring, searching backward starting at the specified index, or `-1` if the
 *          substring is not found.
 */
int str_last_index_of_substring_from(const str_t str, const str_t substr, int from);

/**
 * @brief   Splits the string around matches of the given delimiter.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          array of items
 * @param str           string
 * @param delimiter     delimiter
 * @param items         string array used to store the substrings
 * @return  Returns the number of splits.
 */
int str_split(const str_t str, const str_t delimiter, str_t *items);

#endif