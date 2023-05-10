# pair_t

[TOC]



## pair_new()

- 原型

```c
pair_t *pair_new(T key, T value, destroy_t destroy_key, destroy_t destroy_value);
```

- 描述
    - 创建`pair_t`对象。
- 参数
    - `key`：key。
    - `value`：value。
    - `destroy_key`：用于销毁key的回调函数。
    - `destroy_value`：用于销毁value的回调函数。
- 返回值
    - 如果成功返回`pair_t`，否则返回`NULL`。
- 用例

```c
// Create a (int, int) pair
pair_t *pair1 = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);

// Create a (int, string) pair
pair_t *pair2 = pair_new(Integer_new(0), "hello", Integer_delete, NULL);
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

// Create a (Point, char) pair
pair_t *pair3 = pair_new(Point_new(1, 1), Character_new('A'), Point_delete, Character_delete);
```



## pair_delete()

- 原型

```c
void pair_delete(pair_t *pair);
```

- 描述
    - 销毁`pair_t`对象。
- 参数
    - `pair`：`pair_t`对象。
- 用例

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_delete(pair);
```



## pair_get_key()

- 原型

```c
T pair_get_key(const pair_t *pair);
```

- 描述
    - 获取`pair_t`对象的key。
- 参数
    - `pair`：`pair_t`对象。
- 返回值
    - 返回`pair_t`对象的key。
- 用例

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
Integer *key = pair_get_key(pair);
printf("%d\n", Integer_get(key));
pair_delete(pair);
```



## pair_get_value()

- 原型

```c
T pair_get_value(const pair_t *pair);
```

- 描述
    - 获取`pair_t`对象的value。
- 参数
    - `pair`：`pair_t`对象。
- 返回值
    - 返回`pair_t`对象的value。
- 用例

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
Integer *value = pair_get_value(pair);
printf("%d\n", Integer_get(value));
pair_delete(pair);
```



## pair_set_key()

- 原型

```c
pair_t *pair_set_key(pair_t *pair, T key);
```

- 描述
    - 设置`pair_t`对象的key。
- 参数
    - `pair`：`pair_t`对象。
    - `key`：key。
- 返回值
    - 返回修改后的`pair_t`对象。
- 用例

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_set_key(Integer_new(3));
Integer *key = pair_get_key(pair);
printf("%d\n", Integer_get(key));
pair_delete(pair);
```



## pair_set_value()

- 原型

```c
pair_t *pair_set_value(pair_t *pair, T value);
```

- 描述
    - 设置`pair_t`对象的value。
- 参数
    - `pair`：`pair_t`对象。
    - `value`：值。
- 返回值
    - 返回修改后的`pair_t`对象。
- 用例

```c
pair_t *pair = pair_new(Integer_new(2), Integer_new(4), Integer_delete, Integer_delete);
pair_set_value(Integer_new(9));
Integer *value = pair_get_value(pair);
printf("%d\n", Integer_get(value));
pair_delete(pair);
```

