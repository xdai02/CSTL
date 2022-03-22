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
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == i);
    }
    array_int_destroy(arr);
}

void test_array_int_extend() {
    array_int_t *arr = array_int_create();
    int a[5] = {0, 1, 2, 3, 4};
    int len = array_len(a);
    for (int i = 0; i < 100; i++) {
        array_int_extend(arr, a, len);
    }
    for (int i = 0; i < 100; i += len) {
        for (int j = 0; j < len; j++) {
            assert(array_int_get(arr, i + j) == j);
        }
    }
    array_int_destroy(arr);
}

void test_array_int_insert() {
    array_int_t *arr = array_int_create();
    array_int_insert(arr, 0, 1);
    array_int_insert(arr, 0, 2);
    array_int_insert(arr, 0, 3);
    array_int_insert(arr, 1, 4);
    array_int_insert(arr, 4, 5);
    array_int_insert(arr, 0, 6);
    array_int_insert(arr, 2, 7);
    array_int_insert(arr, 2, 8);
    assert(array_int_get(arr, 0) == 6);
    assert(array_int_get(arr, 1) == 3);
    assert(array_int_get(arr, 2) == 8);
    assert(array_int_get(arr, 3) == 7);
    assert(array_int_get(arr, 4) == 4);
    assert(array_int_get(arr, 5) == 2);
    assert(array_int_get(arr, 6) == 1);
    assert(array_int_get(arr, 7) == 5);
    array_int_destroy(arr);
}

void test_array_int_remove() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 1000; i++) {
        array_int_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        array_int_remove(arr, 0);
    }
    for (int i = 0; i < 100; i++) {
        array_int_remove(arr, array_int_size(arr) - 1);
    }
    for (int i = 0; i < 100; i++) {
        array_int_remove(arr, 500);
    }
    for (int i = 0; i < 500; i++) {
        assert(array_int_get(arr, i) == i + 100);
    }
    for (int i = 500; i < 700; i++) {
        assert(array_int_get(arr, i) == i + 200);
    }
    array_int_destroy(arr);

    arr = array_int_create();
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        array_int_remove(arr, 0);
    }
    array_int_destroy(arr);
}

void test_array_int_min() {
    array_int_t *arr = array_int_create();
    array_int_insert(arr, 0, 1);
    array_int_insert(arr, 0, -2);
    array_int_insert(arr, 0, 3);
    array_int_insert(arr, 1, -4);
    array_int_insert(arr, 4, 5);
    array_int_insert(arr, 0, -6);
    array_int_insert(arr, 2, -7);
    array_int_insert(arr, 2, 8);
    assert(array_int_min(arr) == -7);
    array_int_destroy(arr);
}

void test_array_int_max() {
    array_int_t *arr = array_int_create();
    array_int_insert(arr, 0, 1);
    array_int_insert(arr, 0, -2);
    array_int_insert(arr, 0, 3);
    array_int_insert(arr, 1, -4);
    array_int_insert(arr, 4, 5);
    array_int_insert(arr, 0, -6);
    array_int_insert(arr, 2, -7);
    array_int_insert(arr, 2, 8);
    assert(array_int_max(arr) == 8);
    array_int_destroy(arr);
}

void test_array_int_index_of() {
    array_int_t *arr = array_int_create();
    array_int_append(arr, 1);
    array_int_append(arr, -2);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 5);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 4);
    assert(array_int_index_of(arr, 2) == 2);
    assert(array_int_index_of(arr, 1) == 0);
    assert(array_int_index_of(arr, 4) == 7);
    array_int_destroy(arr);
}

void test_array_int_last_index_of() {
    array_int_t *arr = array_int_create();
    array_int_append(arr, 1);
    array_int_append(arr, -2);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 5);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 4);
    assert(array_int_last_index_of(arr, 2) == 6);
    assert(array_int_last_index_of(arr, 1) == 0);
    assert(array_int_last_index_of(arr, 4) == 7);
    array_int_destroy(arr);
}

void test_array_int_count() {
    array_int_t *arr = array_int_create();
    array_int_append(arr, 1);
    array_int_append(arr, -2);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 5);
    array_int_append(arr, 2);
    array_int_append(arr, 2);
    array_int_append(arr, 4);
    assert(array_int_count(arr, 2) == 4);
    assert(array_int_count(arr, 1) == 1);
    assert(array_int_count(arr, 40) == 0);
    array_int_destroy(arr);
}

