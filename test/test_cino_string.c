#include "test_cino_string.h"

void test_string_create() {
    string_t *s1 = string_create("Hello World");
    assert(s1);
    assert(string_length(s1) == strlen("Hello World"));
    assert(strncmp(string_get(s1), "Hello World", strlen("Hello World")) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(s2);
    assert(string_length(s2) == 0);
    string_destroy(s2);

    string_t *s3 = string_create(NULL);
    assert(!s3);
}

void test_string_destroy() {
    string_t *s1 = string_create("Hello World");
    assert(s1);
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(s2);
    string_destroy(s2);

    string_t *s3 = string_create(NULL);
    assert(!s3);
}

void test_string_get() {
    string_t *s1 = string_create("Hello World");
    assert(strncmp(string_get(s1), "Hello World", strlen("Hello World")) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(string_length(s2) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("A");
    assert(strncmp(string_get(s3), "A", strlen("A")) == 0);
    string_destroy(s3);
}

void test_string_set() {
    string_t *s1 = string_create("Hello World");
    assert(string_length(s1) == strlen("Hello World"));
    s1 = string_set(s1, "World Hello");
    assert(string_length(s1) == strlen("World Hello"));
    assert(strncmp(string_get(s1), "World Hello", strlen("World Hello")) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(string_length(s2) == 0);
    s2 = string_set(s2, "World Hello");
    assert(string_length(s2) == strlen("World Hello"));
    assert(strncmp(string_get(s2), "World Hello", strlen("World Hello")) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("This is a test. Hello World!");
    assert(string_length(s3) == strlen("This is a test. Hello World!"));
    s3 = string_set(s3, "test");
    assert(string_length(s3) == strlen("test"));
    assert(strncmp(string_get(s3), "test", strlen("test")) == 0);
    string_destroy(s3);
}

void test_string_length() {
    string_t *s1 = string_create("Hello World");
    assert(string_length(s1) == strlen("Hello World"));
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(string_length(s2) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("A");
    assert(string_length(s3) == strlen("A"));
    string_destroy(s3);
}

void test_string_clear() {
    string_t *s1 = string_create("Hello World");
    string_clear(s1);
    assert(string_length(s1) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("");
    string_clear(s2);
    assert(string_length(s2) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("A");
    string_clear(s3);
    assert(string_length(s3) == 0);
    string_destroy(s3);
}

void test_string_equal() {
    string_t *s1 = string_create("Hello World");
    string_t *s2 = string_create("Hello World");
    assert(string_equal(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    string_t *s3 = string_create("hello world");
    string_t *s4 = string_create("Hello World");
    assert(!string_equal(s3, s4));
    string_destroy(s3);
    string_destroy(s4);

    string_t *s5 = string_create("hello");
    string_t *s6 = string_create("world");
    assert(!string_equal(s5, s6));
    string_destroy(s5);
    string_destroy(s6);
}

void test_string_equal_ignore_case() {
    string_t *s1 = string_create("Hello World");
    string_t *s2 = string_create("Hello World");
    assert(string_equal_ignore_case(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    string_t *s3 = string_create("hello world");
    string_t *s4 = string_create("Hello World");
    assert(string_equal_ignore_case(s3, s4));
    string_destroy(s3);
    string_destroy(s4);

    string_t *s5 = string_create("hello");
    string_t *s6 = string_create("world");
    assert(!string_equal_ignore_case(s5, s6));
    string_destroy(s5);
    string_destroy(s6);
}

void test_string_to_lower() {
    string_t *s1 = string_create("Hello World");
    string_to_lower(s1);
    assert(string_length(s1) == strlen("hello world"));
    assert(strncmp(string_get(s1), "hello world", strlen("hello world")) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("hello world");
    s2 = string_to_lower(s2);
    assert(string_length(s2) == strlen("hello world"));
    assert(strncmp(string_get(s2), "hello world", strlen("hello world")) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("1234abcdABCD");
    s3 = string_to_lower(s3);
    assert(string_length(s3) == strlen("1234abcdabcd"));
    assert(strncmp(string_get(s3), "1234abcdabcd", strlen("1234abcdabcd")) == 0);
    string_destroy(s3);
}

void test_string_to_upper() {
    string_t *s1 = string_create("Hello World");
    s1 = string_to_upper(s1);
    assert(string_length(s1) == strlen("HELLO WORLD"));
    assert(strncmp(string_get(s1), "HELLO WORLD", strlen("HELLO WORLD")) == 0);
    string_destroy(s1);

    string_t *s2 = string_create("HELLO WORLD");
    string_to_upper(s2);
    assert(string_length(s2) == strlen("HELLO WORLD"));
    assert(strncmp(string_get(s2), "HELLO WORLD", strlen("HELLO WORLD")) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("1234abcdABCD");
    string_to_upper(s3);
    assert(string_length(s3) == strlen("1234ABCDABCD"));
    assert(strncmp(string_get(s3), "1234ABCDABCD", strlen("1234ABCDABCD")) == 0);
    string_destroy(s3);
}

void test_string_starts_with() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("hell");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello World!");
    s2 = string_create("Hello W");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("This is a test.");
    s2 = string_create("This is a test.");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("hello");
    s2 = string_create("HE");
    assert(!string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("123ABC");
    s2 = string_create("1");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("\n\t\0");
    s2 = string_create("\n");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create(NULL);
    s2 = string_create(NULL);
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create(NULL);
    s2 = string_create("\0");
    assert(!string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("\0");
    s2 = string_create(NULL);
    assert(!string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("   ");
    s2 = string_create("\t");
    assert(!string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("  XYZ");
    s2 = string_create(" ");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("Lorem ipsum dolor sit amet");
    assert(!string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("");
    assert(string_starts_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);
}

void test_string_ends_with() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("ello");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello World!");
    s2 = string_create("rld!");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("This is a test.");
    s2 = string_create("This is a test.");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("hello");
    s2 = string_create("o");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("123ABC");
    s2 = string_create("BC");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("\n\t\0");
    s2 = string_create("\0");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create(NULL);
    s2 = string_create(NULL);
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create(NULL);
    s2 = string_create("\0");
    assert(!string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("\0");
    s2 = string_create(NULL);
    assert(!string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("   ");
    s2 = string_create("\t");
    assert(!string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("   ");
    s2 = string_create("\t");
    assert(!string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("XYZ  ");
    s2 = string_create("Z  ");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("Lorem ipsum dolor sit amet");
    assert(!string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("");
    assert(string_ends_with(s1, s2));
    string_destroy(s1);
    string_destroy(s2);
}

void test_string_copy() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("world");
    s1 = string_copy(s1, s2);
    assert(strncmp(string_get(s1), string_get(s2), strlen(string_get(s2))) == 0);
    assert(string_length(s1) == strlen("world"));
    string_destroy(s1);
    string_destroy(s2);

    s1 = NULL;
    s2 = string_create("This is a test.");
    s1 = string_copy(s1, s2);
    assert(!s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("test");
    s1 = string_copy(s1, s2);
    assert(strncmp(string_get(s1), string_get(s2), strlen(string_get(s2))) == 0);
    assert(string_length(s1) == strlen("test"));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = NULL;
    s1 = string_copy(s1, s2);
    assert(string_length(s1) == 0);
    string_destroy(s1);
}

void test_string_concat() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("world");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "helloworld", strlen(string_get(s1))) == 0);
    assert(string_length(s1) == strlen("helloworld"));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("");
    s2 = string_create("This is a test.");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "This is a test.", strlen(string_get(s1))) == 0);
    assert(string_length(s1) == strlen("This is a test."));
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = string_create("test");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "Lorem ipsumtest", strlen(string_get(s1))) == 0);
    assert(string_length(s1) == strlen("Lorem ipsumtest"));
    string_destroy(s1);
    string_destroy(s2);

    s1 = NULL;
    s2 = string_create("test");
    s1 = string_concat(s1, s2);
    assert(!s1);
    string_destroy(s2);

    s1 = string_create("Lorem ipsum");
    s2 = NULL;
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "Lorem ipsum", strlen(string_get(s1))) == 0);
    string_destroy(s1);
}

void test_string_insert_char() {
    string_t *s = NULL;

    s = string_create("ello");
    s = string_insert_char(s, 0, 'H');
    assert(strncmp(string_get(s), "Hello", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, string_length(s), 'o');
    assert(strncmp(string_get(s), "Helloo", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 3, 'l');
    assert(strncmp(string_get(s), "Helllo", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 1, '\n');
    assert(strncmp(string_get(s), "H\nello", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 0, '\0');
    assert(strncmp(string_get(s), "", strlen(string_get(s))) == 0);
    assert(string_length(s) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, string_length(s) - 1, '\0');
    assert(strncmp(string_get(s), "Hell", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("");
    s = string_insert_char(s, 0, 'A');
    assert(strncmp(string_get(s), "A", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = string_create("Test");
    s = string_insert_char(s, 5, 's');
    assert(strncmp(string_get(s), "Test", strlen(string_get(s))) == 0);
    string_destroy(s);

    s = NULL;
    s = string_insert_char(s, 0, 's');
    assert(!s);
}

void test_string_insert_string() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("World");
    s2 = string_create("Hello");
    s1 = string_insert_string(s1, 0, s2);
    assert(strncmp(string_get(s1), "HelloWorld", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello");
    s2 = string_create("World");
    s1 = string_insert_string(s1, string_length(s1), s2);
    assert(strncmp(string_get(s1), "HelloWorld", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello");
    s2 = string_create("!");
    s1 = string_insert_string(s1, string_length(s1), s2);
    assert(strncmp(string_get(s1), "Hello!", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello");
    s2 = string_create("He");
    s1 = string_insert_string(s1, 1, s2);
    assert(strncmp(string_get(s1), "HHeello", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello");
    s2 = string_create("This is a test.");
    s1 = string_insert_string(s1, 2, s2);
    assert(strncmp(string_get(s1), "HeThis is a test.llo", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Hello");
    s2 = string_create("\n\t");
    s1 = string_insert_string(s1, string_length(s1) - 1, s2);
    assert(strncmp(string_get(s1), "Hell\n\to", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("");
    s2 = string_create("A");
    s1 = string_insert_string(s1, 0, s2);
    assert(strncmp(string_get(s1), "A", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = string_create("Test");
    s2 = string_create("s");
    s1 = string_insert_string(s1, 5, s2);
    assert(strncmp(string_get(s1), "Test", strlen(string_get(s1))) == 0);
    string_destroy(s1);
    string_destroy(s2);

    s1 = NULL;
    s2 = string_create("s");
    s1 = string_insert_string(s1, 0, s2);
    assert(!s1);
    string_destroy(s2);
}