#ifndef _HEAP_H_
#define _HEAP_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"

typedef struct heap_t heap_t;

typedef enum heap_type_t {
    MIN_HEAP,
    MAX_HEAP
} heap_type_t;

/**
 * @brief Create a heap_t object.
 * @param heap_type The type of the heap (MIN_HEAP/MAX_HEAP).
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created heap_t object if successful, otherwise returns NULL.
 */
heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy);

/**
 * @brief Destroy a heap_t object.
 * @param heap The heap_t object.
 */
void heap_delete(heap_t *heap);

/**
 * @brief Determine whether a heap_t object is empty.
 * @param heap The heap_t object.
 * @return Returns true if the heap_t object is empty, otherwise returns false.
 */
bool heap_is_empty(const heap_t *heap);

/**
 * @brief Get the size of a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the size of the heap_t object.
 */
size_t heap_size(const heap_t *heap);

/**
 * @brief Clear a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the modified heap_t object.
 */
heap_t *heap_clear(heap_t *heap);

/**
 * @brief Push an element into a heap_t object.
 * @param heap The heap_t object.
 * @param elem The element.
 * @return Returns the modified heap_t object.
 */
heap_t *heap_push(heap_t *heap, T elem);

/**
 * @brief Pop an element from a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the popped element.
 * @note Caller MUST free the returned element (if applicable).
 */
T heap_pop(heap_t *heap);

/**
 * @brief Peek the root element of a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the root element.
 */
T heap_peek(const heap_t *heap);

#endif
