#include "test_cino_array.h"

// void test_array_create() {
//     array_t *arr = array_create("int");
//     assert(arr);
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_destroy() {
//     array_t *arr = array_create("int");
//     assert(arr);
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_int_is_empty() {
//     array_t *arr = array_create();
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 3);
//     assert(!array_int_is_empty(arr));
//     assert(array_int_size(arr) == 3);
//     array_int_clear(arr);
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_int_size() {
//     array_t *arr = array_create();
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 3);
//     assert(!array_int_is_empty(arr));
//     assert(array_int_size(arr) == 3);
//     array_int_clear(arr);
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_int_clear() {
//     array_t *arr = array_create();
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 3);
//     assert(!array_int_is_empty(arr));
//     assert(array_int_size(arr) == 3);
//     array_int_clear(arr);
//     assert(array_int_is_empty(arr));
//     assert(array_int_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_int_get() {
//     array_t *arr = array_create();
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 3);
//     assert(array_int_get(arr, 0) == 1);
//     assert(array_int_get(arr, 1) == 2);
//     assert(array_int_get(arr, 2) == 3);
//     array_destroy(arr);
// }

// void test_array_int_set() {
//     array_t *arr = array_create();
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 3);
//     assert(array_int_get(arr, 0) == 1);
//     assert(array_int_get(arr, 1) == 2);
//     assert(array_int_get(arr, 2) == 3);
//     array_int_set(arr, 0, 9);
//     array_int_set(arr, 2, 7);
//     assert(array_int_get(arr, 0) == 9);
//     assert(array_int_get(arr, 1) == 2);
//     assert(array_int_get(arr, 2) == 7);
//     array_destroy(arr);
// }

// void test_array_int_append() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 100; i++) {
//         array_int_append(arr, i);
//     }
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == i);
//     }
//     array_destroy(arr);
// }

// void test_array_int_extend() {
//     array_t *arr = array_create();
//     int a[5] = {0, 1, 2, 3, 4};
//     int len = array_len(a);
//     for (int i = 0; i < 100; i++) {
//         array_int_extend(arr, a, len);
//     }
//     for (int i = 0; i < 100; i += len) {
//         for (int j = 0; j < len; j++) {
//             assert(array_int_get(arr, i + j) == j);
//         }
//     }
//     array_destroy(arr);
// }

// void test_array_int_insert() {
//     array_t *arr = array_create();
//     array_int_insert(arr, 0, 1);
//     array_int_insert(arr, 0, 2);
//     array_int_insert(arr, 0, 3);
//     array_int_insert(arr, 1, 4);
//     array_int_insert(arr, 4, 5);
//     array_int_insert(arr, 0, 6);
//     array_int_insert(arr, 2, 7);
//     array_int_insert(arr, 2, 8);
//     assert(array_int_get(arr, 0) == 6);
//     assert(array_int_get(arr, 1) == 3);
//     assert(array_int_get(arr, 2) == 8);
//     assert(array_int_get(arr, 3) == 7);
//     assert(array_int_get(arr, 4) == 4);
//     assert(array_int_get(arr, 5) == 2);
//     assert(array_int_get(arr, 6) == 1);
//     assert(array_int_get(arr, 7) == 5);
//     array_destroy(arr);
// }

// void test_array_int_remove() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 100; i++) {
//         array_int_append(arr, i);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_int_remove(arr, 0);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_int_remove(arr, array_int_size(arr) - 1);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_int_remove(arr, 50);
//     }
//     for (int i = 0; i < 50; i++) {
//         assert(array_int_get(arr, i) == i + 10);
//     }
//     for (int i = 50; i < 70; i++) {
//         assert(array_int_get(arr, i) == i + 20);
//     }
//     array_destroy(arr);

//     arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         array_int_append(arr, i);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_int_remove(arr, 0);
//     }
//     array_destroy(arr);
// }

