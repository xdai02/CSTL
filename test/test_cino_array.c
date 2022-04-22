#include "test_cino_array.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void visit_int(void *data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    assert(wrapper);
    assert(wrapper->data >= 0 && wrapper->data < 5);
}

static void visit_double(void *data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    assert(wrapper);
    assert(wrapper->data >= 0.0 && wrapper->data < 5.0);
}

static void visit_char(void *data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    assert(wrapper);
    assert(wrapper->data >= 'A' && wrapper->data < 'A' + 5);
}

static void visit_test(void *data) {
    test_t *test = (test_t *)data;
    assert(test);
    assert(test->i >= 0 && test->i < 5);
    assert(str_to_int(test->str) >= 0 && str_to_int(test->str) < 5);
}

static int compare_test_by_int(const void *data1, const void *data2) {
    test_t *t1 = (test_t *)data1;
    test_t *t2 = (test_t *)data2;
    return t1->i - t2->i;
}

static bool match_test_by_int(const void *data) {
    test_t *t = (test_t *)data;
    return t->i == 4;
}

void test_array_create() {
    array_t *arr = array_create("int", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_destroy() {
    array_t *arr = array_create("int", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    assert(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);
}

void test_array_is_empty() {
    array_t *arr = array_create("int", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
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

void test_array_size() {
    array_t *arr = array_create("int", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
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

void test_array_clear() {
    array_t *arr = array_create("int", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    assert(!array_is_empty(arr));
    assert(array_size(arr) == 5);
    array_clear(arr);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    assert(array_is_empty(arr));
    assert(array_size(arr) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
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

void test_array_foreach() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    array_foreach(arr, visit_int, false);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    array_foreach(arr, visit_double, true);
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    array_foreach(arr, visit_char, false);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }
    array_foreach(arr, visit_test, false);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_get() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == i);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(wrapper->data == i);
    }
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i - 'A');
        assert(wrapper->data == i);
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_set() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 3; i++) {
        array_append(arr, wrap_int(i));
    }
    array_set(arr, 0, wrap_int(9));
    array_set(arr, 2, wrap_int(7));

    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_get(arr, 0);
    assert(wrapper_int->data == 9);
    wrapper_int = (wrapper_int_t *)array_get(arr, 1);
    assert(wrapper_int->data == 1);
    wrapper_int = (wrapper_int_t *)array_get(arr, 2);
    assert(wrapper_int->data == 7);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 3; i++) {
        array_append(arr, wrap_double(i));
    }
    array_set(arr, 0, wrap_double(9.9));
    array_set(arr, 2, wrap_double(7.7));

    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_get(arr, 0);
    assert(double_equal(wrapper_double->data, 9.9));
    wrapper_double = (wrapper_double_t *)array_get(arr, 1);
    assert(double_equal(wrapper_double->data, 1.0));
    wrapper_double = (wrapper_double_t *)array_get(arr, 2);
    assert(double_equal(wrapper_double->data, 7.7));
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i <= 'C'; i++) {
        array_append(arr, wrap_char(i));
    }
    array_set(arr, 0, wrap_char('X'));
    array_set(arr, 2, wrap_char('Y'));

    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_get(arr, 0);
    assert(wrapper_char->data == 'X');
    wrapper_char = (wrapper_char_t *)array_get(arr, 1);
    assert(wrapper_char->data == 'B');
    wrapper_char = (wrapper_char_t *)array_get(arr, 2);
    assert(wrapper_char->data == 'Y');
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(3, sizeof(test_t));

    for (int i = 0; i < 3; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    test[0].i = 9;
    str_copy(test[0].str, "9");
    array_set(arr, 0, &test[0]);
    test[2].i = 7;
    str_copy(test[2].str, "7");
    array_set(arr, 2, &test[2]);

    test_t *t = (test_t *)array_get(arr, 0);
    assert(t->i == 9);
    assert(str_equal(t->str, "9"));
    t = (test_t *)array_get(arr, 1);
    assert(t->i == 1);
    assert(str_equal(t->str, "1"));
    t = (test_t *)array_get(arr, 2);
    assert(t->i == 7);
    assert(str_equal(t->str, "7"));

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_append() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == i);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        array_append(arr, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, i));
    }
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        array_append(arr, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i - 'A');
        assert(wrapper->data == i);
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_insert() {
    int arr1[] = {5, 1, 9, 7, 4};
    int len1 = arr_len(arr1);
    array_t *arr = array_create("int", NULL, NULL);

    array_insert(arr, 0, wrap_int(1));
    array_insert(arr, 0, wrap_int(5));
    array_insert(arr, 2, wrap_int(7));
    array_insert(arr, 3, wrap_int(4));
    array_insert(arr, 2, wrap_int(9));

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == arr1[i]);
    }
    array_destroy(arr);

    double arr2[] = {5.5, 1.1, 9.9, 7.7, 4.4};
    int len2 = arr_len(arr2);
    arr = array_create("double", NULL, NULL);

    array_insert(arr, 0, wrap_double(1.1));
    array_insert(arr, 0, wrap_double(5.5));
    array_insert(arr, 2, wrap_double(7.7));
    array_insert(arr, 3, wrap_double(4.4));
    array_insert(arr, 2, wrap_double(9.9));

    for (int i = 0; i < len2; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, arr2[i]));
    }
    array_destroy(arr);

    char arr3[] = {'C', 'A', 'A' + 5, 'D', 'B', '\0'};
    int len3 = str_length(arr3);
    arr = array_create("char", NULL, NULL);

    array_insert(arr, 0, wrap_char('A'));
    array_insert(arr, 0, wrap_char('C'));
    array_insert(arr, 2, wrap_char('D'));
    array_insert(arr, 3, wrap_char('B'));
    array_insert(arr, 2, wrap_char('A' + 5));

    for (int i = 0; i < len3; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i);
        assert(wrapper->data == arr3[i]);
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    int arr4[] = {1, 4, 3, 2, 0};
    int len4 = arr_len(arr4);

    for (int i = 0; i < len4; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
    }

    array_insert(arr, 0, &test[3]);
    array_insert(arr, 0, &test[1]);
    array_insert(arr, 2, &test[0]);
    array_insert(arr, 1, &test[4]);
    array_insert(arr, 3, &test[2]);

    for (int i = 0; i < len4; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == arr4[i]);
        char str[8] = {0};
        int_to_str(arr4[i], str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_remove() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_int(i));
    }

    unwrap_int(array_remove(arr, 2));
    unwrap_int(array_remove(arr, 1));
    unwrap_int(array_remove(arr, 0));
    unwrap_int(array_remove(arr, 5));
    unwrap_int(array_remove(arr, 5));

    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == i + 3);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_double(i));
    }

    unwrap_double(array_remove(arr, 2));
    unwrap_double(array_remove(arr, 1));
    unwrap_double(array_remove(arr, 0));
    unwrap_double(array_remove(arr, 5));
    unwrap_double(array_remove(arr, 5));

    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, i + 3));
    }
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 10; i++) {
        array_append(arr, wrap_char(i));
    }

    unwrap_char(array_remove(arr, 2));
    unwrap_char(array_remove(arr, 1));
    unwrap_char(array_remove(arr, 0));
    unwrap_char(array_remove(arr, 5));
    unwrap_char(array_remove(arr, 5));

    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i - 'A');
        assert(wrapper->data == i + 3);
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 10; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    array_remove(arr, 2);
    array_remove(arr, 1);
    array_remove(arr, 0);
    array_remove(arr, 5);
    array_remove(arr, 5);

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == i + 3);
        char str[8] = {0};
        int_to_str(i + 3, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_min() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = arr_len(arr1);
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_min(arr);
    assert(wrapper_int->data == 1);
    array_destroy(arr);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = arr_len(arr2);
    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len2; i++) {
        array_append(arr, wrap_double(arr2[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_min(arr);
    assert(double_equal(wrapper_double->data, 1.1));
    array_destroy(arr);

    char arr3[] = {'D', 'F', 'A', 'G', 'C', 'B', 'D', 'E', '\0'};
    int len3 = str_length(arr3);
    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len3; i++) {
        array_append(arr, wrap_char(arr3[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_min(arr);
    assert(wrapper_char->data == 'A');
    array_destroy(arr);

    arr = array_create("T", compare_test_by_int, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    test_t *t = (test_t *)array_min(arr);
    assert(t->i == 1);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_max() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = arr_len(arr1);
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_max(arr);
    assert(wrapper_int->data == 9);
    array_destroy(arr);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = arr_len(arr2);
    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len2; i++) {
        array_append(arr, wrap_double(arr2[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_max(arr);
    assert(double_equal(wrapper_double->data, 9.9));
    array_destroy(arr);

    char arr3[] = {'D', 'F', 'A', 'G', 'C', 'B', 'D', 'E', '\0'};
    int len3 = str_length(arr3);
    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len3; i++) {
        array_append(arr, wrap_char(arr3[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_max(arr);
    assert(wrapper_char->data == 'G');
    array_destroy(arr);

    arr = array_create("T", compare_test_by_int, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    test_t *t = (test_t *)array_max(arr);
    assert(t->i == 9);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }
    assert(array_index_of(arr, wrap_int(4)) == 1);
    assert(array_index_of(arr, wrap_int(10)) == -1);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_double(arr1[i]));
    }
    assert(array_index_of(arr, wrap_double(4.0)) == 1);
    assert(array_index_of(arr, wrap_double(10.0)) == -1);
    array_destroy(arr);

    char arr2[] = {'D', 'A', 'A' + 5, 'D', 'B', '\0'};
    int len2 = str_length(arr2);

    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len2; i++) {
        array_append(arr, wrap_char(arr2[i]));
    }
    assert(array_index_of(arr, wrap_char('D')) == 0);
    assert(array_index_of(arr, wrap_char('X')) == -1);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    assert(array_index_of(arr, match_test_by_int) == 1);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_last_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }
    assert(array_last_index_of(arr, wrap_int(4)) == 5);
    assert(array_last_index_of(arr, wrap_int(10)) == -1);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_double(arr1[i]));
    }
    assert(array_last_index_of(arr, wrap_double(4.0)) == 5);
    assert(array_last_index_of(arr, wrap_double(10.0)) == -1);
    array_destroy(arr);

    char arr2[] = {'D', 'A', 'A' + 5, 'D', 'B', '\0'};
    int len2 = str_length(arr2);

    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len2; i++) {
        array_append(arr, wrap_char(arr2[i]));
    }
    assert(array_last_index_of(arr, wrap_char('D')) == 3);
    assert(array_last_index_of(arr, wrap_char('X')) == -1);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    assert(array_last_index_of(arr, match_test_by_int) == 5);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_count() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }
    assert(array_count(arr, wrap_int(4)) == 2);
    assert(array_count(arr, wrap_int(10)) == 0);
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_double(arr1[i]));
    }
    assert(array_count(arr, wrap_double(4.0)) == 2);
    assert(array_count(arr, wrap_double(10.0)) == 0);
    array_destroy(arr);

    char arr2[] = {'D', 'A', 'A' + 5, 'D', 'B', '\0'};
    int len2 = str_length(arr2);

    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len2; i++) {
        array_append(arr, wrap_char(arr2[i]));
    }
    assert(array_count(arr, wrap_char('D')) == 2);
    assert(array_count(arr, wrap_char('X')) == 0);
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    assert(array_count(arr, match_test_by_int) == 2);
    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_reverse() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_int(i));
    }

    array_reverse(arr);

    for (int i = 0; i < 10; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == 10 - i - 1);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_double(i));
    }

    array_reverse(arr);

    for (int i = 0; i < 10; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, 10 - i - 1));
    }
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 10; i++) {
        array_append(arr, wrap_char(i));
    }

    array_reverse(arr);

    for (int i = 'A'; i < 'A' + 10; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i - 'A');
        assert(wrapper->data == 'A' + (10 - 1) - (i - 'A'));
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 10; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    array_reverse(arr);

    for (int i = 0; i < 10; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == 10 - i - 1);
        char str[8] = {0};
        int_to_str(10 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_swap() {
    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_int(i));
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
        assert(wrapper->data == 10 - i - 1);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < 10; i++) {
        array_append(arr, wrap_double(i));
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
        assert(double_equal(wrapper->data, 10 - i - 1));
    }
    array_destroy(arr);

    arr = array_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 10; i++) {
        array_append(arr, wrap_char(i));
    }

    i = 0;
    j = 9;
    while (i < j) {
        array_swap(arr, i, j);
        i++;
        j--;
    }

    for (int i = 'A'; i < 'A' + 10; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i - 'A');
        assert(wrapper->data == 'A' + (10 - 1) - (i - 'A'));
    }
    array_destroy(arr);

    arr = array_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 10; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
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
        assert(t->i == 10 - i - 1);
        char str[8] = {0};
        int_to_str(10 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}

