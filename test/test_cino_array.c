#include "test_cino_array.h"

typedef struct test_t {
    int a;
    char p[16];
} test_t;

void test_array_create() {
    array_t *arr = array_create("int");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_destroy() {
    array_t *arr = array_create("int");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_is_empty() {
    array_t *arr = array_create("int");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_size() {
    array_t *arr = array_create("int");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T");
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_clear() {
    array_t *arr = array_create("int");
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double");
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T");
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_get() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == i);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double(i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(unwrap_double(wrapper) == i);
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_set() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 3; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }

    wrapper_int_t *wrapper_int = wrap_int(9);
    array_set(arr, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(7);
    array_set(arr, 2, wrapper_int);
    unwrap_int(wrapper_int);

    wrapper_int = (wrapper_int_t *)array_get(arr, 0);
    assert(unwrap_int(wrapper_int) == 9);
    wrapper_int = (wrapper_int_t *)array_get(arr, 1);
    assert(unwrap_int(wrapper_int) == 1);
    wrapper_int = (wrapper_int_t *)array_get(arr, 2);
    assert(unwrap_int(wrapper_int) == 7);
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 3; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }

    wrapper_double_t *wrapper_double = wrap_double(9.9);
    array_set(arr, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(7.7);
    array_set(arr, 2, wrapper_double);
    unwrap_double(wrapper_double);

    wrapper_double = (wrapper_double_t *)array_get(arr, 0);
    assert(equal_double(unwrap_double(wrapper_double), 9.9));
    wrapper_double = (wrapper_double_t *)array_get(arr, 1);
    assert(equal_double(unwrap_double(wrapper_double), 1.0));
    wrapper_double = (wrapper_double_t *)array_get(arr, 2);
    assert(equal_double(unwrap_double(wrapper_double), 7.7));
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 3);
    for (int i = 0; i < 3; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }

    test[0].a = 9;
    str_copy(test[0].p, "9");
    array_set(arr, 0, &test[0]);
    test[2].a = 7;
    str_copy(test[2].p, "7");
    array_set(arr, 2, &test[2]);

    test_t *t = (test_t *)array_get(arr, 0);
    assert(t->a == 9);
    assert(str_equal(t->p, "9"));
    t = (test_t *)array_get(arr, 1);
    assert(t->a == 1);
    assert(str_equal(t->p, "1"));
    t = (test_t *)array_get(arr, 2);
    assert(t->a == 7);
    assert(str_equal(t->p, "7"));

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_append() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == i);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)i));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_insert() {
    int arr1[] = {5, 1, 9, 7, 4};
    int len1 = array_len(arr1);
    array_t *arr = array_create("int");

    wrapper_int_t *wrapper_int = wrap_int(1);
    array_insert(arr, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(5);
    array_insert(arr, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(7);
    array_insert(arr, 2, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(4);
    array_insert(arr, 3, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(9);
    array_insert(arr, 2, wrapper_int);
    unwrap_int(wrapper_int);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == arr1[i]);
    }
    array_destroy(arr);

    double arr2[] = {5.5, 1.1, 9.9, 7.7, 4.4};
    int len2 = array_len(arr2);
    arr = array_create("double");

    wrapper_double_t *wrapper_double = wrap_double(1.1);
    array_insert(arr, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(5.5);
    array_insert(arr, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(7.7);
    array_insert(arr, 2, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(4.4);
    array_insert(arr, 3, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(9.9);
    array_insert(arr, 2, wrapper_double);
    unwrap_double(wrapper_double);

    for (int i = 0; i < len2; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), arr2[i]));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    int arr3[] = {1, 4, 3, 2, 0};
    int len3 = array_len(arr3);

    for (int i = 0; i < len3; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
    }

    array_insert(arr, 0, &test[3]);
    array_insert(arr, 0, &test[1]);
    array_insert(arr, 2, &test[0]);
    array_insert(arr, 1, &test[4]);
    array_insert(arr, 3, &test[2]);

    for (int i = 0; i < len3; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == arr3[i]);
        char p[8] = {0};
        int_to_str(arr3[i], p, sizeof(p));
        assert(str_equal(t->p, p));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_remove() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    array_remove(arr, 2);
    array_remove(arr, 1);
    array_remove(arr, 0);
    array_remove(arr, 5);
    array_remove(arr, 5);
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == i + 3);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    array_remove(arr, 2);
    array_remove(arr, 1);
    array_remove(arr, 0);
    array_remove(arr, 5);
    array_remove(arr, 5);
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)(i + 3)));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 10);
    for (int i = 0; i < 10; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    array_remove(arr, 2);
    array_remove(arr, 1);
    array_remove(arr, 0);
    array_remove(arr, 5);
    array_remove(arr, 5);
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == i + 3);
        char p[8] = {0};
        int_to_str(i + 3, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    array_destroy(arr);
}

