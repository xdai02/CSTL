#include "cstl/array.h"

#define DEFAULT_CAPACITY 16
#define SHRINK_FACTOR 2
#define GROWTH_FACTOR (3 / 2)

struct array_t {
    T *data;
    size_t size;
    size_t capacity;
    compare_t compare;
    destroy_t destroy;
};

/**
 * @brief Create an array_t object.
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created array_t object if successful, otherwise returns NULL.
 */
array_t *array_new(compare_t compare, destroy_t destroy) {
    array_t *array = (array_t *)malloc(sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);

    array->data = (T *)malloc(sizeof(T) * DEFAULT_CAPACITY);
    if (array->data == NULL) {
        free(array);
        return NULL;
    }

    array->size = 0;
    array->capacity = DEFAULT_CAPACITY;
    array->compare = compare;
    array->destroy = destroy;
    return array;
}

/**
 * @brief Destroy an array_t object.
 * @param array The array_t object.
 */
void array_delete(array_t *array) {
    return_if_fail(array != NULL);
    array_clear(array);
    free(array->data);
    free(array);
}

/**
 * @brief Determine whether an array_t object is empty.
 * @param array The array_t object.
 * @return Returns true if the array_t object is empty, otherwise returns false.
 */
bool array_is_empty(const array_t *array) {
    return_value_if_fail(array != NULL, true);
    return array->size == 0;
}

/**
 * @brief Get the size of an array_t object.
 * @param array The array_t object.
 * @return Returns the size of the array_t object.
 */
