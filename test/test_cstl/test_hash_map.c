#include "test_hash_map.h"
#include "cstl.h"
#include <assert.h>

#define N 1000

void test_hash_map_new() {
    hash_map_t *map = hash_map_new(UnsignedLong_compare, UnsignedLong_hash);
    assert(map != NULL);
    assert(hash_map_is_empty(map) == true);
    assert(hash_map_size(map) == 0);
    hash_map_delete(map);
}

void test_hash_map_delete() {
    hash_map_t *map = hash_map_new(UnsignedShort_compare, UnsignedShort_hash);
    assert(map != NULL);
    hash_map_delete(map);
}

void test_hash_map_is_empty() {
    hash_map_t *map = NULL;
    pair_t *pair;

    map = hash_map_new(UnsignedInteger_compare, UnsignedInteger_hash);
    assert(hash_map_is_empty(map) == true);
    pair = pair_new(UnsignedInteger_new(0), UnsignedInteger_new(0), UnsignedInteger_delete, UnsignedInteger_delete);
    hash_map_put(map, pair);
    assert(hash_map_is_empty(map) == false);
    hash_map_delete(map);
}

void test_hash_map_size() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;

    map = hash_map_new(UnsignedInteger_compare, UnsignedInteger_hash);
    assert(hash_map_size(map) == 0);
    for (i = 0; i < N; i++) {
        pair = pair_new(UnsignedInteger_new(i), UnsignedInteger_new(i), UnsignedInteger_delete, UnsignedInteger_delete);
        hash_map_put(map, pair);
    }
    assert(hash_map_size(map) == N);
    hash_map_delete(map);

    map = hash_map_new(Integer_compare, Integer_hash);
    assert(hash_map_size(map) == 0);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }
    assert(hash_map_size(map) == N);
    hash_map_delete(map);
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

void test_hash_map_foreach() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;

    map = hash_map_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }

    n = 0;
    hash_map_foreach(map, key_value_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(keys[i] == i);
        assert(values[i] == i * i);
    }

    hash_map_delete(map);
}

void test_hash_map_clear() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;

    map = hash_map_new(Integer_compare, Integer_hash);
    assert(hash_map_is_empty(map) == true);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }
    assert(hash_map_size(map) == N);
    hash_map_clear(map);
    assert(hash_map_is_empty(map) == true);
    hash_map_delete(map);
}

void test_hash_map_contains() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;
    Integer *key;

    map = hash_map_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }

    for (i = 0; i < N; i++) {
        key = Integer_new(randint(0, 3 * N));
        if (Integer_get(key) < N) {
            assert(hash_map_contains(map, key) == true);
        } else {
            assert(hash_map_contains(map, key) == false);
        }
        Integer_delete(key);
    }

    hash_map_delete(map);
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

static size_t Point_hash(const void *ptr) {
    const Point *point = ptr;
    return (size_t)(point->x + point->y);
}

void test_hash_map_put() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    map = hash_map_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }
    assert(hash_map_size(map) == N);

    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)hash_map_get(map, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    hash_map_delete(map);

    map = hash_map_new(Integer_compare, Integer_hash);

    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_map_put(map, pair);

    assert(hash_map_size(map) == 3);

    key = Integer_new(0);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "hello") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "world") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    hash_map_put(map, pair);

    assert(hash_map_size(map) == 3);

    key = Integer_new(0);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_map_delete(map);

    map = hash_map_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    assert(hash_map_size(map) == 4);

    point = Point_new(1, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'A');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    hash_map_put(map, pair);

    assert(hash_map_size(map) == 5);

    point = Point_new(1, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    hash_map_delete(map);
}

void test_hash_map_remove() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    char *string;
    Character *character;
    Point *point;

    map = hash_map_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        hash_map_remove(map, key);
        Integer_delete(key);
    }
    assert(hash_map_is_empty(map) == true);
    hash_map_delete(map);

    map = hash_map_new(Integer_compare, Integer_hash);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_map_put(map, pair);

    key = Integer_new(0);
    hash_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(1);
    hash_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(0);
    hash_map_remove(map, key);
    Integer_delete(key);

    key = Integer_new(3);
    hash_map_remove(map, key);
    Integer_delete(key);

    assert(hash_map_size(map) == 1);

    key = Integer_new(2);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_map_delete(map);

    map = hash_map_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_map_put(map, pair);

    point = Point_new(1, 1);
    hash_map_remove(map, point);
    Point_delete(point);

    point = Point_new(1, 2);
    hash_map_remove(map, point);
    Point_delete(point);

    point = Point_new(3, 1);
    hash_map_remove(map, point);
    Point_delete(point);

    point = Point_new(3, 2);
    hash_map_remove(map, point);
    Point_delete(point);

    assert(hash_map_size(map) == 2);

    point = Point_new(2, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    hash_map_delete(map);
}

void test_hash_map_get() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    map = hash_map_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)hash_map_get(map, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    hash_map_delete(map);

    map = hash_map_new(Integer_compare, Integer_hash);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    hash_map_put(map, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    hash_map_put(map, pair);

    key = Integer_new(0);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_map_get(map, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_map_delete(map);

    map = hash_map_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    hash_map_put(map, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    hash_map_put(map, pair);

    point = Point_new(1, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)hash_map_get(map, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    hash_map_delete(map);
}

void test_hash_map_iterator() {
    int i = 0;
    hash_map_t *map = NULL;
    pair_t *pair;
    iterator_t *iterator = NULL;
    Integer *key;
    Integer *value;

    map = hash_map_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }

    iterator = hash_map_iterator_new(map);
    while (hash_map_iterator_has_next(iterator)) {
        pair = hash_map_iterator_next(iterator);
        assert(pair != NULL);
        key = (Integer *)pair_get_key(pair);
        value = (Integer *)pair_get_value(pair);
        assert(Integer_get(value) == Integer_get(key) * Integer_get(key));
    }
    hash_map_iterator_delete(iterator);

    hash_map_delete(map);
}
