#include <stdio.h>
#include "test_cstl.h"

void test_str() {
    test_string_create();
    test_string_destroy();
    test_string_clone();
    test_string_length();
    test_string_is_empty();
    test_string_get();
    test_string_char_at();
    test_string_set_char_at();
    test_string_clear();
    test_string_equal();
    test_string_equal_ignore_case();
    test_string_tolower();
    test_string_toupper();
    test_string_starts_with();
    test_string_ends_with();
    test_string_index_of_char();
    test_string_index_of_string();
    test_string_contains_string();
    test_string_reverse();
    test_string_strip();
    test_string_substring();
    test_string_count_substring();
    test_string_append_char();
    test_string_insert_char();
    test_string_concat();
    test_string_insert_string();
    test_string_remove_char();
    test_string_remove_string();
    test_string_replace_char();
    test_string_replace_string();
    test_string_split();

    printf("[PASS] str\n");
}

void test_array() {
    test_array_create();
    test_array_destroy();
    test_array_foreach();
    test_array_is_empty();
    test_array_size();
    test_array_clear();
    test_array_get();
    test_array_set();
    test_array_append();
    test_array_insert();
    test_array_remove();
    test_array_index_of();
    test_array_contains();
    test_array_count();
    test_array_reverse();
    test_array_sort();
    test_array_iterator();

    printf("[PASS] array\n");
}

void test_list() {
    test_list_create();
    test_list_destroy();
    test_list_foreach();
    test_list_is_empty();
    test_list_size();
    test_list_clear();
    test_list_get();
    test_list_set();
    test_list_index_of();
    test_list_contains();
    test_list_get_front();
    test_list_get_back();
    test_list_push_front();
    test_list_push_back();
    test_list_pop_front();
    test_list_pop_back();
    test_list_insert();
    test_list_remove();
    test_list_count();
    test_list_reverse();
    test_list_iterator();

    printf("[PASS] list\n");
}

void test_cstl() {
    test_str();
    test_array();
    test_list();
}
