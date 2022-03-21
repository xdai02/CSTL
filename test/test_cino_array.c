#include "test_cino_array.h"

void test_array_int_create() {
    array_int_t *arr = array_int_create();
    assert(arr);
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_destroy(arr);
}

void test_array_int_destroy() {
    array_int_t *arr = array_int_create();
    assert(arr);
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_destroy(arr);
}

void test_array_int_is_empty() {
    array_int_t *arr = array_int_create();
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 3);
    assert(!array_int_is_empty(arr));
    assert(array_int_size(arr) == 3);
    array_int_clear(arr);
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_destroy(arr);
}

void test_array_int_size() {
    array_int_t *arr = array_int_create();
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 3);
    assert(!array_int_is_empty(arr));
    assert(array_int_size(arr) == 3);
    array_int_clear(arr);
    assert(array_int_is_empty(arr));
    assert(array_int_size(arr) == 0);
    array_int_destroy(arr);
}

void test_array_int_get() {
    array_int_t *arr = array_int_create();
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 3);
    assert(array_int_get(arr, 0) == 1);
    assert(array_int_get(arr, 1) == 2);
    assert(array_int_get(arr, 2) == 3);
    array_int_destroy(arr);
}

void test_array_int_set() {
    array_int_t *arr = array_int_create();
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 3);
    assert(array_int_get(arr, 0) == 1);
    assert(array_int_get(arr, 1) == 2);
    assert(array_int_get(arr, 2) == 3);
    array_int_set(arr, 0, 9);
    array_int_set(arr, 2, 7);
    assert(array_int_get(arr, 0) == 9);
    assert(array_int_get(arr, 1) == 2);
    assert(array_int_get(arr, 2) == 7);
    array_int_destroy(arr);
}

void test_array_int_append() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 10000; i++) {
        array_int_append(arr, i);
    }
    for (int i = 0; i < 10000; i++) {
        assert(array_int_get(arr, i) == i);
    }
    array_int_destroy(arr);
}

void test_array_int_expend() {
    array_int_t *arr = array_int_create();
    int a[5] = {0, 1, 2, 3, 4};
    int len = array_len(a);
    for (int i = 0; i < 10000; i++) {
        array_int_expend(arr, a, len);
    }
    for (int i = 0; i < 10000; i += len) {
        for (int j = 0; j < len; j++) {
            assert(array_int_get(arr, i + j) == j);
        }
    }
    array_int_destroy(arr);
}