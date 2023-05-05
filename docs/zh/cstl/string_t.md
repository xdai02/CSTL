# string_t

[TOC]



## string_create()

- 原型

```c
string_t *string_create(const char *str);
```

- 描述
    - 创建`string_t`对象。
- 参数
    - `str`：原生字符串。
- 返回值
    - 如果分配成功返回`string_t`指针，否则返回`NULL`。
- 用例

```c
string_t *s = string_create("Hello, World!");
```



## string_destroy()

- 原型

```c
void string_destroy(string_t *string);
```

- 描述
    - 销毁`string_t`对象。
- 参数
    - `string`：`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello, World!");
string_destroy(s);
```



## string_clone()

- 原型

```c
string_t *string_clone(const string_t *string);
```

- 描述
    - 拷贝`string_t`对象。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 如果分配成功返回`string_t`指针，否则返回`NULL`。

- 用例

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_clone(s1);
```



## string_length()

- 原型

```c
size_t string_length(const string_t *string);
```

- 描述
    - 返回`string_t`的长度。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回`string_t`的长度。
- 用例

```c
string_t *s = string_create("Hello, World!");
printf("%d\n", string_length(s));
```



## string_is_empty()

- 原型

```c
bool string_is_empty(const string_t *string);
```

- 描述
    - 判断`string_t`对象是否为空。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 如果`string_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
string_t *s = string_create("Hello, World!");
if (string_is_empty(s)) {
    // ...
}
```



## string_get()

- 原型

```c
const char *string_get(const string_t *string);
```

- 描述
    - 获取原生字符串。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回原生字符串。
- 用例

```c
string_t *s = string_create("Hello, World!");
printf("%s\n", string_get(s));
```



## string_char_at()

- 原型

```c
char string_char_at(const string_t *string, size_t index);
```

- 描述
    - 获取指定位置字符串。
- 参数
    - `string`：`string_t`对象。
    - `index`：下标。
- 返回值
    - 返回指定位置字符串。
- 用例

```c
string_t *s = string_create("Hello, World!");
printf("%c\n", string_char_at(5));
```



## string_set_char_at()

- 原型

```c
string_t *string_set_char_at(string_t *string, size_t index, char c);
```

- 描述
    - 设置指定位置字符。
- 参数
    - `string`：`string_t`对象。
    - `index`：下标。
    - `c`：新字符。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello, world!");
string_set_char_at(s, 0, 'H');
```



## string_clear()

- 原型

```c
string_t *string_clear(string_t *string);
```

- 描述
    - 清空`string_t`对象。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello, world!");
string_clear(s);
```



## string_equal()

- 原型

```c
bool string_equal(const string_t *string1, const string_t *string2);
```

- 描述
    - 检查两个`string_t`对象是否相等。
- 参数
    - `string1`：第一个`string_t`对象。
    - `string2`：第二个`string_t`对象。
- 返回值
    - 如果两个`string_t`对象相等返回`true`，否则返回`false`。
- 用例

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_create("Hello World");
if (string_equal(s1, s2)) {
    // ...
}
```



## string_equal_ignore_case()

- 原型

```c
bool string_equal_ignore_case(const string_t *string1, const string_t *string2);
```

- 描述
    - 检查两个`string_t`对象忽略大小写是否相等。
- 参数
    - `string1`：第一个`string_t`对象。
    - `string2`：第二个`string_t`对象。
- 返回值
    - 如果两个`string_t`对象忽略大小写相等返回`true`，否则返回`false`。
- 用例

```c
string_t *s1 = string_create("Hello World");
string_t *s2 = string_create("HELLO WORLD");
if (string_equal_ignore_case(s1, s2)) {
    // ...
}
```



## string_tolower()

- 原型

```c
string_t *string_tolower(string_t *string);
```

- 描述
    - 将`string_t`对象转换小写。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello World");
string_tolower(s);
```



## string_toupper()

- 原型

```c
string_t *string_toupper(string_t *string);
```

- 描述
    - 将`string_t`对象转换大写。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello World");
string_toupper(s);
```



## string_starts_with()

- 原型

```c
bool string_starts_with(const string_t *string, const char *prefix);
```

- 描述
    - 检查`string_t`对象是否以指定前缀开头。
- 参数
    - `string`：`string_t`对象。
    - `prefix`：The prefix.
- 返回值
    - 如果`string_t`对象以指定前缀开头返回`true`，否则返回`false`。
- 用例

```c
string_t *s = string_create("hello world");
if (string_starts_with(s, "hello")) {
    // ...
}
```



## string_ends_with()

- 原型

```c
bool string_ends_with(const string_t *string, const char *suffix);
```

- 描述
    - 检查`string_t`对象是否以指定后缀结尾。
- 参数
    - `string`：`string_t`对象。
    - `suffix`：The suffix.
- 返回值
    - 如果`string_t`对象以指定后缀结尾返回`true`，否则返回`false`。
- 用例

```c
string_t *s = string_create("hello world");
if (string_ends_with(s, "world")) {
    // ...
}
```



## string_index_of_char()

- 原型

```c
int string_index_of_char(const string_t *string, char c);
```

- 描述
    - 返回`string_t`对象中首次出现指定字符的下标。
- 参数
    - `string`：`string_t`对象。
    - `c`：目标字符。
- 返回值
    - 返回`string_t`对象中首次出现指定字符的下标，未找到返回`-1`。
- 用例

```c
string_t *s = string_create("Hello, world!");
int index = string_index_of_char(s, ',');
if (index != -1) {
    // ...
}
```



## string_index_of_string()

- 原型

```c
int string_index_of_string(const string_t *string, const char *str);
```

