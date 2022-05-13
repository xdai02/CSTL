#include "cino_set.h"
#include "cino_tree.h"

/****************************************
 *               set_t
 ****************************************/

typedef struct set_t {
    tree_t *tree;
    data_type_t data_type;
    size_t size;
    compare_t compare;
    destroy_t destroy;
} set_t;

/**
 * @brief   Create cino-set.
 * @param data_type data type
 *                  valid data type includes:
 *                      - DATA_TYPE_INT
 *                      - DATA_TYPE_DOUBLE
 *                      - DATA_TYPE_CHAR
 *                      - DATA_TYPE_T (generic)
 * @param compare   User-defined callback function for comparison.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
 * @param destroy   User-defined callback function for destroying.
 *                  Set to:
 *                      - `compare_int` if the data type is DATA_TYPE_INT
 *                      - `compare_double` if the data type is DATA_TYPE_DOUBLE
 *                      - `compare_char` if the data type is DATA_TYPE_CHAR
 *                      - `compare_t` interface if the data type is DATA_TYPE_T,
 *                         otherwise a default `compare_default` is applied.
 * @return  Returns the pointer to cino-set, or `NULL` if creation failed.
 */
set_t *set_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    set_t *set = (set_t *)calloc(1, sizeof(set_t));
    return_value_if_fail(set != NULL, NULL);

    set->tree = tree_create(data_type, compare, destroy);
    call_and_return_value_if_fail(set->tree != NULL, free(set), NULL);

    set->size = 0;

    set->data_type = data_type;
    set->compare = compare ? compare : compare_default;
    set->destroy = destroy ? destroy : destroy_default;

    return set;
}

/**
 * @brief   Destroy cino-set.
 * @param set   cino-set
 */
void set_destroy(set_t *set) {
    return_if_fail(set != NULL);

    set_clear(set);
    tree_destroy(set->tree);

    set->compare = NULL;
    set->destroy = NULL;

    if (set) {
        free(set);
        set = NULL;
    }
}

/**
 * @brief   Determine if the cino-set is empty.
 * @param set   cino-set
 * @return  Returns `true` if the cino-set is empty, otherwise returns `false`.
 */
bool set_is_empty(const set_t *set) {
    return !set || set->size == 0;
}

/**
 * @brief   Get the number of elements in the cino-set.
 * @param set   cino-set
 * @return  Returns the number of elements in the cino-set.
 */
size_t set_size(const set_t *set) {
    return_value_if_fail(set != NULL, 0);
    return set->size;
}

/**
 * @brief   Clear all the elments in the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_clear(set_t *set) {
    return_value_if_fail(set != NULL, NULL);
    tree_clear(set->tree);
    set->size = 0;
    return set;
}

/**
 * @brief   Traverse cino-set.
 * @param set   cino-set
 * @param visit user-defined callback function for visiting a single element
 */
void set_foreach(set_t *set, visit_t visit) {
    return_if_fail(set != NULL && visit != NULL);
    tree_pre_order(set->tree, visit);
}

/**
 * @brief   Adds an element to the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_add(set_t *set, T data) {
    return_value_if_fail(set != NULL && data != NULL, set);
    tree_insert(set->tree, data);
    set->size = tree_size(set->tree);
    return set;
}

/**
 * @brief   Removes an element from the cino-set.
 * @param set   cino-set
 * @return  Returns the modified cino-set.
 */
set_t *set_remove(set_t *set, T data) {
    return_value_if_fail(set != NULL && data != NULL, set);
    tree_remove(set->tree, data);
    set->size = tree_size(set->tree);
    return set;
}

/**
 * @brief   Get the intersection of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the intersection cino-set, with all the element references.
 */
set_t *set_intersection(set_t *set1, set_t *set2) {
    return_value_if_fail(set1->data_type == set2->data_type, NULL);

    set_t *intersection_set = set_create(set1->data_type, set1->compare, NULL);

    array_t *array_set1 = tree_node_array_create(set1->tree);

    for (int i = 0; i < array_size(array_set1); i++) {
        T data = array_get(array_set1, i);
        if (tree_contains(set1->tree, data) && tree_contains(set2->tree, data)) {
            set_add(intersection_set, data);
        }
    }

    tree_node_array_destroy(array_set1);
    return intersection_set;
}

/**
 * @brief   Get the union of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the union cino-set, with all the element references.
 */
set_t *set_union(set_t *set1, set_t *set2) {
    return_value_if_fail(set1->data_type == set2->data_type, NULL);

    set_t *union_set = set_create(set1->data_type, set1->compare, NULL);

    array_t *array_set1 = tree_node_array_create(set1->tree);
    array_t *array_set2 = tree_node_array_create(set2->tree);

    for (int i = 0; i < array_size(array_set1); i++) {
        set_add(union_set, array_get(array_set1, i));
    }
    for (int i = 0; i < array_size(array_set2); i++) {
        set_add(union_set, array_get(array_set2, i));
    }

    tree_node_array_destroy(array_set1);
    tree_node_array_destroy(array_set2);

    return union_set;
}

/**
 * @brief   Get the difference of two cino-sets.
 * @param set1  cino-set
 * @param set2  cino-set
 * @return  Returns the the difference cino-set, with all the element references.
 */
set_t *set_difference(set_t *set1, set_t *set2) {
    return_value_if_fail(set1->data_type == set2->data_type, NULL);

    set_t *difference_set = set_create(set1->data_type, set1->compare, NULL);

    array_t *array_set1 = tree_node_array_create(set1->tree);
    array_t *array_set2 = tree_node_array_create(set2->tree);

    for (int i = 0; i < array_size(array_set1); i++) {
        set_add(difference_set, array_get(array_set1, i));
    }
    for (int i = 0; i < array_size(array_set2); i++) {
        set_remove(difference_set, array_get(array_set2, i));
    }

    tree_node_array_destroy(array_set1);
    tree_node_array_destroy(array_set2);

    return difference_set;
}