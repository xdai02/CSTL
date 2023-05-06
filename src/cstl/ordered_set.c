#include "cstl/ordered_set.h"
#include "cstl/red_black_tree.h"

struct ordered_set_t {
    red_black_tree_t *tree;
    compare_t compare;
};

/**
 * @brief Create an ordered_set_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created ordered_set_t object if successful, otherwise returns NULL.
 */
ordered_set_t *ordered_set_create(compare_t compare, destroy_t destroy) {
    ordered_set_t *set = NULL;

    return_value_if_fail(compare != NULL, NULL);

    set = (ordered_set_t *)malloc(sizeof(ordered_set_t));
    return_value_if_fail(set != NULL, NULL);

    set->tree = red_black_tree_create(compare, destroy);
    if (set->tree == NULL) {
        free(set);
        return NULL;
    }

    set->compare = compare;
    return set;
}

/**
 * @brief Destroy an ordered_set_t object.
 * @param set The ordered_set_t object.
 */
void ordered_set_destroy(ordered_set_t *set) {
    return_if_fail(set != NULL);
    red_black_tree_destroy(set->tree);
    free(set);
}

/**
 * @brief Determine whether an ordered_set_t object is empty.
 * @param set The ordered_set_t object.
 * @return Returns true if the ordered_set_t object is empty, otherwise returns false.
 */
bool ordered_set_is_empty(const ordered_set_t *set) {
    return_value_if_fail(set != NULL, true);
    return red_black_tree_is_empty(set->tree);
}

/**
 * @brief Get the size of an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the size of the ordered_set_t object.
 */
size_t ordered_set_size(const ordered_set_t *set) {
    return_value_if_fail(set != NULL, 0);
    return red_black_tree_size(set->tree);
}

/**
 * @brief Traverse an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param visit Callback function for visiting a data item.
 */
void ordered_set_foreach(ordered_set_t *set, visit_t visit) {
    return_if_fail(set != NULL && visit != NULL);
    red_black_tree_foreach(set->tree, visit);
}

/**
 * @brief Clear an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the modified ordered_set_t object.
 */
ordered_set_t *ordered_set_clear(ordered_set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    red_black_tree_clear(set->tree);
    return set;
}

/**
 * @brief Check if an ordered_set_t object contains the specified element.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns true if the ordered_set_t object contains the specified element, otherwise returns false.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
bool ordered_set_contains(const ordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, false);
    return red_black_tree_contains(set->tree, elem);
}

/**
 * @brief Add an element to the ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns the modified ordered_set_t object.
 */
ordered_set_t *ordered_set_add(ordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    red_black_tree_insert(set->tree, elem);
    return set;
}

/**
 * @brief Remove the element from the ordered_set_t object.
 * @param set The ordered_set_t object.
 * @param elem The element.
 * @return Returns the modified ordered_set_t object.
 * @note Caller MUST free the parameter `elem` (if applicable).
 */
ordered_set_t *ordered_set_remove(ordered_set_t *set, T elem) {
    return_value_if_fail(set != NULL && elem != NULL, set);
    red_black_tree_remove(set->tree, elem);
    return set;
}

/**
 * @brief Get the union of two ordered_set_t objects.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the union of two ordered_set_t objects.
 * @note Caller MUST destroy the returned union ordered_set_t object.
 */
ordered_set_t *ordered_set_union(const ordered_set_t *set1, const ordered_set_t *set2) {
    ordered_set_t *union_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 == NULL) {
        union_set = ordered_set_create(set2->compare, NULL);
    } else {
        union_set = ordered_set_create(set1->compare, NULL);
    }
    return_value_if_fail(union_set != NULL, NULL);

    if (set1 != NULL) {
        iterator = red_black_tree_iterator_create(set1->tree);
        return_value_if_fail(iterator != NULL, NULL);
        while (red_black_tree_iterator_has_next(iterator)) {
            elem = red_black_tree_iterator_next(iterator);
            ordered_set_add(union_set, elem);
        }
        red_black_tree_iterator_destroy(iterator);
    }

    if (set2 != NULL) {
        iterator = red_black_tree_iterator_create(set2->tree);
        return_value_if_fail(iterator != NULL, NULL);
        while (red_black_tree_iterator_has_next(iterator)) {
            elem = red_black_tree_iterator_next(iterator);
            ordered_set_add(union_set, elem);
        }
        red_black_tree_iterator_destroy(iterator);
    }

    return union_set;
}

/**
 * @brief Get the intersection of two ordered_set_t objects.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the intersection of two ordered_set_t objects.
 * @note Caller MUST destroy the returned intersection ordered_set_t object.
 */
