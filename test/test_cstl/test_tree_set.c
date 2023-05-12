#include "test_tree_set.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_tree_set_new() {
    tree_set_t *set = tree_set_new(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(set != NULL);
    assert(tree_set_is_empty(set) == true);
    assert(tree_set_size(set) == 0);
    tree_set_delete(set);
}

void test_tree_set_delete() {
    tree_set_t *set = tree_set_new(UnsignedShort_compare, UnsignedShort_delete);
    assert(set != NULL);
    tree_set_delete(set);
}

void test_tree_set_is_empty() {
    tree_set_t *set = tree_set_new(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(tree_set_is_empty(set) == true);
    tree_set_add(set, UnsignedInteger_new(0));
    assert(tree_set_is_empty(set) == false);
    tree_set_delete(set);
}

void test_tree_set_size() {
    int i = 0;
    tree_set_t *set = NULL;

    set = tree_set_new(UnsignedLong_compare, UnsignedLong_delete);
    assert(tree_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        tree_set_add(set, UnsignedLong_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    assert(tree_set_size(set) == 0);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
        tree_set_add(set, Integer_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_delete(set);
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

void test_tree_set_foreach() {
    int i = 0;
    tree_set_t *set = NULL;

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }

    n = 0;
    tree_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    n = 0;
    tree_set_foreach(set, Integer_triple);
    tree_set_foreach(set, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == 3 * i);
    }

    tree_set_delete(set);
}

void test_tree_set_clear() {
    int i = 0;
    tree_set_t *set = tree_set_new(Short_compare, Short_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Short_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_clear(set);
    assert(tree_set_is_empty(set) == true);
    tree_set_delete(set);
}

void test_tree_set_contains() {
    int i = 0;
    tree_set_t *set = NULL;
    Integer *integer;

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = Integer_new(randint(0, 3 * N));
        if (Integer_get(integer) < N) {
            assert(tree_set_contains(set, integer) == true);
        } else {
            assert(tree_set_contains(set, integer) == false);
        }
        Integer_delete(integer);
    }

    tree_set_delete(set);
}

void test_tree_set_add() {
    int i = 0;
    tree_set_t *set = NULL;

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
        tree_set_add(set, Integer_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i += 2) {
        tree_set_add(set, Integer_new(i));
    }
    for (i = 1; i < N; i += 2) {
        tree_set_add(set, Integer_new(i));
    }
    assert(tree_set_size(set) == N);
    tree_set_delete(set);
}

void test_tree_set_remove() {
    int i = 0;
    tree_set_t *set = NULL;
    Integer *integer;

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        tree_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(tree_set_is_empty(set) == true);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        tree_set_remove(set, integer);
        tree_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(tree_set_is_empty(set) == true);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N / 2; i++) {
        integer = Integer_new(N - 1 - i);
        tree_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(tree_set_size(set) == N / 2);
    tree_set_delete(set);

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(-1 * i);
        tree_set_remove(set, integer);
        Integer_delete(integer);
    }
    assert(tree_set_size(set) == N - 1);
    tree_set_delete(set);
}

void test_tree_set_union() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    tree_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_union(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    set3 = tree_set_union(set1, set2);
    assert(tree_set_size(set3) == N + 1);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_union(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_union(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    set3 = tree_set_union(set1, set2);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set3 = tree_set_union(NULL, NULL);
    assert(set3 == NULL);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    set3 = tree_set_union(set1, NULL);
    assert(set3 != NULL);
    assert(tree_set_size(set3) == N);
    tree_set_delete(set1);
    tree_set_delete(set3);

    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    set3 = tree_set_union(NULL, set2);
    assert(set3 != NULL);
    assert(tree_set_size(set3) == N);
    tree_set_delete(set2);
    tree_set_delete(set3);
}

void test_tree_set_intersection() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    tree_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) <= N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_size(set3) == N - 1);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 1 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    set3 = tree_set_intersection(set1, set2);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set3 = tree_set_intersection(NULL, NULL);
    assert(set3 == NULL);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    set3 = tree_set_intersection(set1, NULL);
    assert(set3 != NULL);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set1);
    tree_set_delete(set3);

    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    set3 = tree_set_intersection(NULL, set2);
    assert(set3 != NULL);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set2);
    tree_set_delete(set3);
}

void test_tree_set_difference() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    tree_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_difference(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_difference(set1, set2);
    assert(tree_set_size(set3) == N / 2);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N / 2);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    set3 = tree_set_difference(set1, set2);
    assert(tree_set_size(set3) == 1);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_difference(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_difference(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    set3 = tree_set_difference(set1, set2);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set3 = tree_set_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_difference(set1, NULL);
    assert(set3 != NULL);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set3);

    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    set3 = tree_set_difference(NULL, set2);
    assert(set3 == NULL);
    tree_set_delete(set2);
}

void test_tree_set_symmetric_difference() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    tree_set_t *set3 = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_is_empty(set3) == true);

    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_size(set3) == 2);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) == 0 || Integer_get(integer) == N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    set3 = tree_set_symmetric_difference(set1, set2);
    assert(tree_set_is_empty(set3) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
    tree_set_delete(set3);

    set3 = tree_set_symmetric_difference(NULL, NULL);
    assert(set3 == NULL);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }

    set3 = tree_set_symmetric_difference(set1, NULL);
    assert(set3 != NULL);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set1);
    tree_set_delete(set3);

    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    set3 = tree_set_symmetric_difference(NULL, set2);
    assert(set3 != NULL);
    assert(tree_set_size(set3) == N);

    iterator = tree_set_iterator_new(set3);
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) >= 0 && Integer_get(integer) < N);
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set2);
    tree_set_delete(set3);
}

void test_tree_set_is_disjoint() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    assert(tree_set_is_disjoint(set1, set2) == false);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    assert(tree_set_is_disjoint(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    assert(tree_set_is_disjoint(set1, set2) == false);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    assert(tree_set_is_disjoint(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    assert(tree_set_is_disjoint(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    assert(tree_set_is_disjoint(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
}

void test_tree_set_is_subset() {
    tree_set_t *set1 = NULL;
    tree_set_t *set2 = NULL;
    int i = 0;

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    assert(tree_set_is_subset(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    assert(tree_set_is_subset(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N / 2; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = N / 2; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }

    assert(tree_set_is_subset(set1, set2) == false);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);

    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i + 1));
    }

    assert(tree_set_is_subset(set1, set2) == false);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set1, Integer_new(i));
    }
    assert(tree_set_is_subset(set1, set2) == false);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set2, Integer_new(i));
    }
    assert(tree_set_is_subset(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);

    set1 = tree_set_new(Integer_compare, Integer_delete);
    set2 = tree_set_new(Integer_compare, Integer_delete);
    assert(tree_set_is_subset(set1, set2) == true);
    tree_set_delete(set1);
    tree_set_delete(set2);
}

void test_tree_set_iterator() {
    int i = 0;
    tree_set_t *set = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    set = tree_set_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        tree_set_add(set, Integer_new(i));
    }

    iterator = tree_set_iterator_new(set);

    i = 0;
    while (tree_set_iterator_has_next(iterator)) {
        integer = (Integer *)tree_set_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    tree_set_iterator_delete(iterator);
    tree_set_delete(set);
}
