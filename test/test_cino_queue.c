#include "test_cino_queue.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

void test_queue_create() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_destroy() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    assert(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);
}

void test_queue_is_empty() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_size() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_clear() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, &test[i]);
    }
    assert(!queue_is_empty(queue));
    assert(queue_size(queue) == 5);
    queue_clear(queue);
    assert(queue_is_empty(queue));
    assert(queue_size(queue) == 0);
    free(test);
    test = NULL;
    queue_destroy(queue);
}

void test_queue_enqueue() {
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
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
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
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
    queue_t *queue = queue_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_int(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        queue_enqueue(queue, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = queue_get_front(queue);
        assert(double_equal(wrapper->data, i));
        wrapper = queue_dequeue(queue);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        queue_enqueue(queue, wrap_char(i));
    }
    for (int i = 'A'; i < 'A' + 5; i++) {
        wrapper_char_t *wrapper = queue_get_front(queue);
        assert(wrapper->data == i);
        wrapper = queue_dequeue(queue);
        assert(unwrap_char(wrapper) == i);
    }
    assert(queue_size(queue) == 0);
    assert(queue_is_empty(queue));
    queue_destroy(queue);

    queue = queue_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(10, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        queue_enqueue(queue, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
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