// void test_array_int_min() {
//     array_t *arr = array_create();
//     array_int_insert(arr, 0, 1);
//     array_int_insert(arr, 0, -2);
//     array_int_insert(arr, 0, 3);
//     array_int_insert(arr, 1, -4);
//     array_int_insert(arr, 4, 5);
//     array_int_insert(arr, 0, -6);
//     array_int_insert(arr, 2, -7);
//     array_int_insert(arr, 2, 8);
//     assert(array_int_min(arr) == -7);
//     array_destroy(arr);
// }

// void test_array_int_max() {
//     array_t *arr = array_create();
//     array_int_insert(arr, 0, 1);
//     array_int_insert(arr, 0, -2);
//     array_int_insert(arr, 0, 3);
//     array_int_insert(arr, 1, -4);
//     array_int_insert(arr, 4, 5);
//     array_int_insert(arr, 0, -6);
//     array_int_insert(arr, 2, -7);
//     array_int_insert(arr, 2, 8);
//     assert(array_int_max(arr) == 8);
//     array_destroy(arr);
// }

// void test_array_int_index_of() {
//     array_t *arr = array_create();
//     array_int_append(arr, 1);
//     array_int_append(arr, -2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 5);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 4);
//     assert(array_int_index_of(arr, 2) == 2);
//     assert(array_int_index_of(arr, 1) == 0);
//     assert(array_int_index_of(arr, 4) == 7);
//     array_destroy(arr);
// }

// void test_array_int_last_index_of() {
//     array_t *arr = array_create();
//     array_int_append(arr, 1);
//     array_int_append(arr, -2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 5);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 4);
//     assert(array_int_last_index_of(arr, 2) == 6);
//     assert(array_int_last_index_of(arr, 1) == 0);
//     assert(array_int_last_index_of(arr, 4) == 7);
//     array_destroy(arr);
// }

// void test_array_int_count() {
//     array_t *arr = array_create();
//     array_int_append(arr, 1);
//     array_int_append(arr, -2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 5);
//     array_int_append(arr, 2);
//     array_int_append(arr, 2);
//     array_int_append(arr, 4);
//     assert(array_int_count(arr, 2) == 4);
//     assert(array_int_count(arr, 1) == 1);
//     assert(array_int_count(arr, 40) == 0);
//     array_destroy(arr);
// }

// void test_array_int_reverse() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 100; i++) {
//         array_int_append(arr, i);
//     }
//     array_int_reverse(arr);
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == 100 - i - 1);
//     }
//     array_destroy(arr);
// }

// void test_array_int_swap() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 100; i++) {
//         array_int_append(arr, i);
//     }
//     int i = 0;
//     int j = 99;
//     while (i < j) {
//         array_int_swap(arr, i, j);
//         i++;
//         j--;
//     }
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == 100 - i - 1);
//     }
//     array_destroy(arr);
// }

// void test_array_int_sort() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 100; i++) {
//         array_int_append(arr, i);
//     }
//     array_int_sort(arr, false);
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == i);
//     }
//     array_destroy(arr);

//     arr = array_create();
//     for (int i = 99; i >= 0; i--) {
//         array_int_append(arr, i);
//     }
//     array_int_sort(arr, false);
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == i);
//     }
//     array_destroy(arr);

//     arr = array_create();
//     for (int i = 99; i >= 0; i--) {
//         array_int_append(arr, i);
//     }
//     array_int_sort(arr, true);
//     for (int i = 0; i < 100; i++) {
//         assert(array_int_get(arr, i) == 100 - i - 1);
//     }
//     array_destroy(arr);

//     arr = array_create();
//     int result1[] = {-7, -5, 1, 2, 5, 5, 5, 6, 78, 145};
//     int result1_len = array_len(result1);
//     array_int_append(arr, 5);
//     array_int_append(arr, 5);
//     array_int_append(arr, -5);
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 5);
//     array_int_append(arr, -7);
//     array_int_append(arr, 145);
//     array_int_append(arr, 78);
//     array_int_append(arr, 6);
//     array_int_sort(arr, false);
//     for (int i = 0; i < result1_len; i++) {
//         assert(array_int_get(arr, i) == result1[i]);
//     }
//     array_destroy(arr);

