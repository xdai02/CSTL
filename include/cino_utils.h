/**************************************************
 * Module   :   cino_util
 * Function :   Generic utilities and interfaces
 * Category :
 *              - status_t
 *              - logger_t
 *              - Numeric Operation
 *              - Validity Check
 *              - Array Operation
 *              - Dynamic Memory Allocation
 *              - Type Conversion
 *              - String Operation
 **************************************************/

#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define str_t char *  // str_t == char *

typedef char byte_t;  // byte_t == char

#define iter_t void *  // iter_t == void *

/**
 * @brief   User-defined comparison function interface.
 * @param data1 pointer to the first data
 * @param data1 pointer to the second data
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
typedef int (*compare_t)(const void *data1, const void *data2);

/**
 * @brief   User-defined matching function interface.
 * @param data  pointer to the data for matching
 * @return  Returns `true` if the data matches the condition, otherwise returns
 *          `false`.
 */
typedef bool (*match_t)(const void *data);

/****************************************
 *              status_t
 ****************************************/

typedef enum status_t {
    STATUS_OK,
    STATUS_FAIL,
    STATUS_OUT_OF_MEMORY,
    STATUS_FOUND,
    STATUS_NOT_FOUND,
    STATUS_BAD_PARAMETERS,
    STATUS_IO_ERROR,
    STATUS_OUT_OF_BOUNDS,
    STATUS_UNDEFINED,
} status_t;

/****************************************
 *              logger_t
 ****************************************/

typedef enum logger_t {
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
} logger_t;

