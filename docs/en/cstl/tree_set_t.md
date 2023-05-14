# tree_set_t

[TOC]



## tree_set_new()

- Prototype

```c
tree_set_t *tree_set_new(compare_t compare, destroy_t destroy);
```

- Description
    - Create a `tree_set_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `tree_set_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer set using Integer wrapper
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);

// Create a double set using Double wrapper
tree_set_t *set2 = tree_set_new(Double_compare, Double_delete);

// Create a boolean set using Boolean wrapper
tree_set_t *set3 = tree_set_new(Boolean_compare, Boolean_delete);

// Create a character set using Character wrapper
tree_set_t *set4 = tree_set_new(Character_compare, Character_delete);
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

// Create a set of employees
tree_set_t *employees = tree_set_new(Employee_compare, Employee_delete);

// ...
```



## tree_set_delete()

- Prototype

```c
void tree_set_delete(tree_set_t *set);
```

- Description
    - Destroy a `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);
tree_set_delete(set);
```



## tree_set_is_empty()

- Prototype

```c
bool tree_set_is_empty(const tree_set_t *set);
```

- Description
    - Determine whether a `tree_set_t` object is empty.
- Parameters
    - `set`: The `tree_set_t` object.
- Return
    - Returns `true` if the `tree_set_t` object is empty, otherwise returns `false`.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);
if (tree_set_is_empty(set)) {
    // ...
}
tree_set_delete(set);
```



## tree_set_size()

- Prototype

```c
size_t tree_set_size(const tree_set_t *set);
```

- Description
    - Get the size of a `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
- Return
    - Returns the size of the `tree_set_t` object.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);
printf("%d\n", tree_set_size(set));
tree_set_delete(set);
```



## tree_set_foreach()

- Prototype

```c
void tree_set_foreach(tree_set_t *set, visit_t visit);
```

- Description
    - Traverse a `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
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
    tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        tree_set_add(set, Integer_new(i));
    }

    // Print the set
    tree_set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    tree_set_foreach(set, Integer_triple);

    // Print the set
    tree_set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    tree_set_delete(set);

    return 0;
}
```



## tree_set_clear()

- Prototype

```c
tree_set_t *tree_set_clear(tree_set_t *set);
```

- Description
    - Clear a `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
- Return
    - Returns the modified `tree_set_t` object.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set, Integer_new(i));
}

tree_set_clear(set);
tree_set_delete(set);
```



## tree_set_contains()

- Prototype

```c
bool tree_set_contains(const tree_set_t *set, T elem);
```

- Description
    - Check if a `tree_set_t` object contains the specified element.
- Parameters
    - `set`: The `tree_set_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `tree_set_t` object contains the specified element, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (tree_set_contains(set, target)) {
    // ...
}
Integer_delete(target);

tree_set_delete(set);
```



## tree_set_add()

- Prototype

```c
tree_set_t *tree_set_add(tree_set_t *set, T elem);
```

- Description
    - Add an element to the `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `tree_set_t` object.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    tree_set_add(set, Integer_new(i));
}
tree_set_delete(set);
```



## tree_set_remove()

- Prototype

```c
tree_set_t *tree_set_remove(tree_set_t *set, T elem);
```

- Description
    - Remove the element from the `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `tree_set_t` object.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
tree_set_remove(array, target);
Integer_delete(target);

tree_set_delete(set);
```



## tree_set_union()

- Prototype

```c
tree_set_t *tree_set_union(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Get the union of two `tree_set_t` objects.
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns the union of two `tree_set_t` objects.
- Note
    - Caller **MUST** destroy the returned union `tree_set_t` object.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    tree_set_add(set2, Integer_new(i));
}

tree_set_t *set3 = tree_set_union(set1, set2);

tree_set_delete(set1);
tree_set_delete(set2);
tree_set_delete(set2);
```



## tree_set_intersection()

- Prototype

```c
tree_set_t *tree_set_intersection(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Get the intersection of two `tree_set_t` objects.
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns the intersection of two `tree_set_t` objects.
- Note
    - Caller **MUST** destroy the returned intersection `tree_set_t` object.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    tree_set_add(set2, Integer_new(i));
}

tree_set_t *set3 = tree_set_intersection(set1, set2);

tree_set_delete(set1);
tree_set_delete(set2);
tree_set_delete(set2);
```



## tree_set_difference()

- Prototype

```c
tree_set_t *tree_set_difference(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Get the difference of two `tree_set_t` objects.
    - $ A - B $
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns the difference of two `tree_set_t` objects.
- Note
    - Caller **MUST** destroy the returned difference `tree_set_t` object.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    tree_set_add(set2, Integer_new(i));
}

tree_set_t *set3 = tree_set_difference(set1, set2);

tree_set_delete(set1);
tree_set_delete(set2);
tree_set_delete(set2);
```



## tree_set_symmetric_difference()

- Prototype

```c
tree_set_t *tree_set_symmetric_difference(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Get the symmetric difference of two `tree_set_t` objects.
    - $ (A - B) \cup (B - A) $
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns the symmetric difference  of two `tree_set_t` objects.
- Note
    - Caller **MUST** destroy the returned symmetric difference `tree_set_t` object.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    tree_set_add(set2, Integer_new(i));
}

tree_set_t *set3 = tree_set_symmetric_difference(set1, set2);

tree_set_delete(set1);
tree_set_delete(set2);
tree_set_delete(set2);
```



## tree_set_is_disjoint()

- Prototype

```c
bool tree_set_is_disjoint(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Determine if two `tree_set_t` objects are disjoint.
    - Two sets are disjoint if their intersection is empty.
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns `true` if two `tree_set_t` objects are disjoint, otherwise returns `false`.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    tree_set_add(set2, Integer_new(i));
}

if (tree_set_is_disjoint(set1, set2)) {
    // ...
}

tree_set_delete(set1);
tree_set_delete(set2);
```



## tree_set_is_subset()

- Prototype

```c
bool tree_set_is_subset(const tree_set_t *set1, const tree_set_t *set2);
```

- Description
    - Determine if `set1` is a subset of `set2`.
    - A is a subset B if every element of A is also an element of B.
- Parameters
    - `set1`: The first `tree_set_t` object.
    - `set2`: The second `tree_set_t` object.
- Return
    - Returns `true` if `set1` is a subset of `set2`, otherwise returns `false`.
- Usage

```c
tree_set_t *set1 = tree_set_new(Integer_compare, Integer_delete);
tree_set_t *set2 = tree_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 5; i++) {
    tree_set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    tree_set_add(set2, Integer_new(i));
}

if (tree_set_is_subset(set1, set2)) {
    // ...
}

tree_set_delete(set1);
tree_set_delete(set2);
```



## tree_set_iterator_new()

- Prototype

```c
iterator_t *tree_set_iterator_new(const tree_set_t *set);
```

- Description
    - Create an iterator for a `tree_set_t` object.
- Parameters
    - `set`: The `tree_set_t` object.
- Return
    - Returns the iterator for container.



## tree_set_iterator_delete()

- Prototype

```c
void tree_set_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## tree_set_iterator_has_next()

- Prototype

```c
bool tree_set_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## tree_set_iterator_next()

- Prototype

```c
T tree_set_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
tree_set_t *set = tree_set_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    tree_set_add(array, Integer_new(i));
}

iterator_t *iterator = tree_set_iterator_new(array);
while (tree_set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)tree_set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

tree_set_iterator_delete(iterator);
tree_set_delete(set);
```

