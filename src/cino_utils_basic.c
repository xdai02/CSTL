#include "cino_utils_basic.h"

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
 *              3. str == "false" || str == "FALSE" || str == "False"
 *          Otherwise returns `true`.
 */
bool str_to_bool(const str_t str) {
    return str != NULL && strlen(str) > 0 && strncmp(str, "false", strlen(str)) != 0 && strncmp(str, "FALSE", strlen(str)) != 0 && strncmp(str, "False", strlen(str)) != 0;
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