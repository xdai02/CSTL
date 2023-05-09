# ordered_set_t

[TOC]



## ordered_set_new()

- Prototype

```c
ordered_set_t *ordered_set_new(compare_t compare, destroy_t destroy);
```

- Description
    - Create an `ordered_set_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `ordered_set_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer set using Integer wrapper
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);

// Create a double set using Double wrapper
ordered_set_t *set2 = ordered_set_new(Double_compare, Double_delete);

// Create a boolean set using Boolean wrapper
ordered_set_t *set3 = ordered_set_new(Boolean_compare, Boolean_delete);

// Create a character set using Character wrapper
ordered_set_t *set4 = ordered_set_new(Character_compare, Character_delete);
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
ordered_set_t *employees = ordered_set_new(Employee_compare, Employee_delete);

// ...
```



## ordered_set_delete()

- Prototype

```c
void ordered_set_delete(ordered_set_t *set);
```

- Description
    - Destroy an `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_delete(set);
```



## ordered_set_is_empty()

- Prototype

```c
bool ordered_set_is_empty(const ordered_set_t *set);
```

- Description
    - Determine whether an `ordered_set_t` object is empty.
- Parameters
    - `set`: The `ordered_set_t` object.
- Return
    - Returns `true` if the `ordered_set_t` object is empty, otherwise returns `false`.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
if (ordered_set_is_empty(set)) {
    // ...
}
ordered_set_delete(set);
```



## ordered_set_size()

- Prototype

```c
size_t ordered_set_size(const ordered_set_t *set);
```

- Description
    - Get the size of an `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
- Return
    - Returns the size of the `ordered_set_t` object.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
printf("%d\n", ordered_set_size(set));
ordered_set_delete(set);
```



## ordered_set_foreach()

- Prototype

```c
void ordered_set_foreach(ordered_set_t *set, visit_t visit);
```

- Description
    - Traverse an `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
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
    ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        ordered_set_add(set, Integer_new(i));
    }

    // Print the set
    ordered_set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    ordered_set_foreach(set, Integer_triple);

    // Print the set
    ordered_set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    ordered_set_delete(set);

    return 0;
}
```



## ordered_set_clear()

- Prototype

```c
ordered_set_t *ordered_set_clear(ordered_set_t *set);
```

- Description
    - Clear an `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
- Return
    - Returns the modified `ordered_set_t` object.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

ordered_set_clear(set);
ordered_set_delete(set);
```



## ordered_set_contains()

- Prototype

```c
bool ordered_set_contains(const ordered_set_t *set, T elem);
```

- Description
    - Check if an `ordered_set_t` object contains the specified element.
- Parameters
    - `set`: The `ordered_set_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `ordered_set_t` object contains the specified element, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (ordered_set_contains(set, target)) {
    // ...
}
Integer_delete(target);

ordered_set_delete(set);
```



## ordered_set_add()

- Prototype

```c
ordered_set_t *ordered_set_add(ordered_set_t *set, T elem);
```

- Description
    - Add an element to the `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `ordered_set_t` object.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}
ordered_set_delete(set);
```



## ordered_set_remove()

- Prototype

```c
ordered_set_t *ordered_set_remove(ordered_set_t *set, T elem);
```

- Description
    - Remove the element from the `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `ordered_set_t` object.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

Integer *integer = Integer_new(5);
ordered_set_remove(array, integer);
Integer_delete(integer);

ordered_set_delete(set);
```



## ordered_set_union()

- Prototype

```c
ordered_set_t *ordered_set_union(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Get the union of two `ordered_set_t` objects.
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns the union of two `ordered_set_t` objects.
- Note
    - Caller **MUST** destroy the returned union `ordered_set_t` object.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_union(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_intersection()

- Prototype

```c
ordered_set_t *ordered_set_intersection(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Get the intersection of two `ordered_set_t` objects.
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns the intersection of two `ordered_set_t` objects.
- Note
    - Caller **MUST** destroy the returned intersection `ordered_set_t` object.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_intersection(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_difference()

- Prototype

```c
ordered_set_t *ordered_set_difference(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Get the difference of two `ordered_set_t` objects.
    - $ A - B $
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns the difference of two `ordered_set_t` objects.
- Note
    - Caller **MUST** destroy the returned difference `ordered_set_t` object.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_difference(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_symmetric_difference()

- Prototype

```c
ordered_set_t *ordered_set_symmetric_difference(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Get the symmetric difference of two `ordered_set_t` objects.
    - $ (A - B) \cup (B - A) $
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns the symmetric difference  of two `ordered_set_t` objects.
- Note
    - Caller **MUST** destroy the returned symmetric difference `ordered_set_t` object.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_symmetric_difference(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_is_disjoint()

- Prototype

```c
bool ordered_set_is_disjoint(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Determine if two `ordered_set_t` objects are disjoint.
    - Two sets are disjoint if their intersection is empty.
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns `true` if two `ordered_set_t` objects are disjoint, otherwise returns `false`.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    ordered_set_add(set2, Integer_new(i));
}

if (ordered_set_is_disjoint(set1, set2)) {
    // ...
}

ordered_set_delete(set1);
ordered_set_delete(set2);
```



## ordered_set_is_subset()

- Prototype

```c
bool ordered_set_is_subset(const ordered_set_t *set1, const ordered_set_t *set2);
```

- Description
    - Determine if `set1` is a subset of `set2`.
    - A is a subset B if every element of A is also an element of B.
- Parameters
    - `set1`: The first `ordered_set_t` object.
    - `set2`: The second `ordered_set_t` object.
- Return
    - Returns `true` if `set1` is a subset of `set2`, otherwise returns `false`.
- Usage

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 5; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    ordered_set_add(set2, Integer_new(i));
}

if (ordered_set_is_subset(set1, set2)) {
    // ...
}

ordered_set_delete(set1);
ordered_set_delete(set2);
```



## ordered_set_iterator_create()

- Prototype

```c
iterator_t *ordered_set_iterator_create(const ordered_set_t *set);
```

- Description
    - Create an iterator for an `ordered_set_t` object.
- Parameters
    - `set`: The `ordered_set_t` object.
- Return
    - Returns the iterator for container.



## ordered_set_iterator_destroy()

- Prototype

```c
void ordered_set_iterator_destroy(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## ordered_set_iterator_has_next()

- Prototype

```c
bool ordered_set_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## ordered_set_iterator_next()

- Prototype

```c
T ordered_set_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    ordered_set_add(array, Integer_new(i));
}

iterator_t *iterator = ordered_set_iterator_create(array);
while (ordered_set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)ordered_set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

ordered_set_iterator_destroy(iterator);
ordered_set_delete(set);
```

