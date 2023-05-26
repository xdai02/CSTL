#include "test_str.h"
#include "cstl.h"
#include <assert.h>

void test_string_new() {
    string_t *string = NULL;

    string = string_new("Hello World");
    assert(string != NULL);
    assert(string_length(string) == 11);
    assert(string_is_empty(string) == false);
    string_delete(string);

    string = string_new("");
    assert(string != NULL);
    assert(string_length(string) == 0);
    assert(string_is_empty(string) == true);
    string_delete(string);
}

void test_string_delete() {
    string_t *string = string_new("Hello World");
    assert(string != NULL);
    string_delete(string);
}

void test_string_clone() {
    string_t *s1 = string_new("Hello World");
    string_t *s2 = string_clone(s1);

    assert(s1 != NULL);
    assert(s2 != NULL);

    assert(string_length(s1) == string_length(s2));
    assert(string_is_empty(s1) == string_is_empty(s2));
    assert(string_equal(s1, s2) == true);

    string_delete(s1);
    string_delete(s2);
}

void test_string_length() {
    string_t *string = NULL;

    string = string_new("Hello World");
    assert(string_length(string) == 11);
    string_delete(string);

    string = string_new("");
    assert(string_length(string) == 0);
    string_delete(string);
}

void test_string_is_empty() {
    string_t *string = NULL;

    string = string_new("Hello World");
    assert(string_is_empty(string) == false);
    string_delete(string);

    string = string_new("");
    assert(string_is_empty(string) == true);
    string_delete(string);
}

void test_string_get() {
    string_t *string = NULL;

    string = string_new("Hello World");
    assert(strcmp(string_get(string), "Hello World") == 0);
    string_delete(string);

    string = string_new("");
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);
}

void test_string_char_at() {
    string_t *string = string_new("Hello");
    assert(string_char_at(string, 0) == 'H');
    assert(string_char_at(string, 1) == 'e');
    assert(string_char_at(string, 2) == 'l');
    assert(string_char_at(string, 3) == 'l');
    assert(string_char_at(string, 4) == 'o');
    string_delete(string);
}

void test_string_set_char_at() {
    string_t *string = string_new("Hello");
    string_set_char_at(string, 0, 'h');
    assert(string_char_at(string, 0) == 'h');
    assert(string_char_at(string, 1) == 'e');
    assert(string_char_at(string, 2) == 'l');
    assert(string_char_at(string, 3) == 'l');
    assert(string_char_at(string, 4) == 'o');

    string_set_char_at(string, 4, '!');
    assert(string_char_at(string, 0) == 'h');
    assert(string_char_at(string, 1) == 'e');
    assert(string_char_at(string, 2) == 'l');
    assert(string_char_at(string, 3) == 'l');
    assert(string_char_at(string, 4) == '!');

    string_delete(string);
}

void test_string_clear() {
    string_t *string = string_new("Hello");
    assert(string_length(string) == 5);
    assert(string_is_empty(string) == false);
    string_clear(string);
    assert(string_length(string) == 0);
    assert(string_is_empty(string) == true);
    string_delete(string);
}

