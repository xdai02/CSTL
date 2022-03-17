/****************************************
 * 模块 :   cino_array
 * 功能 :   提供cino数组操作
 * 分类 :
 *          - cino int数组
 ****************************************/

#ifndef _CINO_ARRAY_H_
#define _CINO_ARRAY_H_

#include "cino_utils.h"

/**
 * @brief cino int数组结构
 */
typedef struct array_int_t array_int_t;

/****************************************
 *          cino int数组创建
 ****************************************/

/**
 * @brief   创建cino int数组
 * @return  返回构造好的cino int数组，失败返回NULL。
 */
array_int_t *array_int_create();

/****************************************
 *          cino int数组销毁
 ****************************************/

/**
 * @brief   销毁cino int数组
 * @param array    :   cino int数组
 */
void array_int_destroy(array_int_t *array);

// /**
//  * @brief cino数组结构
//  */
// typedef struct array_t array_t;

// /****************************************
//  *            cino数组创建
//  ****************************************/

// /**
//  * @brief   创建cino数组
//  * @param elem_size :   每个元素大小
//  * @return  返回构造好的cino数组，失败返回NULL。
//  */
// array_t *array_create(int elem_size);

// /****************************************
//  *            cino数组销毁
//  ****************************************/

// /**
//  * @brief   销毁cino数组
//  * @param array    :   cino数组
//  */
// void array_destroy(array_t *array);

// /****************************************
//  *            cino数组操作
//  ****************************************/

// /**
//  * @brief   获取cino数组元素个数
//  * @param array :   cino数组
//  * @return  cino数组元素个数
//  */
// int array_size(const array_t *array);

// void *array_get(const array_t *array, int index);

// void array_append(array_t *array, const void *data);

#endif