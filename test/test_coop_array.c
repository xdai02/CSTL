#include "test_coop_array.h"
#include "coop.h"
#include <assert.h>

void test_array_create() {
    array_t *array = NULL;

    array = array_create(UnsignedCharacter_compare, UnsignedCharacter_delete);
    assert(array != NULL);
    assert(array_is_empty(array) == true);
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(NULL, NULL);
    assert(array == NULL);
}

void test_array_destroy() {
    array_t *array = array_create(UnsignedShort_compare, UnsignedShort_delete);
    assert(array != NULL);
    array_destroy(array);
}

static int buffer[100] = {0};
static int n = 0;

static void Integer_store(T elem) {
    Integer *integer = (Integer *)elem;
    buffer[n] = Integer_valueOf(integer);
    n++;
}

void test_array_foreach() {
    const int N = 100;
    int i = 0;

    array_t *array = NULL;

    array = array_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    array_foreach(array, Integer_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(buffer[i] == i);
    }

    array_destroy(array);
}

void test_array_is_empty() {
    array_t *array = array_create(UnsignedInteger_compare, UnsignedInteger_delete);
    assert(array_is_empty(array) == true);
    array_append(array, UnsignedInteger_new(0));
    assert(array_is_empty(array) == false);
    array_destroy(array);
}

void test_array_size() {
    const int N = 10000;
    int i = 0;
    array_t *array = array_create(UnsignedLong_compare, UnsignedLong_delete);
    assert(array_size(array) == 0);
    for (i = 0; i < N; i++) {
        array_append(array, UnsignedLong_new(i));
    }
    assert(array_size(array) == N);
    array_destroy(array);
}

void test_array_clear() {
    const int N = 100;
    int i = 0;
    array_t *array = array_create(Short_compare, Short_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Short_new(i));
    }
    assert(array_size(array) == N);
    array_clear(array);
    assert(array_size(array) == 0);
    array_destroy(array);
}

void test_array_get() {
    int i = 0;
    array_t *array = array_create(Character_compare, Character_delete);
    for (i = 'A'; i <= 'Z'; i++) {
        array_append(array, Character_new(i));
    }
    for (i = 'A'; i <= 'Z'; i++) {
        Character *c = (Character *)array_get(array, i - 'A');
        assert(Character_valueOf(c) == i);
    }
    array_destroy(array);
}

void test_array_set() {
    const int N = 10000;
    int i = 0;
    array_t *array = array_create(Long_compare, Long_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Long_new(i));
    }
    for (i = 0; i < N; i++) {
        array_set(array, i, Long_new(i * 2));
    }
    for (i = 0; i < N; i++) {
        Long *l = (Long *)array_get(array, i);
        assert(Long_valueOf(l) == i * 2);
    }
    array_destroy(array);
}

void test_array_append() {
    const int N = 10000;
    int i = 0;
    array_t *array = NULL;

    array = array_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)array_get(array, i);
        assert(Integer_valueOf(integer) == i);
    }
    array_destroy(array);

    array = array_create(Float_compare, Float_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Float_new(i));
    }
    for (i = 0; i < N; i++) {
        Float *f = (Float *)array_get(array, i);
        assert(float_equal(Float_valueOf(f), i));
    }
    array_destroy(array);
}

void test_array_insert() {
    const int N = 10000;
    int i = 0;
    array_t *array = NULL;

    array = array_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_insert(array, i, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        Integer *integer = (Integer *)array_get(array, i);
        assert(Integer_valueOf(integer) == i);
    }
    array_destroy(array);

    array = array_create(Double_compare, Double_delete);
    array_insert(array, 0, Double_new(1.1));
    array_insert(array, 0, Double_new(2.2));
    array_insert(array, 1, Double_new(3.3));
    array_insert(array, 3, Double_new(4.4));
    array_insert(array, 2, Double_new(5.5));
    assert(double_equal(Double_valueOf((Double *)array_get(array, 0)), 2.2));
    assert(double_equal(Double_valueOf((Double *)array_get(array, 1)), 3.3));
    assert(double_equal(Double_valueOf((Double *)array_get(array, 2)), 5.5));
    assert(double_equal(Double_valueOf((Double *)array_get(array, 3)), 1.1));
    assert(double_equal(Double_valueOf((Double *)array_get(array, 4)), 4.4));
    array_destroy(array);
}

void test_array_remove() {
    const int N = 10000;
    int i = 0;
    array_t *array = NULL;

    array = array_create(Integer_compare, Integer_delete);
    for (i = 0; i < N; i++) {
        array_append(array, Integer_new(i));
    }
    for (i = 0; i < N; i++) {
        array_remove(array, 0);
    }
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(Boolean_compare, Boolean_delete);
    array_append(array, Boolean_new(true));
    array_append(array, Boolean_new(false));
    array_append(array, Boolean_new(true));
    array_append(array, Boolean_new(false));
    array_append(array, Boolean_new(true));
    array_remove(array, 0);
    array_remove(array, 2);
    array_remove(array, 1);
    assert(array_size(array) == 2);
    assert(Boolean_valueOf((Boolean *)array_get(array, 0)) == false);
    assert(Boolean_valueOf((Boolean *)array_get(array, 1)) == true);
    array_destroy(array);
}
