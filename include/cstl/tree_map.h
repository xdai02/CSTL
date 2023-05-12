#ifndef _TREE_MAP_H_
#define _TREE_MAP_H_

#include "utils/utils.h"
#include "cstl/pair.h"
#include "iterator.h"

typedef struct tree_map_t tree_map_t;

tree_map_t *tree_map_new(compare_t compare, destroy_t destroy);
void tree_map_delete(tree_map_t *map);
bool tree_map_is_empty(tree_map_t *map);
size_t tree_map_size(tree_map_t *map);
void tree_map_foreach(tree_map_t *map, visit_pair_t visit);
tree_map_t *tree_map_clear(tree_map_t *map);
tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair);
tree_map_t *tree_map_remove(tree_map_t *map, T key);
T tree_map_get(tree_map_t *map, T key);

#endif
