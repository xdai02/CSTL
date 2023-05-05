# set_t

[TOC]



## set_create()

- Prototype

```c
set_t *set_create(compare_t compare, destroy_t destroy);
```

- Description
    - Create a `set_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `set_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer set using Integer wrapper
set_t *set1 = set_create(Integer_compare, Integer_delete);

// Create a double set using Double wrapper
set_t *set2 = set_create(Double_compare, Double_delete);

// Create a boolean set using Boolean wrapper
set_t *set3 = set_create(Boolean_compare, Boolean_delete);

// Create a character set using Character wrapper
set_t *set4 = set_create(Character_compare, Character_delete);
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

// Create an array of employees
set_t *employees = set_create(Employee_compare, Employee_delete);

// ...
```



## set_destroy()

- Prototype

```c
void set_destroy(set_t *set);
```

- Description
    - Destroy a `set_t` object.
- Parameters
    - `set`: The `set_t` object.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);
set_destroy(set);
```



## set_is_empty()

- Prototype

```c
bool set_is_empty(const set_t *set);
```

- Description
    - Determine whether a `set_t` object is empty.
- Parameters
    - `set`: The `set_t` object.
- Return
    - Returns `true` if the `set_t` object is empty, otherwise returns `false`.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);
if (sety_is_empty(set)) {
    // ...
}
set_destroy(set);
```



## set_size()

- Prototype

```c
size_t set_size(const set_t *set);
```

- Description
    - Get the size of a `set_t` object.
- Parameters
    - `set`: The `set_t` object.
- Return
    - Returns the size of the `set_t` object.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);
printf("%d\n", set_size(set));
set_destroy(set);
```



## set_foreach()

- Prototype

```c
void set_foreach(set_t *set, visit_t visit);
```

- Description
    - Traverse a `set_t` object.
- Parameters
    - `set`: The `set_t` object.
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
    set_t *set = set_create(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        set_add(set, Integer_new(i));
    }

    // Print the set
    set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    set_foreach(set, Integer_triple);

    // Print the set
    set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    set_destroy(set);

    return 0;
}
```



## set_clear()

- Prototype

```c
set_t *set_clear(set_t *set);
```

- Description
    - Clear a `set_t` object.
- Parameters
    - `set`: The `set_t` object.
- Return
    - Returns the modified `set_t` object.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}

set_clear(set);
set_destroy(set);
```



## set_contains()

- Prototype

```c
bool set_contains(const set_t *set, T elem);
```

- Description
    - Check if a `set_t` object contains the specified element.
- Parameters
    - `set`: The `set_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `set_t` object contains the specified element, otherwise returns `false`.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (set_contains(set, target)) {
    // ...
}
Integer_delete(target);

set_destroy(set);
```



## set_add()

- Prototype

```c
set_t *set_add(set_t *set, T elem);
```

- Description
    - Add an element to the `set_t` object.
- Parameters
    - `set`: The `set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `set_t` object.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}
set_destroy(set);
```



## set_remove()

- Prototype

```c
set_t *set_remove(set_t *set, T elem);
```

- Description
    - Remove the element from the `set_t` object.
- Parameters
    - `set`: The `set_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `set_t` object.
- Note
    - Caller **MUST** free the parameter `elem` (if applicable).

- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}

Integer *integer = Integer_new(5);
set_remove(array, integer);
Integer_delete(integer);

set_destroy(set);
```



## set_union()

- Prototype

```c
set_t *set_union(const set_t *set1, const set_t *set2);
```

- Description
    - Get the union of two `set_t` objects.
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns the union of two `set_t` objects.
- Note
    - Caller **MUST** destroy the returned union `set_t` object.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    set_add(set2, Integer_new(i));
}

set_t *set3 = set_union(set1, set2);

set_destroy(set1);
set_destroy(set2);
set_destroy(set2);
```



## set_intersection()

- Prototype

```c
set_t *set_intersection(const set_t *set1, const set_t *set2);
```

- Description
    - Get the intersection of two `set_t` objects.
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns the intersection of two `set_t` objects.
- Note
    - Caller **MUST** destroy the returned intersection `set_t` object.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    set_add(set2, Integer_new(i));
}

set_t *set3 = set_intersection(set1, set2);

set_destroy(set1);
set_destroy(set2);
set_destroy(set2);
```



## set_difference()

- Prototype

```c
set_t *set_difference(const set_t *set1, const set_t *set2);
```

- Description
    - Get the difference of two `set_t` objects.
    - $ A - B $
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns the difference of two `set_t` objects.
- Note
    - Caller **MUST** destroy the returned difference `set_t` object.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    set_add(set2, Integer_new(i));
}

set_t *set3 = set_difference(set1, set2);

set_destroy(set1);
set_destroy(set2);
set_destroy(set2);
```



## set_symmetric_difference()

- Prototype

```c
set_t *set_symmetric_difference(const set_t *set1, const set_t *set2);
```

- Description
    - Get the symmetric difference of two `set_t` objects.
    - $ (A - B) \cup (B - A) $
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns the symmetric difference  of two `set_t` objects.
- Note
    - Caller **MUST** destroy the returned symmetric difference `set_t` object.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    set_add(set2, Integer_new(i));
}

set_t *set3 = set_symmetric_difference(set1, set2);

set_destroy(set1);
set_destroy(set2);
set_destroy(set2);
```



## set_is_disjoint()

- Prototype

```c
bool set_is_disjoint(const set_t *set1, const set_t *set2);
```

- Description
    - Determine if two `set_t` objects are disjoint.
    - Two sets are disjoint if their intersection is empty.
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns `true` if two `set_t` objects are disjoint, otherwise returns `false`.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    set_add(set2, Integer_new(i));
}

if (set_is_disjoint(set1, set2)) {
    // ...
}

set_destroy(set1);
set_destroy(set2);
```



## set_is_subset()

- Prototype

```c
bool set_is_subset(const set_t *set1, const set_t *set2);
```

- Description
    - Determine if `set1` is a subset of `set2`.
    - A is a subset B if every element of A is also an element of B.
- Parameters
    - `set1`: The first `set_t` object.
    - `set2`: The second `set_t` object.
- Return
    - Returns `true` if `set1` is a subset of `set2`, otherwise returns `false`.
- Usage

```c
set_t *set1 = set_create(Integer_compare, Integer_delete);
set_t *set2 = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 5; i++) {
    set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    set_add(set2, Integer_new(i));
}

if (set_is_subset(set1, set2)) {
    // ...
}

set_destroy(set1);
set_destroy(set2);
```



## set_iterator_create()

- Prototype

```c
iterator_t *set_iterator_create(const set_t *set);
```

- Description
    - Create an iterator for an `set_t` object.
- Parameters
    - `set`: The `set_t` object.
- Return
    - Returns the iterator for container.



## set_iterator_destroy()

- Prototype

```c
void set_iterator_destroy(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## set_iterator_has_next()

- Prototype

```c
bool set_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## set_iterator_next()

- Prototype

```c
T set_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
set_t *set = set_create(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    set_add(array, Integer_new(i));
}

iterator_t *iterator = set_iterator_create(array);
while (set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

set_iterator_destroy(iterator);
set_destroy(set);
```

