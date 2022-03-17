#include "test_cino_utils.h"
#include "cino_utils.h"

void test_min() {
    assert(min(5, 2) == 2);
    assert(min(2, 2) == 2);
    assert(min(-5, -2) == -5);
    assert(min(0, 2) == 0);
    assert(min(3.1415, 3.1416) == 3.1415);
    assert(min('a', 'b') == 'a');
    assert(min('X', 'H') == 'H');
    assert(min('A', 'a') == 'A');
    assert(min('z', 'Z') == 'Z');
}

void test_max() {
    assert(max(5, 2) == 5);
    assert(max(2, 2) == 2);
    assert(max(-5, -2) == -2);
    assert(max(0, 2) == 2);
    assert(max(3.1415, 3.1416) == 3.1416);
    assert(max('a', 'b') == 'b');
    assert(max('X', 'H') == 'X');
    assert(max('A', 'a') == 'a');
    assert(max('z', 'Z') == 'z');
}

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

void test_str_to_bool() {
    assert(!str_to_bool(NULL));
    assert(!str_to_bool(""));
    assert(!str_to_bool("False"));
    assert(!str_to_bool("false"));
    assert(!str_to_bool("FALSE"));
    assert(!str_to_bool("fALse"));
    assert(!str_to_bool("0"));
    assert(!str_to_bool("000000000"));

    assert(str_to_bool("true"));
    assert(str_to_bool("-0"));
    assert(str_to_bool("false_but_true"));
    assert(str_to_bool("123"));

    const char *s1 = NULL;
    assert(!str_to_bool(s1));

    const char *s2 = "!@#$";
    assert(str_to_bool(s2));
}

void test_bool_to_str() {
    assert(strncmp(bool_to_str(true), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_str(false), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_str(1), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_str(0), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_str(0.0), "false", strlen("false")) == 0);
    assert(strncmp(bool_to_str(123), "true", strlen("true")) == 0);
    assert(strncmp(bool_to_str(-0), "false", strlen("false")) == 0);
}

void test_str_to_char() {
    char s1[] = "A";
    assert(str_to_char(s1) == 'A');

    char s2[8] = "25X13";
    assert(str_to_char(s2) == '2');

    const char *s3 = "@.!#$)";
    assert(str_to_char(s3) == '@');

    assert(str_to_char(" ") == ' ');
    assert(str_to_char("\n") == '\n');
    assert(str_to_char("\t") == '\t');
    assert(str_to_char(NULL) == '\0');
    assert(str_to_char("") == '\0');
}

void test_char_to_str() {
    char *p = NULL;

    char s1[8] = {0};
    p = char_to_str('H', s1, sizeof(s1));
    assert(strncmp(s1, "H", sizeof(s1)) == 0);
    assert(strncmp(p, "H", sizeof(s1)) == 0);

    char s2[8] = "Hello";
    p = char_to_str('2', s2, sizeof(s2));
    assert(strncmp(s2, "2", sizeof(s2)) == 0);
    assert(strncmp(p, "2", sizeof(s2)) == 0);

    char s3[2] = "#";
    p = char_to_str('!', s3, sizeof(s3));
    assert(strncmp(s3, "!", sizeof(s3)) == 0);
    assert(strncmp(p, "!", sizeof(s3)) == 0);

    char s4[3] = "";
    p = char_to_str('\0', s4, sizeof(s4));
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    p = char_to_str('\0', NULL, 0);
    assert(!p);
}

void test_str_to_int() {
    assert(str_to_int("123") == 123);
    assert(str_to_int("-123") == -123);
    assert(str_to_int("0") == 0);
    assert(str_to_int("+0") == 0);
    assert(str_to_int("-0") == 0);
    assert(str_to_int("3.14") == 3);
    assert(str_to_int("2.717") == 2);
    assert(str_to_int("-3.14") == -3);
    assert(str_to_int("2147483647") == 2147483647);
    assert(str_to_int("-2147483648") == -2147483648);
}

