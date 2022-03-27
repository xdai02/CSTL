#ifndef _TEST_CINO_UTILS_H_
#define _TEST_CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

void test_min();
void test_max();
void test_negate();
void test_swap();
void test_equal_double();

void test_return_if_fail();
void test_return_value_if_fail();
void test_call_and_return_if_fail();
void test_call_and_return_value_if_fail();

void test_array_len();

void test_cino_alloc();
void test_cino_realloc();

void test_str_to_bool();
void test_bool_to_str();
void test_str_to_char();
void test_char_to_str();
void test_str_to_int();
void test_int_to_str();
void test_str_to_double();
void test_double_to_str();

void test_wrap_int();
void test_unwrap_int();
void test_wrap_double();
void test_unwrap_double();

void test_str_equal();
void test_str_equal_ignore_case();
void test_str_to_lower();
void test_str_to_upper();
void test_str_starts_with();
void test_str_ends_with();
void test_str_clear();
void test_str_length();
void test_str_copy();
void test_str_concat();
void test_str_trim();
void test_str_append_char();
void test_str_append_int();
void test_str_append_double();
void test_str_insert_char();
void test_str_insert_string();
void test_str_substring();
void test_str_count_substring();
void test_str_replace_char();
void test_str_replace();
void test_str_remove();
void test_str_index_of_char();
void test_str_index_of_char_from();
void test_str_index_of_substring();
void test_str_index_of_substring_from();
void test_str_last_index_of_char();
void test_str_last_index_of_char_from();
void test_str_last_index_of_substring();
void test_str_last_index_of_substring_from();
void test_str_split();

#endif