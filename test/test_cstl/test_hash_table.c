#include "test_hash_table.h"
#include "coop.h"
#include <assert.h>

#define N 1000

void test_hash_table_new() {
    hash_table_t *hash_table = hash_table_new(UnsignedCharacter_compare, UnsignedCharacter_hash);
    assert(hash_table != NULL);
    assert(hash_table_is_empty(hash_table) == true);
    assert(hash_table_size(hash_table) == 0);
    hash_table_delete(hash_table);
}

void test_hash_table_delete() {
    hash_table_t *hash_table = hash_table_new(UnsignedShort_compare, UnsignedShort_hash);
    assert(hash_table != NULL);
    hash_table_delete(hash_table);
}

void test_hash_table_is_empty() {
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    hash_table = hash_table_new(UnsignedInteger_compare, UnsignedInteger_hash);
    assert(hash_table_is_empty(hash_table) == true);
    pair = pair_new(UnsignedInteger_new(0), UnsignedInteger_new(0), UnsignedInteger_delete, UnsignedInteger_delete);
    hash_table_put(hash_table, pair);
    assert(hash_table_is_empty(hash_table) == false);
    hash_table_delete(hash_table);
}

void test_hash_table_size() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    hash_table = hash_table_new(UnsignedLong_compare, UnsignedLong_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        pair = pair_new(UnsignedLong_new(i), UnsignedLong_new(i), UnsignedLong_delete, UnsignedLong_delete);
        hash_table_put(hash_table, pair);
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_delete(hash_table);

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }
    assert(hash_table_size(hash_table) == N);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(N - i - 1), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_delete(hash_table);
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

void test_hash_table_foreach() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;

    hash_table = hash_table_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }

    n = 0;
    hash_table_foreach(hash_table, key_value_store);

    assert(n == N);
    for (i = 0; i < N; i++) {
        assert(keys[i] >= 0 && keys[i] < N);
        assert(values[i] == keys[i] * keys[i]);
    }

    hash_table_delete(hash_table);
}

void test_hash_table_clear() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;

    hash_table = hash_table_new(Short_compare, Short_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        pair = pair_new(Short_new(i), Short_new(i), Short_delete, Short_delete);
        hash_table_put(hash_table, pair);
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_clear(hash_table);
    assert(hash_table_is_empty(hash_table) == true);
    hash_table_delete(hash_table);
}

void test_hash_table_contains() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    Integer *key;

    hash_table = hash_table_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }

    for (i = 0; i < N; i++) {
        key = Integer_new(randint(0, 3 * N));
        if (Integer_get(key) < N) {
            assert(hash_table_contains(hash_table, key) == true);
        } else {
            assert(hash_table_contains(hash_table, key) == false);
        }
        Integer_delete(key);
    }

    hash_table_delete(hash_table);
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

void test_hash_table_put() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }
    assert(hash_table_size(hash_table) == N);
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)hash_table_get(hash_table, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    hash_table_delete(hash_table);

    hash_table = hash_table_new(Integer_compare, Integer_hash);

    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_table_put(hash_table, pair);

    assert(hash_table_size(hash_table) == 3);

    key = Integer_new(0);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "hello") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "world") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    hash_table_put(hash_table, pair);

    assert(hash_table_size(hash_table) == 3);

    key = Integer_new(0);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_table_delete(hash_table);

    hash_table = hash_table_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    assert(hash_table_size(hash_table) == 4);

    point = Point_new(1, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'A');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);

    assert(hash_table_size(hash_table) == 5);

    point = Point_new(1, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    hash_table_delete(hash_table);
}

void test_hash_table_remove() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    Integer *key;
    char *string;
    Character *character;
    Point *point;

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        hash_table_remove(hash_table, key);
        Integer_delete(key);
    }
    assert(hash_table_is_empty(hash_table) == true);
    hash_table_delete(hash_table);

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_table_put(hash_table, pair);

    key = Integer_new(0);
    hash_table_remove(hash_table, key);
    Integer_delete(key);

    key = Integer_new(1);
    hash_table_remove(hash_table, key);
    Integer_delete(key);

    key = Integer_new(0);
    hash_table_remove(hash_table, key);
    Integer_delete(key);

    key = Integer_new(3);
    hash_table_remove(hash_table, key);
    Integer_delete(key);

    assert(hash_table_size(hash_table) == 1);

    key = Integer_new(2);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_table_delete(hash_table);

    hash_table = hash_table_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);

    point = Point_new(1, 1);
    hash_table_remove(hash_table, point);
    Point_delete(point);

    point = Point_new(1, 2);
    hash_table_remove(hash_table, point);
    Point_delete(point);

    point = Point_new(3, 1);
    hash_table_remove(hash_table, point);
    Point_delete(point);

    point = Point_new(3, 2);
    hash_table_remove(hash_table, point);
    Point_delete(point);

    assert(hash_table_size(hash_table) == 2);

    point = Point_new(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    hash_table_delete(hash_table);
}

void test_hash_table_get() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = (Integer *)hash_table_get(hash_table, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    hash_table_delete(hash_table);

    hash_table = hash_table_new(Integer_compare, Integer_hash);
    pair = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(1), "world", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(2), "test", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(0), "HELLO", Integer_delete, NULL);
    hash_table_put(hash_table, pair);
    pair = pair_new(Integer_new(1), "WORLD", Integer_delete, NULL);
    hash_table_put(hash_table, pair);

    key = Integer_new(0);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = (char *)hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_table_delete(hash_table);

    hash_table = hash_table_new(Point_compare, Point_hash);
    pair = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(1, 2), Character_new('B'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 1), Character_new('C'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 2), Character_new('D'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(1, 1), Character_new('a'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(2, 1), Character_new('c'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);
    pair = pair_new(Point_new(3, 3), Character_new('E'), Point_delete, Character_delete);
    hash_table_put(hash_table, pair);

    point = Point_new(1, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_new(1, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_new(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_new(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_new(3, 3);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    hash_table_delete(hash_table);
}

void test_hash_table_iterator() {
    int i = 0;
    hash_table_t *hash_table = NULL;
    pair_t *pair;
    iterator_t *iterator = NULL;
    Integer *key;
    Integer *value;

    hash_table = hash_table_new(Integer_compare, Integer_hash);

    for (i = 0; i < N; i++) {
        pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_table_put(hash_table, pair);
    }

    iterator = hash_table_iterator_new(hash_table);
    while (hash_table_iterator_has_next(iterator)) {
        pair = hash_table_iterator_next(iterator);
        assert(pair != NULL);
        key = (Integer *)pair_get_key(pair);
        value = (Integer *)pair_get_value(pair);
        assert(Integer_get(value) == Integer_get(key) * Integer_get(key));
    }
    hash_table_iterator_delete(iterator);

    hash_table_delete(hash_table);
}
