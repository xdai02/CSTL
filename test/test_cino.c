#include "test_cino_utils.h"

void test_cino_utils() {
    test_return_if_fail();
    test_return_value_if_fail();
    test_call_and_return_if_fail();
    test_call_and_return_value_if_fail();
    test_array_len();
    test_equals_ignore_case();
    test_string_to_bool();
    test_bool_to_string();
    printf("[OK] test_cino_utils\n");
}

int main(int argc, char *argv[]) {
    test_cino_utils();

    return 0;
}