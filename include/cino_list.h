/**************************************************
 * Module   :   cino_list
 * Function :   Operations on cino-list
 * Category :
 *              - list_t
 **************************************************/

#ifndef _CINO_LIST_H_
#define _CINO_LIST_H_

#include "cino_utils.h"

/****************************************
 *               list_t
 ****************************************/

typedef struct list_t list_t;

/**
 * @brief   Create cino-list.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T, 
 *                         otherwise a default `compare_default` is applied.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T, 
 *                         otherwise a default `compare_default` is applied.
 * @return  Returns the pointer to cino-list, or `NULL` if creation failed.
 */
list_t *list_create(data_type_t data_type, compare_t compare, destroy_t destroy);

/**
 * @brief   Destroy cino-list.
 * @param list  cino-list
 */
void list_destroy(list_t *list);

/**
 * @brief   Determine if the cino-list is empty.
 * @param list  cino-list
 * @return  Returns `true` if the cino-list is empty, otherwise returns `false`.
 */
bool list_is_empty(const list_t *list);

/**
 * @brief   Get the number of elements in the cino-list.
 * @param list  cino-list
 * @return  Returns the number of elements in the cino-list.
 */
size_t list_size(const list_t *list);

/**
 * @brief   Clear all the elments in the cino-list.
 * @param list  cino-list
 * @return  Returns the modified cino-list.
 */
list_t *list_clear(list_t *list);

/**
 * @brief   Traverse cino-list.
 * @param list      cino-list
 * @param visit     user-defined callback function for visiting a single element
 * @param reverse   true = backward, false = forward
 */
void list_foreach(list_t *list, visit_t visit, bool backward);

/**
 * @brief   Get the first element in the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the first
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get_front(const list_t *list);

/**
 * @brief   Get the last element in the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the last
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get_back(const list_t *list);

/**
 * @brief   Get the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the
 *          primitive. Caller should use `->data` to get the primitive value, instead
 *          of unwrapping it.
 */
T list_get(const list_t *list, int index);

/**
 * @brief   Update the element of the indexed component in the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 */
void list_set(list_t *list, int index, T data);

/**
 * @brief   Find the index of the first occurrence of the specified element in the
 *          cino-list.
 * @param list      cino-list
 * @param context   - For primitive cino-list, a wrapper type of the searching data should
 *                    be passed. This function will unwrap for you.
 *                  - For T (generic) cino-list, a match_t callback function should be passed
 *                    as the matching rule.
 * @return  Returns the index of the first occurrence of the specified element in the
 *          cino-list, or `-1` if not found.
 */
int list_index_of(const list_t *list, void *context);

/**
 * @brief   Inserts the specified element at the beginning of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed
 * @return  Returns the modified cino-list.
 */
list_t *list_push_front(list_t *list, T data);

/**
 * @brief   Inserts the specified element at the end of the cino-list.
 * @param list  cino-list
 * @param data  For primitive data, a wrapper type of that primitive is needed
 * @return  Returns the modified cino-list.
 */
list_t *list_push_back(list_t *list, T data);

/**
 * @brief   Removes the first element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T list_pop_front(list_t *list);

/**
 * @brief   Removes the last element from the cino-list.
 * @param list  cino-list
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T list_pop_back(list_t *list);

/**
 * @brief   Inserts the specified element at the indexed location of the cino-list.
 * @param list  cino-list
 * @param index index
 * @param data  For primitive data, a wrapper type of that primitive is needed.
 * @return  Returns the modified cino-list.
 */
list_t *list_insert(list_t *list, int index, T data);

/**
 * @brief   Removes the indexed element from the cino-list.
 * @param list  cino-list
 * @param index index
 * @return  For primitive cino-list, this function returns a wrapper type of the removed
 *          primitive. It is caller's responsibility to unwrap or free.
 */
T list_remove(list_t *list, int index);

#endif