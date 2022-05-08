## cino_tree

- 模块功能：
    - tree_t：提供泛型树操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### tree_t

#### tree_create()

- 函数原型：

```c
tree_t *tree_create(const str_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-tree。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-tree的元素类型，支持"int"、“double”、"char"、“T”（泛型） |
| compare   | 用于比较的回调函数，仅针对T（泛型）cino-tree，基本数据类型cino-tree设置为`NULL`即可 |
| destroy   | 用于销毁的回调函数，仅针对T（泛型）cino-tree，基本数据类型cino-tree设置为`NULL`即可 |

- 返回值：返回cino-tree指针，创建失败返回`NULL`。

---

#### tree_destroy()

- 函数原型：

```c
void tree_destroy(tree_t *tree);
```

- 功能：销毁cino-tree。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

---

#### tree_is_empty()

- 函数原型：

```c
bool tree_is_empty(const tree_t *tree);
```

- 功能：判断cino-tree是否为空。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

- 返回值：cino-tree为空返回`true`，非空返回`false`。

---

#### tree_size()

- 函数原型：

```c
size_t tree_size(const tree_t *tree);
```

- 功能：获取cino-tree元素个数。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

- 返回值：cino-tree元素个数。

---

#### tree_clear()

- 函数原型：

```c
tree_t *tree_clear(tree_t *tree);
```

- 功能：清空cino-tree。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

- 返回值：修改后的cino-tree。

---

#### tree_pre_order()

- 函数原型：

```c
void tree_pre_order(tree_t *tree, visit_t visit);
```

- 功能：先序遍历cino-tree。
- 参数：

| 参数  | 说明                       |
| ----- | -------------------------- |
| tree  | cino-tree                  |
| visit | 用于访问单个元素的回调函数 |

---

#### tree_in_order()

- 函数原型：

```c
void tree_in_order(tree_t *tree, visit_t visit);
```

- 功能：中序遍历cino-tree。
- 参数：

| 参数  | 说明                       |
| ----- | -------------------------- |
| tree  | cino-tree                  |
| visit | 用于访问单个元素的回调函数 |

---

#### tree_post_order()

- 函数原型：

```c
void tree_post_order(tree_t *tree, visit_t visit);
```

- 功能：后序遍历cino-tree。
- 参数：

| 参数  | 说明                       |
| ----- | -------------------------- |
| tree  | cino-tree                  |
| visit | 用于访问单个元素的回调函数 |

---

#### tree_min()

- 函数原型：

```c
T tree_min(const tree_t *tree);
```

- 功能：获取cino-tree最小值。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

- 返回值：cino-tree最小值。

> 对于基本数据类型cino-tree，此函数会返回最小值的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

---

#### tree_max()

- 函数原型：

```c
T tree_max(const tree_t *tree);
```

- 功能：获取cino-tree最大值。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |

- 返回值：cino-tree最大值。

> 对于基本数据类型cino-tree，此函数会返回最大值的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。

---

#### tree_contains()

- 函数原型：

```c
bool tree_contains(tree_t *tree, T data);
```

- 功能：判断cino-tree是否存在指定数据。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |
| data | 查询元素  |

- 返回值：元素存在返回`true`，不存在返回`false`。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### tree_insert()

- 函数原型：

```c
tree_t *tree_insert(tree_t *tree, T data);
```

- 功能：cino-tree在指定下标插入元素。
- 参数：

| 参数  | 说明      |
| ----- | --------- |
| tree  | cino-tree |
| data  | 新元素    |

- 返回值：修改后的cino-tree。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### tree_remove()

- 函数原型：

```c
tree_t *tree_remove(tree_t *tree, T data);
```

- 功能：删除cino-tree中指定元素。
- 参数：

| 参数 | 说明      |
| ---- | --------- |
| tree | cino-tree |
| data | 删除元素  |

- 返回值：修改后的cino-tree。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### tree_set()

- 函数原型：

```c
void tree_set(tree_t *tree, T old_data, T new_data);
```

- 功能：替换cino-tree中指定元素。
- 参数：

| 参数     | 说明      |
| -------- | --------- |
| tree     | cino-tree |
| old_data | 旧元素    |
| new_data | 新元素    |

- 返回值：修改后的cino-tree。

> 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。
