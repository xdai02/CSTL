#include "test_hash_table.h"
#include "coop.h"
#include <assert.h>

#define N 10000

void test_hash_table_create() {
    hash_table_t *hash_table = hash_table_create(UnsignedCharacter_compare, UnsignedCharacter_delete, UnsignedCharacter_delete, UnsignedCharacter_hash);
    assert(hash_table != NULL);
    assert(hash_table_is_empty(hash_table) == true);
    assert(hash_table_size(hash_table) == 0);
    hash_table_destroy(hash_table);
}

void test_hash_table_destroy() {
    hash_table_t *hash_table = hash_table_create(UnsignedShort_compare, UnsignedShort_delete, UnsignedShort_delete, UnsignedShort_hash);
    assert(hash_table != NULL);
    hash_table_destroy(hash_table);
}

void test_hash_table_is_empty() {
    hash_table_t *hash_table = hash_table_create(UnsignedInteger_compare, UnsignedInteger_delete, UnsignedInteger_delete, UnsignedInteger_hash);
    assert(hash_table_is_empty(hash_table) == true);
    hash_table_put(hash_table, UnsignedInteger_new(0), UnsignedInteger_new(0));
    assert(hash_table_is_empty(hash_table) == false);
    hash_table_destroy(hash_table);
}

void test_hash_table_size() {
    int i = 0;
    hash_table_t *hash_table = NULL;

    hash_table = hash_table_create(UnsignedLong_compare, UnsignedLong_delete, UnsignedLong_delete, UnsignedLong_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        hash_table_put(hash_table, UnsignedLong_new(i), UnsignedLong_new(i));
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_destroy(hash_table);

    hash_table = hash_table_create(Integer_compare, Integer_delete, Integer_delete, Integer_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        hash_table_put(hash_table, Integer_new(i), Integer_new(i));
    }
    assert(hash_table_size(hash_table) == N);
    for (i = 0; i < N; i++) {
        hash_table_put(hash_table, Integer_new(i), Integer_new(N - i - 1));
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_destroy(hash_table);
}

void test_hash_table_clear() {
    int i = 0;
    hash_table_t *hash_table = hash_table_create(Short_compare, Short_delete, Short_delete, Short_hash);
    assert(hash_table_is_empty(hash_table) == true);
    for (i = 0; i < N; i++) {
        hash_table_put(hash_table, Short_new(i), Short_new(i));
    }
    assert(hash_table_size(hash_table) == N);
    hash_table_clear(hash_table);
    assert(hash_table_is_empty(hash_table) == true);
    hash_table_destroy(hash_table);
}

typedef struct Point {
    int x;
    int y;
} Point;

static Point *Point_create(int x, int y) {
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
    Integer *key;
    Integer *integer;
    char *string;
    Character *character;
    Point *point;

    hash_table = hash_table_create(Integer_compare, Integer_delete, Integer_delete, Integer_hash);
    for (i = 0; i < N; i++) {
        hash_table_put(hash_table, Integer_new(i), Integer_new(i));
    }
    assert(hash_table_size(hash_table) == N);
    for (i = 0; i < N; i++) {
        key = Integer_new(i);
        integer = hash_table_get(hash_table, key);
        assert(integer != NULL);
        assert(Integer_get(integer) == i);
        Integer_delete(key);
    }
    hash_table_destroy(hash_table);

    hash_table = hash_table_create(Integer_compare, Integer_delete, NULL, Integer_hash);
    hash_table_put(hash_table, Integer_new(0), "hello");
    hash_table_put(hash_table, Integer_new(1), "world");
    hash_table_put(hash_table, Integer_new(2), "test");

    assert(hash_table_size(hash_table) == 3);

    key = Integer_new(0);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "hello") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "world") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_table_put(hash_table, Integer_new(0), "HELLO");
    hash_table_put(hash_table, Integer_new(1), "WORLD");

    assert(hash_table_size(hash_table) == 3);

    key = Integer_new(0);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "HELLO") == 0);
    Integer_delete(key);

    key = Integer_new(1);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "WORLD") == 0);
    Integer_delete(key);

    key = Integer_new(2);
    string = hash_table_get(hash_table, key);
    assert(string != NULL);
    assert(strcmp(string, "test") == 0);
    Integer_delete(key);

    hash_table_destroy(hash_table);

    hash_table = hash_table_create(Point_compare, Point_delete, Character_delete, Point_hash);
    hash_table_put(hash_table, Point_create(1, 1), Character_new('A'));
    hash_table_put(hash_table, Point_create(1, 2), Character_new('B'));
    hash_table_put(hash_table, Point_create(2, 1), Character_new('C'));
    hash_table_put(hash_table, Point_create(2, 2), Character_new('D'));
    assert(hash_table_size(hash_table) == 4);

    point = Point_create(1, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'A');
    Point_delete(point);

    point = Point_create(1, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_create(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'C');
    Point_delete(point);

    point = Point_create(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    hash_table_put(hash_table, Point_create(1, 1), Character_new('a'));
    hash_table_put(hash_table, Point_create(2, 1), Character_new('c'));
    hash_table_put(hash_table, Point_create(3, 3), Character_new('E'));

    assert(hash_table_size(hash_table) == 5);

    point = Point_create(1, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'a');
    Point_delete(point);

    point = Point_create(1, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'B');
    Point_delete(point);

    point = Point_create(2, 1);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'c');
    Point_delete(point);

    point = Point_create(2, 2);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'D');
    Point_delete(point);

    point = Point_create(3, 3);
    character = (Character *)hash_table_get(hash_table, point);
    assert(character != NULL);
    assert(Character_get(character) == 'E');
    Point_delete(point);

    hash_table_destroy(hash_table);
}

void test_hash_table_remove() {
}

void test_hash_table_get() {
}
