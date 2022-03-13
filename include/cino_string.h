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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cino_utils.h"

/**
 * @brief cino字符串结构
 */
typedef struct cino_string_t cino_string_t;

/****************************************
 *            cino字符串创建
 ****************************************/

/**
 * @brief   创建cino字符串
 * @param str   :   字符串
 * @return  返回构造好的cino字符串指针，失败返回NULL。
 */
cino_string_t *cino_string_create(const char *str);

/****************************************
 *            cino字符串销毁
 ****************************************/

/**
 * @brief   销毁cino字符串
 * @param string    :   cino字符串
 */
void cino_string_destroy(cino_string_t *string);

/****************************************
 *            cino字符串操作
 ****************************************/

/**
 * @brief   获取cino字符串值
 * @param string    :   cino字符串
 * @return  cino字符串值
 */
const char *cino_string_get(const cino_string_t *string);

/**
 * @brief   设置cino字符串
 * @param string    :   cino字符串
 * @param str       :   字符串值
 * @return  cino字符串
 */
cino_string_t *cino_string_set(cino_string_t *string, const char *str);

/**
 * @brief   获取cino字符串长度
 * @param string    :   cino字符串
 * @return  cino字符串长度
 */
int cino_string_length(const cino_string_t *string);

/**
 * @brief   清空cino字符串
 * @param string    :   cino字符串
 * @return  cino字符串
 */
cino_string_t *cino_string_clear(cino_string_t *string);

/**
 * @brief   比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool cino_string_equal(const cino_string_t *s1, const cino_string_t *s2);

/**
 * @brief   忽略大小写比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool cino_string_equal_ignore_case(const cino_string_t *s1, const cino_string_t *s2);

/**
 * @brief   cino字符串转小写
 * @param string    :   cino字符串
 * @return  小写cino字符串
 */
cino_string_t *cino_string_tolower(cino_string_t *string);

/**
 * @brief   cino字符串转大写
 * @param string    :   cino字符串
 * @return  cino大写字符串
 */
cino_string_t *cino_string_toupper(cino_string_t *string);

/**
 * @brief   判断cino字符串是否以指定cino子串开头
 * @param string    :   cino字符串
 * @param prefix    :   cino子串
 * @return  如果string以prefix开头返回true，否则返回false。
 */
bool cino_string_starts_with(cino_string_t *string, cino_string_t *prefix);

/**
 * @brief   判断cino字符串是否以指定cino子串结尾
 * @param string    :   cino字符串
 * @param postfix    :   cino子串
 * @return  如果string以postfix结尾返回true，否则返回false。
 */
bool cino_string_ends_with(cino_string_t *string, cino_string_t *postfix);

/**
 * @brief   cino字符串拷贝
 * @param destination   :   目标cino字符串
 * @param source        :   源cino字符串
 * @return  返回目标cino字符串
 */
cino_string_t *cino_string_copy(cino_string_t *destination, const cino_string_t *source);

/**
 * @brief   cino字符串拼接
 * @param destination   :   目标cino字符串
 * @param source        :   源cino字符串
 * @return  返回目标cino字符串。
 */
cino_string_t *cino_string_concat(cino_string_t *destination, const cino_string_t *source);

#endif