# coop_utils

[TOC]



## bool

```c
typedef int bool;
#define true 1
#define false 0
```

- Description
    - Boolean type for compatibility with standards before C99.



## T

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

array_t *array_create() {
    array_t *array = (array_t *)malloc(sizeof(array_t));
    array->data = (T *)malloc(sizeof(T) * 16);
    array->size = 0;
    array->capacity = 16;
    return array;
}
```



## compare_t

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

void mystring_destroy(T data) {
    MyString *mystring = (MyString *)data;
    free(mystring->str);
}
```



## visit_t

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



## return_if_fail()

```c
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }
```

- Description
    - Returns from the current function immediately if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

```c
void array_print(int *arr, int n) {
    return_if_fail(n >= 0);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```



## return_value_if_fail()

```c
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }
```

- Description
    - Returns the specific value from the current function immediately if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
    - `ret`: The value to be returned.
- Usage

```c
char *str_clear(char *str) {
    return_value_if_fail(str != NULL, NULL);
    str[0] = '\0';
    return str;
}
```



## exit_if_fail()

```c
#define exit_if_fail(expr)  \
    if (!(expr)) {          \
        exit(EXIT_FAILURE); \
    }
```

- Description
    - Terminates the program immediately with the `EXIT_FAILURE` status if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

```c
float divide(int a, int b) {
    exit_if_fail(b != 0);
    return (float)a / (float)b;
}
```



## min()

```c
#define min(x, y) (((x) < (y)) ? (x) : (y))
```

- Description
    - Returns the minimum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the minimum of `x` and `y`.
- Usage

```c
printf("%d\n", min(5, 10));
```



## max()

```c
#define max(x, y) (((x) > (y)) ? (x) : (y))
```

- Description
    - Returns the maximum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the maximum of `x` and `y`.
- Usage

```c
printf("%d\n", max(5, 10));
```



## swap()

```c
#define swap(x, y, type) \
    do {                 \
        type temp = (x); \
        (x) = (y);       \
        (y) = temp;      \
    } while (0)
```

- Description
    - Swaps the values of two variables with the given type.
- Parameters
    - `x`: The first variable to be swapped.
    - `y`: The second variable to be swapped.
    - `type`: The type of the variables to be swapped.
- Usage

```c
int x = 3;
int y = 5;
printf("Before: x = %d, y = %d\n", x, y);
swap(x, y, int);
printf("After: x = %d, y = %d\n", x, y);
```



## float_equal()

- Prototype

```c
bool float_equal(float f1, float f2);
```

- Description
    - Compares two floating point numbers for equality within a certain tolerance.
- Parameters
    - `f1`: The first float number to be compared.
    - `f2`: The second float number to be compared.
- Return
    - Returns `true` if the absolute difference between `f1` and `f2` is less than `FLT_EPSILON`, `false` otherwise.
- Usage

```c
float x = 3.14f;
if (float_equal(x, 3.14f)) {
    // ...
}
```



## double_equal()

- Prototype

```c
bool double_equal(double d1, double d2);
```

- Description
    - Compares two double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - `d1`: The first double number to be compared.
    - `d2`: The second double number to be compared.
- Return
    - Returns `true` if the absolute difference between `d1` and `d2` is less than `DBL_EPSILON`, `false` otherwise.
- Usage

```c
double x = 3.14;
if (double_equal(x, 3.14)) {
    // ...
}
```



## long_double_equal()

- Prototype

```c
bool long_double_equal(long double ld1, long double ld2);
```

- Description
    - Compares two long double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - `ld1`: The first long double number to be compared.
    - `ld2`: The second long double number to be compared.
- Return
    - Returns `true` if the absolute difference between `ld1` and `ld2` is less than `LDBL_EPSILON`, `false` otherwise.
- Usage

```c
long double x = 3.14L;
if (long_double_equal(x, 3.14L)) {
    // ...
}
```

