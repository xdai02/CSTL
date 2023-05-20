#include "cstl/heap.h"
#include "cstl/array.h"

struct heap_t {
    heap_type_t heap_type;
    array_t *array;
    compare_t compare;
};

/**
 * @brief Create a heap_t object.
 * @param heap_type The type of the heap (MIN_HEAP/MAX_HEAP).
 * @param compare Callback function for comparing two data items.
 * @param destroy Callback function for destroying a data item.
 * @return Returns the created heap_t object if successful, otherwise returns NULL.
 */
heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy) {
    heap_t *heap = NULL;

    return_value_if_fail(heap_type == MIN_HEAP || heap_type == MAX_HEAP, NULL);
    return_value_if_fail(compare != NULL, NULL);

    heap = (heap_t *)malloc(sizeof(heap_t));
    return_value_if_fail(heap != NULL, NULL);

    heap->array = array_new(compare, destroy);
    if (heap->array == NULL) {
        free(heap);
        return NULL;
    }

    heap->heap_type = heap_type;
    heap->compare = compare;
    return heap;
}

/**
 * @brief Destroy a heap_t object.
 * @param heap The heap_t object.
 */
void heap_delete(heap_t *heap) {
    return_if_fail(heap != NULL);
    array_delete(heap->array);
    free(heap);
}

/**
 * @brief Determine whether a heap_t object is empty.
 * @param heap The heap_t object.
 * @return Returns true if the heap_t object is empty, otherwise returns false.
 */
bool heap_is_empty(const heap_t *heap) {
    return_value_if_fail(heap != NULL, true);
    return array_is_empty(heap->array);
}

/**
 * @brief Get the size of a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the size of the heap_t object.
 */
size_t heap_size(const heap_t *heap) {
    return_value_if_fail(heap != NULL, 0);
    return array_size(heap->array);
}

/**
 * @brief Clear a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the modified heap_t object.
 */
heap_t *heap_clear(heap_t *heap) {
    return_value_if_fail(heap != NULL, NULL);
    array_clear(heap->array);
    return heap;
}

/**
 * @brief Heapify up.
 * @param heap The heap_t object.
 * @param index The index.
 * @return Returns the modified heap_t object.
 */
static heap_t *__heapify_up(heap_t *heap, size_t index) {
    size_t parent_index;
    T current;
    T parent;
    int cmp;
    bool should_swap = false;

    return_value_if_fail(heap != NULL, NULL);

    while (index != 0) {
        parent_index = (index - 1) / 2;
        current = array_get(heap->array, index);
        parent = array_get(heap->array, parent_index);

        cmp = heap->compare(current, parent);
        if (heap->heap_type == MIN_HEAP) {
            should_swap = cmp < 0;
        } else {
            should_swap = cmp > 0;
        }

        if (should_swap) {
            array_swap(heap->array, index, parent_index);
            index = parent_index;
        } else {
            break;
        }
    }

    return heap;
}

/**
 * @brief Heapify down.
 * @param heap The heap_t object.
 * @param index The index.
 * @return Returns the modified heap_t object.
 */
static heap_t *__heapify_down(heap_t *heap, size_t index) {
    size_t left_child_index;
    size_t right_child_index;
    size_t chosen_index;
    T current;
    T left_child;
    T right_child;

    return_value_if_fail(heap != NULL, NULL);

    while (true) {
        left_child_index = index * 2 + 1;
        right_child_index = index * 2 + 2;
        chosen_index = index;

        current = array_get(heap->array, index);
        left_child = array_get(heap->array, left_child_index);
        right_child = array_get(heap->array, right_child_index);

        if (left_child_index < array_size(heap->array)) {
            if (heap->heap_type == MIN_HEAP) {
                if (heap->compare(left_child, current) < 0) {
                    chosen_index = left_child_index;
                }
            } else {
                if (heap->compare(left_child, current) > 0) {
                    chosen_index = left_child_index;
                }
            }
        }

        if (right_child_index < array_size(heap->array)) {
            if (heap->heap_type == MIN_HEAP) {
                if (heap->compare(right_child, array_get(heap->array, chosen_index)) < 0) {
                    chosen_index = right_child_index;
                }
            } else {
                if (heap->compare(right_child, array_get(heap->array, chosen_index)) > 0) {
                    chosen_index = right_child_index;
                }
            }
        }

        if (chosen_index == index) {
            break;
        }

        array_swap(heap->array, index, chosen_index);
        index = chosen_index;
    }

    return heap;
}

/**
 * @brief Push an element into a heap_t object.
 * @param heap The heap_t object.
 * @param elem The element.
 * @return Returns the modified heap_t object.
 */
heap_t *heap_push(heap_t *heap, T elem) {
    return_value_if_fail(heap != NULL, NULL);
    return_value_if_fail(elem != NULL, heap);
    array_append(heap->array, elem);
    __heapify_up(heap, array_size(heap->array) - 1);
    return heap;
}

/**
 * @brief Pop an element from a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the popped element.
 * @note Caller MUST free the returned element (if applicable).
 */
T heap_pop(heap_t *heap) {
    T root = NULL;

    return_value_if_fail(heap != NULL && !heap_is_empty(heap), NULL);

    array_swap(heap->array, 0, array_size(heap->array) - 1);
    root = array_remove(heap->array, array_size(heap->array) - 1);

    if (!heap_is_empty(heap)) {
        __heapify_down(heap, 0);
    }

    return root;
}

/**
 * @brief Peek the root element of a heap_t object.
 * @param heap The heap_t object.
 * @return Returns the root element.
 */
T heap_peek(const heap_t *heap) {
    return_value_if_fail(heap != NULL && !heap_is_empty(heap), NULL);
    return array_get(heap->array, 0);
}
