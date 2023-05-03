#include "red_black_tree.h"

typedef enum {
    RED,
    BLACK
} color_t;

typedef struct node_t {
    int key;
    color_t color;
} node_t;


