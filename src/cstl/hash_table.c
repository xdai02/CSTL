#include "cstl/hash_table.h"
#include "cstl/list.h"

#define DEFAULT_CAPACITY 16
#define GROWTH_FACTOR 2
#define LOAD_FACTOR_THRESHOLD 0.75

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
    hash_t hash;
};

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

static void __pair_destroy(T elem) {
    pair_t *pair = (pair_t *)elem;
    return_if_fail(pair != NULL);

    if (__destroy_key != NULL) {
        __destroy_key(pair->key);
    }
    if (__destroy_value != NULL) {
        __destroy_value(pair->value);
    }
    free(pair);
}

static size_t __hash(const hash_table_t *hash_table, T key) {
    size_t hash_value = 0;

    exit_if_fail(hash_table != NULL && key != NULL);

    if (hash_table->hash != NULL) {
        hash_value = hash_table->hash(key);
    } else {
        hash_value = (size_t)key;
    }
    return hash_value % hash_table->capacity;
}

hash_table_t *hash_table_create(compare_t compare, destroy_t destroy_key, destroy_t destroy_value, hash_t hash) {
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
    hash_table->hash = hash;

    return hash_table;
}

void hash_table_destroy(hash_table_t *hash_table) {
    size_t i = 0;

    return_if_fail(hash_table != NULL);

    __destroy_key = hash_table->destroy_key;
    __destroy_value = hash_table->destroy_value;

    for (i = 0; i < hash_table->capacity; i++) {
        list_destroy(hash_table->buckets[i]);
    }
    free(hash_table->buckets);
    free(hash_table);
}

bool hash_table_is_empty(const hash_table_t *hash_table) {
    return_value_if_fail(hash_table != NULL, true);
    return hash_table->size == 0;
}

size_t hash_table_size(const hash_table_t *hash_table) {
    return_value_if_fail(hash_table != NULL, 0);
    return hash_table->size;
}

hash_table_t *hash_table_clear(hash_table_t *hash_table) {
    size_t i = 0;

    return_value_if_fail(hash_table != NULL, NULL);

    __destroy_key = hash_table->destroy_key;
    __destroy_value = hash_table->destroy_value;

    for (i = 0; i < hash_table->capacity; i++) {
        list_clear(hash_table->buckets[i]);
    }
    hash_table->size = 0;
    return hash_table;
}

static bool __hash_table_resize(hash_table_t *hash_table) {
    size_t old_capacity;
    size_t new_capacity;
    list_t **new_buckets = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    size_t i = 0;
    size_t j = 0;
    size_t new_index = 0;

    return_value_if_fail(hash_table != NULL, false);

    new_capacity = hash_table->capacity * GROWTH_FACTOR;
    new_buckets = (list_t **)malloc(sizeof(list_t *) * new_capacity);
    return_value_if_fail(new_buckets != NULL, false);

    for (i = 0; i < new_capacity; i++) {
        new_buckets[i] = list_create(hash_table->compare, __pair_destroy);
        if (new_buckets[i] == NULL) {
            for (j = 0; j < i; j++) {
                list_destroy(new_buckets[j]);
            }
            free(new_buckets);
            return false;
        }
    }

    old_capacity = hash_table->capacity;
    hash_table->capacity = new_capacity;

    /* Rehash */
    for (i = 0; i < old_capacity; i++) {
        iterator = list_iterator_create(hash_table->buckets[i]);
        if (iterator == NULL) {
            for (j = 0; j < new_capacity; j++) {
                list_destroy(new_buckets[j]);
            }
            free(new_buckets);
            hash_table->capacity = old_capacity;
            return false;
        }

        while (list_iterator_has_next(iterator)) {
            pair = (pair_t *)list_iterator_next(iterator);
            new_index = __hash(hash_table, pair->key);
            list_push_back(new_buckets[new_index], pair);
        }

        while (!list_is_empty(hash_table->buckets[i])) {
            list_pop_front(hash_table->buckets[i]);
        }

        list_iterator_destroy(iterator);
        list_destroy(hash_table->buckets[i]);
    }

    free(hash_table->buckets);
    hash_table->buckets = new_buckets;
    return true;
}

hash_table_t *hash_table_put(hash_table_t *hash_table, T key, T value) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;

    return_value_if_fail(hash_table != NULL, NULL);
    return_value_if_fail(key != NULL && value != NULL, hash_table);

    index = __hash(hash_table, key);
    bucket = hash_table->buckets[index];

    iterator = list_iterator_create(bucket);
    return_value_if_fail(iterator != NULL, hash_table);

    while (list_iterator_has_next(iterator)) {
        pair = (pair_t *)list_iterator_next(iterator);

        /* Key already exists, update the value */
        if (hash_table->compare(pair->key, key) == 0) {
            if (hash_table->destroy_key != NULL) {
                hash_table->destroy_key(key);
            }
            if (hash_table->destroy_value != NULL) {
                hash_table->destroy_value(pair->value);
            }
            pair->value = value;
            list_iterator_destroy(iterator);
            return hash_table;
        }
    }

    /* Key not found, insert a new pair */
    pair = __pair_create(key, value);
    if (pair == NULL) {
        list_iterator_destroy(iterator);
        return hash_table;
    }

    list_push_back(bucket, pair);
    hash_table->size++;
    list_iterator_destroy(iterator);

    if ((float)hash_table->size / hash_table->capacity > LOAD_FACTOR_THRESHOLD) {
        return_value_if_fail(__hash_table_resize(hash_table), hash_table);
    }

    return hash_table;
}

/* @note Caller MUST free the parameter `key` (if applicable). */
hash_table_t *hash_table_remove(hash_table_t *hash_table, T key) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    size_t i = 0;

    return_value_if_fail(hash_table != NULL && key != NULL, hash_table);

    index = __hash(hash_table, key);
    bucket = hash_table->buckets[index];

    iterator = list_iterator_create(bucket);
    return_value_if_fail(iterator != NULL, hash_table);

    i = 0;
    while (list_iterator_has_next(iterator)) {
        pair = (pair_t *)list_iterator_next(iterator);
        if (hash_table->compare(pair->key, key) == 0) {
            pair = list_remove(bucket, i);
            __destroy_key = hash_table->destroy_key;
            __destroy_value = hash_table->destroy_value;
            __pair_destroy(pair);
            hash_table->size--;
            break;
        }
        i++;
    }

    list_iterator_destroy(iterator);
    return hash_table;
}

/* @note Caller MUST free the parameter `key` (if applicable). */
T hash_table_get(const hash_table_t *hash_table, T key) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    T value = NULL;

    return_value_if_fail(hash_table != NULL && key != NULL, NULL);

    index = __hash(hash_table, key);
    bucket = hash_table->buckets[index];

    iterator = list_iterator_create(bucket);
    return_value_if_fail(iterator != NULL, NULL);

    while (list_iterator_has_next(iterator)) {
        pair = (pair_t *)list_iterator_next(iterator);
        if (hash_table->compare(pair->key, key) == 0) {
            value = pair->value;
            break;
        }
    }

    list_iterator_destroy(iterator);
    return value;
}