void test_array_sort() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    int arr2[] = {1, 2, 2, 4, 4, 5, 5};
    int len2 = arr_len(arr2);

    array_t *arr = array_create("int", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }

    array_sort(arr, false);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == arr2[i]);
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_int(arr1[i]));
    }

    array_sort(arr, true);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(arr, i);
        assert(wrapper->data == arr2[len2 - i - 1]);
    }
    array_destroy(arr);

    arr = array_create("double", NULL, NULL);
    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_double(arr1[i]));
    }

    array_sort(arr, false);

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, arr2[i]));
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        array_append(arr, wrap_double(arr1[i]));
    }

    array_sort(arr, true);

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(arr, i);
        assert(double_equal(wrapper->data, arr2[len2 - i - 1]));
    }
    array_destroy(arr);

    char arr3[] = {'E', 'D', 'B', 'B', 'E', 'D', 'A', '\0'};
    int len3 = str_length(arr3);

    char arr4[] = {'A', 'B', 'B', 'D', 'D', 'E', 'E', '\0'};
    int len4 = str_length(arr4);

    arr = array_create("char", NULL, NULL);
    for (int i = 0; i < len3; i++) {
        array_append(arr, wrap_char(arr3[i]));
    }

    array_sort(arr, false);

    for (int i = 0; i < len4; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i);
        assert(wrapper->data == arr4[i]);
    }
    array_clear(arr);

    for (int i = 0; i < len3; i++) {
        array_append(arr, wrap_int(arr3[i]));
    }

    array_sort(arr, true);

    for (int i = 0; i < len4; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(arr, i);
        assert(wrapper->data == arr4[len4 - i - 1]);
    }
    array_destroy(arr);

    arr = array_create("T", compare_test_by_int, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    array_sort(arr, false);

    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == arr2[i]);
        char str[8] = {0};
        int_to_str(arr2[i], str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    array_clear(arr);

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(arr, &test[i]);
    }

    array_sort(arr, true);

    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(arr, i);
        assert(t->i == arr2[len2 - i - 1]);
        char str[8] = {0};
        int_to_str(arr2[len2 - i - 1], str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(arr);
}