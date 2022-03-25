#include "cino_array.h"

/****************************************
 *              list_int_t
 ****************************************/

typedef struct node_t {
    int i_data;
    double d_data;
    void *p_data;
    struct node_t *prev;
    struct node_t *next;
} node_t;

typedef struct list_int_t {
    int *arr;
    size_t size;
} list_int_t;

/*
create()
destroy()
clear()
is_empty()
get()
set()
index_of()
get_front()
get_back()
push_front()
push_back()
pop_front()
pop_back()
insert()
remove()
*/