#include "test_cino_list.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void visit_int(void *data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_int->data = %d", wrapper->data);
    assert(wrapper->data >= 0 && wrapper->data < 5);
}

static void visit_double(void *data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_double->data = %f", wrapper->data);
    assert(wrapper->data >= 0.0 && wrapper->data < 5.0);
}

static void visit_char(void *data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    assert(wrapper);
    LOGGER(NONE, "wrapper_char->data = %c", wrapper->data);
    assert(wrapper->data >= 'A' && wrapper->data < 'A' + 5);
}

static void visit_test(void *data) {
    test_t *test = (test_t *)data;
    assert(test);
    assert(test->i >= 0 && test->i < 5);
    assert(str_to_int(test->str) >= 0 && str_to_int(test->str) < 5);
}

static bool match_test_int(const void *data) {
    test_t *t = (test_t *)data;
    return t->i == 4;
}

void test_list_create() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_destroy() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_is_empty() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_size() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_clear() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_foreach() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    list_foreach(list, visit_int, false);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    list_foreach(list, visit_double, true);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    list_foreach(list, visit_char, true);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }
    list_foreach(list, visit_test, false);
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_get_front() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(!list_get_front(list));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get_front(list);
    assert(wrapper_int->data == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(!list_get_front(list));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get_front(list);
    assert(double_equal(wrapper_double->data, 0.0));
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(!list_get_front(list));
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)list_get_front(list);
    assert(wrapper_char->data == 'A');
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(!list_get_front(list));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    test_t *t = (test_t *)list_get_front(list);
    assert(t->i == 0);
    assert(str_equal(t->str, "0"));

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_get_back() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(!list_get_back(list));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get_back(list);
    assert(wrapper_int->data == 4);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(!list_get_back(list));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get_back(list);
    assert(double_equal(wrapper_double->data, 4.0));
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(!list_get_back(list));
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)list_get_back(list);
    assert(wrapper_char->data == 'E');
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(!list_get_back(list));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    test_t *t = (test_t *)list_get_back(list);
    assert(t->i == 4);
    assert(str_equal(t->str, "4"));

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_get() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    assert(!list_get(list, 0));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get(list, i);
        assert(wrapper_int->data == i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    assert(!list_get(list, 1));
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get(list, i);
        assert(double_equal(wrapper_double->data, i));
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    assert(!list_get(list, 1));
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper_char = (wrapper_char_t *)list_get(list, i);
        assert(wrapper_char->data == 'A' + i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    assert(!list_get(list, 0));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_set() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 3; i++) {
        list_push_back(list, wrap_int(i));
    }

    list_set(list, 0, wrap_int(9));
    list_set(list, 2, wrap_int(7));

    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get(list, 0);
    assert(wrapper_int->data == 9);
    wrapper_int = (wrapper_int_t *)list_get(list, 1);
    assert(wrapper_int->data == 1);
    wrapper_int = (wrapper_int_t *)list_get(list, 2);
    assert(wrapper_int->data == 7);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 3; i++) {
        list_push_back(list, wrap_double(i));
    }

    list_set(list, 0, wrap_double(9.0));
    list_set(list, 2, wrap_double(7.0));

    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get(list, 0);
    assert(double_equal(wrapper_double->data, 9.0));
    wrapper_double = (wrapper_double_t *)list_get(list, 1);
    assert(double_equal(wrapper_double->data, 1.0));
    wrapper_double = (wrapper_double_t *)list_get(list, 2);
    assert(double_equal(wrapper_double->data, 7.0));
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 3; i++) {
        list_push_back(list, wrap_char(i));
    }

    list_set(list, 0, wrap_char('X'));
    list_set(list, 2, wrap_char('Y'));

    wrapper_char_t *wrapper_char = (wrapper_char_t *)list_get(list, 0);
    assert(wrapper_char->data == 'X');
    wrapper_char = (wrapper_char_t *)list_get(list, 1);
    assert(wrapper_char->data == 'B');
    wrapper_char = (wrapper_char_t *)list_get(list, 2);
    assert(wrapper_char->data == 'Y');
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(3, sizeof(test_t));

    for (int i = 0; i < 3; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    test[0].i = 9;
    str_copy(test[0].str, "9");
    list_set(list, 0, &test[0]);
    test[2].i = 7;
    str_copy(test[2].str, "7");
    list_set(list, 2, &test[2]);

    test_t *t = (test_t *)list_get(list, 0);
    assert(t->i == 9);
    assert(str_equal(t->str, "9"));
    t = (test_t *)list_get(list, 1);
    assert(t->i == 1);
    assert(str_equal(t->str, "1"));
    t = (test_t *)list_get(list, 2);
    assert(t->i == 7);
    assert(str_equal(t->str, "7"));

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = arr_len(arr1);

    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < len1; i++) {
        list_push_back(list, wrap_int(arr1[i]));
    }
    assert(list_index_of(list, wrap_int(4)) == 1);
    assert(list_index_of(list, wrap_int(10)) == -1);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < len1; i++) {
        list_push_back(list, wrap_double(arr1[i]));
    }
    assert(list_index_of(list, wrap_double(4.0)) == 1);
    assert(list_index_of(list, wrap_double(10.0)) == -1);
    list_destroy(list);

    char arr2[] = {'D', 'C', 'B', 'B', 'D', 'C', 'A', '\0'};
    int len2 = str_length(arr2);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 0; i < len2; i++) {
        list_push_back(list, wrap_char(arr2[i]));
    }
    assert(list_index_of(list, wrap_char('C')) == 1);
    assert(list_index_of(list, wrap_char('X')) == -1);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    assert(list_index_of(list, match_test_int) == 1);

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_push_front() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_front(list, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_get(list, i);
        assert(wrapper->data == 5 - i - 1);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_front(list, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_get(list, i);
        assert(double_equal(wrapper->data, 5 - i - 1));
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_front(list, wrap_char(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_get(list, i);
        assert(wrapper->data == 'A' + 5 - i - 1);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_front(list, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_push_back() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_get(list, i);
        assert(wrapper->data == i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_get(list, i);
        assert(double_equal(wrapper->data, i));
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_get(list, i);
        assert(wrapper->data == 'A' + i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_pop_front() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_pop_front(list);
        assert(unwrap_int(wrapper) == i);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_pop_front(list);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_pop_front(list);
        assert(unwrap_char(wrapper) == 'A' + i);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_pop_front(list);
        assert(t->i == i);
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_pop_back() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_pop_back(list);
        assert(unwrap_int(wrapper) == 5 - i - 1);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_pop_back(list);
        assert(double_equal(unwrap_double(wrapper), 5 - i - 1));
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }
    for (int i = 0; i < 5; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_pop_back(list);
        assert(unwrap_char(wrapper) == 'A' + 5 - i - 1);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_pop_back(list);
        assert(t->i == 5 - i - 1);
        char str[8] = {0};
        int_to_str(5 - i - 1, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_insert() {
    int arr1[] = {5, 6, 3, 2};
    int len1 = arr_len(arr1);

    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    list_insert(list, 0, wrap_int(3));
    list_insert(list, 0, wrap_int(5));
    list_insert(list, 1, wrap_int(6));
    list_insert(list, 3, wrap_int(2));

    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_get(list, i);
        assert(wrapper->data == arr1[i]);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    list_insert(list, 0, wrap_double(3));
    list_insert(list, 0, wrap_double(5));
    list_insert(list, 1, wrap_double(6));
    list_insert(list, 3, wrap_double(2));

    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_get(list, i);
        assert(double_equal(wrapper->data, arr1[i]));
    }
    list_destroy(list);

    char arr2[] = {'C', 'D', 'B', 'A', '\0'};
    int len2 = str_length(arr2);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    list_insert(list, 0, wrap_char('B'));
    list_insert(list, 0, wrap_char('C'));
    list_insert(list, 1, wrap_char('D'));
    list_insert(list, 3, wrap_char('A'));

    for (int i = 0; i < len2; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_get(list, i);
        assert(wrapper->data == arr2[i]);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    test[0].i = 3;
    str_copy(test[0].str, "3");
    list_insert(list, 0, &test[0]);
    test[1].i = 5;
    str_copy(test[1].str, "5");
    list_insert(list, 0, &test[1]);
    test[2].i = 6;
    str_copy(test[2].str, "6");
    list_insert(list, 1, &test[2]);
    test[3].i = 2;
    str_copy(test[3].str, "2");
    list_insert(list, 3, &test[3]);

    for (int i = 0; i < len1; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->i == arr1[i]);
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_remove() {
    list_t *list = list_create(DATA_TYPE_INT, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_int(i));
    }

    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_remove(list, 1);
    assert(unwrap_int(wrapper_int) == 1);
    wrapper_int = (wrapper_int_t *)list_remove(list, 3);
    assert(unwrap_int(wrapper_int) == 4);
    wrapper_int = (wrapper_int_t *)list_remove(list, 0);
    assert(unwrap_int(wrapper_int) == 0);

    assert(list_size(list) == 2);
    for (int i = 2; i <= 3; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_pop_front(list);
        assert(unwrap_int(wrapper) == i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_DOUBLE, NULL, NULL);
    for (int i = 0; i < 5; i++) {
        list_push_back(list, wrap_double(i));
    }

    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_remove(list, 1);
    assert(double_equal(unwrap_double(wrapper_double), 1.0));
    wrapper_double = (wrapper_double_t *)list_remove(list, 3);
    assert(double_equal(unwrap_double(wrapper_double), 4.0));
    wrapper_double = (wrapper_double_t *)list_remove(list, 0);
    assert(double_equal(unwrap_double(wrapper_double), 0.0));

    assert(list_size(list) == 2);
    for (int i = 2; i <= 3; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_pop_front(list);
        assert(double_equal(unwrap_double(wrapper), i));
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_CHAR, NULL, NULL);
    for (int i = 'A'; i < 'A' + 5; i++) {
        list_push_back(list, wrap_char(i));
    }

    wrapper_char_t *wrapper_char = (wrapper_char_t *)list_remove(list, 1);
    assert(unwrap_char(wrapper_char) == 'B');
    wrapper_char = (wrapper_char_t *)list_remove(list, 3);
    assert(unwrap_char(wrapper_char) == 'E');
    wrapper_char = (wrapper_char_t *)list_remove(list, 0);
    assert(unwrap_char(wrapper_char) == 'A');

    assert(list_size(list) == 2);
    for (int i = 'C'; i <= 'D'; i++) {
        wrapper_char_t *wrapper = (wrapper_char_t *)list_pop_front(list);
        assert(unwrap_char(wrapper) == i);
    }
    list_destroy(list);

    list = list_create(DATA_TYPE_T, NULL, NULL);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));

    for (int i = 0; i < 5; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        list_push_back(list, &test[i]);
    }

    test_t *t = (test_t *)list_remove(list, 1);
    assert(t->i == 1);
    assert(str_equal(t->str, "1"));
    t = (test_t *)list_remove(list, 3);
    assert(t->i == 4);
    assert(str_equal(t->str, "4"));
    t = (test_t *)list_remove(list, 0);
    assert(t->i == 0);
    assert(str_equal(t->str, "0"));

    for (int i = 2; i <= 3; i++) {
        t = (test_t *)list_pop_front(list);
        assert(t->i == i);
        char str[16] = {0};
        int_to_str(i, str, sizeof(str));
        assert(str_equal(t->str, str));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}