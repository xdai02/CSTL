#include "test_cino_utils.h"
#include "cino_utils.h"

void test_min() {
    assert(min(5, 2) == 2);
    assert(min(2, 2) == 2);
    assert(min(-5, -2) == -5);
    assert(min(0, 2) == 0);
    assert(equal_double(min(3.1415, 3.1416), 3.1415));
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
    assert(equal_double(max(3.1415, 3.1416), 3.1416));
    assert(max('a', 'b') == 'b');
    assert(max('X', 'H') == 'X');
    assert(max('A', 'a') == 'a');
    assert(max('z', 'Z') == 'z');
}

void test_negate() {
    assert(negate(5) == -5);
    assert(negate(0) == 0);
    assert(negate(+0) == 0);
    assert(negate(-0) == 0);
    assert(negate(-5) == 5);
    assert(equal_double(negate(3.14), -3.14));
    assert(equal_double(negate(-3.14), 3.14));
    assert(equal_double(negate(0.0), 0.0));
}

void test_swap() {
    int num1 = 1;
    int num2 = 2;
    swap(num1, num2, int);
    assert(num1 == 2);
    assert(num2 == 1);

    double num3 = 3.14;
    double num4 = 2.71;
    swap(num3, num4, double);
    assert(equal_double(num3, 2.71));
    assert(equal_double(num4, 3.14));

    int num5 = 123;
    int num6 = 789;
    int *p1 = &num5;
    int *p2 = &num6;
    swap(*p1, *p2, int);
    assert(num5 == 789);
    assert(num6 == 123);
    assert(*p1 == 789);
    assert(*p2 == 123);

    int num7 = 321;
    int num8 = 987;
    int *p3 = &num7;
    int *p4 = &num8;
    swap(p3, p4, int *);
    assert(num7 == 321);
    assert(num8 == 987);
    assert(*p3 == 987);
    assert(*p4 == 321);
    assert(p3 == &num8);
    assert(p4 == &num7);
}

void test_equal_double() {
    assert(equal_double(0, 0));
    assert(!equal_double(5, 4.9));
    assert(!equal_double(0.001, 0));
    assert(equal_double(3.141592, 3.141592));
    assert(equal_double(-3.141592, -3.141592));
    assert(equal_double(0, -0));
    assert(!equal_double(5.00001, 4.99999));
    assert(equal_double(12345.6789, 12345.67890));
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

    const str_t s1 = NULL;
    assert(!str_to_bool(s1));

    const str_t s2 = "!@#$";
    assert(str_to_bool(s2));
}

void test_bool_to_str() {
    assert(str_equal(bool_to_str(true), "true"));
    assert(str_equal(bool_to_str(false), "false"));
    assert(str_equal(bool_to_str(1), "true"));
    assert(str_equal(bool_to_str(0), "false"));
    assert(str_equal(bool_to_str(0.0), "false"));
    assert(str_equal(bool_to_str(123), "true"));
    assert(str_equal(bool_to_str(-0), "false"));
}

void test_str_to_char() {
    char s1[] = "A";
    assert(str_to_char(s1) == 'A');

    char s2[8] = "25X13";
    assert(str_to_char(s2) == '2');

    const str_t s3 = "@.!#$)";
    assert(str_to_char(s3) == '@');

    assert(str_to_char(" ") == ' ');
    assert(str_to_char("\n") == '\n');
    assert(str_to_char("\t") == '\t');
    assert(str_to_char(NULL) == '\0');
    assert(str_to_char("") == '\0');
}

void test_char_to_str() {
    str_t p = NULL;

    char s1[8] = {0};
    p = char_to_str('H', s1, sizeof(s1));
    assert(str_equal(s1, "H"));
    assert(str_equal(p, "H"));

    char s2[8] = "Hello";
    p = char_to_str('2', s2, sizeof(s2));
    assert(str_equal(s2, "2"));
    assert(str_equal(p, "2"));

    char s3[2] = "#";
    p = char_to_str('!', s3, sizeof(s3));
    assert(str_equal(s3, "!"));
    assert(str_equal(p, "!"));

    char s4[3] = "";
    p = char_to_str('\0', s4, sizeof(s4));
    assert(str_equal(s4, ""));
    assert(str_equal(p, ""));

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
    assert(str_to_int("-3.14") == -3);
    assert(str_to_int("2147483647") == 2147483647);
    assert(str_to_int("-2147483648") == -2147483648);
}

