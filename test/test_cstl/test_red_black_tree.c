#include "test_red_black_tree.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_red_black_tree_new() {
    red_black_tree_t *tree = red_black_tree_new(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(tree != NULL);
    assert(red_black_tree_is_empty(tree) == true);
    assert(red_black_tree_size(tree) == 0);
    red_black_tree_delete(tree);
}

void test_red_black_tree_delete() {
    red_black_tree_t *tree = red_black_tree_new(UnsignedShort_compare, UnsignedShort_delete);
    assert(tree != NULL);
    red_black_tree_delete(tree);
}

void test_red_black_tree_is_empty() {
    red_black_tree_t *tree = red_black_tree_new(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(red_black_tree_is_empty(tree) == true);
    red_black_tree_insert(tree, UnsignedInteger_new(0));
    assert(red_black_tree_is_empty(tree) == false);
    red_black_tree_delete(tree);
}

void test_red_black_tree_size() {
    int i = 0;
    red_black_tree_t *tree = NULL;

    tree = red_black_tree_new(UnsignedLong_compare, UnsignedLong_delete);
    assert(red_black_tree_size(tree) == 0);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, UnsignedLong_new(i));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Short_compare, Short_delete);
    assert(red_black_tree_size(tree) == 0);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Short_new(N - i - 1));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    assert(red_black_tree_size(tree) == 0);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
        red_black_tree_insert(tree, Integer_new(N - i - 1));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);
}

void test_red_black_tree_clear() {
    int i = 0;
    red_black_tree_t *tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_clear(tree);
    assert(red_black_tree_is_empty(tree) == true);
    red_black_tree_delete(tree);
}

void test_red_black_tree_contains() {
    int i = 0;
    red_black_tree_t *tree = NULL;
    Integer *integer;

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = Integer_new(randint(0, 3 * N));
        if (Integer_get(integer) < N) {
            assert(red_black_tree_contains(tree, integer) == true);
        } else {
            assert(red_black_tree_contains(tree, integer) == false);
        }
        Integer_delete(integer);
    }

    red_black_tree_delete(tree);
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

void test_red_black_tree_foreach() {
    int i = 0;
    red_black_tree_t *tree = NULL;

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }

    n = 0;
    red_black_tree_foreach(tree, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    n = 0;
    red_black_tree_foreach(tree, Integer_triple);
    red_black_tree_foreach(tree, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == 3 * i);
    }

    red_black_tree_delete(tree);
}

void test_red_black_tree_insert() {
    int i = 0;
    red_black_tree_t *tree = NULL;

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
        red_black_tree_insert(tree, Integer_new(i));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i += 2) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    for (i = 1; i < N; i += 2) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    assert(red_black_tree_size(tree) == N);
    red_black_tree_delete(tree);
}

void test_red_black_tree_remove() {
    int i = 0;
    red_black_tree_t *tree = NULL;
    Integer *integer;

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        red_black_tree_remove(tree, integer);
        Integer_delete(integer);
    }
    assert(red_black_tree_is_empty(tree) == true);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        red_black_tree_remove(tree, integer);
        red_black_tree_remove(tree, integer);
        Integer_delete(integer);
    }
    assert(red_black_tree_is_empty(tree) == true);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    for (i = 0; i < N / 2; i++) {
        integer = Integer_new(N - 1 - i);
        red_black_tree_remove(tree, integer);
        Integer_delete(integer);
    }
    assert(red_black_tree_size(tree) == N / 2);
    red_black_tree_delete(tree);

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(-1 * i);
        red_black_tree_remove(tree, integer);
        Integer_delete(integer);
    }
    assert(red_black_tree_size(tree) == N - 1);
    red_black_tree_delete(tree);
}

void test_red_black_tree_iterator() {
    int i = 0;
    red_black_tree_t *tree = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    tree = red_black_tree_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        red_black_tree_insert(tree, Integer_new(i));
    }

    iterator = red_black_tree_iterator_new(tree);

    i = 0;
    while (red_black_tree_iterator_has_next(iterator)) {
        integer = (Integer *)red_black_tree_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    red_black_tree_iterator_delete(iterator);
    red_black_tree_delete(tree);
}
