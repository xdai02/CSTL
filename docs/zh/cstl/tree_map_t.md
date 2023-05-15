# tree_map_t

[TOC]



## tree_map_new()

- 原型

```c
tree_map_t *tree_map_new(compare_t compare);
```

- 描述
    - 创建`tree_map_t`对象。
- 参数
    - `compare`：用于比较两个key的回调函数。
- 返回值
    - 如果成功返回`tree_map_t`，否则返回`NULL`。
- 用例

```c
// Create a map with keys of integer type
tree_map_t *map1 = tree_map_new(Integer_compare);

// Create a map with keys of double type
tree_map_t *map2 = tree_map_new(Double_compare);

// Create a map with keys of boolean type
tree_map_t *map3 = tree_map_new(Boolean_compare);

// Create a map with keys of char type
tree_map_t *map4 = tree_map_new(Character_compare);
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

// Create a map of with keys of Employee type
tree_map_t *employees = tree_map_new(Employee_compare);

// ...
```



## tree_map_delete()

- 原型

```c
void tree_map_delete(tree_map_t *map);
```

- 描述
    - 销毁`tree_map_t`对象。
- 参数
    - `map`：`tree_map_t`对象。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);
tree_map_delete(map);
```



## tree_map_is_empty()

- 原型

```c
bool tree_map_is_empty(tree_map_t *map);
```

- 描述
    - 判断`tree_map_t`对象是否为空。
- 参数
    - `map`：`tree_map_t`对象。
- 返回值
    - 如果`tree_map_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);
if (tree_map_is_empty(map)) {
    // ...
}
tree_map_delete(map);
```



## tree_map_size()

- 原型

```c
size_t tree_map_size(tree_map_t *map);
```

- 描述
    - 获取`tree_map_t`对象的大小。
- 参数
    - `map`：`tree_map_t`对象。
- 返回值
    - 返回`tree_map_t`对象的大小。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);
printf("%d\n", tree_map_size(map));
tree_map_delete(map);
```



## tree_map_foreach()

- 原型

```c
void tree_map_foreach(tree_map_t *map, visit_pair_t visit);
```

- 描述
    - 遍历`tree_map_t`对象。
- 参数
    - `map`：`tree_map_t`对象。
    - `visit`：用于访问键值对的回调函数。
- 用例

```c
// Callback function for printing an integer
void item_print(T pair) {
    pair = (pair_t *)pair;
    Integer *key = pair_get_key(pair);
    Integer *value = pair_get_value(pair);
    printf("key：%d, value：%d\n", Integer_get(key), Integer_get(value));
}

int main() {
    tree_map_t *map = tree_map_new(Integer_compare);

    for (int i = 0; i < 10; i++) {
        pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        tree_map_put(map, pair);
    }

    tree_map_foreach(map, item_print);
    printf("\n");

    tree_map_delete(map);

    return 0;
}
```



## tree_map_clear()

- 原型

```c
tree_map_t *tree_map_clear(tree_map_t *map);
```

- 描述
    - 清空`tree_map_t`对象。
- 参数
    - `map`：`tree_map_t`对象。
- 返回值
    - 返回修改后的`tree_map_t`对象。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

tree_map_clear(map);
tree_map_delete(map);
```



## tree_map_contains()

- 原型

```c
bool tree_map_contains(const tree_map_t *map, T key);
```

- 描述
    - 判断`tree_map_t`对象是否包含指定key。
- 参数
    - `map`：`tree_map_t`对象。
    - `key`：key。
- 返回值
    - 如果`tree_map_t`对象包含指定元素返回`true`，否则返回`false`。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。

- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
if (tree_map_contains(map, target)) {
    // ...
}
Integer_delete(target);

tree_map_delete(map);
```



## tree_map_put()

- 原型

```c
tree_map_t *tree_map_put(tree_map_t *map, pair_t *pair);
```

- 描述
    - 在`tree_map_t`对象中添加一个键值对。
- 参数
    - `map`：`tree_map_t`对象。
    - `pair`：`pair_t`对象。
- 返回值
    - 返回修改后的`tree_map_t`对象。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);
for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}
tree_map_delete(map);
```



## tree_map_remove()

- 原型

```c
tree_map_t *tree_map_remove(tree_map_t *map, T key);
```

- 描述
    - 在`tree_map_t`对象中根据指定key删除键值对。
- 参数
    - `map`：`tree_map_t`对象。
    - `key`：key。
- 返回值
    - 返回修改后的`tree_map_t`对象。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。

- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
tree_map_remove(array, target);
Integer_delete(target);

tree_map_delete(map);
```



## tree_map_get()

- 原型

```c
T tree_map_get(const tree_map_t *map, T key);
```

- 描述
    - 根据指定key获取value。
- 参数
    - `map`：`tree_map_t`对象。
    - `key`：key。
- 返回值
    - 如果找到，返回键值对的value，否则返回`NULL`。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

Integer *target = Integer_new(5);
Integer *value = tree_map_get(map, target);
printf("%d\n", Integer_get(value));
Integer_delete(value);

tree_map_delete(map);
```



## tree_map_iterator_new()

- 原型

```c
iterator_t *tree_map_iterator_new(const tree_map_t *map);
```

- 描述
    - 创建`tree_map_t`对象的迭代器。
- 参数
    - `map`：`tree_map_t`对象。
- 返回值
    - 返回容器的迭代器。



## tree_map_iterator_delete()

- 原型

```c
void tree_map_iterator_delete(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## tree_map_iterator_has_next()

- 原型

```c
bool tree_map_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## tree_map_iterator_next()

- 原型

```c
T tree_map_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

```c
tree_map_t *map = tree_map_new(Integer_compare);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    tree_map_put(map, pair);
}

iterator_t *iterator = tree_map_iterator_new(map);
while (tree_map_iterator_has_next(iterator)) {
    pair = tree_map_iterator_next(iterator);
    key = (Integer *)pair_get_key(pair);
    value = (Integer *)pair_get_value(pair);
    printf("key：%d, value：%d\n", Integer_get(key), Integer_get(value));
}
tree_map_iterator_delete(iterator);

tree_map_delete(map);
```

