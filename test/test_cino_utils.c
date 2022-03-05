#include "test_cino_utils.h"
#include "cino_utils.h"

void test_return_if_fail() {
    int cnt = 0;
    cnt++;
    assert(cnt == 1);
    return_if_fail(cnt == 0);
    assert(cnt == 0);
}

static int test_return_value_if_fail_helper(int cnt) {
    return_value_if_fail(cnt == 0, -1);
    return -2;
}

void test_return_value_if_fail() {
    int cnt = 0;
    cnt++;
    assert(cnt == 1);
    cnt = test_return_value_if_fail_helper(cnt);
    assert(cnt == -1);
}

static void test_call_and_return_if_fail_helper(int cnt) {
    assert(cnt == 1);
}

void test_call_and_return_if_fail() {
    int cnt = 0;
    cnt++;
    assert(cnt == 1);
    call_and_return_if_fail(cnt == 0, test_call_and_return_if_fail_helper(cnt));
    assert(cnt == 0);
}

static void test_call_and_return_value_if_fail_helper2(int cnt) {
    assert(cnt == 1);
}

static int test_call_and_return_value_if_fail_helper1(int cnt) {
    assert(cnt == 1);
    call_and_return_value_if_fail(cnt == 0, test_call_and_return_value_if_fail_helper2(cnt), -1);
    return -2;
}

void test_call_and_return_value_if_fail() {
    int cnt = 0;
    cnt++;
    assert(cnt == 1);
    cnt = test_call_and_return_value_if_fail_helper1(cnt);
    assert(cnt == -1);
}

void test_array_len() {
    int arr1[5] = {1, 2, 3, 4, 5};
    assert(array_len(arr1) == 5);

    float arr2[] = {6.1f, 7.2f, 8.3f, 9.4f};
    assert(array_len(arr2) == 4);

    double arr3[] = {3.14, 2.7};
    assert(array_len(arr3) == 2);

    char arr4[3] = {'A', 'B', '\0'};
    assert(array_len(arr4) == 3);

    const char *arr5[] = {"hello", "world", "C/C++", "Java", "Python", "JavaScript"};
    assert(array_len(arr5) == 6);
}

void test_equals_ignore_case() {
    assert(equals_ignore_case("hello", "hello"));
    assert(equals_ignore_case("Hello", "hElLo"));
    assert(equals_ignore_case("", ""));
    assert(equals_ignore_case("ABCDabcd", "abcdABCD"));
    assert(equals_ignore_case("12345", "12345"));
    assert(!equals_ignore_case("abc", "cba"));
    assert(!equals_ignore_case("  ", "    "));
    assert(!equals_ignore_case("\n", "\t"));

    const char *s1 = "XYZ";
    const char *s2 = "xYz";
    assert(equals_ignore_case(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!equals_ignore_case(s1, s2));

    char s3[] = "!@#$%^&*()";
    char s4[32] = "!@#$%^&*()";
    assert(equals_ignore_case(s3, s4));
}

void test_string_to_bool() {
    assert(!string_to_bool(NULL));
    assert(!string_to_bool(""));
    assert(!string_to_bool("False"));
    assert(!string_to_bool("false"));
    assert(!string_to_bool("FALSE"));
    assert(!string_to_bool("fALse"));
    assert(!string_to_bool("0"));
    assert(!string_to_bool("000000000"));

    assert(string_to_bool("true"));
    assert(string_to_bool("-0"));
    assert(string_to_bool("false_but_true"));
    assert(string_to_bool("123"));

    const char *s1 = NULL;
    assert(!string_to_bool(s1));

    const char *s2 = "!@#$";
    assert(string_to_bool(s2));
}

void test_bool_to_string() {
    assert(strncmp(bool_to_string(true), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_string(false), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_string(1), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_string(0), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_string(0.0), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_string(123), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_string(-0), "false", strlen("false")) == 0);
}