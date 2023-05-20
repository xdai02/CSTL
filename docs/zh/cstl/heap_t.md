# heap_t

[TOC]



## heap_new()

- 原型

```c
heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`heap_t`对象。
- 参数
    - `heap_type`：堆的类型（`MIN_HEAP`/`MAX_HEAP`）。
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`heap_t`，否则返回`NULL`。
- 用例

```c
// Create a min heap
heap_t *min_heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);

// Create a max heap
heap_t *max_heap = heap_new(MAX_HEAP, Integer_compare, Integer_delete);
```



## heap_delete()

- 原型

```c
void heap_delete(heap_t *heap);
```

- 描述
    - 销毁`heap_t`对象。
- 参数
    - `heap`：`heap_t`对象。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
heap_delete(heap);
```



## heap_is_empty()

- 原型

```c
bool heap_is_empty(const heap_t *heap);
```

- 描述
    - 判断`heap_t`对象是否为空。
- 参数
    - `heap`：`heap_t`对象。
- 返回值
    - 如果`heap_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
if (heap_is_empty(heap)) {
    // ...
}
heap_delete(heap);
```



## heap_size()

- 原型

```c
size_t heap_size(const heap_t *heap);
```

- 描述
    - 获取`heap_t`对象的大小。
- 参数
    - `heap`：`heap_t`对象。
- 返回值
    - 返回`heap_t`对象的大小。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
printf("%d\n", heap_size(heap));
heap_delete(heap);
```



## heap_clear()

- 原型

```c
heap_t *heap_clear(heap_t *heap);
```

- 描述
    - 清空`heap_t`对象。
- 参数
    - `heap`：`heap_t`对象。
- 返回值
    - 返回修改后的`heap_t`对象。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}

heap_clear(heap);
heap_delete(heap);
```



## heap_push()

- 原型

```c
heap_t *heap_push(heap_t *heap, T elem);
```

- 描述
    - 将一个元素添加到`heap_t`对象中。
- 参数
    - `heap`：`heap_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`heap_t`对象。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}
heap_delete(heap);
```



## stack_pop()

- 原型

```c
T heap_pop(heap_t *heap);
```

- 描述
    - 从`heap_t`对象中删除堆顶元素。
- 参数
    - `heap`：`heap_t`对象。
- 返回值
    - 返回移除元素。
- 注意
    - 调用者**必须**释放返回元素（如适用）。

- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}

Integer *value = heap_pop(heap);
printf("%d\n", Integer_get(value));
Integer_delete(value);

heap_delete(heap);
```



## heap_peek()

- 原型

```c
T heap_peek(const heap_t *heap);
```

- 描述
    - 获取`heap_t`对象的堆顶元素。
- 参数
    - `heap`：`heap_t`对象。
- 返回值
    - 返回堆顶元素。
- 用例

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}

Integer *value = heap_peek(heap);
printf("%d\n", Integer_get(value));

heap_delete(heap);
```

