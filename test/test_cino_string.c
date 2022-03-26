#include "test_cino_string.h"

void test_string_create() {
    string_t *s1 = string_create("Hello World");
    assert(s1);
    assert(string_length(s1) == strlen("Hello World"));
    assert(str_equal(string_get(s1), "Hello World"));
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
    assert(str_equal(string_get(s1), "Hello World"));
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(string_length(s2) == 0);
    string_destroy(s2);

    string_t *s3 = string_create("A");
    assert(str_equal(string_get(s3), "A"));
    string_destroy(s3);
}

void test_string_set() {
    string_t *s1 = string_create("Hello World");
    assert(string_length(s1) == strlen("Hello World"));
    s1 = string_set(s1, "World Hello");
    assert(string_length(s1) == strlen("World Hello"));
    assert(str_equal(string_get(s1), "World Hello"));
    string_destroy(s1);

    string_t *s2 = string_create("");
    assert(string_length(s2) == 0);
    s2 = string_set(s2, "World Hello");
    assert(string_length(s2) == strlen("World Hello"));
    assert(str_equal(string_get(s2), "World Hello"));
    string_destroy(s2);
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
    assert(str_equal(string_get(s), "hello world"));

    string_set(s, "hello world");
    s = string_to_lower(s);
    assert(string_length(s) == strlen("hello world"));
    assert(str_equal(string_get(s), "hello world"));

    string_set(s, "1234abcdABCD");
    s = string_to_lower(s);
    assert(string_length(s) == strlen("1234abcdabcd"));
    assert(str_equal(string_get(s), "1234abcdabcd"));

    string_destroy(s);
}

void test_string_to_upper() {
    string_t *s = NULL;

    s = string_create("Hello World");
    s = string_to_upper(s);
    assert(string_length(s) == strlen("HELLO WORLD"));
    assert(str_equal(string_get(s), "HELLO WORLD"));

    string_set(s, "HELLO WORLD");
    string_to_upper(s);
    assert(string_length(s) == strlen("HELLO WORLD"));
    assert(str_equal(string_get(s), "HELLO WORLD"));

    string_set(s, "1234abcdABCD");
    string_to_upper(s);
    assert(string_length(s) == strlen("1234ABCDABCD"));
    assert(str_equal(string_get(s), "1234ABCDABCD"));

    string_destroy(s);
}

void test_string_starts_with() {
    string_t *s = NULL;

    s = string_create("hello");
    assert(string_starts_with(s, "hell"));

    string_set(s, "Hello World!");
    assert(string_starts_with(s, "Hello W"));

    string_set(s, "This is a test.");
    assert(string_starts_with(s, "This is a test."));

    string_set(s, "hello");
    assert(!string_starts_with(s, "HE"));

    string_set(s, "123ABC");
    assert(string_starts_with(s, "1"));

    string_set(s, "\n\t\0");
    assert(string_starts_with(s, "\n"));

    string_set(s, NULL);
    assert(!string_starts_with(s, NULL));

    string_set(s, NULL);
    assert(string_starts_with(s, "\0"));

    string_set(s, "\0");
    assert(!string_starts_with(s, NULL));

    string_set(s, "   ");
    assert(!string_starts_with(s, "\t"));

    string_set(s, "  XYZ");
    assert(string_starts_with(s, " "));

    string_set(s, "Lorem ipsum");
    assert(!string_starts_with(s, "Lorem ipsum dolor sit amet"));

    string_set(s, "Lorem ipsum");
    assert(string_starts_with(s, ""));

    string_destroy(s);
}

