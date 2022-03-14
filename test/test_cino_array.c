#include "test_cino_array.h"

void test_cino_array_create() {
    cino_array_t *arr = cino_array_create(sizeof(int));
    assert(arr);
    cino_array_append(arr, 1);
    free(arr);
}