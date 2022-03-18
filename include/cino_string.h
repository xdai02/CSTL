/****************************************
 * 模块 :   cino_string
 * 功能 :   提供cino字符串操作
 * 分类 :
 *          - cino字符串创建
 *          - cino字符串销毁
 *          - cino字符串操作
 ****************************************/

#ifndef _CINO_STRING_H_
#define _CINO_STRING_H_

#include "cino_utils.h"

/**
 * @brief cino字符串结构
 */
typedef struct string_t string_t;

/****************************************
 *            cino字符串创建
 ****************************************/

/**
 * @brief   创建cino字符串
 * @param str   :   字符串
 * @return  返回构造好的cino字符串指针，失败返回NULL。
 */
string_t *string_create(const char *str);

/****************************************
 *            cino字符串销毁
 ****************************************/

/**
 * @brief   销毁cino字符串
 * @param string    :   cino字符串
 */
void string_destroy(string_t *string);

/****************************************
 *            cino字符串操作
 ****************************************/

/**
 * @brief   获取cino字符串值
 * @param string    :   cino字符串
 * @return  cino字符串值
 */
const char *string_get(const string_t *string);

/**
 * @brief   设置cino字符串
 * @param string    :   cino字符串
 * @param str       :   字符串值
 * @return  cino字符串
 */
string_t *string_set(string_t *string, const char *str);

/**
 * @brief   获取cino字符串长度
 * @param string    :   cino字符串
 * @return  cino字符串长度
 */
int string_length(const string_t *string);

/**
 * @brief   清空cino字符串
 * @param string    :   cino字符串
 * @return  cino字符串
 */
string_t *string_clear(string_t *string);

/**
 * @brief   比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool string_equal(const string_t *s1, const string_t *s2);

/**
 * @brief   忽略大小写比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool string_equal_ignore_case(const string_t *s1, const string_t *s2);

/**
 * @brief   cino字符串转小写
 * @param string    :   cino字符串
 * @return  小写cino字符串
 */
string_t *string_to_lower(string_t *string);

/**
 * @brief   cino字符串转大写
 * @param string    :   cino字符串
 * @return  cino大写字符串
 */
string_t *string_to_upper(string_t *string);

/**
 * @brief   判断cino字符串是否以指定子串开头
 * @param string    :   cino字符串
 * @param prefix    :   子串
 * @return  如果string以prefix开头返回true，否则返回false。
 */
bool string_starts_with(const string_t *string, const str_t prefix);

/**
 * @brief   判断cino字符串是否以指定子串结尾
 * @param string    :   cino字符串
 * @param postfix   :   子串
 * @return  如果string以postfix结尾返回true，否则返回false。
 */
bool string_ends_with(const string_t *string, const str_t postfix);

/**
 * @brief   cino字符串拷贝
 * @param destination   :   目标cino字符串
 * @param source        :   源cino字符串
 * @return  返回目标cino字符串
 */
string_t *string_copy(string_t *destination, const string_t *source);

/**
 * @brief   cino字符串拼接
 * @param destination   :   目标cino字符串
 * @param source        :   源cino字符串
 * @return  返回目标cino字符串。
 */
string_t *string_concat(string_t *destination, const string_t *source);

/**
 * @brief   去除cino字符串首尾空白字符
 * @param string    :   cino字符串
 * @return  新cino字符串
 */
string_t *string_trim(string_t *string);

/**
 * @brief   cino字符串追加字符
 * @param string    :   cino字符串
 * @param c         :   字符
 * @return  新cino字符串
 */
string_t *string_append_char(string_t *string, char c);

/**
 * @brief   在cino字符串指定位置插入字符
 * @param string    :   cino字符串
 * @param pos       :   插入位置（从0开始）
 * @param c         :   字符
 * @return  新cino字符串
 */
string_t *string_insert_char(string_t *string, int pos, char c);

/**
 * @brief   在cino字符串指定位置插入子串
 * @param string    :   cino字符串
 * @param pos       :   插入位置（从0开始）
 * @param substr    :   子串
 * @return  新cino字符串
 */
string_t *string_insert_string(string_t *string, int pos, const str_t substr);

/**
 * @brief   计算指定子串出现次数
 * @param  string   :   cino主串
 * @param  substr   :   子串
 * @retval  子串出现次数
 */
int string_count_substring(const string_t *string, const str_t substr);

/**
 * @brief   全部替换cino字符串中指定字符
 * @param string    :   cino字符串
 * @param old_char  :   被替换字符
 * @param new_char  :   新字符
 * @return  新cino字符串
 */
string_t *string_replace_char(string_t *string, char old_char, char new_char);

/**
 * @brief   全部替换cino字符串中指定子串
 * @param string    :   cino字符串
 * @param old_str	:   被替换子串
 * @param new_str	:   新串
 * @return  新cino字符串
 */
string_t *string_replace(string_t *string, const str_t old_str, const str_t new_str);

/**
 * @brief   cino字符串删除指定子串
 * @param string    :   cino字符串
 * @param substr	:   子串
 * @return  新cino字符串
 */
string_t *string_remove(string_t *string, const str_t substr);

#endif