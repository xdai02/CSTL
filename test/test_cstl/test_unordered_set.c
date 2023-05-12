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

void test_unordered_set_union() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    unordered_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_union(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    set3 = unordered_set_union(set1, set2);
    assert(unordered_set_size(set3) == N + 1);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_union(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_union(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    set3 = unordered_set_union(set1, set2);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set3 = unordered_set_union(NULL, NULL);
    assert(set3 == NULL);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    set3 = unordered_set_union(set1, NULL);
    assert(set3 != NULL);
    assert(unordered_set_size(set3) == N);
    unordered_set_delete(set1);
    unordered_set_delete(set3);

    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    set3 = unordered_set_union(NULL, set2);
    assert(set3 != NULL);
    assert(unordered_set_size(set3) == N);
    unordered_set_delete(set2);
    unordered_set_delete(set3);
}

void test_unordered_set_intersection() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    unordered_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_size(set3) == N - 1);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 1 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = unordered_set_intersection(set1, set2);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set3 = unordered_set_intersection(NULL, NULL);
    assert(set3 == NULL);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    set3 = unordered_set_intersection(set1, NULL);
    assert(set3 != NULL);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set3);

    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    set3 = unordered_set_intersection(NULL, set2);
    assert(set3 != NULL);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set2);
    unordered_set_delete(set3);
}

void test_unordered_set_difference() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    unordered_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_size(set3) == N / 2);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N / 2);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_size(set3) == 1);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = unordered_set_difference(set1, set2);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set3 = unordered_set_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_difference(set1, NULL);
    assert(set3 != NULL);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set3);

    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    set3 = unordered_set_difference(NULL, set2);
    assert(set3 == NULL);
    unordered_set_delete(set2);
}

void test_unordered_set_symmetric_difference() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    unordered_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_is_empty(set3) == true);

    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_size(set3) == 2);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0 || Integer_get(integer) == N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = unordered_set_symmetric_difference(set1, set2);
    assert(unordered_set_is_empty(set3) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
    unordered_set_delete(set3);

    set3 = unordered_set_symmetric_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }

    set3 = unordered_set_symmetric_difference(set1, NULL);
    assert(set3 != NULL);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set1);
    unordered_set_delete(set3);

    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    set3 = unordered_set_symmetric_difference(NULL, set2);
    assert(set3 != NULL);
    assert(unordered_set_size(set3) == N);

    iterator = unordered_set_iterator_new(set3);
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set2);
    unordered_set_delete(set3);
}

void test_unordered_set_is_disjoint() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    assert(unordered_set_is_disjoint(set1, set2) == false);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    assert(unordered_set_is_disjoint(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    assert(unordered_set_is_disjoint(set1, set2) == false);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    assert(unordered_set_is_disjoint(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    assert(unordered_set_is_disjoint(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(unordered_set_is_disjoint(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
}

void test_unordered_set_is_subset() {
    unordered_set_t *set1 = NULL;
    unordered_set_t *set2 = NULL;
    int i = 0;

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    assert(unordered_set_is_subset(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    assert(unordered_set_is_subset(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }

    assert(unordered_set_is_subset(set1, set2) == false);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i + 1));
    }

    assert(unordered_set_is_subset(set1, set2) == false);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set1, Integer_new(i));
    }
    assert(unordered_set_is_subset(set1, set2) == false);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set2, Integer_new(i));
    }
    assert(unordered_set_is_subset(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);

    set1 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(unordered_set_is_subset(set1, set2) == true);
    unordered_set_delete(set1);
    unordered_set_delete(set2);
}

void test_unordered_set_iterator() {
    int i = 0;
    unordered_set_t *set = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    set = unordered_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        unordered_set_add(set, Integer_new(i));
    }

    iterator = unordered_set_iterator_new(set);

    i = 0;
    while (unordered_set_iterator_has_next(iterator)) {
        integer = (Integer *)unordered_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
        i++;
    }

    unordered_set_iterator_delete(iterator);
    unordered_set_delete(set);
}