//     arr = array_create();
//     int result2[] = {145, 78, 6, 5, 5, 5, 2, 1, -5, -7};
//     int result2_len = array_len(result1);
//     array_int_append(arr, 5);
//     array_int_append(arr, 5);
//     array_int_append(arr, -5);
//     array_int_append(arr, 1);
//     array_int_append(arr, 2);
//     array_int_append(arr, 5);
//     array_int_append(arr, -7);
//     array_int_append(arr, 145);
//     array_int_append(arr, 78);
//     array_int_append(arr, 6);
//     array_int_sort(arr, true);
//     for (int i = 0; i < result2_len; i++) {
//         assert(array_int_get(arr, i) == result2[i]);
//     }
//     array_destroy(arr);
// }

// void test_array_int_iter() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         array_int_append(arr, i);
//     }
//     assert(array_int_iter(arr));
//     array_destroy(arr);
// }

// void test_array_int_iter_has_next() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         array_int_append(arr, i);
//     }
//     void *iter = array_int_iter(arr);
//     assert(iter);
//     assert(array_int_iter_has_next(arr));
//     for (int i = 0; i < 10; i++) {
//         array_int_remove(arr, 0);
//     }
//     iter = array_int_iter(arr);
//     assert(!array_int_iter_has_next(arr));
//     array_destroy(arr);
// }

// void test_array_int_iter_next() {
//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         array_int_append(arr, i);
//     }
//     int i = 0;
//     void *iter = array_int_iter(arr);
//     while (iter) {
//         assert(*(int *)iter == i);
//         iter = array_int_iter_next(arr);
//         i++;
//     }
//     array_destroy(arr);
// }

