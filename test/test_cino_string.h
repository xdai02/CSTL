#ifndef _TEST_CINO_STRING_H_
#define _TEST_CINO_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "cino_utils.h"
#include "cino_string.h"

void test_string_create();
void test_string_destroy();
void test_string_get();
void test_string_set();
void test_string_length();
void test_string_clear();
void test_string_equal();
void test_string_equal_ignore_case();
void test_string_to_lower();
void test_string_to_upper();
void test_string_starts_with();
void test_string_ends_with();
void test_string_copy();
void test_string_concat();
void test_string_insert_char();
void test_string_insert_string();

#endif