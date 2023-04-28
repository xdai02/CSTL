# array_t

[TOC]



## array_create()

- Prototype

```c
array_t *array_create(compare_t compare, destroy_t destroy);
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
array_t *array1 = array_create(Integer_compare, Integer_delete);

// Create a double array using Double wrapper
array_t *array2 = array_create(Double_compare, Double_delete);

// Create a boolean array using Boolean wrapper
array_t *array3 = array_create(Boolean_compare, Boolean_delete);

// Create a character array using Character wrapper
array_t *array4 = array_create(Character_compare, Character_delete);
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
array_t *employees = array_create(Employee_compare, Employee_delete);

// ...
```



## array_destroy()

- Prototype

```c
void array_destroy(array_t *array);
```

- Description
    - Destroy an `array_t` object.
- Parameters
    - `array`: The `array_t` object.
- Usage

```c
array_t *array = array_create(Integer_compare, Integer_delete);
array_destroy(array);
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
void Integer_double(T elem) {
    Integer *integer = (Integer *)elem;
    
}

// Callback function for printing an integer
void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_valueOf(integer));
}

// Create an integer array
array_t *array = array_create(Integer_compare, Integer_delete);

// Add 10 integers
for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

// Print the array
array_foreach(array, Integer_print);

// Destroy the array
array_destroy(array);
```

