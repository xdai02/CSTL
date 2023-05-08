#include <stdio.h>
#include "coop.h"

typedef struct Point {
    int x;
    int y;
} Point;

Point *Point_create(int x, int y) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

void Point_delete(void *ptr) {
    Point *point = ptr;
    free(point);
}

int Point_compare(const void *ptr1, const void *ptr2) {
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

size_t Point_hash(const void *ptr) {
    const Point *point = ptr;
    return (size_t)(point->x + point->y);
}

void Point_print(T key, T value) {
    Point *point = key;
    char *string = value;
    printf("(%d, %d): %s\n", point->x, point->y, string);
}

int main() {
    hash_table_t *hash_table = hash_table_create(Point_compare, Point_delete, NULL, Point_hash);

    hash_table_put(hash_table, Point_create(1, 1), "P1");
    hash_table_put(hash_table, Point_create(1, 2), "P2");
    hash_table_put(hash_table, Point_create(2, 1), "P3");
    hash_table_put(hash_table, Point_create(2, 2), "P4");

    hash_table_foreach(hash_table, Point_print);
    printf("\n");

    Point *key;

    key = Point_create(2, 1);
    char *value = hash_table_get(hash_table, key);
    printf("Value: %s\n", value);
    Point_delete(key);

    key = Point_create(1, 2);
    hash_table_remove(hash_table, key);
    Point_delete(key);

    hash_table_foreach(hash_table, Point_print);
    printf("\n");

    hash_table_destroy(hash_table);
    return 0;
}
