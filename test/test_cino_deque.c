#include "test_cino_deque.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

void test_deque_create() {
    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_destroy() {
    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_is_empty() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_size() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_clear() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == len);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_push_front() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_pop_front() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_get_front() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_front(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_push_back() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_pop_back() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_get_back() {
    const int len = 5;

    deque_t *deque = deque_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        deque_push_back(deque, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}