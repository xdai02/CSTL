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

/**
 * @brief   创建cino字符串
 * @param str   :   字符串
 * @return  返回构造好的cino字符串指针，失败返回NULL。
 */
cino_string_t *cino_string_create(const char *str);

/**
 * @brief   销毁cino字符串
 * @param string    :   cino字符串
 */
void cino_string_destroy(cino_string_t *string);

/**
 * @brief   获取cino字符串值
 * @param string    :   cino字符串
 * @return  cino字符串值
 */
const char *cino_string_get(cino_string_t *string);

/**
 * @brief   获取cino字符串长度
 * @param string    :   cino字符串
 * @return  cino字符串长度
 */
int cino_string_length(cino_string_t *string);

/**
 * @brief   清空cino字符串
 * @param string    :   cino字符串
 */
void cino_string_clear(cino_string_t *string);

#endif