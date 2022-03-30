## cino_list

- 模块功能：
    - list_t：提供泛型双向链表操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### list_t

#### list_create()

- 函数原型：

```c
list_t *list_create(const str_t data_type);
```

- 功能：创建cino-list。
- 参数：

| 参数      | 说明                                                  |
| --------- | ----------------------------------------------------- |
| data_type | cino-list的元素类型，支持"int"、“double”、“T”（泛型） |

- 返回值：返回cino-list指针，创建失败返回`NULL`。

---

#### list_destroy()

- 函数原型：

```c
void list_destroy(list_t *list);
```

- 功能：销毁cino-list。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

> 对于T（泛型）cino-list，调用者需要在调用此函数之前自行释放所插入的元素。

---

#### list_is_empty()

- 函数原型：

```c
bool list_is_empty(const list_t *list);
```

- 功能：判断cino-list是否为空。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

- 返回值：cino-list为空返回`true`，非空返回`false`。

---

#### list_size()

- 函数原型：

```c
size_t list_size(const list_t *list);
```

- 功能：获取cino-list元素个数。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

- 返回值：cino-list元素个数。

---

#### list_clear()

- 函数原型：

```c
list_t *list_clear(list_t *list);
```

- 功能：清空cino-list。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

- 返回值：修改后的cino-list。

> 对于T（泛型）cino-list，调用者需要在调用此函数之前自行释放所插入的元素。

---

#### list_get_front()

- 函数原型：

```c
T list_get_front(const list_t *list);
```

- 功能：获取cino-list头部元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |

- 返回值：返回cino-list头部元素。

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者需要自行拆箱获取元素值。

---

#### list_get_back()

- 函数原型：

```c
T list_get_back(const list_t *list);
```

- 功能：获取cino-list尾部元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |

- 返回值：返回cino-list尾部元素。

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者需要自行拆箱获取元素值。

---

#### list_get()

- 函数原型：

```c
T list_get(const list_t *list, int index);
```

- 功能：获取cino-list指定下标元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |
| index | 下标      |

- 返回值：返回cino-list指定下标元素。

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者需要自行拆箱获取元素值。

---

#### list_set()

- 函数原型：

```c
void list_set(list_t *list, int index, T data);
```

- 功能：设置cino-list指定下标元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |
| index | 下标      |
| data  | 新元素    |

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型，此函数不会释放该包装类型，需要由调用者自行释放。
> - 对于T（泛型）cino-list，调用者需要在调用此函数前自行释放被覆盖位置的空间。

---

#### list_index_of()

- 函数原型：

```c
int list_index_of(const list_t *list, void *context);
```

- 功能：获取cino-list指定元素首次出现下标。
- 参数：

| 参数    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| list    | cino-list                                                    |
| context | 对于基本数据类型cino-list，传入待查询元素的包装类型，调用者需要自行拆箱释放空间<br />对于T（泛型）cino-list，传入match_t类型的回调函数，用于匹配元素 |

- 返回值：cino-list指定元素首次出现下标，返回`-1`表示未找到。

---

