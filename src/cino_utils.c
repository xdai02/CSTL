#include "cino_utils.h"

/****************************************
 *          Numeric Operation
 ****************************************/

/**
 * @brief   Determine if two double values are equal.
 * @param x value 1
 * @param y value 2
 * @return  Returns true if two double values are equal, otherwise return false.
 */
bool equal_double(double x, double y) {
    return fabs(x - y) < 1e-6;
}

/****************************************
 *            Type Conversion
 ****************************************/

/**
 * @brief   Convert string to boolean.
 * @param str   string
 * @return  Returns `false` if:
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. str_equal_ignore_case(str, "false")
 *              4. a string of zeroes
 *          Otherwise returns `true`.
 */
bool str_to_bool(const str_t str) {
    if (!str || strlen(str) == 0 || str_equal_ignore_case(str, "false")) {
        return false;
    }

    while (*str) {
        if (*str != '0') {
            return true;
        }
        str++;
    }

    return false;
}

/**
 * @brief   Convert boolean to string.
 * @param val   boolean value
 * @return  Returns "true" if the boolean value is `true`, otherwise returns "false".
 */
const str_t bool_to_str(bool val) {
    return val ? "true" : "false";
}

/**
 * @brief   Convert string to char.
 * @param str   string
 * @return  Returns the first character of the string, or '\0' if string is NULL.
 */
char str_to_char(const str_t str) {
    return_value_if_fail(str != NULL, '\0');
    return str[0];
}

/**
 * @brief   Convert char to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param c         char
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return  Returns the string after conversion.
 */
str_t char_to_str(char c, str_t str, size_t str_size) {
    return_value_if_fail(str != NULL && str_size >= 2, NULL);
    memset(str, '\0', str_size);
    str[0] = c;
    str[1] = '\0';
    return str;
}

/**
 * @brief   Convert string to int.
 * @param str   string
 * @return  Returns 0 if str == NULL, otherwise returns the result given by atoi().
 */
int str_to_int(const str_t str) {
    return_value_if_fail(str != NULL, 0);
    return atoi(str);
}

/**
 * @brief   Convert int to string.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param val       int value
 * @param str       string used to store the result after conversion
 * @param str_size  sizeof(str)
 * @return   Returns the string after conversion.
 */
str_t int_to_str(int val, str_t str, size_t str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);
    memset(str, '\0', str_size);
    snprintf(str, str_size, "%d", val);
    return str;
}

/**
 * @brief   Convert string to double.
 * @param str   string
 * @return  Returns 0.0 if str == NULL，otherwise returns the result given `atof()`.
 */
double str_to_double(const str_t str) {
    return_value_if_fail(str != NULL, 0.0);
    return atof(str);
}

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
str_t double_to_str(double val, int precision, str_t str, size_t str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);

    const int MIN_PRECISION = 0;
    const int MAX_PRECISION = 16;
    const int DEFAULT_PRECISION = 2;
    if (precision < MIN_PRECISION || precision > MAX_PRECISION) {
        precision = DEFAULT_PRECISION;
    }

    memset(str, '\0', str_size);
    char format[8] = {0};
    snprintf(format, sizeof(format), "%%.%df", precision);
    snprintf(str, str_size, format, val);

    return str;
}

/****************************************
 *               Wrapper
 ****************************************/

/**
 * @brief   Get the wrapper type for int
 * @param data  int value
 * @return  Returns the wrapper type for int, or `NULL` if fails.
 */
wrapper_int_t *wrap_int(int data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)calloc(1, sizeof(wrapper_int_t));
    return_value_if_fail(wrapper != NULL, NULL);
    wrapper->data = data;
    return wrapper;
}

/**
 * @brief   Unwrap and free wrapper_int_t.
 * @param wrapper   wrapper_int_t
 * @return  Returns the primitive int data.
 */
int unwrap_int(wrapper_int_t *wrapper) {
    if (!wrapper) {
        LOGGER(ERROR, "Null pointer exception.");
        return STATUS_BAD_PARAMETERS;
    }
    int data = wrapper->data;
    free(wrapper);
    wrapper = NULL;
    return data;
}

/**
 * @brief   Get the wrapper type for double
 * @param data  double value
 * @return  Returns the wrapper type for double, or `NULL` if fails.
 */
wrapper_double_t *wrap_double(double data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)calloc(1, sizeof(wrapper_double_t));
    return_value_if_fail(wrapper != NULL, NULL);
    wrapper->data = data;
    return wrapper;
}

/**
 * @brief   Unwrap and free wrapper_double_t.
 * @param wrapper   wrapper_double_t
 * @return  Returns the primitive double data.
 */
