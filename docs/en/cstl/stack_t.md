# stack_t

[TOC]



## stack_new()

- Prototype

```c
stack_t *stack_new(destroy_t destroy);
```

- Description
    - Create a `stack_t` object.
- Parameters
    - `destroy`: Callback function for destroying a data item.
- Return
    - Return the created `stack_t` object if successful, otherwise return `NULL`.
- Usage

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

- Prototype

```c
void stack_delete(stack_t *stack);
```

- Description
    - Destroy a `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
stack_delete(stack);
```



## stack_is_empty()

- Prototype

```c
bool stack_is_empty(const stack_t *stack);
```

- Description
    - Determine whether a `stack_t` object is empty.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns `true` if the `stack_t` object is empty, otherwise returns `false`.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
if (stack_is_empty(stack)) {
    // ...
}
stack_delete(stack);
```



## stack_size()

- Prototype

```c
size_t stack_size(const stack_t *stack);
```

- Description
    - Get the size of a `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the size of the `stack_t` object.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
printf("%d\n", stack_size(stack));
stack_delete(stack);
```



## stack_clear()

- Prototype

```c
stack_t *stack_clear(stack_t *stack);
```

- Description
    - Clear a `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the modified `stack_t` object.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);

for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}

stack_clear(stack);
stack_delete(stack);
```



## stack_push()

- Prototype

```c
stack_t *stack_push(stack_t *stack, T elem);
```

- Description
    - Push an element onto the `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `stack_t` object.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
stack_delete(stack);
```



## stack_pop()

- Prototype

```c
T stack_pop(stack_t *stack);
```

- Description
    - Pop an element from the `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the popped element.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
stack_pop(stack);
stack_delete(stack);
```



## stack_peek()

- Prototype

```c
T stack_peek(const stack_t *stack);
```

- Description
    - Get the top element of the `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the top element.
- Usage

```c
stack_t *stack = stack_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
printf("%d\n", Integer_get(stack_peek(stack)));
stack_delete(stack);
```

