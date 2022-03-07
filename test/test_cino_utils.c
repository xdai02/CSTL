#include "test_cino_utils.h"
#include "cino_utils.h"

const double EPS = 1e-6;  // 用于比较浮点数的精度

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

void test_string_to_char() {
    char s1[] = "A";
    assert(string_to_char(s1) == 'A');

    char s2[8] = "25X13";
    assert(string_to_char(s2) == '2');

    const char *s3 = "@.!#$)";
    assert(string_to_char(s3) == '@');

    assert(string_to_char(" ") == ' ');
    assert(string_to_char("\n") == '\n');
    assert(string_to_char("\t") == '\t');
    assert(string_to_char(NULL) == '\0');
    assert(string_to_char("") == '\0');
}

void test_char_to_string() {
    char *p = NULL;

    char s1[8] = {0};
    p = char_to_string('H', s1, sizeof(s1));
    assert(strncmp(s1, "H", sizeof(s1)) == 0);
    assert(strncmp(p, "H", sizeof(s1)) == 0);

    char s2[8] = "Hello";
    p = char_to_string('2', s2, sizeof(s2));
    assert(strncmp(s2, "2", sizeof(s2)) == 0);
    assert(strncmp(p, "2", sizeof(s2)) == 0);

    char s3[2] = "#";
    p = char_to_string('!', s3, sizeof(s3));
    assert(strncmp(s3, "!", sizeof(s3)) == 0);
    assert(strncmp(p, "!", sizeof(s3)) == 0);

    char s4[3] = "";
    p = char_to_string('\0', s4, sizeof(s4));
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    p = char_to_string('\0', NULL, 0);
    assert(!p);
}

void test_string_to_int() {
    assert(string_to_int("123") == 123);
    assert(string_to_int("-123") == -123);
    assert(string_to_int("0") == 0);
    assert(string_to_int("+0") == 0);
    assert(string_to_int("-0") == 0);
    assert(string_to_int("3.14") == 3);
    assert(string_to_int("2.717") == 2);
    assert(string_to_int("-3.14") == -3);
    assert(string_to_int("2147483647") == 2147483647);
    assert(string_to_int("-2147483648") == -2147483648);
}

