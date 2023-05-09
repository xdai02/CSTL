# ordered_set_t

[TOC]



## ordered_set_new()

- 原型

```c
ordered_set_t *ordered_set_new(compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`ordered_set_t`对象。
- 参数
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`ordered_set_t`，否则返回`NULL`。
- 用例

```c
// Create an integer set using Integer wrapper
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);

// Create a double set using Double wrapper
ordered_set_t *set2 = ordered_set_new(Double_compare, Double_delete);

// Create a boolean set using Boolean wrapper
ordered_set_t *set3 = ordered_set_new(Boolean_compare, Boolean_delete);

// Create a character set using Character wrapper
ordered_set_t *set4 = ordered_set_new(Character_compare, Character_delete);
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

// Create a set of employees
ordered_set_t *employees = ordered_set_new(Employee_compare, Employee_delete);

// ...
```



## ordered_set_delete()

- 原型

```c
void ordered_set_delete(ordered_set_t *set);
```

- 描述
    - 销毁`ordered_set_t`对象。
- 参数
    - `set`：`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_delete(set);
```



## ordered_set_is_empty()

- 原型

```c
bool ordered_set_is_empty(const ordered_set_t *set);
```

- 描述
    - 判断`ordered_set_t`对象是否为空。
- 参数
    - `set`：`ordered_set_t`对象。
- 返回值
    - 如果`ordered_set_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
if (ordered_set_is_empty(set)) {
    // ...
}
ordered_set_delete(set);
```



## ordered_set_size()

- 原型

```c
size_t ordered_set_size(const ordered_set_t *set);
```

- 描述
    - 获取`ordered_set_t`对象的大小。
- 参数
    - `set`：`ordered_set_t`对象。
- 返回值
    - 返回`ordered_set_t`对象的大小。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
printf("%d\n", ordered_set_size(set));
ordered_set_delete(set);
```



## ordered_set_foreach()

- 原型

```c
void ordered_set_foreach(ordered_set_t *set, visit_t visit);
```

- 描述
    - 遍历`ordered_set_t`对象。
- 参数
    - `set`：`ordered_set_t`对象。
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
    ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        ordered_set_add(set, Integer_new(i));
    }

    // Print the set
    ordered_set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    ordered_set_foreach(set, Integer_triple);

    // Print the set
    ordered_set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    ordered_set_delete(set);

    return 0;
}
```



## ordered_set_clear()

- 原型

```c
ordered_set_t *ordered_set_clear(ordered_set_t *set);
```

- 描述
    - 清空`ordered_set_t`对象。
- 参数
    - `set`：`ordered_set_t`对象。
- 返回值
    - 返回修改后的`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

ordered_set_clear(set);
ordered_set_delete(set);
```



## ordered_set_contains()

- 原型

```c
bool ordered_set_contains(const ordered_set_t *set, T elem);
```

- 描述
    - 判断`ordered_set_t`对象是否包含指定元素。
- 参数
    - `set`：`ordered_set_t`对象。
    - `elem`：元素。
- 返回值
    - 如果`ordered_set_t`对象包含指定元素返回`true`，否则返回`false`。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (ordered_set_contains(set, target)) {
    // ...
}
Integer_delete(target);

ordered_set_delete(set);
```



## ordered_set_add()

- 原型

```c
ordered_set_t *ordered_set_add(ordered_set_t *set, T elem);
```

- 描述
    - 在`ordered_set_t`对象中添加元素。
- 参数
    - `set`：`ordered_set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}
ordered_set_delete(set);
```



## ordered_set_remove()

- 原型

```c
ordered_set_t *ordered_set_remove(ordered_set_t *set, T elem);
```

- 描述
    - 从`ordered_set_t`对象中删除元素。
- 参数
    - `set`：`ordered_set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`ordered_set_t`对象。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set, Integer_new(i));
}

Integer *integer = Integer_new(5);
ordered_set_remove(array, integer);
Integer_delete(integer);

ordered_set_delete(set);
```



