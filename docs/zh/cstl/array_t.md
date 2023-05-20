# array_t

[TOC]



## array_new()

- 原型

```c
array_t *array_new(compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`array_t`对象。
- 参数
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`array_t`，否则返回`NULL`。
- 用例

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

- 原型

```c
void array_delete(array_t *array);
```

- 描述
    - 销毁`array_t`对象。
- 参数
    - `array`：`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);
array_delete(array);
```



## array_is_empty()

- 原型

```c
bool array_is_empty(const array_t *array);
```

- 描述
    - 判断`array_t`对象是否为空。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 如果`array_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);
if (array_is_empty(array)) {
    // ...
}
array_delete(array);
```



## array_size()

- 原型

```c
size_t array_size(const array_t *array);
```

- 描述
    - 获取`array_t`对象的大小。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 返回`array_t`对象的大小。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);
printf("%d\n", array_size(array));
array_delete(array);
```



## array_foreach()

- 原型

```c
void array_foreach(array_t *array, visit_t visit);
```

- 描述
    - 遍历`array_t`对象。
- 参数
    - `array`：`array_t`对象。
    - `visit`：用于访问元素的回调函数。
- 用例

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

- 原型

```c
array_t *array_clear(array_t *array);
```

- 描述
    - 清空`array_t`对象。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_clear(array);
array_delete(array);
```



## array_get()

- 原型

```c
T array_get(const array_t *array, size_t index);
```

- 描述
    - 获取`array_t`对象指定下标的元素。
- 参数
    - `array`：`array_t`对象。
    - `index`：下标。
- 返回值
    - 返回`array_t`对象指定下标的元素。
- 用例

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

- 原型

```c
array_t *array_set(array_t *array, size_t index, T elem);
```

- 描述
    - 设置`array_t`对象指定下标的元素。
- 参数
    - `array`：`array_t`对象。
    - `index`：下标。
    - `elem`：元素。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_set(array, 5, Integer_new(50));
array_delete(array);
```



## array_append()

- 原型

```c
array_t *array_append(array_t *array, T elem);
```

- 描述
    - 在`array_t`对象末尾追加元素。
- 参数
    - `array`：`array_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}
array_delete(array);
```



## array_insert()

- 原型

```c
array_t *array_insert(array_t *array, size_t index, T elem);
```

- 描述
    - 在`array_t`对象指定下标插入元素。
- 参数
    - `array`：`array_t`对象。
    - `index`：下标。
    - `elem`：元素。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);
array_insert(array, 0, Integer_new(1));
array_insert(array, 1, Integer_new(2));
array_insert(array, 0, Integer_new(3));
array_insert(array, 2, Integer_new(4));
array_delete(array);
```



## array_remove()

- 原型

```c
T array_remove(array_t *array, size_t index);
```

- 描述
    - 删除`array_t`对象指定下标的元素。
- 参数
    - `array`：`array_t`对象。
    - `index`：下标。
- 返回值
    - 返回被删除的元素，失败返回`NULL`。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_remove(array, 5);
array_delete(array);
```



## array_index_of()

- 原型

```c
size_t array_index_of(const array_t *array, T elem);
```

- 描述
    - 获取`array_t`对象指定元素的下标。
- 参数
    - `array`：`array_t`对象。
    - `elem`：元素。
- 返回值
    - 返回`array_t`对象指定元素的下标，找不到返回`-1`。
- 用例

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

- 原型

```c
bool array_contains(const array_t *array, T elem);
```

- 描述
    - 判断`array_t`对象是否包含指定元素。
- 参数
    - `array`：`array_t`对象。
    - `elem`：元素。
- 返回值
    - 如果`array_t`对象包含指定元素返回`true`，否则返回`false`。
- 用例

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

- 原型

```c
size_t array_count(const array_t *array, T elem);
```

- 描述
    - 计算`array_t`对象中指定元素出现次数。
- 参数
    - `array`：`array_t`对象。
    - `elem`：元素。
- 返回值
    - 返回`array_t`对象中指定元素出现次数。
- 用例

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

- 原型

```c
array_t *array_reverse(array_t *array);
```

- 描述
    - 反转`array_t`对象。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

```c
array_t *array = array_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    array_append(array, Integer_new(i));
}

array_reverse(array);
array_delete(array);
```



## array_sort()

- 原型

```c
array_t *array_sort(array_t *array);
```

- 描述
    - 升序排序`array_t`对象。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 返回修改后的`array_t`对象。
- 用例

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

- 原型

```c
iterator_t *array_iterator_new(const array_t *array);
```

- 描述
    - 创建`array_t`对象的迭代器。
- 参数
    - `array`：`array_t`对象。
- 返回值
    - 返回容器的迭代器。



## array_iterator_delete()

- 原型

```c
void array_iterator_delete(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## array_iterator_has_next()

- 原型

```c
bool array_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## array_iterator_has_next()

- 原型

```c
T array_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

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