double unwrap_double(wrapper_double_t *wrapper) {
    if (!wrapper) {
        LOGGER(ERROR, "Null pointer exception.");
        return STATUS_BAD_PARAMETERS;
    }
    double data = wrapper->data;
    free(wrapper);
    wrapper = NULL;
    return data;
}

/****************************************
 *          String Operation
 ****************************************/

/**
 * @brief   Determine if two strings are equal.
 * @param s1    string 1
 * @param s2    string 2
 * @return  Returns true if two strings are equal, otherwise returns false.
 */
bool str_equal(const str_t s1, const str_t s2) {
    return_value_if_fail(s1 != NULL && s2 != NULL, false);
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    return strncmp(s1, s2, strlen(s1)) == 0;
}

/**
 * @brief   Determine if two strings are equal, ignoring case considerations.
 * @param s1    string 1
 * @param s2    string 2
 * @return  Returns true if two strings are equal ignoring case considerations, otherwise
 *          returns false.
 */
bool str_equal_ignore_case(const str_t s1, const str_t s2) {
    return_value_if_fail(s1 != NULL && s2 != NULL, false);

    while (*s1) {
        if (tolower(*s1) != tolower(*s2)) {
            return false;
        }
        s1++;
        s2++;
    }

    return *s1 == *s2;
}

/**
 * @brief   Converts all of the characters to lower case
 * @param str   string
 * @return  String in lower case.
 */
str_t str_to_lower(str_t str) {
    return_value_if_fail(str != NULL, NULL);

    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }

    return str;
}

/**
 * @brief   Converts all of the characters to upper case
 * @param str   string
 * @return  String in upper case.
 */
str_t str_to_upper(str_t str) {
    return_value_if_fail(str != NULL, NULL);

    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    return str;
}

/**
 * @brief   Tests if the string starts with the specified prefix.
 * @param str       string
 * @param prefix    prefix string
 * @return  Returns true if the string starts with the specified prefix, otherwise
 *          returns false.
 */
bool str_starts_with(const str_t str, const str_t prefix) {
    return_value_if_fail(str != NULL && prefix != NULL, false);
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

/**
 * @brief   Tests if the string ends with the specified suffix.
 * @param str       string
 * @param suffix    suffix string
 * @return  Returns true if `str` ends with `postfix`, otherwise returns false.
 */
bool str_ends_with(const str_t str, const str_t suffix) {
    return_value_if_fail(str != NULL && suffix != NULL, false);

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    int offset = str_len - suffix_len;
    return_value_if_fail(offset >= 0, false);

    return strncmp(str + offset, suffix, strlen(suffix)) == 0;
}

/**
 * @brief   Reset string with '\0'.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          and its size.
 * @param str       string
 * @param str_size  sizeof(str)
 */
void str_clear(str_t str, size_t str_size) {
    return_if_fail(str != NULL && str_size > 0);
    memset(str, '\0', str_size);
}

/**
 * @brief   Returns the length of the string.
 * @param str   string
 * @return  Returns the length of the string. Returns 0 if stirng is NULL.
 */
size_t str_length(const str_t str) {
    return_value_if_fail(str != NULL, 0);
    return strlen(str);
}

/**
 * @brief   String copy.
 * @note    It is caller's responsibility to ensure the validity of the passing strings.
 * @param destination   destination string
 * @param source        source string
 * @return  Returns destination string.
 */
str_t str_copy(str_t destination, const str_t source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);

    strncpy(destination, source, strlen(source));
    destination[strlen(source)] = '\0';
    return destination;
}

/**
 * @brief   String concatenate.
 * @note    It is caller's responsibility to ensure the validity of the passing strings.
 * @param destination   destination string
 * @param source        source string
 * @return  Returns destination string.
 */
str_t str_concat(str_t destination, const str_t source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);

    size_t dest_len = strlen(destination);
    size_t src_len = strlen(source);
    strncat(destination, source, src_len);
    destination[dest_len + src_len] = '\0';
    return destination;
}

/**
 * @brief   Removes leading and trailing whitespaces.
 * @param str   string
 * @return  Returns a string with any leading and trailing whitespace removed.
 */
str_t str_trim(str_t str) {
    return_value_if_fail(str != NULL, NULL);

    str_t cur = str;
    str_t end = str + strlen(str) - 1;

    while (isspace(*cur)) {
        cur++;
    }

    // all whitespaces
    if (*cur == '\0') {
        memset(str, '\0', end - str + 1);
        return str;
    }

    if (cur != str) {
        memmove(str, cur, end - cur + 1);
        *end = '\0';
        end--;
    }

    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';

    return str;
}

