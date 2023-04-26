# string_t

[TOC]



## string_create()

- Prototype

```c
string_t *string_create(const char *str);
```

- Description
    - Create a `string_t` object.
- Parameters
    - `str`: The primitive string.
- Return
    - Returns a `string_t` pointer if the memory allocation succeeds, otherwise returns `NULL`.
- Usage

```c
string_t *s = string_create("Hello, World!");
```



## string_destroy()

- Prototype

```c
void string_destroy(string_t *string);
```

- Description
    - Destroy the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Usage

```c
string_t *s = string_create("Hello, World!");
string_destroy(s);
```



## string_clone()

- Prototype

```c
string_t *string_clone(const string_t *string);
```

- Description
    - Clone a `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns a `string_t` pointer if the memory allocation succeeds, otherwise returns `NULL`.

- Usage

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_clone(s1);
```



## string_length()

- Prototype

```c
size_t string_length(const string_t *string);
```

- Description
    - Returns the length of the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the length of the `string_t` object.
- Usage

```c
string_t *s = string_create("Hello, World!");
printf("%d\n", string_length(s));
```



## string_is_empty()

- Prototype

```c
bool string_is_empty(const string_t *string);
```

- Description
    - Checks if the `string_t` object is empty.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns `true` if the `string_t` object is empty, otherwise returns `false`.
- Usage

```c
string_t *s = string_create("Hello, World!");
if (string_is_empty(s)) {
    // ...
}
```



## string_get()

- Prototype

```c
const char *string_get(const string_t *string);
```

- Description
    - Get the primitive string.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the primitive string.
- Usage

```c
string_t *s = string_create("Hello, World!");
printf("%s\n", string_get(s));
```



## string_char_at()

- Prototype

```c
char string_char_at(const string_t *string, size_t index);
```

- Description
    - Get the character at the specified index.
- Parameters
    - `string`: The `string_t` object.
    - `index`: The index.
- Return
    - Returns the character at the specified index.
- Usage

```c
string_t *s = string_create("Hello, World!");
printf("%c\n", string_char_at(5));
```



## string_set_char_at()

- Prototype

```c
string_t *string_set_char_at(string_t *string, size_t index, char c);
```

- Description
    - Set the character at the specified index.
- Parameters
    - `string`: The `string_t` object.
    - `index`: The index.
    - `c`: The new character.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("hello, world!");
string_set_char_at(s, 0, 'H');
```



## string_clear()

- Prototype

```c
string_t *string_clear(string_t *string);
```

- Description
    - Clear the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("hello, world!");
string_clear(s);
```



## string_equal()

- Prototype

```c
bool string_equal(const string_t *string1, const string_t *string2);
```

- Description
    - Checks if two `string_t` objects are equal.
- Parameters
    - `string1`: The first `string_t` object.
    - `string2`: The second `string_t` object.
- Return
    - Returns `true` if the two `string_t` objects are equal, otherwise returns `false`.
- Usage

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_create("Hello World");
if (string_equal(s1, s2)) {
    // ...
}
```



## string_equal_ignore_case()

- Prototype

```c
bool string_equal_ignore_case(const string_t *string1, const string_t *string2);
```

- Description
    - Checks if two `string_t` objects are equal, ignoring case.
- Parameters
    - `string1`: The first `string_t` object.
    - `string2`: The second `string_t` object.
- Return
    - Returns `true` if the two `string_t` objects are equal ignoring case, otherwise returns `false`.
- Usage

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_create("HELLO WORLD");
if (string_equal_ignore_case(s1, s2)) {
    // ...
}
```



## string_tolower()

- Prototype

```c
string_t *string_tolower(string_t *string);
```

- Description
    - Convert the `string_t` object to lowercase.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("Hello World");
string_tolower(s);
```



## string_toupper()

- Prototype

```c
string_t *string_toupper(string_t *string);
```

- Description
    - Convert the `string_t` object to uppercase.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("Hello World");
string_toupper(s);
```



## string_starts_with()

- Prototype

```c
bool string_starts_with(const string_t *string, const char *prefix);
```

- Description
    - Checks if the `string_t` object starts with the specified prefix.
- Parameters
    - `string`: The `string_t` object.
    - `prefix`: The prefix.
- Return
    - Returns `true` if the `string_t` object starts with the specified prefix, otherwise returns `false`.
- Usage

```c
string_t *s = string_create("hello world");
if (string_starts_with(s, "hello")) {
    // ...
}
```



## string_ends_with()

- Prototype

```c
bool string_ends_with(const string_t *string, const char *suffix);
```

- Description
    - Checks if the `string_t` object ends with the specified suffix.
- Parameters
    - `string`: The `string_t` object.
    - `suffix`: The suffix.
- Return
    - Returns `true` if the `string_t` object ends with the specified suffix, otherwise returns `false`.
- Usage

```c
string_t *s = string_create("hello world");
if (string_ends_with(s, "world")) {
    // ...
}
```



## string_index_of_char()

- Prototype

```c
int string_index_of_char(const string_t *string, char c);
```

- Description
    - Returns the index of the first occurrence of the specified character in the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `c`: The target character.
- Return
    - Returns the index of the first occurrence of the specified character in the `string_t` object, or `-1` if the character does not occur.
- Usage

```c
string_t *s = string_create("Hello, world!");
int index = string_index_of_char(s, ',');
if (index != -1) {
    // ...
}
```



## string_index_of_string()

- Prototype

```c
int string_index_of_string(const string_t *string, const char *str);
```

