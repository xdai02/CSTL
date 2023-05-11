#include "cstl/unordered_set.h"
#include "cstl/hash_table.h"

struct unordered_set_t {
    hash_table_t *hash_table;
    compare_t compare;
    destroy_t destroy;
    hash_t hash;
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

    return_value_if_fail(compare != NULL && hash != NULL, NULL);

    set = (unordered_set_t *)malloc(sizeof(unordered_set_t));
    return_value_if_fail(set != NULL, NULL);

    set->hash_table = hash_table_new(compare, hash);
    if (set->hash_table == NULL) {
        free(set);
        return NULL;
    }

    set->compare = compare;
    set->destroy = destroy;
    set->hash = hash;
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

static void __visit_pair(T pair) {
    return_if_fail(pair != NULL);
    pair = (pair_t *)pair;
    __visit(pair_get_key(pair));
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
    pair_t *pair = NULL;
    return_value_if_fail(set != NULL && elem != NULL, set);
    pair = pair_new(elem, elem, set->destroy, NULL);
    hash_table_put(set->hash_table, pair);
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

/**
 * @brief Get the union of two unordered_set_t objects.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the union of two unordered_set_t objects.
 * @note Caller MUST destroy the returned union unordered_set_t object.
 */
unordered_set_t *unordered_set_union(const unordered_set_t *set1, const unordered_set_t *set2) {
    unordered_set_t *union_set = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    T key;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 != NULL) {
        union_set = unordered_set_new(set1->compare, NULL, set1->hash);
    } else {
        union_set = unordered_set_new(set2->compare, NULL, set2->hash);
    }
    return_value_if_fail(union_set != NULL, NULL);

    if (set1 != NULL) {
        iterator = hash_table_iterator_new(set1->hash_table);
        while (hash_table_iterator_has_next(iterator)) {
            pair = hash_table_iterator_next(iterator);
            key = pair_get_key(pair);
            unordered_set_add(union_set, key);
        }
        hash_table_iterator_delete(iterator);
    }

    if (set2 != NULL) {
        iterator = hash_table_iterator_new(set2->hash_table);
        while (hash_table_iterator_has_next(iterator)) {
            pair = hash_table_iterator_next(iterator);
            key = pair_get_key(pair);
            if (!unordered_set_contains(union_set, key)) {
                unordered_set_add(union_set, key);
            }
        }
        hash_table_iterator_delete(iterator);
    }

    return union_set;
}

/**
 * @brief Get the intersection of two unordered_set_t objects.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the intersection of two unordered_set_t objects.
 * @note Caller MUST destroy the returned intersection unordered_set_t object.
 */
unordered_set_t *unordered_set_intersection(const unordered_set_t *set1, const unordered_set_t *set2) {
    unordered_set_t *intersection_set = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    T key;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 == NULL) {
        intersection_set = unordered_set_new(set2->compare, NULL, set2->hash);
    } else {
        intersection_set = unordered_set_new(set1->compare, NULL, set1->hash);
    }
    return_value_if_fail(intersection_set != NULL, NULL);

    return_value_if(set1 == NULL || set2 == NULL, intersection_set);

    iterator = hash_table_iterator_new(set1->hash_table);
    while (hash_table_iterator_has_next(iterator)) {
        pair = hash_table_iterator_next(iterator);
        key = pair_get_key(pair);
        if (unordered_set_contains(set2, key)) {
            unordered_set_add(intersection_set, key);
        }
    }
    hash_table_iterator_delete(iterator);

    return intersection_set;
}

/**
 * @brief Get the difference of two unordered_set_t objects.
 *        A - B
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the difference of two unordered_set_t objects.
 * @note Caller MUST destroy the returned difference unordered_set_t object.
 */
unordered_set_t *unordered_set_difference(const unordered_set_t *set1, const unordered_set_t *set2) {
    unordered_set_t *difference_set = NULL;
    iterator_t *iterator = NULL;
    pair_t *pair;
    T key;

    return_value_if_fail(set1 != NULL, NULL);

    difference_set = unordered_set_new(set1->compare, NULL, set1->hash);
    return_value_if_fail(difference_set != NULL, NULL);

    iterator = hash_table_iterator_new(set1->hash_table);
    while (hash_table_iterator_has_next(iterator)) {
        pair = hash_table_iterator_next(iterator);
        key = pair_get_key(pair);
        if (!unordered_set_contains(set2, key)) {
            unordered_set_add(difference_set, key);
        }
    }
    hash_table_iterator_delete(iterator);

    return difference_set;
}

/**
 * @brief Get the symmetric difference of two unordered_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns the symmetric difference of two unordered_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference unordered_set_t object.
 */
unordered_set_t *unordered_set_symmetric_difference(const unordered_set_t *set1, const unordered_set_t *set2) {
    unordered_set_t *union_set = NULL;
    unordered_set_t *intersection_set = NULL;
    unordered_set_t *symmetric_difference_set = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    union_set = unordered_set_union(set1, set2);
    intersection_set = unordered_set_intersection(set1, set2);
    symmetric_difference_set = unordered_set_difference(union_set, intersection_set);

    unordered_set_delete(union_set);
    unordered_set_delete(intersection_set);
    return symmetric_difference_set;
}

/**
 * @brief Determine if two unordered_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns true if two unordered_set_t objects are disjoint, otherwise returns false.
 */
bool unordered_set_is_disjoint(const unordered_set_t *set1, const unordered_set_t *set2) {
    unordered_set_t *intersection_set = NULL;
    bool is_disjoint = false;

    return_value_if_fail(set1 != NULL && set2 != NULL, true);

    intersection_set = unordered_set_intersection(set1, set2);
    is_disjoint = unordered_set_is_empty(intersection_set);
    unordered_set_delete(intersection_set);
    return is_disjoint;
}

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first unordered_set_t object.
 * @param set2 The second unordered_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool unordered_set_is_subset(const unordered_set_t *set1, const unordered_set_t *set2) {
    iterator_t *iterator = NULL;
    pair_t *pair;
    T key;
    bool is_subset = true;

    return_value_if(set1 == NULL, true);
    return_value_if(set2 == NULL, false);

    iterator = hash_table_iterator_new(set1->hash_table);
    while (hash_table_iterator_has_next(iterator)) {
        pair = hash_table_iterator_next(iterator);
        key = pair_get_key(pair);
        if (!unordered_set_contains(set2, key)) {
            is_subset = false;
            break;
        }
    }
    hash_table_iterator_delete(iterator);

    return is_subset;
}

/**
 * @brief Create an iterator for an unordered_set_t object.
 * @param set The unordered_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *unordered_set_iterator_new(const unordered_set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    return hash_table_iterator_new(set->hash_table);
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void unordered_set_iterator_delete(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    hash_table_iterator_delete(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool unordered_set_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return hash_table_iterator_has_next(iterator);
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T unordered_set_iterator_next(iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(unordered_set_iterator_has_next(iterator), NULL);
    return pair_get_key(hash_table_iterator_next(iterator));
}
