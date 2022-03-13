#ifndef _TEST_CINO_STRING_H_
#define _TEST_CINO_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "cino_utils.h"
#include "cino_string.h"

void test_cino_string_create();
void test_cino_string_destroy();
void test_cino_string_get();
void test_cino_string_set();
void test_cino_string_length();
void test_cino_string_clear();
void test_cino_string_equal();
void test_cino_string_equal_ignore_case();
void test_cino_string_tolower();
void test_cino_string_toupper();
void test_cino_string_starts_with();
void test_cino_string_ends_with();
void test_cino_string_copy();
void test_cino_string_concat();

#endif