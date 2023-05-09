# deque_t

[TOC]



## deque_new()

- Prototype

```c
deque_t *deque_new(destroy_t destroy);
```

- Description
    - Create a `deque_t` object.
- Parameters
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `deque_t` object if successful, otherwise return `NULL`.
- Usage

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

- Prototype

```c
void deque_delete(deque_t *deque);
```

- Description
    - Destroy a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Usage

```c
deque_t *deque = deque_new(Integer_delete);
deque_delete(deque);
```



## deque_is_empty()

- Prototype

```c
bool deque_is_empty(const deque_t *deque);
```

- Description
    - Determine whether a `deque_t` object is empty.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns `true` if the `deque_t` object is empty, otherwise returns `false`.
- Usage

```c
deque_t *deque = deque_new(Integer_delete);
if (deque_is_empty(deque)) {
    // ...
}
deque_delete(deque);
```



## deque_size()

- Prototype

```c
size_t deque_size(const deque_t *deque);
```

- Description
    - Get the size of a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the size of the `queue_t` object.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
printf("%d\n", queue_size(queue));
queue_delete(queue);
```



## queue_clear()

- Prototype

```c
deque_t *deque_clear(deque_t *deque);
```

- Description
    - Clear a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns the modified `deque_t` object.
- Usage

```c
deque_t *deque = deque_new(Integer_delete);

for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}

deque_clear(deque);
deque_delete(deque);
```



## deque_push_front()

- Prototype

```c
deque_t *deque_push_front(deque_t *deque, T elem);
```

- Description
    - Push an element to the front of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `deque_t` object.
- Usage

```c
deque_t *deque = deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_front(deque, Integer_new(i));
}
deque_delete(deque);
```



## deque_push_back()

- Prototype

```c
deque_t *deque_push_back(deque_t *deque, T elem);
```

- Description
    - Push an element to the back of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `deque_t` object.
- Usage

```c
deque_t *deque = deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
deque_delete(deque);
```



## deque_pop_front()

- Prototype

```c
T deque_pop_front(deque_t *deque);
```

- Description
    - Pop an element from the front of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns the front element.
- Usage

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
deque_pop_front(deque);
deque_delete(deque);
```



## deque_pop_back()

- Prototype

```c
T deque_pop_back(deque_t *deque);
```

- Description
    - Pop an element from the back of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns the back element.
- Usage

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
deque_pop_back(deque);
deque_delete(deque);
```



## deque_get_front()

- Prototype

```c
T deque_get_front(const deque_t *deque);
```

- Description
    - Get the front element of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns the front element.
- Usage

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
printf("%d\n", Integer_get(deque_get_front(deque)));
deque_delete(deque);
```



## deque_get_back()

- Prototype

```c
T deque_get_back(deque_t *deque);
```

- Description
    - Get the front element of a `deque_t` object.
- Parameters
    - `deque`: The `deque_t` object.
- Return
    - Returns the back element.
- Usage

```c
deque_t *deque= deque_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    deque_push_back(deque, Integer_new(i));
}
printf("%d\n", Integer_get(deque_get_back(deque)));
deque_delete(deque);
```