/**
 * @brief   Append a char to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param c     char
 * @return  Returns the modified string.
 */
str_t str_append_char(str_t str, char c) {
    return_value_if_fail(str != NULL, NULL);
    size_t len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
    return str;
}

/**
 * @brief   Append an int to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param val   int value
 * @return  Returns the modified string.
 */
str_t str_append_int(str_t str, int val) {
    return_value_if_fail(str != NULL, NULL);
    char str_val[12] = {0};
    int_to_str(val, str_val, sizeof(str_val));
    str_concat(str, str_val);
    return str;
}

/**
 * @brief   Append a double to the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str       string
 * @param val       double value
 * @param precision number of decimal places when rounding (default=2, max=16)
 * @return  Returns the modified string.
 */
str_t str_append_double(str_t str, double val, int precision) {
    return_value_if_fail(str != NULL, NULL);
    char str_val[64] = {0};
    double_to_str(val, precision, str_val, sizeof(str_val));
    str_concat(str, str_val);
    return str;
}

/**
 * @brief   Insert a char into the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str   string
 * @param index insert position
 * @param c     char
 * @return  Returns the modified string.
 */
str_t str_insert_char(str_t str, int index, char c) {
    return_value_if_fail(str != NULL && index >= 0 && index <= strlen(str), str);
    memmove(str + index + 1, str + index, strlen(str + index));
    str[index] = c;
    return str;
}

/**
 * @brief   Insert a string into the string.
 * @note    It is caller's responsibility to ensure the validity of the passing string.
 * @param str       string
 * @param index     insert position
 * @param substr    inserted string
 * @return  Returns the modified string.
 */
str_t str_insert_string(str_t str, int index, const str_t substr) {
    return_value_if_fail(str != NULL && index >= 0 && index <= strlen(str) && substr != NULL, str);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    memmove(str + index + substr_len, str + index, strlen(str + index));
    memcpy(str + index, substr, substr_len);
    str[str_len + substr_len] = '\0';

    return str;
}

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
str_t str_substring(str_t str, int start, int end, str_t substr, size_t substr_size) {
    return_value_if_fail(str != NULL && substr != NULL && substr_size > 0, NULL);

    memset(substr, '\0', substr_size);

    size_t str_len = strlen(str);
    start = start >= 0 ? start : 0;
    start = start < str_len ? start : str_len - 1;
    end = end < str_len ? end : str_len - 1;
    end = end >= 0 ? end : 0;

    return_value_if_fail(end >= start, substr);

    strncpy(substr, str + start, end - start + 1);
    return substr;
}

/**
 * @brief   Count the number of substring occurrences.
 * @param str       string
 * @param substr    substring
 * @return  The number of substring occurrences.
 */
int str_count_substring(const str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, 0);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (str_len == 0 && substr_len == 0) {
        return 1;
    }
    return_value_if_fail(substr_len > 0, 0);

    int cnt = 0;
    const str_t p = str;
    while ((p = strstr(p, substr))) {
        cnt++;
        p += substr_len;
    }
    return cnt;
}

/**
 * @brief   Replacing all occurrences of old char with new char.
 * @param str       string
 * @param old_char  old char
 * @param new_char  new char
 * @return  Returns the modified string.
 */
str_t str_replace_char(str_t str, char old_char, char new_char) {
    return_value_if_fail(str != NULL, NULL);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
        i++;
    }

    return str;
}

/**
 * @brief   Replacing all occurrences of old string with new string.
 * @param str       string
 * @param old_str   old string
 * @param new_str   new string
 * @return  Returns the modified string.
 */
str_t str_replace(str_t str, const str_t old_str, const str_t new_str) {
    return_value_if_fail(str != NULL && old_str != NULL && new_str != NULL, str);

    str_t p = NULL;
    while ((p = strstr(str, old_str))) {
        memmove(p + strlen(new_str), p + strlen(old_str), strlen(p) - strlen(old_str) + 1);
        memcpy(p, new_str, strlen(new_str));
    }

    return str;
}

/**
 * @brief   Removing all occurrences of the given substring.
 * @param str       string
 * @param substr    string to be removed
 * @return  Returns the modified string.
 */
str_t str_remove(str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, str);

    size_t substr_len = strlen(substr);
    if (substr_len > 0) {
        str_t p = str;
        size_t size = 0;
        while ((p = strstr(p, substr))) {
            size = (size == 0) ? p - str + strlen(p + substr_len) + 1 : size - substr_len;
            memmove(p, p + substr_len, size - (p - str));
        }
    }

    return str;
}

