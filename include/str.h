#ifndef _STR_H_
#define _STR_H_

#include "coop_utils.h"

char *str_clear(char *str);
bool str_equal(const char *s1, const char *s2);
bool str_equal_ignore_case(const char *s1, const char *s2);
char *str_tolower(char *str);
char *str_toupper(char *str);
bool str_starts_with(const char *str, const char *prefix);
bool str_ends_with(const char *str, const char *suffix);
int str_index_of_char(const char *str, char c);
int str_index_of_string(const char *str, const char *substr);
char *str_reverse(char *str);
char *str_trim(char *str);
char *str_substring(const char *str, int start, int end);
int str_count_substring(const char *str, const char *substr);
char *str_append_char(char *str, char c);
char *str_insert_char(char *str, int index, char c);
char *str_insert_string(char *str, int index, const char *substr);
char *str_remove_char(char *str, char c);
char *str_remove_string(char *str, const char *substr);
char *str_replace_char(char *str, char old_char, char new_char);
char *str_replace_string(char *str, const char *old_str, const char *new_str);
char **str_split(const char *str, const char *delimiter);

#endif