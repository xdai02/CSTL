#include "test_cino_stack.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void test_setter(test_t *test, int index, int value) {
    test[index].i = value;
    char str[8] = {0};
    int_to_str(value, str, sizeof(str));
    str_copy(test[index].str, str);
}

void test_stack_create() {
    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);
}

void test_stack_destroy() {
    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);
}

void test_stack_is_empty() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_size() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_clear() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == len);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_push() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_pop() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_peek() {
    const int len = 5;

    stack_t *stack = stack_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, len - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), len - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        stack_push(stack, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + len - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + len - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == len - i - 1);
        char str[8] = {0};
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == len - i - 1);
        int_to_str(len - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}