/**
 * @brief   Reverse the order of the string.
 * @param str   string
 * @return  Returns the modified string.
 */
str_t str_reverse(str_t str) {
    return_value_if_fail(str != NULL, NULL);
    size_t str_len = strlen(str);
    for (int i = 0; i < str_len / 2; i++) {
        swap(str[i], str[str_len - i - 1], char);
    }
    return str;
}

/**
 * @brief   Find the first occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the first occurrence of the specified
 *          character, or `-1` if the character is not found.
 */
int str_index_of_char(const str_t str, char c) {
    return_value_if_fail(str != NULL, -1);

    size_t str_len = strlen(str);
    if (str_len == 0 && c == '\0') {
        return 0;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }

    return -1;
}

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
int str_index_of_char_from(const str_t str, char c, int from) {
    return_value_if_fail(str != NULL, -1);

    size_t str_len = strlen(str);
    if (str_len == 0 && c == '\0' && from == 0) {
        return 0;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    int i = from;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }

    return -1;
}

/**
 * @brief   Find the first occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the first occurrence of the specified
 *          substring, or `-1` if the substring is not found.
 */
int str_index_of_substring(const str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (str_len == 0 && substr_len == 0) {
        return 0;
    } else if (substr_len == 0) {
        return -1;
    }

    const str_t p = strstr(str, substr);
    return p ? p - str : -1;
}

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
int str_index_of_substring_from(const str_t str, const str_t substr, int from) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (str_len == 0 && substr_len == 0 && from == 0) {
        return 0;
    } else if (substr_len == 0) {
        return -1;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    const str_t p = strstr(str + from, substr);
    return p ? p - str : -1;
}

/**
 * @brief   Find the last occurrence of the specified character.
 * @param str   string
 * @param c     char
 * @return  Returns the index within the string of the last occurrence of the specified
 *          character, or `-1` if the character is not found.
 */
int str_last_index_of_char(const str_t str, char c) {
    return_value_if_fail(str != NULL, -1);

    size_t str_len = strlen(str);
    if (str_len == 0 && c == '\0') {
        return 0;
    }

    int i = str_len - 1;
    while (i >= 0 && str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i--;
    }

    return -1;
}

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
int str_last_index_of_char_from(const str_t str, char c, int from) {
    return_value_if_fail(str != NULL, -1);

    size_t str_len = strlen(str);
    if (str_len == 0 && c == '\0' && from == 0) {
        return 0;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    int i = from;
    while (i >= 0 && str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i--;
    }

    return -1;
}

/**
 * @brief   Find the last occurrence of the specified substring.
 * @param str       string
 * @param substr    substring
 * @return  Returns the index within the string of the last occurrence of the specified
 *          substring, or `-1` if the substring is not found.
 */
int str_last_index_of_substring(const str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (str_len == 0 && substr_len == 0) {
        return 0;
    } else if (substr_len == 0) {
        return -1;
    }

    for (const str_t p = str + str_len - substr_len; p >= str; p--) {
        if (strncmp(p, substr, substr_len) == 0) {
            return p - str;
        }
    }

    return -1;
}

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
int str_last_index_of_substring_from(const str_t str, const str_t substr, int from) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (str_len == 0 && substr_len == 0 && from == 0) {
        return 0;
    } else if (substr_len == 0) {
        return -1;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    for (str_t p = (str_t)str + from - substr_len + 1; p >= str; p--) {
        if (strncmp(p, substr, substr_len) == 0) {
            return p - str;
        }
    }

    return -1;
}

/**
 * @brief   Splits the string around matches of the given delimiter.
 * @note    It is caller's responsibility to ensure the validity of the passing string
 *          array of items
 * @param str           string
 * @param delimiter     delimiter
 * @param items         string array used to store the substrings
 * @return  Returns the number of splits.
 */
int str_split(const str_t str, const str_t delimiter, str_t *items) {
    return_value_if_fail(str != NULL && delimiter != NULL && items != NULL, 0);

    size_t str_len = strlen(str);
    size_t delimiter_len = strlen(delimiter);

    int cnt = 0;

    const str_t end = str + str_len - 1;
    const str_t p = NULL;

    while ((p = strstr(str, delimiter))) {
        if (p - str == 0) {
            str += delimiter_len;
        } else {
            strncpy(items[cnt], str, p - str);
            items[cnt][p - str] = '\0';
            cnt++;
            str = p + delimiter_len;
        }
    }

    if (str < end) {
        strncpy(items[cnt], str, end - str + 1);
        items[cnt][end - str + 1] = '\0';
        cnt++;
    }

    return cnt;
}
