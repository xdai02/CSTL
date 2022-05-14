#include "test_cino_array.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void visit_int(void *data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_int->data = %d", wrapper->data);
}

static void visit_double(void *data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_double->data = %f", wrapper->data);
}

static void visit_char(void *data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_char->data = %c", wrapper->data);
}

static void visit_test(void *data) {
    test_t *test = (test_t *)data;
    assert(test);
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
    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);
}

void test_array_destroy() {
    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);
}

void test_array_is_empty() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        array_append(array, &test[i]);
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_size() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        array_append(array, &test[i]);
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_clear() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        array_append(array, &test[i]);
    }
    assert(!array_is_empty(array));
    assert(array_size(array) == len);
    array_clear(array);
    assert(array_is_empty(array));
    assert(array_size(array) == 0);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_foreach() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    array_foreach(array, visit_int, false);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    array_foreach(array, visit_double, true);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    array_foreach(array, visit_char, false);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }
    array_foreach(array, visit_test, false);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_get() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == i);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(wrapper->data == i);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + i);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_set() {
    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < 3; i++) {
        array_append(array, wrap_int(i));
    }
    array_set(array, 0, wrap_int(9));
    array_set(array, 2, wrap_int(7));

    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_get(array, 0);
    assert(wrapper_int->data == 9);
    wrapper_int = (wrapper_int_t *)array_get(array, 1);
    assert(wrapper_int->data == 1);
    wrapper_int = (wrapper_int_t *)array_get(array, 2);
    assert(wrapper_int->data == 7);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < 3; i++) {
        array_append(array, wrap_double(i));
    }
    array_set(array, 0, wrap_double(9.9));
    array_set(array, 2, wrap_double(7.7));

    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_get(array, 0);
    assert(double_equal(wrapper_double->data, 9.9));
    wrapper_double = (wrapper_double_t *)array_get(array, 1);
    assert(double_equal(wrapper_double->data, 1.0));
    wrapper_double = (wrapper_double_t *)array_get(array, 2);
    assert(double_equal(wrapper_double->data, 7.7));
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < 3; i++) {
        array_append(array, wrap_char('A' + i));
    }
    array_set(array, 0, wrap_char('X'));
    array_set(array, 2, wrap_char('Y'));

    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_get(array, 0);
    assert(wrapper_char->data == 'X');
    wrapper_char = (wrapper_char_t *)array_get(array, 1);
    assert(wrapper_char->data == 'B');
    wrapper_char = (wrapper_char_t *)array_get(array, 2);
    assert(wrapper_char->data == 'Y');
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(3, sizeof(test_t));

    for (int i = 0; i < 3; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    test[0].i = 9;
    str_copy(test[0].str, "9");
    array_set(array, 0, &test[0]);
    test[2].i = 7;
    str_copy(test[2].str, "7");
    array_set(array, 2, &test[2]);

    test_t *t = (test_t *)array_get(array, 0);
    assert(t->i == 9);
    assert(str_equal(t->str, "9"));
    t = (test_t *)array_get(array, 1);
    assert(t->i == 1);
    assert(str_equal(t->str, "1"));
    t = (test_t *)array_get(array, 2);
    assert(t->i == 7);
    assert(str_equal(t->str, "7"));

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_append() {
    const int len = 5;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == i);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, i));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + i);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_insert() {
    int arr[] = {2, 0, 4, 3, 1};
    int len = arr_len(arr);

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    array_insert(array, 0, wrap_int(0));
    array_insert(array, 0, wrap_int(2));
    array_insert(array, 2, wrap_int(3));
    array_insert(array, 3, wrap_int(1));
    array_insert(array, 2, wrap_int(4));

    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == arr[i]);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);

    array_insert(array, 0, wrap_double(0));
    array_insert(array, 0, wrap_double(2));
    array_insert(array, 2, wrap_double(3));
    array_insert(array, 3, wrap_double(1));
    array_insert(array, 2, wrap_double(4));

    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, arr[i]));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);

    array_insert(array, 0, wrap_char('A' + 0));
    array_insert(array, 0, wrap_char('A' + 2));
    array_insert(array, 2, wrap_char('A' + 3));
    array_insert(array, 3, wrap_char('A' + 1));
    array_insert(array, 2, wrap_char('A' + 4));

    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + arr[i]);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
    }

    array_insert(array, 0, &test[0]);
    array_insert(array, 0, &test[2]);
    array_insert(array, 2, &test[3]);
    array_insert(array, 3, &test[1]);
    array_insert(array, 2, &test[4]);

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == arr[i]);
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_remove() {
    const int len = 10;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }

    unwrap_int(array_remove(array, 2));
    unwrap_int(array_remove(array, 1));
    unwrap_int(array_remove(array, 0));
    unwrap_int(array_remove(array, 5));
    unwrap_int(array_remove(array, 5));

    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == i + 3);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }

    unwrap_double(array_remove(array, 2));
    unwrap_double(array_remove(array, 1));
    unwrap_double(array_remove(array, 0));
    unwrap_double(array_remove(array, 5));
    unwrap_double(array_remove(array, 5));

    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, i + 3));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }

    unwrap_char(array_remove(array, 2));
    unwrap_char(array_remove(array, 1));
    unwrap_char(array_remove(array, 0));
    unwrap_char(array_remove(array, 5));
    unwrap_char(array_remove(array, 5));

    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + i + 3);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    array_remove(array, 2);
    array_remove(array, 1);
    array_remove(array, 0);
    array_remove(array, 5);
    array_remove(array, 5);

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == i + 3);
        char str[8] = {0};
        int_to_str(i + 3, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_min() {
    int arr[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len = arr_len(arr);
    const int min = 1;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(arr[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_min(array);
    assert(wrapper_int->data == min);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(arr[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_min(array);
    assert(double_equal(wrapper_double->data, min));
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + arr[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_min(array);
    assert(wrapper_char->data == 'A' + min);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_test_by_int, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    test_t *t = (test_t *)array_min(array);
    assert(t->i == min);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_max() {
    int arr[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len = arr_len(arr);
    const int max = 9;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(arr[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)array_max(array);
    assert(wrapper_int->data == max);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(arr[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)array_max(array);
    assert(double_equal(wrapper_double->data, max));
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + arr[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)array_max(array);
    assert(wrapper_char->data == 'A' + max);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_test_by_int, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    test_t *t = (test_t *)array_max(array);
    assert(t->i == max);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_index_of() {
    int arr[] = {5, 4, 2, 2, 5, 4, 1};
    int len = arr_len(arr);

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(arr[i]));
    }
    assert(array_index_of(array, wrap_int(4)) == 1);
    assert(array_index_of(array, wrap_int(10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(arr[i]));
    }
    assert(array_index_of(array, wrap_double(4)) == 1);
    assert(array_index_of(array, wrap_double(10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + arr[i]));
    }
    assert(array_index_of(array, wrap_char('A' + 4)) == 1);
    assert(array_index_of(array, wrap_char('A' + 10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    assert(array_index_of(array, match_test_by_int) == 1);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_last_index_of() {
    int arr[] = {5, 4, 2, 2, 5, 4, 1};
    int len = arr_len(arr);

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(arr[i]));
    }
    assert(array_last_index_of(array, wrap_int(4)) == 5);
    assert(array_last_index_of(array, wrap_int(10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(arr[i]));
    }
    assert(array_last_index_of(array, wrap_double(4)) == 5);
    assert(array_last_index_of(array, wrap_double(10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + arr[i]));
    }
    assert(array_last_index_of(array, wrap_char('A' + 4)) == 5);
    assert(array_last_index_of(array, wrap_char('A' + 10)) == -1);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    assert(array_last_index_of(array, match_test_by_int) == 5);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_count() {
    int arr[] = {5, 4, 2, 2, 5, 4, 1};
    int len = arr_len(arr);

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(arr[i]));
    }
    assert(array_count(array, wrap_int(4)) == 2);
    assert(array_count(array, wrap_int(10)) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(arr[i]));
    }
    assert(array_count(array, wrap_double(4)) == 2);
    assert(array_count(array, wrap_double(10)) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + arr[i]));
    }
    assert(array_count(array, wrap_char('A' + 4)) == 2);
    assert(array_count(array, wrap_char('A' + 10)) == 0);
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    assert(array_count(array, match_test_by_int) == 2);
    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_reverse() {
    const int len = 10;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }

    array_reverse(array);

    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == len - i - 1);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }

    array_reverse(array);

    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, len - i - 1));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }

    array_reverse(array);

    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + len - i - 1);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    array_reverse(array);

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_swap() {
    const int len = 10;

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_int(i));
    }

    int i = 0;
    int j = len - 1;
    while (i < j) {
        array_swap(array, i, j);
        i++;
        j--;
    }

    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == len - i - 1);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_double(i));
    }

    i = 0;
    j = len - 1;
    while (i < j) {
        array_swap(array, i, j);
        i++;
        j--;
    }

    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, len - i - 1));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        array_append(array, wrap_char('A' + i));
    }

    i = 0;
    j = len - 1;
    while (i < j) {
        array_swap(array, i, j);
        i++;
        j--;
    }

    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + len - i - 1);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    i = 0;
    j = len - 1;
    while (i < j) {
        array_swap(array, i, j);
        i++;
        j--;
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}

