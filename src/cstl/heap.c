#include "cstl/heap.h"
#include "cstl/array.h"

struct heap_t {
    heap_type_t heap_type;
    array_t *array;
    compare_t compare;
};

heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy) {
    return_value_if_fail(heap_type == MIN_HEAP || heap_type == MAX_HEAP, NULL);
    return_value_if_fail(compare != NULL, NULL);

    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
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

void heap_delete(heap_t *heap) {
    return_if_fail(heap != NULL);
    array_delete(heap->array);
    free(heap);
}

bool heap_is_empty(const heap_t *heap) {
    return_value_if_fail(heap != NULL, true);
    return array_is_empty(heap->array);
}

size_t heap_size(const heap_t *heap) {
    return_value_if_fail(heap != NULL, 0);
    return array_size(heap->array);
}

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
            array_set(heap->array, index, parent);
            array_set(heap->array, parent_index, current);
            index = parent_index;
        } else {
            break;
        }
    }

    return heap;
}

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

        array_set(heap->array, index, array_get(heap->array, chosen_index));
        array_set(heap->array, chosen_index, current);
        index = chosen_index;
    }

    return heap;
}

heap_t *heap_push(heap_t *heap, T elem) {
    return_value_if_fail(heap != NULL, NULL);
    return_value_if_fail(elem != NULL, heap);
    array_append(heap->array, elem);
    __heapify_up(heap, array_size(heap->array) - 1);
    return heap;
}

T heap_pop(heap_t *heap) {
    T root = NULL;
    T last = NULL;

    return_value_if_fail(heap != NULL && !heap_is_empty(heap), NULL);

    root = array_get(heap->array, 0);
    last = array_remove(heap->array, array_size(heap->array) - 1);

    if (!heap_is_empty(heap)) {
        array_set(heap->array, 0, last);
        __heapify_down(heap, 0);
    }

    return root;
}

T heap_peek(const heap_t *heap) {
    return_value_if_fail(heap != NULL && !heap_is_empty(heap), NULL);
    return array_get(heap->array, 0);
}