- Description
    - Returns the index of the first occurrence of the specified substring in the `string_t` object, starting the search at the specified index.
- Parameters
    - `string`: The `string_t` object.
    - `str`: The target substring.
- Return
    - Returns the index of the first occurrence of the specified substring in the `string_t` object, starting the search at the specified index, or `-1` if the substring does not occur.
- Usage

```c
string_t *s = string_create("Hello, world!");
int index = string_index_of_string(s, "world");
if (index != -1) {
    // ...
}
```



## string_contains_string()

- Prototype

```c
bool string_contains_string(const string_t *string, const char *str);
```

- Description
    - Checks if the `string_t` object contains the specified substring.
- Parameters
    - `string`: The `string_t` object.
    - `str`: The target substring.
- Return
    - Returns `true` if the `string_t` object contains the specified substring, otherwise returns `false`.
- Usage

```c
string_t *s = string_create("Hello, world!");
if (string_contains_string(s, "world")) {
    // ...
}
```



## string_reverse()

- Prototype

```c
string_t *string_reverse(string_t *string);
```

- Description
    - Reverse the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the modified `string_t ` object.
- Usage

```c
string_t *s = string_create("hello, world");
string_reverse(s);
```



## string_strip()

- Prototype

```c
string_t *string_strip(string_t *string);
```

- Description
    - Remove the leading and trailing whitespace characters from the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
- Return
    - Returns the modified `string_t ` object.
- Usage

```c
string_t *s = string_create("\n\t  hello world\n\t   ");
string_strip(s);
```



## string_substring()

- Prototype

```c
char *string_substring(const string_t *string, int start, int end)
```

- Description
    - Get the substring of the specified `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `start`: The start index of the substring (inclusive).
    - `end`: The end index of the substring (exclusive).
- Return
    - The substring of the specified `string_t`.
- Note
    - The returned string must be freed by the caller.

- Usage

```c
string_t *s = string_create("Hello, world!");
char *substr = string_substring(s, 7, 12);
printf("%s\n", substr);
```



## string_count_substring()

- Prototype

```c
size_t string_count_substring(const string_t *string, const char *substr);
```

- Description
    - Count the number of occurrences of the specified substring in the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `substr`: The target substring.
- Return
    - The number of occurrences of the specified substring in the `string_t` object.
- Usage

```c
string_t *s = string_create("Hello World Hello World!");
int count = string_count_substring(s, "World");
printf("%d\n", count);
```



## string_append_char()

- Prototype

```c
string_t *string_append_char(string_t *string, char c);
```

- Description
    - Append the specified character to the end of the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `c`: The appended character.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("hello");
string_append_char(s, '!');
```



## string_insert_char()

- Prototype

```c
string_t *string_insert_char(string_t *string, size_t index, char c);
```

- Description
    - Insert the specified character to the specified index of the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `index`: The index to be inserted.
    - `c`: The inserted character.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("hello");
string_insert_char(s, 5, ',');
```



## string_concat()

- Prototype

```c
string_t *string_concat(string_t *string, const char *str);
```

- Description
    - Append the specified string to the end of the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `str`: The appended string.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("hello");
string_concat(s, " world");
```



## string_insert_string()

- Prototype

```c
string_t *string_insert_string(string_t *string, size_t index, const char *str);
```

- Description
    - Insert the specified substring to the specified index of the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `index`: The index to be inserted.
    - `substr`: The inserted substring.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("helloworld");
string_insert_string(str, 5, ", ");
```



## string_remove_char()

- Prototype

```c
string_t *string_remove_char(string_t *string, char c);
```

- Description
    - Removes all occurrences of the specified character from the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `c`: The removed character.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("Hello, world");
string_remove_char(s, 'o');
```



## string_remove_string()

- Prototype

```c
string_t *string_remove_string(string_t *string, const char *str);
```

- Description
    - Removes all occurrences of the specified substring from the `string_t` object.
- Parameters
    - `string`: The `string_t` object.
    - `substr`: The removed substring.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("This is a test");
string_remove_char(s, "is");
```



## string_replace_char()

- Prototype

```c
string_t *string_replace_char(string_t *string, char old_char, char new_char);
```

- Description
    - Replaces all occurrences of the specified character in the `string_t` object with the specified new character.
- Parameters
    - `string`: The `string_t` object.
    - `old_char`: The replaced character.
    - `new_char`: The new character.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("Hello World");
string_replace_char(s, 'o', 'X');
```



## str_replace_string()

- Prototype

```c
char *str_replace_string(char *str, const char *old_str, const char *new_str);
```

- Description
    - Replaces all occurrences of the specified substring in the `string_t` object with the specified new substring.
- Parameters
    - `string`: The `string_t` object.
    - `old_str`: The replaced substring.
    - `new_str`: The new substring.
- Return
    - Returns the modified `string_t` object.
- Usage

```c
string_t *s = string_create("Hello World");
str_replace_string(s, "World", "Earth");
```



## string_split()

- Prototype

```c
char **string_split(const string_t *string, const char *delimiter);
```

- Description
    - Splits the `string_t` object into an array of strings using the specified delimiter.
- Parameters
    - `string`: The `string_t` object.
    - `delimiter`: The delimiter.
- Return
    - An array of strings ends with `NULL`.
- Note
    - The returned array ends with `NULL`.
    - The returned array must be freed by the caller.

- Usage

```c
string_t *s = string_create("123, 456, 789");
char **tokens = string_split(s, ", ");
int i = 0;
while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    free(tokens[i]);
    i++;
}
free(tokens);
```

