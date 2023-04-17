#include "test_cino_map.h"

typedef struct test_t {
    int i;
    char str[16];
} test_t;

static void visit_int(void *data) {
    kv_pair_t *kv_pair = (kv_pair_t *)data;
    assert(kv_pair);
    const str_t key = kv_pair_get_key(kv_pair);
    T value = kv_pair_get_value(kv_pair);
    wrapper_int_t *wrap_int = (wrapper_int_t *)value;
    LOGGER(NONE, "\"%s\": %d", key, wrap_int->data);
}

static void visit_double(void *data) {
    kv_pair_t *kv_pair = (kv_pair_t *)data;
    assert(kv_pair);
    const str_t key = kv_pair_get_key(kv_pair);
    T value = kv_pair_get_value(kv_pair);
    wrapper_double_t *wrap_double = (wrapper_double_t *)value;
    LOGGER(NONE, "\"%s\": %f", key, wrap_double->data);
}

static void visit_char(void *data) {
    kv_pair_t *kv_pair = (kv_pair_t *)data;
    assert(kv_pair);
    const str_t key = kv_pair_get_key(kv_pair);
    T value = kv_pair_get_value(kv_pair);
    wrapper_char_t *wrap_char = (wrapper_char_t *)value;
    LOGGER(NONE, "\"%s\": \'%c\'", key, wrap_char->data);
}

static void visit_test(void *data) {
    kv_pair_t *kv_pair = (kv_pair_t *)data;
    assert(kv_pair);
    const str_t key = kv_pair_get_key(kv_pair);
    T value = kv_pair_get_value(kv_pair);
    test_t *test = (test_t *)value;
    LOGGER(NONE, "\"%s\": [%d, \"%s\"]", key, test->i, test->str);
}

void test_map_create() {
    map_t *map = map_create(destroy_int);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_double);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_char);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_default);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);
}

void test_map_destroy() {
    map_t *map = map_create(destroy_int);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_double);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_char);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);

    map = map_create(destroy_default);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    map_destroy(map);
}

void test_map_is_empty() {
    const int len = 5;

    map_t *map = map_create(destroy_int);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_double);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_char);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_default);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_size() {
    const int len = 5;

    map_t *map = map_create(destroy_int);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_double);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_char);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_default);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        char key[8] = {0};
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_clear() {
    const int len = 5;
    char key[8] = {0};

    map_t *map = map_create(destroy_int);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_double);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_char);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_default);
    assert(map_is_empty(map));
    assert(map_size(map) == 0);

    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    assert(!map_is_empty(map));
    assert(map_size(map) == len);

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_foreach() {
    const int len = 5;
    char key[8] = {0};

    map_t *map = map_create(destroy_int);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    map_foreach(map, visit_int);
    map_destroy(map);

    map = map_create(destroy_double);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    map_foreach(map, visit_double);
    map_destroy(map);

    map = map_create(destroy_char);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    map_foreach(map, visit_char);
    map_destroy(map);

    map = map_create(destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    map_foreach(map, visit_test);

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_contains() {
    const int len = 5;
    char key[8] = {0};

    map_t *map = map_create(destroy_int);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
        assert(map_contains(map, key));
    }
    int_to_str(len + 1, key, sizeof(key));
    assert(!map_contains(map, key));
    map_destroy(map);

    map = map_create(destroy_int);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
        assert(map_contains(map, key));
    }
    int_to_str(len + 1, key, sizeof(key));
    assert(!map_contains(map, key));
    map_destroy(map);

    map = map_create(destroy_char);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
        assert(map_contains(map, key));
    }
    int_to_str(len + 1, key, sizeof(key));
    assert(!map_contains(map, key));
    map_destroy(map);

    map = map_create(destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));

    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
        assert(map_contains(map, key));
    }
    int_to_str(len + 1, key, sizeof(key));
    assert(!map_contains(map, key));

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_add() {
    const int len = 5;
    char key[8] = {0};

    map_t *map = map_create(destroy_int);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_double);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_char);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    assert(map_size(map) == len);
    map_destroy(map);

    map = map_create(destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    assert(map_size(map) == len);

    free(test);
    test = NULL;
    map_destroy(map);
}

void test_map_remove() {
    const int len = 5;
    const int remove_len = 3;
    char key[8] = {0};

    map_t *map = map_create(destroy_int);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_int(i));
    }
    for (int i = 0; i < remove_len; i++) {
        int_to_str(i, key, sizeof(key));
        map_remove(map, key);
    }
    assert(map_size(map) == len - remove_len);
    map_destroy(map);

    map = map_create(destroy_double);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_double(i));
    }
    for (int i = 0; i < remove_len; i++) {
        int_to_str(i, key, sizeof(key));
        map_remove(map, key);
    }
    assert(map_size(map) == len - remove_len);
    map_destroy(map);

    map = map_create(destroy_char);
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, wrap_char(i));
    }
    for (int i = 0; i < remove_len; i++) {
        int_to_str(i, key, sizeof(key));
        map_remove(map, key);
    }
    assert(map_size(map) == len - remove_len);
    map_destroy(map);

    map = map_create(destroy_default);
    test_t *test = (test_t *)calloc(len, sizeof(test_t));
    for (int i = 0; i < len; i++) {
        int_to_str(i, key, sizeof(key));
        map_add(map, key, &test[i]);
    }
    for (int i = 0; i < remove_len; i++) {
        int_to_str(i, key, sizeof(key));
        map_remove(map, key);
    }
    assert(map_size(map) == len - remove_len);

    free(test);
    test = NULL;
    map_destroy(map);
}
