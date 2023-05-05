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

void test_set_foreach() {
    
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

    set1 = set_create(Integer_compare, Integer_delete);
    set2 = set_create(Integer_compare, Integer_delete);

    for (int i = 0; i < N / 2; i++) {
        set_add(set1, Integer_new(i));
    }
    for (int i = N / 2; i < N; i++) {
        set_add(set2, Integer_new(i));
    }

    set3 = set_union(set1, set2);

}

void test_set_intersection() {
}

void test_set_difference() {
}

void test_set_symmetric_difference() {
}

void test_set_is_disjoint() {
}

void test_set_is_subset() {
}

void test_set_iterator() {
    int i = 0;
    red_black_tree_t *tree = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    tree = red_black_tree_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }

    iterator = red_black_tree_iterator_create(tree);

    i = 0;
    while (red_black_tree_iterator_has_next(iterator)) {
        integer = (Integer *)red_black_tree_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    red_black_tree_iterator_destroy(iterator);
    red_black_tree_destroy(tree);
}
