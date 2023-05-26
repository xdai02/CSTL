#ifndef _PAIR_H_
#define _PAIR_H_

#include "utils/exception.h"
#include "utils/types.h"
#include "utils/generic.h"

typedef struct pair_t pair_t;

/**
 * @brief Create a pair_t object.
 * @param key The key.
 * @param value The value.
 * @param destroy_key Callback function for destroying the key.
 * @param destroy_value Callback function for destroying the value.
 * @return Returns the created pair_t object if successful, otherwise returns NULL.
 */
pair_t *pair_new(T key, T value, destroy_t destroy_key, destroy_t destroy_value);

/**
 * @brief Destroy a pair_t object.
 * @param pair The pair_t object.
 */
void pair_delete(pair_t *pair);

/**
 * @brief Get the key of a pair_t object.
 * @param pair The pair_t object.
 * @return Returns the key of the pair_t object.
 */
T pair_get_key(const pair_t *pair);

/**
 * @brief Get the value of a pair_t object.
 * @param pair The pair_t object.
 * @return Returns the value of the pair_t object.
 */
T pair_get_value(const pair_t *pair);

/**
 * @brief Set the key of a pair_t object.
 * @param pair The pair_t object.
 * @param key The key.
 * @return Returns the modified pair_t object.
 */
pair_t *pair_set_key(pair_t *pair, T key);

/**
 * @brief Set the value of a pair_t object.
 * @param pair The pair_t object.
 * @param value The value.
 * @return Returns the modified pair_t object.
 */
pair_t *pair_set_value(pair_t *pair, T value);

#endif
