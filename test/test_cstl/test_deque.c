#include "test_deque.h"
#include "cstl.h"
#include <assert.h>

#define N 1000

void test_deque_new() {
    deque_t *deque = deque_new(UnsignedCharacter_delete);
    assert(deque != NULL);
    assert(deque_is_empty(deque) == true);
    assert(deque_size(deque) == 0);
    deque_delete(deque);
}

void test_deque_delete() {
    deque_t *deque = deque_new(UnsignedShort_delete);
    assert(deque != NULL);
    deque_delete(deque);
}

void test_deque_is_empty() {
    deque_t *deque = deque_new(UnsignedInteger_delete);
    assert(deque_is_empty(deque) == true);
    deque_push_back(deque, UnsignedInteger_new(0));
    assert(deque_is_empty(deque) == false);
    deque_delete(deque);
}

void test_deque_size() {
    int i = 0;
    deque_t *deque = deque_new(UnsignedLong_delete);
    assert(deque_size(deque) == 0);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, UnsignedLong_new(i));
    }
    assert(deque_size(deque) == N);
    deque_delete(deque);
}

void test_deque_clear() {
    int i = 0;
    deque_t *deque = deque_new(Short_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Short_new(i));
    }
    assert(deque_size(deque) == N);
    deque_clear(deque);
    assert(deque_is_empty(deque) == true);
    deque_delete(deque);
}

void test_deque_push_front() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_front(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_get(deque_get_front(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_front(deque);
        Integer_delete(integer);
    }
    deque_delete(deque);
}

void test_deque_push_back() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_get(deque_get_back(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_back(deque);
        Integer_delete(integer);
    }
    deque_delete(deque);
}

void test_deque_pop_front() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        integer = (Integer *)deque_pop_front(deque);
        assert(Integer_get(integer) == i);
        Integer_delete(integer);
    }
    deque_delete(deque);
}

void test_deque_pop_back() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        integer = (Integer *)deque_pop_back(deque);
        assert(Integer_get(integer) == N - i - 1);
        Integer_delete(integer);
    }
    deque_delete(deque);
}

void test_deque_get_front() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_get(deque_get_front(deque)) == i);
        integer = (Integer *)deque_pop_front(deque);
        Integer_delete(integer);
    }
    deque_delete(deque);
}

void test_deque_get_back() {
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_new(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_get(deque_get_back(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_back(deque);
        Integer_delete(integer);
    }
    deque_delete(deque);
}