void test_int_to_str() {
    char *p = NULL;

    char s1[4] = {0};
    p = int_to_str(123, s1, sizeof(s1));
    assert(strncmp(s1, "123", sizeof(s1)) == 0);
    assert(strncmp(p, "123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = int_to_str(-987, s2, sizeof(s2));
    assert(strncmp(s2, "-987", sizeof(s2)) == 0);
    assert(strncmp(p, "-987", sizeof(s2)) == 0);

    char s3[12] = {0};
    p = int_to_str(2147483647, s3, sizeof(s3));
    assert(strncmp(s3, "2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "2147483647", sizeof(s3)) == 0);

    char s4[13] = {0};
    p = int_to_str(-2147483648, s4, sizeof(s4));
    assert(strncmp(s4, "-2147483648", sizeof(s4)) == 0);
    assert(strncmp(p, "-2147483648", sizeof(s4)) == 0);

    char *s5 = (char *)malloc(sizeof(char) * 5);
    p = int_to_str(3.14, s5, 5);
    assert(strncmp(s5, "3", strlen("3")) == 0);
    assert(strncmp(p, "3", strlen("3")) == 0);
    free(s5);

    char *s6 = (char *)malloc(sizeof(char) * 5);
    p = int_to_str(-2.717, s6, 5);
    assert(strncmp(s6, "-2", strlen("-2")) == 0);
    assert(strncmp(p, "-2", strlen("-2")) == 0);
    free(s6);

    p = int_to_str(0, NULL, 0);
    assert(!p);
}

void test_str_to_double() {
    const double EPS = 1e-6;  // 用于比较浮点数的精度

    assert(fabs(str_to_double("123") - 123.0) <= EPS);
    assert(fabs(str_to_double("-123") - (-123.0)) <= EPS);
    assert(fabs(str_to_double("0") - 0.0) <= EPS);
    assert(fabs(str_to_double("+0") - 0.0) <= EPS);
    assert(fabs(str_to_double("-0") - 0.0) <= EPS);
    assert(fabs(str_to_double("3.14") - 3.14) <= EPS);
    assert(fabs(str_to_double("2.717") - 2.717) <= EPS);
    assert(fabs(str_to_double("-3.14") - (-3.14)) <= EPS);
    assert(fabs(str_to_double("2147483647") - 2147483647.0) <= EPS);
    assert(fabs(str_to_double("-2147483648") - (-2147483648.0)) <= EPS);
    assert(fabs(str_to_double("0.00") - 0.0) <= EPS);
    assert(fabs(str_to_double("3.1415926") - 3.1415926) <= EPS);
    assert(fabs(str_to_double("1e2") - 100.0) <= EPS);
    assert(fabs(str_to_double("-2.3e4") - (-23000.0)) <= EPS);
}

void test_double_to_str() {
    char *p = NULL;

    char s1[6] = {0};
    p = double_to_str(123, 1, s1, sizeof(s1));
    assert(strncmp(s1, "123.0", sizeof(s1)) == 0);
    assert(strncmp(p, "123.0", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = double_to_str(-987, 4, s2, sizeof(s2));
    assert(strncmp(s2, "-987.0000", sizeof(s2)) == 0);
    assert(strncmp(p, "-987.0000", sizeof(s2)) == 0);

    char s3[16] = {0};
    p = double_to_str(2147483647, 0, s3, sizeof(s3));
    assert(strncmp(s3, "2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "2147483647", sizeof(s3)) == 0);

    char s4[16] = {0};
    p = double_to_str(-3.141592, 4, s4, sizeof(s4));
    assert(strncmp(s4, "-3.1416", sizeof(s4)) == 0);
    assert(strncmp(p, "-3.1416", sizeof(s4)) == 0);

    char *s5 = (char *)malloc(sizeof(char) * 5);
    p = double_to_str(3.14, 1, s5, 5);
    assert(strncmp(s5, "3.1", strlen("3.1")) == 0);
    assert(strncmp(p, "3.1", strlen("3.1")) == 0);
    free(s5);

    char *s6 = (char *)malloc(sizeof(char) * 8);
    p = double_to_str(2.717, 0, s6, 5);
    assert(strncmp(s6, "3", strlen("3")) == 0);
    assert(strncmp(p, "3", strlen("3")) == 0);
    free(s6);

    char *s7 = (char *)malloc(sizeof(char) * 8);
    p = double_to_str(1e2, 3, s7, 8);
    assert(strncmp(s7, "100.000", strlen("100.000")) == 0);
    assert(strncmp(p, "100.000", strlen("100.000")) == 0);
    free(s7);

    char *s8 = (char *)malloc(sizeof(char) * 32);
    p = double_to_str(-2.71e7, 2, s8, 32);
    assert(strncmp(s8, "-27100000.00", strlen("-27100000.00")) == 0);
    assert(strncmp(p, "-27100000.00", strlen("-27100000.00")) == 0);
    free(s8);

    p = double_to_str(0, -1, NULL, 0);
    assert(!p);
}

void test_str_equal() {
    assert(str_equal("hello", "hello"));
    assert(str_equal("Hello", "Hello"));
    assert(str_equal("", ""));
    assert(str_equal("ABCDabcd", "ABCDabcd"));
    assert(str_equal("12345", "12345"));
    assert(str_equal("abc", "abc"));
    assert(str_equal("   ", "   "));
    assert(str_equal("\n", "\n"));

    const char *s1 = "XYZ";
    const char *s2 = "XYZ";
    assert(str_equal(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!str_equal(s1, s2));

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(str_equal(s3, s4));

    assert(str_equal(NULL, NULL));
    assert(!str_equal("", NULL));
    assert(!str_equal(NULL, ""));
}

void test_str_equal_ignore_case() {
    assert(str_equal_ignore_case("hello", "hello"));
    assert(str_equal_ignore_case("Hello", "hElLo"));
    assert(str_equal_ignore_case("", ""));
    assert(str_equal_ignore_case("ABCDabcd", "abcdABCD"));
    assert(str_equal_ignore_case("12345", "12345"));
    assert(!str_equal_ignore_case("abc", "cba"));
    assert(!str_equal_ignore_case("  ", "    "));
    assert(!str_equal_ignore_case("\n", "\t"));

    const char *s1 = "XYZ";
    const char *s2 = "xYz";
    assert(str_equal_ignore_case(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!str_equal_ignore_case(s1, s2));

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(str_equal_ignore_case(s3, s4));

    assert(str_equal_ignore_case(NULL, NULL));
    assert(!str_equal_ignore_case("", NULL));
    assert(!str_equal_ignore_case(NULL, ""));
}

void test_str_to_lower() {
    char *p = NULL;

    char s1[] = "HELLO";
    p = str_to_lower(s1);
    assert(strncmp(s1, "hello", sizeof(s1)) == 0);
    assert(strncmp(p, "hello", sizeof(s1)) == 0);

    char s2[16] = "HeLlO WoRlD";
    p = str_to_lower(s2);
    assert(strncmp(s2, "hello world", sizeof(s2)) == 0);
    assert(strncmp(p, "hello world", sizeof(s2)) == 0);

    char s3[32] = "!@#$123Abc";
    p = str_to_lower(s3);
    assert(strncmp(s3, "!@#$123abc", sizeof(s3)) == 0);
    assert(strncmp(p, "!@#$123abc", sizeof(s3)) == 0);

    char s4[] = "";
    p = str_to_lower(s4);
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    char s5[] = "\n\t\0";
    p = str_to_lower(s5);
    assert(strncmp(s5, "\n\t\0", sizeof(s5)) == 0);
    assert(strncmp(p, "\n\t\0", sizeof(s5)) == 0);
}

void test_str_to_upper() {
    char *p = NULL;

    char s1[] = "hello";
    p = str_to_upper(s1);
    assert(strncmp(s1, "HELLO", sizeof(s1)) == 0);
    assert(strncmp(p, "HELLO", sizeof(s1)) == 0);

    char s2[16] = "HeLlO WoRlD";
    p = str_to_upper(s2);
    assert(strncmp(s2, "HELLO WORLD", sizeof(s2)) == 0);
    assert(strncmp(p, "HELLO WORLD", sizeof(s2)) == 0);

    char s3[32] = "!@#$123Abc";
    p = str_to_upper(s3);
    assert(strncmp(s3, "!@#$123ABC", sizeof(s3)) == 0);
    assert(strncmp(p, "!@#$123ABC", sizeof(s3)) == 0);

    char s4[] = "";
    p = str_to_upper(s4);
    assert(strncmp(s4, "", sizeof(s4)) == 0);
    assert(strncmp(p, "", sizeof(s4)) == 0);

    char s5[] = "\n\t\0";
    p = str_to_upper(s5);
    assert(strncmp(s5, "\n\t\0", sizeof(s5)) == 0);
    assert(strncmp(p, "\n\t\0", sizeof(s5)) == 0);
}

void test_str_starts_with() {
    assert(str_starts_with("hello", "hell"));
    assert(str_starts_with("Hello World!", "Hello W"));
    assert(str_starts_with("This is a test.", "This is a test."));
    assert(!str_starts_with("hello", "HE"));
    assert(str_starts_with("123ABC", "1"));
    assert(str_starts_with("\n\t\0", "\n"));
    assert(str_starts_with(NULL, NULL));
    assert(!str_starts_with(NULL, "\0"));
    assert(!str_starts_with("\0", NULL));
    assert(!str_starts_with("   ", "\t"));
    assert(str_starts_with("  XYZ", " "));
    assert(!str_starts_with("Lorem ipsum", "Lorem ipsum dolor sit amet"));
    assert(str_starts_with("Lorem ipsum", ""));
}

void test_str_ends_with() {
    assert(str_ends_with("hello", "ello"));
    assert(str_ends_with("Hello World!", "rld!"));
    assert(str_ends_with("This is a test.", "This is a test."));
    assert(str_ends_with("hello", "o"));
    assert(str_ends_with("123ABC", "BC"));
    assert(str_ends_with("\n\t\0", "\0"));
    assert(str_ends_with(NULL, NULL));
    assert(!str_ends_with(NULL, "\0"));
    assert(!str_ends_with("\0", NULL));
    assert(!str_ends_with("   ", "\t"));
    assert(str_ends_with("XYZ  ", "Z  "));
    assert(!str_ends_with("Lorem ipsum", "Lorem ipsum dolor sit amet"));
    assert(str_ends_with("Lorem ipsum", ""));
}

void test_str_clear() {
    char s1[] = "hello world!";
    str_clear(s1, sizeof(s1));
    assert(strlen(s1) == 0);

    char s2[32];
    str_clear(s2, sizeof(s2));
    assert(strlen(s1) == 0);
}

void test_str_length() {
    assert(str_length("") == 0);
    assert(str_length(NULL) == 0);
    assert(str_length("\n\t") == 2);
    assert(str_length("ABC\nabc\0XYZ") == 7);

    char s1[] = "hello world!";
    assert(str_length(s1) == 12);

    char s2[32] = "This is a test";
    assert(str_length(s2) == 14);

    const char *s3 = "!@#$^&*()";
    assert(str_length(s3) == 9);
}

void test_str_copy() {
    char *p = NULL;

    char s1[] = "hello";
    char s2[] = "world";
    p = str_copy(s1, s2);
    assert(strncmp(s1, s2, sizeof(s1)) == 0);
    assert(strncmp(s2, "world", sizeof(s2)) == 0);
    assert(strncmp(p, s1, sizeof(s1)) == 0);

    char s3[32] = {0};
    char *s4 = "This is a test.";
    p = str_copy(s3, s4);
    assert(strncmp(s3, s4, sizeof(s3)) == 0);
    assert(strncmp(s4, "This is a test.", strlen("This is a test.")) == 0);
    assert(strncmp(p, s3, sizeof(s3)) == 0);

    char s5[16] = "Lorem ipsum";
    char *s6 = "test";
    p = str_copy(s5, s6);
    assert(strncmp(s5, s6, sizeof(s5)) == 0);
    assert(strncmp(s6, "test", strlen("test")) == 0);
    assert(strncmp(p, s5, sizeof(s5)) == 0);

    p = str_copy(NULL, "test");
    assert(!p);

    char s7[16] = "Lorem ipsum";
    p = str_copy(s7, NULL);
    assert(strncmp(s7, "Lorem ipsum", sizeof(s7)) == 0);
    assert(strncmp(p, s7, sizeof(s7)) == 0);
}

void test_str_concat() {
    char *p = NULL;

    char s1[11] = "hello";
    char s2[] = "world";
    p = str_concat(s1, s2);
    assert(strncmp(s1, "helloworld", sizeof(s1)) == 0);
    assert(strncmp(s2, "world", sizeof(s2)) == 0);
    assert(strncmp(p, s1, sizeof(s1)) == 0);

    char s3[32] = {0};
    char *s4 = "This is a test.";
    p = str_concat(s3, s4);
    assert(strncmp(s3, "This is a test.", sizeof(s3)) == 0);
    assert(strncmp(s4, "This is a test.", strlen("This is a test.")) == 0);
    assert(strncmp(p, s3, sizeof(s3)) == 0);

    char s5[16] = "Lorem ipsum";
    char *s6 = "test";
    p = str_concat(s5, s6);
    assert(strncmp(s5, "Lorem ipsumtest", sizeof(s5)) == 0);
    assert(strncmp(s6, "test", strlen("test")) == 0);
    assert(strncmp(p, s5, sizeof(s5)) == 0);

    p = str_concat(NULL, "test");
    assert(!p);

    char s7[16] = "Lorem ipsum";
    p = str_concat(s7, NULL);
    assert(strncmp(s7, "Lorem ipsum", sizeof(s7)) == 0);
    assert(strncmp(p, s7, sizeof(s7)) == 0);
}

void test_str_trim() {
    char *p = NULL;

    char s1[8] = " hello";
    p = str_trim(s1);
    assert(strncmp(s1, "hello", sizeof(s1)) == 0);
    assert(strncmp(p, "hello", sizeof(s1)) == 0);

    char s2[8] = "hello ";
    p = str_trim(s2);
    assert(strncmp(s2, "hello", sizeof(s2)) == 0);
    assert(strncmp(p, "hello", sizeof(s2)) == 0);

    char s3[8] = " hello ";
    p = str_trim(s3);
    assert(strncmp(s3, "hello", sizeof(s3)) == 0);
    assert(strncmp(p, "hello", sizeof(s3)) == 0);

    char s4[32] = "   hello        ";
    p = str_trim(s4);
    assert(strncmp(s4, "hello", sizeof(s4)) == 0);
    assert(strncmp(p, "hello", sizeof(s4)) == 0);

    char s5[32] = "\nhello        ";
    p = str_trim(s5);
    assert(strncmp(s5, "hello", sizeof(s5)) == 0);
    assert(strncmp(p, "hello", sizeof(s5)) == 0);

    char s6[32] = "\t  hello  \n   \t \n      ";
    p = str_trim(s6);
    assert(strncmp(s6, "hello", sizeof(s6)) == 0);
    assert(strncmp(p, "hello", sizeof(s6)) == 0);

    char s7[8] = "hello";
    p = str_trim(s7);
    assert(strncmp(s7, "hello", sizeof(s7)) == 0);
    assert(strncmp(p, "hello", sizeof(s7)) == 0);

    char s8[16] = "        ";
    p = str_trim(s8);
    assert(strncmp(s8, "", sizeof(s8)) == 0);
    assert(strncmp(p, "", sizeof(s8)) == 0);

    char s9[16] = "\n\t\r\n\r\n\r\t";
    p = str_trim(s9);
    assert(strncmp(s9, "", sizeof(s9)) == 0);
    assert(strncmp(p, "", sizeof(s9)) == 0);

    p = str_trim(NULL);
    assert(!p);
}

void test_str_append_char() {
    char *p = NULL;

    char s1[11] = "hello";
    p = str_append_char(s1, 'X');
    assert(strncmp(s1, "helloX", sizeof(s1)) == 0);
    assert(strncmp(p, "helloX", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = str_append_char(s2, ' ');
    assert(strncmp(s2, " ", sizeof(s2)) == 0);
    assert(strncmp(p, " ", sizeof(s2)) == 0);

    char s3[16] = "Lorem ipsum";
    char c = '\t';
    p = str_append_char(s3, c);
    assert(strncmp(s3, "Lorem ipsum\t", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum\t", sizeof(s3)) == 0);

    p = str_append_char(NULL, '!');
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = str_append_char(s4, '.');
    assert(strncmp(s4, "Lorem ipsum.", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum.", sizeof(s4)) == 0);
}

void test_str_append_int() {
    char *p = NULL;

    char s1[11] = "hello";
    p = str_append_int(s1, 123);
    assert(strncmp(s1, "hello123", sizeof(s1)) == 0);
    assert(strncmp(p, "hello123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = str_append_int(s2, -987);
    assert(strncmp(s2, "-987", sizeof(s2)) == 0);
    assert(strncmp(p, "-987", sizeof(s2)) == 0);

    char s3[32] = "Lorem ipsum";
    p = str_append_int(s3, 2147483647);
    assert(strncmp(s3, "Lorem ipsum2147483647", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum2147483647", sizeof(s3)) == 0);

    p = str_append_int(NULL, 0);
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = str_append_int(s4, 3.14);
    assert(strncmp(s4, "Lorem ipsum3", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum3", sizeof(s4)) == 0);

    char s5[32] = "Lorem ipsum";
    p = str_append_int(s5, -2147483648);
    assert(strncmp(s5, "Lorem ipsum-2147483648", sizeof(s5)) == 0);
    assert(strncmp(p, "Lorem ipsum-2147483648", sizeof(s5)) == 0);
}

void test_str_append_double() {
    char *p = NULL;

    char s1[11] = "hello";
    p = str_append_double(s1, 123, 0);
    assert(strncmp(s1, "hello123", sizeof(s1)) == 0);
    assert(strncmp(p, "hello123", sizeof(s1)) == 0);

    char s2[32] = {0};
    p = str_append_double(s2, -987, 5);
    assert(strncmp(s2, "-987.00000", sizeof(s2)) == 0);
    assert(strncmp(p, "-987.00000", sizeof(s2)) == 0);

    char s3[32] = "Lorem ipsum";
    p = str_append_double(s3, 3.141, 16);
    assert(strncmp(s3, "Lorem ipsum3.1410000000000000", sizeof(s3)) == 0);
    assert(strncmp(p, "Lorem ipsum3.1410000000000000", sizeof(s3)) == 0);

    p = str_append_double(NULL, 0, -1);
    assert(!p);

    char s4[16] = "Lorem ipsum";
    p = str_append_double(s4, -2.7172, 2);
    assert(strncmp(s4, "Lorem ipsum-2.72", sizeof(s4)) == 0);
    assert(strncmp(p, "Lorem ipsum-2.72", sizeof(s4)) == 0);

    char s5[32] = "Lorem ipsum";
    p = str_append_double(s5, 0.00001, 0);
    assert(strncmp(s5, "Lorem ipsum0", sizeof(s5)) == 0);
    assert(strncmp(p, "Lorem ipsum0", sizeof(s5)) == 0);

    char s6[32] = "This is a test";
    p = str_append_double(s6, -12.34567, -2);
    assert(strncmp(s6, "This is a test-12.35", sizeof(s6)) == 0);
    assert(strncmp(p, "This is a test-12.35", sizeof(s6)) == 0);
}

void test_str_insert_char() {
    const char *p = NULL;

    char s1[8] = "ello";
    p = str_insert_char(s1, 0, 'H');
    assert(strncmp(s1, "Hello", sizeof(s1)) == 0);
    assert(strncmp(p, "Hello", sizeof(s1)) == 0);

    char s2[8] = "Hello";
    p = str_insert_char(s2, strlen(s2), 'o');
    assert(strncmp(s2, "Helloo", sizeof(s2)) == 0);
    assert(strncmp(p, "Helloo", sizeof(s2)) == 0);

    char s3[8] = "Hello";
    p = str_insert_char(s3, 3, 'l');
    assert(strncmp(s3, "Helllo", sizeof(s3)) == 0);
    assert(strncmp(p, "Helllo", sizeof(s3)) == 0);

    char s4[8] = "Hello";
    p = str_insert_char(s4, 1, '\n');
    assert(strncmp(s4, "H\nello", sizeof(s4)) == 0);
    assert(strncmp(p, "H\nello", sizeof(s4)) == 0);

    char s5[8] = "Hello";
    p = str_insert_char(s5, 0, '\0');
    assert(strncmp(s5, "", sizeof(s5)) == 0);
    assert(strncmp(p, "", sizeof(s5)) == 0);

    char s6[8] = "Hello";
    p = str_insert_char(s6, strlen(s6) - 1, '\0');
    assert(strncmp(s6, "Hell", sizeof(s6)) == 0);
    assert(strncmp(p, "Hell", sizeof(s6)) == 0);

    char s7[8] = {0};
    p = str_insert_char(s7, 0, 'A');
    assert(strncmp(s7, "A", sizeof(s7)) == 0);
    assert(strncmp(p, "A", sizeof(s7)) == 0);

    char s8[8] = "Test";
    p = str_insert_char(s8, 5, 's');
    assert(strncmp(s8, "Test", sizeof(s8)) == 0);
    assert(strncmp(p, "Test", sizeof(s8)) == 0);

    p = str_insert_char(NULL, 0, 's');
    assert(!p);
}

void test_str_insert_string() {
    char *p = NULL;

    char s1[16] = "World";
    p = str_insert_string(s1, 0, "Hello");
    assert(strncmp(s1, "HelloWorld", sizeof(s1)) == 0);
    assert(strncmp(p, "HelloWorld", sizeof(s1)) == 0);

    char s2[16] = "Hello";
    p = str_insert_string(s2, strlen(s2), "World");
    assert(strncmp(s2, "HelloWorld", sizeof(s2)) == 0);
    assert(strncmp(p, "HelloWorld", sizeof(s2)) == 0);

    char s3[8] = "Hello";
    p = str_insert_string(s3, strlen(s3), "!");
    assert(strncmp(s3, "Hello!", sizeof(s3)) == 0);
    assert(strncmp(p, "Hello!", sizeof(s3)) == 0);

    char s4[8] = "Hello";
    p = str_insert_string(s4, 1, "He");
    assert(strncmp(s4, "HHeello", sizeof(s4)) == 0);
    assert(strncmp(p, "HHeello", sizeof(s4)) == 0);

    char s5[32] = "Hello";
    p = str_insert_string(s5, 2, "This is a test.");
    assert(strncmp(s5, "HeThis is a test.llo", sizeof(s5)) == 0);
    assert(strncmp(p, "HeThis is a test.llo", sizeof(s5)) == 0);

    char s6[8] = "Hello";
    p = str_insert_string(s6, strlen(s6) - 1, "\n\t");
    assert(strncmp(s6, "Hell\n\to", sizeof(s6)) == 0);
    assert(strncmp(p, "Hell\n\to", sizeof(s6)) == 0);

    char s7[8] = {0};
    p = str_insert_string(s7, 0, "A");
    assert(strncmp(s7, "A", sizeof(s7)) == 0);
    assert(strncmp(p, "A", sizeof(s7)) == 0);

    char s8[8] = "Test";
    p = str_insert_string(s8, 5, "s");
    assert(strncmp(s8, "Test", sizeof(s8)) == 0);
    assert(strncmp(p, "Test", sizeof(s8)) == 0);

    p = str_insert_string(NULL, 0, "s");
    assert(!p);
}

void test_str_substring() {
    char *p = NULL;
    char substr[32] = {0};

    char s1[8] = "hello";
    p = str_substring(s1, 0, 2, substr, sizeof(substr));
    assert(strncmp(s1, "hello", sizeof(s1)) == 0);
    assert(strncmp(substr, "hel", sizeof(substr)) == 0);
    assert(strncmp(p, "hel", sizeof(substr)) == 0);

    char s2[8] = "hello";
    p = str_substring(s2, 1, 3, substr, sizeof(substr));
    assert(strncmp(s2, "hello", sizeof(s2)) == 0);
    assert(strncmp(substr, "ell", sizeof(substr)) == 0);
    assert(strncmp(p, "ell", sizeof(substr)) == 0);

    char s3[8] = "hello";
    p = str_substring(s3, 0, 4, substr, sizeof(substr));
    assert(strncmp(s3, "hello", sizeof(s3)) == 0);
    assert(strncmp(substr, "hello", sizeof(substr)) == 0);
    assert(strncmp(p, "hello", sizeof(substr)) == 0);

    char s4[32] = "hello World!";
    p = str_substring(s4, 5, 99, substr, sizeof(substr));
    assert(strncmp(s4, "hello World!", sizeof(s4)) == 0);
    assert(strncmp(substr, " World!", sizeof(substr)) == 0);
    assert(strncmp(p, " World!", sizeof(substr)) == 0);

    char s5[32] = "hello World!";
    p = str_substring(s5, -99, 99, substr, sizeof(substr));
    assert(strncmp(s5, "hello World!", sizeof(s5)) == 0);
    assert(strncmp(substr, "hello World!", sizeof(substr)) == 0);
    assert(strncmp(p, "hello World!", sizeof(substr)) == 0);

    char s6[32] = "hello World!";
    p = str_substring(s6, 8, 2, substr, sizeof(substr));
    assert(strncmp(s6, "hello World!", sizeof(s6)) == 0);
    assert(strncmp(substr, "", sizeof(substr)) == 0);
    assert(strncmp(p, "", sizeof(substr)) == 0);

    char s7[32] = "hello World!";
    p = str_substring(s7, 7, 7, substr, sizeof(substr));
    assert(strncmp(s7, "hello World!", sizeof(s7)) == 0);
    assert(strncmp(substr, "o", sizeof(substr)) == 0);
    assert(strncmp(p, "o", sizeof(substr)) == 0);

    char s8[32] = "hello World!";
    p = str_substring(s8, -99, 9, substr, sizeof(substr));
    assert(strncmp(s8, "hello World!", sizeof(s8)) == 0);
    assert(strncmp(substr, "hello Worl", sizeof(substr)) == 0);
    assert(strncmp(p, "hello Worl", sizeof(substr)) == 0);

    p = str_substring(NULL, 7, 7, NULL, -2);
    assert(!p);
}

void test_str_count_substring() {
    assert(str_count_substring("hello", "hel") == 1);
    assert(str_count_substring("hello", "ell") == 1);
    assert(str_count_substring("hello", "hello") == 1);
    assert(str_count_substring("hello", "l") == 2);
    assert(str_count_substring("hello World!", "l") == 3);
    assert(str_count_substring("This is a test.", "is") == 2);
    assert(str_count_substring("This is a test.", "hello") == 0);
    assert(str_count_substring("This is a test.", "") == 0);
    assert(str_count_substring("", "hello") == 0);
    assert(str_count_substring("", "") == 1);
    assert(str_count_substring(NULL, NULL) == 0);
    assert(str_count_substring("goooooood", "o") == 7);
    assert(str_count_substring("goooooood", "oo") == 3);
    assert(str_count_substring("goooooood", "ooo") == 2);
    assert(str_count_substring("goooooood", "oooo") == 1);
}

void test_str_replace_char() {
    char *p = NULL;

    char s1[16] = "Hello World!";
    p = str_replace_char(s1, 'l', 'L');
    assert(strncmp(s1, "HeLLo WorLd!", sizeof(s1)) == 0);
    assert(strncmp(p, "HeLLo WorLd!", sizeof(s1)) == 0);

    char s2[16] = "Hello World!";
    p = str_replace_char(s2, 'e', 'a');
    assert(strncmp(s2, "Hallo World!", sizeof(s2)) == 0);
    assert(strncmp(p, "Hallo World!", sizeof(s2)) == 0);

    char s3[16] = "Hello World!";
    p = str_replace_char(s3, ' ', '#');
    assert(strncmp(s3, "Hello#World!", sizeof(s3)) == 0);
    assert(strncmp(p, "Hello#World!", sizeof(s3)) == 0);

    char s4[16] = "Hello World!";
    p = str_replace_char(s4, 'X', ' ');
    assert(strncmp(s4, "Hello World!", sizeof(s4)) == 0);
    assert(strncmp(p, "Hello World!", sizeof(s4)) == 0);

    char s5[16] = "Hello World!";
    p = str_replace_char(s5, 'l', '\0');
    assert(strncmp(s5, "He", sizeof(s5)) == 0);
    assert(strncmp(p, "He", sizeof(s5)) == 0);

    p = str_replace_char(NULL, 'a', 'b');
    assert(!p);
}

void test_str_replace() {
    char *p = NULL;

    char s1[32] = "This is a test.";
    p = str_replace(s1, "is", "IS");
    assert(strncmp(s1, "ThIS IS a test.", sizeof(s1)) == 0);
    assert(strncmp(p, "ThIS IS a test.", sizeof(s1)) == 0);

    char s2[32] = "This is a test.";
    p = str_replace(s2, "a", "A");
    assert(strncmp(s2, "This is A test.", sizeof(s2)) == 0);
    assert(strncmp(p, "This is A test.", sizeof(s2)) == 0);

    char s3[32] = "foobar foobar foobar";
    p = str_replace(s3, "foobar", "func");
    assert(strncmp(s3, "func func func", sizeof(s3)) == 0);
    assert(strncmp(p, "func func func", sizeof(s3)) == 0);

    char s4[32] = "CCCCCCCCCCCCCCC";
    p = str_replace(s4, "C", "U");
    assert(strncmp(s4, "UUUUUUUUUUUUUUU", sizeof(s4)) == 0);
    assert(strncmp(p, "UUUUUUUUUUUUUUU", sizeof(s4)) == 0);

    char s5[32] = "CCCCCCCCCCCCCCC";
    p = str_replace(s5, "A", "I");
    assert(strncmp(s5, "CCCCCCCCCCCCCCC", sizeof(s5)) == 0);
    assert(strncmp(p, "CCCCCCCCCCCCCCC", sizeof(s5)) == 0);

    char s6[32] = "foobar foobar foobar";
    p = str_replace(s6, "foobar", "");
    assert(strncmp(s6, "  ", sizeof(s6)) == 0);
    assert(strncmp(p, "  ", sizeof(s6)) == 0);

    char s7[32] = "foobarfoobaoobar";
    p = str_replace(s7, "foobar", "Replace");
    assert(strncmp(s7, "Replacefoobaoobar", sizeof(s7)) == 0);
    assert(strncmp(p, "Replacefoobaoobar", sizeof(s7)) == 0);

    char s8[8] = "";
    p = str_replace(s8, "foobar", "Replace");
    assert(strncmp(s8, "", sizeof(s8)) == 0);
    assert(strncmp(p, "", sizeof(s8)) == 0);

    p = str_replace(NULL, NULL, NULL);
    assert(!p);
}

void test_str_remove() {
    char *p = NULL;

    char s1[] = "Hello World";
    p = str_remove(s1, "llo");
    assert(strncmp(s1, "He World", sizeof(s1)) == 0);
    assert(strncmp(p, "He World", sizeof(s1)) == 0);

    char s2[] = "Hello World";
    p = str_remove(s2, " ");
    assert(strncmp(s2, "HelloWorld", sizeof(s2)) == 0);
    assert(strncmp(p, "HelloWorld", sizeof(s2)) == 0);

    char s3[] = "Hello World";
    p = str_remove(s3, "Hello");
    assert(strncmp(s3, " World", sizeof(s3)) == 0);
    assert(strncmp(p, " World", sizeof(s3)) == 0);

    char s4[] = "Hello World";
    p = str_remove(s4, "World");
    assert(strncmp(s4, "Hello ", sizeof(s4)) == 0);
    assert(strncmp(p, "Hello ", sizeof(s4)) == 0);

    char s5[] = "Hello World";
    p = str_remove(s5, "Hello World");
    assert(strncmp(s5, "", sizeof(s5)) == 0);
    assert(strncmp(p, "", sizeof(s5)) == 0);

    char s6[] = "This is a test";
    p = str_remove(s6, "is");
    assert(strncmp(s6, "Th  a test", sizeof(s6)) == 0);
    assert(strncmp(p, "Th  a test", sizeof(s6)) == 0);

    char s7[] = "This is a test";
    p = str_remove(s7, "hello");
    assert(strncmp(s7, "This is a test", sizeof(s7)) == 0);
    assert(strncmp(p, "This is a test", sizeof(s7)) == 0);

    p = str_remove(NULL, NULL);
    assert(!p);
}

void test_str_index_of_char() {
    assert(str_index_of_char("Hello World", 'l') == 2);
    assert(str_index_of_char("Hello World", 'e') == 1);
    assert(str_index_of_char("Hello World", 'd') == 10);
    assert(str_index_of_char("Hello World", 'H') == 0);
    assert(str_index_of_char("Hello World", '#') == -1);
    assert(str_index_of_char("", 'a') == -1);
    assert(str_index_of_char(NULL, 'a') == -1);
    assert(str_index_of_char("", '\0') == 0);
}

void test_str_index_of_char_from() {
    assert(str_index_of_char_from("Hello World", 'l', 0) == 2);
    assert(str_index_of_char_from("Hello World", 'l', 1) == 2);
    assert(str_index_of_char_from("Hello World", 'l', 2) == 2);
    assert(str_index_of_char_from("Hello World", 'l', 3) == 3);
    assert(str_index_of_char_from("Hello World", 'l', 7) == 9);
    assert(str_index_of_char_from("Hello World", 'l', 9) == 9);
    assert(str_index_of_char_from("Hello World", 'l', 10) == -1);
    assert(str_index_of_char_from("Hello World", 'a', 0) == -1);
    assert(str_index_of_char_from("Hello World", 'e', 1) == 1);
    assert(str_index_of_char_from("Hello World", 'o', 6) == 7);
    assert(str_index_of_char_from("Hello World", 'H', 5) == -1);
    assert(str_index_of_char_from("", 'a', 0) == -1);
    assert(str_index_of_char_from(NULL, 'a', 5) == -1);
    assert(str_index_of_char_from("Hello World", 'l', 99) == -1);
    assert(str_index_of_char_from("Hello World", 'l', -99) == -1);
    assert(str_index_of_char_from("", '\0', 0) == 0);
}

void test_str_index_of_substring() {
    assert(str_index_of_substring("Hello World", "l") == 2);
    assert(str_index_of_substring("Hello World", "ll") == 2);
    assert(str_index_of_substring("Hello World", "llo") == 2);
    assert(str_index_of_substring("Hello World", "World") == 6);
    assert(str_index_of_substring("Hello World", "Hello") == 0);
    assert(str_index_of_substring("Hello World", "") == -1);
    assert(str_index_of_substring("Hello World", " ") == 5);
    assert(str_index_of_substring("Hello World", "hell") == -1);
    assert(str_index_of_substring("Hello World", "lo W") == 3);
    assert(str_index_of_substring("Hello World", "Hello World!") == -1);
    assert(str_index_of_substring("", "") == 0);
    assert(str_index_of_substring("", "Hello") == -1);
    assert(str_index_of_substring(NULL, "") == -1);
}

void test_str_index_of_substring_from() {
    assert(str_index_of_substring_from("Hello World", "l", 0) == 2);
    assert(str_index_of_substring_from("Hello World", "ll", 0) == 2);
    assert(str_index_of_substring_from("Hello World", "llo", 0) == 2);
    assert(str_index_of_substring_from("Hello World", "World", 3) == 6);
    assert(str_index_of_substring_from("Hello World", "World", 8) == -1);
    assert(str_index_of_substring_from("Hello World", "Hello", 0) == 0);
    assert(str_index_of_substring_from("Hello World", "Hello", 5) == -1);
    assert(str_index_of_substring_from("Hello World", "Hello", -99) == -1);
    assert(str_index_of_substring_from("Hello World", "", 0) == -1);
    assert(str_index_of_substring_from("Hello World", " ", 4) == 5);
    assert(str_index_of_substring_from("Hello World", " ", 7) == -1);
    assert(str_index_of_substring_from("Hello World", "hell", 0) == -1);
    assert(str_index_of_substring_from("Hello World", "lo W", 3) == 3);
    assert(str_index_of_substring_from("Hello World", "Hello World!", 0) == -1);
    assert(str_index_of_substring_from("", "", 0) == 0);
    assert(str_index_of_substring_from("", "", 6) == -1);
    assert(str_index_of_substring_from("", "Hello", 0) == -1);
    assert(str_index_of_substring_from(NULL, "", 99) == -1);
}

void test_str_last_index_of_char() {
    assert(str_last_index_of_char("Hello World", 'l') == 9);
    assert(str_last_index_of_char("Hello World", 'e') == 1);
    assert(str_last_index_of_char("Hello World", 'd') == 10);
    assert(str_last_index_of_char("Hello World", 'H') == 0);
    assert(str_last_index_of_char("Hello World", ' ') == 5);
    assert(str_last_index_of_char("", 'a') == -1);
    assert(str_last_index_of_char(NULL, 'a') == -1);
    assert(str_last_index_of_char("", '\0') == 0);
}

void test_str_last_index_of_char_from() {
    assert(str_last_index_of_char_from("Hello World", 'l', 0) == -1);
    assert(str_last_index_of_char_from("Hello World", 'l', 1) == -1);
    assert(str_last_index_of_char_from("Hello World", 'l', 10) == 9);
    assert(str_last_index_of_char_from("Hello World", 'l', 8) == 3);
    assert(str_last_index_of_char_from("Hello World", 'l', 3) == 3);
    assert(str_last_index_of_char_from("Hello World", 'l', 2) == 2);
    assert(str_last_index_of_char_from("Hello World", 'l', 1) == -1);
    assert(str_last_index_of_char_from("Hello World", 'a', 5) == -1);
    assert(str_last_index_of_char_from("Hello World", 'e', 7) == 1);
    assert(str_last_index_of_char_from("Hello World", 'o', 5) == 4);
    assert(str_last_index_of_char_from("Hello World", 'H', 0) == 0);
    assert(str_last_index_of_char_from("", 'a', 0) == -1);
    assert(str_last_index_of_char_from(NULL, 'a', 5) == -1);
    assert(str_last_index_of_char_from("Hello World", 'l', 99) == -1);
    assert(str_last_index_of_char_from("Hello World", 'l', -99) == -1);
    assert(str_last_index_of_char_from("", '\0', 0) == 0);
}

void test_str_last_index_of_substring() {
    assert(str_last_index_of_substring("Hello World", "l") == 9);
    assert(str_last_index_of_substring("Hello World", "ll") == 2);
    assert(str_last_index_of_substring("Hello World", "llo") == 2);
    assert(str_last_index_of_substring("Hello World", "World") == 6);
    assert(str_last_index_of_substring("Hello World", "Hello") == 0);
    assert(str_last_index_of_substring("Hello World", "o") == 7);
    assert(str_last_index_of_substring("Hello World", " ") == 5);
    assert(str_last_index_of_substring("Hello World", "hell") == -1);
    assert(str_last_index_of_substring("Hello World", "lo W") == 3);
    assert(str_last_index_of_substring("Hello World", "Hello World!") == -1);
    assert(str_last_index_of_substring("", "") == 0);
    assert(str_last_index_of_substring("", "Hello") == -1);
    assert(str_last_index_of_substring(NULL, "") == -1);
    assert(str_last_index_of_substring("Hello World", "") == -1);
}

void test_str_last_index_of_substring_from() {
    assert(str_last_index_of_substring_from("Hello World", "l", 0) == -1);
    assert(str_last_index_of_substring_from("Hello World", "ll", 0) == -1);
    assert(str_last_index_of_substring_from("Hello World", "llo", 10) == 2);
    assert(str_last_index_of_substring_from("Hello World", "World", 10) == 6);
    assert(str_last_index_of_substring_from("Hello World", "World", 8) == -1);
    assert(str_last_index_of_substring_from("Hello World", "Hello", 5) == 0);
    assert(str_last_index_of_substring_from("Hello World", "Hello", 4) == 0);
    assert(str_last_index_of_substring_from("Hello World", "Hello", 3) == -1);
    assert(str_last_index_of_substring_from("Hello World", "Hello", -99) == -1);
    assert(str_last_index_of_substring_from("Hello World", "", 0) == -1);
    assert(str_last_index_of_substring_from("Hello World", " ", 6) == 5);
    assert(str_last_index_of_substring_from("Hello World", " ", 3) == -1);
    assert(str_last_index_of_substring_from("Hello World", "hell", 6) == -1);
    assert(str_last_index_of_substring_from("Hello World", "lo W", 3) == -1);
    assert(str_last_index_of_substring_from("Hello World", "Hello World!", 8) == -1);
    assert(str_last_index_of_substring_from("", "", 0) == 0);
    assert(str_last_index_of_substring_from("", "", 6) == -1);
    assert(str_last_index_of_substring_from("", "Hello", 0) == -1);
    assert(str_last_index_of_substring_from(NULL, "", 99) == -1);
}

void test_str_split() {
    const int ITEM_NUM = 10;
    const int ITEM_MAX_LEN = 64;
    char **items = (char **)calloc(ITEM_NUM, sizeof(char *));
    for (int i = 0; i < ITEM_NUM; i++) {
        items[i] = (char *)calloc(ITEM_MAX_LEN + 1, sizeof(char));
    }

    int cnt = 0;

    cnt = str_split("This is a test", " ", items);
    assert(cnt == 4);
    assert(strncmp(items[0], "This", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "is", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], "a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[3], "test", ITEM_MAX_LEN) == 0);

    cnt = str_split("this_is_a_test", "_", items);
    assert(cnt == 4);
    assert(strncmp(items[0], "this", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "is", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], "a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[3], "test", ITEM_MAX_LEN) == 0);

    cnt = str_split("this_is_a_test", "i", items);
    assert(cnt == 3);
    assert(strncmp(items[0], "th", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "s_", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], "s_a_test", ITEM_MAX_LEN) == 0);

    cnt = str_split("this_is_a_test", "is", items);
    assert(cnt == 3);
    assert(strncmp(items[0], "th", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "_", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], "_a_test", ITEM_MAX_LEN) == 0);

    cnt = str_split("This    is a            test", "  ", items);
    assert(cnt == 3);
    assert(strncmp(items[0], "This", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "is a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], "test", ITEM_MAX_LEN) == 0);

    cnt = str_split("  This   is   a   test  ", "  ", items);
    assert(cnt == 4);
    assert(strncmp(items[0], "This", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], " is", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], " a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[3], " test", ITEM_MAX_LEN) == 0);

    cnt = str_split(" This  is   a    test   a  is This", "  ", items);
    assert(cnt == 6);
    assert(strncmp(items[0], " This", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[1], "is", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[2], " a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[3], "test", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[4], " a", ITEM_MAX_LEN) == 0);
    assert(strncmp(items[5], "is This", ITEM_MAX_LEN) == 0);

    for (int i = 0; i < ITEM_NUM; i++) {
        free(items[i]);
    }
    free(items);
}

void test_cino_alloc() {
    int *arr1 = (int *)cino_alloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        arr1[i] = i;
        assert(arr1[i] == i);
    }
    free(arr1);

    double *arr2 = (double *)cino_alloc(0 * sizeof(double));
    assert(!arr2);

    char *p1 = (char *)cino_alloc(6 * sizeof(char));
    memcpy(p1, "Hello", strlen("Hello"));
    assert(strncmp(p1, "Hello", strlen(p1)) == 0);
    free(p1);

    char **p2 = (char **)cino_alloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        p2[i] = (char *)cino_alloc(10 * sizeof(char));
        snprintf(p2[i], 10, "Test-%d", i);
        char real[10] = {0};
        snprintf(real, 10, "Test-%d", i);
        assert(strncmp(p2[i], real, strlen(real)) == 0);
    }
    for (int i = 0; i < 5; i++) {
        free(p2[i]);
    }
    free(p2);

    struct test_t {
        int a;
        char *p;
    };

    struct test_t *test = (struct test_t *)cino_alloc(sizeof(struct test_t));
    test->a = 123;
    test->p = (char *)cino_alloc(16 * sizeof(char));
    memcpy(test->p, "Hello World!", strlen("Hello World!"));
    assert(test->a == 123);
    assert(strncmp(test->p, "Hello World!", strlen(test->p)) == 0);
    free(test->p);
    free(test);
}

void test_cino_realloc() {
    int *arr1 = (int *)cino_alloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        arr1[i] = i;
        assert(arr1[i] == i);
    }
    arr1 = (int *)cino_realloc(arr1, 100 * sizeof(int), 200 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        assert(arr1[i] == i);
    }
    for (int i = 100; i < 200; i++) {
        assert(arr1[i] == 0);
    }
    free(arr1);

    double *arr2 = (double *)cino_realloc(arr1, 5, 0 * sizeof(double));
    assert(!arr2);

    float *arr3 = (float *)cino_realloc(NULL, 0, 10 * sizeof(float));
    assert(arr3);
    free(arr3);

    char *p1 = (char *)cino_alloc(6 * sizeof(char));
    memcpy(p1, "Hello", strlen("Hello"));
    assert(strncmp(p1, "Hello", strlen(p1)) == 0);
    p1 = (char *)cino_realloc(p1, 6, 12 * sizeof(char));
    assert(strncmp(p1, "Hello", strlen(p1)) == 0);
    free(p1);

    struct test_t {
        int a;
        char *p;
    };

    struct test_t *test = (struct test_t *)cino_alloc(sizeof(struct test_t));
    test->a = 123;
    test->p = (char *)cino_alloc(16 * sizeof(char));
    memcpy(test->p, "Hello World!", strlen("Hello World!"));
    assert(test->a == 123);
    assert(strncmp(test->p, "Hello World!", strlen(test->p)) == 0);
    test->p = (char *)cino_realloc(test->p, 16, 8);
    assert(test->a == 123);
    test->p[7] = '\0';
    assert(strncmp(test->p, "Hello W", strlen(test->p)) == 0);
    free(test->p);
    free(test);
}