## ordered_set_union()

- 原型

```c
ordered_set_t *ordered_set_union(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 获取两个`ordered_set_t`对象的并集。
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 返回两个`ordered_set_t`对象的并集。
- 注意
    - 调用者**必须**销毁返回的并集`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_union(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_intersection()

- 原型

```c
ordered_set_t *ordered_set_intersection(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 获取两个`ordered_set_t`对象的交集。
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 返回两个`ordered_set_t`对象的交集。
- 注意
    - 调用者**必须**销毁返回的交集`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_intersection(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_difference()

- 原型

```c
ordered_set_t *ordered_set_difference(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 获取两个`ordered_set_t`对象的差集。
    - $ A - B $
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 返回两个`ordered_set_t`对象的差集。
- 注意
    - 调用者**必须**销毁返回的差集`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_difference(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_symmetric_difference()

- 原型

```c
ordered_set_t *ordered_set_symmetric_difference(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 获取两个`ordered_set_t`对象的对称差集。
    - $ (A - B) \cup (B - A) $
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 返回两个`ordered_set_t`对象的对称差集。
- 注意
    - 调用者**必须**销毁返回的对称差集`ordered_set_t`对象。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    ordered_set_add(set2, Integer_new(i));
}

ordered_set_t *set3 = ordered_set_symmetric_difference(set1, set2);

ordered_set_delete(set1);
ordered_set_delete(set2);
ordered_set_delete(set2);
```



## ordered_set_is_disjoint()

- 原型

```c
bool ordered_set_is_disjoint(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 判断两个`ordered_set_t`对象是否为不相交集合。
    - 如果两个集合的交集为空，那么它们为不相交集合。
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 如果两个`ordered_set_t`对象是否为不相交集合返回`true`，否则返回`false`。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    ordered_set_add(set2, Integer_new(i));
}

if (ordered_set_is_disjoint(set1, set2)) {
    // ...
}

ordered_set_delete(set1);
ordered_set_delete(set2);
```



## ordered_set_is_subset()

- 原型

```c
bool ordered_set_is_subset(const ordered_set_t *set1, const ordered_set_t *set2);
```

- 描述
    - 判断`set1`是否为`set2`的子集。
    - 如果A中所有元素都是B中的元素，那么A是B的子集。
- 参数
    - `set1`：第一个`ordered_set_t`对象。
    - `set2`：第二个`ordered_set_t`对象。
- 返回值
    - 如果`set1`是`set2`的子集返回`true`，否则返回`false`。
- 用例

```c
ordered_set_t *set1 = ordered_set_new(Integer_compare, Integer_delete);
ordered_set_t *set2 = ordered_set_new(Integer_compare, Integer_delete);

for (int i = 0; i < 5; i++) {
    ordered_set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    ordered_set_add(set2, Integer_new(i));
}

if (ordered_set_is_subset(set1, set2)) {
    // ...
}

ordered_set_delete(set1);
ordered_set_delete(set2);
```



## ordered_set_iterator_create()

- 原型

```c
iterator_t *ordered_set_iterator_create(const ordered_set_t *set);
```

- 描述
    - 创建`ordered_set_t`对象的迭代器。
- 参数
    - `set`：`ordered_set_t`对象。
- 返回值
    - 返回容器的迭代器。



## ordered_set_iterator_destroy()

- 原型

```c
void ordered_set_iterator_destroy(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## ordered_set_iterator_has_next()

- 原型

```c
bool ordered_set_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## ordered_set_iterator_next()

- 原型

```c
T ordered_set_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

```c
ordered_set_t *set = ordered_set_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    ordered_set_add(array, Integer_new(i));
}

iterator_t *iterator = ordered_set_iterator_create(array);
while (ordered_set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)ordered_set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

ordered_set_iterator_destroy(iterator);
ordered_set_delete(set);
```

