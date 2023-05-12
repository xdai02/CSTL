# hash_set_t

[TOC]



## hash_set_new()

- Prototype

```c
hash_set_t *hash_set_new(compare_t compare, destroy_t destroy, hash_t hash);
```

- Description
    - Create a `hash_set_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
    - `hash`: Callback function for hashing a data item.
- Return
    - Returns the created `hash_set_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer set using Integer wrapper
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

// Create a double set using Double wrapper
hash_set_t *set2 = unhash_set_new(Double_compare, Double_delete, Double_hash);

// Create a boolean set using Boolean wrapper
hash_set_t *set3 = hash_set_new(Boolean_compare, Boolean_delete, Boolean_hash);

// Create a character set using Character wrapper
hash_set_t *set4 = hash_set_new(Character_compare, Character_delete, Character_hash);
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

// Callback function for destroying an employee
void Employee_delete(void *ptr) {
    Employee *e = (Employee *)ptr;
    free(e);
}

// Callback function for hashing an employee
size_t Employee_hash(const void *ptr) {
    const Employee *e = (Employee *)ptr;
    return (size_t)age;
}

// Create a set of employees
hash_set_t *employees = hash_set_new(Employee_compare, Employee_delete, Employee_hash);

// ...
```



## hash_set_delete()

- Prototype

```c
void hash_set_delete(hash_set_t *set);
```

- Description
    - Destroy a `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_delete(set);
```



## hash_set_is_empty()

- Prototype

```c
bool hash_set_is_empty(const hash_set_t *set);
```

- Description
    - Determine whether a `hash_set_t` object is empty.
- Parameters
    - `set`: The `hash_set_t` object.
- Return
    - Returns `true` if the `hash_set_t` object is empty, otherwise returns `false`.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
if (hash_set_is_empty(set)) {
    // ...
}
hash_set_delete(set);
```



## hash_set_size()

- Prototype

```c
size_t hash_set_size(const hash_set_t *set);
```

- Description
    - Get the size of a `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
- Return
    - Returns the size of the `hash_set_t` object.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
printf("%d\n", hash_set_size(set));
hash_set_delete(set);
```



## hash_set_foreach()

- Prototype

```c
void hash_set_foreach(hash_set_t *set, visit_t visit);
```

- Description
    - Traverse a `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
    - `visit`: Callback function for visiting a data item.
- Usage

```c
// Callback function for printing an integer
void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

// Callback function for tripling an integer
void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

int main() {
    // Create a set of integers
    hash_set_t *set = hash_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        hash_set_add(set, Integer_new(i));
    }

    // Print the set
    hash_set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    hash_set_foreach(set, Integer_triple);

    // Print the set
    hash_set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    hash_set_delete(set);

    return 0;
}
```



## hash_set_clear()

- Prototype

```c
hash_set_t *hash_set_clear(hash_set_t *set);
```

- Description
    - Clear a `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
- Return
    - Returns the modified `hash_set_t` object.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

hash_set_clear(set);
hash_set_delete(set);
```



## hash_set_contains()

- Prototype

```c
bool hash_set_contains(const hash_set_t *set, T elem);
```

- Description
    - Check if a `hash_set_t` object contains the specified element.
- Parameters
    - `set`: The `hash_set_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `hash_set_t` object contains the specified element, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (hash_set_contains(set, target)) {
    // ...
}
Integer_delete(target);

hash_set_delete(set);
```



## hash_set_add()

- Prototype

```c
hash_set_t *hash_set_add(hash_set_t *set, T elem);
```

- Description
    - Add an element to the `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `hash_set_t` object.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}
hash_set_delete(set);
```



## hash_set_remove()

- Prototype

```c
hash_set_t *hash_set_remove(hash_set_t *set, T elem);
```

- Description
    - Remove the element from the `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `hash_set_t` object.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

Integer *integer = Integer_new(5);
hash_set_remove(array, integer);
Integer_delete(integer);

hash_set_delete(set);
```



## hash_set_union()

- Prototype

```c
hash_set_t *hash_set_union(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Get the union of two `hash_set_t` objects.
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns the union of two `hash_set_t` objects.
- Note
    - Caller **MUST** destroy the returned union `hash_set_t` object.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_union(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_intersection()

- Prototype

```c
hash_set_t *hash_set_intersection(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Get the intersection of two `hash_set_t` objects.
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns the intersection of two `hash_set_t` objects.
- Note
    - Caller **MUST** destroy the returned intersection `hash_set_t` object.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_intersection(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_difference()

- Prototype

```c
hash_set_t *hash_set_difference(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Get the difference of two `hash_set_t` objects.
    - $ A - B $
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns the difference of two `hash_set_t` objects.
- Note
    - Caller **MUST** destroy the returned difference `hash_set_t` object.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_difference(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_symmetric_difference()

- Prototype

```c
hash_set_t *hash_set_symmetric_difference(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Get the symmetric difference of two `hash_set_t` objects.
    - $ (A - B) \cup (B - A) $
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns the symmetric difference  of two `hash_set_t` objects.
- Note
    - Caller **MUST** destroy the returned symmetric difference `hash_set_t` object.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_symmetric_difference(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_is_disjoint()

- Prototype

```c
bool hash_set_is_disjoint(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Determine if two `hash_set_t` objects are disjoint.
    - Two sets are disjoint if their intersection is empty.
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns `true` if two `hash_set_t` objects are disjoint, otherwise returns `false`.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    hash_set_add(set2, Integer_new(i));
}

if (hash_set_is_disjoint(set1, set2)) {
    // ...
}

hash_set_delete(set1);
hash_set_delete(set2);
```



## hash_set_is_subset()

- Prototype

```c
bool hash_set_is_subset(const hash_set_t *set1, const hash_set_t *set2);
```

- Description
    - Determine if `set1` is a subset of `set2`.
    - A is a subset B if every element of A is also an element of B.
- Parameters
    - `set1`: The first `hash_set_t` object.
    - `set2`: The second `hash_set_t` object.
- Return
    - Returns `true` if `set1` is a subset of `set2`, otherwise returns `false`.
- Usage

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 5; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    hash_set_add(set2, Integer_new(i));
}

if (hash_set_is_subset(set1, set2)) {
    // ...
}

hash_set_delete(set1);
hash_set_delete(set2);
```



## hash_set_iterator_new()

- Prototype

```c
iterator_t *hash_set_iterator_new(const hash_set_t *set);
```

- Description
    - Create an iterator for a `hash_set_t` object.
- Parameters
    - `set`: The `hash_set_t` object.
- Return
    - Returns the iterator for container.



## hash_set_iterator_delete()

- Prototype

```c
void hash_set_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## hash_set_iterator_has_next()

- Prototype

```c
bool hash_set_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## hash_set_iterator_next()

- Prototype

```c
T hash_set_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
for (i = 0; i < 10; i++) {
    hash_set_add(array, Integer_new(i));
}

iterator_t *iterator = hash_set_iterator_new(array);
while (hash_set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)hash_set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

hash_set_iterator_delete(iterator);
hash_set_delete(set);
```

