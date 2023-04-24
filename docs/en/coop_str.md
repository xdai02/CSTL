# coop_str

[TOC]



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
    - `substr`: The appended character.
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
str_insert_char(str, 5, ", ");
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
    - Splits the string into a list of strings using the specified delimiter.
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

