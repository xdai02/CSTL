#include "test_heap.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_heap_new() {
    heap_t *heap = NULL;

    heap = heap_new(MIN_HEAP, UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(heap != NULL);
    assert(heap_is_empty(heap) == true);
    assert(heap_size(heap) == 0);
    heap_delete(heap);

    heap = heap_new(MAX_HEAP, Character_compare, Character_delete);
    assert(heap != NULL);
    assert(heap_is_empty(heap) == true);
    assert(heap_size(heap) == 0);
    heap_delete(heap);
}

void test_heap_delete() {
    heap_t *heap = NULL;

    heap = heap_new(MIN_HEAP, UnsignedShort_compare, UnsignedShort_delete);
    assert(heap != NULL);
    heap_delete(heap);

    heap = heap_new(MAX_HEAP, Short_compare, Short_delete);
    assert(heap != NULL);
    heap_delete(heap);
}

void test_heap_is_empty() {
    heap_t *heap = NULL;

    heap = heap_new(MIN_HEAP, UnsignedInteger_compare, UnsignedInteger_delete);
    assert(heap_is_empty(heap) == true);
    heap_push(heap, UnsignedInteger_new(0));
    assert(heap_is_empty(heap) == false);
    heap_delete(heap);

    heap = heap_new(MAX_HEAP, Integer_compare, Integer_delete);
    assert(heap_is_empty(heap) == true);
    heap_push(heap, Integer_new(0));
    assert(heap_is_empty(heap) == false);
    heap_delete(heap);
}

void test_heap_size() {
    heap_t *heap = NULL;
    int i = 0;

    heap = heap_new(MIN_HEAP, UnsignedLong_compare, UnsignedLong_delete);
    assert(heap_size(heap) == 0);
    for (i = 0; i < N; i++) {
        heap_push(heap, UnsignedLong_new(i));
    }
    assert(heap_size(heap) == N);
    heap_delete(heap);

    heap = heap_new(MAX_HEAP, Long_compare, Long_delete);
    assert(heap_size(heap) == 0);
    for (i = 0; i < N; i++) {
        heap_push(heap, Long_new(i));
    }
    assert(heap_size(heap) == N);
    heap_delete(heap);
}

void test_heap_clear() {
    heap_t *heap = NULL;
    int i = 0;

    heap = heap_new(MIN_HEAP, Float_compare, Float_delete);
    assert(heap_size(heap) == 0);
    for (i = 0; i < N; i++) {
        heap_push(heap, Float_new(i));
    }
    assert(heap_size(heap) == N);
    heap_clear(heap);
    assert(heap_is_empty(heap) == true);
    heap_delete(heap);

    heap = heap_new(MAX_HEAP, Double_compare, Double_delete);
    assert(heap_size(heap) == 0);
    for (i = 0; i < N; i++) {
        heap_push(heap, Double_new(i));
    }
    assert(heap_size(heap) == N);
    heap_clear(heap);
    assert(heap_is_empty(heap) == true);
    heap_delete(heap);
}

void test_heap_push() {
}

void test_heap_pop() {
}

void test_heap_peek() {
}
