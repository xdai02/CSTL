/**************************************************
 * Module   :   cino_string
 * Function :   Operations on cino-string
 * Category :
 *              - string_t
 **************************************************/

#ifndef _CINO_STRING_H_
#define _CINO_STRING_H_

#include "cino_utils.h"

typedef struct string_t string_t;

/**
 * @brief   Create cino-string.
 * @param str   string
 * @return  Returns the pointer to cino-string. Returns NULL if the creation failed.
 */
string_t *string_create(const char *str);

/**
 * @brief   Destroy cino-string.
 * @param string    cino-string
 */
void string_destroy(string_t *string);

/**
 * @brief   Get the string literal.
 * @param string    cino-string
 * @return  String literal.
 */
const char *string_get(const string_t *string);

/**
 * @brief   Set the string value.
 * @param string    cino-string
 * @param str       string literal
 * @return  Returns the modified cino-string.
 */
string_t *string_set(string_t *string, const char *str);

/**
 * @brief   Returns the length of the cino-string.
 * @param str   cino-string
 * @return  Returns the length of the cino-string. Returns 0 if cino-string is NULL.
 */
size_t string_length(const string_t *string);

/**
 * @brief   Reset cino-string with '\0'.
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_clear(string_t *string);

/**
 * @brief   Determine if two cino-strings are equal.
 * @param s1    cino-string 1
 * @param s2    cino-string 2
 * @return  Returns true if two cino-strings are equal, otherwise returns false.
 */
bool string_equal(const string_t *s1, const string_t *s2);

/**
 * @brief   Determine if two cino-strings are equal, ignoring case considerations.
 * @param s1    cino-string 1
 * @param s2    cino-string 2
 * @return  Returns true if two cino-strings are equal ignoring case considerations, otherwise 
 *          returns false.
 */
bool string_equal_ignore_case(const string_t *s1, const string_t *s2);

/**
 * @brief   Converts all of the characters to lower case
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_to_lower(string_t *string);

/**
 * @brief   Converts all of the characters to upper case
 * @param string    cino-string
 * @return  Returns the modified cino-string.
 */
string_t *string_to_upper(string_t *string);

/**
 * @brief   Tests if the cino-string starts with the specified prefix.
 * @param string    cino-string
 * @param prefix    prefix string
 * @return  Returns true if the cino-string starts with the specified prefix, otherwise 
 *          returns false.
 */
bool string_starts_with(const string_t *string, const str_t prefix);

/**
 * @brief   Tests if the cino-string ends with the specified suffix.
 * @param string    cino-string
 * @param suffix    suffix string
 * @return  Returns true if the cino-string ends with the specified suffix, otherwise 
 *          returns false.
 */
bool string_ends_with(const string_t *string, const str_t postfix);

/**
 * @brief   cino-string copy.
 * @param destination   destination cino-string
 * @param source        source cino-string
 * @return  Returns the destination cino-string.
 */
string_t *string_copy(string_t *destination, const string_t *source);

/**
 * @brief   cino-string concatenate.
 * @param destination   destination cino-string
 * @param source        source cino-string
 * @return  Returns destination cino-string.
 */
string_t *string_concat(string_t *destination, const string_t *source);

/**
 * @brief   Removes leading and trailing whitespaces.
 * @param string    cino-string
 * @return  Returns a cino-string with any leading and trailing whitespace removed.
 */
string_t *string_trim(string_t *string);

/**
 * @brief   Append a char to the cino-string.
 * @param string    cino-string
 * @param c         char
 * @return  Returns the modified cino-string.
 */
string_t *string_append_char(string_t *string, char c);

/**
 * @brief   Insert a char into the cino-string.
 * @param string    cino-string
 * @param index     insert position
 * @param c         char
 * @return  Returns the modified cino-string.
 */
string_t *string_insert_char(string_t *string, int index, char c);

/**
 * @brief   Insert a string into the cino-string.
 * @param string    cino-string
 * @param index     insert position
 * @param substr    inserted string
 * @return  Returns the modified cino-string.
 */
string_t *string_insert_string(string_t *string, int index, const str_t substr);

/**
 * @brief   Count the number of substring occurrences.
 * @param string    cino-string
 * @param substr    substring
 * @return  The number of substring occurrences.
 */
int string_count_substring(const string_t *string, const str_t substr);

/**
 * @brief   Replacing all occurrences of old char with new char.
 * @param string    cino-string
 * @param old_char  old char 
 * @param new_char  new char
 * @return  Returns the modified cino-string.
 */
string_t *string_replace_char(string_t *string, char old_char, char new_char);

/**
 * @brief   Replacing all occurrences of old string with new string.
 * @param string    cino-string
 * @param old_str   old string 
 * @param new_str   new string
 * @return  Returns the modified cino-string.
 */
string_t *string_replace(string_t *string, const str_t old_str, const str_t new_str);

/**
 * @brief   Removing all occurrences of the given substring.
 * @param string    cino-string
 * @param substr    string to be removed
 * @return  Returns the modified cino-string.
 */
string_t *string_remove(string_t *string, const str_t substr);

#endif