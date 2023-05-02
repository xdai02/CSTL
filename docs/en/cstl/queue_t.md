# queue_t

[TOC]



## queue_create()

- Prototype

```c
queue_t *queue_create(destroy_t destroy);
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
queue_t *queue1 = queue_create(Integer_delete);

// Create a double queue using Double wrapper
queue_t *queue2 = queue_create(Double_delete);

// Create a boolean queue using Boolean wrapper
queue_t *queue3 = queue_create(Boolean_delete);

// Create a character queue using Character wrapper
queue_t *queue4 = queue_create(Character_delete);
```



## queue_destroy()

- Prototype

```c
void queue_destroy(queue_t *queue);
```

- Description
    - Destroy an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
queue_destroy(queue);
```



## queue_is_empty()

- Prototype

```c
bool queue_is_empty(const queue_t *queue);
```

- Description
    - Determine whether an `queue_t` object is empty.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns `true` if the `queue_t` object is empty, otherwise returns `false`.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
if (queue_is_empty(queue)) {
    // ...
}
queue_destroy(queue);
```



## queue_size()

- Prototype

```c
size_t queue_size(const queue_t *queue);
```

- Description
    - Get the size of an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the size of the `queue_t` object.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
printf("%d\n", queue_size(queue));
queue_destroy(queue);
```



## queue_clear()

- Prototype

```c
queue_t *queue_clear(queue_t *queue);
```

- Description
    - Clear an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the modified `queue_t` object.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);

for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}

queue_clear(queue);
queue_destroy(queue);
```



## queue_enqueue()

- Prototype

```c
queue_t *queue_enqueue(queue_t *queue, T elem);
```

- Description
    - Enqueue an element to an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `queue_t` object.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
queue_destroy(queue);
```



## queue_dequeue()

- Prototype

```c
T queue_dequeue(queue_t *queue);
```

- Description
    - Dequeue an element from an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the dequeued element.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
queue_dequeue(queue);
queue_destroy(queue);
```



## queue_peek()

- Prototype

```c
T queue_peek(const queue_t *queue);
```

- Description
    - Get the front element of an `queue_t` object.
- Parameters
    - `queue`: The `queue_t` object.
- Return
    - Returns the front element.
- Usage

```c
queue_t *queue = queue_create(Integer_delete);
for (int i = 0; i < 10; i++) {
    queue_enqueue(queue, Integer_new(i));
}
printf("%d\n", Integer_valueOf(queue_peek(queue)));
queue_destroy(queue);
```

