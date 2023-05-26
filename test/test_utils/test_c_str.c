#include "test_c_str.h"
#include "cstl.h"
#include <assert.h>

void test_str_clear() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_clear(str), "") == 0);
    assert(str[0] == '\0');

    strcpy(str, "");
    assert(strcmp(str_clear(str), "") == 0);
    assert(str[0] == '\0');

    strcpy(str, "Th!$ !s @ t3st str!ng.");
    assert(strcmp(str_clear(str), "") == 0);
    assert(str[0] == '\0');

    strcpy(str, "   ");
    assert(strcmp(str_clear(str), "") == 0);
    assert(str[0] == '\0');
}

void test_str_equal() {
    assert(str_equal("hello", "hello") == true);
    assert(str_equal("hello", "world") == false);
    assert(str_equal("", "") == true);
    assert(str_equal("hello", "") == false);
    assert(str_equal("Hello, world!", "Hello, world!") == true);
}

void test_str_equal_ignore_case() {
    assert(str_equal_ignore_case("hello", "HELLO") == true);
    assert(str_equal_ignore_case("hello", "world") == false);
    assert(str_equal_ignore_case("", "") == true);
    assert(str_equal_ignore_case("hello", "") == false);
    assert(str_equal_ignore_case("Hello, world!", "HELLO, WORLD!") == true);
}

void test_str_tolower() {
    char str[32];

    strcpy(str, "HELLO");
    assert(strcmp(str_tolower(str), "hello") == 0);
    assert(strcmp(str, "hello") == 0);

    strcpy(str, "");
    assert(strcmp(str_tolower(str), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "HeLLo, W0rLd! 123");
    assert(strcmp(str_tolower(str), "hello, w0rld! 123") == 0);
    assert(strcmp(str, "hello, w0rld! 123") == 0);

    strcpy(str, "@!$%^&*()");
    assert(strcmp(str_tolower(str), "@!$%^&*()") == 0);
    assert(strcmp(str, "@!$%^&*()") == 0);
}

void test_str_toupper() {
    char str[32];

    strcpy(str, "hello");
    assert(strcmp(str_toupper(str), "HELLO") == 0);
    assert(strcmp(str, "HELLO") == 0);

    strcpy(str, "");
    assert(strcmp(str_toupper(str), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "HeLLo, W0rLd! 123");
    assert(strcmp(str_toupper(str), "HELLO, W0RLD! 123") == 0);
    assert(strcmp(str, "HELLO, W0RLD! 123") == 0);

    strcpy(str, "@!$%^&*()");
    assert(strcmp(str_toupper(str), "@!$%^&*()") == 0);
    assert(strcmp(str, "@!$%^&*()") == 0);
}

void test_str_starts_with() {
    assert(str_starts_with("hello, world!", "hello") == true);
    assert(str_starts_with("hello, world!", "world") == false);
    assert(str_starts_with("hello, world!", "") == true);
    assert(str_starts_with("", "hello") == false);
    assert(str_starts_with("", "") == true);
    assert(str_starts_with("Hello, world!", "Hello, world!") == true);
}

void test_str_ends_with() {
    assert(str_ends_with("hello, world!", "world!") == true);
    assert(str_ends_with("hello, world!", "hello") == false);
    assert(str_ends_with("hello, world!", "") == true);
    assert(str_ends_with("", "world!") == false);
    assert(str_ends_with("", "") == true);
    assert(str_ends_with("Hello, world!", "Hello, world!") == true);
}

void test_str_index_of_char() {
    assert(str_index_of_char("Hello, world!", 'H') == 0);
    assert(str_index_of_char("Hello, world!", ',') == 5);
    assert(str_index_of_char("Hello, world!", '!') == 12);
    assert(str_index_of_char("Hello, world!", 'z') == -1);
    assert(str_index_of_char("", 'a') == -1);
    assert(str_index_of_char("abcdef", 'a') == 0);
    assert(str_index_of_char("abcdef", 'f') == 5);
    assert(str_index_of_char("abcdef", 'z') == -1);
}

void test_str_index_of_string() {
    assert(str_index_of_string("Hello, world!", "world") == 7);
    assert(str_index_of_string("Hello, world!", "abc") == -1);
    assert(str_index_of_string("", "Hello, world!") == -1);
    assert(str_index_of_string("abcdef", "") == -1);
    assert(str_index_of_string("abcdef", "xyz") == -1);
    assert(str_index_of_string("Hello, world!", "Hello, world!") == 0);
}

void test_str_contains_string() {
    assert(str_contains_string("Hello, world!", "world") == true);
    assert(str_contains_string("Hello, world!", "abc") == false);
    assert(str_contains_string("", "Hello, world!") == false);
    assert(str_contains_string("abcdef", "") == false);
    assert(str_contains_string("abcdef", "xyz") == false);
    assert(str_contains_string("Hello, world!", "Hello, world!") == true);
}

void test_str_reverse() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_reverse(str), "!dlrow ,olleH") == 0);
    assert(strcmp(str, "!dlrow ,olleH") == 0);

    strcpy(str, "");
    assert(strcmp(str_reverse(str), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "abcdef");
    assert(strcmp(str_reverse(str), "fedcba") == 0);
    assert(strcmp(str, "fedcba") == 0);
}

