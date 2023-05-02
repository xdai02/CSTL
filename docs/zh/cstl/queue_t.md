# queue_t

[TOC]



## queue_create()

- 原型

```c
queue_t *queue_create(destroy_t destroy);
```

- 描述
    - 创建`queue_t`对象。
- 参数
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`queue_t`，否则返回`NULL`。
- 用例

```c
// Create an integer queue using Integer wrapper
queue_t *queue1 = queue_create(Integer_delete);

// Create a double queue using Double wrapper
queue_t *queue2 = queue_create(Double_delete);

// Create a boolean queue using Boolean wrapper
queue_t *queue3 = queue_create(Boolean_delete);

// Create a character queue using Character wrapper
queue_t *queue4 = queue_create(Character_delete);
```



## queue_destroy()

- 原型

```c
void queue_destroy(queue_t *queue);
```

- 描述
    - 销毁`queue_t`对象。
- 参数
    - `queue`：`queue_t`对象。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
queue_destroy(queue);
```



## queue_is_empty()

- 原型

```c
bool queue_is_empty(const queue_t *queue);
```

- 描述
    - 判断`queue_t`对象是否为空。
- 参数
    - `queue`：`queue_t`对象。
- 返回值
    - 如果`queue_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
if (queue_is_empty(queue)) {
    // ...
}
queue_destroy(queue);
```



## queue_size()

- 原型

```c
size_t queue_size(const queue_t *queue);
```

- 描述
    - 获取`queue_t`对象的大小。
- 参数
    - `queue`：`queue_t`对象。
- 返回值
    - 返回`queue_t`对象的大小。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
printf("%d\n", queue_size(queue));
queue_destroy(queue);
```



## queue_clear()

- 原型

```c
queue_t *queue_clear(queue_t *queue);
```

- 描述
    - 清空`queue_t`对象。
- 参数
    - `queue`：`queue_t`对象。
- 返回值
    - 返回修改后的`queue_t`对象。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);

for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}

queue_clear(queue);
queue_destroy(queue);
```



## queue_enqueue()

- 原型

```c
queue_t *queue_enqueue(queue_t *queue, T elem);
```

- 描述
    - 入队。
- 参数
    - `queue`：`queue_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`queue_t`对象。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
queue_destroy(queue);
```



## queue_dequeue()

- 原型

```c
T queue_dequeue(queue_t *queue);
```

- 描述
    - 出队。
- 参数
    - `queue`：`queue_t`对象。
- 返回值
    - 返回出队元素。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
queue_dequeue(queue);
queue_destroy(queue);
```



## queue_peek()

- 原型

```c
T queue_peek(const queue_t *queue);
```

- 描述
    - 获取队头元素。
- 参数
    - `queue`：`queue_t`对象。
- 返回值
    - 返回队头元素。
- 用例

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
printf("%d\n", Integer_valueOf(queue_peek(queue)));
queue_destroy(queue);
```


