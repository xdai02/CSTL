# pair_t

[TOC]



## pair_new()

- Prototype

```c
pair_t *pair_new(T key, T value, destroy_t destroy_key, destroy_t destroy_value);
```

- Description
    - Create a `pair_t` object.
- Parameters
    - `key`: The key.
    - `value`: The value.
    - `destroy_key`: Callback function for destroying the key.
    - `destroy_value`: Callback function for destroying the value.
- Return
    - Returns the created `pair_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create a (int, int) pair
pair_t *pair1 = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);

// Create a (int, string) pair
pair_t *pair2 = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
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

// Create a (Point, char) pair
pair_t *pair3 = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
```



## pair_delete()

- Prototype

```c
void pair_delete(pair_t *pair);
```

- Description
    - Destroy a `pair_t` object.
- Parameters
    - `pair`: The `pair_t` object.
- Usage

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_delete(pair);
```



## pair_get_key()

- Prototype

```c
T pair_get_key(const pair_t *pair);
```

- Description
    - Get the key of a `pair_t` object.
- Parameters
    - `pair`: The `pair_t` object.
- Return
    - Returns the key of the `pair_t` object.
- Usage

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
Integer *key = pair_get_key(pair);
printf("%d\n", Integer_get(key));
pair_delete(pair);
```



## pair_get_value()

- Prototype

```c
T pair_get_value(const pair_t *pair);
```

- Description
    - Get the value of a `pair_t` object.
- Parameters
    - `pair`: The `pair_t` object.
- Return
    - Returns the value of the `pair_t` object.
- Usage

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
Integer *value = pair_get_value(pair);
printf("%d\n", Integer_get(value));
pair_delete(pair);
```



## pair_set_key()

- Prototype

```c
pair_t *pair_set_key(pair_t *pair, T key);
```

- Description
    - Set the key of a `pair_t` object.
- Parameters
    - `pair`: The `pair_t` object.
    - `key`: The key.
- Return
    - Returns the modified `pair_t` object.
- Usage

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_set_key(Integer_new(3));
Integer *key = pair_get_key(pair);
printf("%d\n", Integer_get(key));
pair_delete(pair);
```



## pair_set_value()

- Prototype

```c
pair_t *pair_set_value(pair_t *pair, T value);
```

- Description
    - Set the value of a `pair_t` object.
- Parameters
    - `pair`: The `pair_t` object.
    - `value`: The value.
- Return
    - Returns the modified `pair_t` object.
- Usage

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_set_value(Integer_new(9));
Integer *value = pair_get_value(pair);
printf("%d\n", Integer_get(value));
pair_delete(pair);
```