void test_string_equal() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_new("Hello World");
    s2 = string_new("Hello World");
    assert(string_equal(s1, s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("Hello World");
    s2 = string_new("HELLO WORLD");
    assert(string_equal(s1, s2) == false);
    string_delete(s1);
    string_delete(s2);
}

void test_string_equal_ignore_case() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_new("Hello World");
    s2 = string_new("Hello World");
    assert(string_equal_ignore_case(s1, s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("Hello World");
    s2 = string_new("HELLO WORLD");
    assert(string_equal_ignore_case(s1, s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("Hello World");
    s2 = string_new("hello world!");
    assert(string_equal_ignore_case(s1, s2) == false);
    string_delete(s1);
    string_delete(s2);
}

void test_string_compare() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_new("Hello World");
    s2 = string_new("Hello World");
    assert(string_compare(s1, s2) == 0);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("Hello World");
    s2 = string_new("HELLO WORLD");
    assert(string_compare(s1, s2) > 0);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("Hello World");
    s2 = string_new("hello world!");
    assert(string_compare(s1, s2) < 0);
    string_delete(s1);
    string_delete(s2);
}

void test_string_tolower() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_new("HELLO");
    s2 = string_new("hello");
    assert(string_equal(string_tolower(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("");
    s2 = string_new("");
    assert(string_equal(string_tolower(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("HeLLo, W0rLd! 123");
    s2 = string_new("hello, w0rld! 123");
    assert(string_equal(string_tolower(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("@!$%^&*()");
    s2 = string_new("@!$%^&*()");
    assert(string_equal(string_tolower(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);
}

void test_string_toupper() {
    string_t *s1 = NULL;
    string_t *s2 = NULL;

    s1 = string_new("hello");
    s2 = string_new("HELLO");
    assert(string_equal(string_toupper(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("");
    s2 = string_new("");
    assert(string_equal(string_toupper(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("HeLLo, W0rLd! 123");
    s2 = string_new("HELLO, W0RLD! 123");
    assert(string_equal(string_toupper(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);

    s1 = string_new("@!$%^&*()");
    s2 = string_new("@!$%^&*()");
    assert(string_equal(string_toupper(s1), s2) == true);
    string_delete(s1);
    string_delete(s2);
}

void test_string_starts_with() {
    string_t *string = NULL;

    string = string_new("hello, world!");
    assert(string_starts_with(string, "hello") == true);
    string_delete(string);

    string = string_new("hello, world!");
    assert(string_starts_with(string, "world") == false);
    string_delete(string);

    string = string_new("hello, world!");
    assert(string_starts_with(string, "") == true);
    string_delete(string);

    string = string_new("");
    assert(string_starts_with(string, "hello") == false);
    string_delete(string);

    string = string_new("");
    assert(string_starts_with(string, "") == true);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_starts_with(string, "Hello, world!") == true);
    string_delete(string);
}

void test_string_ends_with() {
    string_t *string = NULL;

    string = string_new("hello, world!");
    assert(string_ends_with(string, "world!") == true);
    string_delete(string);

    string = string_new("hello, world!");
    assert(string_ends_with(string, "hello") == false);
    string_delete(string);

    string = string_new("hello, world!");
    assert(string_ends_with(string, "") == true);
    string_delete(string);

    string = string_new("");
    assert(string_ends_with(string, "world!") == false);
    string_delete(string);

    string = string_new("");
    assert(string_ends_with(string, "") == true);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_ends_with(string, "Hello, world!") == true);
    string_delete(string);
}

void test_string_index_of_char() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    assert(string_index_of_char(string, 'H') == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_index_of_char(string, ',') == 5);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_index_of_char(string, '!') == 12);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_index_of_char(string, 'z') == -1);
    string_delete(string);

    string = string_new("");
    assert(string_index_of_char(string, 'a') == -1);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_index_of_char(string, 'a') == 0);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_index_of_char(string, 'f') == 5);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_index_of_char(string, 'z') == -1);
    string_delete(string);
}

void test_string_index_of_string() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    assert(string_index_of_string(string, "world") == 7);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_index_of_string(string, "abc") == -1);
    string_delete(string);

    string = string_new("");
    assert(string_index_of_string(string, "Hello, world!") == -1);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_index_of_string(string, "") == -1);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_index_of_string(string, "xyz") == -1);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_index_of_string(string, "Hello, world!") == 0);
    string_delete(string);
}

void test_string_contains_string() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "world") == true);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "abc") == false);
    string_delete(string);

    string = string_new("");
    assert(string_contains_string(string, "Hello, world!") == false);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_contains_string(string, "") == false);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_contains_string(string, "xyz") == false);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "Hello, world!") == true);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "hello") == false);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "world!") == true);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_contains_string(string, "Hello, world!") == true);
    string_delete(string);
}

void test_string_reverse() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_reverse(string);
    assert(strcmp(string_get(string), "!dlrow ,olleH") == 0);
    string_delete(string);

    string = string_new("");
    string_reverse(string);
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);

    string = string_new("abcdef");
    string_reverse(string);
    assert(strcmp(string_get(string), "fedcba") == 0);
    string_delete(string);
}

