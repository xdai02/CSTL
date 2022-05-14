#include "test_cino_set.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void visit_int(void *data) {
    wrapper_int_t *wrapper = (wrapper_int_t *)data;
    assert(wrapper);
    LOGGER(INFO, "wrapper_int->data = %d", wrapper->data);
}

static void visit_double(void *data) {
    wrapper_double_t *wrapper = (wrapper_double_t *)data;
    assert(wrapper);
    LOGGER(INFO, "wrapper_double->data = %f", wrapper->data);
}

static void visit_char(void *data) {
    wrapper_char_t *wrapper = (wrapper_char_t *)data;
    assert(wrapper);
    LOGGER(INFO, "wrapper_char->data = %c", wrapper->data);
}

static void visit_test(void *data) {
    test_t *test = (test_t *)data;
    assert(test);
}

void test_set_create() {
    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);
}

void test_set_destroy() {
    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);
}

void test_set_is_empty() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);

    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_size() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);

    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_clear() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_clear(set);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_clear(set);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);
    set_clear(set);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    assert(!set_is_empty(set));
    assert(set_size(set) == len);

    set_clear(set);
    assert(set_is_empty(set));
    assert(set_size(set) == 0);

    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_foreach() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    set_foreach(set, visit_int);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    set_foreach(set, visit_double);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    set_foreach(set, visit_char);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    set_foreach(set, visit_test);
    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_add() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    assert(set_size(set) == len);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }

    assert(set_size(set) == len);

    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_remove() {
    const int len = 5;

    set_t *set = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_int(i));
    }
    for (int i = 0; i < 3; i++) {
        set_remove(set, wrap_int(i));
    }
    assert(set_size(set) == 2);
    set_foreach(set, visit_int);
    set_destroy(set);

    set = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_double(i));
    }
    for (int i = 0; i < 3; i++) {
        set_remove(set, wrap_double(i));
    }
    assert(set_size(set) == 2);
    set_foreach(set, visit_double);
    set_destroy(set);

    set = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        set_add(set, wrap_char('A' + i));
    }
    for (int i = 0; i < 3; i++) {
        set_remove(set, wrap_char('A' + i));
    }
    assert(set_size(set) == 2);
    set_foreach(set, visit_char);
    set_destroy(set);

    set = set_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        set_add(set, &test[i]);
    }
    for (int i = 0; i < 3; i++) {
        set_remove(set, &test[i]);
    }

    assert(set_size(set) == 2);
    set_foreach(set, visit_test);

    free(test);
    test = NULL;
    set_destroy(set);
}

void test_set_intersection() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 5, 7, 9};
    int len1 = arr_len(arr1);
    int len2 = arr_len(arr2);

    set_t *set1 = set_create(DATA_TYPE_INT, compare_int, destroy_int);
    set_t *set2 = set_create(DATA_TYPE_INT, compare_int, destroy_int);

    for (int i = 0; i < len1; i++) {
        set_add(set1, wrap_int(arr1[i]));
    }
    for (int i = 0; i < len2; i++) {
        set_add(set2, wrap_int(arr2[i]));
    }

    set_t *intersection = set_intersection(set1, set2);
    assert(set_size(intersection) == 3);
    set_foreach(intersection, visit_int);

    set_destroy(intersection);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    set2 = set_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);

    for (int i = 0; i < len1; i++) {
        set_add(set1, wrap_double(arr1[i]));
    }
    for (int i = 0; i < len2; i++) {
        set_add(set2, wrap_double(arr2[i]));
    }

    intersection = set_intersection(set1, set2);
    assert(set_size(intersection) == 3);
    set_foreach(intersection, visit_double);

    set_destroy(intersection);
    set_destroy(set1);
    set_destroy(set2);

    set1 = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    set2 = set_create(DATA_TYPE_CHAR, compare_char, destroy_char);

    for (int i = 0; i < len1; i++) {
        set_add(set1, wrap_char(arr1[i] + 'A'));
    }
    for (int i = 0; i < len2; i++) {
        set_add(set2, wrap_char(arr2[i] + 'A'));
    }

    intersection = set_intersection(set1, set2);
    assert(set_size(intersection) == 3);
    set_foreach(intersection, visit_char);

    set_destroy(intersection);
    set_destroy(set1);
    set_destroy(set2);
}

void test_set_union() {
}

void test_set_difference() {
}