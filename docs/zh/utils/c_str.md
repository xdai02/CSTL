# str

[TOC]



## str_clear()

- 原型

```c
char *str_clear(char *str);
```

- 描述
    - 清空字符串。
- 参数
    - `str`：待清空字符串。
- 返回值
    - 清空后的字符串。
- 用例

```c
char str[] = "hello";
str_clear(str);
printf("%s\n", str);
```



## str_equal()

- 原型

```c
bool str_equal(const char *s1, const char *s2);
```

- 描述
    - 检查两个字符串是否相同。
- 参数
    - `s1`：第一个字符串
    - `s2`：第二个字符串。
- 返回值
    - 如果两个字符串相同返回`true`，否则返回`false`。
- 用例

```c
char s1[] = "hello";
char s2[] = "hello";
if (str_equal(s1, s2)) {
    // ...
}
```



## str_equal_ignore_case()

- 原型

```c
bool str_equal_ignore_case(const char *s1, const char *s2);
```

- 描述
    - 忽略大小写检查两个字符串是否相同。
- 参数
    - `s1`：第一个字符串
    - `s2`：第二个字符串。
- 返回值
    - 如果两个字符串忽略大小写相同返回`true`，否则返回`false`。
- 用例

```c
char s1[] = "hello";
char s2[] = "HELLO";
if (str_equal_ignore_case(s1, s2)) {
    // ...
}
```



## str_tolower()

- 原型

```c
char *str_tolower(char *str);
```

- 描述
    - 字符串转小写。
- 参数
    - `str`：待转换字符串。
- 返回值
    - 转换后的字符串。
- 用例

```c
char str[] = "Hello World";
str_tolower(str);
printf("%s\n", str);
```



## str_toupper()

- 原型

```c
char *str_toupper(char *str);
```

- 描述
    - 字符串转大写。
- 参数
    - `str`：待转换字符串。
- 返回值
    - 转换后的字符串。
- 用例

```c
char str[] = "Hello World";
str_toupper(str);
printf("%s\n", str);
```



## str_starts_with()

- 原型

```c
bool str_starts_with(const char *str, const char *prefix);
```

- 描述
    - 检查字符串是否以指定前缀开头。
- 参数
    - `str`：待检查字符串。
    - `prefix`：待检查前缀。
- 返回值
    - 如果字符串以指定前缀开头返回 `true`，否则返回`false`。
- 用例

```c
if (str_starts_with("hello, world!", "hello")) {
    // ...
}
```



## str_ends_with()

- 原型

```c
bool str_ends_with(const char *str, const char *suffix);
```

- 描述
    - 检查字符串是否以指定后缀结尾。
- 参数
    - `str`：待检查字符串。
    - `suffix`：待检查后缀。
- 返回值
    - 如果字符串以指定后缀结尾返回 `true`，否则返回`false`。
- 用例

```c
if (str_ends_with("hello, world!", "world")) {
    // ...
}
```



## str_index_of_char()

- 原型

```c
int str_index_of_char(const char *str, char c);
```

- 描述
    - 返回字符串中指定字符首次出现的下标。
- 参数
    - `str`：待查找字符串。
    - `c`：目标字符。
- 返回值
    - 字符串中指定字符首次出现的下标。
- 用例

```c
int index = str_index_of_char("Hello, world!", ',');
if (index != -1) {
    // ...
}
```



## str_index_of_string()

- 原型

```c
int str_index_of_string(const char *str, const char *substr);
```

- 描述
    - 返回字符串中指定字符串首次出现的下标。
- 参数
    - `str`：待查找字符串。
    - `substr`：目标字符串。
- 返回值
    - 字符串中指定字符串首次出现的下标。
- 用例

```c
int index = str_index_of_string("Hello, world!", "world");
if (index != -1) {
    // ...
}
```



## str_contains_string()

- 原型

```c
bool str_contains_string(const char *str, const char *substr);
```

- 描述
    - 检查字符串是否包含指定子串。
- 参数
    - `str`：待检查字符串
    - `substr`：目标子串。
- 返回值
    - 如果字符串包含指定子串返回 `true`，返回`false`。
- 用例

```c
if (str_contains_string("Hello, world!", "world")) {
    // ...
}
```



## str_reverse()

- 原型

```c
char *str_reverse(char *str);
```

- 描述
    - 反转字符串。
- 参数
    - `str`：待反转字符串。
- 返回值
    - 反转后的字符串。
- 用例

```c
char str[] = "hello, world";
str_reverse(str);
printf("%s\n", str);
```



## str_strip()

- 原型

```c
char *str_strip(char *str);
```

- 描述
    - 去除字符串首尾空白字符。
