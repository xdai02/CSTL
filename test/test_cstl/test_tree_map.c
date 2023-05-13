#include "test_tree_map.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_tree_map_new() {
    tree_map_t *map = tree_map_new(UnsignedLong_compare, UnsignedLong_delete);
    assert(map != NULL);
    assert(tree_map_is_empty(map) == true);
    assert(tree_map_size(map) == 0);
    tree_map_delete(map);
}

void test_tree_map_delete() {
    tree_map_t *map = tree_map_new(UnsignedShort_compare, UnsignedShort_delete);
    assert(map != NULL);
    tree_map_delete(map);
}

void test_tree_map_is_empty() {
    tree_map_t *map = NULL;
    pair_t *pair;

    map = tree_map_new(UnsignedInteger_compare, (destroy_t)pair_delete);
    assert(tree_map_is_empty(map) == true);
    pair = pair_new(UnsignedInteger_new(0), UnsignedInteger_new(0), UnsignedInteger_delete, UnsignedInteger_delete);
    tree_map_put(map, pair);
    assert(tree_map_is_empty(map) == false);
    tree_map_delete(map);
}

void test_tree_map_size() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;

    map = tree_map_new(UnsignedInteger_compare, (destroy_t)pair_delete);
    assert(tree_map_size(map) == 0);
    for (i = 0; i < N; i++) {
        pair = pair_new(UnsignedInteger_new(i), UnsignedInteger_new(i), UnsignedInteger_delete, UnsignedInteger_delete);
        tree_map_put(map, pair);
    }
    assert(tree_map_size(map) == N);
    tree_map_delete(map);

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    assert(tree_map_size(map) == 0);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }
    assert(tree_map_size(map) == N);
    tree_map_delete(map);
}

static int keys[N] = {0};
static int values[N] = {0};
static int n = 0;

static void key_value_store(T pair) {
    Integer *key;
    Integer *value;

    pair = (pair_t *)pair;
    key = pair_get_key(pair);
    value = pair_get_value(pair);
    keys[n] = Integer_get(key);
    values[n] = Integer_get(value);
    n++;
}

void test_tree_map_foreach() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }

    n = 0;
    tree_map_foreach(map, key_value_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(keys[i] == i);
        assert(values[i] == i * i);
    }

    tree_map_delete(map);
}

void test_tree_map_clear() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    assert(tree_map_is_empty(map) == true);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }
    assert(tree_map_size(map) == N);
    tree_map_clear(map);
    assert(tree_map_is_empty(map) == true);
    tree_map_delete(map);
}

typedef struct Point {
    int x;
    int y;
} Point;

static Point *Point_new(int x, int y) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

static void Point_delete(void *ptr) {
    Point *point = ptr;
    free(point);
}

static int Point_compare(const void *ptr1, const void *ptr2) {
    const Point *point1 = ptr1;
    const Point *point2 = ptr2;
    if (point1->x < point2->x) {
        return -1;
    } else if (point1->x > point2->x) {
        return 1;
    } else {
        if (point1->y < point2->y) {
            return -1;
        } else if (point1->y > point2->y) {
            return 1;
        } else {
            return 0;
        }
    }
}

void test_tree_map_put() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }
    assert(tree_map_size(map) == N);

    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)tree_map_get(map, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    tree_map_delete(map);

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);

    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    tree_map_put(map, pair);

    assert(tree_map_size(map) == 3);

    key = Integer_new(0);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "hello") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "world") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    tree_map_put(map, pair);

    assert(tree_map_size(map) == 3);

    key = Integer_new(0);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    tree_map_delete(map);

    map = tree_map_new(Point_compare, (destroy_t)pair_delete);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    assert(tree_map_size(map) == 4);

    point = Point_new(1, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'A');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    tree_map_put(map, pair);

    assert(tree_map_size(map) == 5);

    point = Point_new(1, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    tree_map_delete(map);
}

void test_tree_map_remove() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    char *string;
    Character *character;
    Point *point;

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        tree_map_remove(map, key);
        Integer_delete(key);
    }
    assert(tree_map_is_empty(map) == true);
    tree_map_delete(map);

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    tree_map_put(map, pair);

    key = Integer_new(0);
    tree_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(1);
    tree_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(0);
    tree_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(3);
    tree_map_remove(map, key);
    Integer_delete(key);

    assert(tree_map_size(map) == 1);

    key = Integer_new(2);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    tree_map_delete(map);

    map = tree_map_new(Point_compare, (destroy_t)pair_delete);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    tree_map_put(map, pair);

    point = Point_new(1, 1);
    tree_map_remove(map, point);
    Point_delete(point);

    point = Point_new(1, 2);
    tree_map_remove(map, point);
    Point_delete(point);

    point = Point_new(3, 1);
    tree_map_remove(map, point);
    Point_delete(point);

    point = Point_new(3, 2);
    tree_map_remove(map, point);
    Point_delete(point);

    assert(tree_map_size(map) == 2);

    point = Point_new(2, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    tree_map_delete(map);
}

void test_tree_map_get() {
    int i = 0;
    tree_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)tree_map_get(map, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    tree_map_delete(map);

    map = tree_map_new(Integer_compare, (destroy_t)pair_delete);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    tree_map_put(map, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    tree_map_put(map, pair);

    key = Integer_new(0);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)tree_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    tree_map_delete(map);

    map = tree_map_new(Point_compare, (destroy_t)pair_delete);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    tree_map_put(map, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    tree_map_put(map, pair);

    point = Point_new(1, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)tree_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    tree_map_delete(map);
}
