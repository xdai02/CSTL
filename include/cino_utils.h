/****************************************
 * 模块 :   cino_util
 * 功能 :   提供常用操作接口
 * 分类 :
 *          - 合法性检查
 *          - 数组操作
 *          - 字符串操作
 *          - 类型转换
****************************************/

#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/****************************************
 *              合法性检查
****************************************/

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

/****************************************
 *              数组操作
****************************************/

/**
 * @brief   获取C数组元素个数
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

/****************************************
 *              字符串操作
****************************************/

/**
 * @brief   比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool string_equal(const char *s1, const char *s2);

/**
 * @brief   忽略大小写比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool equals_ignore_case(const char *s1, const char *s2);

/**
 * @brief   判断字符串是否以指定子串开头
 * @param str       :   字符串
 * @param prefix    :   子串
 * @return  如果str以prefix开头返回true，否则返回false。
 */
bool string_starts_with(const char *str, const char *prefix);

/**
 * @brief   判断字符串是否以指定子串结尾
 * @param str       :   字符串
 * @param postfix   :   子串
 * @return  如果str以postfix结尾返回true，否则返回false。
 */
bool string_ends_with(const char *str, const char *postfix);

/**
 * @brief   清空字符串
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param str       :   字符串
 * @param str_size  :   sizeof(str)
 */
void string_clear(char *str, int str_size);

/**
 * @brief   计算字符串长度
 * @param str   :   字符串
 * @return  str为NULL返回0，否则返回字符串长度。
 */
int string_length(const char *str);

/**
 * @brief   字符串拷贝
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串。
 */
char *string_copy(char *destination, const char *source);

/**
 * @brief   字符串拼接
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串。
 */
char *string_concat(char *destination, const char *source);

/**
 * @brief   字符串追加字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param c     :   字符
 * @return  新字符串
 */
char *string_append_char(char *str, char c);

/**
 * @brief   字符串追加int
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param val   :   int值
 * @return  新字符串
 */
char *string_append_int(char *str, int val);

/**
 * @brief   字符串追加double
 * @note    调用者需要确保str的长度足够。
 * @param str           :   字符串
 * @param val           :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @return  新字符串
 */
char *string_append_double(char *str, double val, int precision);

/****************************************
 *              类型转换
****************************************/

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

/**
 * @brief   string转char
 * @param  str  :   保存转换结果的字符串
 * @return  如果str == NULL返回'\0'，否则返回str的第一个字符。
 */
char string_to_char(const char *str);

/**
 * @brief   char转string
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  c            :   字符
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串。
 */
char *char_to_string(char c, char *str, int str_size);

/**
 * @brief   string转int
 * @param str   :   字符串
 * @return  当str == NULL时返回0，其它情况返回atoi()的结果。
 */
int string_to_int(const char *str);

/**
 * @brief   int转string
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val      :   int值
 * @param  str      :   保存转换结果的字符串
 * @param  str_size :   sizeof(str)
 * @return   转换后字符串。
 */
char *int_to_string(int val, char *str, int str_size);

/**
 * @brief   string转double
 * @param str   :   字符串
 * @return  当str == NULL时返回0.0，其它情况返回atof()的结果。
 */
double string_to_double(const char *str);

/**
 * @brief   double转string
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val          :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串。
 */
char *double_to_string(double val, int precision, char *str, int str_size);

#endif