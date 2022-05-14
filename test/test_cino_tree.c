#include "test_cino_tree.h"

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

void test_tree_create() {
    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);
}

void test_tree_destroy() {
    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);
}

void test_tree_is_empty() {
    int arr[] = {5, 2, 8, 0, 5, 6, 2, 2, 12, 12, 23, 9, 18, 9, 10};
    int len = arr_len(arr);

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(arr[i]));
    }
    tree_in_order(tree, visit_int);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(arr[i]));
    }
    tree_pre_order(tree, visit_double);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + arr[i]));
    }
    tree_pre_order(tree, visit_char);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_pre_order(tree, visit_test);

    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_size() {
    const int len = 5;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    assert(!tree_is_empty(tree));
    assert(tree_size(tree) == len);
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    assert(!tree_is_empty(tree));
    assert(tree_size(tree) == len);
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    assert(!tree_is_empty(tree));
    assert(tree_size(tree) == len);
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    assert(!tree_is_empty(tree));
    assert(tree_size(tree) == len);
    tree_clear(tree);
    assert(tree_is_empty(tree));
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_clear() {
    int arr[] = {5, 2, 8, 0, 5, 6, 2, 2, 12, 12, 23, 9, 18, 9, 10};
    int len = arr_len(arr);

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(arr[i]));
    }
    tree_in_order(tree, visit_int);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(arr[i]));
    }
    tree_pre_order(tree, visit_double);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + arr[i]));
    }
    tree_pre_order(tree, visit_char);
    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = arr[i];
        char str[8] = {0};
        int_to_str(arr[i], str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_pre_order(tree, visit_test);

    assert(!tree_is_empty(tree));
    tree_clear(tree);
    assert(tree_is_empty(tree));
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_pre_order() {
    const int len = 10;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    tree_in_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    tree_pre_order(tree, visit_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    tree_pre_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_pre_order(tree, visit_test);

    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_in_order() {
    const int len = 10;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    tree_in_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    tree_in_order(tree, visit_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    assert(tree_is_empty(tree));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    tree_in_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_in_order(tree, visit_test);

    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_post_order() {
    const int len = 10;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    tree_post_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    tree_post_order(tree, visit_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    tree_post_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    assert(tree_is_empty(tree));
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, &test[i]);
    }
    tree_post_order(tree, visit_test);
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_min() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = arr_len(arr1);

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len1; i++) {
        tree_insert(tree, wrap_int(arr1[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)tree_min(tree);
    assert(wrapper_int->data == 1);
    tree_destroy(tree);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = arr_len(arr2);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len2; i++) {
        tree_insert(tree, wrap_double(arr2[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)tree_min(tree);
    assert(double_equal(wrapper_double->data, 1.1));
    tree_destroy(tree);

    char arr3[] = {'D', 'F', 'A', 'G', 'C', 'B', 'D', 'E', '\0'};
    int len3 = str_length(arr3);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len3; i++) {
        tree_insert(tree, wrap_char(arr3[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)tree_min(tree);
    assert(wrapper_char->data == 'A');
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_test_by_int, destroy_default);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    test_t *t = (test_t *)tree_min(tree);
    assert(t->i == 1);
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_max() {
    int arr1[] = {5, 7, 1, 9, 4, 2, 5, 6};
    int len1 = arr_len(arr1);

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len1; i++) {
        tree_insert(tree, wrap_int(arr1[i]));
    }
    wrapper_int_t *wrapper_int = (wrapper_int_t *)tree_max(tree);
    assert(wrapper_int->data == 9);
    tree_destroy(tree);

    double arr2[] = {5.5, 7.7, 1.1, 9.9, 4.4, 2.2, 5.5, 6.6};
    int len2 = arr_len(arr2);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len2; i++) {
        tree_insert(tree, wrap_double(arr2[i]));
    }
    wrapper_double_t *wrapper_double = (wrapper_double_t *)tree_max(tree);
    assert(double_equal(wrapper_double->data, 9.9));
    tree_destroy(tree);

    char arr3[] = {'D', 'F', 'A', 'G', 'C', 'B', 'D', 'E', '\0'};
    int len3 = str_length(arr3);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len3; i++) {
        tree_insert(tree, wrap_char(arr3[i]));
    }
    wrapper_char_t *wrapper_char = (wrapper_char_t *)tree_max(tree);
    assert(wrapper_char->data == 'G');
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_test_by_int, destroy_default);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    test_t *t = (test_t *)tree_max(tree);
    assert(t->i == 9);
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_contains() {
    const int len = 5;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    wrapper_int_t *wrapper_int = NULL;
    for (int i = 0; i < len; i++) {
        wrapper_int = wrap_int(i);
        assert(tree_contains(tree, wrapper_int));
        unwrap_int(wrapper_int);
    }
    wrapper_int = wrap_int(6);
    assert(!tree_contains(tree, wrapper_int));
    unwrap_int(wrapper_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    wrapper_double_t *wrapper_double = NULL;
    for (int i = 0; i < len; i++) {
        wrapper_double = wrap_double(i);
        assert(tree_contains(tree, wrapper_double));
        unwrap_double(wrapper_double);
    }
    wrapper_double = wrap_double(6.0);
    assert(!tree_contains(tree, wrapper_double));
    unwrap_double(wrapper_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    wrapper_char_t *wrapper_char = NULL;
    for (int i = 0; i < len; i++) {
        wrapper_char = wrap_char('A' + i);
        assert(tree_contains(tree, wrapper_char));
        unwrap_char(wrapper_char);
    }
    wrapper_char = wrap_char('X');
    assert(!tree_contains(tree, wrapper_char));
    unwrap_char(wrapper_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        tree_insert(tree, &test[i]);
    }
    for (int i = 0; i < len; i++) {
        assert(tree_contains(tree, &test[i]));
    }
    assert(!tree_contains(tree, NULL));
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_insert() {
    int arr1[] = {5, 2, 8, 0, 5, 6, 2, 2, 12, 57, 23, 63, 18, 84, 55};
    int len1 = arr_len(arr1);

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len1; i++) {
        tree_insert(tree, wrap_int(arr1[i]));
    }
    tree_in_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len1; i++) {
        tree_insert(tree, wrap_double(arr1[i]));
    }
    tree_pre_order(tree, visit_double);
    tree_destroy(tree);

    char arr2[] = {'F', 'A', 'C', 'C', 'A', 'I', 'L', 'W', 'Z', 'T', '\0'};
    int len2 = str_length(arr2);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len2; i++) {
        tree_insert(tree, wrap_char(arr2[i]));
    }
    tree_pre_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len1, sizeof(test_t));

    for (int i = 0; i < len1; i++) {
        test[i].i = arr1[i];
        char str[8] = {0};
        int_to_str(arr1[i], str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_pre_order(tree, visit_test);

    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_remove() {
    const int len = 10;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    tree_remove(tree, wrap_int(5));
    tree_remove(tree, wrap_int(3));
    tree_remove(tree, wrap_int(5));
    tree_remove(tree, wrap_int(9));
    tree_pre_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    tree_remove(tree, wrap_double(5));
    tree_remove(tree, wrap_double(3));
    tree_remove(tree, wrap_double(5));
    tree_remove(tree, wrap_double(9));
    tree_pre_order(tree, visit_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    tree_remove(tree, wrap_char('A' + 5));
    tree_remove(tree, wrap_char('A' + 3));
    tree_remove(tree, wrap_char('A' + 5));
    tree_remove(tree, wrap_char('A' + 9));
    tree_pre_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    tree_remove(tree, &test[5]);
    tree_remove(tree, &test[3]);
    tree_remove(tree, &test[5]);
    tree_remove(tree, &test[9]);
    tree_pre_order(tree, visit_test);

    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_set() {
    const int len = 5;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    for (int i = 0; i < len; i++) {
        tree_set(tree, wrap_int(i), wrap_int(len - i - 1));
    }
    tree_pre_order(tree, visit_int);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    for (int i = 0; i < len; i++) {
        tree_set(tree, wrap_double(i), wrap_double(len - i - 1));
    }
    tree_pre_order(tree, visit_double);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    for (int i = 0; i < len; i++) {
        tree_set(tree, wrap_char('A' + i), wrap_char('A' + len - i - 1));
    }
    tree_pre_order(tree, visit_char);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    for (int i = 0; i < len; i++) {
        tree_set(tree, &test[i], &test[len - i - 1]);
    }
    tree_pre_order(tree, visit_test);

    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_node_array_create() {
    const int len = 5;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    array_t *array = tree_node_array_create(tree);
    array_foreach(array, visit_int, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    array = tree_node_array_create(tree);
    array_foreach(array, visit_double, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    array = tree_node_array_create(tree);
    array_foreach(array, visit_char, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    array = tree_node_array_create(tree);
    array_foreach(array, visit_test, false);

    tree_node_array_destroy(array);
    free(test);
    test = NULL;
    tree_destroy(tree);
}

void test_tree_node_array_destroy() {
    const int len = 5;

    tree_t *tree = tree_create(DATA_TYPE_INT, compare_int, destroy_int);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_int(i));
    }
    array_t *array = tree_node_array_create(tree);
    array_foreach(array, visit_int, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_DOUBLE, compare_double, destroy_double);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_double(i));
    }
    array = tree_node_array_create(tree);
    array_foreach(array, visit_double, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_CHAR, compare_char, destroy_char);
    for (int i = 0; i < len; i++) {
        tree_insert(tree, wrap_char('A' + i));
    }
    array = tree_node_array_create(tree);
    array_foreach(array, visit_char, false);
    tree_node_array_destroy(array);
    tree_destroy(tree);

    tree = tree_create(DATA_TYPE_T, compare_default, destroy_default);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        test[i].i = i;
        char str[8] = {0};
        int_to_str(i, str, sizeof(str));
        str_copy(test[i].str, str);
        tree_insert(tree, &test[i]);
    }

    array = tree_node_array_create(tree);
    array_foreach(array, visit_test, false);
    tree_node_array_destroy(array);

    free(test);
    test = NULL;
    tree_destroy(tree);
}