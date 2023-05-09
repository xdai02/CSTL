# array_t

[TOC]



## array_new()

- Prototype

```c
array_t *array_new(compare_t compare, destroy_t destroy);
```

- Description
    - Create an `array_t` object.
- Parameters
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `array_t` object if successful, otherwise returns `NULL`.
- Usage

```c
// Create an integer array using Integer wrapper
array_t *array1 = array_new(Integer_compare, Integer_delete);

// Create a double array using Double wrapper
array_t *array2 = array_new(Double_compare, Double_delete);

// Create a boolean array using Boolean wrapper
array_t *array3 = array_new(Boolean_compare, Boolean_delete);

// Create a character array using Character wrapper
array_t *array4 = array_new(Character_compare, Character_delete);
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
array_t *employees = array_new(Employee_compare, Employee_delete);

// ...
```



## array_delete()

- Prototype

```c
void array_delete(array_t *array);
```

- Description
    - Destroy an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
array_delete(array);
```



## array_is_empty()

- Prototype

```c
bool array_is_empty(const array_t *array);
```

- Description
    - Determine whether an `array_t` object is empty.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns `true` if the `array_t` object is empty, otherwise returns `false`.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
if (array_is_empty(array)) {
    // ...
}
array_delete(array);
```



## array_size()

- Prototype

```c
size_t array_size(const array_t *array);
```

- Description
    - Get the size of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns the size of the `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
printf("%d\n", array_size(array));
array_delete(array);
```



## array_foreach()

- Prototype

```c
void array_foreach(array_t *array, visit_t visit);
```

- Description
    - Traverse an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
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
    // Create an array of integers
    array_t *array = array_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the array
        array_append(array, Integer_new(i));
    }

    // Print the array
    array_foreach(array, Integer_print);
    printf("\n");

    // Triple the integers in the array
    array_foreach(array, Integer_triple);

    // Print the array
    array_foreach(array, Integer_print);
    printf("\n");

    // Destroy the array
    array_delete(array);

    return 0;
}
```



## array_clear()

- Prototype

```c
array_t *array_clear(array_t *array);
```

- Description
    - Clear an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_clear(array);
array_delete(array);
```



## array_get()

- Prototype

```c
T array_get(const array_t *array, size_t index);
```

- Description
    - Get the element at the specified index of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `index`: The index.
- Return
    - Returns the element at the specified index of the `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

Integer *integer = (Integer *)array_get(array, 5);
printf("%d\n", Integer_get(integer));

array_delete(array);
```



## array_set()

- Prototype

```c
array_t *array_set(array_t *array, size_t index, T elem);
```

- Description
    - Set the element at the specified index of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `index`: The index.
    - `elem`: The element.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_set(array, 5, Integer_new(50));
array_delete(array);
```



## array_append()

- Prototype

```c
array_t *array_append(array_t *array, T elem);
```

- Description
    - Append an element to the end of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}
array_delete(array);
```



## array_insert()

- Prototype

```c
array_t *array_insert(array_t *array, size_t index, T elem);
```

- Description
    - Insert an element at the specified index of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `index`: The index.
    - `elem`: The element.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
array_insert(array, 0, Integer_new(1));
array_insert(array, 1, Integer_new(2));
array_insert(array, 0, Integer_new(3));
array_insert(array, 2, Integer_new(4));
array_delete(array);
```



## array_remove()

- Prototype

```c
T array_remove(array_t *array, size_t index);
```

- Description
    - Remove the element at the specified index of an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `index`: The index.
- Return
    - Returns the removed element if successful, otherwise returns `NULL`.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_remove(array, 5);
array_delete(array);
```



## array_index_of()

- Prototype

```c
size_t array_index_of(const array_t *array, T elem);
```

- Description
    - Get the index of the specified element in an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `elem`: The element.
- Return
    - Returns the index of the specified element if found, otherwise returns `-1`.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

Integer *target = Integer_new(5);
printf("%d\n", array_index_of(array, target));
Integer_delete(target);

array_delete(array);
```



## array_contains()

- Prototype

```c
bool array_contains(const array_t *array, T elem);
```

- Description
    - Check if an `array_t` object contains the specified element.
- Parameters
    - `array`: The `array_t` object.
    - `elem`: The element.
- Return
    - Returns `true` if the `array_t` object contains the specified element, otherwise returns `false`.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

Integer *target = Integer_new(5);
if (array_contains(array, target)) {
    // ...
}
Integer_delete(target);

array_delete(array);
```



## array_count()

- Prototype

```c
size_t array_count(const array_t *array, T elem);
```

- Description
    - Count the number of occurrences of the specified element in an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
    - `elem`: The element.
- Return
    - Returns the number of occurrences of the specified element in the `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

array_append(array, Integer_new(1));
array_append(array, Integer_new(2));
array_append(array, Integer_new(2));
array_append(array, Integer_new(3));
array_append(array, Integer_new(2));

Integer *target = Integer_new(2);
printf("%d\n", array_count(array, target));
Integer_delete(target);

array_delete(array);
```



## array_reverse()

- Prototype

```c
array_t *array_reverse(array_t *array);
```

- Description
    - Reverse an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_reverse(array);
array_delete(array);
```



## array_sort()

- Prototype

```c
array_t *array_sort(array_t *array);
```

- Description
    - Sort an `array_t` object in ascending order.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns the modified `array_t` object.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);

array_append(array, Integer_new(4));
array_append(array, Integer_new(1));
array_append(array, Integer_new(3));
array_append(array, Integer_new(7));
array_append(array, Integer_new(6));

array_sort(array);
array_delete(array);
```



## array_iterator_new()

- Prototype

```c
iterator_t *array_iterator_new(const array_t *array);
```

- Description
    - Create an iterator for an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Return
    - Returns the iterator for container.



## array_iterator_delete()

- Prototype

```c
void array_iterator_delete(iterator_t *iterator);
```

- Description
    - Destroy an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.



## array_iterator_has_next()

- Prototype

```c
bool array_iterator_has_next(const iterator_t *iterator);
```

- Description
    - Determine whether an iterator has the next element.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns `true` if the iterator has the next element, otherwise returns `false`.



## array_iterator_has_next()

- Prototype

```c
T array_iterator_next(iterator_t *iterator);
```

- Description
    - Get the next element of an iterator.
- Parameters
    - `iterator`: The `iterator_t` object.
- Return
    - Returns the next element of the iterator.
- Usage

```c
array_t *array = array_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

iterator_t *iterator = array_iterator_new(array);
while (array_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)array_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

array_iterator_delete(iterator);
array_delete(array);
```

