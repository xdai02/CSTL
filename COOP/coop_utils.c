#include "coop_utils.h"

void *malloc_s(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "%s(): Not enough space.\n", __func__);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *calloc_s(size_t count, size_t size) {
    void *ptr = calloc(count, size);
    if (ptr == NULL) {
        fprintf(stderr, "%s(): Not enough space.\n", __func__);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *realloc_s(void *ptr, size_t new_size) {
    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL) {
        fprintf(stderr, "%s(): Not enough space.\n", __func__);
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}