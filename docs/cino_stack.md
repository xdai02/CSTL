## cino_stack

- 模块功能：
    - stack_t：提供泛型栈操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### stack_t

#### stack_create()

- 函数原型：

```c
stack_t *stack_create(const str_t data_type, compare_t compare, destroy_t destroy);
```

- 功能：创建cino-stack。
- 参数：

| 参数      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| data_type | cino-stack的元素类型，支持"int"、“double”、"char"、“T”（泛型） |
| compare   | 用于比较的回调函数，仅针对T（泛型）cino-stack，基本数据类型cino-stack设置为`NULL`即可 |
| destroy   | 用于销毁的回调函数，仅针对T（泛型）cino-stack，基本数据类型cino-stack设置为`NULL`即可 |

- 返回值：返回cino-stack指针，创建失败返回`NULL`。

---

#### stack_destroy()

- 函数原型：

```c
void stack_destroy(stack_t *stack);
```

- 功能：销毁cino-stack。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

---

#### stack_is_empty()

- 函数原型：

```c
bool stack_is_empty(const stack_t *stack);
```

- 功能：判断cino-stack是否为空。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

- 返回值：cino-stack为空返回`true`，非空返回`false`。

---

#### stack_size()

- 函数原型：

```c
size_t stack_size(const stack_t *stackarray);
```

- 功能：获取cino-array元素个数。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

- 返回值：cino-stack元素个数。

---

#### stack_clear()

- 函数原型：

```c
stack_t *stack_clear(stack_t *stack);
```

- 功能：清空cino-stack。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

- 返回值：修改后的cino-stack。

---

#### stack_push()

- 函数原型：

```c
stack_t *stack_push(stack_t *stack, T data)
```

- 功能：cino-stack入栈元素。
- 参数：

| 参数   | 说明        |
| ----- | -------------- |
| stack | cino-stack |
| data  | 新元素         |

- 返回值：修改后的cino-stack。

> - 对于基本数据类型，调用者需要传入该基本数据类型的包装类型。

---

#### stack_pop()

- 函数原型：

```c
T stack_pop(stack_t *stack);
```

- 功能：cino-stack出栈元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

- 返回值：被删除的元素。

> 对于基本数据类型，此函数会返回该数据类型的包装类型，调用者需要拆箱/释放。

---

#### stack_peek()

- 函数原型：

```c
T stack_peek(stack_t *stack);
```

- 功能：cino-stack栈顶元素。

- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| stack | cino-stack |

- 返回值：被删除的元素。

> 对于基本数据类型cino-stack，此函数会返回该数据类型的包装类型，调用者应该使用`->data`访问基本元素，而不是拆箱。
