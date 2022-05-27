## cino_queue

- 模块功能：
    - queue_t：提供泛型队列操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### queue_t

#### queue_create()

- 函数原型：

```c
queue_t *queue_create(data_type_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-queue。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-queue的元素类型，支持DATA_TYPE_INT、DATA_TYPE_DOUBLE、DATA_TYPE_CHAR、DATA_TYPE_T（泛型） |
| compare   | 用于比较的回调函数，<br />DATA_TYPE_INT类型使用compare_int，<br />DATA_TYPE_DOUBLE类型使用compare_double，<br />DATA_TYPE_CHAR类型使用compare_char，<br />DATA_TYPE_T类型可使用自定义compare_t函数接口，使用`NULL`为默认方式 |
| destroy   | 用于销毁的回调函数，<br />DATA_TYPE_INT类型使用destroy_int，<br />DATA_TYPE_DOUBLE类型使用destroy_double，<br />DATA_TYPE_CHAR类型使用destroy_char，<br />DATA_TYPE_T类型可使用自定义destroy_t函数接口，使用`NULL`为默认方式 |

- 返回值：返回cino-queue指针，创建失败返回`NULL`。

---

#### queue_destroy()

- 函数原型：

```c
void queue_destroy(queue_t *queue);
```

- 功能：销毁cino-queue。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

---

#### queue_is_empty()

- 函数原型：

```c
bool queue_is_empty(const queue_t *queue);
```

- 功能：判断cino-queue是否为空。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

- 返回值：cino-queue为空返回`true`，非空返回`false`。

---

#### queue_size()

- 函数原型：

```c
size_t queue_size(const queue_t *queuearray);
```

- 功能：获取cino-queue元素个数。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

- 返回值：cino-queue元素个数。

---

#### queue_clear()

- 函数原型：

```c
queue_t *queue_clear(queue_t *queue);
```

- 功能：清空cino-queue。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

- 返回值：修改后的cino-queue。

---

#### queue_enqueue()

- 函数原型：

```c
queue_t *queue_enqueue(queue_t *queue, T data)
```

- 功能：cino-queue入队元素。
- 参数：

| 参数   | 说明        |
| ----- | -------------- |
| queue | cino-queue |
| data  | 新元素         |

- 返回值：修改后的cino-queue。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### queue_dequeue()

- 函数原型：

```c
T queue_dequeue(queue_t *queue);
```

- 功能：cino-queue出队元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

- 返回值：被删除的元素，如果队列为空返回`NULL`。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### queue_get_front()

- 函数原型：

```c
T queue_get_front(queue_t *queue);
```

- 功能：cino-queue获取队头元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| queue | cino-queue |

- 返回值：返回队头元素，如果队列为空返回`NULL`。

> 对于基本数据类型cino-queue，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。
