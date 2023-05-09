#include "test_queue.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_queue_new() {
    queue_t *queue = queue_new(UnsignedCharacter_delete);
    assert(queue != NULL);
    assert(queue_is_empty(queue) == true);
    assert(queue_size(queue) == 0);
    queue_delete(queue);
}

void test_queue_delete() {
    queue_t *queue = queue_new(UnsignedShort_delete);
    assert(queue != NULL);
    queue_delete(queue);
}

void test_queue_is_empty() {
    queue_t *queue = queue_new(UnsignedInteger_delete);
    assert(queue_is_empty(queue) == true);
    queue_enqueue(queue, UnsignedInteger_new(0));
    assert(queue_is_empty(queue) == false);
    queue_delete(queue);
}

void test_queue_size() {
    int i = 0;
    queue_t *queue = queue_new(UnsignedLong_delete);
    assert(queue_size(queue) == 0);
    for (i = 0; i < N; i++) {
        queue_enqueue(queue, UnsignedLong_new(i));
    }
    assert(queue_size(queue) == N);
    queue_delete(queue);
}

void test_queue_clear() {
    int i = 0;
    queue_t *queue = queue_new(Short_delete);
    for (i = 0; i < N; i++) {
        queue_enqueue(queue, Short_new(i));
    }
    assert(queue_size(queue) == N);
    queue_clear(queue);
    assert(queue_is_empty(queue) == true);
    queue_delete(queue);
}

void test_queue_enqueue() {
    int i = 0;
    queue_t *queue = queue_new(Integer_delete);
    for (i = 0; i < N; i++) {
        queue_enqueue(queue, Integer_new(i));
    }
    assert(queue_size(queue) == N);
    queue_delete(queue);
}

void test_queue_dequeue() {
    int i = 0;
    queue_t *queue = NULL;
    Integer *integer;

    queue = queue_new(Integer_delete);
    for (i = 0; i < N; i++) {
        queue_enqueue(queue, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = (Integer *)queue_dequeue(queue);
        assert(Integer_get(integer) == i);
        Integer_delete(integer);
    }
    assert(queue_size(queue) == 0);
    queue_delete(queue);
}

void test_queue_peek() {
    int i = 0;
    queue_t *queue = NULL;
    Integer *integer;

    queue = queue_new(Integer_delete);
    for (i = 0; i < N; i++) {
        queue_enqueue(queue, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        assert(Integer_get(queue_peek(queue)) == i);
        integer = (Integer *)queue_dequeue(queue);
        Integer_delete(integer);
    }
    assert(queue_is_empty(queue) == true);
    queue_delete(queue);
}
