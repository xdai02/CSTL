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

/****************************************
 *          cino int数组操作
 ****************************************/

/**
 * @brief   判断cino int数组是否为空
 * @param array :   cino int数组
 * @return  空数组返回true，非空返回false。
 */
bool array_int_is_empty(const array_int_t *array);

/**
 * @brief   获取cino int数组元素个数
 * @param array :   cino int数组
 * @return  cino int数组元素个数
 */
int array_int_size(const array_int_t *array);

/**
 * @brief   清空cino int数组
 * @param array :   cino int数组
 * @return  清空后的cino int数组
 */
array_int_t *array_int_clear(array_int_t *array);

/**
 * @brief   获取cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @return  cino int数组指定下标元素
 */
int array_int_get(const array_int_t *array, int index);

/**
 * @brief   更新cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @param data  :   新元素
 */
void array_int_set(array_int_t *array, int index, int data);

/**
 * @brief   cino int数组末尾追加元素
 * @param array :   cino int数组
 * @param data  :   新元素
 * @return  cino int数组
 */
array_int_t *array_int_append(array_int_t *array, int data);

/**
 * @brief   cino int数组末尾追加数组
 * @param array     :   cino int数组
 * @param arr       :   追加数组
 * @param arr_len   :   追加数组元素个数
 * @return  cino int数组
 */
array_int_t *array_int_expend(array_int_t *array, int *arr, int arr_len);

/**
 * @brief   在cino int数组指定位置插入元素
 * @param array :   cino int数组
 * @param pos   :   位置（从0开始）
 * @param data  :   新元素
 * @return  cino int数组
 */
array_int_t *array_int_insert(array_int_t *array, int pos, int data);

/**
 * @brief   删除cino int数组指定下标元素
 * @param array :   cino int数组
 * @param index :   下标
 * @return  cino int数组
 */
array_int_t *array_int_remove(array_int_t *array, int index);

/**
 * @brief   获取cino int数组最小值
 * @param array :   cino int数组
 * @return  cino int数组最小值
 */
int array_int_min(const array_int_t *array);

/**
 * @brief   获取cino int数组最大值
 * @param array :   cino int数组
 * @return  cino int数组最大值
 */
int array_int_max(const array_int_t *array);

/**
 * @brief   查找cino int数组指定元素首次出现下标
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素首次出现下标，未找到返回-1。
 */
int array_int_index_of(const array_int_t *array, int data);

/**
 * @brief   查找cino int数组指定元素最后一次出现下标
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素最后一次出现下标，未找到返回-1。
 */
int array_int_last_index_of(const array_int_t *array, int data);

/**
 * @brief   统计指定元素在cino int数组中出现次数
 * @param array :   cino int数组
 * @param data  :   查询元素
 * @return  查询元素出现次数
 */
int array_int_count(const array_int_t *array, int data);

/**
 * @brief   反转cino int数组
 * @param array :   cino int数组
 * @return  反转后的cino int数组
 */
array_int_t *array_int_reverse(array_int_t *array);

/**
 * @brief   交换cino int数组中指定下标元素
 * @param array     :   cino int数组
 * @param index1    :   被交换元素下标
 * @param index2    :   被交换元素下标
 * @return  交换后的cino int数组
 */
array_int_t *array_int_swap(array_int_t *array, int index1, int index2);

/**
 * @brief   排序cino int数组
 * @param array     :   cino int数组
 * @param reverse   :   是否逆序
 * @return  排序后的cino int数组
 */
array_int_t *array_int_sort(array_int_t *array, bool reverse);

/****************************************
 *          cino int数组迭代器
 ****************************************/

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