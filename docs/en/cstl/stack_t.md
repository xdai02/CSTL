# stack_t

[TOC]



## stack_create()

- Prototype

```c
stack_t *stack_create(destroy_t destroy);
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
stack_t *stack1 = stack_create(Integer_delete);

// Create a double stack using Double wrapper
stack_t *stack2 = stack_create(Double_delete);

// Create a boolean stack using Boolean wrapper
stack_t *stack3 = stack_create(Boolean_delete);

// Create a character stack using Character wrapper
stack_t *stack4 = stack_create(Character_delete);
```



## stack_destroy()

- Prototype

```c
void stack_destroy(stack_t *stack);
```

- Description
    - Destroy an `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Usage

```c
stack_t *stack = stack_create(Integer_delete);
stack_destroy(stack);
```



## stack_is_empty()

- Prototype

```c
bool stack_is_empty(const stack_t *stack);
```

- Description
    - Determine whether an `stack_t` object is empty.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns `true` if the `stack_t` object is empty, otherwise returns `false`.
- Usage

```c
stack_t *stack = stack_create(Integer_delete);
if (stack_is_empty(stack)) {
    // ...
}
stack_destroy(stack);
```



## stack_size()

- Prototype

```c
size_t stack_size(const stack_t *stack);
```

- Description
    - Get the size of an `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the size of the `stack_t` object.
- Usage

```c
stack_t *stack = stack_create(Integer_delete);
printf("%d\n", stack_size(stack));
stack_destroy(stack);
```



## stack_clear()

- Prototype

```c
stack_t *stack_clear(stack_t *stack);
```

- Description
    - Clear an `stack_t` object.
- Parameters
    - `stack`: The `stack_t` object.
- Return
    - Returns the modified `stack_t` object.
- Usage

```c
stack_t *stack = stack_create(Integer_delete);

for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}

stack_clear(stack);
stack_destroy(stack);
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
stack_t *stack = stack_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
stack_destroy(stack);
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
stack_t *stack = stack_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
stack_pop(stack);
stack_destroy(stack);
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
stack_t *stack = stack_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    stack_push(stack, Integer_new(i));
}
printf("%d\n", Integer_valueOf(stack_peek(stack)));
stack_destroy(stack);
```

