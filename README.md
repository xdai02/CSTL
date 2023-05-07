# COOP

**COOP** is a library that provides object-oriented features in C, similar to those used in other languages such as C++, Java, or Python. It simplifies the process of working with complex data structures and algorithms in C.



# utils

- [x] **types**: Typedefs and macros for basic and derived data types.
- [x] **exception**: Basic exception handling mechanism for checking validality.

```c
return_if(expr);
return_if_fail(expr);
return_value_if(expr, ret);
return_value_if_fail(expr, ret);
exit_if(expr);
exit_if_fail(expr);
```

- [x] **numeric**: Utility functions for numeric data.

```c
min(x, y);
max(x, y);
swap(x, y, type);
bool float_equal(float f1, float f2);
bool double_equal(double d1, double d2);
```

- [x] **random**: Random number generator.

```c
int randint(int min, int max);
double uniform(double min, double max);
shuffle(array, n, type);
```

- [x] **c_str**:  Utility functions for primitive C strings.

```c
char *str_clear(char *str);
bool str_equal(const char *s1, const char *s2);
bool str_equal_ignore_case(const char *s1, const char *s2);
char *str_tolower(char *str);
char *str_toupper(char *str);
bool str_starts_with(const char *str, const char *prefix);
bool str_ends_with(const char *str, const char *suffix);
int str_index_of_char(const char *str, char c);
int str_index_of_string(const char *str, const char *substr);
bool str_contains_string(const char *str, const char *substr);
char *str_reverse(char *str);
char *str_strip(char *str);
char *str_substring(const char *str, size_t start, size_t end);
size_t str_count_substring(const char *str, const char *substr);
char *str_append_char(char *str, char c);
char *str_insert_char(char *str, size_t index, char c);
char *str_insert_string(char *str, size_t index, const char *substr);
char *str_remove_char(char *str, char c);
char *str_remove_string(char *str, const char *substr);
char *str_replace_char(char *str, char old_char, char new_char);
char *str_replace_string(char *str, const char *old_str, const char *new_str);
char **str_split(const char *str, const char *delimiter);
```

- [x] **wrapper**: A collection of wrapper types for primitive data types.

