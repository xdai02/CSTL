#include "cstl/hash_table.h"
#include "cstl/list.h"

typedef struct pair_t {
    T key;
    T value;
} pair_t;

struct hash_table_t {
    list_t **buckets;
    size_t size;
    size_t capacity;
    compare_t compare;
    destroy_t destroy_key;
    destroy_t destroy_value;
};

static const int DEFAULT_CAPACITY = 16;

static pair_t *__pair_create(T key, T value) {
    pair_t *pair = NULL;

    return_value_if_fail(key != NULL && value != NULL, NULL);

    pair = (pair_t *)malloc(sizeof(pair_t));
    return_value_if_fail(pair != NULL, NULL);

    pair->key = key;
    pair->value = value;
    return pair;
}

static destroy_t __destroy_key = NULL;
static destroy_t __destroy_value = NULL;

static void __pair_destroy(pair_t *pair) {
    return_if_fail(pair != NULL);

    if (__destroy_key != NULL) {
        __destroy_key(pair->key);
    }
    if (__destroy_value != NULL) {
        __destroy_value(pair->value);
    }
    free(pair);
}

static size_t __hash(const hash_table_t *hash_table, const T key) {
    exit_if_fail(hash_table != NULL && key != NULL);

    // TODO
}

hash_table_t *hash_table_create(compare_t compare, destroy_t destroy_key, destroy_t destroy_value) {
    hash_table_t *hash_table = NULL;
    size_t i = 0;
    size_t j = 0;

    return_value_if_fail(compare != NULL, NULL);

    hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
    return_value_if_fail(hash_table != NULL, NULL);

    hash_table->buckets = (list_t **)malloc(sizeof(list_t *) * DEFAULT_CAPACITY);
    if (hash_table->buckets == NULL) {
        free(hash_table);
        return NULL;
    }

    for (i = 0; i < DEFAULT_CAPACITY; i++) {
        hash_table->buckets[i] = list_create(compare, __pair_destroy);
        if (hash_table->buckets[i] == NULL) {
            for (j = 0; j < i; j++) {
                list_destroy(hash_table->buckets[j]);
            }
            free(hash_table->buckets);
            free(hash_table);
            return NULL;
        }
    }

    hash_table->size = 0;
    hash_table->capacity = DEFAULT_CAPACITY;
    hash_table->compare = compare;
    hash_table->destroy_key = destroy_key;
    hash_table->destroy_value = destroy_value;

    return hash_table;
}

void hash_table_destroy(hash_table_t *hash_table) {
    size_t i = 0;

    return_if_fail(hash_table != NULL);

    for (i = 0; i < hash_table->capacity; i++) {
        list_destroy(hash_table->buckets[i]);
    }
    free(hash_table->buckets);
    free(hash_table);
}
