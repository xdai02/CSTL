# coop_utils

[TOC]



## bool

```c
typedef int bool;
#define true 1
#define false 0
```

- 描述
    - 用于兼容C99之前的标准



## T

```c
#define T void*
```

- 描述
    - 用于指向任意类型的指针，等价于`void *`。
- 用例

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

- 描述
    - 用于比较两个数据的函数指针。
- 参数
    - `data1`：第一个被比较的数据。
    - `data2`：第二个被比较的数据。
- 返回值
    - 当`data1 < data2`返回负整数。
    - 当`data1 == data2`返回0。
    - 当`data1 > data2`返回正整数。
- 用例

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

- 描述
    - 用于销毁数据的函数指针。
- 参数
    - `data`：需要被销毁的数据。
- 用例

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

- 描述
    - 用于访问数据的函数指针。
- Parameters
    - `data`：需要被访问的数据。
- 用例

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

- 描述
    - 当`expr`为`false`时，立即从当前函数返回。常用于检查函数执行的条件。
- 参数
    - `expr`: 需要判断的表达式。
- 用例

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

- 描述
    - 当`expr`为`false`时，立即从当前函数返回指定值。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
    - `ret`：返回值。
- 用例

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

- 描述
    - 当`expr`为`false`时，立即以`EXIT_FAILURE`状态终止程序。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
- 用例

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

- 描述
    - 返回两数的较小值。
- 参数
    - `x`：第一个需要比较的数。
    - `y`：第二个需要比较的数。
- 返回值
    - 返回`x`和`y`的较小值。
- 用例

```c
printf("%d\n", min(5, 10));
```



## max()

```c
#define max(x, y) (((x) > (y)) ? (x) : (y))
```

- 描述
    - 返回两数的较大值。
- 参数
    - `x`：第一个需要比较的数。
    - `y`：第二个需要比较的数。
- 返回值
    - 返回`x`和`y`的较大值。
- 用例

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

- 描述
    - 交换两个给定类型的变量
- 参数
    - `x`：第一个需要交换的变量。
    - `y`：第二个需要交换的变量。
    - `type`: 所需交换的类型。
- 用例

```c
int x = 3;
int y = 5;
printf("Before: x = %d, y = %d\n", x, y);
swap(x, y, int);
printf("After: x = %d, y = %d\n", x, y);
```



## float_equal()

- 原型

```c
bool float_equal(float f1, float f2)
```

- 描述
    - 在一定的容差范围内比较两个浮点数是否相等。
- 参数
    - `f1`：要比较的第一个浮点数。
    - `f2`：要比较的第二个浮点数。
- 返回值
    - 如果`f1`和`f2`之间的绝对差小于`FLT_EPSILON`，则返回`true`，否则返回`false`。
- 用例

```c
float x = 3.14f;
if (float_equal(x, 3.14f)) {
    // ...
}
```



## double_equal()

- 原型

```c
bool double_equal(double d1, double d2)
```

- 描述
    - 在一定的容差范围内比较两个双精度浮点数是否相等。
- 参数
    - `d1`：要比较的第一个双精度数。
    - `d2`：要比较的第二个双精度数。
- 返回值
    - 如果`d1`和`d2`之间的绝对差小于`DBL_EPSILON`，则返回`true`，否则返回`false`。
- 用例

```c
double x = 3.14;
if (double_equal(x, 3.14)) {
    // ...
}
```



## long_double_equal()

- 原型

```c
bool long_double_equal(long double ld1, long double ld2)
```

- 描述
    - 在一定的容差范围内比较两个长双精度浮点数是否相等。
- 参数
    - `ld1`：要比较的第一个长双精度数。
    - `ld2`：要比较的第二个长双精度数。
- 返回值
    - 如果`ld1`和`ld2`之间的绝对差小于`LDBL_EPSILON`，则返回`true`，否则返回`false`。 
- 用例

```c
long double x = 3.14L;
if (long_double_equal(x, 3.14L)) {
    // ...
}
```