void test_string_strip() {
    string_t *string = NULL;

    string = string_new("  Hello, world!  ");
    string_strip(string);
    assert(strcmp(string_get(string), "Hello, world!") == 0);
    string_delete(string);

    string = string_new("");
    string_strip(string);
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);

    string = string_new("abcdef");
    string_strip(string);
    assert(strcmp(string_get(string), "abcdef") == 0);
    string_delete(string);

    string = string_new("   ");
    string_strip(string);
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);

    string = string_new("\n\t\t\t\nHello, world!\n\t\t\t\n");
    string_strip(string);
    assert(strcmp(string_get(string), "Hello, world!") == 0);
    string_delete(string);

    string = string_new("\n\n\n\n   \t\t\t\n ");
    string_strip(string);
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);
}

void test_string_substring() {
    string_t *string = NULL;
    char *substring = NULL;

    string = string_new("Hello, world!");
    substring = string_substring(string, 0, 5);
    assert(strcmp(substring, "Hello") == 0);
    string_delete(string);
    free(substring);

    string = string_new("Hello, world!");
    substring = string_substring(string, 7, 12);
    assert(strcmp(substring, "world") == 0);
    string_delete(string);
    free(substring);

    string = string_new("abcdef");
    substring = string_substring(string, 2, 5);
    assert(strcmp(substring, "cde") == 0);
    string_delete(string);
    free(substring);

    string = string_new("");
    substring = string_substring(string, 0, 0);
    assert(substring == NULL);
    string_delete(string);
}

void test_string_count_substring() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    assert(string_count_substring(string, "world") == 1);
    string_delete(string);

    string = string_new("Hello, world!");
    assert(string_count_substring(string, "abc") == 0);
    string_delete(string);

    string = string_new("");
    assert(string_count_substring(string, "Hello, world!") == 0);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_count_substring(string, "") == 0);
    string_delete(string);

    string = string_new("abcdef");
    assert(string_count_substring(string, "xyz") == 0);
    string_delete(string);

    string = string_new("Hello Hello Hello World!");
    assert(string_count_substring(string, "Hello") == 3);
    string_delete(string);

    string = string_new("Hello World Hello World!");
    assert(string_count_substring(string, "World") == 2);
    string_delete(string);
}

void test_string_append_char() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_append_char(string, '!');
    assert(strcmp(string_get(string), "Hello, world!!") == 0);
    string_delete(string);

    string = string_new("");
    string_append_char(string, 'A');
    assert(strcmp(string_get(string), "A") == 0);
    string_delete(string);

    string = string_new("abc");
    string_append_char(string, 'd');
    assert(strcmp(string_get(string), "abcd") == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    string_append_char(string, '\0');
    assert(strcmp(string_get(string), "Hello, world!") == 0);
    string_delete(string);
}

void test_string_insert_char() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_insert_char(string, 0, 'A');
    assert(strcmp(string_get(string), "AHello, world!") == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    string_insert_char(string, 13, '!');
    assert(strcmp(string_get(string), "Hello, world!!") == 0);
    string_delete(string);

    string = string_new("abc");
    string_insert_char(string, 1, 'X');
    assert(strcmp(string_get(string), "aXbc") == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    string_insert_char(string, 5, '\0');
    assert(strcmp(string_get(string), "Hello") == 0);
    string_delete(string);
}

void test_string_concat() {
    string_t *string = NULL;

    string = string_new("Hello, ");
    string_concat(string, "world!");
    assert(strcmp(string_get(string), "Hello, world!") == 0);
    string_delete(string);

    string = string_new("");
    string_concat(string, "Hello, world!");
    assert(strcmp(string_get(string), "Hello, world!") == 0);
    string_delete(string);

    string = string_new("Hello, ");
    string_concat(string, "");
    assert(strcmp(string_get(string), "Hello, ") == 0);
    string_delete(string);

    string = string_new("");
    string_concat(string, "");
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);
}

void test_string_insert_string() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_insert_string(string, 0, "A");
    assert(strcmp(string_get(string), "AHello, world!") == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    string_insert_string(string, 13, "!!");
    assert(strcmp(string_get(string), "Hello, world!!!") == 0);
    string_delete(string);

    string = string_new("abc");
    string_insert_string(string, 1, "XYZ");
    assert(strcmp(string_get(string), "aXYZbc") == 0);
    string_delete(string);
}