void test_str_strip() {
    char str[32];

    strcpy(str, "  Hello, world!  ");
    assert(strcmp(str_strip(str), "Hello, world!") == 0);
    assert(strcmp(str, "Hello, world!") == 0);

    strcpy(str, "");
    assert(strcmp(str_strip(str), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "abcdef");
    assert(strcmp(str_strip(str), "abcdef") == 0);
    assert(strcmp(str, "abcdef") == 0);

    strcpy(str, "   ");
    assert(strcmp(str_strip(str), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "\n\t\t\t\nHello, world!\n\t\t\t\n");
    assert(strcmp(str_strip(str), "Hello, world!") == 0);
    assert(strcmp(str, "Hello, world!") == 0);

    strcpy(str, "\n\n\n\n   \t\t\t\n ");
    assert(strcmp(str_strip(str), "") == 0);
    assert(strcmp(str, "") == 0);
}

void test_str_substring() {
    char *substr = NULL;

    substr = str_substring("Hello, world!", 0, 5);
    assert(strcmp(substr, "Hello") == 0);
    free(substr);

    substr = str_substring("Hello, world!", 7, 12);
    assert(strcmp(substr, "world") == 0);
    free(substr);

    substr = str_substring("abcdef", 2, 5);
    assert(strcmp(substr, "cde") == 0);
    free(substr);

    substr = str_substring("", 0, 0);
    assert(substr == NULL);
}

void test_str_count_substring() {
    assert(str_count_substring("Hello, world!", "world") == 1);
    assert(str_count_substring("Hello, world!", "abc") == 0);
    assert(str_count_substring("", "Hello, world!") == 0);
    assert(str_count_substring("abcdef", "") == 0);
    assert(str_count_substring("abcdef", "xyz") == 0);
    assert(str_count_substring("Hello Hello Hello World!", "Hello") == 3);
    assert(str_count_substring("Hello World Hello World!", "World") == 2);
}

void test_str_append_char() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_append_char(str, '!'), "Hello, world!!") == 0);
    assert(strcmp(str, "Hello, world!!") == 0);

    strcpy(str, "");
    assert(strcmp(str_append_char(str, 'A'), "A") == 0);
    assert(strcmp(str, "A") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_append_char(str, 'd'), "abcd") == 0);
    assert(strcmp(str, "abcd") == 0);

    strcpy(str, "Hello, world!");
    assert(strcmp(str_append_char(str, '\0'), "Hello, world!") == 0);
    assert(strcmp(str, "Hello, world!") == 0);
}

void test_str_insert_char() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_insert_char(str, 0, 'A'), "AHello, world!") == 0);
    assert(strcmp(str, "AHello, world!") == 0);

    strcpy(str, "Hello, world!");
    assert(strcmp(str_insert_char(str, 13, '!'), "Hello, world!!") == 0);
    assert(strcmp(str, "Hello, world!!") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_insert_char(str, 1, 'X'), "aXbc") == 0);
    assert(strcmp(str, "aXbc") == 0);

    strcpy(str, "Hello, world!");
    assert(strcmp(str_insert_char(str, 5, '\0'), "Hello") == 0);
    assert(strcmp(str, "Hello") == 0);
}