size_t array_size(const array_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

/**
 * @brief Traverse an array_t object.
 * @param array The array_t object.
 * @param visit Callback function for visiting a data item.
 */
void array_foreach(array_t *array, visit_t visit) {
    size_t i = 0;
    return_if_fail(array != NULL && visit != NULL);
    for (i = 0; i < array->size; i++) {
        visit(array->data[i]);
    }
}

/**
 * @brief Clear an array_t object.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_clear(array_t *array) {
    return_value_if_fail(array != NULL, NULL);

    array_foreach(array, array->destroy);

    array->data = (T *)realloc(array->data, sizeof(T) * DEFAULT_CAPACITY);
    array->size = 0;
    array->capacity = DEFAULT_CAPACITY;
    return array;
}

/**
 * @brief Get the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @return Returns the element at the specified index of the array_t object.
 */
T array_get(const array_t *array, size_t index) {
    return_value_if_fail(array != NULL, NULL);
    return_value_if_fail(index >= 0 && index < array->size, NULL);
    return array->data[index];
}

/**
 * @brief Set the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @param elem  The element.
 * @return Returns the modified array_t object.
 */
array_t *array_set(array_t *array, size_t index, T elem) {
    return_value_if_fail(array != NULL, NULL);
    return_value_if_fail(index >= 0 && index < array->size, array);
    return_value_if_fail(elem != NULL, array);
    if (array->destroy != NULL) {
        array->destroy(array->data[index]);
    }
    array->data[index] = elem;
    return array;
}

/**
 * @brief Swap two elements in an array_t object.
 * @param array The array_t object.
 * @param index1 The index of the first element.
 * @param index2 The index of the second element.
 * @return Returns the modified array_t object.
 */
array_t *array_swap(array_t *array, size_t index1, size_t index2) {
    return_value_if_fail(array != NULL, NULL);
    return_value_if_fail(index1 >= 0 && index1 < array->size, array);
    return_value_if_fail(index2 >= 0 && index2 < array->size, array);
    swap(array->data[index1], array->data[index2], T);
    return array;
}

/**
 * @brief Resize an array_t object.
 *        1. If the size of the array_t object is less than half of the capacity, the capacity is halved.
 *        2. If the size of the array_t object is greater than or equal to the capacity, the capacity is increased by 50%.
 * @param array The array_t object.
 * @return Returns true if memory reallocation is successful, otherwise returns false.
 */
static bool __array_resize(array_t *array) {
    size_t new_capacity;
    T *new_data = NULL;

    return_value_if_fail(array != NULL, false);

    if (array->size < array->capacity / SHRINK_FACTOR) {
        new_capacity = array->capacity / SHRINK_FACTOR + 1;
    } else if (array->size >= array->capacity) {
        new_capacity = array->capacity * GROWTH_FACTOR + 1;
    } else {
        return true;
    }

    new_data = (T *)realloc(array->data, sizeof(T) * new_capacity);
    return_value_if_fail(new_data != NULL, false);
    array->data = new_data;
    array->capacity = new_capacity;
    return true;
}

/**
 * @brief Append an element to the end of an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the modified array_t object.
 */
array_t *array_append(array_t *array, T elem) {
    return_value_if_fail(array != NULL && elem != NULL, array);
    return_value_if_fail(__array_resize(array), array);
    array->data[array->size] = elem;
    array->size++;
    return array;
}

/**
 * @brief Insert an element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @param elem The element.
 * @return Returns the modified array_t object.
 */
array_t *array_insert(array_t *array, size_t index, T elem) {
    size_t i = 0;

    return_value_if_fail(array != NULL, NULL);
    return_value_if_fail(index >= 0 && index <= array->size, array);
    return_value_if_fail(__array_resize(array), array);

    for (i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = elem;
    array->size++;

    return array;
}

/**
 * @brief Remove the element at the specified index of an array_t object.
 * @param array The array_t object.
 * @param index The index.
 * @return Returns the removed element.
 * @note Caller MUST free the returned element (if applicable).
 */
T array_remove(array_t *array, size_t index) {
    size_t i = 0;
    T elem = NULL;

    return_value_if_fail(array != NULL, NULL);
    return_value_if_fail(index >= 0 && index < array->size, array);

    elem = array->data[index];
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;

    return elem;
}

/**
 * @brief Get the index of the specified element in an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the index of the specified element in the array_t object.
 */
size_t array_index_of(const array_t *array, T elem) {
    size_t i = 0;

    return_value_if_fail(array != NULL && elem != NULL, -1);
    return_value_if_fail(array->compare != NULL, -1);

    for (i = 0; i < array->size; i++) {
        if (array->compare(array->data[i], elem) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Check if an array_t object contains the specified element.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns true if the array_t object contains the specified element, otherwise returns false.
 */
bool array_contains(const array_t *array, T elem) {
    return array_index_of(array, elem) != -1;
}

/**
 * @brief Count the number of occurrences of the specified element in an array_t object.
 * @param array The array_t object.
 * @param elem The element.
 * @return Returns the number of occurrences of the specified element in the array_t object.
 */
size_t array_count(const array_t *array, T elem) {
    size_t i = 0;
    size_t count = 0;

    return_value_if_fail(array != NULL && elem != NULL, 0);
    return_value_if_fail(array->compare != NULL, 0);

    for (i = 0; i < array->size; i++) {
        if (array->compare(array->data[i], elem) == 0) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Reverse an array_t object.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_reverse(array_t *array) {
    size_t i = 0;

    return_value_if_fail(array != NULL, array);

    for (i = 0; i < array->size / 2; i++) {
        swap(array->data[i], array->data[array->size - i - 1], T);
    }
    return array;
}

static compare_t __compare = NULL;

/**
 * @brief Private function for comparing elements.
 * @param a The first element.
 * @param b The second element.
 * @return Returns negative value if the first element is less than the second element.
 *         Returns 0 if the first element is equal to the second element.
 *         Returns positive value if the first element is greater than the second element.
 */
static int __T_compare(const T a, const T b) {
    exit_if_fail(a != NULL && b != NULL && __compare != NULL);
    return __compare(*(const T *)a, *(const T *)b);
}

/**
 * @brief Sort an array_t object in ascending order.
 * @param array The array_t object.
 * @return Returns the modified array_t object.
 */
array_t *array_sort(array_t *array) {
    return_value_if_fail(array != NULL, array);
    return_value_if_fail(array->compare != NULL, array);

    __compare = array->compare;
    qsort(array->data, array->size, sizeof(T), __T_compare);
    return array;
}

/**
 * @brief Create an iterator for an array_t object.
 * @param array The array_t object.
 * @return Returns the iterator for container.
 */
iterator_t *array_iterator_new(const array_t *array) {
    iterator_t *iterator = NULL;

    return_value_if_fail(array != NULL, NULL);

    iterator = (iterator_t *)malloc(sizeof(iterator_t));
    return_value_if_fail(iterator != NULL, NULL);

    iterator->container = (void *)array;
    iterator->current = 0;
    return iterator;
}

/**
 * @brief Destroy an iterator.
 * @param iterator The iterator_t object.
 */
void array_iterator_delete(iterator_t *iterator) {
    return_if_fail(iterator != NULL);
    free(iterator);
}

/**
 * @brief Determine whether an iterator has the next element.
 * @param iterator The iterator_t object.
 * @return Returns true if the iterator has the next element, otherwise returns false.
 */
bool array_iterator_has_next(const iterator_t *iterator) {
    array_t *array = NULL;

    return_value_if_fail(iterator != NULL, false);

    array = iterator->container;
    return (size_t)iterator->current < array->size;
}

/**
 * @brief Get the next element of an iterator.
 * @param iterator The iterator_t object.
 * @return Returns the next element of the iterator.
 */
T array_iterator_next(iterator_t *iterator) {
    array_t *array = NULL;
    T elem = NULL;

    return_value_if_fail(iterator != NULL, NULL);
    return_value_if_fail(array_iterator_has_next(iterator), NULL);

    array = iterator->container;
    elem = array->data[(size_t)iterator->current];
    iterator->current = (void *)((size_t)iterator->current + 1);
    return elem;
}