void test_array_int_reverse() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    array_int_reverse(arr);
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == 100 - i - 1);
    }
    array_int_destroy(arr);
}

void test_array_int_swap() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    int i = 0;
    int j = 99;
    while (i < j) {
        array_int_swap(arr, i, j);
        i++;
        j--;
    }
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == 100 - i - 1);
    }
    array_int_destroy(arr);
}

void test_array_int_sort() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    array_int_sort(arr, false);
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == i);
    }
    array_int_destroy(arr);

    arr = array_int_create();
    for (int i = 99; i >= 0; i--) {
        array_int_append(arr, i);
    }
    array_int_sort(arr, false);
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == i);
    }
    array_int_destroy(arr);

    arr = array_int_create();
    for (int i = 99; i >= 0; i--) {
        array_int_append(arr, i);
    }
    array_int_sort(arr, true);
    for (int i = 0; i < 100; i++) {
        assert(array_int_get(arr, i) == 100 - i - 1);
    }
    array_int_destroy(arr);

    arr = array_int_create();
    int result1[] = {-7, -5, 1, 2, 5, 5, 5, 6, 78, 145};
    int result1_len = array_len(result1);
    array_int_append(arr, 5);
    array_int_append(arr, 5);
    array_int_append(arr, -5);
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 5);
    array_int_append(arr, -7);
    array_int_append(arr, 145);
    array_int_append(arr, 78);
    array_int_append(arr, 6);
    array_int_sort(arr, false);
    for (int i = 0; i < result1_len; i++) {
        assert(array_int_get(arr, i) == result1[i]);
    }
    array_int_destroy(arr);

    arr = array_int_create();
    int result2[] = {145, 78, 6, 5, 5, 5, 2, 1, -5, -7};
    int result2_len = array_len(result1);
    array_int_append(arr, 5);
    array_int_append(arr, 5);
    array_int_append(arr, -5);
    array_int_append(arr, 1);
    array_int_append(arr, 2);
    array_int_append(arr, 5);
    array_int_append(arr, -7);
    array_int_append(arr, 145);
    array_int_append(arr, 78);
    array_int_append(arr, 6);
    array_int_sort(arr, true);
    for (int i = 0; i < result2_len; i++) {
        assert(array_int_get(arr, i) == result2[i]);
    }
    array_int_destroy(arr);
}

void test_array_int_iter_begin() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 10; i++) {
        array_int_append(arr, i);
    }
    assert(array_int_iter_begin(arr));
    array_int_destroy(arr);
}

void test_array_int_iter_end() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 10; i++) {
        array_int_append(arr, i);
    }
    assert(array_int_iter_end(arr));
    array_int_destroy(arr);
}

void test_array_int_iter_next() {
    array_int_t *arr = array_int_create();
    for (int i = 0; i < 100; i++) {
        array_int_append(arr, i);
    }
    void *iter = array_int_iter_begin(arr);
    void *end = array_int_iter_end(arr);
    int i = 0;
    while (iter != end) {
        assert(*(int *)iter == i);
        iter = array_int_iter_next(iter);
        i++;
    }
    array_int_destroy(arr);
}

void test_array_double_create() {
    array_double_t *arr = array_double_create();
    assert(arr);
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_destroy(arr);
}

void test_array_double_destroy() {
    array_double_t *arr = array_double_create();
    assert(arr);
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_destroy(arr);
}

void test_array_double_is_empty() {
    array_double_t *arr = array_double_create();
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_append(arr, 1.1);
    array_double_append(arr, 2.2);
    array_double_append(arr, 3.3);
    assert(!array_double_is_empty(arr));
    assert(array_double_size(arr) == 3);
    array_double_clear(arr);
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_destroy(arr);
}

void test_array_double_size() {
    array_double_t *arr = array_double_create();
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_append(arr, 1.1);
    array_double_append(arr, 2.2);
    array_double_append(arr, 3.3);
    assert(!array_double_is_empty(arr));
    assert(array_double_size(arr) == 3);
    array_double_clear(arr);
    assert(array_double_is_empty(arr));
    assert(array_double_size(arr) == 0);
    array_double_destroy(arr);
}

