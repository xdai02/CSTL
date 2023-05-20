#ifndef _HEAP_H_
#define _HEAP_H_

#include "utils/utils.h"

typedef struct heap_t heap_t;

typedef enum heap_type_t {
    MIN_HEAP,
    MAX_HEAP,
} heap_type_t;

heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy);
void heap_delete(heap_t *heap);
bool heap_is_empty(const heap_t *heap);
size_t heap_size(const heap_t *heap);
heap_t *heap_push(heap_t *heap, T elem);
T heap_pop(heap_t *heap);
T heap_peek(const heap_t *heap);

#endif
