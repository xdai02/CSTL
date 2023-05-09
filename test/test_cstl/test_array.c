#include "test_array.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_array_new() {
    array_t *array = array_new(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(array != NULL);
    assert(array_is_empty(array) == true);
    assert(array_size(array) == 0);
    array_delete(array);
}

void test_array_delete() {
    array_t *array = array_new(UnsignedShort_compare, UnsignedShort_delete);
    assert(array != NULL);
    array_delete(array);
}

void test_array_is_empty() {
    array_t *array = array_new(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(array_is_empty(array) == true);
    array_append(array, UnsignedInteger_new(0));
    assert(array_is_empty(array) == false);
    array_delete(array);
}

void test_array_size() {
    int i = 0;
    array_t *array = array_new(UnsignedLong_compare, UnsignedLong_delete);
    assert(array_size(array) == 0);
    for (i = 0; i < N; i++) {
        array_append(array, UnsignedLong_new(i));
    }
    assert(array_size(array) == N);
    array_delete(array);
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

void test_array_foreach() {
    int i = 0;
    array_t *array = NULL;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }

    n = 0;
    array_foreach(array, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    array_foreach(array, Integer_triple);

    for (i = 0; i < N; i++) {
        assert(Integer_get(array_get(array, i)) == i * 3);
    }

    array_delete(array);
}

void test_array_clear() {
    int i = 0;
    array_t *array = array_new(Short_compare, Short_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Short_new(i));
    }
    assert(array_size(array) == N);
    array_clear(array);
    assert(array_is_empty(array) == true);
    array_delete(array);
}

void test_array_get() {
    int i = 0;
    array_t *array = array_new(Character_compare, Character_delete);
    for (i = 'A'; i <= 'Z'; i++) {
        array_append(array, Character_new(i));
    }
    for (i = 'A'; i <= 'Z'; i++) {
        Character *c = (Character *)array_get(array, i - 'A');
        assert(Character_get(c) == i);
    }
    array_delete(array);
}

void test_array_set() {
    int i = 0;
    array_t *array = array_new(Long_compare, Long_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Long_new(i));
    }
    for (i = 0; i < N; i++) {
        array_set(array, i, Long_new(i * 2));
    }
    for (i = 0; i < N; i++) {
        Long *l = (Long *)array_get(array, i);
        assert(Long_get(l) == i * 2);
    }
    array_delete(array);
}

void test_array_append() {
    int i = 0;
    array_t *array = NULL;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)array_get(array, i);
        assert(Integer_get(integer) == i);
    }
    array_delete(array);

    array = array_new(Float_compare, Float_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Float_new(i));
    }
    for (i = 0; i < N; i++) {
        Float *f = (Float *)array_get(array, i);
        assert(float_equal(Float_get(f), i));
    }
    array_delete(array);
}

void test_array_insert() {
    int i = 0;
    array_t *array = NULL;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_insert(array, i, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)array_get(array, i);
        assert(Integer_get(integer) == i);
    }
    array_delete(array);

    array = array_new(Double_compare, Double_delete);
    array_insert(array, 0, Double_new(1.1));
    array_insert(array, 0, Double_new(2.2));
    array_insert(array, 1, Double_new(3.3));
    array_insert(array, 3, Double_new(4.4));
    array_insert(array, 2, Double_new(5.5));
    assert(double_equal(Double_get((Double *)array_get(array, 0)), 2.2));
    assert(double_equal(Double_get((Double *)array_get(array, 1)), 3.3));
    assert(double_equal(Double_get((Double *)array_get(array, 2)), 5.5));
    assert(double_equal(Double_get((Double *)array_get(array, 3)), 1.1));
    assert(double_equal(Double_get((Double *)array_get(array, 4)), 4.4));
    array_delete(array);
}

