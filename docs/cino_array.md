## cino_array

- 模块功能：
    - array_t：提供泛型动态数组操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### array_t

#### array_create()

- 函数原型：

```c
array_t *array_create(const str_t data_type);
```

- 功能：创建cino-array。
- 参数：

| 参数      | 说明                                                   |
| --------- | ------------------------------------------------------ |
| data_type | cino-array的元素类型，支持"int"、“double”、“T”（泛型） |

- 返回值：返回cino-array指针，创建失败返回`NULL`。

---

#### array_destroy()

- 函数原型：

```c
void array_destroy(array_t *array);
```

- 功能：销毁cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

> 对于T（泛型）cino-array，调用者需要在调用此函数之前自行释放所插入的元素。

---

#### array_is_empty()

- 函数原型：

```c
bool array_is_empty(const array_t *array);
```

- 功能：判断cino-array是否为空。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：cino-array为空返回`true`，非空返回`false`。

---

#### array_size()

- 函数原型：

```c
size_t array_size(const array_t *array);
```

- 功能：获取cino-array元素个数。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：cino-array元素个数。

---

#### array_clear()

- 函数原型：

```c
array_t *array_clear(array_t *array);
```

- 功能：清空cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：修改后的cino-array。

> 对于T（泛型）cino-array，调用者需要在调用此函数之前自行释放所插入的元素。

---

#### array_get()

- 函数原型：

```c
T array_get(const array_t *array, int index);
```

- 功能：获取cino-array指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 下标       |

- 返回值：返回cino-array指定下标元素。

> 对于基本数据类型cino-array，此函数会返回该数据类型的包装类型，调用者需要自行拆箱获取元素值。

---

#### array_set()

- 函数原型：

```c
void array_set(array_t *array, int index, T data);
```

- 功能：设置cino-array指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 下标       |
| data  | 新元素     |

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型，此函数不会释放该包装类型，需要由调用者自行释放。
> - 对于T（泛型）cino-array，调用者需要在调用此函数前自行释放被覆盖位置的空间。

---

#### array_append()

- 函数原型：

```c
array_t *array_append(array_t *array, T data);
```

- 功能：cino-array追加元素。
- 参数：

| 参数   | 说明        |
| ----- | -------------- |
| array | cino-array |
| data  | 新元素         |

- 返回值：修改后的cino-array。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型，此函数不会释放该包装类型，需要由调用者自行释放。
> - 对于T（泛型）cino-array，调用者需要在调用此函数前自行释放被覆盖位置的空间。

---

#### array_insert()

- 函数原型：

```c
array_t *array_insert(array_t *array, int index, T data);
```

- 功能：cino-array插入元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 插入下标   |
| data  | 新元素     |

- 返回值：修改后的cino-array。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型，此函数不会释放该包装类型，需要由调用者自行释放。
> - 对于T（泛型）cino-array，调用者需要在调用此函数前自行释放被覆盖位置的空间。

---

#### array_remove()

- 函数原型：

```c
array_t *array_remove(array_t *array, int index);
```

- 功能：删除cino-array中指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 删除下标   |

- 返回值：修改后的cino-array。

> 对于T（泛型）cino-array，该函数仅负责将元素从cino-array移除，调用者需要自行释放被删除元素。

---

#### array_min()

- 函数原型：

```c
T array_min(const array_t *array, compare_t compare);
```

- 功能：获取cino-array最小值。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| array   | cino-array                                                   |
| compare | 用于比较的回调函数，仅针对T（泛型）cino-array，基本数据类型cino-array设置为`NULL`即可 |

- 返回值：cino-array最小值。

> 对于基本数据类型cino-array，该函数会返回最小值的包装类型，调用者需要自行拆箱。

---

#### array_max()

- 函数原型：

```c
T array_max(const array_t *array, compare_t compare);
```

- 功能：获取cino-array最大值。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| array   | cino-array                                                   |
| compare | 用于比较的回调函数，仅针对T（泛型）cino-array，基本数据类型cino-array设置为`NULL`即可 |

- 返回值：cino-array最大值。

> 对于基本数据类型cino-array，该函数会返回最大值的包装类型，调用者需要自行拆箱。

---

#### array_index_of()

- 函数原型：

```c
int array_index_of(const array_t *array, void *context);
```

- 功能：获取cino-array指定元素首次出现下标。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| array   | cino-array                                                   |
| context | 对于基本数据类型cino-array，传入待查询元素的包装类型，调用者需要自行拆箱释放空间<br />对于T（泛型）cino-array，传入match_t类型的回调函数，用于匹配元素 |

- 返回值：cino-array指定元素首次出现下标，返回`-1`表示未找到。

---

- #### array_last_index_of()

    - 函数原型：

    ```c
    int array_last_index_of(const array_t *array, void *context);
    ```

    - 功能：获取cino-array指定元素最后一次出现下标。
    - 参数：

    | 参数    | 说明                                                         |
    | ------- | ------------------------------------------------------------ |
    | array   | cino-array                                                   |
    | context | 对于基本数据类型cino-array，传入待查询元素的包装类型，调用者需要自行拆箱释放空间<br />对于T（泛型）cino-array，传入match_t类型的回调函数，用于匹配元素 |

    - 返回值：cino-array指定元素最后一次出现下标，返回`-1`表示未找到。

---

#### array_count()

- 函数原型：

```c
int array_count(const array_t *array, void *context);
```

- 功能：统计cino-array指定元素出现次数。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| array   | cino-array                                                   |
| context | 对于基本数据类型cino-array，传入待查询元素的包装类型，调用者需要自行拆箱释放空间<br />对于T（泛型）cino-array，传入match_t类型的回调函数，用于匹配元素 |

- 返回值：指定元素出现次数。

---

#### array_reverse()

- 函数原型：

```c
array_t *array_reverse(array_t *array);
```

- 功能：反转cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：修改后的cino-array。

---

#### array_swap()

- 函数原型：

```c
array_t *array_swap(array_t *array, int index1, int index2);
```

- 功能：交换cino-array指定下标元素。
- 参数：

| 参数   | 说明       |
| ------ | ---------- |
| array  | cino-array |
| index1 | 下标1      |
| index2 | 下标2      |

- 返回值：修改后的cino-array。

---

#### array_sort()

- 函数原型：

```c
array_t *array_sort(array_t *array, bool reverse, compare_t compare);
```

- 功能：cino-array排序。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| array   | cino-array                                                   |
| reverse | 是否逆序                                                     |
| compare | 用于比较的回调函数，仅针对T（泛型）cino-array，基本数据类型cino-array设置为`NULL`即可 |

- 返回值：修改后的cino-array。

---

#### array_iter()

- 函数原型：

```c
iter_t array_iter(array_t *array)
```

- 功能：获取cino-array的迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：迭代器。

---

#### array_iter_has_next()

- 函数原型：

```c
bool array_iter_has_next(const array_t *array)
```

- 功能：判断是否存在下一个迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：如果存在下一个迭代器返回`true`，不存在返回`false`。

---

#### array_iter_next()

- 函数原型：

```c
iter_t array_iter_next(array_t *array)
```

- 功能：获取下一个迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：下一个迭代器。