void test_string_ends_with() {
    string_t *s = NULL;

    s = string_create("hello");
    assert(string_ends_with(s, "ello"));

    string_set(s, "Hello World!");
    assert(string_ends_with(s, "rld!"));

    string_set(s, "This is a test.");
    assert(string_ends_with(s, "This is a test."));

    string_set(s, "hello");
    assert(string_ends_with(s, "o"));

    string_set(s, "123ABC");
    assert(string_ends_with(s, "BC"));

    string_set(s, "\n\t\0");
    assert(string_ends_with(s, "\0"));

    string_set(s, NULL);
    assert(!string_ends_with(s, NULL));

    string_set(s, NULL);
    assert(string_ends_with(s, "\0"));

    string_set(s, "\0");
    assert(!string_ends_with(s, NULL));

    string_set(s, "   ");
    assert(!string_ends_with(s, "\t"));

    string_set(s, "XYZ  ");
    assert(string_ends_with(s, "Z  "));

    string_set(s, "Lorem ipsum");
    assert(!string_ends_with(s, "Lorem ipsum dolor sit amet"));

    string_set(s, "Lorem ipsum");
    assert(string_ends_with(s, ""));

    string_destroy(s);
}

void test_string_copy() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_create("hello");
    s2 = string_create("world");
    s1 = string_copy(s1, s2);
    assert(str_equal(string_get(s1), string_get(s2)));
    assert(string_length(s1) == string_length(s2));

    string_set(s1, NULL);
    string_set(s2, "This is a test.");
    s1 = string_copy(s1, s2);
    assert(str_equal(string_get(s1), string_get(s2)));
    assert(string_length(s1) == string_length(s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "test");
    s1 = string_copy(s1, s2);
    assert(str_equal(string_get(s1), string_get(s2)));
    assert(string_length(s1) == string_length(s2));

    string_set(s1, "Lorem ipsum");
    string_set(s2, NULL);
    s1 = string_copy(s1, s2);
    assert(str_equal(string_get(s1), string_get(s2)));
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
    assert(str_equal(string_get(s1), "helloworld"));
    assert(string_length(s1) == strlen("helloworld"));

    string_set(s1, "");
    string_set(s2, "This is a test.");
    s1 = string_concat(s1, s2);
    assert(str_equal(string_get(s1), "This is a test."));
    assert(string_length(s1) == strlen("This is a test."));

    string_set(s1, "Lorem ipsum");
    string_set(s2, "test");
    s1 = string_concat(s1, s2);
    assert(str_equal(string_get(s1), "Lorem ipsumtest"));
    assert(string_length(s1) == strlen("Lorem ipsumtest"));

    string_set(s1, NULL);
    string_set(s2, "test");
    s1 = string_concat(s1, s2);
    assert(str_equal(string_get(s1), "test"));
    assert(string_length(s1) == strlen("test"));

    string_set(s1, "Lorem ipsum");
    string_set(s2, NULL);
    s1 = string_concat(s1, s2);
    assert(str_equal(string_get(s1), "Lorem ipsum"));

    string_destroy(s1);
    string_destroy(s2);
}

void test_string_trim() {
    string_t *s = NULL;

    s = string_create("hello");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, "hello ");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, " hello ");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, "   hello        ");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, "\nhello        ");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, "\t  hello  \n   \t \n      ");
    s = string_trim(s);
    assert(str_equal(string_get(s), "hello"));

    string_set(s, "        ");
    s = string_trim(s);
    assert(str_equal(string_get(s), ""));

    string_set(s, "\n\t\r\n\r\n\r\t");
    s = string_trim(s);
    assert(str_equal(string_get(s), ""));

    string_set(s, NULL);
    s = string_trim(s);
    assert(str_equal(string_get(s), ""));

    string_destroy(s);
}

void test_string_append_char() {
    string_t *s = NULL;

    s = string_create("hello");
    s = string_append_char(s, 'X');
    assert(str_equal(string_get(s), "helloX"));

    string_set(s, "");
    s = string_append_char(s, ' ');
    assert(str_equal(string_get(s), " "));

    string_set(s, "Lorem ipsum");
    s = string_append_char(s, '\t');
    assert(str_equal(string_get(s), "Lorem ipsum\t"));

    string_set(s, NULL);
    s = string_append_char(s, '!');
    assert(str_equal(string_get(s), "!"));

    string_set(s, "Lorem ipsum");
    s = string_append_char(s, '.');
    assert(str_equal(string_get(s), "Lorem ipsum."));

    string_destroy(s);
}

