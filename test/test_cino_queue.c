#include "test_cino_queue.h"

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

void test_queue_create() {
    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_destroy() {
    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_is_empty() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_size() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_clear() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == len);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_enqueue() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == 'A' + i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == 'A' + i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)queue_get_front(queue);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = queue_dequeue(queue);
        assert(t->i == i);
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));

    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_dequeue() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == 'A' + i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == 'A' + i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)queue_get_front(queue);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = queue_dequeue(queue);
        assert(t->i == i);
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));

    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_get_front() {
    const int len = 5;

    queue_t *queue = queue_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        queue_enqueue(queue, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == 'A' + i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == 'A' + i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test_setter(test, i, i);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)queue_get_front(queue);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));

        t = queue_dequeue(queue);
        assert(t->i == i);
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));

    free(test);
    test = NULL;
    queue_destroy(queue);
}