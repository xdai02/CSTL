#include "coop_array.h"
#include "coop_utils.h"

struct array_t {
    T *data;
    size_t size;
    size_t capacity;
    compare_t compare;
    destroy_t destroy;
};

array_t *array_create(compare_t compare, destroy_t destroy) {
    const int INITIAL_CAPACITY = 16;
    array_t *array = NULL;

    return_value_if_fail(compare != NULL && destroy != NULL, NULL);

    array = (array_t *)malloc(sizeof(array_t));
    return_value_if_fail(array != NULL, NULL);

    array->data = (T *)malloc(sizeof(T) * INITIAL_CAPACITY);
    if (array->data == NULL) {
        free(array);
        return NULL;
    }

    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    array->compare = compare;
    array->destroy = destroy;

    return array;
}

void array_destroy(array_t *array) {
    return_if_fail(array != NULL);
    array_clear(array);
    free(array->data);
    free(array);
}

void array_foreach(array_t *array, visit_t visit) {
    size_t i = 0;
    return_if_fail(array != NULL && visit != NULL);
    for (i = 0; i < array->size; i++) {
        visit(array->data[i]);
    }
}

bool array_is_empty(const array_t *array) {
    return_value_if_fail(array != NULL, true);
    return array->size == 0;
}

size_t array_size(const array_t *array) {
    return_value_if_fail(array != NULL, 0);
    return array->size;
}

array_t *array_clear(array_t *array) {
    const int INITIAL_CAPACITY = 16;

    return_value_if_fail(array != NULL, NULL);

    array_foreach(array, array->destroy);

    array->data = (T *)realloc(array->data, sizeof(T) * INITIAL_CAPACITY);
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    return array;
}

T array_get(const array_t *array, size_t index) {
    return_value_if_fail(array != NULL && index >= 0 && index < array->size, NULL);
    return array->data[index];
}

array_t *array_set(array_t *array, size_t index, T elem) {
    return_if_fail(array != NULL && index >= 0 && index < array->size);
    array->destroy(array->data[index]);
    array->data[index] = elem;
}

static bool __array_resize(array_t *array) {
    size_t new_capacity;

    return_value_if_fail(array != NULL, false);

    if (array->size < array->capacity / 2) {
        new_capacity = array->capacity / 2 + 1;
    } else if (array->size >= array->capacity) {
        new_capacity = array->capacity * 3 / 2 + 1;
    } else {
        return true;
    }

    array->data = (T *)realloc(array->data, sizeof(T) * new_capacity);
    return_value_if_fail(array->data != NULL, false);
    array->capacity = new_capacity;
    return true;
}

array_t *array_append(array_t *array, T elem) {
    return_value_if_fail(array != NULL && elem != NULL, array);
    return_value_if_fail(__array_resize(array), array);
    array->data[array->size] = elem;
    array->size++;
    return array;
}

array_t *array_insert(array_t *array, size_t index, T elem) {
    size_t i = 0;

    return_value_if_fail(array != NULL && index >= 0 && index <= array->size, array);
    return_value_if_fail(__array_resize(array), array);

    for (i = array->size; i > index; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = elem;
    array->size++;

    return array;
}

T array_remove(array_t *array, size_t index) {
    size_t i = 0;

    return_value_if_fail(array != NULL && index >= 0 && index < array->size, array);

    T elem = array->data[index];
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;

    return elem;
}

size_t array_index_of(const array_t *array, T elem) {
    size_t i = 0;

    return_value_if_fail(array != NULL && elem != NULL, -1);

    for (i = 0; i < array->size; i++) {
        if (array->compare(array->data[i], elem) == 0) {
            return i;
        }
    }

    return -1;
}

bool array_contains(const array_t *array, T elem) {
    return array_index_of(array, elem) != -1;
}

size_t array_count(const array_t *array, T elem) {
    size_t i = 0;
    size_t count = 0;

    return_value_if_fail(array != NULL && elem != NULL, 0);

    for (i = 0; i < array->size; i++) {
        if (array->compare(array->data[i], elem) == 0) {
            count++;
        }
    }

    return count;
}

array_t *array_reverse(array_t *array) {
    size_t i = 0;

    return_value_if_fail(array != NULL, array);

    for (i = 0; i < array->size / 2; i++) {
        swap(array->data[i], array->data[array->size - i - 1], T);
    }

    return array;
}

static compare_t compare;

static int __compare(const T a, const T b) {
    return compare(*(T *)a, *(T *)b);
}

array_t *array_sort(array_t *array) {
    return_value_if_fail(array != NULL, array);
    compare = array->compare;
    qsort(array->data, array->size, sizeof(T), __compare);
    return array;
}
