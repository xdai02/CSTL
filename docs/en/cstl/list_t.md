# list_t

[TOC]



## list_new()

- Prototype

```c
list_t *list_new(compare_t compare, destroy_t destroy);
```

- Description
    - Create a `list_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `list_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer linked list using Integer wrapper
list_t *list1 = list_new(Integer_compare, Integer_delete);

// Create a double linked list using Double wrapper
list_t *list2 = list_new(Double_compare, Double_delete);

// Create a boolean linked list using Boolean wrapper
list_t *list3 = list_new(Boolean_compare, Boolean_delete);

// Create a character linked list using Character wrapper
list_t *list4 = list_new(Character_compare, Character_delete);
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

// Create a list of employees
list_t *employees = list_new(Employee_compare, Employee_delete);

// ...
```



## list_delete()

- Prototype

```c
void list_delete(list_t *list);
```

- Description
    - Destroy a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);
list_delete(list);
```



## list_is_empty()

- Prototype

```c
bool list_is_empty(const list_t *list);
```

- Description
    - Determine whether a `list_t` object is empty.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns `true` if the `list_t` object is empty, otherwise returns `false`.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);
if (list_is_empty(list)) {
    // ...
}
list_delete(list);
```



## list_size()

- Prototype

```c
size_t list_size(const list_t *list);
```

- Description
    - Get the size of a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the size of the `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);
printf("%d\n", list_size(list));
list_delete(list);
```



## list_foreach()

- Prototype

```c
void list_foreach(list_t *list, visit_t visit);
```

- Description
    - Traverse a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
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
    // Create a list of integers
    list_t *list = list_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the list
        list_push_back(list, Integer_new(i));
    }

    // Print the list
    list_foreach(list, Integer_print);
    printf("\n");

    // Triple the integers in the list
    list_foreach(list, Integer_triple);

    // Print the list_
    list_foreach(list, Integer_print);
    printf("\n");

    // Destroy the list
    list_delete(list);

    return 0;
}
```



## list_clear()

- Prototype

```c
list_t *list_clear(list_t *list);
```

- Description
    - Clear a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_clear(list);
list_delete(list);
```



## list_get()

- Prototype

```c
T list_get(const list_t *list, size_t index);
```

- Description
    - Get the element at the specified index of a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `index`: The index.
- Return
    - Returns the element at the specified index of the `list_t` object.
- Usage

```c
list_t *list= list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get(list, 5);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_set()

- Prototype

```c
list_t *list_set(list_t *list, size_t index, T elem);
```

- Description
    - Set the element at the specified position in the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `index`: The index.
    - `elem`: The element.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_set(list, 5, Integer_new(50));
list_delete(list);
```



## list_index_of()

- Prototype

```c
int list_index_of(const list_t *list, T elem);
```

- Description
    - Get the index of the specified element in the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `elem`: The element.
- Return
    - Returns the index of the specified element if found, otherwise returns `-1`.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *target = Integer_new(5);
printf("%d\n", list_index_of(list, target));
Integer_delete(target);

list_delete(list);
```



## list_contains()

- Prototype

```c
bool list_contains(const list_t *list, T elem);
```

- Description
    - Determine whether the `list_t` object contains the specified element.
- Parameters
    - `list`: The `list_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `list_t` object contains the specified element, otherwise returns `false`.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *target = Integer_new(5);
if (list_contains(list, target)) {
    // ...
}
Integer_delete(target);

list_delete(list);
```



## list_count()

- Prototype

```c
size_t list_count(const list_t *list, T elem);
```

- Description
    - Count the number of occurrences of the specified element in a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `elem`: The element.
- Return
    - Returns the number of occurrences of the specified element in the `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

list_push_back(list, Integer_new(1));
list_push_back(list, Integer_new(2));
list_push_back(list, Integer_new(2));
list_push_back(list, Integer_new(3));
list_push_back(list, Integer_new(2));

Integer *target = Integer_new(2);
printf("%d\n", list_count(list, target));
Integer_delete(target);

list_delete(list);
```



## list_get_front()

- Prototype

```c
T list_get_front(const list_t *list);
```

- Description
    - Get the first element of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the first element if successful, otherwise returns `NULL`.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get_front(list);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_get_back()

- Prototype

```c
T list_get_back(const list_t *list);
```

- Description
    - Get the last element of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the last element if successful, otherwise returns `NULL`.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get_back(list);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_push_front()

- Prototype

```c
list_t *list_push_front(list_t *list, T elem);
```

- Description
    - Insert the specified element at the beginning of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_front(list, Integer_new(i));
}

list_delete(list);
```



## list_push_back()

- Prototype

```c
list_t *list_push_back(list_t *list, T elem);
```

- Description
    - Insert the specified element at the end of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_delete(list);
```



## list_pop_front()

- Prototype

```c
T list_pop_front(list_t *list);
```

- Description
    - Remove the first element of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the removed element if successful, otherwise returns `NULL`.
- Note
    - Caller **MUST** free the returned element (if applicable).

- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_pop_front(list);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_pop_back()

- Prototype

```c
T list_pop_back(list_t *list);
```

- Description
    - Remove the last element of the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the removed element if successful, otherwise returns `NULL`.
- Note
    - Caller **MUST** free the returned element (if applicable).
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_pop_back(list);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_insert()

- Prototype

```c
list_t *list_insert(list_t *list, size_t index, T elem);
```

- Description
    - Insert the specified element at the specified position in the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `index`: The index.
    - `elem`: The element.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);
list_insert(list, 0, Integer_new(1));
list_insert(list, 1, Integer_new(2));
list_insert(list, 0, Integer_new(3));
list_insert(list, 2, Integer_new(4));
list_delete(list);
```



## list_remove()

- Prototype

```c
T list_remove(list_t *list, size_t index);
```

- Description
    - Removes the element at the specified position in the `list_t` object.
- Parameters
    - `list`: The `list_t` object.
    - `index`: The index.
- Return
    - Returns the removed element if successful, otherwise returns `NULL`.
- Note
    - Caller **MUST** free the returned element (if applicable).
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_remove(list, 5);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_reverse()

- Prototype

```c
list_t *list_reverse(list_t *list);
```

- Description
    - Reverse a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the modified `list_t` object.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_reverse(list);
list_delete(list);
```



## list_iterator_new()

- Prototype

```c
iterator_t *list_iterator_new(const list_t *list);
```

- Description
    - Create an iterator for a `list_t` object.
- Parameters
    - `list`: The `list_t` object.
- Return
    - Returns the iterator for container.



## list_iterator_delete()

- Prototype

```c
void list_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## list_iterator_has_next()

- Prototype

```c
bool list_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## list_iterator_next()

- Prototype

```c
T list_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
list_t *list = list_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

iterator_t *iterator = list_iterator_new(list);
while (list_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)list_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

list_iterator_delete(iterator);
list_delete(list);
```