void test_int_to_str() {
    str_t p = NULL;

    char s1[4] = {0};
    p = int_to_str(123, s1, sizeof(s1));
    assert(str_equal(s1, "123"));
    assert(str_equal(p, "123"));

    char s2[32] = {0};
    p = int_to_str(-987, s2, sizeof(s2));
    assert(str_equal(s2, "-987"));
    assert(str_equal(p, "-987"));

    char s3[12] = {0};
    p = int_to_str(2147483647, s3, sizeof(s3));
    assert(str_equal(s3, "2147483647"));
    assert(str_equal(p, "2147483647"));

    char s4[13] = {0};
    p = int_to_str(-2147483648, s4, sizeof(s4));
    assert(str_equal(s4, "-2147483648"));
    assert(str_equal(p, "-2147483648"));

    p = int_to_str(0, NULL, 0);
    assert(!p);
}

void test_str_to_double() {
    assert(equal_double(str_to_double("123"), 123.0));
    assert(equal_double(str_to_double("-123"), -123.0));
    assert(equal_double(str_to_double("0"), 0.0));
    assert(equal_double(str_to_double("+0"), 0.0));
    assert(equal_double(str_to_double("-0"), 0.0));
    assert(equal_double(str_to_double("-3.14"), -3.14));
    assert(equal_double(str_to_double("2147483647"), 2147483647.0));
    assert(equal_double(str_to_double("-2147483648"), -2147483648.0));
    assert(equal_double(str_to_double("0.00"), 0.0));
    assert(equal_double(str_to_double("3.1415926"), 3.1415926));
    assert(equal_double(str_to_double("1e2"), 100.0));
    assert(equal_double(str_to_double("-2.3e4"), -23000.0));
}

void test_double_to_str() {
    str_t p = NULL;

    char s1[6] = {0};
    p = double_to_str(123, 1, s1, sizeof(s1));
    assert(str_equal(s1, "123.0"));
    assert(str_equal(p, "123.0"));

    char s2[32] = {0};
    p = double_to_str(-987, 4, s2, sizeof(s2));
    assert(str_equal(s2, "-987.0000"));
    assert(str_equal(p, "-987.0000"));

    char s3[16] = {0};
    p = double_to_str(2147483647, 0, s3, sizeof(s3));
    assert(str_equal(s3, "2147483647"));
    assert(str_equal(p, "2147483647"));

    char s4[16] = {0};
    p = double_to_str(-3.141592, 4, s4, sizeof(s4));
    assert(str_equal(s4, "-3.1416"));
    assert(str_equal(p, "-3.1416"));

    char s5[16] = {0};
    p = double_to_str(2.717, 0, s5, 5);
    assert(str_equal(s5, "3"));
    assert(str_equal(p, "3"));

    p = double_to_str(0, -1, NULL, 0);
    assert(!p);
}

void test_wrap_int() {
    wrapper_int_t *wrapper = wrap_int(123);
    assert(wrapper->data == 123);
    assert(unwrap_int(wrapper) == 123);
}

void test_unwrap_int() {
    wrapper_int_t *wrapper = wrap_int(123);
    assert(wrapper->data == 123);
    assert(unwrap_int(wrapper) == 123);
}

void test_wrap_double() {
    wrapper_double_t *wrapper = wrap_double(3.14);
    assert(equal_double(wrapper->data, 3.14));
    assert(equal_double(unwrap_double(wrapper), 3.14));
}

