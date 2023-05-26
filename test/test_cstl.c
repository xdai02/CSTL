#include <stdio.h>
#include "test_utils/test_numeric.h"
#include "test_utils/test_random.h"
#include "test_utils/test_c_str.h"
#include "test_utils/test_wrapper.h"
#include "test_cstl/test_str.h"
#include "test_cstl/test_array.h"
#include "test_cstl/test_list.h"
#include "test_cstl/test_stack.h"
#include "test_cstl/test_queue.h"
#include "test_cstl/test_deque.h"
#include "test_cstl/test_heap.h"
#include "test_cstl/test_red_black_tree.h"
#include "test_cstl/test_hash_table.h"
#include "test_cstl/test_tree_set.h"
#include "test_cstl/test_hash_set.h"
#include "test_cstl/test_tree_map.h"
#include "test_cstl/test_hash_map.h"

void test_numeric() {
    test_min();
    test_max();
    test_swap();
    test_float_equal();
    test_double_equal();

    printf("[PASS] numeric\n");
}

void test_random() {
    test_randint();
    test_uniform();
    test_shuffle();

    printf("[PASS] random\n");
}

void test_c_str() {
    test_str_clear();
    test_str_equal();
    test_str_equal_ignore_case();
    test_str_tolower();
    test_str_toupper();
    test_str_starts_with();
    test_str_ends_with();
    test_str_index_of_char();
    test_str_index_of_string();
    test_str_contains_string();
    test_str_reverse();
    test_str_strip();
    test_str_substring();
    test_str_count_substring();
    test_str_append_char();
    test_str_insert_char();
    test_str_insert_string();
    test_str_remove_char();
    test_str_remove_string();
    test_str_replace_char();
    test_str_replace_string();
    test_str_split();

    printf("[PASS] c_str\n");
}

void test_wrapper() {
    test_Character();
    test_UnsignedCharacter();
    test_Short();
    test_UnsignedShort();
    test_Integer();
    test_UnsignedInteger();
    test_Long();
    test_UnsignedLong();
    test_Float();
    test_Double();
    test_Boolean();

    printf("[PASS] wrapper\n");
}

void test_utils() {
    test_numeric();
    test_random();
    test_c_str();
    test_wrapper();
}

void test_str() {
    test_string_new();
    test_string_delete();
    test_string_clone();
    test_string_length();
    test_string_is_empty();
    test_string_get();
    test_string_char_at();
    test_string_set_char_at();
    test_string_clear();
    test_string_equal();
    test_string_equal_ignore_case();
    test_string_compare();
    test_string_tolower();
    test_string_toupper();
    test_string_starts_with();
    test_string_ends_with();
    test_string_index_of_char();
    test_string_index_of_string();
    test_string_contains_string();
    test_string_reverse();
    test_string_strip();
    test_string_substring();
    test_string_count_substring();
    test_string_append_char();
    test_string_insert_char();
    test_string_concat();
    test_string_insert_string();
    test_string_remove_char();
    test_string_remove_string();
    test_string_replace_char();
    test_string_replace_string();
    test_string_split();

    printf("[PASS] str\n");
}

void test_array() {
    test_array_new();
    test_array_delete();
    test_array_is_empty();
    test_array_size();
    test_array_foreach();
    test_array_clear();
    test_array_get();
    test_array_set();
    test_array_swap();
    test_array_append();
    test_array_insert();
    test_array_remove();
    test_array_index_of();
    test_array_contains();
    test_array_count();
    test_array_reverse();
    test_array_sort();
    test_array_iterator();

    printf("[PASS] array\n");
}

void test_list() {
    test_list_new();
    test_list_delete();
    test_list_is_empty();
    test_list_size();
    test_list_foreach();
    test_list_clear();
    test_list_get();
    test_list_set();
    test_list_index_of();
    test_list_contains();
    test_list_get_front();
    test_list_get_back();
    test_list_push_front();
    test_list_push_back();
    test_list_pop_front();
    test_list_pop_back();
    test_list_insert();
    test_list_remove();
    test_list_count();
    test_list_reverse();
    test_list_iterator();

    printf("[PASS] list\n");
}

