/****************************************
 * 模块 :   cino_array
 * 功能 :   提供cino数组操作
 * 分类 :
 *          - cino数组创建
 *          - cino数组销毁
 *          - cino数组操作
 ****************************************/

#ifndef _CINO_ARRAY_H_
#define _CINO_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cino_utils.h"

/**
 * @brief cino数组结构
 */
typedef struct array_t array_t;

/****************************************
 *            cino数组创建
 ****************************************/

/**
 * @brief   创建cino数组
 * @param elem_size :   每个元素大小
 * @return  返回构造好的cino数组，失败返回NULL。
 */
array_t *array_create(int elem_size);

/****************************************
 *            cino数组销毁
 ****************************************/

/**
 * @brief   销毁cino数组
 * @param array    :   cino数组
 */
void array_destroy(array_t *array);

/****************************************
 *            cino数组操作
 ****************************************/

/**
 * @brief   获取cino数组元素个数
 * @param string    :   cino数组
 * @return  cino数组元素个数
 */
int array_length(const array_t *array);

void *array_get(const array_t *array, int index);

void array_append(array_t *array, const void *data);

#endif