```c
typedef struct Character Character;
Character *Character_new(char value);
void Character_delete(void *ptr);
char Character_get(const Character *character);
void Character_set(Character *character, char value);
bool Character_equals(const Character *character1, const Character *character2);
int Character_compare(const void *ptr1, const void *ptr2);

typedef struct UnsignedCharacter UnsignedCharacter;
UnsignedCharacter *UnsignedCharacter_new(unsigned char value);
void UnsignedCharacter_delete(void *ptr);
unsigned char UnsignedCharacter_get(const UnsignedCharacter *uc);
void UnsignedCharacter_set(UnsignedCharacter *uc, unsigned char value);
bool UnsignedCharacter_equals(const UnsignedCharacter *uc1, const UnsignedCharacter *uc2);
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2);

typedef struct Short Short;
Short *Short_new(short value);
void Short_delete(void *ptr);
short Short_get(const Short *s);
void Short_set(Short *s, short value);
bool Short_equals(const Short *s1, const Short *s2);
int Short_compare(const void *ptr1, const void *ptr2);

typedef struct UnsignedShort UnsignedShort;
UnsignedShort *UnsignedShort_new(unsigned short value);
void UnsignedShort_delete(void *ptr);
unsigned short UnsignedShort_get(const UnsignedShort *us);
void UnsignedShort_set(UnsignedShort *us, unsigned short value);
bool UnsignedShort_equals(const UnsignedShort *us1, const UnsignedShort *us2);
int UnsignedShort_compare(const void *ptr1, const void *ptr2);

typedef struct Integer Integer;
Integer *Integer_new(int value);
void Integer_delete(void *ptr);
int Integer_get(const Integer *integer);
void Integer_set(Integer *integer, int value);
bool Integer_equals(const Integer *integer1, const Integer *integer2);
int Integer_compare(const void *ptr1, const void *ptr2);

typedef struct UnsignedInteger UnsignedInteger;
UnsignedInteger *UnsignedInteger_new(unsigned int value);
void UnsignedInteger_delete(void *ptr);
unsigned int UnsignedInteger_get(const UnsignedInteger *ui);
void UnsignedInteger_set(UnsignedInteger *ui, unsigned int value);
bool UnsignedInteger_equals(const UnsignedInteger *ui1, const UnsignedInteger *ui2);
int UnsignedInteger_compare(const void *ptr1, const void *ptr2);

typedef struct Long Long;
Long *Long_new(long value);
void Long_delete(void *ptr);
long Long_get(const Long *l);
void Long_set(Long *l, long value);
bool Long_equals(const Long *long1, const Long *long2);
int Long_compare(const void *ptr1, const void *ptr2);

typedef struct UnsignedLong UnsignedLong;
UnsignedLong *UnsignedLong_new(unsigned long value);
void UnsignedLong_delete(void *ptr);
unsigned long UnsignedLong_get(const UnsignedLong *ul);
void UnsignedLong_set(UnsignedLong *ul, unsigned long value);
bool UnsignedLong_equals(const UnsignedLong *ul1, const UnsignedLong *ul2);
int UnsignedLong_compare(const void *ptr1, const void *ptr2);

typedef struct Float Float;
Float *Float_new(float value);
void Float_delete(void *ptr);
float Float_get(const Float *f);
void Float_set(Float *f, float value);
bool Float_equals(const Float *float1, const Float *float2);
int Float_compare(const void *ptr1, const void *ptr2);

typedef struct Double Double;
Double *Double_new(double value);
void Double_delete(void *ptr);
double Double_get(const Double *d);
void Double_set(Double *d, double value);
bool Double_equals(const Double *double1, const Double *double2);
int Double_compare(const void *ptr1, const void *ptr2);

typedef struct Boolean Boolean;
Boolean *Boolean_new(bool value);
void Boolean_delete(void *ptr);
bool Boolean_get(const Boolean *boolean);
void Boolean_set(Boolean *boolean, bool value);
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2);
int Boolean_compare(const void *ptr1, const void *ptr2);
```

- [x] **generic**: Callback function interfaces for generic programming.

```c
#define T void*
typedef int (*compare_t)(const T data1, const T data2);
typedef void (*destroy_t)(T data);
typedef void (*visit_t)(T data);
```



# cstl

- [x] **iterator**: `iterator_t` for traversing data structures.
- [x] **str**: Dynamic `string_t ` with automatic memory management.

```c
typedef struct string_t string_t;

string_t *string_create(const char *str);
void string_destroy(string_t *string);
string_t *string_clone(const string_t *string);
size_t string_length(const string_t *string);
bool string_is_empty(const string_t *string);
const char *string_get(const string_t *string);
char string_char_at(const string_t *string, size_t index);
string_t *string_set_char_at(string_t *string, size_t index, char c);
string_t *string_clear(string_t *string);
bool string_equal(const string_t *string1, const string_t *string2);
bool string_equal_ignore_case(const string_t *string1, const string_t *string2);
string_t *string_tolower(string_t *string);
string_t *string_toupper(string_t *string);
bool string_starts_with(const string_t *string, const char *prefix);
bool string_ends_with(const string_t *string, const char *suffix);
int string_index_of_char(const string_t *string, char c);
int string_index_of_string(const string_t *string, const char *str);
bool string_contains_string(const string_t *string, const char *str);
string_t *string_reverse(string_t *string);
string_t *string_strip(string_t *string);
char *string_substring(const string_t *string, int start, int end);
size_t string_count_substring(const string_t *string, const char *substr);
string_t *string_append_char(string_t *string, char c);
string_t *string_insert_char(string_t *string, size_t index, char c);
string_t *string_concat(string_t *string, const char *str);
string_t *string_insert_string(string_t *string, size_t index, const char *str);
string_t *string_remove_char(string_t *string, char c);
string_t *string_remove_string(string_t *string, const char *str);
string_t *string_replace_char(string_t *string, char old_char, char new_char);
string_t *string_replace_string(string_t *string, const char *old_str, const char *new_str);
char **string_split(const string_t *string, const char *delimiter);
```

