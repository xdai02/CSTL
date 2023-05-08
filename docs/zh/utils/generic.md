# generic

[TOC]



## T

- 原型

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

- 原型

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

- 原型

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

- 原型

```c
typedef void (*visit_t)(T data);
```

- 描述
    - 用于访问数据的函数指针。
- 参数
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



## visit_pair_t

- 原型

```c
typedef void (*visit_pair_t)(T key, T value);
```

- 描述
    - 用于访问key-value对的函数指针。
- 参数
    - `key`：需要被访问的key。
    - `value`：需要被访问的value。
- 用例

```c
void key_value_print(T key, T value) {
    Integer *k = (Integer *)key;
    Integer *v = (Integer *)value;
    printf("key=%d, value=%d\n", Integer_get(k), Integer_get(v));
}
```



## hash_t

- 原型

```c
typedef size_t (*hash_t)(const T data);
```

- 描述
    - 用于哈希数据的函数指针。
- 参数
    - `data`：需要哈希的的数据。
- 用例

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

