#include "test_cino_utils.h"
#include "test_cino_string.h"

void test_cino_utils() {
    test_min();
    test_max();

    test_return_if_fail();
    test_return_value_if_fail();
    test_call_and_return_if_fail();
    test_call_and_return_value_if_fail();

    test_array_len();

    test_string_to_bool();
    test_bool_to_string();
    test_string_to_char();
    test_char_to_string();
    test_string_to_int();
    test_int_to_string();
    test_string_to_double();
    test_double_to_string();

    test_string_equal();
    test_string_equal_ignore_case();
    test_string_starts_with();
    test_string_tolower();
    test_string_toupper();
    test_string_ends_with();
    test_string_clear();
    test_string_length();
    test_string_copy();
    test_string_concat();
    test_string_trim();
    test_string_append_char();
    test_string_append_int();
    test_string_append_double();
    test_string_insert_char();
    test_string_insert_string();
    test_string_substring();
    test_string_replace_char();
    test_string_replace();
    test_string_remove();
    test_string_index_of_char();
    test_string_index_of_char_from();
    test_string_index_of_substring();
    test_string_index_of_substring_from();
    test_string_last_index_of_char();
    test_string_last_index_of_char_from();
    test_string_last_index_of_substring();
    test_string_last_index_of_substring_from();
    test_string_split();

    test_cino_alloc();
    test_cino_realloc();

    printf("[PASS] test_cino_utils\n");
}

void test_cino_string() {
    test_cino_string_create();
    test_cino_string_destroy();
    test_cino_string_get();
    test_cino_string_set();
    test_cino_string_length();
    test_cino_string_clear();
    test_cino_string_equal();
    test_cino_string_equal_ignore_case();
    test_cino_string_tolower();
    test_cino_string_toupper();
    test_cino_string_starts_with();
    test_cino_string_ends_with();
    test_cino_string_copy();
    test_cino_string_concat();
    test_cino_string_insert_char();
    test_cino_string_insert_string();

    printf("[PASS] test_cino_string\n");
}

int main(int argc, char *argv[]) {
    test_cino_utils();
    test_cino_string();

    return 0;
}