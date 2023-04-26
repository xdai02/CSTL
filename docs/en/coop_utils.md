# coop_utils

[TOC]



## bool

```c
typedef int bool;
#define true 1
#define false 0
```

- Description
    - Boolean type for compatibility with standards before C99.



## T

```c
#define T void*
```

- Description
    - A generic data type representing a pointer to any data type. It is an alias for `void *`.
- Usage

```c
typedef struct array_t {
    T *data;
    size_t size;
    size_t capacity;
} array_t;

array_t *array_create() {
    array_t *array = (array_t *)malloc(sizeof(array_t));
    array->data = (T *)malloc(sizeof(T) * 16);
    array->size = 0;
    array->capacity = 16;
    return array;
}
```



## compare_t

```c
typedef int (*compare_t)(const T data1, const T data2);
```

- Description
    - A generic function pointer type for comparing two data items.
- Parameters
    - `data1`: The first data item to be compared.
    - `data2`: The second data item to be compared.
- Return
    - Returns a negative integer if `data1 < data2`.
    - Returns 0 if `data1 == data2`.
    - Returns a positive integer if `data1 > data2`.
- Usage

```c
typedef struct {
    char name[32];
    int age;
} Person;

int person_compare(const T data1, const T data2) {
    const Person *person1 = (Person *)data1;
    const Person *person2 = (Person *)data2;
    return person1->age - person2->age;
}
```



## destroy_t

```c
typedef void (*destroy_t)(T data);
```

- Description
    - A generic function pointer type for destroying a data item.
- Parameters
    - `data`: The data item to be destroyed.
- Usage

```c
typedef struct {
    char *str;
} MyString;

void mystring_destroy(T data) {
    MyString *mystring = (MyString *)data;
    free(mystring->str);
}
```



## visit_t

```c
typedef void (*visit_t)(T data);
```

- Description
    - A generic function pointer type for visiting a data item.
- Parameters
    - `data`: The data item to be visited.
- Usage

```c
typedef struct {
    char name[100];
    int id;
    float salary;
} Employee;

void employee_print(T data) {
    Employee *employee = (Employee *)data;
    printf("Employee Name: %s\n", employee->name);
    printf("Employee ID: %d\n", employee->id);
    printf("Employee Salary: %.2f\n", employee->salary);
}
```



## return_if_fail()

```c
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }
```

- Description
    - Returns from the current function immediately if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

```c
void array_print(int *arr, int n) {
    return_if_fail(n >= 0);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```



## return_value_if_fail()

```c
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }
```

- Description
    - Returns the specific value from the current function immediately if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
    - `ret`: The value to be returned.
- Usage

```c
char *str_clear(char *str) {
    return_value_if_fail(str != NULL, NULL);
    str[0] = '\0';
    return str;
}
```



## exit_if_fail()

```c
#define exit_if_fail(expr)  \
    if (!(expr)) {          \
        exit(EXIT_FAILURE); \
    }
```

- Description
    - Terminates the program immediately with the `EXIT_FAILURE` status if the given expression `expr` is `false`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

```c
float divide(int a, int b) {
    exit_if_fail(b != 0);
    return (float)a / (float)b;
}
```



## min()

```c
#define min(x, y) (((x) < (y)) ? (x) : (y))
```

- Description
    - Returns the minimum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the minimum of `x` and `y`.
- Usage

```c
printf("%d\n", min(5, 10));
```



## max()

```c
#define max(x, y) (((x) > (y)) ? (x) : (y))
```

- Description
    - Returns the maximum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the maximum of `x` and `y`.
- Usage

```c
printf("%d\n", max(5, 10));
```



## swap()

```c
#define swap(x, y, type) \
    do {                 \
        type temp = (x); \
        (x) = (y);       \
        (y) = temp;      \
    } while (0)
```

- Description
    - Swaps the values of two variables with the given type.
- Parameters
    - `x`: The first variable to be swapped.
    - `y`: The second variable to be swapped.
    - `type`: The type of the variables to be swapped.
- Usage

```c
int x = 3;
int y = 5;
printf("Before: x = %d, y = %d\n", x, y);
swap(x, y, int);
printf("After: x = %d, y = %d\n", x, y);
```



## float_equal()

- Prototype

```c
bool float_equal(float f1, float f2);
```

- Description
    - Compares two floating point numbers for equality within a certain tolerance.
- Parameters
    - `f1`: The first float number to be compared.
    - `f2`: The second float number to be compared.
- Return
    - Returns `true` if the absolute difference between `f1` and `f2` is less than `FLT_EPSILON`, `false` otherwise.
- Usage

```c
float x = 3.14f;
if (float_equal(x, 3.14f)) {
    // ...
}
```



## double_equal()

- Prototype

```c
bool double_equal(double d1, double d2);
```

- Description
    - Compares two double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - `d1`: The first double number to be compared.
    - `d2`: The second double number to be compared.
- Return
    - Returns `true` if the absolute difference between `d1` and `d2` is less than `DBL_EPSILON`, `false` otherwise.
