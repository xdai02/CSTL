#include "test_cino_string.h"

void test_cino_string_create() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(s1);
    assert(cino_string_length(s1) == strlen("Hello World"));
    assert(strncmp(cino_string_get(s1), "Hello World", strlen("Hello World")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create(NULL);
    assert(!s3);
}

void test_cino_string_destroy() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(s1);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(s2);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create(NULL);
    assert(!s3);
}

void test_cino_string_get() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(s1);
    assert(strncmp(cino_string_get(s1), "Hello World", strlen("Hello World")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    assert(s3);
    assert(strncmp(cino_string_get(s3), "A", strlen("A")) == 0);
    cino_string_destroy(s3);
}

void test_cino_string_length() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(s1);
    assert(cino_string_length(s1) == strlen("Hello World"));
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    assert(s3);
    assert(cino_string_length(s3) == strlen("A"));
    cino_string_destroy(s3);
}

void test_cino_string_clear() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(s1);
    cino_string_clear(s1);
    assert(cino_string_length(s1) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(s2);
    cino_string_clear(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    assert(s3);
    cino_string_clear(s3);
    assert(cino_string_length(s3) == 0);
    cino_string_destroy(s3);
}