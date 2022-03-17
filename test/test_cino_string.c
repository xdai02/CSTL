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
    assert(s3);
    assert(string_length(s3) == 0);
    string_destroy(s3);
}

void test_string_destroy() {
    string_t *s1 = string_create("Hello World");
    assert(s1);
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(s2);
    string_destroy(s2);

    string_t *s3 = string_create(NULL);
    assert(s3);
    string_destroy(s3);
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
    string_t *s = NULL;

    s = string_create("Hello World");
    assert(string_length(s) == strlen("Hello World"));

    string_set(s, "");
    assert(string_length(s) == 0);

    string_set(s, "A");
    assert(string_length(s) == 1);

    string_destroy(s);
}

void test_string_clear() {
    string_t *s = NULL;

    s = string_create("Hello World");
    string_clear(s);
    assert(string_length(s) == 0);

    string_set(s, "");
    string_clear(s);
    assert(string_length(s) == 0);

    string_set(s, "A");
    string_clear(s);
    assert(string_length(s) == 0);

    string_destroy(s);
}

void test_string_equal() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("Hello World");
    s2 = string_create("Hello World");
    assert(string_equal(s1, s2));

    string_set(s1, "hello world");
    string_set(s2, "Hello World");
    assert(!string_equal(s1, s2));

    string_set(s1, "hello");
    string_set(s2, "world");
    assert(!string_equal(s1, s2));

    string_destroy(s1);
    string_destroy(s2);
}

void test_string_equal_ignore_case() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("Hello World");
    s2 = string_create("Hello World");
    assert(string_equal_ignore_case(s1, s2));

    string_set(s1, "hello world");
    string_set(s2, "Hello World");
    assert(string_equal_ignore_case(s1, s2));

    string_set(s1, "hello");
    string_set(s2, "world");
    assert(!string_equal_ignore_case(s1, s2));

    string_destroy(s1);
    string_destroy(s2);
}

void test_string_to_lower() {
    string_t *s = NULL;

    s = string_create("Hello World");
    string_to_lower(s);
    assert(string_length(s) == strlen("hello world"));
    assert(strncmp(string_get(s), "hello world", strlen("hello world")) == 0);

    string_set(s, "hello world");
    s = string_to_lower(s);
    assert(string_length(s) == strlen("hello world"));
    assert(strncmp(string_get(s), "hello world", strlen("hello world")) == 0);

    string_set(s, "1234abcdABCD");
    s = string_to_lower(s);
    assert(string_length(s) == strlen("1234abcdabcd"));
    assert(strncmp(string_get(s), "1234abcdabcd", strlen("1234abcdabcd")) == 0);

    string_destroy(s);
}

void test_string_to_upper() {
    string_t *s = NULL;

    s = string_create("Hello World");
    s = string_to_upper(s);
    assert(string_length(s) == strlen("HELLO WORLD"));
    assert(strncmp(string_get(s), "HELLO WORLD", strlen("HELLO WORLD")) == 0);

    string_set(s, "HELLO WORLD");
    string_to_upper(s);
    assert(string_length(s) == strlen("HELLO WORLD"));
    assert(strncmp(string_get(s), "HELLO WORLD", strlen("HELLO WORLD")) == 0);

    string_set(s, "1234abcdABCD");
    string_to_upper(s);
    assert(string_length(s) == strlen("1234ABCDABCD"));
    assert(strncmp(string_get(s), "1234ABCDABCD", strlen("1234ABCDABCD")) == 0);

    string_destroy(s);
}

