# set_t

[TOC]



## set_create()

- 原型

```c
set_t *set_create(compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`set_t`对象。
- 参数
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`set_t`，否则返回`NULL`。
- 用例

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

- 原型

```c
void set_destroy(set_t *set);
```

- 描述
    - 销毁`set_t`对象。
- 参数
    - `set`：`set_t`对象。
- 用例

```c
set_t *set = set_create(Integer_compare, Integer_delete);
set_destroy(set);
```



## set_is_empty()

- 原型

```c
bool set_is_empty(const set_t *set);
```

- 描述
    - 判断`set_t`对象是否为空。
- 参数
    - `set`：`set_t`对象。
- 返回值
    - 如果`set_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
set_t *set = set_create(Integer_compare, Integer_delete);
if (sety_is_empty(set)) {
    // ...
}
set_destroy(set);
```



## set_size()

- 原型

```c
size_t set_size(const set_t *set);
```

- 描述
    - 获取`set_t`对象的大小。
- 参数
    - `set`：`set_t`对象。
- 返回值
    - 返回`set_t`对象的大小。
- 用例

```c
set_t *set = set_create(Integer_compare, Integer_delete);
printf("%d\n", set_size(set));
set_destroy(set);
```



## set_foreach()

- 原型

```c
void set_foreach(set_t *set, visit_t visit);
```

- 描述
    - 遍历`set_t`对象。
- 参数
    - `set`：`set_t`对象。
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

- 原型

```c
set_t *set_clear(set_t *set);
```

- 描述
    - 清空`set_t`对象。
- 参数
    - `set`：`set_t`对象。
- 返回值
    - 返回修改后的`set_t`对象。
- 用例

```c
set_t *set = set_create(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}

set_clear(set);
set_destroy(set);
```



## set_contains()

- 原型

```c
bool set_contains(const set_t *set, T elem);
```

- 描述
    - 判断`set_t`对象是否包含指定元素。
- 参数
    - `set`：`set_t`对象。
    - `elem`：元素。
- 返回值
    - 如果`set_t`对象包含指定元素返回`true`，否则返回`false`。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

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

- 原型

```c
set_t *set_add(set_t *set, T elem);
```

- 描述
    - 在`set_t`对象中添加元素。
- 参数
    - `set`：`set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`set_t`对象。
- 用例

```c
set_t *set = set_create(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    set_add(set, Integer_new(i));
}
set_destroy(set);
```



## set_remove()

- 原型

```c
set_t *set_remove(set_t *set, T elem);
```

- 描述
    - 从`set_t`对象中删除元素。
- 参数
    - `set`：`set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`set_t`对象。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

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

- 原型

```c
set_t *set_union(const set_t *set1, const set_t *set2);
```

- 描述
    - 获取两个`set_t`对象的并集。
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 返回两个`set_t`对象的并集。
- 注意
    - 调用者**必须**销毁返回的并集`set_t`对象。
- 用例

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

- 原型

```c
set_t *set_intersection(const set_t *set1, const set_t *set2);
```

- 描述
    - 获取两个`set_t`对象的交集。
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 返回两个`set_t`对象的交集。
- 注意
    - 调用者**必须**销毁返回的交集`set_t`对象。
- 用例

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

- 原型

```c
set_t *set_difference(const set_t *set1, const set_t *set2);
```

- 描述
    - 获取两个`set_t`对象的差集。
    - $ A - B $
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 返回两个`set_t`对象的差集。
- 注意
    - 调用者**必须**销毁返回的差集`set_t`对象。
- 用例

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

- 原型

```c
set_t *set_symmetric_difference(const set_t *set1, const set_t *set2);
```

- 描述
    - 获取两个`set_t`对象的对称差集。
    - $ (A - B) \cup (B - A) $
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 返回两个`set_t`对象的对称差集。
- 注意
    - 调用者**必须**销毁返回的对称差集`set_t`对象。
- 用例

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

- 原型

```c
bool set_is_disjoint(const set_t *set1, const set_t *set2);
```

- 描述
    - 判断两个`set_t`对象是否为不相交集合。
    - 如果两个集合的交集为空，那么它们为不相交集合。
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 如果两个`set_t`对象是否为不相交集合返回`true`，否则返回`false`。
- 用例

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

- 原型

```c
bool set_is_subset(const set_t *set1, const set_t *set2);
```

- 描述
    - 判断`set1`是否为`set2`的子集。
    - 如果A中所有元素都是B中的元素，那么A是B的子集。
- 参数
    - `set1`：第一个`set_t`对象。
    - `set2`：第二个`set_t`对象。
- 返回值
    - 如果`set1`是`set2`的子集返回`true`，否则返回`false`。
- 用例

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

- 原型

```c
iterator_t *set_iterator_create(const set_t *set);
```

- 描述
    - 创建`set_t`对象的迭代器。
- 参数
    - `set`：`set_t`对象。
- 返回值
    - 返回容器的迭代器。



## set_iterator_destroy()

- 原型

```c
void set_iterator_destroy(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## set_iterator_has_next()

- 原型

```c
bool set_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## set_iterator_next()

- 原型

```c
T set_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

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

