#include "test_deque.h"
#include "coop.h"
#include <assert.h>

void test_deque_create() {
    deque_t *deque = deque_create(UnsignedCharacter_delete);
    assert(deque != NULL);
    assert(deque_is_empty(deque) == true);
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_destroy() {
    deque_t *deque = deque_create(UnsignedCharacter_delete);
    assert(deque != NULL);
    deque_destroy(deque);
}

void test_deque_is_empty() {
    deque_t *deque = deque_create(UnsignedInteger_delete);
    assert(deque_is_empty(deque) == true);
    deque_push_back(deque, UnsignedInteger_new(0));
    assert(deque_is_empty(deque) == false);
    deque_destroy(deque);
}

void test_deque_size() {
    const int N = 1000;
    int i = 0;
    deque_t *deque = deque_create(UnsignedLong_delete);
    assert(deque_size(deque) == 0);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, UnsignedLong_new(i));
    }
    assert(deque_size(deque) == N);
    deque_destroy(deque);
}

void test_deque_clear() {
    const int N = 100;
    int i = 0;
    deque_t *deque = deque_create(Short_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Short_new(i));
    }
    assert(deque_size(deque) == N);
    deque_clear(deque);
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_push_front() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_front(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_valueOf(deque_get_front(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_front(deque);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}

void test_deque_push_back() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_valueOf(deque_get_back(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_back(deque);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}

void test_deque_pop_front() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        integer = (Integer *)deque_pop_front(deque);
        assert(Integer_valueOf(integer) == i);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}

void test_deque_pop_back() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        integer = (Integer *)deque_pop_back(deque);
        assert(Integer_valueOf(integer) == N - i - 1);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}

void test_deque_get_front() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_valueOf(deque_get_front(deque)) == i);
        integer = (Integer *)deque_pop_front(deque);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}

void test_deque_get_back() {
    const int N = 100;
    int i = 0;
    deque_t *deque = NULL;
    Integer *integer;

    deque = deque_create(Integer_delete);
    for (i = 0; i < N; i++) {
        deque_push_back(deque, Integer_new(i));
    }
    assert(deque_size(deque) == N);
    for (i = 0; i < N; i++) {
        assert(Integer_valueOf(deque_get_back(deque)) == N - i - 1);
        integer = (Integer *)deque_pop_back(deque);
        Integer_delete(integer);
    }
    deque_destroy(deque);
}
