#include "cstl/pair.h"

struct pair_t {
    T key;
    T value;
    destroy_t destroy_key;
    destroy_t destroy_value;
};

/**
 * @brief Create a pair_t object.
 * @param key The key.
 * @param value The value.
 * @return Returns the created pair_t object if successful, otherwise returns NULL.
 */
pair_t *pair_new(T key, T value, destroy_t destroy_key, destroy_t destroy_value) {
    pair_t *pair = NULL;

    return_value_if_fail(key != NULL, NULL);

    pair = (pair_t *)malloc(sizeof(pair_t));
    return_value_if_fail(pair != NULL, NULL);

    pair->key = key;
    pair->value = value;
    pair->destroy_key = destroy_key;
    pair->destroy_value = destroy_value;
    return pair;
}

/**
 * @brief Destroy a pair_t object.
 * @param pair The pair_t object.
 */
void pair_delete(pair_t *pair) {
    return_if_fail(pair != NULL);

    if (pair->destroy_key != NULL) {
        pair->destroy_key(pair->key);
    }
    if (pair->destroy_value != NULL) {
        pair->destroy_value(pair->value);
    }
    free(pair);
}

T pair_get_key(const pair_t *pair) {
    return_value_if_fail(pair != NULL, NULL);
    return pair->key;
}

T pair_get_value(const pair_t *pair) {
    return_value_if_fail(pair != NULL, NULL);
    return pair->value;
}

pair_t *pair_set_key(pair_t *pair, T key) {
    return_value_if_fail(pair != NULL && key != NULL, pair);
    if (pair->destroy_key != NULL) {
        pair->destroy_key(pair->key);
    }
    pair->key = key;
    return pair;
}

pair_t *pair_set_value(pair_t *pair, T value) {
    return_value_if_fail(pair != NULL, pair);
    if (pair->destroy_value != NULL) {
        pair->destroy_value(pair->value);
    }
    pair->value = value;
    return pair;
}
