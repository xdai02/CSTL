#include "test_cino_array.h"

void test_array_create() {
    array_t *arr = array_create(sizeof(int));
    assert(arr);
    int num = 1;
    array_append(arr, &num);
    int result = *(int *)array_get(arr, 0);
    assert(result == 1);
    array_destroy(arr);
}