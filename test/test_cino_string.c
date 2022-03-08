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

void test_cino_string_create_from_char() {
    cino_string_t *s1 = cino_string_create_from_char('A');
    assert(s1);
    assert(cino_string_length(s1) == strlen("A"));
    assert(strncmp(cino_string_get(s1), "A", strlen("A")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create_from_char('\0');
    assert(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);
}

void test_cino_string_create_from_int() {
    cino_string_t *s1 = cino_string_create_from_int(123);
    assert(s1);
    assert(cino_string_length(s1) == strlen("123"));
    assert(strncmp(cino_string_get(s1), "123", strlen("123")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create_from_int(2147483647);
    assert(s2);
    assert(cino_string_length(s2) == strlen("2147483647"));
    assert(strncmp(cino_string_get(s2), "2147483647", strlen("2147483647")) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create_from_int(-2147483648);
    assert(s3);
    assert(cino_string_length(s3) == strlen("-2147483648"));
    assert(strncmp(cino_string_get(s3), "-2147483648", strlen("-2147483648")) == 0);
    cino_string_destroy(s3);

    cino_string_t *s4 = cino_string_create_from_int(0);
    assert(s4);
    assert(cino_string_length(s4) == strlen("0"));
    assert(strncmp(cino_string_get(s4), "0", strlen("0")) == 0);
    cino_string_destroy(s4);

    cino_string_t *s5 = cino_string_create_from_int(3.14);
    assert(s5);
    assert(cino_string_length(s5) == strlen("3"));
    assert(strncmp(cino_string_get(s5), "3", strlen("3")) == 0);
    cino_string_destroy(s5);
}

void test_cino_string_create_from_double() {
    cino_string_t *s1 = cino_string_create_from_double(123, 1);
    assert(s1);
    assert(cino_string_length(s1) == strlen("123.0"));
    assert(strncmp(cino_string_get(s1), "123.0", strlen("123.0")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create_from_double(2147483647, 3);
    assert(s2);
    assert(cino_string_length(s2) == strlen("2147483647.000"));
    assert(strncmp(cino_string_get(s2), "2147483647.000", strlen("2147483647.000")) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create_from_double(-2147483648, 0);
    assert(s3);
    assert(cino_string_length(s3) == strlen("-2147483648"));
    assert(strncmp(cino_string_get(s3), "-2147483648", strlen("-2147483648")) == 0);
    cino_string_destroy(s3);

    cino_string_t *s4 = cino_string_create_from_double(-2.7172, 2);
    assert(s4);
    assert(cino_string_length(s4) == strlen("-2.72"));
    assert(strncmp(cino_string_get(s4), "-2.72", strlen("-2.72")) == 0);
    cino_string_destroy(s4);

    cino_string_t *s5 = cino_string_create_from_double(3.14, 2);
    assert(s5);
    assert(cino_string_length(s5) == strlen("3.14"));
    assert(strncmp(cino_string_get(s5), "3.14", strlen("3.14")) == 0);
    cino_string_destroy(s5);
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
    assert(strncmp(cino_string_get(s1), "Hello World", strlen("Hello World")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    assert(strncmp(cino_string_get(s3), "A", strlen("A")) == 0);
    cino_string_destroy(s3);
}

void test_cino_string_set() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(cino_string_length(s1) == strlen("Hello World"));
    s1 = cino_string_set(s1, "World Hello");
    assert(cino_string_length(s1) == strlen("World Hello"));
    assert(strncmp(cino_string_get(s1), "World Hello", strlen("World Hello")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(cino_string_length(s2) == 0);
    s2 = cino_string_set(s2, "World Hello");
    assert(cino_string_length(s2) == strlen("World Hello"));
    assert(strncmp(cino_string_get(s2), "World Hello", strlen("World Hello")) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("This is a test. Hello World!");
    assert(cino_string_length(s3) == strlen("This is a test. Hello World!"));
    s3 = cino_string_set(s3, "test");
    assert(cino_string_length(s3) == strlen("test"));
    assert(strncmp(cino_string_get(s3), "test", strlen("test")) == 0);
    cino_string_destroy(s3);
}

void test_cino_string_length() {
    cino_string_t *s1 = cino_string_create("Hello World");
    assert(cino_string_length(s1) == strlen("Hello World"));
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    assert(cino_string_length(s3) == strlen("A"));
    cino_string_destroy(s3);
}

void test_cino_string_clear() {
    cino_string_t *s1 = cino_string_create("Hello World");
    cino_string_clear(s1);
    assert(cino_string_length(s1) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("");
    cino_string_clear(s2);
    assert(cino_string_length(s2) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("A");
    cino_string_clear(s3);
    assert(cino_string_length(s3) == 0);
    cino_string_destroy(s3);
}

void test_cino_string_equal() {
    cino_string_t *s1 = cino_string_create("Hello World");
    cino_string_t *s2 = cino_string_create("Hello World");
    assert(cino_string_equal(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("hello world");
    cino_string_t *s4 = cino_string_create("Hello World");
    assert(!cino_string_equal(s3, s4));
    cino_string_destroy(s3);
    cino_string_destroy(s4);

    cino_string_t *s5 = cino_string_create("hello");
    cino_string_t *s6 = cino_string_create("world");
    assert(!cino_string_equal(s5, s6));
    cino_string_destroy(s5);
    cino_string_destroy(s6);
}

void test_cino_string_equal_ignore_case() {
    cino_string_t *s1 = cino_string_create("Hello World");
    cino_string_t *s2 = cino_string_create("Hello World");
    assert(cino_string_equal_ignore_case(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("hello world");
    cino_string_t *s4 = cino_string_create("Hello World");
    assert(cino_string_equal_ignore_case(s3, s4));
    cino_string_destroy(s3);
    cino_string_destroy(s4);

    cino_string_t *s5 = cino_string_create("hello");
    cino_string_t *s6 = cino_string_create("world");
    assert(!cino_string_equal_ignore_case(s5, s6));
    cino_string_destroy(s5);
    cino_string_destroy(s6);
}

void test_cino_string_tolower() {
    cino_string_t *s1 = cino_string_create("Hello World");
    cino_string_tolower(s1);
    assert(cino_string_length(s1) == strlen("hello world"));
    assert(strncmp(cino_string_get(s1), "hello world", strlen("hello world")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("hello world");
    s2 = cino_string_tolower(s2);
    assert(cino_string_length(s2) == strlen("hello world"));
    assert(strncmp(cino_string_get(s2), "hello world", strlen("hello world")) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("1234abcdABCD");
    s3 = cino_string_tolower(s3);
    assert(cino_string_length(s3) == strlen("1234abcdabcd"));
    assert(strncmp(cino_string_get(s3), "1234abcdabcd", strlen("1234abcdabcd")) == 0);
    cino_string_destroy(s3);
}

void test_cino_string_toupper() {
    cino_string_t *s1 = cino_string_create("Hello World");
    s1 = cino_string_toupper(s1);
    assert(cino_string_length(s1) == strlen("HELLO WORLD"));
    assert(strncmp(cino_string_get(s1), "HELLO WORLD", strlen("HELLO WORLD")) == 0);
    cino_string_destroy(s1);

    cino_string_t *s2 = cino_string_create("HELLO WORLD");
    cino_string_toupper(s2);
    assert(cino_string_length(s2) == strlen("HELLO WORLD"));
    assert(strncmp(cino_string_get(s2), "HELLO WORLD", strlen("HELLO WORLD")) == 0);
    cino_string_destroy(s2);

    cino_string_t *s3 = cino_string_create("1234abcdABCD");
    cino_string_toupper(s3);
    assert(cino_string_length(s3) == strlen("1234ABCDABCD"));
    assert(strncmp(cino_string_get(s3), "1234ABCDABCD", strlen("1234ABCDABCD")) == 0);
    cino_string_destroy(s3);
}