void test_unwrap_double() {
    wrapper_double_t *wrapper = wrap_double(3.14);
    assert(equal_double(wrapper->data, 3.14));
    assert(equal_double(unwrap_double(wrapper), 3.14));
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

    const str_t s1 = "XYZ";
    const str_t s2 = "XYZ";
    assert(str_equal(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!str_equal(s1, s2));

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(str_equal(s3, s4));

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

    const str_t s1 = "XYZ";
    const str_t s2 = "xYz";
    assert(str_equal_ignore_case(s1, s2));

    s1 = "987654321";
    s2 = "987654321 ";
    assert(!str_equal_ignore_case(s1, s2));

    char s3[] = "!@#$^&*()";
    char s4[32] = "!@#$^&*()";
    assert(str_equal_ignore_case(s3, s4));

    assert(!str_equal_ignore_case("", NULL));
    assert(!str_equal_ignore_case(NULL, ""));
}

void test_str_to_lower() {
    str_t p = NULL;

    char s1[] = "HELLO";
    p = str_to_lower(s1);
    assert(str_equal(s1, "hello"));
    assert(str_equal(p, "hello"));

    char s2[16] = "HeLlO WoRlD";
    p = str_to_lower(s2);
    assert(str_equal(s2, "hello world"));
    assert(str_equal(p, "hello world"));

    char s3[32] = "!@#$123Abc";
    p = str_to_lower(s3);
    assert(str_equal(s3, "!@#$123abc"));
    assert(str_equal(p, "!@#$123abc"));

    char s4[] = "";
    p = str_to_lower(s4);
    assert(str_equal(s4, ""));
    assert(str_equal(p, ""));

    char s5[] = "\n\t\0";
    p = str_to_lower(s5);
    assert(str_equal(s5, "\n\t\0"));
    assert(str_equal(p, "\n\t\0"));
}

void test_str_to_upper() {
    str_t p = NULL;

    char s1[] = "hello";
    p = str_to_upper(s1);
    assert(str_equal(s1, "HELLO"));
    assert(str_equal(p, "HELLO"));

    char s2[16] = "HeLlO WoRlD";
    p = str_to_upper(s2);
    assert(str_equal(s2, "HELLO WORLD"));
    assert(str_equal(p, "HELLO WORLD"));

    char s3[32] = "!@#$123Abc";
    p = str_to_upper(s3);
    assert(str_equal(s3, "!@#$123ABC"));
    assert(str_equal(p, "!@#$123ABC"));

    char s4[] = "";
    p = str_to_upper(s4);
    assert(str_equal(s4, ""));
    assert(str_equal(p, ""));

    char s5[] = "\n\t\0";
    p = str_to_upper(s5);
    assert(str_equal(s5, "\n\t\0"));
    assert(str_equal(p, "\n\t\0"));
}

void test_str_starts_with() {
    assert(str_starts_with("hello", "hell"));
    assert(str_starts_with("Hello World!", "Hello W"));
    assert(str_starts_with("This is a test.", "This is a test."));
    assert(!str_starts_with("hello", "HE"));
    assert(str_starts_with("123ABC", "1"));
    assert(str_starts_with("\n\t\0", "\n"));
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
    str_t p = NULL;

    char s1[] = "hello";
    char s2[] = "world";
    p = str_copy(s1, s2);
    assert(str_equal(s1, s2));
    assert(str_equal(s2, "world"));
    assert(str_equal(p, s1));

    char s3[32] = {0};
    str_t s4 = "This is a test.";
    p = str_copy(s3, s4);
    assert(str_equal(s3, s4));
    assert(str_equal(s4, "This is a test."));
    assert(str_equal(p, s3));

    char s5[16] = "Lorem ipsum";
    str_t s6 = "test";
    p = str_copy(s5, s6);
    assert(str_equal(s5, s6));
    assert(str_equal(s6, "test"));
    assert(str_equal(p, s5));

    char s7[16] = "Lorem ipsum";
    p = str_copy(s7, NULL);
    assert(str_equal(s7, "Lorem ipsum"));
    assert(str_equal(p, s7));

    p = str_copy(NULL, "test");
    assert(!p);
}

void test_str_concat() {
    str_t p = NULL;

    char s1[11] = "hello";
    char s2[] = "world";
    p = str_concat(s1, s2);
    assert(str_equal(s1, "helloworld"));
    assert(str_equal(s2, "world"));
    assert(str_equal(p, s1));

    char s3[32] = {0};
    str_t s4 = "This is a test.";
    p = str_concat(s3, s4);
    assert(str_equal(s3, "This is a test."));
    assert(str_equal(s4, "This is a test."));
    assert(str_equal(p, s3));

    char s5[16] = "Lorem ipsum";
    str_t s6 = "test";
    p = str_concat(s5, s6);
    assert(str_equal(s5, "Lorem ipsumtest"));
    assert(str_equal(s6, "test"));
    assert(str_equal(p, s5));

    char s7[16] = "Lorem ipsum";
    p = str_concat(s7, NULL);
    assert(str_equal(s7, "Lorem ipsum"));
    assert(str_equal(p, s7));

    p = str_concat(NULL, "test");
    assert(!p);
}

void test_str_trim() {
    str_t p = NULL;

    char s1[8] = " hello";
    p = str_trim(s1);
    assert(str_equal(s1, "hello"));
    assert(str_equal(p, "hello"));

    char s2[8] = "hello ";
    p = str_trim(s2);
    assert(str_equal(s2, "hello"));
    assert(str_equal(p, "hello"));

    char s3[8] = " hello ";
    p = str_trim(s3);
    assert(str_equal(s3, "hello"));
    assert(str_equal(p, "hello"));

    char s4[32] = "   hello        ";
    p = str_trim(s4);
    assert(str_equal(s4, "hello"));
    assert(str_equal(p, "hello"));

    char s5[32] = "\nhello        ";
    p = str_trim(s5);
    assert(str_equal(s5, "hello"));
    assert(str_equal(p, "hello"));

    char s6[32] = "\t  hello  \n   \t \n      ";
    p = str_trim(s6);
    assert(str_equal(s6, "hello"));
    assert(str_equal(p, "hello"));

    char s7[8] = "hello";
    p = str_trim(s7);
    assert(str_equal(s7, "hello"));
    assert(str_equal(p, "hello"));

    char s8[16] = "        ";
    p = str_trim(s8);
    assert(str_equal(s8, ""));
    assert(str_equal(p, ""));

    char s9[16] = "\n\t\r\n\r\n\r\t";
    p = str_trim(s9);
    assert(str_equal(s9, ""));
    assert(str_equal(p, ""));

    p = str_trim(NULL);
    assert(!p);
}

void test_str_append_char() {
    str_t p = NULL;

    char s1[11] = "hello";
    p = str_append_char(s1, 'X');
    assert(str_equal(s1, "helloX"));
    assert(str_equal(p, "helloX"));

    char s2[32] = {0};
    p = str_append_char(s2, ' ');
    assert(str_equal(s2, " "));
    assert(str_equal(p, " "));

    char s3[16] = "Lorem ipsum";
    char c = '\t';
    p = str_append_char(s3, c);
    assert(str_equal(s3, "Lorem ipsum\t"));
    assert(str_equal(p, "Lorem ipsum\t"));

    p = str_append_char(NULL, '!');
    assert(!p);
}

void test_str_append_int() {
    str_t p = NULL;

    char s1[11] = "hello";
    p = str_append_int(s1, 123);
    assert(str_equal(s1, "hello123"));
    assert(str_equal(p, "hello123"));

    char s2[32] = {0};
    p = str_append_int(s2, -987);
    assert(str_equal(s2, "-987"));
    assert(str_equal(p, "-987"));

    char s3[32] = "Lorem ipsum";
    p = str_append_int(s3, 2147483647);
    assert(str_equal(s3, "Lorem ipsum2147483647"));
    assert(str_equal(p, "Lorem ipsum2147483647"));

    p = str_append_int(NULL, 0);
    assert(!p);
}

void test_str_append_double() {
    str_t p = NULL;

    char s1[11] = "hello";
    p = str_append_double(s1, 123, 0);
    assert(str_equal(s1, "hello123"));
    assert(str_equal(p, "hello123"));

    char s2[32] = {0};
    p = str_append_double(s2, -987, 5);
    assert(str_equal(s2, "-987.00000"));
    assert(str_equal(p, "-987.00000"));

    char s3[32] = "Lorem ipsum";
    p = str_append_double(s3, 3.141, 16);
    assert(str_equal(s3, "Lorem ipsum3.1410000000000000"));
    assert(str_equal(p, "Lorem ipsum3.1410000000000000"));

    p = str_append_double(NULL, 0, -1);
    assert(!p);
}

void test_str_insert_char() {
    const str_t p = NULL;

    char s1[8] = "ello";
    p = str_insert_char(s1, 0, 'H');
    assert(str_equal(s1, "Hello"));
    assert(str_equal(p, "Hello"));

    char s2[8] = "Hello";
    p = str_insert_char(s2, strlen(s2), 'o');
    assert(str_equal(s2, "Helloo"));
    assert(str_equal(p, "Helloo"));

    char s3[8] = "Hello";
    p = str_insert_char(s3, 3, 'l');
    assert(str_equal(s3, "Helllo"));
    assert(str_equal(p, "Helllo"));

    char s4[8] = "Hello";
    p = str_insert_char(s4, 1, '\n');
    assert(str_equal(s4, "H\nello"));
    assert(str_equal(p, "H\nello"));

    char s5[8] = "Hello";
    p = str_insert_char(s5, 0, '\0');
    assert(str_equal(s5, ""));
    assert(str_equal(p, ""));

    char s6[8] = "Hello";
    p = str_insert_char(s6, strlen(s6) - 1, '\0');
    assert(str_equal(s6, "Hell"));
    assert(str_equal(p, "Hell"));

    char s7[8] = {0};
    p = str_insert_char(s7, 0, 'A');
    assert(str_equal(s7, "A"));
    assert(str_equal(p, "A"));

    char s8[8] = "Test";
    p = str_insert_char(s8, 5, 's');
    assert(str_equal(s8, "Test"));
    assert(str_equal(p, "Test"));

    p = str_insert_char(NULL, 0, 's');
    assert(!p);
}

void test_str_insert_string() {
    str_t p = NULL;

    char s1[16] = "World";
    p = str_insert_string(s1, 0, "Hello");
    assert(str_equal(s1, "HelloWorld"));
    assert(str_equal(p, "HelloWorld"));

    char s2[16] = "Hello";
    p = str_insert_string(s2, strlen(s2), "World");
    assert(str_equal(s2, "HelloWorld"));
    assert(str_equal(p, "HelloWorld"));

    char s3[8] = "Hello";
    p = str_insert_string(s3, strlen(s3), "!");
    assert(str_equal(s3, "Hello!"));
    assert(str_equal(p, "Hello!"));

    char s4[8] = "Hello";
    p = str_insert_string(s4, 1, "He");
    assert(str_equal(s4, "HHeello"));
    assert(str_equal(p, "HHeello"));

    char s5[32] = "Hello";
    p = str_insert_string(s5, 2, "This is a test.");
    assert(str_equal(s5, "HeThis is a test.llo"));
    assert(str_equal(p, "HeThis is a test.llo"));

    char s6[8] = "Hello";
    p = str_insert_string(s6, strlen(s6) - 1, "\n\t");
    assert(str_equal(s6, "Hell\n\to"));
    assert(str_equal(p, "Hell\n\to"));

    char s7[8] = {0};
    p = str_insert_string(s7, 0, "A");
    assert(str_equal(s7, "A"));
    assert(str_equal(p, "A"));

    char s8[8] = "Test";
    p = str_insert_string(s8, 5, "s");
    assert(str_equal(s8, "Test"));
    assert(str_equal(p, "Test"));

    p = str_insert_string(NULL, 0, "s");
    assert(!p);
}

void test_str_substring() {
    str_t p = NULL;
    char substr[32] = {0};

    char s1[8] = "hello";
    p = str_substring(s1, 0, 2, substr, sizeof(substr));
    assert(str_equal(s1, "hello"));
    assert(str_equal(substr, "hel"));
    assert(str_equal(p, "hel"));

    char s2[8] = "hello";
    p = str_substring(s2, 1, 3, substr, sizeof(substr));
    assert(str_equal(s2, "hello"));
    assert(str_equal(substr, "ell"));
    assert(str_equal(p, "ell"));

    char s3[8] = "hello";
    p = str_substring(s3, 0, 4, substr, sizeof(substr));
    assert(str_equal(s3, "hello"));
    assert(str_equal(substr, "hello"));
    assert(str_equal(p, "hello"));

    char s4[32] = "hello World!";
    p = str_substring(s4, 5, 99, substr, sizeof(substr));
    assert(str_equal(s4, "hello World!"));
    assert(str_equal(substr, " World!"));
    assert(str_equal(p, " World!"));

    char s5[32] = "hello World!";
    p = str_substring(s5, -99, 99, substr, sizeof(substr));
    assert(str_equal(s5, "hello World!"));
    assert(str_equal(substr, "hello World!"));
    assert(str_equal(p, "hello World!"));

    char s6[32] = "hello World!";
    p = str_substring(s6, 8, 2, substr, sizeof(substr));
    assert(str_equal(s6, "hello World!"));
    assert(str_equal(substr, ""));
    assert(str_equal(p, ""));

    char s7[32] = "hello World!";
    p = str_substring(s7, 7, 7, substr, sizeof(substr));
    assert(str_equal(s7, "hello World!"));
    assert(str_equal(substr, "o"));
    assert(str_equal(p, "o"));

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
    str_t p = NULL;

    char s1[16] = "Hello World!";
    p = str_replace_char(s1, 'l', 'L');
    assert(str_equal(s1, "HeLLo WorLd!"));
    assert(str_equal(p, "HeLLo WorLd!"));

    char s2[16] = "Hello World!";
    p = str_replace_char(s2, 'e', 'a');
    assert(str_equal(s2, "Hallo World!"));
    assert(str_equal(p, "Hallo World!"));

    char s3[16] = "Hello World!";
    p = str_replace_char(s3, ' ', '#');
    assert(str_equal(s3, "Hello#World!"));
    assert(str_equal(p, "Hello#World!"));

    char s4[16] = "Hello World!";
    p = str_replace_char(s4, 'X', ' ');
    assert(str_equal(s4, "Hello World!"));
    assert(str_equal(p, "Hello World!"));

    char s5[16] = "Hello World!";
    p = str_replace_char(s5, 'l', '\0');
    assert(str_equal(s5, "He"));
    assert(str_equal(p, "He"));

    p = str_replace_char(NULL, 'a', 'b');
    assert(!p);
}

void test_str_replace() {
    str_t p = NULL;

    char s1[32] = "This is a test.";
    p = str_replace(s1, "is", "IS");
    assert(str_equal(s1, "ThIS IS a test."));
    assert(str_equal(p, "ThIS IS a test."));

    char s2[32] = "This is a test.";
    p = str_replace(s2, "a", "A");
    assert(str_equal(s2, "This is A test."));
    assert(str_equal(p, "This is A test."));

    char s3[32] = "foobar foobar foobar";
    p = str_replace(s3, "foobar", "func");
    assert(str_equal(s3, "func func func"));
    assert(str_equal(p, "func func func"));

    char s4[32] = "CCCCCCCCCCCCCCC";
    p = str_replace(s4, "C", "U");
    assert(str_equal(s4, "UUUUUUUUUUUUUUU"));
    assert(str_equal(p, "UUUUUUUUUUUUUUU"));

    char s5[32] = "CCCCCCCCCCCCCCC";
    p = str_replace(s5, "A", "I");
    assert(str_equal(s5, "CCCCCCCCCCCCCCC"));
    assert(str_equal(p, "CCCCCCCCCCCCCCC"));

    char s6[32] = "foobar foobar foobar";
    p = str_replace(s6, "foobar", "");
    assert(str_equal(s6, "  "));
    assert(str_equal(p, "  "));

    char s7[32] = "foobarfoobaoobar";
    p = str_replace(s7, "foobar", "Replace");
    assert(str_equal(s7, "Replacefoobaoobar"));
    assert(str_equal(p, "Replacefoobaoobar"));

    char s8[8] = "";
    p = str_replace(s8, "foobar", "Replace");
    assert(str_equal(s8, ""));
    assert(str_equal(p, ""));

    char s9[32] = "This is a test";
    p = str_replace(s9, "is", "THISIS");
    assert(str_equal(s9, "ThTHISIS THISIS a test"));
    assert(str_equal(p, "ThTHISIS THISIS a test"));

    p = str_replace(NULL, NULL, NULL);
    assert(!p);
}

void test_str_remove() {
    str_t p = NULL;

    char s1[] = "Hello World";
    p = str_remove(s1, "llo");
    assert(str_equal(s1, "He World"));
    assert(str_equal(p, "He World"));

    char s2[] = "Hello World";
    p = str_remove(s2, " ");
    assert(str_equal(s2, "HelloWorld"));
    assert(str_equal(p, "HelloWorld"));

    char s3[] = "Hello World";
    p = str_remove(s3, "Hello");
    assert(str_equal(s3, " World"));
    assert(str_equal(p, " World"));

    char s4[] = "Hello World";
    p = str_remove(s4, "World");
    assert(str_equal(s4, "Hello "));
    assert(str_equal(p, "Hello "));

    char s5[] = "Hello World";
    p = str_remove(s5, "Hello World");
    assert(str_equal(s5, ""));
    assert(str_equal(p, ""));

    char s6[] = "This is a test";
    p = str_remove(s6, "is");
    assert(str_equal(s6, "Th  a test"));
    assert(str_equal(p, "Th  a test"));

    char s7[] = "This is a test";
    p = str_remove(s7, "hello");
    assert(str_equal(s7, "This is a test"));
    assert(str_equal(p, "This is a test"));

    p = str_remove(NULL, NULL);
    assert(!p);
}

void test_str_reverse() {
    str_t p = NULL;

    char s1[] = "Hello World";
    p = str_reverse(s1);
    assert(str_equal(s1, "dlroW olleH"));
    assert(str_equal(p, "dlroW olleH"));

    char s2[] = "H";
    p = str_reverse(s2);
    assert(str_equal(s2, "H"));
    assert(str_equal(p, "H"));

    char s3[] = "";
    p = str_reverse(s3);
    assert(str_equal(s3, ""));
    assert(str_equal(p, ""));

    char s4[] = "Hello\0World";
    p = str_reverse(s4);
    assert(str_equal(s4, "olleH"));
    assert(str_equal(p, "olleH"));

    p = str_reverse(NULL);
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
    str_t *items = (str_t *)calloc(ITEM_NUM, sizeof(str_t));
    for (int i = 0; i < ITEM_NUM; i++) {
        items[i] = (str_t)calloc(ITEM_MAX_LEN + 1, sizeof(char));
    }

    int cnt = 0;

    cnt = str_split("This is a test", " ", items);
    assert(cnt == 4);
    assert(str_equal(items[0], "This"));
    assert(str_equal(items[1], "is"));
    assert(str_equal(items[2], "a"));
    assert(str_equal(items[3], "test"));

    cnt = str_split("this_is_a_test", "_", items);
    assert(cnt == 4);
    assert(str_equal(items[0], "this"));
    assert(str_equal(items[1], "is"));
    assert(str_equal(items[2], "a"));
    assert(str_equal(items[3], "test"));

    cnt = str_split("this_is_a_test", "i", items);
    assert(cnt == 3);
    assert(str_equal(items[0], "th"));
    assert(str_equal(items[1], "s_"));
    assert(str_equal(items[2], "s_a_test"));

    cnt = str_split("this_is_a_test", "is", items);
    assert(cnt == 3);
    assert(str_equal(items[0], "th"));
    assert(str_equal(items[1], "_"));
    assert(str_equal(items[2], "_a_test"));

    cnt = str_split("This    is a            test", "  ", items);
    assert(cnt == 3);
    assert(str_equal(items[0], "This"));
    assert(str_equal(items[1], "is a"));
    assert(str_equal(items[2], "test"));

    cnt = str_split("  This   is   a   test  ", "  ", items);
    assert(cnt == 4);
    assert(str_equal(items[0], "This"));
    assert(str_equal(items[1], " is"));
    assert(str_equal(items[2], " a"));
    assert(str_equal(items[3], " test"));

    cnt = str_split(" This  is   a    test   a  is This", "  ", items);
    assert(cnt == 6);
    assert(str_equal(items[0], " This"));
    assert(str_equal(items[1], "is"));
    assert(str_equal(items[2], " a"));
    assert(str_equal(items[3], "test"));
    assert(str_equal(items[4], " a"));
    assert(str_equal(items[5], "is This"));

    for (int i = 0; i < ITEM_NUM; i++) {
        free(items[i]);
        items[i] = NULL;
    }
    free(items);
    items = NULL;
}
