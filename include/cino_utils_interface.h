/**************************************************
 * Module   :   cino_utils_interface
 * Function :   Interface for callback functions
 * Category :
 *              - Callback Interface
 **************************************************/

#ifndef _CINO_UTILS_INTERFACE_H_
#define _CINO_UTILS_INTERFACE_H_

/****************************************
 *          Callback Interface
 ****************************************/

/**
 * @brief   User-defined comparison function interface.
 * @param data1 pointer to the first data
 * @param data2 pointer to the second data
 * @return  Returns
 *              - 0 if two values are equal
 *              - positive if the first value is greater than the second value
 *              - negative if the first value is less than the second value
 */
typedef int (*compare_t)(const void *data1, const void *data2);

/**
 * @brief   User-defined matching function interface.
 * @param data  pointer to the data for matching
 * @return  Returns `true` if the data matches the condition, otherwise returns
 *          `false`.
 */
typedef bool (*match_t)(const void *data);

/**
 * @brief   User-defined visitor function interface for traversal.
 * @param data  pointer to the data visiting
 */
typedef void (*visit_t)(void *data);

#endif