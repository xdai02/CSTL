#include "cino_utils.h"

/**
 * @brief   Case insensitive string comparion
 * @param s1    :   string 1
 * @param s2    :   string 2
 * @return  Return `true` if `s1` is the same as `s2` ignoring case, 
 *          otherwise return `false`.
 */
bool equals_ignore_case(const char *s1, const char *s2)
{
    if (!s1 && !s2)
    {
        return true;
    }

    if (!s1 || !s2)
    {
        return false;
    }

    while (*s1)
    {
        if (tolower(*s1) != tolower(*s2))
        {
            return false;
        }
        s1++;
        s2++;
    }

    return *s1 == *s2;
}

/**
 * @brief   Convert string to boolean
 * @param str   :   string
 * @return  Return `false` if `str` is NULL, or strlen(str) == 0, or 
 *          `str` equals "false" ignoring case, otherwise return `true`.
 */
bool string_to_bool(const char *str)
{
    return str && strlen(str) > 0 && !equals_ignore_case(str, "false");
}

/**
 * @brief   Convert boolean to string
 * @param val   :   boolean value
 * @return  Return "true" or "false" based on `val`.
 */
const char *bool_to_string(bool val)
{
    return val ? "true" : "false";
}