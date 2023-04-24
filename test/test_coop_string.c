#include "test_coop_string.h"
#include "coop.h"
#include <assert.h>

void test_coop_string_create() {
    string_t *string = NULL;

    string = string_create("Hello World");
    assert(string != NULL);
    assert(string_length(string) == 11);
    assert(string_is_empty(string) == false);
    string_destroy(string);

    string = string_create("");
    assert(string != NULL);
    assert(string_length(string) == 0);
    assert(string_is_empty(string) == true);
    string_destroy(string);
}

void test_coop_string_destroy() {
    string_t *string = string_create("Hello World");
    assert(string != NULL);
    string_destroy(string);
    assert(string_length(string) == 0);
    assert(string_is_empty(string) == true);
}

void test_coop_string_clone() {
    string_t *s1 = string_create("Hello World");
    string_t *s2 = string_clone(s1);

    assert(s1 != NULL);
    assert(s2 != NULL);

    assert(string_length(s1) == string_length(s2));
    assert(string_is_empty(s1) == string_is_empty(s2));
    assert(string_equal(s1, s2) == true);

    string_destroy(s1);
    string_destroy(s2);
}

void test_coop_string_length() {
    
}