void test_array_double_get() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    array_double_append(arr, 1.1);
    array_double_append(arr, 2.2);
    array_double_append(arr, 3.3);
    assert(fabs(array_double_get(arr, 0) - 1.1) <= eps);
    assert(fabs(array_double_get(arr, 1) - 2.2) <= eps);
    assert(fabs(array_double_get(arr, 2) - 3.3) <= eps);
    array_double_destroy(arr);
}

void test_array_double_set() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    array_double_append(arr, 1.1);
    array_double_append(arr, 2.2);
    array_double_append(arr, 3.3);
    assert(fabs(array_double_get(arr, 0) - 1.1) <= eps);
    assert(fabs(array_double_get(arr, 1) - 2.2) <= eps);
    assert(fabs(array_double_get(arr, 2) - 3.3) <= eps);
    array_double_set(arr, 0, 9.9);
    array_double_set(arr, 2, 7.7);
    assert(fabs(array_double_get(arr, 0) - 9.9) <= eps);
    assert(fabs(array_double_get(arr, 1) - 2.2) <= eps);
    assert(fabs(array_double_get(arr, 2) - 7.7) <= eps);
    array_double_destroy(arr);
}

void test_array_double_append() {
    array_double_t *arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        assert(array_double_get(arr, i) == i);
    }
    array_double_destroy(arr);
}

void test_array_double_extend() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    double a[5] = {0, 1, 2, 3, 4};
    int len = array_len(a);
    for (int i = 0; i < 100; i++) {
        array_double_extend(arr, a, len);
    }
    for (int i = 0; i < 100; i += len) {
        for (int j = 0; j < len; j++) {
            assert(fabs(array_double_get(arr, i + j) - j) <= eps);
        }
    }
    array_double_destroy(arr);
}

void test_array_double_insert() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    array_double_insert(arr, 0, 1.1);
    array_double_insert(arr, 0, 2.2);
    array_double_insert(arr, 0, 3.3);
    array_double_insert(arr, 1, 4.4);
    array_double_insert(arr, 4, 5.5);
    array_double_insert(arr, 0, 6.6);
    array_double_insert(arr, 2, 7.7);
    array_double_insert(arr, 2, 8.8);
    assert(fabs(array_double_get(arr, 0) - 6.6) <= eps);
    assert(fabs(array_double_get(arr, 1) - 3.3) <= eps);
    assert(fabs(array_double_get(arr, 2) - 8.8) <= eps);
    assert(fabs(array_double_get(arr, 3) - 7.7) <= eps);
    assert(fabs(array_double_get(arr, 4) - 4.4) <= eps);
    assert(fabs(array_double_get(arr, 5) - 2.2) <= eps);
    assert(fabs(array_double_get(arr, 6) - 1.1) <= eps);
    assert(fabs(array_double_get(arr, 7) - 5.5) <= eps);
    array_double_destroy(arr);
}

void test_array_double_remove() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    for (int i = 0; i < 1000; i++) {
        array_double_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        array_double_remove(arr, 0);
    }
    for (int i = 0; i < 100; i++) {
        array_double_remove(arr, array_double_size(arr) - 1);
    }
    for (int i = 0; i < 100; i++) {
        array_double_remove(arr, 500);
    }
    for (int i = 0; i < 500; i++) {
        assert(fabs(array_double_get(arr, i) - (i + 100)) <= eps);
    }
    for (int i = 500; i < 700; i++) {
        assert(fabs(array_double_get(arr, i) - (i + 200)) <= eps);
    }
    array_double_destroy(arr);

    arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    for (int i = 0; i < 100; i++) {
        array_double_remove(arr, 0);
    }
    array_double_destroy(arr);
}

void test_array_double_min() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    array_double_insert(arr, 0, 1);
    array_double_insert(arr, 0, -2);
    array_double_insert(arr, 0, 3);
    array_double_insert(arr, 1, -4);
    array_double_insert(arr, 4, 5);
    array_double_insert(arr, 0, -6);
    array_double_insert(arr, 2, -7);
    array_double_insert(arr, 2, 8);
    assert(fabs(array_double_min(arr) - (-7)) <= eps);
    array_double_destroy(arr);
}

