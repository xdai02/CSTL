#include "cstl/hash_table.h"
#include "cstl/list.h"

#define DEFAULT_CAPACITY 16
#define GROWTH_FACTOR 2
#define LOAD_FACTOR_THRESHOLD 0.75

struct hash_table_t {
    list_t **buckets;
    size_t size;
    size_t capacity;
    compare_t compare;
    hash_t hash;
};

/**
 * @brief Helper function for deleting a pair_t object.
 * @param data The pair_t object.
 */
static void __pair_delete(T data) {
    pair_t *pair = NULL;
    return_if_fail(data != NULL);
    pair = (pair_t *)data;
    pair_delete(pair);
}

/**
 * @brief Get the hash value of a key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns the hash value of the key.
 */
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

/**
 * @brief Create a hash_table_t object.
 * @param compare Callback function for comparing two keys.
 * @param hash Callback function for hashing a key.
 * @return Returns the created hash_table_t object if successful, otherwise returns NULL.
 */
hash_table_t *hash_table_new(compare_t compare, hash_t hash) {
    hash_table_t *hash_table = NULL;
    size_t i = 0;
    size_t j = 0;

    return_value_if_fail(compare != NULL && hash != NULL, NULL);

    hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
    return_value_if_fail(hash_table != NULL, NULL);

    hash_table->buckets = (list_t **)malloc(sizeof(list_t *) * DEFAULT_CAPACITY);
    if (hash_table->buckets == NULL) {
        free(hash_table);
        return NULL;
    }

    for (i = 0; i < DEFAULT_CAPACITY; i++) {
        hash_table->buckets[i] = list_new(NULL, __pair_delete);
        if (hash_table->buckets[i] == NULL) {
            for (j = 0; j < i; j++) {
                list_delete(hash_table->buckets[j]);
            }
            free(hash_table->buckets);
            free(hash_table);
            return NULL;
        }
    }

    hash_table->size = 0;
    hash_table->capacity = DEFAULT_CAPACITY;
    hash_table->compare = compare;
    hash_table->hash = hash;

    return hash_table;
}

/**
 * @brief Destroy a hash_table_t object.
 * @param hash_table The hash_table_t object.
 */
void hash_table_delete(hash_table_t *hash_table) {
    size_t i = 0;

    return_if_fail(hash_table != NULL);

    for (i = 0; i < hash_table->capacity; i++) {
        list_delete(hash_table->buckets[i]);
    }

    free(hash_table->buckets);
    free(hash_table);
}

/**
 * @brief Determine whether a hash_table_t object is empty.
 * @param hash_table The hash_table_t object.
 * @return Returns true if the hash_table_t object is empty, otherwise returns false.
 */
bool hash_table_is_empty(const hash_table_t *hash_table) {
    return_value_if_fail(hash_table != NULL, true);
    return hash_table->size == 0;
}

/**
 * @brief Get the size of a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the size of the hash_table_t object.
 */
size_t hash_table_size(const hash_table_t *hash_table) {
    return_value_if_fail(hash_table != NULL, 0);
    return hash_table->size;
}

/**
 * @brief Traverse a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @param visit Callback function for visiting a key-value pair.
 */
void hash_table_foreach(hash_table_t *hash_table, visit_pair_t visit) {
    size_t i = 0;
    iterator_t *iterator = NULL;
    pair_t *pair;

    return_if_fail(hash_table != NULL && visit != NULL);

    for (i = 0; i < hash_table->capacity; i++) {
        iterator = list_iterator_new(hash_table->buckets[i]);
        while (list_iterator_has_next(iterator)) {
            pair = (pair_t *)list_iterator_next(iterator);
            visit(pair);
        }
        list_iterator_delete(iterator);
    }
}

/**
 * @brief Clear a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the modified hash_table_t object.
 */
hash_table_t *hash_table_clear(hash_table_t *hash_table) {
    size_t i = 0;

    return_value_if_fail(hash_table != NULL, NULL);

    for (i = 0; i < hash_table->capacity; i++) {
        list_clear(hash_table->buckets[i]);
    }

    hash_table->size = 0;
    return hash_table;
}

