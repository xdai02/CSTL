#include "test_coop_str.h"
#include "coop.h"
#include <assert.h>

void test_str_clear() {
    char str1[] = "Hello, world!";
    assert(strcmp(str_clear(str1), "") == 0);
    assert(str1[0] == '\0');

    char str2[] = "";
    assert(strcmp(str_clear(str2), "") == 0);
    assert(str2[0] == '\0');

    char str3[] = "Th!$ !s @ t3st str!ng.";
    assert(strcmp(str_clear(str3), "") == 0);
    assert(str3[0] == '\0');

    char str4[] = "   ";
    assert(strcmp(str_clear(str4), "") == 0);
    assert(str4[0] == '\0');
}

void test_str_equal() {
    assert(str_equal("hello", "hello") == true);
    assert(str_equal("hello", "world") == false);
    assert(str_equal("", "") == true);
    assert(str_equal("hello", "") == false);
}

void test_str_equal_ignore_case() {
    assert(str_equal_ignore_case("hello", "HELLO") == true);
    assert(str_equal_ignore_case("hello", "world") == false);
    assert(str_equal_ignore_case("", "") == true);
    assert(str_equal_ignore_case("hello", "") == false);
}

void test_str_tolower() {
    char str1[] = "HELLO";
    assert(strcmp(str_tolower(str1), "hello") == 0);
    assert(strcmp(str1, "hello") == 0);

    char str2[] = "";
    assert(strcmp(str_tolower(str2), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "HeLLo, W0rLd! 123";
    assert(strcmp(str_tolower(str3), "hello, w0rld! 123") == 0);
    assert(strcmp(str3, "hello, w0rld! 123") == 0);

    char str4[] = "@!$%^&*()";
    assert(strcmp(str_tolower(str4), "@!$%^&*()") == 0);
    assert(strcmp(str4, "@!$%^&*()") == 0);
}

void test_str_toupper() {
    char str1[] = "hello";
    assert(strcmp(str_toupper(str1), "HELLO") == 0);
    assert(strcmp(str1, "HELLO") == 0);

    char str2[] = "";
    assert(strcmp(str_toupper(str2), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "HeLLo, W0rLd! 123";
    assert(strcmp(str_toupper(str3), "HELLO, W0RLD! 123") == 0);
    assert(strcmp(str3, "HELLO, W0RLD! 123") == 0);

    char str4[] = "@!$%^&*()";
    assert(strcmp(str_toupper(str4), "@!$%^&*()") == 0);
    assert(strcmp(str4, "@!$%^&*()") == 0);
}

void test_str_starts_with() {
    assert(str_starts_with("hello, world!", "hello") == true);
    assert(str_starts_with("hello, world!", "world") == false);
    assert(str_starts_with("hello, world!", "") == true);
    assert(str_starts_with("", "hello") == false);
    assert(str_starts_with("", "") == true);
}

void test_str_ends_with() {
    assert(str_ends_with("hello, world!", "world!") == true);
    assert(str_ends_with("hello, world!", "hello") == false);
    assert(str_ends_with("hello, world!", "") == true);
    assert(str_ends_with("", "world!") == false);
    assert(str_ends_with("", "") == true);
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
}

void test_str_reverse() {
    char str1[] = "Hello, world!";
    assert(strcmp(str_reverse(str1), "!dlrow ,olleH") == 0);
    assert(strcmp(str1, "!dlrow ,olleH") == 0);

    char str2[] = "";
    assert(strcmp(str_reverse(str2), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "abcdef";
    assert(strcmp(str_reverse(str3), "fedcba") == 0);
    assert(strcmp(str3, "fedcba") == 0);
}

void test_str_trim() {
    char str1[] = "  Hello, world!  ";
    assert(strcmp(str_trim(str1), "Hello, world!") == 0);
    assert(strcmp(str1, "Hello, world!") == 0);

    char str2[] = "";
    assert(strcmp(str_trim(str2), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "abcdef";
    assert(strcmp(str_trim(str3), "abcdef") == 0);
    assert(strcmp(str3, "abcdef") == 0);

    char str4[] = "   ";
    assert(strcmp(str_trim(str4), "") == 0);
    assert(strcmp(str4, "") == 0);
}

void test_str_substring() {
    char *substr1 = str_substring("Hello, world!", 0, 5);
    assert(strcmp(substr1, "Hello") == 0);
    free(substr1);

    char *substr2 = str_substring("Hello, world!", 7, 12);
    assert(strcmp(substr2, "world") == 0);
    free(substr2);

    char *substr3 = str_substring("", 0, 0);
    assert(strcmp(substr3, "") == 0);
    free(substr3);

    char *substr4 = str_substring("abcdef", 2, 5);
    assert(strcmp(substr4, "cde") == 0);
    free(substr4);
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
    char str1[20] = "Hello, world!";
    assert(strcmp(str_append_char(str1, '!'), "Hello, world!!") == 0);
    assert(strcmp(str1, "Hello, world!!") == 0);

    char str2[20] = "";
    assert(strcmp(str_append_char(str2, 'A'), "A") == 0);
    assert(strcmp(str2, "A") == 0);

    char str3[20] = "abc";
    assert(strcmp(str_append_char(str3, 'd'), "abcd") == 0);
    assert(strcmp(str3, "abcd") == 0);
}

void test_str_insert_char() {
    char str1[20] = "Hello, world!";
    assert(strcmp(str_insert_char(str1, 0, 'A'), "AHello, world!") == 0);
    assert(strcmp(str1, "AHello, world!") == 0);

    char str2[20] = "Hello, world!";
    assert(strcmp(str_insert_char(str2, 13, '!'), "Hello, world!!") == 0);
    assert(strcmp(str2, "Hello, world!!") == 0);

    char str3[20] = "abc";
    assert(strcmp(str_insert_char(str3, 1, 'X'), "aXbc") == 0);
    assert(strcmp(str3, "aXbc") == 0);
}

void test_str_insert_string() {
    char str1[20] = "Hello, world!";
    assert(strcmp(str_insert_string(str1, 0, "A"), "AHello, world!") == 0);
    assert(strcmp(str1, "AHello, world!") == 0);

    char str2[20] = "Hello, world!";
    assert(strcmp(str_insert_string(str2, 13, "!!"), "Hello, world!!!") == 0);
    assert(strcmp(str2, "Hello, world!!!") == 0);

    char str3[20] = "abc";
    assert(strcmp(str_insert_string(str3, 1, "XYZ"), "aXYZbc") == 0);
    assert(strcmp(str3, "aXYZbc") == 0);
}

void test_str_remove_char() {
    char str1[] = "Hello, world!";
    assert(strcmp(str_remove_char(str1, 'o'), "Hell, wrld!") == 0);
    assert(strcmp(str1, "Hell, wrld!") == 0);

    char str2[] = "aaaaaa";
    assert(strcmp(str_remove_char(str2, 'a'), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "abc";
    assert(strcmp(str_remove_char(str3, 'd'), "abc") == 0);
    assert(strcmp(str3, "abc") == 0);
}

void test_str_remove_string() {
    char str1[] = "Hello, world! world!";
    assert(strcmp(str_remove_string(str1, "world"), "Hello, ! !") == 0);
    assert(strcmp(str1, "Hello, ! !") == 0);

    char str2[] = "aaaaaa";
    assert(strcmp(str_remove_string(str2, "aa"), "") == 0);
    assert(strcmp(str2, "") == 0);

    char str3[] = "abc";
    assert(strcmp(str_remove_string(str3, "d"), "abc") == 0);
    assert(strcmp(str3, "abc") == 0);

    char str4[] = "aaaaaaa";
    assert(strcmp(str_remove_string(str4, "aa"), "a") == 0);
    assert(strcmp(str4, "a") == 0);
}

void test_str_replace_char() {
    char str1[] = "Hello, world!";
    assert(strcmp(str_replace_char(str1, 'o', 'X'), "HellX, wXrld!") == 0);
    assert(strcmp(str1, "HellX, wXrld!") == 0);

    char str2[] = "aaaaaa";
    assert(strcmp(str_replace_char(str2, 'a', 'b'), "bbbbbb") == 0);
    assert(strcmp(str2, "bbbbbb") == 0);

    char str3[] = "abc";
    assert(strcmp(str_replace_char(str3, 'd', 'X'), "abc") == 0);
    assert(strcmp(str3, "abc") == 0);
}

void test_str_replace_string() {
    char str1[30] = "Hello, world! world!";
    assert(strcmp(str_replace_string(str1, "world", "Earth"), "Hello, Earth! Earth!") == 0);
    assert(strcmp(str1, "Hello, Earth! Earth!") == 0);

    char str2[20] = "aaaaaa";
    assert(strcmp(str_replace_string(str2, "aa", "bb"), "bbbbbb") == 0);
    assert(strcmp(str2, "bbbbbb") == 0);

    char str3[20] = "abc";
    assert(strcmp(str_replace_string(str3, "d", "X"), "abc") == 0);
    assert(strcmp(str3, "abc") == 0);

    char str4[30] = "Test test test.";
    assert(strcmp(str_replace_string(str4, "test", "new"), "Test new new.") == 0);
    assert(strcmp(str4, "Test new new.") == 0);

    char str5[20] = "abcdef";
    assert(strcmp(str_replace_string(str5, "cd", "DCE"), "abDCEef") == 0);
    assert(strcmp(str5, "abDCEef") == 0);
}

void test_str_split() {
    char **temp = NULL;

    char **tokens1 = str_split("Hello, world! world!", " ");
    assert(strcmp(tokens1[0], "Hello,") == 0);
    assert(strcmp(tokens1[1], "world!") == 0);
    assert(strcmp(tokens1[2], "world!") == 0);
    assert(tokens1[3] == NULL);

    temp = tokens1;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens1);

    char **tokens2 = str_split("abc,def,ghi", ",");
    assert(strcmp(tokens2[0], "abc") == 0);
    assert(strcmp(tokens2[1], "def") == 0);
    assert(strcmp(tokens2[2], "ghi") == 0);
    assert(tokens2[3] == NULL);

    temp = tokens2;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens2);

    char **tokens3 = str_split("aaaaaa", "a");
    assert(tokens3[0] == NULL);

    temp = tokens3;
    while (*temp) {
        free(*temp);
        temp++;
    }
    free(tokens3);
}
