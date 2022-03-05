#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @brief   判断表达式expr是否成立，不成立直接返回。
 */
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

/**
 * @brief   判断表达式expr是否成立，不成立返回ret。
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

/**
 * @brief   判断表达式expr是否成立，不成立调用func后返回。
 */
#define call_and_return_if_fail(expr, func) \
    if (!(expr)) {                          \
        func;                               \
        return;                             \
    }

/**
 * @brief   判断表达式expr是否成立，不成立调用func后返回ret。
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr)) {                                     \
        func;                                          \
        return (ret);                                  \
    }

/**
 * @brief   获取C数组元素个数
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

/**
 * @brief   忽略大小写比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool equals_ignore_case(const char *s1, const char *s2);

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
bool string_to_bool(const char *str);

/**
 * @brief   bool转string
 * @param val   :   bool值
 * @return  val为true返回"true"，val为false返回"false"。
 */
const char *bool_to_string(bool val);

#endif