static int cmp_by_int(const void *data1, const void *data2) {
    test_t *t1 = (test_t *)data1;
    test_t *t2 = (test_t *)data2;
    return t1->a - t2->a;
}

static int cmp_by_str(const void *data1, const void *data2) {
    test_t *t1 = (test_t *)data1;
    test_t *t2 = (test_t *)data2;
    return strncmp(t1->p, t2->p, strlen(t1->p));
}

void test_array_min() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = array_len(arr1);
    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_min(arr, NULL);
    assert(unwrap_int(wrapper_int) == 1);
    array_destroy(arr);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = array_len(arr2);
    arr = array_create("double");
    for (int i = 0; i < len2; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr2[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_min(arr, NULL);
    assert(equal_double(unwrap_double(wrapper_double), 1.1));
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    test_t *t = (test_t *)array_min(arr, cmp_by_int);
    assert(t->a == 1);
    t = (test_t *)array_min(arr, cmp_by_str);
    char p[8] = {0};
    int_to_str(1, p, sizeof(p));
    assert(str_equal(t->p, p));
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_max() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = array_len(arr1);
    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_max(arr, NULL);
    assert(unwrap_int(wrapper_int) == 9);
    array_destroy(arr);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = array_len(arr2);
    arr = array_create("double");
    for (int i = 0; i < len2; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr2[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_max(arr, NULL);
    assert(equal_double(unwrap_double(wrapper_double), 9.9));
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    test_t *t = (test_t *)array_max(arr, cmp_by_int);
    assert(t->a == 9);
    t = (test_t *)array_max(arr, cmp_by_str);
    char p[8] = {0};
    int_to_str(9, p, sizeof(p));
    assert(str_equal(t->p, p));
    free(test);
    test = NULL;
    array_destroy(arr);
}

static bool match_by_int(const void *data) {
    test_t *t = (test_t *)data;
    return t->a == 4;
}

void test_array_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = array_len(arr1);

    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = wrap_int(4);
    assert(array_index_of(arr, wrapper_int) == 1);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(10);
    assert(array_index_of(arr, wrapper_int) == -1);
    unwrap_int(wrapper_int);
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = wrap_double(4.0);
    assert(array_index_of(arr, wrapper_double) == 1);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(10.0);
    assert(array_index_of(arr, wrapper_double) == -1);
    unwrap_double(wrapper_double);
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    assert(array_index_of(arr, match_by_int) == 1);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_last_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = array_len(arr1);

    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = wrap_int(4);
    assert(array_last_index_of(arr, wrapper_int) == 5);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(10);
    assert(array_last_index_of(arr, wrapper_int) == -1);
    unwrap_int(wrapper_int);
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = wrap_double(4.0);
    assert(array_last_index_of(arr, wrapper_double) == 5);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(10.0);
    assert(array_last_index_of(arr, wrapper_double) == -1);
    unwrap_double(wrapper_double);
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    assert(array_last_index_of(arr, match_by_int) == 5);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_count() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = array_len(arr1);

    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = wrap_int(4);
    assert(array_count(arr, wrapper_int) == 2);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(10);
    assert(array_count(arr, wrapper_int) == 0);
    unwrap_int(wrapper_int);
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = wrap_double(4.0);
    assert(array_count(arr, wrapper_double) == 2);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(10.0);
    assert(array_count(arr, wrapper_double) == 0);
    unwrap_double(wrapper_double);
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    assert(array_count(arr, match_by_int) == 2);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_reverse() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    array_reverse(arr);
    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == 10 - i - 1);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    array_reverse(arr);
    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)(10 - i - 1)));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 10);
    for (int i = 0; i < 10; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    array_reverse(arr);
    for (int i = 0; i < 10; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == 10 - i - 1);
        char p[8] = {0};
        int_to_str(10 - i - 1, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_swap() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    int i = 0;
    int j = 9;
    while (i < j) {
        array_swap(arr, i, j);
        i++;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == 10 - i - 1);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    i = 0;
    j = 9;
    while (i < j) {
        array_swap(arr, i, j);
        i++;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)(10 - i - 1)));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 10);
    for (int i = 0; i < 10; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    i = 0;
    j = 9;
    while (i < j) {
        array_swap(arr, i, j);
        i++;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == 10 - i - 1);
        char p[8] = {0};
        int_to_str(10 - i - 1, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_sort() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = array_len(arr1);

    int arr2[] = {1, 2, 2, 4, 4, 5, 5};
    int len2 = array_len(arr2);

    array_t *arr = array_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    array_sort(arr, false, NULL);
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == arr2[i]);
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    array_sort(arr, true, NULL);
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(unwrap_int(wrapper) == arr2[len2 - i - 1]);
    }
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    array_sort(arr, false, NULL);
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)arr2[i]));
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    array_sort(arr, true, NULL);
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(equal_double(unwrap_double(wrapper), (double)arr2[len2 - i - 1]));
    }
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * len1);
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    array_sort(arr, false, cmp_by_int);
    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == arr2[i]);
        char p[8] = {0};
        int_to_str(arr2[i], p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }
    array_sort(arr, true, cmp_by_str);
    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->a == arr2[len2 - i - 1]);
        char p[8] = {0};
        int_to_str(arr2[len2 - i - 1], p, sizeof(p));
        assert(str_equal(t->p, p));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_iter() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    assert(array_iter(arr));
    array_destroy(arr);

    arr = array_create("double");
    assert(!array_iter(arr));
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        array_append(arr, &test[i]);
    }
    assert(array_iter(arr));
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_iter_has_next() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }
    array_iter(arr);
    assert(array_iter_has_next(arr));
    array_destroy(arr);

    arr = array_create("double");
    assert(!array_iter(arr));
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }
    iter_t *iter = array_iter(arr);
    assert(iter);
    for (int i = 0; i < 5; i++) {
        if (array_iter_has_next(arr)) {
            iter = array_iter_next(arr);
        }
    }
    assert(!array_iter_has_next(arr));
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        array_append(arr, &test[i]);
    }
    array_iter(arr);
    assert(array_iter_has_next(arr));
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_iter_next() {
    array_t *arr = array_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        array_append(arr, wrapper);
        unwrap_int(wrapper);
    }

    int i = 0;
    iter_t iter = array_iter(arr);
    while (iter) {
        assert(*(int *)iter == i);
        iter = array_iter_next(arr);
        i++;
    }
    assert(i == 5);
    array_destroy(arr);

    arr = array_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        array_append(arr, wrapper);
        unwrap_double(wrapper);
    }

    i = 0;
    iter = array_iter(arr);
    while (iter) {
        assert(equal_double(*(double *)iter, (double)i));
        iter = array_iter_next(arr);
        i++;
    }
    assert(i == 5);
    array_destroy(arr);

    arr = array_create("T");
    test_t *test = (test_t *)cino_alloc(sizeof(test_t) * 5);
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        array_append(arr, &test[i]);
    }

    i = 0;
    iter = array_iter(arr);
    while (iter) {
        test_t *t = (test_t *)iter;
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
        iter = array_iter_next(arr);
        i++;
    }
    assert(i == 5);

    free(test);
    test = NULL;
    array_destroy(arr);
}