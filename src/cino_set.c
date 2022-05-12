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
 * @param compare   User-defined callback function for comparison, only for T (generic)
 *                  cino-set. Set to `NULL` if it is a primitive cino-set.
 * @param destroy   User-defined callback function for destroying, only for T (generic)
 *                  cino-set. Set to `NULL` if it is a primitive cino-set.
 * @return  Returns the pointer to cino-set, or `NULL` if creation failed.
 */
set_t *set_create(data_type_t data_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(is_valid_cino_data_type(data_type), NULL);

    set_t *set = (set_t *)calloc(1, sizeof(set_t));
    return_value_if_fail(set != NULL, NULL);

    set->tree = tree_create(data_type, compare, destroy);
    call_and_return_value_if_fail(set->tree != NULL, free(set), NULL);

    set->size = 0;

    if (data_type == DATA_TYPE_INT) {
        set->data_type = DATA_TYPE_INT;
        set->compare = compare_int;
        set->destroy = destroy_int;
    } else if (data_type == DATA_TYPE_DOUBLE) {
        set->data_type = DATA_TYPE_DOUBLE;
        set->compare = compare_double;
        set->destroy = destroy_double;
    } else if (data_type == DATA_TYPE_CHAR) {
        set->data_type = DATA_TYPE_CHAR;
        set->compare = compare_char;
        set->destroy = destroy_char;
    } else if (data_type == DATA_TYPE_T) {
        set->data_type = DATA_TYPE_T;
        set->compare = compare ? compare : compare_T;
        set->destroy = destroy ? destroy : destroy_T;
    }

    return set;
}

/**
 * @brief   Destroy cino-set.
 * @param set   cino-set
 */
void set_destroy(set_t *set) {
    return_if_fail(set != NULL);

    set_clear(set);

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

set_t *set_intersection(set_t *set1, set_t *set2) {
    return_value_if_fail(set1->data_type == set2->data_type, NULL);

    set_t *intersection = set_create(set1->data_type, set1->compare, NULL);

    return intersection;
}

// 交集
// 并集
// 差集
// 补集