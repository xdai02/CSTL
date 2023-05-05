#include "test_set.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_set_create() {
    set_t *set = set_create(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(set != NULL);
    assert(set_is_empty(set) == true);
    assert(set_size(set) == 0);
    set_destroy(set);
}

void test_set_destroy() {
    set_t *set = set_create(UnsignedShort_compare, UnsignedShort_delete);
    assert(set != NULL);
    set_destroy(set);
}

void test_set_is_empty() {
    set_t *set = set_create(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(set_is_empty(set) == true);
    set_add(set, UnsignedInteger_new(0));
    assert(set_is_empty(set) == false);
    set_destroy(set);
}

void test_set_size() {
    int i = 0;
    set_t *set = NULL;

    set = set_create(UnsignedLong_compare, UnsignedLong_delete);
    assert(set_size(set) == 0);
    for (i = 0; i < N; i++) {
        set_add(set, UnsignedLong_new(i));
    }
    assert(set_size(set) == N);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    assert(set_size(set) == 0);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
        set_add(set, Integer_new(i));
    }
    assert(set_size(set) == N);
    set_destroy(set);
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

void test_set_foreach() {
    int i = 0;
    set_t *set = NULL;

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }

    n = 0;
    set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    n = 0;
    set_foreach(set, Integer_triple);
    set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == 3 * i);
    }

    set_destroy(set);
}

void test_set_clear() {
    int i = 0;
    set_t *set = set_create(Short_compare, Short_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Short_new(i));
    }
    assert(set_size(set) == N);
    set_clear(set);
    assert(set_is_empty(set) == true);
    set_destroy(set);
}

void test_set_contains() {
    int i = 0;
    set_t *set = NULL;
    Integer *integer;

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = Integer_new(randint(0, 3 * N));
        if (Integer_get(integer) < N) {
            assert(set_contains(set, integer) == true);
        } else {
            assert(set_contains(set, integer) == false);
        }
        Integer_delete(integer);
    }

    set_destroy(set);
}

void test_set_add() {
    int i = 0;
    set_t *set = NULL;

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }
    assert(set_size(set) == N);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
        set_add(set, Integer_new(i));
    }
    assert(set_size(set) == N);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i += 2) {
        set_add(set, Integer_new(i));
    }
    for (i = 1; i < N; i += 2) {
        set_add(set, Integer_new(i));
    }
    assert(set_size(set) == N);
    set_destroy(set);
}

void test_set_remove() {
    int i = 0;
    set_t *set = NULL;
    Integer *integer;

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(set_is_empty(set) == true);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        set_remove(set, integer);
        set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(set_is_empty(set) == true);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }
    for (i = 0; i < N / 2; i++) {
        integer = Integer_new(N - 1 - i);
        set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(set_size(set) == N / 2);
    set_destroy(set);

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(-1 * i);
        set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(set_size(set) == N - 1);
    set_destroy(set);
}

void test_set_union() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_union(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    set3 = set_union(set1, set2);
    assert(set_size(set3) == N + 1);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_union(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_union(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    set3 = set_union(set1, set2);
    assert(set_is_empty(set3) == true);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set3 = set_union(NULL, NULL);
    assert(set3 == NULL);

    set1 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    set3 = set_union(set1, NULL);
    assert(set3 != NULL);
    assert(set_size(set3) == N);
    set_destroy(set1);
    set_destroy(set3);

    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    set3 = set_union(NULL, set2);
    assert(set3 != NULL);
    assert(set_size(set3) == N);
    set_destroy(set2);
    set_destroy(set3);
}

void test_set_intersection() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_intersection(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_intersection(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    set3 = set_intersection(set1, set2);
    assert(set_size(set3) == N - 1);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 1 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_intersection(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_intersection(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    set3 = set_intersection(set1, set2);
    assert(set_is_empty(set3) == true);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set3 = set_intersection(NULL, NULL);
    assert(set3 == NULL);

    set1 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    set3 = set_intersection(set1, NULL);
    assert(set3 != NULL);
    assert(set_is_empty(set3) == true);
    set_destroy(set1);
    set_destroy(set3);

    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    set3 = set_intersection(NULL, set2);
    assert(set3 != NULL);
    assert(set_is_empty(set3) == true);
    set_destroy(set2);
    set_destroy(set3);
}

void test_set_difference() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_difference(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_difference(set1, set2);
    assert(set_size(set3) == N / 2);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N / 2);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    set3 = set_difference(set1, set2);
    assert(set_size(set3) == 1);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) == 0);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_difference(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_difference(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    set3 = set_difference(set1, set2);
    assert(set_is_empty(set3) == true);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set3 = set_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_difference(set1, NULL);
    assert(set3 != NULL);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set3);

    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    set3 = set_difference(NULL, set2);
    assert(set3 == NULL);
    set_destroy(set2);
}

void test_set_symmetric_difference() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_symmetric_difference(set1, set2);
    assert(set_is_empty(set3) == true);

    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_symmetric_difference(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    set3 = set_symmetric_difference(set1, set2);
    assert(set_size(set3) == 2);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) == 0 || Integer_get(integer) == N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_symmetric_difference(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_symmetric_difference(set1, set2);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    set3 = set_symmetric_difference(set1, set2);
    assert(set_is_empty(set3) == true);
    set_destroy(set1);
    set_destroy(set2);
    set_destroy(set3);

    set3 = set_symmetric_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }

    set3 = set_symmetric_difference(set1, NULL);
    assert(set3 != NULL);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set1);
    set_destroy(set3);

    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    set3 = set_symmetric_difference(NULL, set2);
    assert(set3 != NULL);
    assert(set_size(set3) == N);

    iterator = set_iterator_create(set3);
    while (set_iterator_has_next(iterator)) {
        integer = set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    set_iterator_destroy(iterator);
    set_destroy(set2);
    set_destroy(set3);
}

void test_set_is_disjoint() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    assert(set_is_disjoint(set1, set2) == false);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    assert(set_is_disjoint(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    assert(set_is_disjoint(set1, set2) == false);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    assert(set_is_disjoint(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    assert(set_is_disjoint(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    assert(set_is_disjoint(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);
}

void test_set_is_subset() {
    set_t *set1 = NULL;
    set_t *set2 = NULL;
    int i = 0;

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    assert(set_is_subset(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    assert(set_is_subset(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    assert(set_is_subset(set1, set2) == false);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i + 1));
    }

    assert(set_is_subset(set1, set2) == false);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set1, Integer_new(i));
    }
    assert(set_is_subset(set1, set2) == false);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set2, Integer_new(i));
    }
    assert(set_is_subset(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);
    assert(set_is_subset(set1, set2) == true);
    set_destroy(set1);
    set_destroy(set2);
}

void test_set_iterator() {
    int i = 0;
    set_t *set = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    set = set_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        set_add(set, Integer_new(i));
    }

    iterator = set_iterator_create(set);

    i = 0;
    while (set_iterator_has_next(iterator)) {
        integer = (Integer *)set_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    set_iterator_destroy(iterator);
    set_destroy(set);
}
