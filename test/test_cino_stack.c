#include "test_cino_stack.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

void test_stack_create() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);
}

void test_stack_destroy() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    assert(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);
}

void test_stack_is_empty() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_size() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_clear() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        stack_push(stack, &test[i]);
    }
    assert(!stack_is_empty(stack));
    assert(stack_size(stack) == 5);
    stack_clear(stack);
    assert(stack_is_empty(stack));
    assert(stack_size(stack) == 0);
    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_push() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 5 - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_pop() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 5 - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}

void test_stack_peek() {
    stack_t *stack = stack_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 5 - i - 1);
        wrapper = stack_pop(stack);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        stack_push(stack, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = stack_peek(stack);
        assert(double_equal(wrapper->data, 5 - i - 1));
        wrapper = stack_pop(stack);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        stack_push(stack, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = stack_peek(stack);
        assert(wrapper->data == 'A' + (5 - 1) - (i - 'A'));
        wrapper = stack_pop(stack);
        assert(unwrap_char(wrapper) == 'A' + (5 - 1) - (i - 'A'));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));
    stack_destroy(stack);

    stack = stack_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        stack_push(stack, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)stack_peek(stack);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = stack_pop(stack);
        assert(t->i == 5 - i - 1);
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(stack_size(stack) == 0);
    assert(stack_is_empty(stack));

    free(test);
    test = NULL;
    stack_destroy(stack);
}