void test_array_remove() {
    int i = 0;
    Integer *integer;
    Boolean *boolean;
    array_t *array = NULL;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = (Integer *)array_remove(array, 0);
        assert(Integer_get(integer) == i);
        Integer_delete(integer);
    }
    assert(array_is_empty(array) == true);
    array_delete(array);

    array = array_new(Boolean_compare, Boolean_delete);
    array_append(array, Boolean_new(true));
    array_append(array, Boolean_new(false));
    array_append(array, Boolean_new(true));
    array_append(array, Boolean_new(false));
    array_append(array, Boolean_new(true));

    boolean = array_remove(array, 0);
    assert(Boolean_get(boolean) == true);
    Boolean_delete(boolean);

    boolean = array_remove(array, 2);
    assert(Boolean_get(boolean) == false);
    Boolean_delete(boolean);

    boolean = array_remove(array, 1);
    assert(Boolean_get(boolean) == true);
    Boolean_delete(boolean);

    assert(array_size(array) == 2);
    assert(Boolean_get((Boolean *)array_get(array, 0)) == false);
    assert(Boolean_get((Boolean *)array_get(array, 1)) == true);
    array_delete(array);
}

void test_array_index_of() {
    int i = 0;
    Integer *integer;

    array_t *array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        integer = Integer_new(i);
        assert(array_index_of(array, integer) == i);
        Integer_delete(integer);
    }
    array_delete(array);
}

void test_array_contains() {
    int i = 0;
    Integer *integer;

    array_t *array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }

    for (i = 0; i < 2 * N; i++) {
        integer = Integer_new(i);
        if (i < N) {
            assert(array_contains(array, integer) == true);
        } else {
            assert(array_contains(array, integer) == false);
        }
        Integer_delete(integer);
    }

    array_delete(array);
}

void test_array_count() {
    array_t *array = NULL;
    Integer *integer;
    int i = 0;
    int n;

    int arr[] = {9, 1, 2, 8, 2, 5, 2, 8, 9, 1, 2, 8, 2, 5, 2, 8};
    n = sizeof(arr) / sizeof(arr[0]);

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < n; i++) {
        array_append(array, Integer_new(arr[i]));
    }

    integer = Integer_new(1);
    assert(array_count(array, integer) == 2);
    Integer_delete(integer);

    integer = Integer_new(2);
    assert(array_count(array, integer) == 6);
    Integer_delete(integer);

    integer = Integer_new(3);
    assert(array_count(array, integer) == 0);
    Integer_delete(integer);

    integer = Integer_new(5);
    assert(array_count(array, integer) == 2);
    Integer_delete(integer);

    integer = Integer_new(8);
    assert(array_count(array, integer) == 4);
    Integer_delete(integer);

    integer = Integer_new(9);
    assert(array_count(array, integer) == 2);
    Integer_delete(integer);

    array_delete(array);
}

void test_array_reverse() {
    int i = 0;
    array_t *array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    array_reverse(array);
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)array_get(array, i);
        assert(Integer_get(integer) == N - i - 1);
    }
    array_delete(array);
}

void test_array_sort() {
    int i = 0;
    array_t *array = NULL;
    Integer *integer1;
    Integer *integer2;
    Double *double1;
    Double *double2;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(randint(0, N)));
    }
    array_sort(array);
    for (i = 0; i < N - 1; i++) {
        integer1 = (Integer *)array_get(array, i);
        integer2 = (Integer *)array_get(array, i + 1);
        assert(Integer_get(integer1) <= Integer_get(integer2));
    }

    array_delete(array);

    array = array_new(Double_compare, Double_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Double_new(uniform(0, 1)));
    }
    array_sort(array);
    for (i = 0; i < N - 1; i++) {
        double1 = (Double *)array_get(array, i);
        double2 = (Double *)array_get(array, i + 1);
        assert(Double_get(double1) <= Double_get(double2));
    }
    array_delete(array);
}

void test_array_iterator() {
    int i = 0;
    array_t *array = NULL;
    iterator_t *iterator = NULL;
    Integer *integer;

    array = array_new(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }

    iterator = array_iterator_create(array);

    i = 0;
    while (array_iterator_has_next(iterator)) {
        integer = (Integer *)array_iterator_next(iterator);
        assert(Integer_get(integer) == i);
        i++;
    }

    array_iterator_destroy(iterator);
    array_delete(array);
}
