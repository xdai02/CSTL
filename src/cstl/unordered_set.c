#include "cstl/unordered_set.h"
#include "cstl/hash_table.h"

#if 0
struct unordered_set_t {
    hash_table_t *hash_table;
};

/**
 * @brief Create an unordered_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @param hash Callback function for hashing a data item.
 * @return Returns the created unordered_set_t object if successful, otherwise returns NULL.
 */
unordered_set_t *unordered_set_new(compare_t compare, destroy_t destroy, hash_t hash) {
    unordered_set_t *set = NULL;
    pair_t *pair = NULL;

    return_value_if_fail(compare != NULL && hash != NULL, NULL);

    set = (unordered_set_t *)malloc(sizeof(unordered_set_t));
    return_value_if_fail(set != NULL, NULL);

    set->hash_table = hash_table_new(compare, destroy, NULL, hash);
    if (set->hash_table == NULL) {
        free(set);
        return NULL;
    }

    return set;
}

/**
 * @brief Destroy an unordered_set_t object.
 * @param set The unordered_set_t object.
 */
void unordered_set_delete(unordered_set_t *set) {
    return_if_fail(set != NULL);
    hash_table_delete(set->hash_table);
    free(set);
}

/**
 * @brief Determine whether an unordered_set_t object is empty.
 * @param set The unordered_set_t object.
 * @return Returns true if the unordered_set_t object is empty, otherwise returns false.
 */
bool unordered_set_is_empty(const unordered_set_t *set) {
    return_value_if_fail(set != NULL, false);
    return hash_table_is_empty(set->hash_table);
}

/**
 * @brief Get the size of an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the size of the unordered_set_t object.
 */
size_t unordered_set_size(const unordered_set_t *set) {
    return_value_if_fail(set != NULL, 0);
    return hash_table_size(set->hash_table);
}

static visit_t __visit = NULL;

static void __visit_pair(T key, T value) {
    __visit(key);
}

/**
 * @brief Traverse an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void unordered_set_foreach(unordered_set_t *set, visit_t visit) {
    return_if_fail(set != NULL);
    __visit = visit;
    hash_table_foreach(set->hash_table, __visit_pair);
}

/**
 * @brief Clear an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the modified unordered_set_t object.
 */
unordered_set_t *unordered_set_clear(unordered_set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    hash_table_clear(set->hash_table);
    return set;
}

/**
 * @brief Check if an unordered_set_t object contains the specified element.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns true if the unordered_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool unordered_set_contains(const unordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL, false);
    return hash_table_get(set->hash_table, elem) != NULL;
}

/**
 * @brief Add an element to the unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns the modified unordered_set_t object.
 */
unordered_set_t *unordered_set_add(unordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    hash_table_put(set->hash_table, elem, elem);
    return set;
}

/**
 * @brief Remove the element from the unordered_set_t object.
 * @param set The unordered_set_t object.
 * @param elem The element.
 * @return Returns the modified unordered_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
unordered_set_t *unordered_set_remove(unordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    hash_table_remove(set->hash_table, elem);
    return set;
}

#endif
