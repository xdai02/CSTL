#include "test_stack.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_stack_new() {
    stack_t *stack = stack_new(UnsignedCharacter_delete);
    assert(stack != NULL);
    assert(stack_is_empty(stack) == true);
    assert(stack_size(stack) == 0);
    stack_delete(stack);
}

void test_stack_delete() {
    stack_t *stack = stack_new(UnsignedShort_delete);
    assert(stack != NULL);
    stack_delete(stack);
}

void test_stack_is_empty() {
    stack_t *stack = stack_new(UnsignedInteger_delete);
    assert(stack_is_empty(stack) == true);
    stack_push(stack, UnsignedInteger_new(0));
    assert(stack_is_empty(stack) == false);
    stack_delete(stack);
}

void test_stack_size() {
    int i = 0;
    stack_t *stack = stack_new(UnsignedLong_delete);
    assert(stack_size(stack) == 0);
    for (i = 0; i < N; i++) {
        stack_push(stack, UnsignedLong_new(i));
    }
    assert(stack_size(stack) == N);
    stack_delete(stack);
}

void test_stack_clear() {
    int i = 0;
    stack_t *stack = stack_new(Short_delete);
    for (i = 0; i < N; i++) {
        stack_push(stack, Short_new(i));
    }
    assert(stack_size(stack) == N);
    stack_clear(stack);
    assert(stack_is_empty(stack) == true);
    stack_delete(stack);
}

void test_stack_push() {
    int i = 0;
    stack_t *stack = stack_new(Integer_delete);
    for (i = 0; i < N; i++) {
        stack_push(stack, Integer_new(i));
    }
    assert(stack_size(stack) == N);
    stack_delete(stack);
}

void test_stack_pop() {
    int i = 0;
    stack_t *stack = NULL;
    Integer *integer;

    stack = stack_new(Integer_delete);
    for (i = 0; i < N; i++) {
        stack_push(stack, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = (Integer *)stack_pop(stack);
        assert(Integer_get(integer) == N - i - 1);
        Integer_delete(integer);
    }
    assert(stack_size(stack) == 0);
    stack_delete(stack);
}

void test_stack_peek() {
    int i = 0;
    stack_t *stack = NULL;
    Integer *integer;

    stack = stack_new(Integer_delete);
    for (i = 0; i < N; i++) {
        stack_push(stack, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        assert(Integer_get(stack_peek(stack)) == N - i - 1);
        integer = (Integer *)stack_pop(stack);
        Integer_delete(integer);
    }
    assert(stack_is_empty(stack) == true);
    stack_delete(stack);
}
