#include <stdio.h>
#include "test_utils.h"
#include "test_cstl.h"

int main() {
    test_utils();
    test_cstl();

    printf("[PASS] ALL\n");
    return 0;
}
