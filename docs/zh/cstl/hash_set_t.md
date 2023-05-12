# hash_set_t

[TOC]



## hash_set_new()

- 原型

```c
hash_set_t *hash_set_new(compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`hash_set_t`对象。
- 参数
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
    - `hash`: 用于哈希元素的回调函数。
- 返回值
    - 如果成功返回`hash_set_t`，否则返回`NULL`。
- 用例

```c
// Create an integer set using Integer wrapper
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

// Create a double set using Double wrapper
hash_set_t *set2 = unhash_set_new(Double_compare, Double_delete, Double_hash);

// Create a boolean set using Boolean wrapper
hash_set_t *set3 = hash_set_new(Boolean_compare, Boolean_delete, Boolean_hash);

// Create a character set using Character wrapper
hash_set_t *set4 = hash_set_new(Character_compare, Character_delete, Character_hash);
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

// Callback function for hashing an employee
size_t Employee_hash(const void *ptr) {
    const Employee *e = (Employee *)ptr;
    return (size_t)age;
}

// Create a set of employees
hash_set_t *employees = hash_set_new(Employee_compare, Employee_delete, Employee_hash);

// ...
```



## hash_set_delete()

- 原型

```c
void hash_set_delete(hash_set_t *set);
```

- 描述
    - 销毁`hash_set_t`对象。
- 参数
    - `set`：`hash_set_t`对象。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_delete(set);
```



## hash_set_is_empty()

- 原型

```c
bool hash_set_is_empty(const hash_set_t *set);
```

- 描述
    - 判断`hash_set_t`对象是否为空。
- 参数
    - `set`：`hash_set_t`对象。
- 返回值
    - 如果`hash_set_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
if (hash_set_is_empty(set)) {
    // ...
}
hash_set_delete(set);
```



## hash_set_size()

- 原型

```c
size_t hash_set_size(const hash_set_t *set);
```

- 描述
    - 获取`hash_set_t`对象的大小。
- 参数
    - `set`：`hash_set_t`对象。
- 返回值
    - 返回`hash_set_t`对象的大小。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
printf("%d\n", hash_set_size(set));
hash_set_delete(set);
```



## hash_set_foreach()

- 原型

```c
void hash_set_foreach(hash_set_t *set, visit_t visit);
```

- 描述
    - 遍历`hash_set_t`对象。
- 参数
    - `set`：`hash_set_t`对象。
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
    hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the set
        hash_set_add(set, Integer_new(i));
    }

    // Print the set
    hash_set_foreach(set, Integer_print);
    printf("\n");

    // Triple the integers in the set
    hash_set_foreach(set, Integer_triple);

    // Print the set
    hash_set_foreach(set, Integer_print);
    printf("\n");

    // Destroy the set
    hash_set_delete(set);

    return 0;
}
```



## hash_set_clear()

- 原型

```c
hash_set_t *hash_set_clear(hash_set_t *set);
```

- 描述
    - 清空`hash_set_t`对象。
- 参数
    - `set`：`hash_set_t`对象。
- 返回值
    - 返回修改后的`hash_set_t`对象。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

hash_set_clear(set);
hash_set_delete(set);
```



## hash_set_contains()

- 原型

```c
bool hash_set_contains(const hash_set_t *set, T elem);
```

- 描述
    - 判断`hash_set_t`对象是否包含指定元素。
- 参数
    - `set`：`hash_set_t`对象。
    - `elem`：元素。
- 返回值
    - 如果`hash_set_t`对象包含指定元素返回`true`，否则返回`false`。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

Integer *target = Integer_new(5);
if (hash_set_contains(set, target)) {
    // ...
}
Integer_delete(target);

hash_set_delete(set);
```



## hash_set_add()

- 原型

```c
hash_set_t *hash_set_add(hash_set_t *set, T elem);
```

- 描述
    - 在`hash_set_t`对象中添加元素。
- 参数
    - `set`：`hash_set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`hash_set_t`对象。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}
hash_set_delete(set);
```



## hash_set_remove()

- 原型

```c
hash_set_t *hash_set_remove(hash_set_t *set, T elem);
```

- 描述
    - 从`hash_set_t`对象中删除元素。
