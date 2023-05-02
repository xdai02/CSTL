# COOP

**COOP** is a library that provides object-oriented features in C, similar to those used in other languages such as C++, Java, or Python. It simplifies the process of working with complex data structures and algorithms in C.



## utils

- [x] **types**: Provides typedefs and macros for various basic and derived data types.
- [x] **exception**: Implements a basic exception handling mechanism to handle errors gracefully.
- [x] **numeric**: Contains utility functions for working with numeric data.
- [x] **random**: Offers a set of functions for generating random numbers.
- [x] **str**:  Provides a set of utility functions for working with primitive strings.
- [x] **wrapper**: Includes a collection of wrapper types for primitive data types.
- [x] **generic**: Contains macros and function interfaces for implementing generic programming concepts.



## cstl

- [x] **cstl_string**: Implements a dynamic string type `string_t` with automatic memory management.
- [x] **iterator**: Provides a common interface `iterator_t` for traversing various data structures.
- [x] **cstl_array**: Implements a dynamic array `array_t` type with automatic resizing and memory management.
- [x] **cstl_list**: Implements a doubly-linked list data structure `list_t` for efficient insertion and deletion operations.
- [ ] **cstl_stack**: Implements a stack data structure `stack_t`, which is a Last-In-First-Out (LIFO) collection of elements.
- [ ] **cstl_queue**: Implements a queue data structure `queue_t`, which is a First-In-First-Out (FIFO) collection of elements.
- [ ] **cstl_deque**: Implements a double-ended queue (deque) data structure `deque_t`, which allows elements to be added or removed from both ends efficiently.
- [ ] **cstl_set**: Implements a set data structure `set_t`, which is a collection of unique elements, without any specific order.
- [ ] **cstl_map**: Provides a map data structure `map_t`, which is a collection of key-value pairs.



## Usage

- Run test code

```shell
cmake ./
make
./bin/test_coop
```

- Run demo code

```shell
cd demo
cmake ./
make
./[module_name]
```

- Clean intermediate files

```shell
make clean_all
```

