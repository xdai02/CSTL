#include "test_cino_list.h"

typedef struct test_t {
    int a;
    char p[16];
} test_t;

void test_list_create() {
    list_t *list = list_create("int");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_destroy() {
    list_t *list = list_create("int");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_is_empty() {
    list_t *list = list_create("int");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_size() {
    list_t *list = list_create("int");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    assert(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);
}

void test_list_clear() {
    list_t *list = list_create("int");
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double(i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    assert(!list_is_empty(list));
    assert(list_size(list) == 5);
    list_clear(list);
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
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

void test_list_get_front() {
    list_t *list = list_create("int");
    assert(!list_get_front(list));
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get_front(list);
    assert(unwrap_int(wrapper_int) == 0);
    list_destroy(list);

    list = list_create("double");
    assert(!list_get_front(list));
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get_front(list);
    assert(equal_double(unwrap_double(wrapper_double), 0.0));
    list_destroy(list);

    list = list_create("T");
    assert(!list_get_front(list));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    test_t *t = (test_t *)list_get_front(list);
    assert(t->a == 0);
    assert(str_equal(t->p, "0"));
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_get_back() {
    list_t *list = list_create("int");
    assert(!list_get_back(list));
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get_back(list);
    assert(unwrap_int(wrapper_int) == 4);
    list_destroy(list);

    list = list_create("double");
    assert(!list_get_back(list));
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get_back(list);
    assert(equal_double(unwrap_double(wrapper_double), 4.0));
    list_destroy(list);

    list = list_create("T");
    assert(!list_get_back(list));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    test_t *t = (test_t *)list_get_back(list);
    assert(t->a == 4);
    assert(str_equal(t->p, "4"));
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_get() {
    list_t *list = list_create("int");
    assert(!list_get(list, 0));
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get(list, i);
        assert(unwrap_int(wrapper_int) == i);
    }
    list_destroy(list);

    list = list_create("double");
    assert(!list_get(list, 1));
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get(list, i);
        assert(equal_double(unwrap_double(wrapper_double), (double)i));
    }
    list_destroy(list);

    list = list_create("T");
    assert(!list_get(list, 0));
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_set() {
    list_t *list = list_create("int");
    for (int i = 0; i < 3; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }

    wrapper_int_t *wrapper_int = wrap_int(9);
    list_set(list, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(7);
    list_set(list, 2, wrapper_int);
    unwrap_int(wrapper_int);

    wrapper_int = (wrapper_int_t *)list_get(list, 0);
    assert(unwrap_int(wrapper_int) == 9);
    wrapper_int = (wrapper_int_t *)list_get(list, 1);
    assert(unwrap_int(wrapper_int) == 1);
    wrapper_int = (wrapper_int_t *)list_get(list, 2);
    assert(unwrap_int(wrapper_int) == 7);
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < 3; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }

    wrapper_double_t *wrapper_double = wrap_double(9.0);
    list_set(list, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(7.0);
    list_set(list, 2, wrapper_double);
    unwrap_double(wrapper_double);

    wrapper_double = (wrapper_double_t *)list_get(list, 0);
    assert(equal_double(unwrap_double(wrapper_double), 9.0));
    wrapper_double = (wrapper_double_t *)list_get(list, 1);
    assert(equal_double(unwrap_double(wrapper_double), 1.0));
    wrapper_double = (wrapper_double_t *)list_get(list, 2);
    assert(equal_double(unwrap_double(wrapper_double), 7.0));
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(3, sizeof(test_t));
    for (int i = 0; i < 3; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }

    test[0].a = 9;
    str_copy(test[0].p, "9");
    list_set(list, 0, &test[0]);
    test[2].a = 7;
    str_copy(test[2].p, "7");
    list_set(list, 2, &test[2]);

    test_t *t = (test_t *)list_get(list, 0);
    assert(t->a == 9);
    assert(str_equal(t->p, "9"));
    t = (test_t *)list_get(list, 1);
    assert(t->a == 1);
    assert(str_equal(t->p, "1"));
    t = (test_t *)list_get(list, 2);
    assert(t->a == 7);
    assert(str_equal(t->p, "7"));

    free(test);
    test = NULL;
    list_destroy(list);
}

static bool match_by_int(const void *data) {
    test_t *t = (test_t *)data;
    return t->a == 4;
}

void test_list_index_of() {
    int arr1[] = {5, 4, 2, 2, 5, 4, 1};
    int len1 = array_len(arr1);

    list_t *list = list_create("int");
    for (int i = 0; i < len1; i++) {
        wrapper_int_t *wrapper = wrap_int(arr1[i]);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    wrapper_int_t *wrapper_int = wrap_int(4);
    assert(list_index_of(list, wrapper_int) == 1);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(10);
    assert(list_index_of(list, wrapper_int) == -1);
    unwrap_int(wrapper_int);
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < len1; i++) {
        wrapper_double_t *wrapper = wrap_double((double)arr1[i]);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    wrapper_double_t *wrapper_double = wrap_double(4.0);
    assert(list_index_of(list, wrapper_double) == 1);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double(10.0);
    assert(list_index_of(list, wrapper_double) == -1);
    unwrap_double(wrapper_double);
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));
    for (int i = 0; i < len1; i++) {
        test[i].a = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    assert(list_index_of(list, match_by_int) == 1);
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_push_front() {
    list_t *list = list_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_front(list, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get(list, i);
        assert(unwrap_int(wrapper_int) == 5 - i - 1);
    }
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_front(list, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get(list, i);
        assert(equal_double(unwrap_double(wrapper_double), (double)(5 - i - 1)));
    }
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_front(list, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->a == 5 - i - 1);
        char p[8] = {0};
        int_to_str(5 - i - 1, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_push_back() {
    list_t *list = list_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_get(list, i);
        assert(unwrap_int(wrapper_int) == i);
    }
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_get(list, i);
        assert(equal_double(unwrap_double(wrapper_double), (double)i));
    }
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_pop_front() {
    list_t *list = list_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_pop_front(list);
        assert(unwrap_int(wrapper_int) == i);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_pop_front(list);
        assert(equal_double(unwrap_double(wrapper_double), (double)i));
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_pop_front(list);
        assert(t->a == i);
        char p[8] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_pop_back() {
    list_t *list = list_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper_int = (wrapper_int_t *)list_pop_back(list);
        assert(unwrap_int(wrapper_int) == 5 - i - 1);
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper_double = (wrapper_double_t *)list_pop_back(list);
        assert(equal_double(unwrap_double(wrapper_double), (double)(5 - i - 1)));
    }
    assert(list_is_empty(list));
    assert(list_size(list) == 0);
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }
    for (int i = 0; i < 5; i++) {
        test_t *t = (test_t *)list_pop_back(list);
        assert(t->a == 5 - i - 1);
        char p[8] = {0};
        int_to_str(5 - i - 1, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_insert() {
    int arr[] = {5, 6, 3, 2};
    int len = array_len(arr);

    list_t *list = list_create("int");
    wrapper_int_t *wrapper_int = wrap_int(3);
    list_insert(list, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(5);
    list_insert(list, 0, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(6);
    list_insert(list, 1, wrapper_int);
    unwrap_int(wrapper_int);
    wrapper_int = wrap_int(2);
    list_insert(list, 3, wrapper_int);
    unwrap_int(wrapper_int);

    for (int i = 0; i < len; i++) {
        wrapper_int_t *wrapper = (wrapper_int_t *)list_get(list, i);
        assert(unwrap_int(wrapper) == arr[i]);
    }
    list_destroy(list);

    list = list_create("double");
    wrapper_double_t *wrapper_double = wrap_double((double)3);
    list_insert(list, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double((double)5);
    list_insert(list, 0, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double((double)6);
    list_insert(list, 1, wrapper_double);
    unwrap_double(wrapper_double);
    wrapper_double = wrap_double((double)2);
    list_insert(list, 3, wrapper_double);
    unwrap_double(wrapper_double);

    for (int i = 0; i < len; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_get(list, i);
        assert(equal_double(unwrap_double(wrapper), (double)arr[i]));
    }
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    test[0].a = 3;
    str_copy(test[0].p, "3");
    list_insert(list, 0, &test[0]);
    test[1].a = 5;
    str_copy(test[1].p, "5");
    list_insert(list, 0, &test[1]);
    test[2].a = 6;
    str_copy(test[2].p, "6");
    list_insert(list, 1, &test[2]);
    test[3].a = 2;
    str_copy(test[3].p, "2");
    list_insert(list, 3, &test[3]);

    for (int i = 0; i < len; i++) {
        test_t *t = (test_t *)list_get(list, i);
        assert(t->a == arr[i]);
        char p[8] = {0};
        int_to_str(arr[i], p, sizeof(p));
        assert(str_equal(t->p, p));
    }

    free(test);
    test = NULL;
    list_destroy(list);
}

void test_list_remove() {
    list_t *list = list_create("int");
    for (int i = 0; i < 5; i++) {
        wrapper_int_t *wrapper = wrap_int(i);
        list_push_back(list, wrapper);
        unwrap_int(wrapper);
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

    list = list_create("double");
    for (int i = 0; i < 5; i++) {
        wrapper_double_t *wrapper = wrap_double((double)i);
        list_push_back(list, wrapper);
        unwrap_double(wrapper);
    }

    wrapper_double_t *wrapper_double = (wrapper_double_t *)list_remove(list, 1);
    assert(equal_double(unwrap_double(wrapper_double), 1.0));
    wrapper_double = (wrapper_double_t *)list_remove(list, 3);
    assert(equal_double(unwrap_double(wrapper_double), 4.0));
    wrapper_double = (wrapper_double_t *)list_remove(list, 0);
    assert(equal_double(unwrap_double(wrapper_double), 0.0));

    assert(list_size(list) == 2);
    for (int i = 2; i <= 3; i++) {
        wrapper_double_t *wrapper = (wrapper_double_t *)list_pop_front(list);
        assert(equal_double(unwrap_double(wrapper), (double)i));
    }
    list_destroy(list);

    list = list_create("T");
    test_t *test = (test_t *)calloc(5, sizeof(test_t));
    for (int i = 0; i < 5; i++) {
        test[i].a = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].p, str);
        list_push_back(list, &test[i]);
    }

    test_t *t = (test_t *)list_remove(list, 1);
    assert(t->a == 1);
    assert(str_equal(t->p, "1"));
    t = (test_t *)list_remove(list, 3);
    assert(t->a == 4);
    assert(str_equal(t->p, "4"));
    t = (test_t *)list_remove(list, 0);
    assert(t->a == 0);
    assert(str_equal(t->p, "0"));

    for (int i = 2; i <= 3; i++) {
        t = (test_t *)list_pop_front(list);
        assert(t->a == i);
        char p[16] = {0};
        int_to_str(i, p, sizeof(p));
        assert(str_equal(t->p, p));
    }
    free(test);
    test = NULL;
    list_destroy(list);
}