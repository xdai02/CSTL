# hash_map_t

[TOC]



## hash_map_new()

- Prototype

```c
hash_map_t *hash_map_new(compare_t compare, hash_t hash);
```

- Description
    - Create a `hash_map_t` object.
- Parameters
    - `compare`: Callback function for comparing two keys.
    - `hash`: Callback function for hashing a key.
- Return
    - Returns the created `hash_map_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create a map with keys of integer type
hash_map_t *map1 = tree_map_new(Integer_compare, Integer_hash);

// Create a map with keys of double type
hash_map_t *map2 = tree_map_new(Double_compare, Double_hash);

// Create a map with keys of boolean type
hash_map_t *map3 = tree_map_new(Boolean_compare, Boolean_hash);

// Create a map with keys of char type
hash_map_t *map4 = tree_map_new(Character_compare, Character_hash);
```

```c
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

// Create a map of with keys of Point type
hash_map_t *points = hash_map_new(Point_compare, Point_hash);

// ...
```



## hash_map_delete()

- Prototype

```c
void hash_map_delete(hash_map_t *map);
```

- Description
    - Destroy a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
hash_map_delete(set);
```



## hash_map_is_empty()

- Prototype

```c
bool hash_map_is_empty(hash_map_t *map);
```

- Description
    - Determine whether a `hash_map_t` object is empty.
- Parameters
    - `map`: The `hash_map_t` object.
- Return
    - Returns `true` if the `hash_map_t` object is empty, otherwise returns `false`.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
if (hash_map_is_empty(map)) {
    // ...
}
hash_map_delete(set);
```



## hash_map_size()

- Prototype

```c
size_t hash_map_size(hash_map_t *map);
```

- Description
    - Get the size of a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
- Return
    - Returns the size of the `hash_map_t` object.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
printf("%d\n", hash_map_size(set));
hash_map_delete(map);
```



## hash_map_foreach()

- Prototype

```c
void hash_map_foreach(hash_map_t *map, visit_pair_t visit);
```

- Description
    - Traverse a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
    - `visit`: Callback function for visiting a key-value pair.
- Usage

```c
// Callback function for printing an integer
void item_print(T pair) {
    pair = (pair_t *)pair;
    Integer *key = pair_get_key(pair);
    Integer *value = pair_get_value(pair);
    printf("key: %d, value: %d\n", Integer_get(key), Integer_get(value));
}

int main() {
    hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

    for (int i = 0; i < 10; i++) {
        pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }

    hash_map_foreach(map, item_print);
    printf("\n");

    hash_map_delete(map);

    return 0;
}
```



## hash_map_clear()

- Prototype

```c
hash_map_t *hash_map_clear(hash_map_t *map);
```

- Description
    - Clear a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
- Return
    - Returns the modified `hash_map_t` object.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

hash_map_clear(map);
hash_map_delete(map);
```



## hash_map_contains()

- Prototype

```c
bool hash_map_contains(const hash_map_t *map, T key);
```

- Description
    - Check if a `hash_map_t` object contains the specified key.
- Parameters
    - `map`: The `hash_map_t` object.
    - `key`: The key.
- Return
    - Returns `true` if the `hash_map_t` object contains the specified key, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).

- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
if (hash_map_contains(map, target)) {
    // ...
}
Integer_delete(target);

hash_map_delete(map);
```



## hash_map_put()

- Prototype

```c
hash_map_t *hash_map_put(hash_map_t *map, pair_t *pair);
```

- Description
    - Put a key-value pair into a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
    - `pair`: The `pair_t` object.
- Return
    - Returns the modified `hash_map_t` object.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}
hash_map_delete(map);
```



## hash_map_remove()

- Prototype

```c
hash_map_t *hash_map_remove(hash_map_t *map, T key);
```

- Description
    - Remove a key-value pair from a `hash_map_t` object by given key.
- Parameters
    - `map`: The `hash_map_t` object.
    - `key`: The key.
- Return
    - Returns the modified `hash_map_t` object.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).

- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
hash_map_remove(array, target);
Integer_delete(target);

hash_map_delete(map);
```



## tree_mahash_map_get_get()

- Prototype

```c
T hash_map_get(const hash_map_t *map, T key);
```

- Description
    - Get the value of a key-value pair by given key.
- Parameters
    - `map`: The `hash_map_t` object.
    - `key`: The key.
- Return
    - Returns the value of the key-value pair if found, otherwise `NULL`.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
Integer *value = hash_map_get(map, target);
printf("%d\n", Integer_get(value));
Integer_delete(value);

hash_map_delete(map);
```



## hash_map_iterator_new()

- Prototype

```c
iterator_t *hash_map_iterator_new(const hash_map_t *map);
```

- Description
    - Create an iterator for a `hash_map_t` object.
- Parameters
    - `map`: The `hash_map_t` object.
- Return
    - Returns the iterator for container.



## hash_map_iterator_delete()

- Prototype

```c
void hash_map_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## hash_map_iterator_has_next()

- Prototype

```c
bool hash_map_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## hash_map_iterator_next()

- Prototype

```c
T hash_map_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next pair of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next pair of the iterator.
- Usage

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

iterator_t *iterator = tree_map_iterator_new(map);
while (hash_map_iterator_has_next(iterator)) {
    pair = hash_map_iterator_next(iterator);
    key = (Integer *)pair_get_key(pair);
    value = (Integer *)pair_get_value(pair);
    printf("key: %d, value: %d\n", Integer_get(key), Integer_get(value));
}
hash_map_iterator_delete(iterator);

hash_map_delete(map);
```

