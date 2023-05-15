# hash_map_t

[TOC]



## hash_map_new()

- 原型

```c
hash_map_t *hash_map_new(compare_t compare, hash_t hash);
```

- 描述
    - 创建`hash_map_t`对象。
- 参数
    - `compare`：用于比较两个key的回调函数。
    - `hash`：用于哈希key的回调函数。
- 返回值
    - 如果成功返回`hash_map_t`，否则返回`NULL`。
- 用例

```c
// Create a map with keys of integer type
hash_map_t *map1 = tree_map_new(Integer_compare, Integer_hash);

// Create a map with keys of double type
hash_map_t *map2 = tree_map_new(Double_compare, Double_hash);

// Create a map with keys of boolean type
hash_map_t *map3 = tree_map_new(Boolean_compare, Boolean_hash);

// Create a map with keys of char type
hash_map_t *map4 = tree_map_new(Character_compare, Character_hash);
```

```c
typedef struct Point {
    int x;
    int y;
} Point;

static Point *Point_new(int x, int y) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

static void Point_delete(void *ptr) {
    Point *point = ptr;
    free(point);
}

static int Point_compare(const void *ptr1, const void *ptr2) {
    const Point *point1 = ptr1;
    const Point *point2 = ptr2;
    if (point1->x < point2->x) {
        return -1;
    } else if (point1->x > point2->x) {
        return 1;
    } else {
        if (point1->y < point2->y) {
            return -1;
        } else if (point1->y > point2->y) {
            return 1;
        } else {
            return 0;
        }
    }
}

static size_t Point_hash(const void *ptr) {
    const Point *point = ptr;
    return (size_t)(point->x + point->y);
}

// Create a map of with keys of Point type
hash_map_t *points = hash_map_new(Point_compare, Point_hash);

// ...
```



## hash_map_delete()

- 原型

```c
void hash_map_delete(hash_map_t *map);
```

- 描述
    - 销毁`hash_map_t`对象。
- 参数
    - `map`：`hash_map_t`对象。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
hash_map_delete(set);
```



## hash_map_is_empty()

- 原型

```c
bool hash_map_is_empty(hash_map_t *map);
```

- 描述
    - 判断`hash_map_t`对象是否为空。
- 参数
    - `map`：`hash_map_t`对象。
- 返回值
    - 如果`hash_map_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
if (hash_map_is_empty(map)) {
    // ...
}
hash_map_delete(set);
```



## hash_map_size()

- 原型

```c
size_t hash_map_size(hash_map_t *map);
```

- 描述
    - 获取`hash_map_t`对象的大小。
- 参数
    - `map`：`hash_map_t`对象。
- 返回值
    - 返回`hash_map_t`对象的大小。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
printf("%d\n", hash_map_size(set));
hash_map_delete(map);
```



## hash_map_foreach()

- 原型

```c
void hash_map_foreach(hash_map_t *map, visit_pair_t visit);
```

- 描述
    - 遍历`hash_map_t`对象。
- 参数
    - `map`：`hash_map_t`对象。
    - `visit`：用于访问键值对的回调函数。
- 用例

```c
// Callback function for printing an integer
void item_print(T pair) {
    pair = (pair_t *)pair;
    Integer *key = pair_get_key(pair);
    Integer *value = pair_get_value(pair);
    printf("key: %d, value: %d\n", Integer_get(key), Integer_get(value));
}

int main() {
    hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

    for (int i = 0; i < 10; i++) {
        pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
        hash_map_put(map, pair);
    }

    hash_map_foreach(map, item_print);
    printf("\n");

    hash_map_delete(map);

    return 0;
}
```



## hash_map_clear()

- 原型

```c
hash_map_t *hash_map_clear(hash_map_t *map);
```

- 描述
    - 清空`hash_map_t`对象。
- 参数
    - `map`：`hash_map_t`对象。
- 返回值
    - 返回修改后的`hash_map_t`对象。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

hash_map_clear(map);
hash_map_delete(map);
```



## hash_map_contains()

- 原型

```c
bool hash_map_contains(const hash_map_t *map, T key);
```

- 描述
    - 判断`hash_map_t`对象是否包含指定key。
- 参数
    - `map`：`hash_map_t`对象。
    - `key`：key。
- 返回值
    - 如果`hash_map_t`对象包含指定元素返回`true`，否则返回`false`。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。

- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
if (hash_map_contains(map, target)) {
    // ...
}
Integer_delete(target);

hash_map_delete(map);
```



## hash_map_put()

- 原型

```c
hash_map_t *hash_map_put(hash_map_t *map, pair_t *pair);
```

- 描述
    - 在`hash_map_t`对象中添加一个键值对。
- 参数
    - `map`：`hash_map_t`对象。
    - `pair`：`pair_t`对象。
- 返回值
    - 返回修改后的`hash_map_t`对象。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);
for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}
hash_map_delete(map);
```



## hash_map_remove()

- 原型

```c
hash_map_t *hash_map_remove(hash_map_t *map, T key);
```

- 描述
    - 在`hash_map_t`对象中根据指定key删除键值对。
- 参数
    - `map`：`hash_map_t`对象。
    - `key`：key。
- 返回值
    - 返回修改后的`hash_map_t`对象。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。

- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
hash_map_remove(array, target);
Integer_delete(target);

hash_map_delete(map);
```



## hash_map_get()

- 原型

```c
T hash_map_get(const hash_map_t *map, T key);
```

- 描述
    - 根据指定key获取value。
- 参数
    - `map`：`hash_map_t`对象。
    - `key`：key。
- 返回值
    - 如果找到，返回键值对的value，否则返回`NULL`。
- 注意
    - 调用者**必须**释放参数`key`（如适用）。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

Integer *target = Integer_new(5);
Integer *value = hash_map_get(map, target);
printf("%d\n", Integer_get(value));
Integer_delete(value);

hash_map_delete(map);
```



## hash_map_iterator_new()

- 原型

```c
iterator_t *hash_map_iterator_new(const hash_map_t *map);
```

- 描述
    - 创建`hash_map_t`对象的迭代器。
- 参数
    - `map`：`hash_map_t`对象。
- 返回值
    - 返回容器的迭代器。



## hash_map_iterator_delete()

- 原型

```c
void hash_map_iterator_delete(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## hash_map_iterator_has_next()

- 原型

```c
bool hash_map_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## hash_map_iterator_next()

- 原型

```c
T hash_map_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

```c
hash_map_t *map = hash_map_new(Integer_compare, Integer_hash);

for (int i = 0; i < 10; i++) {
    pair_t *pair = pair_new(Integer_new(i), Integer_new(i * i), Integer_delete, Integer_delete);
    hash_map_put(map, pair);
}

iterator_t *iterator = tree_map_iterator_new(map);
while (hash_map_iterator_has_next(iterator)) {
    pair = hash_map_iterator_next(iterator);
    key = (Integer *)pair_get_key(pair);
    value = (Integer *)pair_get_value(pair);
    printf("key: %d, value: %d\n", Integer_get(key), Integer_get(value));
}
hash_map_iterator_delete(iterator);

hash_map_delete(map);
```

