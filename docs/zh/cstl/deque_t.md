# deque_t

[TOC]



## deque_new()

- 原型

```c
deque_t *deque_new(destroy_t destroy);
```

- 描述
    - 创建`deque_t`对象。
- 参数
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`deque_t`，否则返回`NULL`。
- 用例

```c
// Create an integer deque using Integer wrapper
deque_t *deque1 = deque_new(Integer_delete);

// Create a double deque using Double wrapper
deque_t *deque2 = deque_new(Double_delete);

// Create a boolean deque using Boolean wrapper
deque_t *deque3 = deque_new(Boolean_delete);

// Create a character deque using Character wrapper
deque_t *deque4 = deque_new(Character_delete);
```



## deque_delete()

- 原型

```c
void deque_delete(deque_t *deque);
```

- 描述
    - 销毁`deque_t`对象。
- 参数
    - `deque`：`deque_t`对象。
- 用例

```c
deque_t *deque = deque_new(Integer_delete);
deque_delete(deque);
```



## deque_is_empty()

- 原型

```c
bool deque_is_empty(const deque_t *deque);
```

- 描述
    - 判断`deque_t`对象是否为空。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 如果`deque_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
deque_t *deque = deque_new(Integer_delete);
if (deque_is_empty(deque)) {
    // ...
}
deque_delete(deque);
```



## deque_size()

- 原型

```c
size_t deque_size(const deque_t *deque);
```

- 描述
    - 获取`deque_t`对象的大小。
- 参数
    - `queue`：`deque_t`对象。
- 返回值
    - 返回`deque_t`对象的大小。
- 用例

```c
queue_t *queue = queue_new(Integer_delete);
printf("%d\n", queue_size(queue));
queue_delete(queue);
```



## queue_clear()

- 原型

```c
deque_t *deque_clear(deque_t *deque);
```

- 描述
    - 清空`deque_t`对象。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 返回修改后的`deque_t`对象。
- 用例

```c
deque_t *deque = deque_new(Integer_delete);

for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}

deque_clear(deque);
deque_delete(deque);
```



## deque_push_front()

- 原型

```c
deque_t *deque_push_front(deque_t *deque, T elem);
```

- 描述
    - 在队首插入元素。
- 参数
    - `deque`：`deque_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`deque_t`对象。
- 用例

```c
deque_t *deque = deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_front(deque, Integer_new(i));
}
deque_delete(deque);
```



## deque_push_back()

- 原型

```c
deque_t *deque_push_back(deque_t *deque, T elem);
```

- 描述
    - 在队尾插入元素。
- 参数
    - `deque`：`deque_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`deque_t`对象。
- 用例

```c
deque_t *deque = deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
deque_delete(deque);
```



## deque_pop_front()

- 原型

```c
T deque_pop_front(deque_t *deque);
```

- 描述
    - 移除队头元素。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 返回队头元素。
- 注意
    - 调用者**必须**释放返回元素（如适用）。
- 用例

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}

Integer *value = deque_pop_front(deque);
printf("%d\n", Integer_get(value));
Integer_delete(value);

deque_delete(deque);
```



## deque_pop_back()

- 原型

```c
T deque_pop_back(deque_t *deque);
```

- 描述
    - 移除队尾元素。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 返回队尾元素。
- 注意
    - 调用者**必须**释放返回元素（如适用）。
- 用例

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}

Integer *value = deque_pop_back(deque);
printf("%d\n", Integer_get(value));
Integer_delete(value);

deque_delete(deque);
```



## deque_get_front()

- 原型

```c
T deque_get_front(const deque_t *deque);
```

- 描述
    - 获取队头元素。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 返回队头元素。
- 用例

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
printf("%d\n", Integer_get(deque_get_front(deque)));
deque_delete(deque);
```



## deque_get_back()

- 原型

```c
T deque_get_back(deque_t *deque);
```

- 描述
    - 获取队尾元素。
- 参数
    - `deque`：`deque_t`对象。
- 返回值
    - 返回队尾元素。
- 用例

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
printf("%d\n", Integer_get(deque_get_back(deque)));
deque_delete(deque);
```

