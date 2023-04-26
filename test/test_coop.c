#include <stdio.h>
#include "test_utils.h"
#include "test_wrapper.h"
#include "test_cstl_string.h"
#include "test_cstl_array.h"

void test_utils() {
    test_min();
    test_max();
    test_swap();
    test_float_equal();
    test_double_equal();
    test_randint();
    test_random();

    test_str_clear();
    test_str_equal();
    test_str_equal_ignore_case();
    test_str_tolower();
    test_str_toupper();
    test_str_starts_with();
    test_str_ends_with();
    test_str_index_of_char();
    test_str_index_of_string();
    test_str_contains_string();
    test_str_reverse();
    test_str_strip();
    test_str_substring();
    test_str_count_substring();
    test_str_append_char();
    test_str_insert_char();
    test_str_insert_string();
    test_str_remove_char();
    test_str_remove_string();
    test_str_replace_char();
    test_str_replace_string();
    test_str_split();

    printf("[PASS] utils\n");
}

void test_wrapper() {
    test_Character();
    test_UnsignedCharacter();
    test_Short();
    test_UnsignedShort();
    test_Integer();
    test_UnsignedInteger();
    test_Long();
    test_UnsignedLong();
    test_Float();
    test_Double();
    test_Boolean();

    printf("[PASS] wrapper\n");
}

void test_cstl_string() {
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

    printf("[PASS] cstl_string\n");
}

void test_cstl_array() {
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

    printf("[PASS] cstl_array\n");
}

int main() {
    test_utils();
    test_wrapper();
    test_cstl_string();
    test_cstl_array();

    return 0;
}