void test_string_starts_with() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("hell");
    assert(string_starts_with(s1, s2));

    string_set(s1, "Hello World!");
    string_set(s2, "Hello W");
    assert(string_starts_with(s1, s2));

    string_set(s1, "This is a test.");
    string_set(s2, "This is a test.");
    assert(string_starts_with(s1, s2));

    string_set(s1, "hello");
    string_set(s2, "HE");
    assert(!string_starts_with(s1, s2));

    string_set(s1, "123ABC");
    string_set(s2, "1");
    assert(string_starts_with(s1, s2));

    string_set(s1, "\n\t\0");
    string_set(s2, "\n");
    assert(string_starts_with(s1, s2));

    string_set(s1, NULL);
    string_set(s2, NULL);
    assert(string_starts_with(s1, s2));

    string_set(s1, NULL);
    string_set(s2, "\0");
    assert(string_starts_with(s1, s2));

    string_set(s1, "\0");
    string_set(s2, NULL);
    assert(string_starts_with(s1, s2));

    string_set(s1, "   ");
    string_set(s2, "\t");
    assert(!string_starts_with(s1, s2));

    string_set(s1, "  XYZ");
    string_set(s2, " ");
    assert(string_starts_with(s1, s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "Lorem ipsum dolor sit amet");
    assert(!string_starts_with(s1, s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "");
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

    string_set(s1, "Hello World!");
    string_set(s2, "rld!");
    assert(string_ends_with(s1, s2));

    string_set(s1, "This is a test.");
    string_set(s2, "This is a test.");
    assert(string_ends_with(s1, s2));

    string_set(s1, "hello");
    string_set(s2, "o");
    assert(string_ends_with(s1, s2));

    string_set(s1, "123ABC");
    string_set(s2, "BC");
    assert(string_ends_with(s1, s2));

    string_set(s1, "\n\t\0");
    string_set(s2, "\0");
    assert(string_ends_with(s1, s2));

    string_set(s1, NULL);
    string_set(s2, NULL);
    assert(string_ends_with(s1, s2));

    string_set(s1, NULL);
    string_set(s2, "\0");
    assert(string_ends_with(s1, s2));

    string_set(s1, "\0");
    string_set(s2, NULL);
    assert(string_ends_with(s1, s2));

    string_set(s1, "   ");
    string_set(s2, "\t");
    assert(!string_ends_with(s1, s2));

    string_set(s1, "XYZ  ");
    string_set(s2, "Z  ");
    assert(string_ends_with(s1, s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "Lorem ipsum dolor sit amet");
    assert(!string_ends_with(s1, s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "");
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
    assert(strncmp(string_get(s1), string_get(s2), string_length(s2)) == 0);
    assert(string_length(s1) == string_length(s2));

    string_set(s1, NULL);
    string_set(s2, "This is a test.");
    s1 = string_copy(s1, s2);
    assert(strncmp(string_get(s1), string_get(s2), string_length(s2)) == 0);
    assert(string_length(s1) == string_length(s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "test");
    s1 = string_copy(s1, s2);
    assert(strncmp(string_get(s1), string_get(s2), string_length(s2)) == 0);
    assert(string_length(s1) == string_length(s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, NULL);
    s1 = string_copy(s1, s2);
    assert(strncmp(string_get(s1), string_get(s2), string_length(s2)) == 0);
    assert(string_length(s1) == string_length(s2));

    string_destroy(s1);
    string_destroy(s2);
}

void test_string_concat() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("world");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "helloworld", string_length(s1)) == 0);
    assert(string_length(s1) == strlen("helloworld"));

    string_set(s1, "");
    string_set(s2, "This is a test.");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "This is a test.", string_length(s1)) == 0);
    assert(string_length(s1) == strlen("This is a test."));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "test");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "Lorem ipsumtest", string_length(s1)) == 0);
    assert(string_length(s1) == strlen("Lorem ipsumtest"));

    string_set(s1, NULL);
    string_set(s2, "test");
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "test", string_length(s1)) == 0);
    assert(string_length(s1) == strlen("test"));

    string_set(s1, "Lorem ipsum");
    string_set(s2, NULL);
    s1 = string_concat(s1, s2);
    assert(strncmp(string_get(s1), "Lorem ipsum", string_length(s1)) == 0);

    string_destroy(s1);
    string_destroy(s2);
}

void test_string_trim() {
    string_t *s = NULL;

    s = string_create("hello");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, "hello ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, " hello ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, "   hello        ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, "\nhello        ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, "\t  hello  \n   \t \n      ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "hello", string_length(s)) == 0);

    string_set(s, "        ");
    s = string_trim(s);
    assert(strncmp(string_get(s), "", string_length(s)) == 0);

    string_set(s, "\n\t\r\n\r\n\r\t");
    s = string_trim(s);
    assert(strncmp(string_get(s), "", string_length(s)) == 0);

    string_set(s, NULL);
    s = string_trim(s);
    assert(strncmp(string_get(s), "", string_length(s)) == 0);

    string_destroy(s);
}

void test_string_append_char() {
    string_t *s = NULL;

    s = string_create("hello");
    s = string_append_char(s, 'X');
    assert(strncmp(string_get(s), "helloX", string_length(s)) == 0);

    string_set(s, "");
    s = string_append_char(s, ' ');
    assert(strncmp(string_get(s), " ", string_length(s)) == 0);

    string_set(s, "Lorem ipsum");
    s = string_append_char(s, '\t');
    assert(strncmp(string_get(s), "Lorem ipsum\t", string_length(s)) == 0);

    string_set(s, NULL);
    s = string_append_char(s, '!');
    assert(strncmp(string_get(s), "!", string_length(s)) == 0);

    string_set(s, "Lorem ipsum");
    s = string_append_char(s, '.');
    assert(strncmp(string_get(s), "Lorem ipsum.", string_length(s)) == 0);

    string_destroy(s);
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

    string_set(s1, "Hello");
    string_set(s2, "World");
    s1 = string_insert_string(s1, string_length(s1), s2);
    assert(strncmp(string_get(s1), "HelloWorld", strlen(string_get(s1))) == 0);

    string_set(s1, "Hello");
    string_set(s2, "!");
    s1 = string_insert_string(s1, string_length(s1), s2);
    assert(strncmp(string_get(s1), "Hello!", strlen(string_get(s1))) == 0);

    string_set(s1, "Hello");
    string_set(s2, "He");
    s1 = string_insert_string(s1, 1, s2);
    assert(strncmp(string_get(s1), "HHeello", strlen(string_get(s1))) == 0);

    string_set(s1, "Hello");
    string_set(s2, "This is a test.");
    s1 = string_insert_string(s1, 2, s2);
    assert(strncmp(string_get(s1), "HeThis is a test.llo", strlen(string_get(s1))) == 0);

    string_set(s1, "Hello");
    string_set(s2, "\n\t");
    s1 = string_insert_string(s1, string_length(s1) - 1, s2);
    assert(strncmp(string_get(s1), "Hell\n\to", strlen(string_get(s1))) == 0);

    string_set(s1, "");
    string_set(s2, "A");
    s1 = string_insert_string(s1, 0, s2);
    assert(strncmp(string_get(s1), "A", strlen(string_get(s1))) == 0);

    string_set(s1, "Test");
    string_set(s2, "s");
    s1 = string_insert_string(s1, 5, s2);
    assert(strncmp(string_get(s1), "Test", strlen(string_get(s1))) == 0);

    string_set(s1, NULL);
    string_set(s2, "s");
    s1 = string_insert_string(s1, 0, s2);
    assert(strncmp(string_get(s1), "s", strlen(string_get(s1))) == 0);

    string_destroy(s1);
    string_destroy(s2);
}