- [x] **array**: Generic `array_t` with automatic memory management.

```c
typedef struct array_t array_t;

array_t *array_create(compare_t compare, destroy_t destroy);
void array_destroy(array_t *array);
bool array_is_empty(const array_t *array);
size_t array_size(const array_t *array);
void array_foreach(array_t *array, visit_t visit);
array_t *array_clear(array_t *array);
T array_get(const array_t *array, size_t index);
array_t *array_set(array_t *array, size_t index, T elem);
array_t *array_append(array_t *array, T elem);
array_t *array_insert(array_t *array, size_t index, T elem);
T array_remove(array_t *array, size_t index);
size_t array_index_of(const array_t *array, T elem);
bool array_contains(const array_t *array, T elem);
size_t array_count(const array_t *array, T elem);
array_t *array_reverse(array_t *array);
array_t *array_sort(array_t *array);
iterator_t *array_iterator_create(const array_t *array);
void array_iterator_destroy(iterator_t *iterator);
bool array_iterator_has_next(const iterator_t *iterator);
T array_iterator_next(iterator_t *iterator);
```

- [x] **list**: Generic doubly linked list `list_t`.

```c
typedef struct list_t list_t;

list_t *list_create(compare_t compare, destroy_t destroy);
void list_destroy(list_t *list);
bool list_is_empty(const list_t *list);
size_t list_size(const list_t *list);
void list_foreach(list_t *list, visit_t visit);
list_t *list_clear(list_t *list);
T list_get(const list_t *list, size_t index);
list_t *list_set(list_t *list, size_t index, T elem);
int list_index_of(const list_t *list, T elem);
bool list_contains(const list_t *list, T elem);
size_t list_count(const list_t *list, T elem);
T list_get_front(const list_t *list);
T list_get_back(const list_t *list);
list_t *list_push_front(list_t *list, T elem);
list_t *list_push_back(list_t *list, T elem);
T list_pop_front(list_t *list);
T list_pop_back(list_t *list);
list_t *list_insert(list_t *list, size_t index, T elem);
T list_remove(list_t *list, size_t index);
list_t *list_reverse(list_t *list);
iterator_t *list_iterator_create(const list_t *list);
void list_iterator_destroy(iterator_t *iterator);
bool list_iterator_has_next(const iterator_t *iterator);
T list_iterator_next(iterator_t *iterator);
```

- [x] **stack**: Generic array based LIFO `stack_t`.

```c
typedef struct stack_t stack_t;

stack_t *stack_create(destroy_t destroy);
void stack_destroy(stack_t *stack);
bool stack_is_empty(const stack_t *stack);
size_t stack_size(const stack_t *stack);
stack_t *stack_clear(stack_t *stack);
stack_t *stack_push(stack_t *stack, T elem);
T stack_pop(stack_t *stack);
T stack_peek(const stack_t *stack);
```

- [x] **queue**: Generic doubly linked list based FIFO `queue_t`.

```c
typedef struct queue_t queue_t;

queue_t *queue_create(destroy_t destroy);
void queue_destroy(queue_t *queue);
bool queue_is_empty(const queue_t *queue);
size_t queue_size(const queue_t *queue);
queue_t *queue_clear(queue_t *queue);
queue_t *queue_enqueue(queue_t *queue, T elem);
T queue_dequeue(queue_t *queue);
T queue_peek(const queue_t *queue);
```

- [x] **deque**: Generic doubly linked list based `deque_t`.