void test_array_double_max() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    array_double_insert(arr, 0, 1);
    array_double_insert(arr, 0, -2);
    array_double_insert(arr, 0, 3);
    array_double_insert(arr, 1, -4);
    array_double_insert(arr, 4, 5);
    array_double_insert(arr, 0, -6);
    array_double_insert(arr, 2, -7);
    array_double_insert(arr, 2, 8);
    assert(fabs(array_double_max(arr) - 8) <= eps);
    array_double_destroy(arr);
}

void test_array_double_reverse() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    array_double_reverse(arr);
    for (int i = 0; i < 100; i++) {
        assert(fabs(array_double_get(arr, i) - (100 - i - 1)) <= eps);
    }
    array_double_destroy(arr);
}

void test_array_double_swap() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    int i = 0;
    int j = 99;
    while (i < j) {
        array_double_swap(arr, i, j);
        i++;
        j--;
    }
    for (int i = 0; i < 100; i++) {
        assert(fabs(array_double_get(arr, i) - (100 - i - 1)) <= eps);
    }
    array_double_destroy(arr);
}

void test_array_double_sort() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    array_double_sort(arr, false);
    for (int i = 0; i < 100; i++) {
        assert(fabs(array_double_get(arr, i) - i) <= eps);
    }
    array_double_destroy(arr);

    arr = array_double_create();
    for (int i = 99; i >= 0; i--) {
        array_double_append(arr, i);
    }
    array_double_sort(arr, false);
    for (int i = 0; i < 100; i++) {
        assert(fabs(array_double_get(arr, i) - i) <= eps);
    }
    array_double_destroy(arr);

    arr = array_double_create();
    for (int i = 99; i >= 0; i--) {
        array_double_append(arr, i);
    }
    array_double_sort(arr, true);
    for (int i = 0; i < 100; i++) {
        assert(fabs(array_double_get(arr, i) - (100 - i - 1)) <= eps);
    }
    array_double_destroy(arr);

    arr = array_double_create();
    double result1[] = {-7, -5, 1, 2, 5, 5, 5, 6, 78, 145};
    int result1_len = array_len(result1);
    array_double_append(arr, 5);
    array_double_append(arr, 5);
    array_double_append(arr, -5);
    array_double_append(arr, 1);
    array_double_append(arr, 2);
    array_double_append(arr, 5);
    array_double_append(arr, -7);
    array_double_append(arr, 145);
    array_double_append(arr, 78);
    array_double_append(arr, 6);
    array_double_sort(arr, false);
    for (int i = 0; i < result1_len; i++) {
        assert(fabs(array_double_get(arr, i) - result1[i]) <= eps);
    }
    array_double_destroy(arr);

    arr = array_double_create();
    double result2[] = {145, 78, 6, 5, 5, 5, 2, 1, -5, -7};
    int result2_len = array_len(result1);
    array_double_append(arr, 5);
    array_double_append(arr, 5);
    array_double_append(arr, -5);
    array_double_append(arr, 1);
    array_double_append(arr, 2);
    array_double_append(arr, 5);
    array_double_append(arr, -7);
    array_double_append(arr, 145);
    array_double_append(arr, 78);
    array_double_append(arr, 6);
    array_double_sort(arr, true);
    for (int i = 0; i < result2_len; i++) {
        assert(fabs(array_double_get(arr, i) - result2[i]) <= eps);
    }
    array_double_destroy(arr);
}

void test_array_double_iter_begin() {
    array_double_t *arr = array_double_create();
    for (int i = 0; i < 10; i++) {
        array_double_append(arr, i);
    }
    assert(array_double_iter_begin(arr));
    array_double_destroy(arr);
}

void test_array_double_iter_end() {
    array_double_t *arr = array_double_create();
    for (int i = 0; i < 10; i++) {
        array_double_append(arr, i);
    }
    assert(array_double_iter_end(arr));
    array_double_destroy(arr);
}

void test_array_double_iter_next() {
    const double eps = 1e-6;

    array_double_t *arr = array_double_create();
    for (int i = 0; i < 100; i++) {
        array_double_append(arr, i);
    }
    void *iter = array_double_iter_begin(arr);
    void *end = array_double_iter_end(arr);
    int i = 0;
    while (iter != end) {
        assert(fabs(*(double *)iter - i) <= eps);
        iter = array_double_iter_next(iter);
        i++;
    }
    array_double_destroy(arr);
}