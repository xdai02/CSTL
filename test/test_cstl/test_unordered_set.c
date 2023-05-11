#include "test_unordered_set.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_unordered_set_new() {
    unordered_set_t *set = unordered_set_new(UnsignedCharacter_compare, UnsignedCharacter_delete, UnsignedCharacter_hash);
    assert(set != NULL);
    assert(unordered_set_is_empty(set) == true);
    assert(unordered_set_size(set) == 0);
    unordered_set_delete(set);
}

void test_unordered_set_delete() {
    unordered_set_t *set = unordered_set_new(UnsignedShort_compare, UnsignedShort_delete, UnsignedShort_hash);
    assert(set != NULL);
    unordered_set_delete(set);
}

void test_unordered_set_is_empty() {
    unordered_set_t *set = unordered_set_new(UnsignedInteger_compare, UnsignedInteger_delete, UnsignedInteger_hash);
    assert(unordered_set_is_empty(set) == true);
    unordered_set_add(set, UnsignedInteger_new(0));
    assert(unordered_set_is_empty(set) == false);
    unordered_set_delete(set);
}

void test_unordered_set_size() {
    int i = 0;
    unordered_set_t *set = NULL;

    set = unordered_set_new(UnsignedLong_compare, UnsignedLong_delete, UnsignedLong_hash);
    assert(unordered_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, UnsignedLong_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(unordered_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
        unordered_set_add(set, Integer_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_delete(set);
}

static int buffer[N] = {0};
static int n = 0;

static void Integer_store(T elem) {
    Integer *integer = (Integer *)elem;
    buffer[n] = Integer_get(integer);
    n++;
}

static void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

void test_unordered_set_foreach() {
    int i = 0;
    unordered_set_t *set = NULL;

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }

    n = 0;
    unordered_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] >= 0 && buffer[i] < N);
    }

    n = 0;
    unordered_set_foreach(set, Integer_triple);
    unordered_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] >= 0 && buffer[i] < N * 3);
    }

    unordered_set_delete(set);
}

void test_unordered_set_clear() {
    int i = 0;
    unordered_set_t *set = unordered_set_new(Short_compare, Short_delete, Short_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Short_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_clear(set);
    assert(unordered_set_is_empty(set) == true);
    unordered_set_delete(set);
}

void test_unordered_set_contains() {
    int i = 0;
    unordered_set_t *set = NULL;
    Integer *integer;

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = Integer_new(randint(0, 3 * N));
        if (Integer_get(integer) < N) {
            assert(unordered_set_contains(set, integer) == true);
        } else {
            assert(unordered_set_contains(set, integer) == false);
        }
        Integer_delete(integer);
    }

    unordered_set_delete(set);
}

void test_unordered_set_add() {
    int i = 0;
    unordered_set_t *set = NULL;

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
        unordered_set_add(set, Integer_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i += 2) {
        unordered_set_add(set, Integer_new(i));
    }
    for (i = 1; i < N; i += 2) {
        unordered_set_add(set, Integer_new(i));
    }
    assert(unordered_set_size(set) == N);
    unordered_set_delete(set);
}

void test_unordered_set_remove() {
    int i = 0;
    unordered_set_t *set = NULL;
    Integer *integer;

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        unordered_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(unordered_set_is_empty(set) == true);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        unordered_set_remove(set, integer);
        unordered_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(unordered_set_is_empty(set) == true);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N / 2; i++) {
        integer = Integer_new(N - 1 - i);
        unordered_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(unordered_set_size(set) == N / 2);
    unordered_set_delete(set);

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(-1 * i);
        unordered_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(unordered_set_size(set) == N - 1);
    unordered_set_delete(set);
}