#ifdef WIN32
#define LOGGER(level, format, ...)                                                                                          \
    do {                                                                                                                    \
        if (level == NONE) {                                                                                                \
            break;                                                                                                          \
        } else if (level == DEBUG) {                                                                                        \
            fprintf(stderr, "[DEBUG] >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__); \
        } else if (level == INFO) {                                                                                         \
            fprintf(stderr, "[INFO] >>> " format "\n", __VA_ARGS__);                                                        \
        } else if (level == WARNING) {                                                                                      \
            fprintf(stderr, "[WARNING] >>> " format "\n", __VA_ARGS__);                                                     \
        } else if (level == ERROR) {                                                                                        \
            fprintf(stderr, "[ERROR] >>> " format "\n", __VA_ARGS__);                                                       \
        }                                                                                                                   \
    } while (0)
#else
#define LOGGER(level, format, args...)                                                                                 \
    do {                                                                                                               \
        if (level == NONE) {                                                                                           \
            break;                                                                                                     \
        } else if (level == DEBUG) {                                                                                   \
            fprintf(stderr, "[DEBUG] >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args); \
        } else if (level == INFO) {                                                                                    \
            fprintf(stderr, "[INFO] >>> " format "\n", ##args);                                                        \
        } else if (level == WARNING) {                                                                                 \
            fprintf(stderr, "[WARNING] >>> " format "\n", ##args);                                                     \
        } else if (level == ERROR) {                                                                                   \
            fprintf(stderr, "[ERROR] >>> " format "\n", ##args);                                                       \
        }                                                                                                              \
    } while (0)
#endif

/****************************************
 *          Numeric Operation
 ****************************************/

/**
 * @brief   Returns the smaller of two values.
 */
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * @brief   Returns the greater of two values.
 */
#define max(x, y) (((x) > (y)) ? (x) : (y))

/**
 * @brief   Swap two values of specified type.
 */
#define swap(x, y, type) \
    do {                 \
        type temp = x;   \
        x = y;           \
        y = temp;        \
    } while (0)

/**
 * @brief   Determine if two double values are equal.
 * @param x value 1
 * @param y value 2
 * @return  Returns true if two double values are equal, otherwise return false.
 */
bool equal_double(double x, double y);

/****************************************
 *            Validity Check
 ****************************************/

/**
 * @brief   Determine if the specified expression is true, return if it failed.
 */
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

/**
 * @brief   Determine if the specified expression is true, return the given value if
 *          it failed.
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

/**
 * @brief   Determine if the specified expression is true, call the specified function
 *          and return if it failed.
 */
#define call_and_return_if_fail(expr, func) \
    if (!(expr)) {                          \
        func;                               \
        return;                             \
    }

/**
 * @brief   Determine if the specified expression is true, call the specified function
 *          and return the given value if it failed.
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr)) {                                     \
        func;                                          \
        return (ret);                                  \
    }

/****************************************
 *          Array Operation
 ****************************************/

/**
 * @brief   Returns the number of elements in C array.
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

/****************************************
 *      Dynamic Memory Management
 ****************************************/

/**
 * @brief   Dynamically allocate memory of the specified byte size.
 * @note    It is caller's responsibility to `free()` after using it.
 * @param size  requested memory size in bytes
 * @return  Returns a pointer to the beginning of the block. If the function failed
 *          to allocate the requested block of memory, a null pointer is returned.
 */
void *cino_alloc(size_t size);

/**
 * @brief   Changes the size of the memory block pointed to by given pointer.
 * @note    It is caller's responsibility to `free()` after using it.
 * @param p         pointer to a memory block previously allocated
 * @param old_size  old size for the memory block in bytes
 * @param new_size  new size for the memory block in bytes
 * @return  Returns a pointer to the beginning of the block. If the function failed
 *          to allocate the requested block of memory, a null pointer is returned.
 */
void *cino_realloc(void *p, size_t old_size, size_t new_size);

/****************************************
 *            Type Conversion
 ****************************************/

/**
 * @brief   Convert string to boolean.
 * @param str   string
 * @return  Returns false if:
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. str_equal_ignore_case(str, "false")
 *              4. a string of zeros
 *          Otherwise return true.
 */
bool str_to_bool(const str_t str);

/**
 * @brief   Convert boolean to string.
 * @param val   boolean value
 * @return  Returns "true" if the boolean value is `true`, otherwise retuens "false".
 */
const str_t bool_to_str(bool val);

/**
 * @brief   Convert string to char.
 * @param str   string
 * @return  Returns the first character of the string. Returns '\0' if string is NULL.
 */
char str_to_char(const str_t str);

/**
 * @brief   Convert char to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param c         char
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return  Returns the string after conversion.
 */
str_t char_to_str(char c, str_t str, size_t str_size);

/**
 * @brief   Convert string to int.
 * @param str   string
 * @return  Returns 0 if str == NULL, otherwise returns the result given by `atoi()`.
 */
int str_to_int(const str_t str);

/**
 * @brief   Convert int to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param val       int value
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return   Returns the string after conversion.
 */
str_t int_to_str(int val, str_t str, size_t str_size);

/**
 * @brief   Convert string to double.
 * @param str   string
 * @return  Returns 0.0 if str == NULL，otherwise returns the result given `atof()`.
 */
double str_to_double(const str_t str);

/**
 * @brief   Convert double to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param val           double value
 * @param precision     number of decimal places when rounding (default=2, max=16)
 * @param str           string used to store the result after conversion
 * @param str_size      sizeof(str)
 * @return  Returns the string after conversion.
 */
str_t double_to_str(double val, int precision, str_t str, size_t str_size);

/****************************************
 *          String Operation
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
 * @brief   Find the first occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the first occurrence of the specified
 *          character, or -1 if the character is not found.
 */
int str_index_of_char(const str_t str, char c);

/**
 * @brief   Find the first occurrence of the specified character, starting the
 *          search at the specified index.
 * @param str   string
 * @param c     char
 * @param from  start index for searching
 * @return  Returns the index within the string of the first occurrence of the specified
 *          character, starting the search at the specified index, or -1 if the
 *          character is not found.
 */
int str_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   Find the first occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the first occurrence of the specified
 *          substring, or -1 if the substring is not found.
 */
int str_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   Find the first occurrence of the specified substring, starting the
 *          search at the specified index.
 * @param str       string
 * @param substr    substring
 * @param from      start index for searching
 * @return  Returns the index within the string of the first occurrence of the specified
 *          substring, starting the search at the specified index, or -1 if the
 *          substring is not found.
 */
int str_index_of_substring_from(const str_t str, const str_t substr, int from);

/**
 * @brief   Find the last occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the last occurrence of the specified
 *          character, or -1 if the character is not found.
 */
int str_last_index_of_char(const str_t str, char c);

/**
 * @brief   Find the last occurrence of the specified character, searching backward
 *          starting at the specified index.
 * @param str   string
 * @param c     char
 * @param from  start index for searching
 * @return  Returns the index within the string of the last occurrence of the specified
 *          character, searching backward starting at the specified index, or -1 if the
 *          character is not found.
 */
int str_last_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   Find the last occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the last occurrence of the specified
 *          substring, or -1 if the substring is not found.
 */
int str_last_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   Find the last occurrence of the specified substring, searching backward
 *          starting at the specified index.
 * @param str       string
 * @param substr    substring
 * @param from  start index for searching
 * @return  Returns the index within the string of the last occurrence of the specified
 *          substring, searching backward starting at the specified index, or -1 if the
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