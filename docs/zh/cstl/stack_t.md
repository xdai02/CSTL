# stack_t

[TOC]



## stack_new()

- 原型

```c
stack_t *stack_new(destroy_t destroy);
```

- 描述
    - 创建`stack_t`对象。
- 参数
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`stack_t`，否则返回`NULL`。
- 用例

```c
// Create an integer stack using Integer wrapper
stack_t *stack1 = stack_new(Integer_delete);

// Create a double stack using Double wrapper
stack_t *stack2 = stack_new(Double_delete);

// Create a boolean stack using Boolean wrapper
stack_t *stack3 = stack_new(Boolean_delete);

// Create a character stack using Character wrapper
stack_t *stack4 = stack_new(Character_delete);
```



## stack_delete()

- 原型

```c
void stack_delete(stack_t *stack);
```

- 描述
    - 销毁`stack_t`对象。
- 参数
    - `stack`：`stack_t`对象。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);
stack_delete(stack);
```



## stack_is_empty()

- 原型

```c
bool stack_is_empty(const stack_t *stack);
```

- 描述
    - 判断`stack_t`对象是否为空。
- 参数
    - `stack`：`stack_t`对象。
- 返回值
    - 如果`stack_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);
if (stack_is_empty(stack)) {
    // ...
}
stack_delete(stack);
```



## stack_size()

- 原型

```c
size_t stack_size(const stack_t *stack);
```

- 描述
    - 获取`stack_t`对象的大小。
- 参数
    - `stack`：`stack_t`对象。
- 返回值
    - 返回`stack_t`对象的大小。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);
printf("%d\n", stack_size(stack));
stack_delete(stack);
```



## stack_clear()

- 原型

```c
stack_t *stack_clear(stack_t *stack);
```

- 描述
    - 清空`stack_t`对象。
- 参数
    - `stack`：`stack_t`对象。
- 返回值
    - 返回修改后的`stack_t`对象。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);

for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}

stack_clear(stack);
stack_delete(stack);
```



## stack_push()

- 原型

```c
stack_t *stack_push(stack_t *stack, T elem);
```

- 描述
    - 入栈。
- 参数
    - `stack`：`stack_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`stack_t`对象。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
stack_delete(stack);
```



## stack_pop()

- 原型

```c
T stack_pop(stack_t *stack);
```

- 描述
    - 出栈。
- 参数
    - `stack`：`stack_t`对象。
- 返回值
    - 返回出栈元素。
- 注意
    - 调用者**必须**释放返回元素（如适用）。

- 用例

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}

Integer *value = stack_pop(stack);
printf("%d\n", Integer_get(value));
Integer_delete(value);

stack_delete(stack);
```



## stack_peek()

- 原型

```c
T stack_peek(const stack_t *stack);
```

- 描述
    - 获取栈顶元素。
- 参数
    - `stack`：`stack_t`对象。
- 返回值
    - 返回栈顶元素。
- 用例

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
printf("%d\n", Integer_get(stack_peek(stack)));
stack_delete(stack);
```

