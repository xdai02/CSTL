#ifndef _TEST_CINO_UTILS_H_
#define _TEST_CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

void test_return_if_fail();
void test_return_value_if_fail();
void test_call_and_return_if_fail();
void test_call_and_return_value_if_fail();

void test_array_len();

void test_string_to_bool();
void test_bool_to_string();
void test_string_to_char();
void test_char_to_string();
void test_string_to_int();
void test_int_to_string();
void test_string_to_double();
void test_double_to_string();

void test_string_equal();
void test_equals_ignore_case();
void test_string_tolower();
void test_string_toupper();
void test_string_starts_with();
void test_string_ends_with();
void test_string_clear();
void test_string_length();
void test_string_copy();
void test_string_concat();
void test_string_trim();
void test_string_append_char();
void test_string_append_int();
void test_string_append_double();
void test_string_insert_char();
void test_string_insert_string();
void test_string_substring();
void test_string_replace_char();
void test_string_replace();
void test_string_remove();
void test_string_index_of_char();
void test_string_index_of_char_from();
void test_string_index_of_substring();
void test_string_index_of_substring_from();
void test_string_last_index_of_char();
void test_string_last_index_of_char_from();
void test_string_last_index_of_substring();
void test_string_last_index_of_substring_from();

#endif