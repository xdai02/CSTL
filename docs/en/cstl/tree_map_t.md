# tree_map_t

[TOC]



## tree_map_new()

- Prototype

```c
tree_map_t *tree_map_new(compare_t compare);
```

- Description
    - Create a `tree_map_t` object.
- Parameters
    - `compare`: Callback function for comparing two keys.
- Return
    - Returns the created `tree_map_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create a map with keys of integer type
tree_map_t *map1 = tree_map_new(Integer_compare);

// Create a map with keys of double type
tree_map_t *map2 = tree_map_new(Double_compare);

// Create a map with keys of boolean type
tree_map_t *map3 = tree_map_new(Boolean_compare);

// Create a map with keys of char type
tree_map_t *map4 = tree_map_new(Character_compare);
```

```c
typedef struct {
    char name[32];
    int age;
} Employee;

// Callback function for comparing two employees
int Employee_compare(const void *ptr1, const void *ptr2) {
    Employee *e1 = (Employee *)ptr1;
    Employee *e2 = (Employee *)ptr2;
    return e1->age - e2->age;
}

// Create a map of with keys of Employee type
tree_map_t *employees = tree_map_new(Employee_compare);

// ...
```



## tree_map_delete()

- Prototype

```c
void tree_map_delete(tree_map_t *map);
```

- Description
    - Destroy a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);
tree_map_delete(set);
```



## tree_map_is_empty()

- Prototype

```c
bool tree_map_is_empty(tree_map_t *map);
```

- Description
    - Determine whether a `tree_map_t` object is empty.
- Parameters
    - `map`: The `tree_map_t` object.
- Return
    - Returns `true` if the `tree_map_t` object is empty, otherwise returns `false`.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);
if (tree_map_is_empty(map)) {
    // ...
}
tree_map_delete(set);
```



## tree_map_size()

- Prototype

```c
size_t tree_map_size(tree_map_t *map);
```

- Description
    - Get the size of a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
- Return
    - Returns the size of the `tree_map_t` object.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);
printf("%d\n", tree_map_size(set));
tree_map_delete(map);
```



## tree_map_foreach()

- Prototype

```c
void tree_map_foreach(tree_map_t *map, visit_pair_t visit);
```

- Description
    - Traverse a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
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
    tree_map_t *map = tree_map_new(Integer_compare);

    for (int i = 0; i < 10; i++) {
        pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }

    tree_map_foreach(set, item_print);
    printf("\n");

    tree_map_delete(set);

    return 0;
}
```



## tree_map_clear()

- Prototype

```c
tree_map_t *tree_map_clear(tree_map_t *map);
```

- Description
    - Clear a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
- Return
    - Returns the modified `tree_map_t` object.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

tree_map_clear(set);
tree_map_delete(set);
```



## tree_map_contains()

- Prototype

```c
bool tree_map_contains(const tree_map_t *map, T key);
```

- Description
    - Check if a `tree_map_t` object contains the specified key.
- Parameters
    - `map`: The `tree_map_t` object.
    - `key`: The key.
- Return
    - Returns `true` if the `tree_map_t` object contains the specified key, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).

- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
if (tree_map_contains(map, target)) {
    // ...
}
Integer_delete(target);

tree_map_delete(map);
```



## tree_map_put()

- Prototype

```c
tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair);
```

- Description
    - Put a key-value pair into a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
    - `pair`: The `pair_t` object.
- Return
    - Returns the modified `tree_map_t` object.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);
for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}
tree_map_delete(map);
```



## tree_map_remove()

- Prototype

```c
tree_map_t *tree_map_remove(tree_map_t *map, T key);
```

- Description
    - Remove a key-value pair from a `tree_map_t` object by given key.
- Parameters
    - `map`: The `tree_map_t` object.
    - `key`: The key.
- Return
    - Returns the modified `tree_map_t` object.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).

- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
tree_map_remove(array, target);
Integer_delete(target);

tree_map_delete(map);
```



## tree_map_get()

- Prototype

```c
T tree_map_get(const tree_map_t *map, T key);
```

- Description
    - Get the value of a key-value pair by given key.
- Parameters
    - `map`: The `tree_map_t` object.
    - `key`: The key.
- Return
    - Returns the value of the key-value pair if found, otherwise `NULL`.
- Note
    - Caller **MUST** free the parameter `key` (if applicable).
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
Integer *value = tree_map_get(map, target);
printf("%d\n", Integer_get(value));
Integer_delete(value);

tree_map_delete(map);
```



## tree_map_iterator_new()

- Prototype

```c
iterator_t *tree_map_iterator_new(const tree_map_t *map);
```

- Description
    - Create an iterator for a `tree_map_t` object.
- Parameters
    - `map`: The `tree_map_t` object.
- Return
    - Returns the iterator for container.



## tree_map_iterator_delete()

- Prototype

```c
void tree_map_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## tree_map_iterator_has_next()

- Prototype

```c
bool tree_map_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## tree_map_iterator_next()

- Prototype

```c
T tree_map_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next pair of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next pair of the iterator.
- Usage

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

iterator_t *iterator = tree_map_iterator_new(map);
while (tree_map_iterator_has_next(iterator)) {
    pair = tree_map_iterator_next(iterator);
    key = (Integer *)pair_get_key(pair);
    value = (Integer *)pair_get_value(pair);
    printf("key: %d, value: %d\n", Integer_get(key), Integer_get(value));
}
tree_map_iterator_delete(iterator);

tree_map_delete(map);
```

