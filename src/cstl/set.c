#include "set.h"
#include "red_black_tree.h"

struct set_t {
    red_black_tree_t *tree;
    compare_t compare;
    destroy_t destroy;
};

/**
 * @brief Create a set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created set_t object if successful, otherwise returns NULL.
 */
set_t *set_create(compare_t compare, destroy_t destroy) {
    set_t *set = NULL;

    return_value_if_fail(compare != NULL, NULL);

    set = (set_t *)malloc(sizeof(set_t));
    return_value_if_fail(set != NULL, NULL);

    set->tree = red_black_tree_create(compare, destroy);
    if (set->tree == NULL) {
        free(set);
        return NULL;
    }

    set->compare = compare;
    set->destroy = destroy;
    return set;
}

/**
 * @brief Destroy an set_t object.
 * @param set The set_t object.
 */
void set_destroy(set_t *set) {
    return_if_fail(set != NULL);
    red_black_tree_destroy(set->tree);
    free(set);
}

/**
 * @brief Determine whether an set_t object is empty.
 * @param set The set_t object.
 * @return Returns true if the set_t object is empty, otherwise returns false.
 */
bool set_is_empty(const set_t *set) {
    return_value_if_fail(set != NULL, true);
    return red_black_tree_is_empty(set->tree);
}

/**
 * @brief Get the size of an set_t object.
 * @param arsetay The set_t object.
 * @return Returns the size of the set_t object.
 */
size_t set_size(const set_t *set) {
    return_value_if_fail(set != NULL, 0);
    return red_black_tree_size(set->tree);
}

/**
 * @brief Traverse an set_t object.
 * @param set The set_t object.
 * @param visit Callback function for visiting a data item.
 */
void set_foreach(set_t *set, visit_t visit) {
    return_if_fail(set != NULL && visit != NULL);
    red_black_tree_foreach(set->tree, visit);
}

/**
 * @brief Clear an set_t object.
 * @param set The set_t object.
 * @return Returns the modified set_t object.
 */
set_t *set_clear(set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    red_black_tree_clear(set->tree);
    return set;
}

/**
 * @brief Check if an set_t object contains the specified element.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns true if the set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool set_contains(const set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, false);
    return red_black_tree_contains(set->tree, elem);
}

/**
 * @brief Add an element to the set_t object.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns the modified set_t object.
 */
set_t *set_add(set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    red_black_tree_insert(set->tree, elem);
    return set;
}

/**
 * @brief Remove the element from the set_t object.
 * @param set The set_t object.
 * @param elem The element.
 * @return Returns the modified set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
set_t *set_remove(set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    red_black_tree_remove(set->tree, elem);
    return set;
}

/**
 * @brief Get the union of two set_t objects.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the union of two set_t objects.
 * @note Caller MUST destroy the returned union set_t object.
 */
set_t *set_union(const set_t *set1, const set_t *set2) {
    set_t *union_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 == NULL) {
        union_set = set_create(set2->compare, NULL);
    } else {
        union_set = set_create(set1->compare, NULL);
    }
    return_value_if_fail(union_set != NULL, NULL);

    if (set1 != NULL) {
        iterator = red_black_tree_iterator_create(set1->tree);
        return_value_if_fail(iterator != NULL, NULL);
        while (red_black_tree_iterator_has_next(iterator)) {
            elem = red_black_tree_iterator_next(iterator);
            set_add(union_set, elem);
        }
        red_black_tree_iterator_destroy(iterator);
    }

    if (set2 != NULL) {
        iterator = red_black_tree_iterator_create(set2->tree);
        return_value_if_fail(iterator != NULL, NULL);
        while (red_black_tree_iterator_has_next(iterator)) {
            elem = red_black_tree_iterator_next(iterator);
            set_add(union_set, elem);
        }
        red_black_tree_iterator_destroy(iterator);
    }

    return union_set;
}

/**
 * @brief Set the intersection of two set_t objects.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the intersection of two set_t objects.
 * @note Caller MUST destroy the returned intersection set_t object.
 */
set_t *set_intersection(const set_t *set1, const set_t *set2) {
    set_t *intersection_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 == NULL) {
        intersection_set = set_create(set2->compare, NULL);
    } else {
        intersection_set = set_create(set1->compare, NULL);
    }
    return_value_if_fail(intersection_set != NULL, NULL);

    return_value_if(set1 == NULL || set2 == NULL, intersection_set);

    iterator = red_black_tree_iterator_create(set1->tree);
    return_value_if_fail(iterator != NULL, NULL);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (set_contains(set2, elem)) {
            set_add(intersection_set, elem);
        }
    }
    red_black_tree_iterator_destroy(iterator);

    return intersection_set;
}

/**
 * @brief Get the difference of two set_t objects.
 *        A - B
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the difference of two set_t objects.
 * @note Caller MUST destroy the returned difference set_t object.
 */
set_t *set_difference(const set_t *set1, const set_t *set2) {
    set_t *difference_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if_fail(set1 != NULL, NULL);

    difference_set = set_create(set1->compare, NULL);
    return_value_if_fail(difference_set != NULL, NULL);

    iterator = red_black_tree_iterator_create(set1->tree);
    return_value_if_fail(iterator != NULL, NULL);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (!set_contains(set2, elem)) {
            set_add(difference_set, elem);
        }
    }
    red_black_tree_iterator_destroy(iterator);

    return difference_set;
}

/**
 * @brief Get the symmetric difference of two set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns the symmetric difference of two set_t objects.
 * @note Caller MUST destroy the returned symmetric difference set_t object.
 */
set_t *set_symmetric_difference(const set_t *set1, const set_t *set2) {
    set_t *union_set = NULL;
    set_t *intersection_set = NULL;
    set_t *symmetric_difference_set = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    union_set = set_union(set1, set2);
    intersection_set = set_intersection(set1, set2);
    symmetric_difference_set = set_difference(union_set, intersection_set);

    set_destroy(union_set);
    set_destroy(intersection_set);
    return symmetric_difference_set;
}

/**
 * @brief Determine if two set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns true if two set_t objects are disjoint, otherwise returns false.
 */
bool set_is_disjoint(const set_t *set1, const set_t *set2) {
    set_t *intersection_set = NULL;
    bool is_disjoint = false;

    return_value_if_fail(set1 != NULL && set2 != NULL, true);

    intersection_set = set_intersection(set1, set2);
    is_disjoint = set_is_empty(intersection_set);
    set_destroy(intersection_set);
    return is_disjoint;
}

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first set_t object.
 * @param set2 The second set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool set_is_subset(const set_t *set1, const set_t *set2) {
    iterator_t *iterator = NULL;
    T elem = NULL;
    bool is_subset = true;

    return_value_if(set1 == NULL, true);
    return_value_if(set2 == NULL, false);

    iterator = red_black_tree_iterator_create(set1->tree);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (!set_contains(set2, elem)) {
            is_subset = false;
            break;
        }
    }
    red_black_tree_iterator_destroy(iterator);
    return is_subset;
}

/**
 * @brief Create an iterator for an set_t object.
 * @param set The set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *set_iterator_create(const set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    return red_black_tree_iterator_create(set->tree);
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void set_iterator_destroy(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    red_black_tree_iterator_destroy(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool set_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return red_black_tree_iterator_has_next(iterator);
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T set_iterator_next(iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(set_iterator_has_next(iterator), NULL);
    return red_black_tree_iterator_next(iterator);
}