void test_string_remove_char() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_remove_char(string, 'o');
    assert(strcmp(string_get(string), "Hell, wrld!") == 0);
    string_delete(string);

    string = string_new("aaaaaa");
    string_remove_char(string, 'a');
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);

    string = string_new("abc");
    string_remove_char(string, 'd');
    assert(strcmp(string_get(string), "abc") == 0);
    string_delete(string);
}

void test_string_remove_string() {
    string_t *string = NULL;

    string = string_new("Hello, world! world!");
    string_remove_string(string, "world");
    assert(strcmp(string_get(string), "Hello, ! !") == 0);
    string_delete(string);

    string = string_new("aaaaaa");
    string_remove_string(string, "aa");
    assert(strcmp(string_get(string), "") == 0);
    string_delete(string);

    string = string_new("abc");
    string_remove_string(string, "d");
    assert(strcmp(string_get(string), "abc") == 0);
    string_delete(string);

    string = string_new("aaaaaaa");
    string_remove_string(string, "aa");
    assert(strcmp(string_get(string), "a") == 0);
    string_delete(string);
}

void test_string_replace_char() {
    string_t *string = NULL;

    string = string_new("Hello, world!");
    string_replace_char(string, 'o', 'X');
    assert(strcmp(string_get(string), "HellX, wXrld!") == 0);
    string_delete(string);

    string = string_new("aaaaaa");
    string_replace_char(string, 'a', 'b');
    assert(strcmp(string_get(string), "bbbbbb") == 0);
    string_delete(string);

    string = string_new("abc");
    string_replace_char(string, 'd', 'X');
    assert(strcmp(string_get(string), "abc") == 0);
    string_delete(string);

    string = string_new("Hello, world!");
    string_replace_char(string, 'o', '\0');
    assert(strcmp(string_get(string), "Hell") == 0);
    string_delete(string);
}

void test_string_replace_string() {
    string_t *string = NULL;

    string = string_new("Hello, world! world!");
    string_replace_string(string, "world", "Earth");
    assert(strcmp(string_get(string), "Hello, Earth! Earth!") == 0);
    string_delete(string);

    string = string_new("aaaaaa");
    string_replace_string(string, "aa", "bb");
    assert(strcmp(string_get(string), "bbbbbb") == 0);
    string_delete(string);

    string = string_new("abc");
    string_replace_string(string, "d", "X");
    assert(strcmp(string_get(string), "abc") == 0);
    string_delete(string);

    string = string_new("Test test test.");
    string_replace_string(string, "test", "new");
    assert(strcmp(string_get(string), "Test new new.") == 0);
    string_delete(string);

    string = string_new("abcdef");
    string_replace_string(string, "cd", "DCE");
    assert(strcmp(string_get(string), "abDCEef") == 0);
    string_delete(string);
}

void test_string_split() {
    string_t *string = NULL;
    char **tokens = NULL;
    char **temp = NULL;

    string = string_new("Hello, world! world!");
    tokens = string_split(string, " ");
    assert(strcmp(tokens[0], "Hello,") == 0);
    assert(strcmp(tokens[1], "world!") == 0);
    assert(strcmp(tokens[2], "world!") == 0);
    assert(tokens[3] == NULL);

    string_delete(string);
    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    string = string_new("123, 456, 789");
    tokens = string_split(string, ", ");
    assert(strcmp(tokens[0], "123") == 0);
    assert(strcmp(tokens[1], "456") == 0);
    assert(strcmp(tokens[2], "789") == 0);
    assert(tokens[3] == NULL);

    string_delete(string);
    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    string = string_new("aaaaaa");
    tokens = string_split(string, "a");
    assert(tokens[0] == NULL);

    string_delete(string);
    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    string = string_new("2023/04/23");
    tokens = string_split(string, "/");
    assert(strcmp(tokens[0], "2023") == 0);
    assert(strcmp(tokens[1], "04") == 0);
    assert(strcmp(tokens[2], "23") == 0);
    assert(tokens[3] == NULL);

    string_delete(string);
    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);
}