- Usage

```c
double x = 3.14;
if (double_equal(x, 3.14)) {
    // ...
}
```



## randint()

- Prototype

```c
int randint(int min, int max);
```

- Description
    - Generate a random integer between `min` and `max`.
- Parameters
    - `min`: The lower bound of the random number (inclusive).
    - `max`: The upper bound of the random number (inclusive).
- Return
    - The random integer.
- Usage

```c
printf("%d\n", randint(1, 100));
```



## random()

- Prototype

```c
double random();
```

- Description
    - Generate a random floating point number between 0 and 1 (both inclusive).
- Return
    - The random floating point number between 0 and 1 (both inclusive).
- Usage

```c
printf("%f\n", random());
```



## str_clear()

- Prototype

```c
char *str_clear(char *str);
```

- Description
    - Clear the string.
- Parameters
    - `str`: The string to be cleared.
- Return
    - The cleared string.
- Usage

```c
char str[] = "hello";
str_clear(str);
printf("%s\n", str);
```



## str_equal()

- Prototype

```c
bool str_equal(const char *s1, const char *s2);
```

- Description
    - Checks if two strings are equal.
- Parameters
    - `s1`: The first string.
    - `s2`: The second string.
- Return
    - Returns `true` if the two strings are equal, otherwise returns `false`.
- Usage

```c
char s1[] = "hello";
char s2[] = "hello";
if (str_equal(s1, s2)) {
    // ...
}
```



## str_equal_ignore_case()

- Prototype

```c
bool str_equal_ignore_case(const char *s1, const char *s2);
```

- Description
    - Checks if two strings are equal, ignoring case.
- Parameters
    - `s1`: The first string.
    - `s2`: The second string.
- Return
    - Returns `true` if the two strings are equal ignoring case, otherwise returns `false`.
- Usage

```c
char s1[] = "hello";
char s2[] = "HELLO";
if (str_equal_ignore_case(s1, s2)) {
    // ...
}
```



## str_tolower()

- Prototype

```c
char *str_tolower(char *str);
```

- Description
    - Convert the string to lowercase.
- Parameters
    - `str`: The string to be converted.
- Return
    - The converted string.
- Usage

```c
char str[] = "Hello World";
str_tolower(str);
printf("%s\n", str);
```



## str_toupper()

- Prototype

```c
char *str_toupper(char *str);
```

- Description
    - Convert the string to uppercase.
- Parameters
    - `str`: The string to be converted.
- Return
    - The converted string.
- Usage

```c
char str[] = "Hello World";
str_toupper(str);
printf("%s\n", str);
```



## str_starts_with()

- Prototype

```c
bool str_starts_with(const char *str, const char *prefix);
```

- Description
    - Checks if the string starts with the specified prefix.
- Parameters
    - `str`: The string to be checked.
    - `prefix`: The prefix to be checked.
- Return
    - Returns `true` if the string starts with the specified prefix, otherwise returns `false`.
- Usage

```c
if (str_starts_with("hello, world!", "hello")) {
    // ...
}
```



## str_ends_with()

- Prototype

```c
bool str_ends_with(const char *str, const char *suffix);
```

- Description
    - Checks if the string ends with the specified suffix.
- Parameters
    - `str`: The string to be checked.
    - `suffix`: The suffix to be checked.
- Return
    - Returns `true` if the string ends with the specified suffix, otherwise returns `false`.
- Usage

```c
if (str_ends_with("hello, world!", "world")) {
    // ...
}
```



## str_index_of_char()

- Prototype

```c
int str_index_of_char(const char *str, char c);
```

- Description
    - Returns the index of the first occurrence of the specified character in the string.
- Parameters
    - `str`: The string to be searched.
    - `c`: The target character.
- Return
    - The index of the first occurrence of the specified character in the string.
- Usage

```c
int index = str_index_of_char("Hello, world!", ',');
if (index != -1) {
    // ...
}
```



## str_index_of_string()

- Prototype

```c
int str_index_of_string(const char *str, const char *substr);
```

- Description
    - Returns the index of the first occurrence of the specified substring in the string.
- Parameters
    - `str`: The string to be searched.
    - `substr`: The target substring.
- Return
    - The index of the first occurrence of the specified substring in the string.
- Usage

```c
int index = str_index_of_string("Hello, world!", "world");
if (index != -1) {
    // ...
}
```



## str_contains_string()

- Prototype

```c
bool str_contains_string(const char *str, const char *substr);
```

- Description
    - Checks if the string contains the specified substring.
- Parameters
    - `str`: The string to be checked.
    - `substr`: The target substring.
- Return
    - Returns `true` if the string contains the specified substring, otherwise returns `false`.
- Usage

```c
if (str_contains_string("Hello, world!", "world")) {
    // ...
}
```



## str_reverse()

- Prototype

```c
char *str_reverse(char *str);
```

- Description
    - Reverse the string.
- Parameters
    - `str`: The string to be reversed.
- Return
    - The reversed string.
- Usage

