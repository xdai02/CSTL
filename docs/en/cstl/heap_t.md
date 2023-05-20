# heap_t

[TOC]



## heap_new()

- Prototype

```c
heap_t *heap_new(heap_type_t heap_type, compare_t compare, destroy_t destroy);
```

- Description
    - Create a `heap_t` object.
- Parameters
    - `heap_type`: The type of the heap (`MIN_HEAP`/`MAX_HEAP`).
    - `compare`: Callback function for comparing two data items.
    - `destroy`: Callback function for destroying a data item.
- Return
    - Returns the created `heap_t` object if successful, otherwise return `NULL`.
- Usage

```c
// Create a min heap
heap_t *min_heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);

// Create a max heap
heap_t *max_heap = heap_new(MAX_HEAP, Integer_compare, Integer_delete);
```



## heap_delete()

- Prototype

```c
void heap_delete(heap_t *heap);
```

- Description
    - Destroy a `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
heap_delete(heap);
```



## heap_is_empty()

- Prototype

```c
bool heap_is_empty(const heap_t *heap);
```

- Description
    - Determine whether a `heap_t` object is empty.
- Parameters
    - `heap`: The `heap_t` object.
- Return
    - Returns `true` if the `heap_t` object is empty, otherwise returns `false`.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
if (heap_is_empty(heap)) {
    // ...
}
heap_delete(heap);
```



## heap_size()

- Prototype

```c
size_t heap_size(const heap_t *heap);
```

- Description
    - Get the size of a `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
- Return
    - Returns the size of the `heap_t` object.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
printf("%d\n", heap_size(heap));
heap_delete(heap);
```



## heap_clear()

- Prototype

```c
heap_t *heap_clear(heap_t *heap);
```

- Description
    - Clear a `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
- Return
    - Returns the modified `heap_t` object.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}

heap_clear(heap);
heap_delete(heap);
```



## heap_push()

- Prototype

```c
heap_t *heap_push(heap_t *heap, T elem);
```

- Description
    - Push an element into a `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
    - `elem`: The element.
- Return
    - Returns the modified `heap_t` object.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}
heap_delete(heap);
```



## stack_pop()

- Prototype

```c
T heap_pop(heap_t *heap);
```

- Description
    - Pop an element from the `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
- Return
    - Returns the popped element.
- Note
    - Caller **MUST** free the returned element (if applicable).

- Usage

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

- Prototype

```c
T heap_peek(const heap_t *heap);
```

- Description
    - Get the root element of the `heap_t` object.
- Parameters
    - `heap`: The `heap_t` object.
- Return
    - Returns the root element.
- Usage

```c
heap_t *heap = heap_new(MIN_HEAP, Integer_compare, Integer_delete);
for (int i = 0; i < 10; i++) {
    heap_push(heap, Integer_new(i));
}

Integer *value = heap_peek(heap);
printf("%d\n", Integer_get(value));

heap_delete(heap);
```

