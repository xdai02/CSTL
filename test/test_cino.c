#include "test_cino_utils.h"

void test_cino_utils() {
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
    test_equals_ignore_case();
    test_string_starts_with();
    test_string_tolower();
    test_string_toupper();
    test_string_ends_with();
    test_string_clear();
    test_string_length();
    test_string_copy();
    test_string_concat();
    test_string_append_char();
    test_string_append_int();
    test_string_append_double();
    test_string_insert_char();
    // test_string_insert_string();

    printf("[PASS] test_cino_utils\n");
}

int main(int argc, char *argv[]) {
    test_cino_utils();

    return 0;
}