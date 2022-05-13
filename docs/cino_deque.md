## cino_deque

- 模块功能：
    - deque_t：提供泛型双端队列操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### deque_t

#### deque_create()

- 函数原型：

```c
deque_t *deque_create(data_type_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-deque。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-deque的元素类型，支持DATA_TYPE_INT、DATA_TYPE_DOUBLE、DATA_TYPE_CHAR、DATA_TYPE_T（泛型） |
| compare   | 用于比较的回调函数，<br />DATA_TYPE_INT类型使用compare_int，<br />DATA_TYPE_DOUBLE类型使用compare_double，<br />DATA_TYPE_CHAR类型使用compare_char，<br />DATA_TYPE_T类型可使用自定义compare_t函数接口，使用`NULL`使用默认方式 |
| destroy   | 用于销毁的回调函数，<br />DATA_TYPE_INT类型使用compare_int，<br />DATA_TYPE_DOUBLE类型使用compare_double，<br />DATA_TYPE_CHAR类型使用compare_char，<br />DATA_TYPE_T类型可使用自定义compare_t函数接口，使用`NULL`使用默认方式 |

- 返回值：返回cino-deque指针，创建失败返回`NULL`。

---

#### deque_destroy()

- 函数原型：

```c
void deque_destroy(deque_t *deque);
```

- 功能：销毁cino-deque。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

---

#### deque_is_empty()

- 函数原型：

```c
bool deque_is_empty(const deque_t *deque);
```

- 功能：判断cino-deque是否为空。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：cino-deque为空返回`true`，非空返回`false`。

---

#### deque_size()

- 函数原型：

```c
size_t deque_size(const deque_t *dequearray);
```

- 功能：获取cino-deque元素个数。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：cino-deque元素个数。

---

#### deque_clear()

- 函数原型：

```c
deque_t *deque_clear(deque_t *deque);
```

- 功能：清空cino-deque。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：修改后的cino-deque。

---

#### deque_push_front()

- 函数原型：

```c
deque_t *deque_push_front(deque_t *deque, T data)
```

- 功能：cino-deque在队头插入元素。
- 参数：

| 参数   | 说明        |
| ----- | -------------- |
| deque | cino-deque |
| data  | 新元素         |

- 返回值：修改后的cino-deque。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### deque_pop_front()

- 函数原型：

```c
T deque_pop_front(deque_t *deque);
```

- 功能：cino-deque删除队头元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：被删除的元素，如果队列为空返回`NULL`。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### deque_get_front()

- 函数原型：

```c
T deque_get_front(deque_t *deque);
```

- 功能：cino-deque获取队头元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：返回队头元素，如果队列为空返回`NULL`。

> 对于基本数据类型cino-deque，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

---

#### deque_push_back()

- 函数原型：

```c
deque_t *deque_push_back(deque_t *deque, T data)
```

- 功能：cino-deque在队尾插入元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |
| data  | 新元素     |

- 返回值：修改后的cino-deque。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### deque_pop_back()

- 函数原型：

```c
T deque_pop_back(deque_t *deque);
```

- 功能：cino-deque删除队尾元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：被删除的元素，如果队列为空返回`NULL`。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### deque_get_back()

- 函数原型：

```c
T deque_get_back(deque_t *deque);
```

- 功能：cino-deque获取队尾元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| deque | cino-deque |

- 返回值：返回队尾元素，如果队列为空返回`NULL`。

> 对于基本数据类型cino-deque，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。