- 参数
    - `str`：待去除首尾空白字符的字符串。
- 返回值
    - 去除首尾空白字符的字符串。
- 用例

```c
char str[] = "\n\t  hello world\n\t   ";
str_strip(str);
printf("%s\n", str);
```



## str_substring()

- 原型

```c
char *str_substring(const char *str, size_t start, size_t end);
```

- 描述
    - 从字符串中截取子串。
- 参数
    - `str`：待截取字符串。
    - `start`：子串开始下标（包含）。
    - `end`：子串结束下标（不包含）。
- 返回值
    - 截取的子串。
- 注意
    - 调用者**必须**释放返回的子串。

- 用例

```c
char *s = str_substring("Hello, world!", 7, 12);
printf("%s\n", s);
free(s);
```



## str_count_substring()

- 原型

```c
char *str_substring(const char *str, size_t start, size_t end);
```

- 描述
    - 计算字符串中指定子串出现的次数。
- 参数
    - `str`：待查找字符串。
    - `substr`：目标子串。
- 返回值
    - 字符串中指定子串出现的次数。
- 用例

```c
int count = str_count_substring("Hello World Hello World!", "World");
printf("%d\n", count);
```



## str_append_char()

- 原型

```c
char *str_append_char(char *str, char c);
```

- 描述
    - 在字符串末尾追加一个字符。
- 参数
    - `str`：待追加字符串。
    - `c`：追加字符。
- 返回值
    - 追加后的字符串。
- 用例

```c
char str[32] = "hello";
str_append_char(str, '!');
printf("%s\n", str);
```



## str_insert_char()

- 原型

```c
char *str_insert_char(char *str, size_t index, char c);
```

- 描述
    - 在字符串的指定位置插入指定字符。
- 参数
    - `str`：待插入字符串。
    - `index`：待插入位置。
    - `c`：插入字符。
- 返回值
    - 插入后的字符串。
- 用例

```c
char str[32] = "hello world";
str_insert_char(str, 5, ',');
printf("%s\n", str);
```



## str_insert_string()

- 原型

```c
char *str_insert_string(char *str, size_t index, const char *substr);
```

- 描述
    - 在字符串的指定位置插入指定字符串。
- 参数
    - `str`：待插入字符串。
    - `index`：待插入位置。
    - `substr`：插入字符串。
- 返回值
    - 插入后的字符串。
- 用例

```c
char str[32] = "helloworld";
str_insert_string(str, 5, ", ");
printf("%s\n", str);
```



## str_remove_char()

- 原型

```c
char *str_remove_char(char *str, char c);
```

- 描述
    - 删除字符串中所有指定字符。
- 参数
    - `str`：待删除字符串。
    - `c`：删除字符。
- 返回值
    - 删除后的字符串。
- 用例

```c
char str[32] = "Hello, world";
str_remove_char(str, 'o');
printf("%s\n", str);
```



## str_remove_string()

- 原型

```c
char *str_remove_string(char *str, const char *substr);
```

- 描述
    - 删除字符串中所有指定字符串。
- 参数
    - `str`：待删除字符串。
    - `substr`：删除字符串。
- 返回值
    - 删除后的字符串。
- 用例

```c
char str[32] = "This is a test";
str_remove_string(str, "is");
printf("%s\n", str);
```



## str_replace_char()

- 原型

```c
char *str_replace_char(char *str, char old_char, char new_char);
```

- 描述
    - 将字符串中所有指定字符替换为新字符。
- 参数
    - `str`：待替换字符串。
    - `old_char`：被替换字符。
    - `new_char`：新字符。
- 返回值
    - 替换后的字符串。
- 用例

```c
char str[32] = "Hello World";
str_replace_char(str, 'o', 'X');
printf("%s\n", str);
```



## str_replace_string()

- 原型

```c
char *str_replace_string(char *str, const char *old_str, const char *new_str);
```

- 描述
    - 将字符串中所有指定字符串替换为新字符串。
- 参数
    - `str`：待替换字符串。
    - `old_str`：被替换字符串。
    - `new_str`：新字符串。
- 返回值
    - 替换后的字符串。
- 用例

```c
char str[32] = "Hello World";
str_replace_char(str, "World", "Earth");
printf("%s\n", str);
```



## str_split()

- 原型

```c
char **str_split(const char *str, const char *delimiter);
```

- 描述
    - 将字符串使用指定的分隔符分割成字符串数组。
- 参数
    - `str`：待分割字符串。
    - `delimiter`：分隔符。
- 返回值
    - 以`NULL`结尾的字符串数组。
- 注意
    - 返回的字符串数组以`NULL`结尾。
    - 调用者**必须**释放返回的字符串数组。

- 用例

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

