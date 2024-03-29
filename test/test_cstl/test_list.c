#include "test_list.h"
#include "cstl.h"
#include <assert.h>

#define N 1000

void test_list_new() {
    list_t *list = list_new(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(list != NULL);
    assert(list_is_empty(list) == true);
    assert(list_size(list) == 0);
    list_delete(list);
}

void test_list_delete() {
    list_t *list = list_new(UnsignedShort_compare, UnsignedShort_delete);
    assert(list != NULL);
    list_delete(list);
}

void test_list_is_empty() {
    list_t *list = list_new(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(list_is_empty(list) == true);
    list_push_back(list, UnsignedInteger_new(0));
    assert(list_is_empty(list) == false);
    list_delete(list);
}

void test_list_size() {
    int i = 0;
    list_t *list = list_new(UnsignedLong_compare, UnsignedLong_delete);
    assert(list_size(list) == 0);
    for (i = 0; i < N; i++) {
        list_push_back(list, UnsignedLong_new(i));
    }
    assert(list_size(list) == N);
    list_delete(list);
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

void test_list_foreach() {
    int i = 0;
    list_t *list = NULL;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    n = 0;
    list_foreach(list, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    list_foreach(list, Integer_triple);

    for (i = 0; i < N; i++) {
        assert(Integer_get(list_get(list, i)) == i * 3);
    }

    list_delete(list);
}

void test_list_clear() {
    int i = 0;
    list_t *list = list_new(Short_compare, Short_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Short_new(i));
    }
    assert(list_size(list) == N);
    list_clear(list);
    assert(list_is_empty(list) == true);
    list_delete(list);
}

void test_list_get() {
    int i = 0;
    list_t *list = list_new(Character_compare, Character_delete);
    for (i = 'A'; i <= 'Z'; i++) {
        list_push_back(list, Character_new(i));
    }
    for (i = 'A'; i <= 'Z'; i++) {
        Character *c = (Character *)list_get(list, i - 'A');
        assert(Character_get(c) == i);
    }
    list_delete(list);
}

void test_list_set() {
    int i = 0;

    list_t *list = list_new(Long_compare, Long_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Long_new(i));
    }
    for (i = 0; i < N; i++) {
        list_set(list, i, Long_new(i * 2));
    }
    for (i = 0; i < N; i++) {
        Long *l = (Long *)list_get(list, i);
        assert(Long_get(l) == i * 2);
    }
    list_delete(list);
}

void test_list_index_of() {
    int i = 0;
    Integer *integer;

    list_t *list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        assert(list_index_of(list, integer) == i);
        Integer_delete(integer);
    }
    list_delete(list);
}

void test_list_contains() {
    int i = 0;
    Integer *integer;

    list_t *list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    for (i = 0; i < 2 * N; i++) {
        integer = Integer_new(i);
        if (i < N) {
            assert(list_contains(list, integer) == true);
        } else {
            assert(list_contains(list, integer) == false);
        }
        Integer_delete(integer);
    }

    list_delete(list);
}

void test_list_count() {
    list_t *list = NULL;
    Integer *integer;
    int i = 0;
    int n;

    int arr[] = {9, 1, 2, 8, 2, 5, 2, 8, 9, 1, 2, 8, 2, 5, 2, 8};
    n = sizeof(arr) / sizeof(arr[0]);

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < n; i++) {
        list_push_back(list, Integer_new(arr[i]));
    }

    integer = Integer_new(1);
    assert(list_count(list, integer) == 2);
    Integer_delete(integer);

    integer = Integer_new(2);
    assert(list_count(list, integer) == 6);
    Integer_delete(integer);

    integer = Integer_new(3);
    assert(list_count(list, integer) == 0);
    Integer_delete(integer);

    integer = Integer_new(5);
    assert(list_count(list, integer) == 2);
    Integer_delete(integer);

    integer = Integer_new(8);
    assert(list_count(list, integer) == 4);
    Integer_delete(integer);

    integer = Integer_new(9);
    assert(list_count(list, integer) == 2);
    Integer_delete(integer);

    list_delete(list);
}

