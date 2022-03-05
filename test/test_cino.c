#include "test_cino_utils.h"

void test_cino_utils() {
    test_return_if_fail();
    test_return_value_if_fail();
    test_call_and_return_if_fail();
    test_call_and_return_value_if_fail();

    test_array_len();

    test_string_equal();
    test_equals_ignore_case();
    test_string_clear();
    test_string_length();
    test_string_copy();

    test_string_to_bool();
    test_bool_to_string();
    test_string_to_int();
    test_int_to_string();
    test_string_to_double();
    test_double_to_string();

    printf("[PASS] test_cino_utils\n");
}

int main(int argc, char *argv[]) {
    test_cino_utils();

    return 0;
}