void test_str_insert_string() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_insert_string(str, 0, "A"), "AHello, world!") == 0);
    assert(strcmp(str, "AHello, world!") == 0);

    strcpy(str, "Hello, world!");
    assert(strcmp(str_insert_string(str, 13, "!!"), "Hello, world!!!") == 0);
    assert(strcmp(str, "Hello, world!!!") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_insert_string(str, 1, "XYZ"), "aXYZbc") == 0);
    assert(strcmp(str, "aXYZbc") == 0);
}

void test_str_remove_char() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_remove_char(str, 'o'), "Hell, wrld!") == 0);
    assert(strcmp(str, "Hell, wrld!") == 0);

    strcpy(str, "aaaaaa");
    assert(strcmp(str_remove_char(str, 'a'), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_remove_char(str, 'd'), "abc") == 0);
    assert(strcmp(str, "abc") == 0);
}

void test_str_remove_string() {
    char str[32];

    strcpy(str, "Hello, world! world!");
    assert(strcmp(str_remove_string(str, "world"), "Hello, ! !") == 0);
    assert(strcmp(str, "Hello, ! !") == 0);

    strcpy(str, "aaaaaa");
    assert(strcmp(str_remove_string(str, "aa"), "") == 0);
    assert(strcmp(str, "") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_remove_string(str, "d"), "abc") == 0);
    assert(strcmp(str, "abc") == 0);

    strcpy(str, "aaaaaaa");
    assert(strcmp(str_remove_string(str, "aa"), "a") == 0);
    assert(strcmp(str, "a") == 0);
}

void test_str_replace_char() {
    char str[32];

    strcpy(str, "Hello, world!");
    assert(strcmp(str_replace_char(str, 'o', 'X'), "HellX, wXrld!") == 0);
    assert(strcmp(str, "HellX, wXrld!") == 0);

    strcpy(str, "aaaaaa");
    assert(strcmp(str_replace_char(str, 'a', 'b'), "bbbbbb") == 0);
    assert(strcmp(str, "bbbbbb") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_replace_char(str, 'd', 'X'), "abc") == 0);
    assert(strcmp(str, "abc") == 0);

    strcpy(str, "Hello, world!");
    assert(strcmp(str_replace_char(str, 'o', '\0'), "Hell") == 0);
    assert(strcmp(str, "Hell") == 0);
}

void test_str_replace_string() {
    char str[32];

    strcpy(str, "Hello, world! world!");
    assert(strcmp(str_replace_string(str, "world", "Earth"), "Hello, Earth! Earth!") == 0);
    assert(strcmp(str, "Hello, Earth! Earth!") == 0);

    strcpy(str, "aaaaaa");
    assert(strcmp(str_replace_string(str, "aa", "bb"), "bbbbbb") == 0);
    assert(strcmp(str, "bbbbbb") == 0);

    strcpy(str, "abc");
    assert(strcmp(str_replace_string(str, "d", "X"), "abc") == 0);
    assert(strcmp(str, "abc") == 0);

    strcpy(str, "Test test test.");
    assert(strcmp(str_replace_string(str, "test", "new"), "Test new new.") == 0);
    assert(strcmp(str, "Test new new.") == 0);

    strcpy(str, "abcdef");
    assert(strcmp(str_replace_string(str, "cd", "DCE"), "abDCEef") == 0);
    assert(strcmp(str, "abDCEef") == 0);
}

void test_str_split() {
    char **temp = NULL;
    char **tokens = NULL;

    tokens = str_split("Hello, world! world!", " ");
    assert(strcmp(tokens[0], "Hello,") == 0);
    assert(strcmp(tokens[1], "world!") == 0);
    assert(strcmp(tokens[2], "world!") == 0);
    assert(tokens[3] == NULL);

    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    tokens = str_split("123, 456, 789", ", ");
    assert(strcmp(tokens[0], "123") == 0);
    assert(strcmp(tokens[1], "456") == 0);
    assert(strcmp(tokens[2], "789") == 0);
    assert(tokens[3] == NULL);

    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    tokens = str_split("aaaaaa", "a");
    assert(tokens[0] == NULL);

    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);

    tokens = str_split("2023/04/23", "/");
    assert(strcmp(tokens[0], "2023") == 0);
    assert(strcmp(tokens[1], "04") == 0);
    assert(strcmp(tokens[2], "23") == 0);
    assert(tokens[3] == NULL);

    temp = tokens;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens);
}
