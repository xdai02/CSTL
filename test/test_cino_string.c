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

void test_cino_string_starts_with() {
    cino_string_t *s1 = NULL;
    cino_string_t *s2 = NULL;

    s1 = cino_string_create("hello");
    s2 = cino_string_create("hell");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Hello World!");
    s2 = cino_string_create("Hello W");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("This is a test.");
    s2 = cino_string_create("This is a test.");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("hello");
    s2 = cino_string_create("HE");
    assert(!cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("123ABC");
    s2 = cino_string_create("1");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("\n\t\0");
    s2 = cino_string_create("\n");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create(NULL);
    s2 = cino_string_create(NULL);
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create(NULL);
    s2 = cino_string_create("\0");
    assert(!cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("\0");
    s2 = cino_string_create(NULL);
    assert(!cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("   ");
    s2 = cino_string_create("\t");
    assert(!cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("  XYZ");
    s2 = cino_string_create(" ");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("Lorem ipsum dolor sit amet");
    assert(!cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("");
    assert(cino_string_starts_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);
}

void test_cino_string_ends_with() {
    cino_string_t *s1 = NULL;
    cino_string_t *s2 = NULL;

    s1 = cino_string_create("hello");
    s2 = cino_string_create("ello");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Hello World!");
    s2 = cino_string_create("rld!");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("This is a test.");
    s2 = cino_string_create("This is a test.");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("hello");
    s2 = cino_string_create("o");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("123ABC");
    s2 = cino_string_create("BC");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("\n\t\0");
    s2 = cino_string_create("\0");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create(NULL);
    s2 = cino_string_create(NULL);
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create(NULL);
    s2 = cino_string_create("\0");
    assert(!cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("\0");
    s2 = cino_string_create(NULL);
    assert(!cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("   ");
    s2 = cino_string_create("\t");
    assert(!cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("   ");
    s2 = cino_string_create("\t");
    assert(!cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("XYZ  ");
    s2 = cino_string_create("Z  ");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("Lorem ipsum dolor sit amet");
    assert(!cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("");
    assert(cino_string_ends_with(s1, s2));
    cino_string_destroy(s1);
    cino_string_destroy(s2);
}

void test_cino_string_copy() {
    cino_string_t *s1 = NULL;
    cino_string_t *s2 = NULL;

    s1 = cino_string_create("hello");
    s2 = cino_string_create("world");
    s1 = cino_string_copy(s1, s2);
    assert(strncmp(cino_string_get(s1), cino_string_get(s2), strlen(cino_string_get(s2))) == 0);
    assert(cino_string_length(s1) == strlen("world"));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = NULL;
    s2 = cino_string_create("This is a test.");
    s1 = cino_string_copy(s1, s2);
    assert(!s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("test");
    s1 = cino_string_copy(s1, s2);
    assert(strncmp(cino_string_get(s1), cino_string_get(s2), strlen(cino_string_get(s2))) == 0);
    assert(cino_string_length(s1) == strlen("test"));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = NULL;
    s1 = cino_string_copy(s1, s2);
    assert(cino_string_length(s1) == 0);
    cino_string_destroy(s1);
}

void test_cino_string_concat() {
    cino_string_t *s1 = NULL;
    cino_string_t *s2 = NULL;

    s1 = cino_string_create("hello");
    s2 = cino_string_create("world");
    s1 = cino_string_concat(s1, s2);
    assert(strncmp(cino_string_get(s1), "helloworld", strlen("helloworld")) == 0);
    assert(cino_string_length(s1) == strlen("helloworld"));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("");
    s2 = cino_string_create("This is a test.");
    s1 = cino_string_concat(s1, s2);
    assert(strncmp(cino_string_get(s1), "This is a test.", strlen("This is a test.")) == 0);
    assert(cino_string_length(s1) == strlen("This is a test."));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = cino_string_create("test");
    s1 = cino_string_concat(s1, s2);
    assert(strncmp(cino_string_get(s1), "Lorem ipsumtest", strlen("Lorem ipsumtest")) == 0);
    assert(cino_string_length(s1) == strlen("Lorem ipsumtest"));
    cino_string_destroy(s1);
    cino_string_destroy(s2);

    s1 = NULL;
    s2 = cino_string_create("test");
    s1 = cino_string_concat(s1, s2);
    assert(!s1);
    cino_string_destroy(s2);

    s1 = cino_string_create("Lorem ipsum");
    s2 = NULL;
    s1 = cino_string_concat(s1, s2);
    assert(strncmp(cino_string_get(s1), "Lorem ipsum", strlen("Lorem ipsum")) == 0);
    cino_string_destroy(s1);
}