/**
 * @brief Check if a hash_table_t object contains the specified key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns true if the hash_table_t object contains the specified key, otherwise returns false.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
bool hash_table_contains(const hash_table_t *hash_table, T key) {
    return_value_if_fail(hash_table != NULL && key != NULL, false);
    return hash_table_get(hash_table, key) != NULL;
}

/**
 * @brief Resize a hash_table_t object.
 *        Double the hash_table_t object if the load factor is greater than 0.75.
 * @param hash_table The hash_table_t object.
 * @return Returns true if memory reallocation is successful, otherwise returns false.
 */
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
        new_buckets[i] = list_new(NULL, __pair_delete);
        if (new_buckets[i] == NULL) {
            for (j = 0; j < i; j++) {
                list_delete(new_buckets[j]);
            }
            free(new_buckets);
            return false;
        }
    }

    old_capacity = hash_table->capacity;
    hash_table->capacity = new_capacity;

    /* Rehash */
    for (i = 0; i < old_capacity; i++) {
        iterator = list_iterator_new(hash_table->buckets[i]);
        if (iterator == NULL) {
            for (j = 0; j < new_capacity; j++) {
                list_delete(new_buckets[j]);
            }
            free(new_buckets);
            hash_table->capacity = old_capacity;
            return false;
        }

        while (list_iterator_has_next(iterator)) {
            pair = (pair_t *)list_iterator_next(iterator);
            new_index = __hash(hash_table, pair_get_key(pair));
            list_push_back(new_buckets[new_index], pair);
        }

        while (!list_is_empty(hash_table->buckets[i])) {
            list_pop_front(hash_table->buckets[i]);
        }

        list_iterator_delete(iterator);
        list_delete(hash_table->buckets[i]);
    }

    free(hash_table->buckets);
    hash_table->buckets = new_buckets;
    return true;
}

/**
 * @brief Put a key-value pair into a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @param pair The pair_t object.
 * @return Returns the modified hash_table_t object.
 */
hash_table_t *hash_table_put(hash_table_t *hash_table, pair_t *pair) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *current_pair = NULL;
    pair_t *removed_pair = NULL;
    size_t i = 0;

    return_value_if_fail(hash_table != NULL && pair != NULL, hash_table);

    index = __hash(hash_table, pair_get_key(pair));
    bucket = hash_table->buckets[index];

    i = 0;
    iterator = list_iterator_new(bucket);
    while (list_iterator_has_next(iterator)) {
        current_pair = (pair_t *)list_iterator_next(iterator);

        /* Key already exists */
        if (hash_table->compare(pair_get_key(pair), pair_get_key(current_pair)) == 0) {
            removed_pair = (pair_t *)list_remove(bucket, i);
            pair_delete(removed_pair);
            list_push_back(bucket, pair);
            list_iterator_delete(iterator);
            return hash_table;
        }
        i++;
    }
    list_iterator_delete(iterator);

    /* Key not found, insert a new pair */
    list_push_back(bucket, pair);
    hash_table->size++;

    if ((float)hash_table->size / hash_table->capacity > LOAD_FACTOR_THRESHOLD) {
        return_value_if_fail(__hash_table_resize(hash_table), hash_table);
    }

    return hash_table;
}

/**
 * @brief Remove a key-value pair from a hash_table_t object by given key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns the modified hash_table_t object.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
hash_table_t *hash_table_remove(hash_table_t *hash_table, T key) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    size_t i = 0;

    return_value_if_fail(hash_table != NULL && key != NULL, hash_table);

    index = __hash(hash_table, key);
    bucket = hash_table->buckets[index];

    i = 0;
    iterator = list_iterator_new(bucket);
    while (list_iterator_has_next(iterator)) {
        pair = (pair_t *)list_iterator_next(iterator);
        if (hash_table->compare(pair_get_key(pair), key) == 0) {
            pair = list_remove(bucket, i);
            pair_delete(pair);
            hash_table->size--;
            break;
        }
        i++;
    }

    list_iterator_delete(iterator);
    return hash_table;
}

/**
 * @brief Get the value of a key-value pair by given key.
 * @param hash_table The hash_table_t object.
 * @param key The key.
 * @return Returns the value of the key-value pair if found, otherwise NULL.
 * @note Caller MUST free the parameter `key` (if applicable).
 */