- 描述
    - 返回`string_t`对象中首次出现指定字符串的下标。
- 参数
    - `string`：`string_t`对象。
    - `str`：目标字符串。
- 返回值
    - 返回`string_t`对象中首次出现指定字符串的下标，未找到返回`-1`。
- 用例

```c
string_t *s = string_create("Hello, world!");
int index = string_index_of_string(s, "world");
if (index != -1) {
    // ...
}
```



## string_contains_string()

- 原型

```c
bool string_contains_string(const string_t *string, const char *str);
```

- 描述
    - 检查`string_t`对象是否包含指定子串。
- 参数
    - `string`：`string_t`对象。
    - `str`：目标字符串。
- 返回值
    - 如果`string_t`对象包含指定子串返回`true`，否则返回`false`。
- 用例

```c
string_t *s = string_create("Hello, world!");
if (string_contains_string(s, "world")) {
    // ...
}
```



## string_reverse()

- 原型

```c
string_t *string_reverse(string_t *string);
```

- 描述
    - 反转`string_t`对象。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello, world");
string_reverse(s);
```



## string_strip()

- 原型

```c
string_t *string_strip(string_t *string);
```

- 描述
    - 删除`string_t`对象首尾的空白字符。
- 参数
    - `string`：`string_t`对象。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("\n\t  hello world\n\t   ");
string_strip(s);
```



## string_substring()

- 原型

```c
char *string_substring(const string_t *string, int start, int end)
```

- 描述
    - 获取`string_t`对象的子串。
- 参数
    - `string`：`string_t`对象。
    - `start`：子串开始下标（包含）。
    - `end`：子串结束下标（不包含）。
- 返回值
    - 指定范围内的子串。
- 注意
    - 调用者**必须**释放返回的子串。

- 用例

```c
string_t *s = string_create("Hello, world!");
char *substr = string_substring(s, 7, 12);
printf("%s\n", substr);
```



## string_count_substring()

- 原型

```c
size_t string_count_substring(const string_t *string, const char *substr);
```

- 描述
    - 计算`string_t`对象中指定子串出现次数。
- 参数
    - `string`：`string_t`对象。
    - `substr`：目标字符串。
- 返回值
    - 返回`string_t`对象中指定子串出现次数。
- 用例

```c
string_t *s = string_create("Hello World Hello World!");
int count = string_count_substring(s, "World");
printf("%d\n", count);
```



## string_append_char()

- 原型

```c
string_t *string_append_char(string_t *string, char c);
```

- 描述
    - 在`string_t`对象末尾追加指定字符。
- 参数
    - `string`：`string_t`对象。
    - `c`：追加字符。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello");
string_append_char(s, '!');
```



## string_insert_char()

- 原型

```c
string_t *string_insert_char(string_t *string, size_t index, char c);
```

- 描述
    - 在`string_t`对象中的指定位置插入指定字符。
- 参数
    - `string`：`string_t`对象。
    - `index`：插入下标。
    - `c`：插入字符。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello");
string_insert_char(s, 5, ',');
```



## string_concat()

- 原型

```c
string_t *string_concat(string_t *string, const char *str);
```

- 描述
    - 在`string_t`对象末尾追加指定字符串。
- 参数
    - `string`：`string_t`对象。
    - `str`：追加字符串。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("hello");
string_concat(s, " world");
```



## string_insert_string()

- 原型

```c
string_t *string_insert_string(string_t *string, size_t index, const char *str);
```

- 描述
    - 在`string_t`对象的指定位置插入指定字符串。
- 参数
    - `string`：`string_t`对象。
    - `index`：插入下标。
    - `substr`：插入字符串。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("helloworld");
string_insert_string(str, 5, ", ");
```



## string_remove_char()

- 原型

```c
string_t *string_remove_char(string_t *string, char c);
```

- 描述
    - 删除`string_t`对象中出现的所有指定字符。
- 参数
    - `string`：`string_t`对象。
    - `c`：删除字符。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello, world");
string_remove_char(s, 'o');
```



## string_remove_string()

- 原型

```c
string_t *string_remove_string(string_t *string, const char *str);
```

- 描述
    - 删除`string_t`对象中出现的所有指定字符串。
- 参数
    - `string`：`string_t`对象。
    - `substr`：删除字符串。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("This is a test");
string_remove_char(s, "is");
```



## string_replace_char()

- 原型

```c
string_t *string_replace_char(string_t *string, char old_char, char new_char);
```

- 描述
    - 将`string_t`对象中所有指定字符替换为新字符。
- 参数
    - `string`：`string_t`对象。
    - `old_char`：需替换字符。
    - `new_char`：新字符。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello World");
string_replace_char(s, 'o', 'X');
```



## str_replace_string()

- 原型

```c
char *str_replace_string(char *str, const char *old_str, const char *new_str);
```

- 描述
    - 将`string_t`对象中所有指定字符串替换为新字符串。
- 参数
    - `string`：`string_t`对象。
    - `old_str`：需替换字符串。
    - `new_str`：新字符串。
- 返回值
    - 返回修改后的`string_t`对象。
- 用例

```c
string_t *s = string_create("Hello World");
str_replace_string(s, "World", "Earth");
```



## string_split()

- 原型

```c
char **string_split(const string_t *string, const char *delimiter);
```

- 描述
    - 将`string_t`对象使用指定的分隔符分割成字符串数组。
- 参数
    - `string`：`string_t`对象。
    - `delimiter`：分隔符。
- 返回值
    - 以`NULL`结尾的字符串数组。
- 注意
    - 返回的字符串数组以`NULL`结尾。
    - 调用者**必须**释放返回的字符串数组。

- 用例

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

