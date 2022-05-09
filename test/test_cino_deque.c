#include "test_cino_deque.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

void test_deque_create() {
    deque_t *deque = deque_create("int", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_destroy() {
    deque_t *deque = deque_create("int", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    assert(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);
}

void test_deque_is_empty() {
    deque_t *deque = deque_create("int", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_size() {
    deque_t *deque = deque_create("int", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_clear() {
    deque_t *deque = deque_create("int", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, &test[i]);
    }
    assert(!deque_is_empty(deque));
    assert(deque_size(deque) == 5);
    deque_clear(deque);
    assert(deque_is_empty(deque));
    assert(deque_size(deque) == 0);
    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_push_front() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_front(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_pop_front() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_front(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_get_front() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_front(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_front(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_front(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_front(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_front(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_front(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_front(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_front(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_front(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_front(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_push_back() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_pop_back() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}

void test_deque_get_back() {
    deque_t *deque = deque_create("int", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 5 - i - 1);
        wrapper = deque_pop_back(deque);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("double", NULL, NULL);
    for (int i = 0; i < 5; i++) {
        deque_push_back(deque, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = deque_get_back(deque);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = deque_pop_back(deque);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("char", NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        deque_push_back(deque, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = deque_get_back(deque);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = deque_pop_back(deque);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));
    deque_destroy(deque);

    deque = deque_create("T", NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        deque_push_back(deque, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)deque_get_back(deque);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = deque_pop_back(deque);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(deque_size(deque) == 0);
    assert(deque_is_empty(deque));

    free(test);
    test = NULL;
    deque_destroy(deque);
}