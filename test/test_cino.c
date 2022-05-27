#include "test_cino_utils.h"
#include "test_cino_string.h"
#include "test_cino_array.h"
#include "test_cino_list.h"
#include "test_cino_stack.h"
#include "test_cino_queue.h"
#include "test_cino_deque.h"
#include "test_cino_tree.h"
#include "test_cino_set.h"
#include "test_cino_map.h"

void test_cino_utils() {
    test_min();
    test_max();
    test_negate();
    test_swap();
    test_double_equal();

    test_return_if_fail();
    test_return_value_if_fail();
    test_call_and_return_if_fail();
    test_call_and_return_value_if_fail();

    test_arr_len();
    test_arr_reverse();

    test_str_to_bool();
    test_bool_to_str();
    test_str_to_char();
    test_char_to_str();
    test_str_to_int();
    test_int_to_str();
    test_str_to_double();
    test_double_to_str();

    test_wrap_int();
    test_unwrap_int();
    test_wrap_double();
    test_unwrap_double();
    test_wrap_char();
    test_unwrap_char();

    test_str_equal();
    test_str_equal_ignore_case();
    test_str_starts_with();
    test_str_to_lower();
    test_str_to_upper();
    test_str_ends_with();
    test_str_clear();
    test_str_length();
    test_str_copy();
    test_str_concat();
    test_str_trim();
    test_str_append_char();
    test_str_append_int();
    test_str_append_double();
    test_str_insert_char();
    test_str_insert_string();
    test_str_substring();
    test_str_count_substring();
    test_str_replace_char();
    test_str_replace();
    test_str_remove();
    test_str_reverse();
    test_str_index_of_char();
    test_str_index_of_char_from();
    test_str_index_of_substring();
    test_str_index_of_substring_from();
    test_str_last_index_of_char();
    test_str_last_index_of_char_from();
    test_str_last_index_of_substring();
    test_str_last_index_of_substring_from();
    test_str_split();

    LOGGER(INFO, "[PASS] test_cino_utils");
}

void test_cino_string() {
    test_string_create();
    test_string_destroy();
    test_string_get();
    test_string_set();
    test_string_length();
    test_string_clear();
    test_string_equal();
    test_string_equal_ignore_case();
    test_string_to_lower();
    test_string_to_upper();
    test_string_starts_with();
    test_string_ends_with();
    test_string_copy();
    test_string_concat();
    test_string_trim();
    test_string_append_char();
    test_string_insert_char();
    test_string_insert_string();
    test_string_count_substring();
    test_string_replace_char();
    test_string_replace();
    test_string_remove();
    test_string_reverse();

    LOGGER(INFO, "[PASS] test_cino_string");
}

void test_cino_array() {
    test_array_create();
    test_array_destroy();
    test_array_is_empty();
    test_array_size();
    test_array_clear();
    test_array_foreach();
    test_array_get();
    test_array_set();
    test_array_append();
    test_array_insert();
    test_array_remove();
    test_array_min();
    test_array_max();
    test_array_index_of();
    test_array_last_index_of();
    test_array_count();
    test_array_reverse();
    test_array_swap();
    test_array_sort();

    LOGGER(INFO, "[PASS] test_cino_array");
}

void test_cino_list() {
    test_list_create();
    test_list_destroy();
    test_list_is_empty();
    test_list_size();
    test_list_clear();
    test_list_foreach();
    test_list_get_front();
    test_list_get_back();
    test_list_get();
    test_list_set();
    test_list_index_of();
    test_list_push_front();
    test_list_push_back();
    test_list_pop_front();
    test_list_pop_back();
    test_list_insert();
    test_list_remove();

    LOGGER(INFO, "[PASS] test_cino_list");
}

void test_cino_stack() {
    test_stack_create();
    test_stack_destroy();
    test_stack_is_empty();
    test_stack_size();
    test_stack_clear();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();

    LOGGER(INFO, "[PASS] test_cino_stack");
}

void test_cino_queue() {
    test_queue_create();
    test_queue_destroy();
    test_queue_is_empty();
    test_queue_size();
    test_queue_clear();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_get_front();

    LOGGER(INFO, "[PASS] test_cino_queue");
}

void test_cino_deque() {
    test_deque_create();
    test_deque_destroy();
    test_deque_is_empty();
    test_deque_size();
    test_deque_clear();
    test_deque_push_front();
    test_deque_pop_front();
    test_deque_get_front();
    test_deque_push_back();
    test_deque_pop_back();
    test_deque_get_back();

    LOGGER(INFO, "[PASS] test_cino_deque");
}

void test_cino_tree() {
    test_tree_create();
    test_tree_destroy();
    test_tree_is_empty();
    test_tree_size();
    test_tree_clear();
    test_tree_pre_order();
    test_tree_in_order();
    test_tree_post_order();
    test_tree_min();
    test_tree_max();
    test_tree_contains();
    test_tree_insert();
    test_tree_remove();
    test_tree_set();
    test_tree_node_array_create();
    test_tree_node_array_destroy();

    LOGGER(INFO, "[PASS] test_cino_tree");
}

void test_cino_set() {
    test_set_create();
    test_set_destroy();
    test_set_is_empty();
    test_set_size();
    test_set_clear();
    test_set_foreach();
    test_set_contains();
    test_set_add();
    test_set_remove();
    test_set_intersection();
    test_set_union();
    test_set_difference();

    LOGGER(INFO, "[PASS] test_cino_set");
}

void test_cino_map() {
    LOGGER(INFO, "[PASS] test_cino_map");
}

int main(int argc, char *argv[]) {
    test_cino_utils();
    test_cino_string();
    test_cino_array();
    test_cino_list();
    test_cino_stack();
    test_cino_queue();
    test_cino_deque();
    test_cino_tree();
    test_cino_set();
    test_cino_map();

    return 0;
}