void test_list_get_front() {
    int i = 0;
    list_t *list = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    integer = (Integer *)list_get_front(list);
    assert(Integer_get(integer) == 0);

    list_delete(list);
}

void test_list_get_back() {
    int i = 0;
    list_t *list = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    integer = (Integer *)list_get_back(list);
    assert(Integer_get(integer) == N - 1);

    list_delete(list);
}

void test_list_push_front() {
    int i = 0;
    list_t *list = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_front(list, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = (Integer *)list_get(list, i);
        assert(Integer_get(integer) == N - 1 - i);
    }

    list_delete(list);
}

void test_list_push_back() {
    int i = 0;
    list_t *list = NULL;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)list_get(list, i);
        assert(Integer_get(integer) == i);
    }
    list_delete(list);

    list = list_new(Float_compare, Float_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Float_new(i));
    }
    for (i = 0; i < N; i++) {
        Float *f = (Float *)list_get(list, i);
        assert(float_equal(Float_get(f), i));
    }
    list_delete(list);
}

void test_list_pop_front() {
    int i = 0;
    list_t *list = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = (Integer *)list_pop_front(list);
        assert(Integer_get(integer) == i);
        Integer_delete(integer);
    }

    list_delete(list);
}

void test_list_pop_back() {
    int i = 0;
    list_t *list = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    for (i = 0; i < N; i++) {
        integer = (Integer *)list_pop_back(list);
        assert(Integer_get(integer) == N - 1 - i);
        Integer_delete(integer);
    }

    list_delete(list);
}

void test_list_insert() {
    int i = 0;
    list_t *list = NULL;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_insert(list, i, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)list_get(list, i);
        assert(Integer_get(integer) == i);
    }
    list_delete(list);

    list = list_new(Double_compare, Double_delete);
    list_insert(list, 0, Double_new(1.1));
    list_insert(list, 0, Double_new(2.2));
    list_insert(list, 1, Double_new(3.3));
    list_insert(list, 3, Double_new(4.4));
    list_insert(list, 2, Double_new(5.5));
    assert(double_equal(Double_get((Double *)list_get(list, 0)), 2.2));
    assert(double_equal(Double_get((Double *)list_get(list, 1)), 3.3));
    assert(double_equal(Double_get((Double *)list_get(list, 2)), 5.5));
    assert(double_equal(Double_get((Double *)list_get(list, 3)), 1.1));
    assert(double_equal(Double_get((Double *)list_get(list, 4)), 4.4));
    list_delete(list);
}

void test_list_remove() {
    int i = 0;
    Integer *integer;
    Boolean *boolean;
    list_t *list = NULL;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = (Integer *)list_remove(list, 0);
        assert(Integer_get(integer) == i);
        Integer_delete(integer);
    }
    assert(list_is_empty(list) == true);
    list_delete(list);

    list = list_new(Boolean_compare, Boolean_delete);
    list_push_back(list, Boolean_new(true));
    list_push_back(list, Boolean_new(false));
    list_push_back(list, Boolean_new(true));
    list_push_back(list, Boolean_new(false));
    list_push_back(list, Boolean_new(true));

    boolean = list_remove(list, 0);
    assert(Boolean_get(boolean) == true);
    Boolean_delete(boolean);

    boolean = list_remove(list, 2);
    assert(Boolean_get(boolean) == false);
    Boolean_delete(boolean);

    boolean = list_remove(list, 1);
    assert(Boolean_get(boolean) == true);
    Boolean_delete(boolean);

    assert(list_size(list) == 2);
    assert(Boolean_get((Boolean *)list_get(list, 0)) == false);
    assert(Boolean_get((Boolean *)list_get(list, 1)) == true);
    list_delete(list);
}

void test_list_reverse() {
    int i = 0;
    list_t *list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }
    list_reverse(list);
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)list_get(list, i);
        assert(Integer_get(integer) == N - i - 1);
    }
    list_delete(list);
}

void test_list_iterator() {
    int i = 0;
    list_t *list = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    list = list_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        list_push_back(list, Integer_new(i));
    }

    iterator = list_iterator_new(list);

    i = 0;
    while (list_iterator_has_next(iterator)) {
        integer = (Integer *)list_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    list_iterator_delete(iterator);
    list_delete(list);
}