// void test_array_double_create() {
//     array_t *arr = array_double_create();
//     assert(arr);
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_destroy() {
//     array_t *arr = array_double_create();
//     assert(arr);
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_is_empty() {
//     array_t *arr = array_double_create();
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_append(arr, 1.1);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 3.3);
//     assert(!array_double_is_empty(arr));
//     assert(array_double_size(arr) == 3);
//     array_double_clear(arr);
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_size() {
//     array_t *arr = array_double_create();
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_append(arr, 1.1);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 3.3);
//     assert(!array_double_is_empty(arr));
//     assert(array_double_size(arr) == 3);
//     array_double_clear(arr);
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_clear() {
//     array_t *arr = array_double_create();
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_append(arr, 1.1);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 3.3);
//     assert(!array_double_is_empty(arr));
//     assert(array_double_size(arr) == 3);
//     array_double_clear(arr);
//     assert(array_double_is_empty(arr));
//     assert(array_double_size(arr) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_get() {
//     array_t *arr = array_double_create();
//     array_double_append(arr, 1.1);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 3.3);
//     assert(equal_double(array_double_get(arr, 0), 1.1));
//     assert(equal_double(array_double_get(arr, 1), 2.2));
//     assert(equal_double(array_double_get(arr, 2), 3.3));
//     array_double_destroy(arr);
// }

// void test_array_double_set() {
//     array_t *arr = array_double_create();
//     array_double_append(arr, 1.1);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 3.3);
//     assert(equal_double(array_double_get(arr, 0), 1.1));
//     assert(equal_double(array_double_get(arr, 1), 2.2));
//     assert(equal_double(array_double_get(arr, 2), 3.3));
//     array_double_set(arr, 0, 9.9);
//     array_double_set(arr, 2, 7.7);
//     assert(equal_double(array_double_get(arr, 0), 9.9));
//     assert(equal_double(array_double_get(arr, 1), 2.2));
//     assert(equal_double(array_double_get(arr, 2), 7.7));
//     array_double_destroy(arr);
// }

// void test_array_double_append() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 100; i++) {
//         array_double_append(arr, i);
//     }
//     for (int i = 0; i < 100; i++) {
//         assert(array_double_get(arr, i) == i);
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_extend() {
//     array_t *arr = array_double_create();
//     double a[5] = {0, 1, 2, 3, 4};
//     int len = array_len(a);
//     for (int i = 0; i < 100; i++) {
//         array_double_extend(arr, a, len);
//     }
//     for (int i = 0; i < 100; i += len) {
//         for (int j = 0; j < len; j++) {
//             assert(equal_double(array_double_get(arr, i + j), j));
//         }
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_insert() {
//     array_t *arr = array_double_create();
//     array_double_insert(arr, 0, 1.1);
//     array_double_insert(arr, 0, 2.2);
//     array_double_insert(arr, 0, 3.3);
//     array_double_insert(arr, 1, 4.4);
//     array_double_insert(arr, 4, 5.5);
//     array_double_insert(arr, 0, 6.6);
//     array_double_insert(arr, 2, 7.7);
//     array_double_insert(arr, 2, 8.8);
//     assert(equal_double(array_double_get(arr, 0), 6.6));
//     assert(equal_double(array_double_get(arr, 1), 3.3));
//     assert(equal_double(array_double_get(arr, 2), 8.8));
//     assert(equal_double(array_double_get(arr, 3), 7.7));
//     assert(equal_double(array_double_get(arr, 4), 4.4));
//     assert(equal_double(array_double_get(arr, 5), 2.2));
//     assert(equal_double(array_double_get(arr, 6), 1.1));
//     assert(equal_double(array_double_get(arr, 7), 5.5));
//     array_double_destroy(arr);
// }

// void test_array_double_remove() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 100; i++) {
//         array_double_append(arr, i);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_double_remove(arr, 0);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_double_remove(arr, array_double_size(arr) - 1);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_double_remove(arr, 50);
//     }
//     for (int i = 0; i < 00; i++) {
//         assert(equal_double(array_double_get(arr, i), i + 10));
//     }
//     for (int i = 50; i < 70; i++) {
//         assert(equal_double(array_double_get(arr, i), i + 20));
//     }
//     array_double_destroy(arr);

//     arr = array_double_create();
//     for (int i = 0; i < 10; i++) {
//         array_double_append(arr, i);
//     }
//     for (int i = 0; i < 10; i++) {
//         array_double_remove(arr, 0);
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_min() {
//     array_t *arr = array_double_create();
//     array_double_insert(arr, 0, 1);
//     array_double_insert(arr, 0, -2);
//     array_double_insert(arr, 0, 3);
//     array_double_insert(arr, 1, -4);
//     array_double_insert(arr, 4, 5);
//     array_double_insert(arr, 0, -6);
//     array_double_insert(arr, 2, -7);
//     array_double_insert(arr, 2, 8);
//     assert(equal_double(array_double_min(arr), -7));
//     array_double_destroy(arr);
// }

// void test_array_double_max() {
//     array_t *arr = array_double_create();
//     array_double_insert(arr, 0, 1);
//     array_double_insert(arr, 0, -2);
//     array_double_insert(arr, 0, 3);
//     array_double_insert(arr, 1, -4);
//     array_double_insert(arr, 4, 5);
//     array_double_insert(arr, 0, -6);
//     array_double_insert(arr, 2, -7);
//     array_double_insert(arr, 2, 8);
//     assert(equal_double(array_double_max(arr), 8));
//     array_double_destroy(arr);
// }

// void test_array_double_index_of() {
//     array_t *arr = array_double_create();
//     array_double_append(arr, 1.1);
//     array_double_append(arr, -2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 5.5);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 4.4);
//     assert(array_double_index_of(arr, 2.2) == 2);
//     assert(array_double_index_of(arr, 1.1) == 0);
//     assert(array_double_index_of(arr, 4.4) == 7);
//     array_double_destroy(arr);
// }

// void test_array_double_last_index_of() {
//     array_t *arr = array_double_create();
//     array_double_append(arr, 1.1);
//     array_double_append(arr, -2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 5.5);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 4.4);
//     assert(array_double_last_index_of(arr, 2.2) == 6);
//     assert(array_double_last_index_of(arr, 1.1) == 0);
//     assert(array_double_last_index_of(arr, 4.4) == 7);
//     array_double_destroy(arr);
// }

// void test_array_double_count() {
//     array_t *arr = array_double_create();
//     array_double_append(arr, 1.1);
//     array_double_append(arr, -2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 5.5);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 2.2);
//     array_double_append(arr, 4.4);
//     assert(array_double_count(arr, 2.2) == 4);
//     assert(array_double_count(arr, 1.1) == 1);
//     assert(array_double_count(arr, 40.0) == 0);
//     array_double_destroy(arr);
// }

// void test_array_double_reverse() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 100; i++) {
//         array_double_append(arr, i);
//     }
//     array_double_reverse(arr);
//     for (int i = 0; i < 100; i++) {
//         assert(equal_double(array_double_get(arr, i), 100 - i - 1));
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_swap() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 100; i++) {
//         array_double_append(arr, i);
//     }
//     int i = 0;
//     int j = 99;
//     while (i < j) {
//         array_double_swap(arr, i, j);
//         i++;
//         j--;
//     }
//     for (int i = 0; i < 100; i++) {
//         assert(equal_double(array_double_get(arr, i), 100 - i - 1));
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_sort() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 100; i++) {
//         array_double_append(arr, i);
//     }
//     array_double_sort(arr, false);
//     for (int i = 0; i < 100; i++) {
//         assert(equal_double(array_double_get(arr, i), i));
//     }
//     array_double_destroy(arr);

//     arr = array_double_create();
//     for (int i = 99; i >= 0; i--) {
//         array_double_append(arr, i);
//     }
//     array_double_sort(arr, false);
//     for (int i = 0; i < 100; i++) {
//         assert(equal_double(array_double_get(arr, i), i));
//     }
//     array_double_destroy(arr);

//     arr = array_double_create();
//     for (int i = 99; i >= 0; i--) {
//         array_double_append(arr, i);
//     }
//     array_double_sort(arr, true);
//     for (int i = 0; i < 100; i++) {
//         assert(equal_double(array_double_get(arr, i), 100 - i - 1));
//     }
//     array_double_destroy(arr);

//     arr = array_double_create();
//     double result1[] = {-7, -5, 1, 2, 5, 5, 5, 6, 78, 145};
//     int result1_len = array_len(result1);
//     array_double_append(arr, 5);
//     array_double_append(arr, 5);
//     array_double_append(arr, -5);
//     array_double_append(arr, 1);
//     array_double_append(arr, 2);
//     array_double_append(arr, 5);
//     array_double_append(arr, -7);
//     array_double_append(arr, 145);
//     array_double_append(arr, 78);
//     array_double_append(arr, 6);
//     array_double_sort(arr, false);
//     for (int i = 0; i < result1_len; i++) {
//         assert(equal_double(array_double_get(arr, i), result1[i]));
//     }
//     array_double_destroy(arr);

//     arr = array_double_create();
//     double result2[] = {145, 78, 6, 5, 5, 5, 2, 1, -5, -7};
//     int result2_len = array_len(result1);
//     array_double_append(arr, 5);
//     array_double_append(arr, 5);
//     array_double_append(arr, -5);
//     array_double_append(arr, 1);
//     array_double_append(arr, 2);
//     array_double_append(arr, 5);
//     array_double_append(arr, -7);
//     array_double_append(arr, 145);
//     array_double_append(arr, 78);
//     array_double_append(arr, 6);
//     array_double_sort(arr, true);
//     for (int i = 0; i < result2_len; i++) {
//         assert(equal_double(array_double_get(arr, i), result2[i]));
//     }
//     array_double_destroy(arr);
// }

// void test_array_double_iter() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 10; i++) {
//         array_double_append(arr, i);
//     }
//     assert(array_double_iter(arr));
//     array_double_destroy(arr);
// }

// void test_array_double_iter_has_next() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 10; i++) {
//         array_double_append(arr, i);
//     }
//     void *iter = array_double_iter(arr);
//     assert(iter);
//     assert(array_double_iter_has_next(arr));
//     for (int i = 0; i < 10; i++) {
//         array_double_remove(arr, 0);
//     }
//     iter = array_double_iter(arr);
//     assert(!array_double_iter_has_next(arr));
//     array_double_destroy(arr);
// }

// void test_array_double_iter_next() {
//     array_t *arr = array_double_create();
//     for (int i = 0; i < 10; i++) {
//         array_double_append(arr, i);
//     }
//     int i = 0;
//     void *iter = array_double_iter(arr);
//     while (iter) {
//         assert(equal_double(*(double *)iter, i));
//         iter = array_double_iter_next(arr);
//         i++;
//     }
//     array_double_destroy(arr);
// }

// typedef struct student_t {
//     int id;
//     char name[32];
// } student_t;

// void test_array_create() {
//     array_t *arr = array_create();
//     assert(arr);
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_destroy() {
//     array_t *arr = array_create();
//     assert(arr);
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_destroy(arr);
// }

// void test_array_is_empty() {
//     int *num1 = (int *)malloc(sizeof(int));
//     *num1 = 1;
//     int *num2 = (int *)malloc(sizeof(int));
//     *num2 = 2;
//     int *num3 = (int *)malloc(sizeof(int));
//     *num3 = 3;

//     array_t *arr = array_create();
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_append(arr, num1);
//     array_append(arr, num2);
//     array_append(arr, num3);
//     assert(!array_is_empty(arr));
//     assert(array_size(arr) == 3);
//     array_clear(arr);
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_destroy(arr);

//     free(num1);
//     free(num2);
//     free(num3);
// }

// void test_array_size() {
//     int *num1 = (int *)malloc(sizeof(int));
//     *num1 = 1;
//     int *num2 = (int *)malloc(sizeof(int));
//     *num2 = 2;
//     int *num3 = (int *)malloc(sizeof(int));
//     *num3 = 3;

//     array_t *arr = array_create();
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_append(arr, num1);
//     array_append(arr, num2);
//     array_append(arr, num3);
//     assert(!array_is_empty(arr));
//     assert(array_size(arr) == 3);
//     array_clear(arr);
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_destroy(arr);

//     free(num1);
//     free(num2);
//     free(num3);
// }

// void test_array_clear() {
//     int *num1 = (int *)malloc(sizeof(int));
//     *num1 = 1;
//     int *num2 = (int *)malloc(sizeof(int));
//     *num2 = 2;
//     int *num3 = (int *)malloc(sizeof(int));
//     *num3 = 3;

//     array_t *arr = array_create();
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_append(arr, num1);
//     array_append(arr, num2);
//     array_append(arr, num3);
//     assert(!array_is_empty(arr));
//     assert(array_size(arr) == 3);
//     array_clear(arr);
//     assert(array_is_empty(arr));
//     assert(array_size(arr) == 0);
//     array_destroy(arr);

//     free(num1);
//     free(num2);
//     free(num3);
// }

// void test_array_get() {
//     int *num1 = (int *)malloc(sizeof(int));
//     *num1 = 1;
//     int *num2 = (int *)malloc(sizeof(int));
//     *num2 = 2;
//     int *num3 = (int *)malloc(sizeof(int));
//     *num3 = 3;

//     array_t *arr = array_create();
//     array_append(arr, num1);
//     array_append(arr, num2);
//     array_append(arr, num3);
//     assert(*(int *)array_get(arr, 0) == 1);
//     assert(*(int *)array_get(arr, 1) == 2);
//     assert(*(int *)array_get(arr, 2) == 3);
//     array_destroy(arr);

//     free(num1);
//     free(num2);
//     free(num3);
// }

// void test_array_set() {
//     int *num1 = (int *)malloc(sizeof(int));
//     *num1 = 1;
//     int *num2 = (int *)malloc(sizeof(int));
//     *num2 = 2;
//     int *num3 = (int *)malloc(sizeof(int));
//     *num3 = 3;

//     array_t *arr = array_create();
//     array_append(arr, num1);
//     array_append(arr, num2);
//     array_append(arr, num3);
//     assert(*(int *)array_get(arr, 0) == 1);
//     assert(*(int *)array_get(arr, 1) == 2);
//     assert(*(int *)array_get(arr, 2) == 3);
//     *num1 = 9;
//     *num3 = 7;
//     array_set(arr, 0, num1);
//     array_set(arr, 2, num3);
//     assert(*(int *)array_get(arr, 0) == 9);
//     assert(*(int *)array_get(arr, 1) == 2);
//     assert(*(int *)array_get(arr, 2) == 7);
//     array_destroy(arr);

//     free(num1);
//     free(num2);
//     free(num3);
// }

// void test_array_append() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = i;
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", i);
//         array_append(arr, &stu[i]);
//     }
//     for (int i = 0; i < 10; i++) {
//         student_t *s = (student_t *)array_get(arr, i);
//         char name[32] = {0};
//         snprintf(name, sizeof(name), "Name-%d", i);
//         assert(s->id == i);
//         assert(strncmp(s->name, name, strlen(name)) == 0);
//     }

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_insert() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 8);
//     for (int i = 0; i < 8; i++) {
//         stu[i].id = i;
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", i);
//     }

//     array_t *arr = array_create();
//     array_insert(arr, 0, &stu[0]);
//     array_insert(arr, 0, &stu[1]);
//     array_insert(arr, 0, &stu[2]);
//     array_insert(arr, 1, &stu[3]);
//     array_insert(arr, 4, &stu[4]);
//     array_insert(arr, 0, &stu[5]);
//     array_insert(arr, 2, &stu[6]);
//     array_insert(arr, 2, &stu[7]);

//     int result[] = {5, 2, 7, 6, 3, 1, 0, 4};
//     for (int i = 0; i < 8; i++) {
//         student_t *s = (student_t *)array_get(arr, i);
//         char name[32] = {0};
//         assert(s->id == result[i]);
//         snprintf(name, sizeof(name), "Name-%d", result[i]);
//         assert(strncmp(s->name, name, strlen(name)) == 0);
//     }

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_remove() {
//     int *nums = (int *)malloc(sizeof(int) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         nums[i] = i;
//         array_append(arr, &nums[i]);
//     }
//     array_remove(arr, 3);
//     array_remove(arr, 0);
//     array_remove(arr, 7);
//     array_remove(arr, 5);
//     array_remove(arr, 0);
//     assert(*(int *)array_get(arr, 0) == 2);
//     assert(*(int *)array_get(arr, 1) == 4);
//     assert(*(int *)array_get(arr, 2) == 5);
//     assert(*(int *)array_get(arr, 3) == 6);
//     assert(*(int *)array_get(arr, 4) == 8);

//     array_destroy(arr);
//     free(nums);
// }

// static int cmp_by_id(const void *data1, const void *data2) {
//     student_t *s1 = (student_t *)data1;
//     student_t *s2 = (student_t *)data2;
//     return s1->id - s2->id;
// }

// static int cmp_by_name(const void *data1, const void *data2) {
//     student_t *s1 = (student_t *)data1;
//     student_t *s2 = (student_t *)data2;
//     return strncmp(s1->name, s2->name, strlen(s1->name));
// }

// void test_array_min() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);
//     int id[] = {4, 6, 9, 0, 1, 7, 5, 2, 3, 8};

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = id[i];
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", id[i]);
//         array_append(arr, &stu[i]);
//     }

//     student_t *s = (student_t *)array_min(arr, cmp_by_id);
//     assert(s->id == 0);
//     assert(strncmp(s->name, "Name-0", strlen("Name-0")) == 0);
//     s = (student_t *)array_min(arr, cmp_by_name);
//     assert(s->id == 0);
//     assert(strncmp(s->name, "Name-0", strlen("Name-0")) == 0);

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_max() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);
//     int id[] = {4, 6, 9, 0, 1, 7, 5, 2, 3, 8};

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = id[i];
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", id[i]);
//         array_append(arr, &stu[i]);
//     }

//     student_t *s = (student_t *)array_max(arr, cmp_by_id);
//     assert(s->id == 9);
//     assert(strncmp(s->name, "Name-9", strlen("Name-9")) == 0);
//     s = (student_t *)array_max(arr, cmp_by_name);
//     assert(s->id == 9);
//     assert(strncmp(s->name, "Name-9", strlen("Name-9")) == 0);

//     array_destroy(arr);
//     free(stu);
// }

// static bool match_by_id(const void *data) {
//     student_t *s = (student_t *)data;
//     return s->id == 5;
// }

// void test_array_find() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);
//     int id[] = {4, 6, 5, 5, 1, 7, 5, 2, 3, 5};

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = id[i];
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", id[i]);
//         array_append(arr, &stu[i]);
//     }

//     student_t *s = (student_t *)array_find(arr, match_by_id);
//     assert(s->id == 5);
//     assert(strncmp(s->name, "Name-5", strlen("Name-5")) == 0);

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_count() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);
//     int id[] = {4, 6, 5, 5, 1, 7, 5, 2, 3, 5};

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = id[i];
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", id[i]);
//         array_append(arr, &stu[i]);
//     }
//     assert(array_count(arr, match_by_id) == 4);

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_reverse() {
//     int *nums = (int *)malloc(sizeof(int) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         nums[i] = i;
//         array_append(arr, &nums[i]);
//     }
//     array_reverse(arr);
//     for (int i = 0; i < 10; i++) {
//         assert(*(int *)array_get(arr, i) == 10 - i - 1);
//     }

//     array_destroy(arr);
//     free(nums);
// }

// void test_array_swap() {
//     int *nums = (int *)malloc(sizeof(int) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         nums[i] = i;
//         array_append(arr, &nums[i]);
//     }
//     int i = 0;
//     int j = 9;
//     while (i < j) {
//         array_swap(arr, i, j);
//         i++;
//         j--;
//     }
//     for (int i = 0; i < 10; i++) {
//         assert(*(int *)array_get(arr, i) == 10 - i - 1);
//     }

//     array_destroy(arr);
//     free(nums);
// }

// void test_array_sort() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);
//     int id[] = {4, 6, 9, 0, 1, 7, 5, 2, 3, 8};

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = id[i];
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", id[i]);
//         array_append(arr, &stu[i]);
//     }

//     array_sort(arr, cmp_by_id);
//     for (int i = 0; i < 10; i++) {
//         student_t *s = (student_t *)array_get(arr, i);
//         char name[32] = {0};
//         snprintf(name, sizeof(name), "Name-%d", i);
//         assert(s->id == i);
//         assert(strncmp(s->name, name, strlen(name)) == 0);
//     }

//     array_sort(arr, cmp_by_name);
//     for (int i = 0; i < 10; i++) {
//         student_t *s = (student_t *)array_get(arr, i);
//         char name[32] = {0};
//         snprintf(name, sizeof(name), "Name-%d", i);
//         assert(s->id == i);
//         assert(strncmp(s->name, name, strlen(name)) == 0);
//     }

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_iter() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = i;
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", i);
//         array_append(arr, &stu[i]);
//     }
//     assert(array_iter(arr));

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_iter_has_next() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = i;
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", i);
//         array_append(arr, &stu[i]);
//     }
//     void *iter = array_iter(arr);
//     assert(iter);
//     assert(array_iter_has_next(arr));
//     for (int i = 0; i < 10; i++) {
//         array_remove(arr, 0);
//     }
//     iter = array_iter(arr);
//     assert(!array_iter_has_next(arr));

//     array_destroy(arr);
//     free(stu);
// }

// void test_array_iter_next() {
//     student_t *stu = (student_t *)malloc(sizeof(student_t) * 10);

//     array_t *arr = array_create();
//     for (int i = 0; i < 10; i++) {
//         stu[i].id = i;
//         snprintf(stu[i].name, sizeof(stu[i].name), "Name-%d", i);
//         array_append(arr, &stu[i]);
//     }

//     int i = 0;
//     void *iter = array_iter(arr);
//     while (iter) {
//         student_t *s = (student_t *)iter;
//         char name[32] = {0};
//         snprintf(name, sizeof(name), "Name-%d", i);
//         assert(s->id == i);
//         assert(strncmp(s->name, name, strlen(name)) == 0);
//         iter = array_iter_next(arr);
//         i++;
//     }

//     array_destroy(arr);
//     free(stu);
// }