ordered_set_t *ordered_set_intersection(const ordered_set_t *set1, const ordered_set_t *set2) {
    ordered_set_t *intersection_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    if (set1 == NULL) {
        intersection_set = ordered_set_create(set2->compare, NULL);
    } else {
        intersection_set = ordered_set_create(set1->compare, NULL);
    }
    return_value_if_fail(intersection_set != NULL, NULL);

    return_value_if(set1 == NULL || set2 == NULL, intersection_set);

    iterator = red_black_tree_iterator_create(set1->tree);
    return_value_if_fail(iterator != NULL, NULL);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (ordered_set_contains(set2, elem)) {
            ordered_set_add(intersection_set, elem);
        }
    }
    red_black_tree_iterator_destroy(iterator);

    return intersection_set;
}

/**
 * @brief Get the difference of two ordered_set_t objects.
 *        A - B
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the difference of two ordered_set_t objects.
 * @note Caller MUST destroy the returned difference ordered_set_t object.
 */
ordered_set_t *ordered_set_difference(const ordered_set_t *set1, const ordered_set_t *set2) {
    ordered_set_t *difference_set = NULL;
    iterator_t *iterator = NULL;
    T elem = NULL;

    return_value_if_fail(set1 != NULL, NULL);

    difference_set = ordered_set_create(set1->compare, NULL);
    return_value_if_fail(difference_set != NULL, NULL);

    iterator = red_black_tree_iterator_create(set1->tree);
    return_value_if_fail(iterator != NULL, NULL);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (!ordered_set_contains(set2, elem)) {
            ordered_set_add(difference_set, elem);
        }
    }
    red_black_tree_iterator_destroy(iterator);

    return difference_set;
}

/**
 * @brief Get the symmetric difference of two ordered_set_t objects.
 *        (A - B) U (B - A)
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns the symmetric difference of two ordered_set_t objects.
 * @note Caller MUST destroy the returned symmetric difference ordered_set_t object.
 */
ordered_set_t *ordered_set_symmetric_difference(const ordered_set_t *set1, const ordered_set_t *set2) {
    ordered_set_t *union_set = NULL;
    ordered_set_t *intersection_set = NULL;
    ordered_set_t *symmetric_difference_set = NULL;

    return_value_if(set1 == NULL && set2 == NULL, NULL);

    union_set = ordered_set_union(set1, set2);
    intersection_set = ordered_set_intersection(set1, set2);
    symmetric_difference_set = ordered_set_difference(union_set, intersection_set);

    ordered_set_destroy(union_set);
    ordered_set_destroy(intersection_set);
    return symmetric_difference_set;
}

/**
 * @brief Determine if two ordered_set_t objects are disjoint.
 *        Two sets are disjoint if their intersection is empty.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns true if two ordered_set_t objects are disjoint, otherwise returns false.
 */
bool ordered_set_is_disjoint(const ordered_set_t *set1, const ordered_set_t *set2) {
    ordered_set_t *intersection_set = NULL;
    bool is_disjoint = false;

    return_value_if_fail(set1 != NULL && set2 != NULL, true);

    intersection_set = ordered_set_intersection(set1, set2);
    is_disjoint = ordered_set_is_empty(intersection_set);
    ordered_set_destroy(intersection_set);
    return is_disjoint;
}

/**
 * @brief Determine if set1 is a subset of set2.
 *        A is a subset B if every element of A is also an element of B.
 * @param set1 The first ordered_set_t object.
 * @param set2 The second ordered_set_t object.
 * @return Returns true if set1 is a subset of set2, otherwise returns false.
 */
bool ordered_set_is_subset(const ordered_set_t *set1, const ordered_set_t *set2) {
    iterator_t *iterator = NULL;
    T elem = NULL;
    bool is_subset = true;

    return_value_if(set1 == NULL, true);
    return_value_if(set2 == NULL, false);

    iterator = red_black_tree_iterator_create(set1->tree);
    while (red_black_tree_iterator_has_next(iterator)) {
        elem = red_black_tree_iterator_next(iterator);
        if (!ordered_set_contains(set2, elem)) {
            is_subset = false;
            break;
        }
    }
    red_black_tree_iterator_destroy(iterator);
    return is_subset;
}

/**
 * @brief Create an iterator for an ordered_set_t object.
 * @param set The ordered_set_t object.
 * @return Returns the iterator for container.
 */
iterator_t *ordered_set_iterator_create(const ordered_set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    return red_black_tree_iterator_create(set->tree);
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void ordered_set_iterator_destroy(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    red_black_tree_iterator_destroy(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool ordered_set_iterator_has_next(const iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, false);
    return red_black_tree_iterator_has_next(iterator);
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T ordered_set_iterator_next(iterator_t *iterator) {
    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(ordered_set_iterator_has_next(iterator), NULL);
    return red_black_tree_iterator_next(iterator);
}