```c
typedef struct deque_t deque_t;

deque_t *deque_create(destroy_t destroy);
void deque_destroy(deque_t *deque);
bool deque_is_empty(const deque_t *deque);
size_t deque_size(const deque_t *deque);
deque_t *deque_clear(deque_t *deque);
deque_t *deque_push_front(deque_t *deque, T elem);
deque_t *deque_push_back(deque_t *deque, T elem);
T deque_pop_front(deque_t *deque);
T deque_pop_back(deque_t *deque);
T deque_get_front(const deque_t *deque);
T deque_get_back(const deque_t *deque);
```

- [x] **red black tree**: Generic `red_black_tree_t`.

```c
typedef struct red_black_tree_t red_black_tree_t;

red_black_tree_t *red_black_tree_create(compare_t compare, destroy_t destroy);
void red_black_tree_destroy(red_black_tree_t *tree);
bool red_black_tree_is_empty(const red_black_tree_t *tree);
size_t red_black_tree_size(const red_black_tree_t *tree);
red_black_tree_t *red_black_tree_clear(red_black_tree_t *tree);
bool red_black_tree_contains(const red_black_tree_t *tree, T key);
void red_black_tree_foreach(red_black_tree_t *tree, visit_t visit);
red_black_tree_t *red_black_tree_insert(red_black_tree_t *tree, T key);
red_black_tree_t *red_black_tree_remove(red_black_tree_t *tree, T key);
iterator_t *red_black_tree_iterator_create(const red_black_tree_t *tree);
void red_black_tree_iterator_destroy(iterator_t *iterator);
bool red_black_tree_iterator_has_next(const iterator_t *iterator);
T red_black_tree_iterator_next(iterator_t *iterator);
```

- [x] **ordered_set**: Generic red black tree based `ordered_set_t`.

```c
typedef struct ordered_set_t ordered_set_t;

ordered_set_t *ordered_set_create(compare_t compare, destroy_t destroy);
void ordered_set_destroy(ordered_set_t *set);
bool ordered_set_is_empty(const ordered_set_t *set);
size_t ordered_set_size(const ordered_set_t *set);
void ordered_set_foreach(ordered_set_t *set, visit_t visit);
ordered_set_t *ordered_set_clear(ordered_set_t *set);
bool ordered_set_contains(const ordered_set_t *set, T elem);
ordered_set_t *ordered_set_add(ordered_set_t *set, T elem);
ordered_set_t *ordered_set_remove(ordered_set_t *set, T elem);
ordered_set_t *ordered_set_union(const ordered_set_t *set1, const ordered_set_t *set2);
ordered_set_t *ordered_set_intersection(const ordered_set_t *set1, const ordered_set_t *set2);
ordered_set_t *ordered_set_difference(const ordered_set_t *set1, const ordered_set_t *set2);
ordered_set_t *ordered_set_symmetric_difference(const ordered_set_t *set1, const ordered_set_t *set2);
bool ordered_set_is_disjoint(const ordered_set_t *set1, const ordered_set_t *set2);
bool ordered_set_is_subset(const ordered_set_t *set1, const ordered_set_t *set2);
iterator_t *ordered_set_iterator_create(const ordered_set_t *set);
void ordered_set_iterator_destroy(iterator_t *iterator);
bool ordered_set_iterator_has_next(const iterator_t *iterator);
T ordered_set_iterator_next(iterator_t *iterator);
```

- [ ] **unordered_set**: Generic hash table based `unordered_set_t`.

```c
typedef struct unordered_set_t unordered_set_t;

// TODO
```

- [ ] **ordered_map**: Generic red black tree based `ordered_map_t` for key-value pairs.

```c
typedef struct ordered_map_t ordered_map_t;

// TODO
```

- [ ] **unordered_map**: Generic hash table based `unordered_map_t` for key-value pairs.

```c
typedef struct unordered_map_t unordered_map_t;

// TODO
```



# Usage

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
./bin/demo_[module_name]
```

- Clean intermediate files

```shell
make clean_all
```