void test_stack() {
    test_stack_new();
    test_stack_delete();
    test_stack_is_empty();
    test_stack_size();
    test_stack_clear();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();

    printf("[PASS] stack\n");
}

void test_queue() {
    test_queue_new();
    test_queue_delete();
    test_queue_is_empty();
    test_queue_size();
    test_queue_clear();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_peek();

    printf("[PASS] queue\n");
}

void test_deque() {
    test_deque_new();
    test_deque_delete();
    test_deque_is_empty();
    test_deque_size();
    test_deque_clear();
    test_deque_push_front();
    test_deque_push_back();
    test_deque_pop_front();
    test_deque_pop_back();
    test_deque_get_front();
    test_deque_get_back();

    printf("[PASS] deque\n");
}

void test_heap() {
    test_heap_new();
    test_heap_delete();
    test_heap_is_empty();
    test_heap_size();
    test_heap_clear();
    test_heap_push();
    test_heap_pop();
    test_heap_peek();

    printf("[PASS] heap\n");
}

void test_red_black_tree() {
    test_red_black_tree_new();
    test_red_black_tree_delete();
    test_red_black_tree_is_empty();
    test_red_black_tree_size();
    test_red_black_tree_clear();
    test_red_black_tree_contains();
    test_red_black_tree_foreach();
    test_red_black_tree_insert();
    test_red_black_tree_remove();
    test_red_black_tree_iterator();

    printf("[PASS] red_black_tree\n");
}

void test_hash_table() {
    test_hash_table_new();
    test_hash_table_delete();
    test_hash_table_is_empty();
    test_hash_table_size();
    test_hash_table_foreach();
    test_hash_table_clear();
    test_hash_table_contains();
    test_hash_table_put();
    test_hash_table_remove();
    test_hash_table_get();
    test_hash_table_iterator();

    printf("[PASS] hash_table\n");
}

void test_tree_set() {
    test_tree_set_new();
    test_tree_set_delete();
    test_tree_set_is_empty();
    test_tree_set_size();
    test_tree_set_foreach();
    test_tree_set_clear();
    test_tree_set_contains();
    test_tree_set_add();
    test_tree_set_remove();
    test_tree_set_union();
    test_tree_set_intersection();
    test_tree_set_difference();
    test_tree_set_symmetric_difference();
    test_tree_set_is_disjoint();
    test_tree_set_is_subset();
    test_tree_set_iterator();

    printf("[PASS] tree_set\n");
}

void test_hash_set() {
    test_hash_set_new();
    test_hash_set_delete();
    test_hash_set_is_empty();
    test_hash_set_size();
    test_hash_set_foreach();
    test_hash_set_clear();
    test_hash_set_contains();
    test_hash_set_add();
    test_hash_set_remove();
    test_hash_set_union();
    test_hash_set_intersection();
    test_hash_set_difference();
    test_hash_set_symmetric_difference();
    test_hash_set_is_disjoint();
    test_hash_set_is_subset();
    test_hash_set_iterator();

    printf("[PASS] hash_set\n");
}

void test_tree_map() {
    test_tree_map_new();
    test_tree_map_delete();
    test_tree_map_is_empty();
    test_tree_map_size();
    test_tree_map_foreach();
    test_tree_map_clear();
    test_tree_map_contains();
    test_tree_map_put();
    test_tree_map_remove();
    test_tree_map_get();
    test_tree_map_iterator();

    printf("[PASS] tree_map\n");
}

void test_hash_map() {
    test_hash_map_new();
    test_hash_map_delete();
    test_hash_map_is_empty();
    test_hash_map_size();
    test_hash_map_foreach();
    test_hash_map_clear();
    test_hash_map_contains();
    test_hash_map_put();
    test_hash_map_remove();
    test_hash_map_get();
    test_hash_map_iterator();

    printf("[PASS] hash_map\n");
}

void test_cstl() {
    test_str();
    test_array();
    test_list();
    test_stack();
    test_queue();
    test_deque();
    test_heap();
    test_red_black_tree();
    test_hash_table();
    test_tree_set();
    test_hash_set();
    test_tree_map();
    test_hash_map();
}

int main() {
    test_utils();
    test_cstl();
    
    printf("[PASS] ALL\n");
    return 0;
}