void test_string_insert_char() {
    string_t *s = NULL;

    s = string_create("ello");
    s = string_insert_char(s, 0, 'H');
    assert(str_equal(string_get(s), "Hello"));
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, string_length(s), 'o');
    assert(str_equal(string_get(s), "Helloo"));
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 3, 'l');
    assert(str_equal(string_get(s), "Helllo"));
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 1, '\n');
    assert(str_equal(string_get(s), "H\nello"));
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, 0, '\0');
    assert(str_equal(string_get(s), ""));
    assert(string_length(s) == 0);
    string_destroy(s);

    s = string_create("Hello");
    s = string_insert_char(s, string_length(s) - 1, '\0');
    assert(str_equal(string_get(s), "Hell"));
    string_destroy(s);

    s = string_create("");
    s = string_insert_char(s, 0, 'A');
    assert(str_equal(string_get(s), "A"));
    string_destroy(s);

    s = string_create("Test");
    s = string_insert_char(s, 5, 's');
    assert(str_equal(string_get(s), "Test"));
    string_destroy(s);

    s = NULL;
    s = string_insert_char(s, 0, 's');
    assert(!s);
}

void test_string_insert_string() {
    string_t *s = NULL;

    s = string_create("World");
    s = string_insert_string(s, 0, "Hello");
    assert(str_equal(string_get(s), "HelloWorld"));

    string_set(s, "Hello");
    s = string_insert_string(s, string_length(s), "World");
    assert(str_equal(string_get(s), "HelloWorld"));

    string_set(s, "Hello");
    s = string_insert_string(s, string_length(s), "!");
    assert(str_equal(string_get(s), "Hello!"));

    string_set(s, "Hello");
    s = string_insert_string(s, 1, "He");
    assert(str_equal(string_get(s), "HHeello"));

    string_set(s, "Hello");
    s = string_insert_string(s, 2, "This is a test.");
    assert(str_equal(string_get(s), "HeThis is a test.llo"));

    string_set(s, "Hello");
    s = string_insert_string(s, string_length(s) - 1, "\n\t");
    assert(str_equal(string_get(s), "Hell\n\to"));

    string_set(s, "");
    s = string_insert_string(s, 0, "A");
    assert(str_equal(string_get(s), "A"));

    string_set(s, "Test");
    s = string_insert_string(s, 5, "s");
    assert(str_equal(string_get(s), "Test"));

    string_set(s, NULL);
    s = string_insert_string(s, 0, "s");
    assert(str_equal(string_get(s), "s"));

    string_destroy(s);
}

void test_string_count_substring() {
    string_t *s = NULL;

    s = string_create("hello");
    assert(string_count_substring(s, "hel") == 1);

    string_set(s, "hello");
    assert(string_count_substring(s, "hel") == 1);

    string_set(s, "hello");
    assert(string_count_substring(s, "hello") == 1);

    string_set(s, "hello");
    assert(string_count_substring(s, "l") == 2);

    string_set(s, "hello World!");
    assert(string_count_substring(s, "l") == 3);

    string_set(s, "This is a test.");
    assert(string_count_substring(s, "is") == 2);

    string_set(s, "This is a test.");
    assert(string_count_substring(s, "hello") == 0);

    string_set(s, "This is a test.");
    assert(string_count_substring(s, "") == 0);

    string_set(s, "");
    assert(string_count_substring(s, "hello") == 0);

    string_set(s, "");
    assert(string_count_substring(s, "") == 1);

    string_set(s, NULL);
    assert(string_count_substring(s, NULL) == 0);

    string_set(s, "goooooood");
    assert(string_count_substring(s, "o") == 7);

    string_set(s, "goooooood");
    assert(string_count_substring(s, "oo") == 3);

    string_set(s, "goooooood");
    assert(string_count_substring(s, "ooo") == 2);

    string_set(s, "goooooood");
    assert(string_count_substring(s, "oooo") == 1);

    string_destroy(s);
}

