/****************************************
 * 模块 :   cino_util
 * 功能 :   提供常用操作接口
 * 分类 :
 *          - 合法性检查
 *          - 数组操作
 *          - 类型转换
 *          - 字符串操作
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
 * @return   转换后字符串
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
 * @return   转换后字符串
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
 * @return   转换后字符串
 */
char *double_to_string(double val, int precision, char *str, int str_size);

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
 * @brief   字符串转小写
 * @param str   :   字符串
 * @return  小写字符串
 */
char *string_tolower(char *str);

/**
 * @brief   字符串转大写
 * @param str   :   字符串
 * @return  大写字符串
 */
char *string_toupper(char *str);

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
 * @return  返回目标字符串
 */
char *string_copy(char *destination, const char *source);

/**
 * @brief   字符串拼接
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串
 */
char *string_concat(char *destination, const char *source);

/**
 * @brief   去除字符串首尾空白字符
 * @param str   :   字符串
 * @return  新字符串
 */
char *string_trim(char *str);

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

/**
 * @brief   在字符串指定位置插入字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param pos   :   插入位置（从0开始）
 * @param c     :   字符
 * @return  新字符串
 */
char *string_insert_char(char *str, int pos, char c);

/**
 * @brief   在字符串指定位置插入子串
 * @note    调用者需要确保str的长度足够。
 * @param str       :   字符串
 * @param pos       :   插入位置（从0开始）
 * @param substr    :   子串
 * @return  新字符串
 */
char *string_insert_string(char *str, int pos, const char *substr);

/**
 * @brief   截取字符串指定范围子串
 * @note    调用者需要确保substr分配了足够的空间、substr_size的长度正确。
 * @param str           :   主串
 * @param start         :   开始下标
 * @param end           :   结束下标
 * @param substr        :   保存子串
 * @param substr_size   :   sizeof(substr)
 * @return  返回[start, end]返回的子串，start或end不合法返回空串。
 */
char *string_substring(char *str, int start, int end, char *substr, int substr_size);

/**
 * @brief   全部替换字符串中指定字符
 * @param str       :   字符串
 * @param old_char  :   被替换字符
 * @param new_char  :   新字符
 * @return  新字符串
 */
char *string_replace_char(char *str, char old_char, char new_char);

/**
 * @brief   全部替换字符串中指定子串
 * @param str       :   字符串
 * @param old_str	:   被替换子串
 * @param new_str	:   新串
 * @return  新字符串
 */
char *string_replace(char *str, const char *old_str, const char *new_str);

/**
 * @brief   字符串删除指定子串
 * @param str       :   字符串
 * @param substr	:   子串
 * @return  新字符串
 */
char *string_remove(char *str, const char *substr);

/**
 * @brief   字符串中查找首次出现指定字符的下标
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符首次出现的下标，不存在返回-1。
 */
int string_index_of_char(const char *str, char c);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定字符的下标
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始查找下标
 * @return  返回字符从指定位置开始首次出现的下标，不存在返回-1。
 */
int string_index_of_char_from(const char *str, char c, int from);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串首次出现的下标，不存在返回-1。
 */
int string_index_of_substring(const char *str, const char *substr);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始首次出现的下标，不存在返回-1。
 */
int string_index_of_substring_from(const char *str, const char *substr, int from);

/**
 * @brief   字符串中查找最后一次出现指定字符的下标
 * @note    空串中查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符最后一次出现的下标，不存在返回-1。
 */
int string_last_index_of_char(const char *str, char c);

/**
 * @brief   字符串中查找从开始位置向前最后一次出现指定字符的下标
 * @note    空串中从0开始查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始下标
 * @return  返回字符从开始位置向前最后一次出现的下标，不存在返回-1。
 */
int string_last_index_of_char_from(const char *str, char c, int from);

/**
 * @brief   字符串中查找最后一次出现指定子串的下标
 * @note    空串中查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串最后一次出现的下标，不存在返回-1。
 */
int string_last_index_of_substring(const char *str, const char *substr);

/**
 * @brief   字符串中查找从指定位置开始向前最后一次出现指定子串的下标
 * @note    空串中从0开始查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始向前最后一次出现的下标，不存在返回-1。
 */
int string_last_index_of_substring_from(const char *str, const char *substr, int from);

/**
 * @brief   字符串分割
 * @note    调用者需要确保字符串数组items的空间分配正确。
 * @param str       :   字符串
 * @param delimiter :   分割串
 * @param items     :   保存分割后子串的二维数组
 * @return  返回分割后产生的子串数量。
 */
int string_split(const char *str, const char *delimiter, char **items);

#endif