## cino_set

- 模块功能：
    - set_t：提供泛型集合操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### set_t

#### set_create()

- 函数原型：

```c
set_t *set_create(data_type_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-set。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-set的元素类型，支持DATA_TYPE_INT、DATA_TYPE_DOUBLE、DATA_TYPE_CHAR、DATA_TYPE_T（泛型） |
| compare   | 用于比较的回调函数，<br />DATA_TYPE_INT类型使用compare_int，<br />DATA_TYPE_DOUBLE类型使用compare_double，<br />DATA_TYPE_CHAR类型使用compare_char，<br />DATA_TYPE_T类型可使用自定义compare_t函数接口，使用`NULL`为默认方式 |
| destroy   | 用于销毁的回调函数，<br />DATA_TYPE_INT类型使用destroy_int，<br />DATA_TYPE_DOUBLE类型使用destroy_double，<br />DATA_TYPE_CHAR类型使用destroy_char，<br />DATA_TYPE_T类型可使用自定义destroy_t函数接口，使用`NULL`为默认方式 |

- 返回值：返回cino-set指针，创建失败返回`NULL`。

---

#### set_destroy()

- 函数原型：

```c
void set_destroy(set_t *set);
```

- 功能：销毁cino-set。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |

---

#### set_is_empty()

- 函数原型：

```c
bool set_is_empty(const set_t *set);
```

- 功能：判断cino-set是否为空。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |

- 返回值：cino-set为空返回`true`，非空返回`false`。

---

#### set_size()

- 函数原型：

```c
size_t set_size(const set_t *set);
```

- 功能：获取cino-set元素个数。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |

- 返回值：cino-set元素个数。

---

#### set_clear()

- 函数原型：

```c
set_t *set_clear(set_t *set);
```

- 功能：清空cino-set。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |

- 返回值：修改后的cino-set。

---

#### set_foreach()

- 函数原型：

```c
void set_foreach(set_t *set, visit_t visit);
```

- 功能：遍历cino-set。
- 参数：

| 参数      | 说明                       |
| --------- | -------------------------- |
| set       | cino-set                   |
| visit     | 用于访问单个元素的回调函数 |

---

#### set_contains()

- 函数原型：

```c
bool set_contains(set_t *set, T data);
```

- 功能：判断cino-set是否存在指定数据。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |
| data | 查询元素 |

- 返回值：元素存在返回`true`，不存在返回`false`。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。调用者需要拆箱/释放。

---

#### set_add()

- 函数原型：

```c
set_t *set_add(set_t *set, T data);
```

- 功能：cino-set添加元素。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |
| data | 新元素   |

- 返回值：修改后的cino-set。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### set_remove()

- 函数原型：

```c
set_t *set_remove(set_t *set, T data);
```

- 功能：删除cino-set中指定元素。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set  | cino-set |
| data | 删除元素 |

- 返回值：修改后的cino-set。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### set_intersection()

- 函数原型：

```c
set_t *set_intersection(set_t *set1, set_t *set2);
```

- 功能：交集。
- 参数：

| 参数     | 说明     |
| -------- | -------- |
| set1     | cino-set |
| set2     | cino-set |

- 返回值：返回包含元素引用的交集。

---

#### set_union()

- 函数原型：

```c
set_t *set_union(set_t *set1, set_t *set2);
```

- 功能：并集。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set1 | cino-set |
| set2 | cino-set |

- 返回值：返回包含元素引用的并集。

---

#### set_difference()

- 函数原型：

```c
set_t *set_difference(set_t *set1, set_t *set2);
```

- 功能：差集。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| set1 | cino-set |
| set2 | cino-set |

- 返回值：返回包含元素引用的差集。