void test_string_replace_char() {
    string_t *s = NULL;

    s = string_create("Hello World!");
    s = string_replace_char(s, 'l', 'L');
    assert(str_equal(string_get(s), "HeLLo WorLd!"));

    string_set(s, "Hello World!");
    s = string_replace_char(s, 'e', 'a');
    assert(str_equal(string_get(s), "Hallo World!"));

    string_set(s, "Hello World!");
    s = string_replace_char(s, ' ', '#');
    assert(str_equal(string_get(s), "Hello#World!"));

    string_set(s, "Hello World!");
    s = string_replace_char(s, 'X', ' ');
    assert(str_equal(string_get(s), "Hello World!"));

    string_set(s, "Hello World!");
    s = string_replace_char(s, 'l', '\0');
    assert(str_equal(string_get(s), "He"));
    assert(string_length(s) == strlen("He"));

    string_set(s, NULL);
    s = string_replace_char(s, 'a', 'b');
    assert(str_equal(string_get(s), ""));
    assert(string_length(s) == 0);

    string_destroy(s);
}

void test_string_replace() {
    string_t *s = NULL;

    s = string_create("This is a test.");
    s = string_replace(s, "is", "IS");
    assert(str_equal(string_get(s), "ThIS IS a test."));

    string_set(s, "This is a test.");
    s = string_replace(s, "a", "A");
    assert(str_equal(string_get(s), "This is A test."));

    string_set(s, "foobar foobar foobar");
    s = string_replace(s, "foobar", "func");
    assert(str_equal(string_get(s), "func func func"));

    string_set(s, "CCCCCCCCCCCCCCC");
    s = string_replace(s, "C", "U");
    assert(str_equal(string_get(s), "UUUUUUUUUUUUUUU"));
    string_set(s, "CCCCCCCCCCCCCCC");
    s = string_replace(s, "A", "I");
    assert(str_equal(string_get(s), "CCCCCCCCCCCCCCC"));

    string_set(s, "foobar foobar foobar");
    s = string_replace(s, "foobar", "");
    assert(str_equal(string_get(s), "  "));

    string_set(s, "foobarfoobaoobar");
    s = string_replace(s, "foobar", "Replace");
    assert(str_equal(string_get(s), "Replacefoobaoobar"));

    string_set(s, "");
    s = string_replace(s, "foobar", "Replace");
    assert(str_equal(string_get(s), ""));

    string_set(s, "This is a test");
    s = string_replace(s, "is", "THISIS");
    assert(str_equal(string_get(s), "ThTHISIS THISIS a test"));

    string_destroy(s);
}

void test_string_remove() {
    string_t *s = NULL;

    s = string_create("Hello World");
    s = string_remove(s, "llo");
    assert(str_equal(string_get(s), "He World"));

    string_set(s, "Hello World");
    s = string_remove(s, " ");
    assert(str_equal(string_get(s), "HelloWorld"));

    string_set(s, "Hello World");
    s = string_remove(s, "Hello");
    assert(str_equal(string_get(s), " World"));

    string_set(s, "Hello World");
    s = string_remove(s, "World");
    assert(str_equal(string_get(s), "Hello "));

    string_set(s, "Hello World");
    s = string_remove(s, "Hello World");
    assert(str_equal(string_get(s), ""));

    string_set(s, "This is a test");
    s = string_remove(s, "is");
    assert(str_equal(string_get(s), "Th  a test"));

    string_set(s, "This is a test");
    s = string_remove(s, "hello");
    assert(str_equal(string_get(s), "This is a test"));

    string_destroy(s);
}