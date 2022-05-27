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
list_t *list_create(data_type_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-list。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-list的元素类型，支持DATA_TYPE_INT、DATA_TYPE_DOUBLE、DATA_TYPE_CHAR、DATA_TYPE_T（泛型） |
| compare   | 用于比较的回调函数，<br />DATA_TYPE_INT类型使用compare_int，<br />DATA_TYPE_DOUBLE类型使用compare_double，<br />DATA_TYPE_CHAR类型使用compare_char，<br />DATA_TYPE_T类型可使用自定义compare_t函数接口，使用`NULL`为默认方式 |
| destroy   | 用于销毁的回调函数，<br />DATA_TYPE_INT类型使用destroy_int，<br />DATA_TYPE_DOUBLE类型使用destroy_double，<br />DATA_TYPE_CHAR类型使用destroy_char，<br />DATA_TYPE_T类型可使用自定义destroy_t函数接口，使用`NULL`为默认方式 |

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

---

#### list_foreach()

- 函数原型：

```c
void list_foreach(list_t *list, visit_t visit, bool backward);
```

- 功能：遍历cino-list。
- 参数：

| 参数      | 说明                       |
| --------- | -------------------------- |
| list      | cino-list                  |
| visit     | 用于访问单个元素的回调函数 |
| backwards | 反向遍历                   |

- 返回值：修改后的cino-list。

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

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

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

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

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

> 对于基本数据类型cino-list，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

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

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

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
| context | 对于基本数据类型cino-list，传入待查询元素的包装类型，此函数会释放该包装类型<br />对于T（泛型）cino-list，传入match_t类型的回调函数，用于匹配元素 |

- 返回值：cino-list指定元素首次出现下标，返回`-1`表示未找到。

---

#### list_push_front()

- 函数原型：

```c
list_t *list_push_front(list_t *list, T data);
```

- 功能：在cino-list头部插入元素。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |
| data | 新元素    |

- 返回值：修改后的cino-list。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### list_push_back()

- 函数原型：

```c
list_t *list_push_back(list_t *list, T data);
```

- 功能：在cino-list尾部插入元素。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |
| data | 新元素    |

- 返回值：修改后的cino-list。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### list_pop_front()

- 函数原型：

```c
T list_pop_front(list_t *list);
```

- 功能：删除cino-list头部元素。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

- 返回值：返回被删除的元素。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### list_pop_back()

- 函数原型：

```c
T list_pop_back(list_t *list);
```

- 功能：删除cino-list尾部元素。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| list | cino-list |

- 返回值：修改后的cino-list。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### list_insert()

- 函数原型：

```c
list_t *list_insert(list_t *list, int index, T data);
```

- 功能：cino-list在指定下标插入元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |
| index | 插入下标  |
| data  | 新元素    |

- 返回值：修改后的cino-list。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### list_remove()

- 函数原型：

```c
T list_remove(list_t *list, int index);
```

- 功能：删除cino-list中指定下标元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| list  | cino-list |
| index | 删除下标  |

- 返回值：被删除的元素。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。