T hash_table_get(const hash_table_t *hash_table, T key) {
    size_t index = 0;
    list_t *bucket = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    T value = NULL;

    return_value_if_fail(hash_table != NULL && key != NULL, NULL);

    index = __hash(hash_table, key);
    bucket = hash_table->buckets[index];

    iterator = list_iterator_new(bucket);
    while (list_iterator_has_next(iterator)) {
        pair = (pair_t *)list_iterator_next(iterator);
        if (hash_table->compare(pair_get_key(pair), key) == 0) {
            value = pair_get_value(pair);
            break;
        }
    }
    list_iterator_delete(iterator);

    return value;
}

typedef struct hash_table_iterator_state_t {
    size_t bucket_index;
    iterator_t *list_iterator;
} hash_table_iterator_state_t;

/**
 * @brief Create an iterator for a hash_table_t object.
 * @param hash_table The hash_table_t object.
 * @return Returns the iterator for container.
 */
iterator_t *hash_table_iterator_new(const hash_table_t *hash_table) {
    iterator_t *iterator = NULL;
    hash_table_iterator_state_t *state = NULL;

    return_value_if_fail(hash_table != NULL, NULL);

    iterator = (iterator_t *)malloc(sizeof(iterator_t));
    return_value_if_fail(iterator != NULL, NULL);

    state = (hash_table_iterator_state_t *)malloc(sizeof(hash_table_iterator_state_t));
    if (state == NULL) {
        free(iterator);
        return NULL;
    }

    state->bucket_index = 0;
    state->list_iterator = list_iterator_new(hash_table->buckets[0]);
    if (state->list_iterator == NULL) {
        free(state);
        free(iterator);
        return NULL;
    }

    iterator->container = (void *)hash_table;
    iterator->current = (void *)state;
    return iterator;
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void hash_table_iterator_delete(iterator_t *iterator) {
    hash_table_iterator_state_t *state = NULL;

    return_if_fail(iterator != NULL);

    if (iterator->current != NULL) {
        state = iterator->current;
        if (state->list_iterator != NULL) {
            list_iterator_delete(state->list_iterator);
        }
        free(state);
    }
    free(iterator);
}

/**
 * @brief Determine whether an iterator has the next pair.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next pair, otherwise returns false.
 */
bool hash_table_iterator_has_next(const iterator_t *iterator) {
    hash_table_iterator_state_t *state = NULL;
    hash_table_t *hash_table = NULL;
    size_t i = 0;

    return_value_if_fail(iterator != NULL, false);
    return_value_if_fail(iterator->current != NULL, false);

    state = (hash_table_iterator_state_t *)iterator->current;
    if (list_iterator_has_next(state->list_iterator)) {
        return true;
    }

    hash_table = (hash_table_t *)iterator->container;
    for (i = state->bucket_index + 1; i < hash_table->capacity; i++) {
        if (!list_is_empty(hash_table->buckets[i])) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Get the next pair of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next pair of the iterator.
 */
pair_t *hash_table_iterator_next(iterator_t *iterator) {
    hash_table_iterator_state_t *state = NULL;
    hash_table_t *hash_table = NULL;
    size_t i = 0;

    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(iterator->current != NULL, NULL);

    state = (hash_table_iterator_state_t *)iterator->current;
    if (list_iterator_has_next(state->list_iterator)) {
        return list_iterator_next(state->list_iterator);
    }

    hash_table = (hash_table_t *)iterator->container;
    for (i = state->bucket_index + 1; i < hash_table->capacity; i++) {
        if (!list_is_empty(hash_table->buckets[i])) {
            /* Destroy the old iterator and create a new one */
            list_iterator_delete(state->list_iterator);
            state->bucket_index = i;
            state->list_iterator = list_iterator_new(hash_table->buckets[i]);
            return_value_if_fail(state->list_iterator != NULL, NULL);
            return list_iterator_next(state->list_iterator);
        }
    }

    return NULL;
}
