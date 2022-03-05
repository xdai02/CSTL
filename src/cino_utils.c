#include "cino_utils.h"

/**
 * @brief   忽略大小写比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool equals_ignore_case(const char *s1, const char *s2) {
    if (!s1 && !s2) {
        return true;
    }

    if (!s1 || !s2) {
        return false;
    }

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
 * @brief   string转bool
 * @param str   :   字符串
 * @return  返回false的情况：
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. equals_ignore_case(str, "false")
 *              4. str为全0字符串
 *          其它情况返回true。
 */
bool string_to_bool(const char *str) {
    if (!str || strlen(str) == 0 || equals_ignore_case(str, "false")) {
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
 * @brief   bool转string
 * @param val   :   bool值
 * @return  val为true返回"true"，val为false返回"false"。
 */
const char *bool_to_string(bool val) {
    return val ? "true" : "false";
}