void test_array_sort() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    int arr2[] = {1, 2, 2, 4, 4, 5, 5};
    int len2 = arr_len(arr2);

    array_t *array = array_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_int(arr1[i]));
    }

    array_sort(array, false);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == arr2[i]);
    }
    array_clear(array);

    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_int(arr1[i]));
    }

    array_sort(array, true);

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)array_get(array, i);
        assert(wrapper->data == arr2[len2 - i - 1]);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_double(arr1[i]));
    }

    array_sort(array, false);

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, arr2[i]));
    }
    array_clear(array);

    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_double(arr1[i]));
    }

    array_sort(array, true);

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)array_get(array, i);
        assert(double_equal(wrapper->data, arr2[len2 - i - 1]));
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_char('A' + arr1[i]));
    }

    array_sort(array, false);

    for (int i = 0; i < len2; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == 'A' + arr2[i]);
    }
    array_clear(array);

    for (int i = 0; i < len1; i++) {
        array_append(array, wrap_int(arr1[i]));
    }

    array_sort(array, true);

    for (int i = 0; i < len2; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)array_get(array, i);
        assert(wrapper->data == arr2[len2 - i - 1]);
    }
    array_destroy(array);

    array = array_create(DATA_TYPE_T, compare_test_by_int, destroy_default);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    array_sort(array, false);

    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == arr2[i]);
        char str[8] = {0};
        int_to_str(arr2[i], str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    array_clear(array);

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        array_append(array, &test[i]);
    }

    array_sort(array, true);

    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)array_get(array, i);
        assert(t->i == arr2[len2 - i - 1]);
        char str[8] = {0};
        int_to_str(arr2[len2 - i - 1], str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    array_destroy(array);
}