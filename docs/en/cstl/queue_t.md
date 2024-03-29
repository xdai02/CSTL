# queue_t

[TOC]



## queue_new()

- Prototype

```c
queue_t *queue_new(destroy_t destroy);
```

- Description
    - Create a `queue_t` object.
- Parameters
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `queue_t` object if successful, otherwise return `NULL`.
- Usage

```c
// Create an integer queue using Integer wrapper
queue_t *queue1 = queue_new(Integer_delete);

// Create a double queue using Double wrapper
queue_t *queue2 = queue_new(Double_delete);

// Create a boolean queue using Boolean wrapper
queue_t *queue3 = queue_new(Boolean_delete);

// Create a character queue using Character wrapper
queue_t *queue4 = queue_new(Character_delete);
```



## queue_delete()

- Prototype

```c
void queue_delete(queue_t *queue);
```

- Description
    - Destroy a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
queue_delete(queue);
```



## queue_is_empty()

- Prototype

```c
bool queue_is_empty(const queue_t *queue);
```

- Description
    - Determine whether a `queue_t` object is empty.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns `true` if the `queue_t` object is empty, otherwise returns `false`.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
if (queue_is_empty(queue)) {
    // ...
}
queue_delete(queue);
```



## queue_size()

- Prototype

```c
size_t queue_size(const queue_t *queue);
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
queue_t *queue_clear(queue_t *queue);
```

- Description
    - Clear a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the modified `queue_t` object.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);

for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}

queue_clear(queue);
queue_delete(queue);
```



## queue_enqueue()

- Prototype

```c
queue_t *queue_enqueue(queue_t *queue, T elem);
```

- Description
    - Enqueue an element to a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `queue_t` object.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
queue_delete(queue);
```



## queue_dequeue()

- Prototype

```c
T queue_dequeue(queue_t *queue);
```

- Description
    - Dequeue an element from a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the dequeued element.
- Note
    - Caller **MUST** free the returned element (if applicable).
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}

Integer *value = queue_dequeue(queue);
printf("%d\n", Integer_get(value));
Integer_delete(value);

queue_delete(queue);
```



## queue_peek()

- Prototype

```c
T queue_peek(const queue_t *queue);
```

- Description
    - Get the front element of a `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the front element.
- Usage

```c
queue_t *queue = queue_new(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
printf("%d\n", Integer_get(queue_peek(queue)));
queue_delete(queue);
```

