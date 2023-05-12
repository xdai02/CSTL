#include "test_hash_set.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_hash_set_new() {
    hash_set_t *set = hash_set_new(UnsignedCharacter_compare, UnsignedCharacter_delete, UnsignedCharacter_hash);
    assert(set != NULL);
    assert(hash_set_is_empty(set) == true);
    assert(hash_set_size(set) == 0);
    hash_set_delete(set);
}

void test_hash_set_delete() {
    hash_set_t *set = hash_set_new(UnsignedShort_compare, UnsignedShort_delete, UnsignedShort_hash);
    assert(set != NULL);
    hash_set_delete(set);
}

void test_hash_set_is_empty() {
    hash_set_t *set = hash_set_new(UnsignedInteger_compare, UnsignedInteger_delete, UnsignedInteger_hash);
    assert(hash_set_is_empty(set) == true);
    hash_set_add(set, UnsignedInteger_new(0));
    assert(hash_set_is_empty(set) == false);
    hash_set_delete(set);
}

void test_hash_set_size() {
    int i = 0;
    hash_set_t *set = NULL;

    set = hash_set_new(UnsignedLong_compare, UnsignedLong_delete, UnsignedLong_hash);
    assert(hash_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        hash_set_add(set, UnsignedLong_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(hash_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
        hash_set_add(set, Integer_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_delete(set);
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

void test_hash_set_foreach() {
    int i = 0;
    hash_set_t *set = NULL;

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }

    n = 0;
    hash_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] >= 0 && buffer[i] < N);
    }

    n = 0;
    hash_set_foreach(set, Integer_triple);
    hash_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] >= 0 && buffer[i] < N * 3);
    }

    hash_set_delete(set);
}

void test_hash_set_clear() {
    int i = 0;
    hash_set_t *set = hash_set_new(Short_compare, Short_delete, Short_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Short_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_clear(set);
    assert(hash_set_is_empty(set) == true);
    hash_set_delete(set);
}

void test_hash_set_contains() {
    int i = 0;
    hash_set_t *set = NULL;
    Integer *integer;

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = Integer_new(randint(0, 3 * N));
        if (Integer_get(integer) < N) {
            assert(hash_set_contains(set, integer) == true);
        } else {
            assert(hash_set_contains(set, integer) == false);
        }
        Integer_delete(integer);
    }

    hash_set_delete(set);
}

void test_hash_set_add() {
    int i = 0;
    hash_set_t *set = NULL;

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
        hash_set_add(set, Integer_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i += 2) {
        hash_set_add(set, Integer_new(i));
    }
    for (i = 1; i < N; i += 2) {
        hash_set_add(set, Integer_new(i));
    }
    assert(hash_set_size(set) == N);
    hash_set_delete(set);
}

void test_hash_set_remove() {
    int i = 0;
    hash_set_t *set = NULL;
    Integer *integer;

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        hash_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(hash_set_is_empty(set) == true);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        hash_set_remove(set, integer);
        hash_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(hash_set_is_empty(set) == true);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N / 2; i++) {
        integer = Integer_new(N - 1 - i);
        hash_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(hash_set_size(set) == N / 2);
    hash_set_delete(set);

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(-1 * i);
        hash_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(hash_set_size(set) == N - 1);
    hash_set_delete(set);
}

void test_hash_set_union() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    hash_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_union(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    set3 = hash_set_union(set1, set2);
    assert(hash_set_size(set3) == N + 1);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_union(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_union(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    set3 = hash_set_union(set1, set2);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set3 = hash_set_union(NULL, NULL);
    assert(set3 == NULL);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    set3 = hash_set_union(set1, NULL);
    assert(set3 != NULL);
    assert(hash_set_size(set3) == N);
    hash_set_delete(set1);
    hash_set_delete(set3);

    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    set3 = hash_set_union(NULL, set2);
    assert(set3 != NULL);
    assert(hash_set_size(set3) == N);
    hash_set_delete(set2);
    hash_set_delete(set3);
}

void test_hash_set_intersection() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    hash_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_size(set3) == N - 1);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 1 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = hash_set_intersection(set1, set2);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set3 = hash_set_intersection(NULL, NULL);
    assert(set3 == NULL);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    set3 = hash_set_intersection(set1, NULL);
    assert(set3 != NULL);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set1);
    hash_set_delete(set3);

    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    set3 = hash_set_intersection(NULL, set2);
    assert(set3 != NULL);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set2);
    hash_set_delete(set3);
}

void test_hash_set_difference() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    hash_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_difference(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_difference(set1, set2);
    assert(hash_set_size(set3) == N / 2);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N / 2);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    set3 = hash_set_difference(set1, set2);
    assert(hash_set_size(set3) == 1);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_difference(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_difference(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = hash_set_difference(set1, set2);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set3 = hash_set_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_difference(set1, NULL);
    assert(set3 != NULL);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set3);

    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    set3 = hash_set_difference(NULL, set2);
    assert(set3 == NULL);
    hash_set_delete(set2);
}

void test_hash_set_symmetric_difference() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    hash_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_is_empty(set3) == true);

    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_size(set3) == 2);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0 || Integer_get(integer) == N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set3 = hash_set_symmetric_difference(set1, set2);
    assert(hash_set_is_empty(set3) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
    hash_set_delete(set3);

    set3 = hash_set_symmetric_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }

    set3 = hash_set_symmetric_difference(set1, NULL);
    assert(set3 != NULL);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set1);
    hash_set_delete(set3);

    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    set3 = hash_set_symmetric_difference(NULL, set2);
    assert(set3 != NULL);
    assert(hash_set_size(set3) == N);

    iterator = hash_set_iterator_new(set3);
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set2);
    hash_set_delete(set3);
}

void test_hash_set_is_disjoint() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    assert(hash_set_is_disjoint(set1, set2) == false);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    assert(hash_set_is_disjoint(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    assert(hash_set_is_disjoint(set1, set2) == false);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    assert(hash_set_is_disjoint(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    assert(hash_set_is_disjoint(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(hash_set_is_disjoint(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
}

void test_hash_set_is_subset() {
    hash_set_t *set1 = NULL;
    hash_set_t *set2 = NULL;
    int i = 0;

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    assert(hash_set_is_subset(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    assert(hash_set_is_subset(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N / 2; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }

    assert(hash_set_is_subset(set1, set2) == false);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i + 1));
    }

    assert(hash_set_is_subset(set1, set2) == false);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set1, Integer_new(i));
    }
    assert(hash_set_is_subset(set1, set2) == false);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set2, Integer_new(i));
    }
    assert(hash_set_is_subset(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);

    set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    assert(hash_set_is_subset(set1, set2) == true);
    hash_set_delete(set1);
    hash_set_delete(set2);
}

void test_hash_set_iterator() {
    int i = 0;
    hash_set_t *set = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_set_add(set, Integer_new(i));
    }

    iterator = hash_set_iterator_new(set);

    i = 0;
    while (hash_set_iterator_has_next(iterator)) {
        integer = (Integer *)hash_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
        i++;
    }

    hash_set_iterator_delete(iterator);
    hash_set_delete(set);
}
