#ifndef _COOP_LIST_H_
#define _COOP_LIST_H_

#include "coop_utils.h"

typedef struct list_t list_t;

list_t *list_create(compare_t compare, destroy_t destroy);
void list_destroy(list_t *list);
void list_foreach(list_t *list, visit_t visit);
bool list_is_empty(const list_t *list);
size_t list_size(const list_t *list);
list_t *list_clear(list_t *list);
T list_get(const list_t *list, size_t index);
list_t *list_set(list_t *list, size_t index, T elem);
list_t *list_add(list_t *list, T elem);
list_t *list_insert(list_t *list, size_t index, T elem);

#endif