```c
char str[] = "hello, world";
str_reverse(str);
printf("%s\n", str);
```



## str_strip()

- Prototype

```c
char *str_strip(char *str);
```

- Description
    - Remove the leading and trailing whitespace characters from the string.
- Parameters
    - `str`: The string to be stripped.
- Return
    - The stripped string.
- Usage

```c
char str[] = "\n\t  hello world\n\t   ";
str_strip(str);
printf("%s\n", str);
```



## str_substring()

- Prototype

```c
char *str_substring(const char *str, size_t start, size_t end);
```

- Description
    - Get the substring of the specified string.
- Parameters
    - `str`: The string to be sliced.
    - `start`: The start index of the substring (inclusive).
    - `end`: The end index of the substring (exclusive).
- Return
    - The substring of the specified string.
- Note
    - The returned string must be freed by the caller.

- Usage

```c
char *s = str_substring("Hello, world!", 7, 12);
printf("%s\n", s);
free(s);
```



## str_count_substring()

- Prototype

```c
char *str_substring(const char *str, size_t start, size_t end);
```

- Description
    - Count the number of occurrences of the specified substring in the string.
- Parameters
    - `str`: The string to be searched.
    - `substr`: The target substring.
- Return
    - The number of occurrences of the specified substring in the string.
- Usage

```c
int count = str_count_substring("Hello World Hello World!", "World");
printf("%d\n", count);
```



## str_append_char()

- Prototype

```c
char *str_append_char(char *str, char c);
```

- Description
    - Append the specified character to the end of the string.
- Parameters
    - `str`: The string to be appended.
    - `c`: The appended character.
- Return
    - The string after appending.
- Usage

```c
char str[32] = "hello";
str_append_char(str, '!');
printf("%s\n", str);
```



## str_insert_char()

- Prototype

```c
char *str_insert_char(char *str, size_t index, char c);
```

- Description
    - Insert the specified character to the specified index of the string.
- Parameters
    - `str`: The string to be inserted.
    - `index`: The index to be inserted.
    - `c`: The inserted character.
- Return
    - The string after inserting.
- Usage

```c
char str[32] = "hello world";
str_insert_char(str, 5, ',');
printf("%s\n", str);
```



## str_insert_string()

- Prototype

```c
char *str_insert_string(char *str, size_t index, const char *substr);
```

- Description
    - Insert the specified substring to the specified index of the string.
- Parameters
    - `str`: The string to be inserted.
    - `index`: The index to be inserted.
    - `substr`: The inserted substring.
- Return
    - The string after inserting.
- Usage

```c
char str[32] = "helloworld";
str_insert_string(str, 5, ", ");
printf("%s\n", str);
```



## str_remove_char()

- Prototype

```c
char *str_remove_char(char *str, char c);
```

- Description
    - Removes all occurrences of the specified character from the string.
- Parameters
    - `str`: The string to be removed.
    - `c`: The removed character.
- Return
    - The string after removing.
- Usage

```c
char str[32] = "Hello, world";
str_remove_char(str, 'o');
printf("%s\n", str);
```



## str_remove_string()

- Prototype

```c
char *str_remove_string(char *str, const char *substr);
```

- Description
    - Removes all occurrences of the specified substring from the string.
- Parameters
    - `str`: The string to be removed.
    - `substr`: The removed substring.
- Return
    - The string after removing.
- Usage

```c
char str[32] = "This is a test";
str_remove_string(str, "is");
printf("%s\n", str);
```



## str_replace_char()

- Prototype

```c
char *str_replace_char(char *str, char old_char, char new_char);
```

- Description
    - Replaces all occurrences of the specified character in the string with the specified new character.
- Parameters
    - `str`: The string to be replaced.
    - `old_char`: The replaced character.
    - `new_char`: The new character.
- Return
    - The string after replacing.
- Usage

```c
char str[32] = "Hello World";
str_replace_char(str, 'o', 'X');
printf("%s\n", str);
```



## str_replace_string()

- Prototype

```c
char *str_replace_string(char *str, const char *old_str, const char *new_str);
```

- Description
    - Replaces all occurrences of the specified substring in the string with the specified new substring.
- Parameters
    - `str`: The string to be replaced.
    - `old_str`: The replaced substring.
    - `new_str`: The new substring.
- Return
    - The string after replacing.
- Usage

```c
char str[32] = "Hello World";
str_replace_char(str, "World", "Earth");
printf("%s\n", str);
```



## str_split()

- Prototype

```c
char **str_split(const char *str, const char *delimiter);
```

- Description
    - Splits the string into an array of strings using the specified delimiter.
- Parameters
    - `str`: The string to be split.
    - `delimiter`: The delimiter.
- Return
    - An array of strings ends with `NULL`.
- Note
    - The returned array ends with `NULL`.
    - The returned array must be freed by the caller.

- Usage

```c
char **tokens = str_split("123, 456, 789", ", ");
int i = 0;
while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    free(tokens[i]);
    i++;
}
free(tokens);
```