- 参数
    - `set`：`hash_set_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`hash_set_t`对象。
- 注意
    - 调用者**必须**释放参数`elem`（如适用）。

- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set, Integer_new(i));
}

Integer *integer = Integer_new(5);
hash_set_remove(array, integer);
Integer_delete(integer);

hash_set_delete(set);
```



## hash_set_union()

- 原型

```c
hash_set_t *hash_set_union(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 获取两个`hash_set_t`对象的并集。
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 返回两个`hash_set_t`对象的并集。
- 注意
    - 调用者**必须**销毁返回的并集`hash_set_t`对象。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_union(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_intersection()

- 原型

```c
hash_set_t *hash_set_intersection(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 获取两个`hash_set_t`对象的交集。
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 返回两个`hash_set_t`对象的交集。
- 注意
    - 调用者**必须**销毁返回的交集`hash_set_t`对象。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_intersection(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_difference()

- 原型

```c
hash_set_t *hash_set_difference(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 获取两个`hash_set_t`对象的差集。
    - $ A - B $
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 返回两个`hash_set_t`对象的差集。
- 注意
    - 调用者**必须**销毁返回的差集`hash_set_t`对象。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_difference(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_symmetric_difference()

- 原型

```c
hash_set_t *hash_set_symmetric_difference(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 获取两个`hash_set_t`对象的对称差集。
    - $ (A - B) \cup (B - A) $
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 返回两个`hash_set_t`对象的对称差集。
- 注意
    - 调用者**必须**销毁返回的对称差集`hash_set_t`对象。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 5; i < 15; i++) {
    hash_set_add(set2, Integer_new(i));
}

hash_set_t *set3 = hash_set_symmetric_difference(set1, set2);

hash_set_delete(set1);
hash_set_delete(set2);
hash_set_delete(set2);
```



## hash_set_is_disjoint()

- 原型

```c
bool hash_set_is_disjoint(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 判断两个`hash_set_t`对象是否为不相交集合。
    - 如果两个集合的交集为空，那么它们为不相交集合。
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 如果两个`hash_set_t`对象是否为不相交集合返回`true`，否则返回`false`。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 10; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 10; i < 20; i++) {
    hash_set_add(set2, Integer_new(i));
}

if (hash_set_is_disjoint(set1, set2)) {
    // ...
}

hash_set_delete(set1);
hash_set_delete(set2);
```



## hash_set_is_subset()

- 原型

```c
bool hash_set_is_subset(const hash_set_t *set1, const hash_set_t *set2);
```

- 描述
    - 判断`set1`是否为`set2`的子集。
    - 如果A中所有元素都是B中的元素，那么A是B的子集。
- 参数
    - `set1`：第一个`hash_set_t`对象。
    - `set2`：第二个`hash_set_t`对象。
- 返回值
    - 如果`set1`是`set2`的子集返回`true`，否则返回`false`。
- 用例

```c
hash_set_t *set1 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
hash_set_t *set2 = hash_set_new(Integer_compare, Integer_delete, Integer_hash);

for (int i = 0; i < 5; i++) {
    hash_set_add(set1, Integer_new(i));
}

for (int i = 0; i < 10; i++) {
    hash_set_add(set2, Integer_new(i));
}

if (hash_set_is_subset(set1, set2)) {
    // ...
}

hash_set_delete(set1);
hash_set_delete(set2);
```



## hash_set_iterator_new()

- 原型

```c
iterator_t *hash_set_iterator_new(const hash_set_t *set);
```

- 描述
    - 创建`hash_set_t`对象的迭代器。
- 参数
    - `set`：`hash_set_t`对象。
- 返回值
    - 返回容器的迭代器。



## hash_set_iterator_delete()

- 原型

```c
void hash_set_iterator_delete(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## hash_set_iterator_has_next()

- 原型

```c
bool hash_set_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## hash_set_iterator_next()

- 原型

```c
T hash_set_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

```c
hash_set_t *set = hash_set_new(Integer_compare, Integer_delete, Integer_hash);
for (i = 0; i < 10; i++) {
    hash_set_add(array, Integer_new(i));
}

iterator_t *iterator = hash_set_iterator_new(array);
while (hash_set_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)hash_set_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

hash_set_iterator_delete(iterator);
hash_set_delete(set);
```

