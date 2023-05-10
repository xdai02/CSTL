#ifndef _GENERIC_H_
#define _GENERIC_H_

/**
 * @brief A generic data type representing a pointer to any data type.
 *        It is an alias for void *.
 */
#define T void *

/**
 * @brief A generic function pointer type for comparing two data items.
 * @param data1 The first data item to be compared.
 * @param data2 The second data item to be compared.
 * @return Returns a negative integer if data1 < data2, 0 if data1 == data2, or a positive integer if data1 > data2.
 */
typedef int (*compare_t)(const T data1, const T data2);

/**
 * @brief A generic function pointer type for destroying a data item.
 * @param data The data item to be destroyed.
 */
typedef void (*destroy_t)(T data);

/**
 * @brief A generic function pointer type for visiting a data item.
 * @param data The data item to be visited.
 */
typedef void (*visit_t)(T data);

/**
 * @brief A generic function pointer type for visiting a key-value pair.
 * @param pair The pair_t object to be visited.
 */
typedef void (*visit_pair_t)(T pair);

/**
 * @brief A generic function pointer type for hashing a data item.
 * @param data The data item to be hashed.
 */
typedef size_t (*hash_t)(const T data);

#endif