void test_int_to_string() {
    char *p = NULL;

    char s1[4] = {0};
    p = int_to_string(123, s1, sizeof(s1));
    assert(strncmp(s1, "123", sizeof(s1)) == 0);
    assert(strncmp(p, "123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = int_to_string(-987, s2, sizeof(s2));
    assert(strncmp(s2, "-987", sizeof(s2)) == 0);
    assert(strncmp(p, "-987", sizeof(s2)) == 0);

    char s3[12] = {0};
    p = int_to_string(2147483647, s3, sizeof(s3));
    assert(strncmp(s3, "2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "2147483647", sizeof(s3)) == 0);

    char s4[13] = {0};
    p = int_to_string(-2147483648, s4, sizeof(s4));
    assert(strncmp(s4, "-2147483648", sizeof(s4)) == 0);
    assert(strncmp(p, "-2147483648", sizeof(s4)) == 0);

    char *s5 = (char *)malloc(sizeof(char) * 5);
    p = int_to_string(3.14, s5, 5);
    assert(strncmp(s5, "3", strlen("3")) == 0);
    assert(strncmp(p, "3", strlen("3")) == 0);
    free(s5);

    char *s6 = (char *)malloc(sizeof(char) * 5);
    p = int_to_string(-2.717, s6, 5);
    assert(strncmp(s6, "-2", strlen("-2")) == 0);
    assert(strncmp(p, "-2", strlen("-2")) == 0);
    free(s6);

    p = int_to_string(0, NULL, 0);
    assert(!p);
}

void test_string_to_double() {
    assert(fabs(string_to_double("123") - 123.0) <= EPS);
    assert(fabs(string_to_double("-123") - (-123.0)) <= EPS);
    assert(fabs(string_to_double("0") - 0.0) <= EPS);
    assert(fabs(string_to_double("+0") - 0.0) <= EPS);
    assert(fabs(string_to_double("-0") - 0.0) <= EPS);
    assert(fabs(string_to_double("3.14") - 3.14) <= EPS);
    assert(fabs(string_to_double("2.717") - 2.717) <= EPS);
    assert(fabs(string_to_double("-3.14") - (-3.14)) <= EPS);
    assert(fabs(string_to_double("2147483647") - 2147483647.0) <= EPS);
    assert(fabs(string_to_double("-2147483648") - (-2147483648.0)) <= EPS);
    assert(fabs(string_to_double("0.00") - 0.0) <= EPS);
    assert(fabs(string_to_double("3.1415926") - 3.1415926) <= EPS);
    assert(fabs(string_to_double("1e2") - 100.0) <= EPS);
    assert(fabs(string_to_double("-2.3e4") - (-23000.0)) <= EPS);
}

void test_double_to_string() {
    char *p = NULL;

    char s1[6] = {0};
    p = double_to_string(123, 1, s1, sizeof(s1));
    assert(strncmp(s1, "123.0", sizeof(s1)) == 0);
    assert(strncmp(p, "123.0", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = double_to_string(-987, 4, s2, sizeof(s2));
    assert(strncmp(s2, "-987.0000", sizeof(s2)) == 0);
    assert(strncmp(p, "-987.0000", sizeof(s2)) == 0);

    char s3[16] = {0};
    p = double_to_string(2147483647, 0, s3, sizeof(s3));
    assert(strncmp(s3, "2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "2147483647", sizeof(s3)) == 0);

    char s4[16] = {0};
    p = double_to_string(-3.141592, 4, s4, sizeof(s4));
    assert(strncmp(s4, "-3.1416", sizeof(s4)) == 0);
    assert(strncmp(p, "-3.1416", sizeof(s4)) == 0);

    char *s5 = (char *)malloc(sizeof(char) * 5);
    p = double_to_string(3.14, 1, s5, 5);
    assert(strncmp(s5, "3.1", strlen("3.1")) == 0);
    assert(strncmp(p, "3.1", strlen("3.1")) == 0);
    free(s5);

    char *s6 = (char *)malloc(sizeof(char) * 8);
    p = double_to_string(2.717, 0, s6, 5);
    assert(strncmp(s6, "3", strlen("3")) == 0);
    assert(strncmp(p, "3", strlen("3")) == 0);
    free(s6);

    char *s7 = (char *)malloc(sizeof(char) * 8);
    p = double_to_string(1e2, 3, s7, 8);
    assert(strncmp(s7, "100.000", strlen("100.000")) == 0);
    assert(strncmp(p, "100.000", strlen("100.000")) == 0);
    free(s7);

    char *s8 = (char *)malloc(sizeof(char) * 32);
    p = double_to_string(-2.71e7, 2, s8, 32);
    assert(strncmp(s8, "-27100000.00", strlen("-27100000.00")) == 0);
    assert(strncmp(p, "-27100000.00", strlen("-27100000.00")) == 0);
    free(s8);

    p = double_to_string(0, -1, NULL, 0);
    assert(!p);
}

void test_string_equal() {
    assert(string_equal("hello", "hello"));
    assert(string_equal("Hello", "Hello"));
    assert(string_equal("", ""));
    assert(string_equal("ABCDabcd", "ABCDabcd"));
    assert(string_equal("12345", "12345"));
    assert(string_equal("abc", "abc"));
    assert(string_equal("   ", "   "));
    assert(string_equal("\n", "\n"));

    const char *s1 = "XYZ";
    const char *s2 = "XYZ";
    assert(string_equal(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!string_equal(s1, s2));

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(string_equal(s3, s4));

    assert(string_equal(NULL, NULL));
    assert(!string_equal("", NULL));
    assert(!string_equal(NULL, ""));
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

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(equals_ignore_case(s3, s4));

    assert(equals_ignore_case(NULL, NULL));
    assert(!equals_ignore_case("", NULL));
    assert(!equals_ignore_case(NULL, ""));
}

void test_string_tolower() {
    char *p = NULL;

    char s1[] = "HELLO";
    p = string_tolower(s1);
    assert(strncmp(s1, "hello", sizeof(s1)) == 0);
    assert(strncmp(p, "hello", sizeof(s1)) == 0);

    char s2[16] = "HeLlO WoRlD";
    p = string_tolower(s2);
    assert(strncmp(s2, "hello world", sizeof(s2)) == 0);
    assert(strncmp(p, "hello world", sizeof(s2)) == 0);

    char s3[32] = "!@#$123Abc";
    p = string_tolower(s3);
    assert(strncmp(s3, "!@#$123abc", sizeof(s3)) == 0);
    assert(strncmp(p, "!@#$123abc", sizeof(s3)) == 0);

    char s4[] = "";
    p = string_tolower(s4);
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    char s5[] = "\n\t\0";
    p = string_tolower(s5);
    assert(strncmp(s5, "\n\t\0", sizeof(s5)) == 0);
    assert(strncmp(p, "\n\t\0", sizeof(s5)) == 0);
}

void test_string_toupper() {
    char *p = NULL;

    char s1[] = "hello";
    p = string_toupper(s1);
    assert(strncmp(s1, "HELLO", sizeof(s1)) == 0);
    assert(strncmp(p, "HELLO", sizeof(s1)) == 0);

    char s2[16] = "HeLlO WoRlD";
    p = string_toupper(s2);
    assert(strncmp(s2, "HELLO WORLD", sizeof(s2)) == 0);
    assert(strncmp(p, "HELLO WORLD", sizeof(s2)) == 0);

    char s3[32] = "!@#$123Abc";
    p = string_toupper(s3);
    assert(strncmp(s3, "!@#$123ABC", sizeof(s3)) == 0);
    assert(strncmp(p, "!@#$123ABC", sizeof(s3)) == 0);

    char s4[] = "";
    p = string_toupper(s4);
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    char s5[] = "\n\t\0";
    p = string_toupper(s5);
    assert(strncmp(s5, "\n\t\0", sizeof(s5)) == 0);
    assert(strncmp(p, "\n\t\0", sizeof(s5)) == 0);
}

void test_string_starts_with() {
    assert(string_starts_with("hello", "hell"));
    assert(string_starts_with("Hello World!", "Hello W"));
    assert(string_starts_with("This is a test.", "This is a test."));
    assert(!string_starts_with("hello", "HE"));
    assert(string_starts_with("123ABC", "1"));
    assert(string_starts_with("\n\t\0", "\n"));
    assert(string_starts_with(NULL, NULL));
    assert(!string_starts_with(NULL, "\0"));
    assert(!string_starts_with("\0", NULL));
    assert(!string_starts_with("   ", "\t"));
    assert(string_starts_with("  XYZ", " "));
    assert(!string_starts_with("Lorem ipsum", "Lorem ipsum dolor sit amet"));
    assert(string_starts_with("Lorem ipsum", ""));
}

void test_string_ends_with() {
    assert(string_ends_with("hello", "ello"));
    assert(string_ends_with("Hello World!", "rld!"));
    assert(string_ends_with("This is a test.", "This is a test."));
    assert(string_ends_with("hello", "o"));
    assert(string_ends_with("123ABC", "BC"));
    assert(string_ends_with("\n\t\0", "\0"));
    assert(string_ends_with(NULL, NULL));
    assert(!string_ends_with(NULL, "\0"));
    assert(!string_ends_with("\0", NULL));
    assert(!string_ends_with("   ", "\t"));
    assert(string_ends_with("XYZ  ", "Z  "));
    assert(!string_ends_with("Lorem ipsum", "Lorem ipsum dolor sit amet"));
    assert(string_ends_with("Lorem ipsum", ""));
}

void test_string_clear() {
    char s1[] = "hello world!";
    string_clear(s1, sizeof(s1));
    assert(strlen(s1) == 0);

    char s2[32];
    string_clear(s2, sizeof(s2));
    assert(strlen(s1) == 0);
}

void test_string_length() {
    assert(string_length("") == 0);
    assert(string_length(NULL) == 0);
    assert(string_length("\n\t") == 2);
    assert(string_length("ABC\nabc\0XYZ") == 7);

    char s1[] = "hello world!";
    assert(string_length(s1) == 12);

    char s2[32] = "This is a test";
    assert(string_length(s2) == 14);

    const char *s3 = "!@#$^&*()";
    assert(string_length(s3) == 9);
}

void test_string_copy() {
    char *p = NULL;

    char s1[] = "hello";
    char s2[] = "world";
    p = string_copy(s1, s2);
    assert(strncmp(s1, "world", sizeof(s1)) == 0);
    assert(strncmp(s2, "world", sizeof(s2)) == 0);
    assert(strncmp(p, "world", sizeof(s1)) == 0);

    char s3[32] = {0};
    char *s4 = "This is a test.";
    p = string_copy(s3, s4);
    assert(strncmp(s3, "This is a test.", sizeof(s3)) == 0);
    assert(strncmp(s4, "This is a test.", strlen("This is a test.")) == 0);
    assert(strncmp(p, "This is a test.", sizeof(s3)) == 0);

    char s5[16] = "Lorem ipsum";
    char *s6 = "test";
    p = string_copy(s5, s6);
    assert(strncmp(s5, "test", sizeof(s5)) == 0);
    assert(strncmp(s6, "test", strlen("test")) == 0);
    assert(strncmp(p, "test", sizeof(s5)) == 0);

    p = string_copy(NULL, "test");
    assert(!p);

    char s7[16] = "Lorem ipsum";
    p = string_copy(s7, NULL);
    assert(strncmp(s7, "Lorem ipsum", sizeof(s7)) == 0);
    assert(strncmp(p, "Lorem ipsum", sizeof(s7)) == 0);
}

void test_string_concat() {
    char *p = NULL;

    char s1[11] = "hello";
    char s2[] = "world";
    p = string_concat(s1, s2);
    assert(strncmp(s1, "helloworld", sizeof(s1)) == 0);
    assert(strncmp(s2, "world", sizeof(s2)) == 0);
    assert(strncmp(p, "helloworld", sizeof(s1)) == 0);

    char s3[32] = {0};
    char *s4 = "This is a test.";
    p = string_concat(s3, s4);
    assert(strncmp(s3, "This is a test.", sizeof(s3)) == 0);
    assert(strncmp(s4, "This is a test.", strlen("This is a test.")) == 0);
    assert(strncmp(p, "This is a test.", sizeof(s3)) == 0);

    char s5[16] = "Lorem ipsum";
    char *s6 = "test";
    p = string_concat(s5, s6);
    assert(strncmp(s5, "Lorem ipsumtest", sizeof(s5)) == 0);
    assert(strncmp(s6, "test", strlen("test")) == 0);
    assert(strncmp(p, "Lorem ipsumtest", sizeof(s5)) == 0);

    p = string_concat(NULL, "test");
    assert(!p);

    char s7[16] = "Lorem ipsum";
    p = string_concat(s7, NULL);
    assert(strncmp(s7, "Lorem ipsum", sizeof(s7)) == 0);
    assert(strncmp(p, "Lorem ipsum", sizeof(s7)) == 0);
}

void test_string_trim() {
    char *p = NULL;

    char s1[8] = " hello";
    p = string_trim(s1);
    assert(strncmp(s1, "hello", sizeof(s1)) == 0);
    assert(strncmp(p, "hello", sizeof(s1)) == 0);

    char s2[8] = "hello ";
    p = string_trim(s2);
    assert(strncmp(s2, "hello", sizeof(s2)) == 0);
    assert(strncmp(p, "hello", sizeof(s2)) == 0);

    char s3[8] = " hello ";
    p = string_trim(s3);
    assert(strncmp(s3, "hello", sizeof(s3)) == 0);
    assert(strncmp(p, "hello", sizeof(s3)) == 0);

    char s4[32] = "   hello        ";
    p = string_trim(s4);
    assert(strncmp(s4, "hello", sizeof(s4)) == 0);
    assert(strncmp(p, "hello", sizeof(s4)) == 0);

    char s5[32] = "\nhello        ";
    p = string_trim(s5);
    assert(strncmp(s5, "hello", sizeof(s5)) == 0);
    assert(strncmp(p, "hello", sizeof(s5)) == 0);

    char s6[32] = "\t  hello  \n   \t \n      ";
    p = string_trim(s6);
    assert(strncmp(s6, "hello", sizeof(s6)) == 0);
    assert(strncmp(p, "hello", sizeof(s6)) == 0);

    char s7[8] = "hello";
    p = string_trim(s7);
    assert(strncmp(s7, "hello", sizeof(s7)) == 0);
    assert(strncmp(p, "hello", sizeof(s7)) == 0);

    char s8[16] = "        ";
    p = string_trim(s8);
    assert(strncmp(s8, "", sizeof(s8)) == 0);
    assert(strncmp(p, "", sizeof(s8)) == 0);

    char s9[16] = "\n\t\r\n\r\n\r\t";
    p = string_trim(s9);
    assert(strncmp(s9, "", sizeof(s9)) == 0);
    assert(strncmp(p, "", sizeof(s9)) == 0);

    p = string_trim(NULL);
    assert(!p);
}

void test_string_append_char() {
    char *p = NULL;

    char s1[11] = "hello";
    p = string_append_char(s1, 'X');
    assert(strncmp(s1, "helloX", sizeof(s1)) == 0);
    assert(strncmp(p, "helloX", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = string_append_char(s2, ' ');
    assert(strncmp(s2, " ", sizeof(s2)) == 0);
    assert(strncmp(p, " ", sizeof(s2)) == 0);

    char s3[16] = "Lorem ipsum";
    char c = '\t';
    p = string_append_char(s3, c);
    assert(strncmp(s3, "Lorem ipsum\t", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum\t", sizeof(s3)) == 0);

    p = string_append_char(NULL, '!');
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = string_append_char(s4, '.');
    assert(strncmp(s4, "Lorem ipsum.", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum.", sizeof(s4)) == 0);
}

void test_string_append_int() {
    char *p = NULL;

    char s1[11] = "hello";
    p = string_append_int(s1, 123);
    assert(strncmp(s1, "hello123", sizeof(s1)) == 0);
    assert(strncmp(p, "hello123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = string_append_int(s2, -987);
    assert(strncmp(s2, "-987", sizeof(s2)) == 0);
    assert(strncmp(p, "-987", sizeof(s2)) == 0);

    char s3[32] = "Lorem ipsum";
    p = string_append_int(s3, 2147483647);
    assert(strncmp(s3, "Lorem ipsum2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum2147483647", sizeof(s3)) == 0);

    p = string_append_int(NULL, 0);
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = string_append_int(s4, 3.14);
    assert(strncmp(s4, "Lorem ipsum3", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum3", sizeof(s4)) == 0);

    char s5[32] = "Lorem ipsum";
    p = string_append_int(s5, -2147483648);
    assert(strncmp(s5, "Lorem ipsum-2147483648", sizeof(s5)) == 0);
    assert(strncmp(p, "Lorem ipsum-2147483648", sizeof(s5)) == 0);
}

void test_string_append_double() {
    char *p = NULL;

    char s1[11] = "hello";
    p = string_append_double(s1, 123, 0);
    assert(strncmp(s1, "hello123", sizeof(s1)) == 0);
    assert(strncmp(p, "hello123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = string_append_double(s2, -987, 5);
    assert(strncmp(s2, "-987.00000", sizeof(s2)) == 0);
    assert(strncmp(p, "-987.00000", sizeof(s2)) == 0);

    char s3[32] = "Lorem ipsum";
    p = string_append_double(s3, 3.141, 16);
    assert(strncmp(s3, "Lorem ipsum3.1410000000000000", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum3.1410000000000000", sizeof(s3)) == 0);

    p = string_append_double(NULL, 0, -1);
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = string_append_double(s4, -2.7172, 2);
    assert(strncmp(s4, "Lorem ipsum-2.72", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum-2.72", sizeof(s4)) == 0);

    char s5[32] = "Lorem ipsum";
    p = string_append_double(s5, 0.00001, 0);
    assert(strncmp(s5, "Lorem ipsum0", sizeof(s5)) == 0);
    assert(strncmp(p, "Lorem ipsum0", sizeof(s5)) == 0);

    char s6[32] = "This is a test";
    p = string_append_double(s6, -12.34567, -2);
    assert(strncmp(s6, "This is a test-12.35", sizeof(s6)) == 0);
    assert(strncmp(p, "This is a test-12.35", sizeof(s6)) == 0);
}

void test_string_insert_char() {
    const char *p = NULL;

    char s1[8] = "ello";
    p = string_insert_char(s1, 0, 'H');
    assert(strncmp(s1, "Hello", sizeof(s1)) == 0);
    assert(strncmp(p, "Hello", sizeof(s1)) == 0);

    char s2[8] = "Hello";
    p = string_insert_char(s2, strlen(s2), 'o');
    assert(strncmp(s2, "Helloo", sizeof(s2)) == 0);
    assert(strncmp(p, "Helloo", sizeof(s2)) == 0);

    char s3[8] = "Hello";
    p = string_insert_char(s3, 3, 'l');
    assert(strncmp(s3, "Helllo", sizeof(s3)) == 0);
    assert(strncmp(p, "Helllo", sizeof(s3)) == 0);

    char s4[8] = "Hello";
    p = string_insert_char(s4, 1, '\n');
    assert(strncmp(s4, "H\nello", sizeof(s4)) == 0);
    assert(strncmp(p, "H\nello", sizeof(s4)) == 0);

    char s5[8] = "Hello";
    p = string_insert_char(s5, 0, '\0');
    assert(strncmp(s5, "", sizeof(s5)) == 0);
    assert(strncmp(p, "", sizeof(s5)) == 0);

    char s6[8] = "Hello";
    p = string_insert_char(s6, strlen(s6) - 1, '\0');
    assert(strncmp(s6, "Hell", sizeof(s6)) == 0);
    assert(strncmp(p, "Hell", sizeof(s6)) == 0);

    char s7[8] = {0};
    p = string_insert_char(s7, 0, 'A');
    assert(strncmp(s7, "A", sizeof(s7)) == 0);
    assert(strncmp(p, "A", sizeof(s7)) == 0);

    char s8[8] = "Test";
    p = string_insert_char(s8, 5, 's');
    assert(strncmp(s8, "Test", sizeof(s8)) == 0);
    assert(strncmp(p, "Test", sizeof(s8)) == 0);

    p = string_insert_char(NULL, 0, 's');
    assert(!p);
}

void test_string_insert_string() {
    char *p = NULL;

    char s1[16] = "World";
    p = string_insert_string(s1, 0, "Hello");
    assert(strncmp(s1, "HelloWorld", sizeof(s1)) == 0);
    assert(strncmp(p, "HelloWorld", sizeof(s1)) == 0);

    char s2[16] = "Hello";
    p = string_insert_string(s2, strlen(s2), "World");
    assert(strncmp(s2, "HelloWorld", sizeof(s2)) == 0);
    assert(strncmp(p, "HelloWorld", sizeof(s2)) == 0);

    char s3[8] = "Hello";
    p = string_insert_string(s3, strlen(s3), "!");
    assert(strncmp(s3, "Hello!", sizeof(s3)) == 0);
    assert(strncmp(p, "Hello!", sizeof(s3)) == 0);

    char s4[8] = "Hello";
    p = string_insert_string(s4, 1, "He");
    assert(strncmp(s4, "HHeello", sizeof(s4)) == 0);
    assert(strncmp(p, "HHeello", sizeof(s4)) == 0);

    char s5[32] = "Hello";
    p = string_insert_string(s5, 2, "This is a test.");
    assert(strncmp(s5, "HeThis is a test.llo", sizeof(s5)) == 0);
    assert(strncmp(p, "HeThis is a test.llo", sizeof(s5)) == 0);

    char s6[8] = "Hello";
    p = string_insert_string(s6, strlen(s6) - 1, "\n\t");
    assert(strncmp(s6, "Hell\n\to", sizeof(s6)) == 0);
    assert(strncmp(p, "Hell\n\to", sizeof(s6)) == 0);

    char s7[8] = {0};
    p = string_insert_string(s7, 0, "A");
    assert(strncmp(s7, "A", sizeof(s7)) == 0);
    assert(strncmp(p, "A", sizeof(s7)) == 0);

    char s8[8] = "Test";
    p = string_insert_string(s8, 5, "s");
    assert(strncmp(s8, "Test", sizeof(s8)) == 0);
    assert(strncmp(p, "Test", sizeof(s8)) == 0);

    p = string_insert_string(NULL, 0, "s");
    assert(!p);
}