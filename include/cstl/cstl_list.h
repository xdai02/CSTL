#ifndef _CSTL_LIST_H_
#define _CSTL_LIST_H_

#include "utils.h"
#include "iterator.h"

typedef struct list_t list_t;

list_t *list_create(compare_t compare, destroy_t destroy);
void list_destroy(list_t *list);
void list_foreach(list_t *list, visit_t visit);
bool list_is_empty(const list_t *list);
size_t list_size(const list_t *list);
list_t *list_clear(list_t *list);
T list_get(const list_t *list, size_t index);
list_t *list_set(list_t *list, size_t index, T elem);
int list_index_of(const list_t *list, T elem);
bool list_contains(const list_t *list, T elem);
T list_get_front(const list_t *list);
T list_get_back(const list_t *list);
list_t *list_push_front(list_t *list, T elem);
list_t *list_push_back(list_t *list, T elem);
T list_pop_front(list_t *list);
T list_pop_back(list_t *list);
list_t *list_insert(list_t *list, size_t index, T elem);
T list_remove(list_t *list, size_t index);
iterator_t *list_iterator_create(const list_t *list);
void list_iterator_destroy(iterator_t *iterator);
bool list_iterator_has_next(const iterator_t *iterator);
T list_iterator_next(iterator_t *iterator);

#endif
