## cino_map

- 模块功能：
    - map_t：提供泛型字典操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### map_t

#### kv_pair_get_key()

- 函数原型：

```c
const str_t kv_pair_get_key(kv_pair_t *kv_pair);
```

- 功能：获取键值对中的key。

- 参数：

| 参数    | 说明      |
| ------- | --------- |
| kv_pair | kv_pair_t |

- 返回值：返回键值对中的key。

---

#### kv_pair_get_value()

- 函数原型：

```c
T kv_pair_get_value(kv_pair_t *kv_pair);
```

- 功能：获取键值对中的value。

- 参数：

| 参数    | 说明      |
| ------- | --------- |
| kv_pair | kv_pair_t |

- 返回值：返回键值对中的value。

---

#### map_create()

- 函数原型：

```c
map_t *map_create(destroy_t destroy);
```

- 功能：创建cino-map。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| destroy | 用于销毁键值对中的value的回调函数，<br />wrapper_int_t类型使用destroy_int，<br />wrapper_double_t类型使用destroy_double，<br />wrapper_char_t类型使用destroy_char，<br />T类型可使用自定义destroy_t函数接口，使用`NULL`为默认方式 |

- 返回值：返回cino-map指针，创建失败返回`NULL`。

---

#### map_destroy()

- 函数原型：

```c
void map_destroy(map_t *map);
```

- 功能：销毁cino-map。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| map  | cino-map |

---

#### map_is_empty()

- 函数原型：

```c
bool map_is_empty(const map_t *map);
```

- 功能：判断cino-map是否为空。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| map  | cino-map |

- 返回值：cino-map为空返回`true`，非空返回`false`。

---

#### map_size()

- 函数原型：

```c
size_t map_size(const map_t *map);
```

- 功能：获取cino-map元素个数。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| map  | cino-map |

- 返回值：cino-map元素个数。

---

#### map_clear()

- 函数原型：

```c
map_t *map_clear(map_t *map);
```

- 功能：清空cino-map。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| map  | cino-map |

- 返回值：修改后的cino-map。

---

#### map_foreach()

- 函数原型：

```c
void map_foreach(map_t *map, visit_t visit);
```

- 功能：遍历cino-map。
- 参数：

| 参数  | 说明                       |
| ----- | -------------------------- |
| map   | cino-map                   |
| visit | 用于访问单个元素的回调函数 |

---

#### map_contains()

- 函数原型：

```c
bool map_contains(map_t *map, const str_t key);
```

- 功能：根据key查询cino-map是否存在对应键值对。
- 参数：

| 参数 | 说明                          |
| ---- | ----------------------------- |
| map  | cino-map                      |
| key  | 键值对的key，只能为字符串类型 |

- 返回值：元素存在返回`true`，不存在返回`false`。

---

#### map_add()

- 函数原型：

```c
map_t *map_add(map_t *map, const str_t key, T value);
```

- 功能：cino-map添加键值对。
- 参数：

| 参数  | 说明                                                       |
| ----- | ---------------------------------------------------------- |
| map   | cino-map                                                   |
| key   | 键值对的key，只能为字符串类型                              |
| value | 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。 |

- 返回值：修改后的cino-map。

---

#### map_remove()

- 函数原型：

```c
map_t *map_remove(map_t *map, const str_t key);
```

- 功能：根据key删除cino-map中指定键值对。
- 参数：

| 参数 | 说明                          |
| ---- | ----------------------------- |
| map  | cino-map                      |
| key  | 键值对的key，只能为字符串类型 |

- 返回值：修改后的cino-map。
