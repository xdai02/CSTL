# generic

[TOC]



## T

- Prototype

```c
#define T void*
```

- Description
    - A generic data type representing a pointer to any data type. It is an alias for `void *`.
- Usage

```c
typedef struct array_t {
    T *data;
    size_t size;
    size_t capacity;
} array_t;

array_t *array_new() {
    array_t *array = (array_t *)malloc(sizeof(array_t));
    array->data = (T *)malloc(sizeof(T) * 16);
    array->size = 0;
    array->capacity = 16;
    return array;
}
```



## compare_t

- Prototype

```c
typedef int (*compare_t)(const T data1, const T data2);
```

- Description
    - A generic function pointer type for comparing two data items.
- Parameters
    - `data1`: The first data item to be compared.
    - `data2`: The second data item to be compared.
- Return
    - Returns a negative integer if `data1 < data2`.
    - Returns 0 if `data1 == data2`.
    - Returns a positive integer if `data1 > data2`.
- Usage

```c
typedef struct {
    char name[32];
    int age;
} Person;

int person_compare(const T data1, const T data2) {
    const Person *person1 = (Person *)data1;
    const Person *person2 = (Person *)data2;
    return person1->age - person2->age;
}
```



## destroy_t

- Prototype

```c
typedef void (*destroy_t)(T data);
```

- Description
    - A generic function pointer type for destroying a data item.
- Parameters
    - `data`: The data item to be destroyed.
- Usage

```c
typedef struct {
    char *str;
} MyString;

void mystring_delete(T data) {
    MyString *mystring = (MyString *)data;
    free(mystring->str);
}
```



## visit_t

- Prototype

```c
typedef void (*visit_t)(T data);
```

- Description
    - A generic function pointer type for visiting a data item.
- Parameters
    - `data`: The data item to be visited.
- Usage

```c
typedef struct {
    char name[100];
    int id;
    float salary;
} Employee;

void employee_print(T data) {
    Employee *employee = (Employee *)data;
    printf("Employee Name: %s\n", employee->name);
    printf("Employee ID: %d\n", employee->id);
    printf("Employee Salary: %.2f\n", employee->salary);
}
```



## visit_pair_t

- Prototype

```c
typedef void (*visit_pair_t)(T key, T value);
```

- Description
    - A generic function pointer type for visiting a key-value pair.
- Parameters
    - `key`: The key of the pair to be visited.
    - `value`: The value of the pair to be visited.
- Usage

```c
void key_value_print(T key, T value) {
    Integer *k = (Integer *)key;
    Integer *v = (Integer *)value;
    printf("key=%d, value=%d\n", Integer_get(k), Integer_get(v));
}
```



## hash_t

- Prototype

```c
typedef size_t (*hash_t)(const T data);
```

- Description
    - A generic function pointer type for hashing a data item.
- Parameters
    - `data`: The data item to be hashed.
- Usage

```c
typedef struct Point {
    int x;
    int y;
} Point;

size_t Point_hash(const T data) {
    const Point *point = data;
    return (size_t)(point->x + point->y);
}
```

