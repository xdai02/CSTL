## cino_string

- 模块功能：提供cino-string结构操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### cino-string操作

#### string_create()

- 函数原型：

```c
string_t *string_create(const char *str);
```

- 功能：创建string_t。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：返回string_t指针，创建失败返回`NULL`。

---

#### string_destroy()

- 函数原型：

```c
void string_destroy(string_t *string);
```

- 功能：销毁string_t。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

---

#### string_get()

- 函数原型：

```c
const char *string_get(const string_t *string);
```

- 功能：获取cino-string的字符串值。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

- 返回值：cino-string的字符串值。

---

#### string_set()

- 函数原型：

```c
string_t *string_set(string_t *string, const char *str);
```

- 功能：设置cino-string的字符串值。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| str    | 字符串      |

- 返回值：修改后的cino-string。

---

#### string_length()

- 函数原型：

```c
int string_length(const string_t *string);
```

- 功能：获取cino-string长度。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

- 返回值：cino-string长度。

---

#### string_clear()

- 函数原型：

```c
string_t *string_clear(string_t *string);
```

- 功能：清空cino-string。
- 参数：

| 参数     | 说明        |
| -------- | ----------- |
| string   | cino-string |

- 返回值：修改后的cino-string。

---

#### string_equal()

- 函数原型：

```c
bool string_equal(const string_t *s1, const string_t *s2);
```

- 功能：判断cino-string是否相等。
- 参数：

| 参数 | 说明          |
| ---- | ------------- |
| s1   | cino-string 1 |
| s2   | cino-string 2 |

- 返回值：cino-string相等返回`true`，不相等返回`false`。

---

#### string_equal_ignore_case()

- 函数原型：

```c
bool string_equal_ignore_case(const string_t *s1, const string_t *s2);
```

- 功能：忽略大小写判断cino-string是否相等。
- 参数：

| 参数 | 说明          |
| ---- | ------------- |
| s1   | cino-string 1 |
| s2   | cino-string 2 |

- 返回值：cino-string忽略大小写相等返回`true`，不相等返回`false`。

---

#### string_to_lower()

- 函数原型：

```c
string_t *string_to_lower(string_t *string);
```

- 功能：cino-string转小写。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

- 返回值：小写cino-string。

---

#### string_to_upper()

- 函数原型：

```c
string_t *string_to_upper(string_t *string);
```

- 功能：cino-string转大写。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

- 返回值：大写cino-string。

---

#### string_starts_with()

- 函数原型：

```c
bool string_starts_with(const string_t *string, const str_t prefix);
```

- 功能：判断cino-string是否以指定子串开头。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| prefix | 子串        |

- 返回值：如果cino-string以`prefix`开头返回`true`，否则返回`false`。

---

#### string_ends_with()

- 函数原型：

```c
bool string_ends_with(const string_t *string, const str_t postfix);
```

- 功能：判断cino-string是否以指定子串结尾。
- 参数：

| 参数    | 说明        |
| ------- | ----------- |
| string  | cino-string |
| postfix | 子串        |

- 返回值：如果cino-string以`postfix`结尾返回`true`，否则返回`false`。

---

#### string_copy()

- 函数原型：

```c
string_t *string_copy(string_t *destination, const string_t *source);
```

- 功能：cino-string拷贝。
- 参数：

| 参数        | 说明            |
| ----------- | --------------- |
| destination | 目标cino-string |
| source      | 源cino-string   |

- 返回值：返回目标cino-string。

---

#### string_concat()

- 函数原型：

```c
string_t *string_concat(string_t *destination, const string_t *source);
```

- 功能：cino-string拼接。
- 参数：

| 参数        | 说明            |
| ----------- | --------------- |
| destination | 目标cino-string |
| source      | 源cino-string   |

- 返回值：返回目标cino-string。

---

#### string_trim()

- 函数原型：

```c
string_t *string_trim(string_t *string);
```

- 功能：删除cino-string首尾空白字符。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |

- 返回值：返回删除首尾空白字符后的cino-string。

---

#### string_append_char()

- 函数原型：

```c
string_t *string_append_char(string_t *string, char c);
```

- 功能：cino-string追加字符。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| c      | 字符        |

- 返回值：修改后的cino-string。

---

#### string_insert_char()

- 函数原型：

```c
string_t *string_insert_char(string_t *string, int index, char c);
```

- 功能：cino-string插入字符。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| index  | 插入位置    |
| c      | 字符        |

- 返回值：修改后的cino-string。

---

#### string_insert_string()

- 函数原型：

```c
string_t *string_insert_string(string_t *string, int index, const str_t substr);
```

- 功能：cino-string插入字符串。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| index  | 插入位置    |
| substr | 插入字符串  |

- 返回值：修改后的cino-string。

---

#### string_count_substring()

- 函数原型：

```c
int string_count_substring(const string_t *string, const str_t substr);
```

- 功能：计算子串出现次数。
- 参数：

| 参数        | 说明                 |
| ----------- | -------------------- |
| string   | cino-string    |
| substr      | 子串 |

- 返回值：子串出现次数。

---

#### string_replace_char()

- 函数原型：

```c
string_t *string_replace_char(string_t *string, char old_char, char new_char);
```

- 功能：替换cino-string中所有指定字符。
- 参数：

| 参数     | 说明        |
| -------- | ----------- |
| string   | cino-string |
| old_char | 旧字符      |
| new_char | 新字符      |

- 返回值：修改后的cino-string。

---

#### string_replace()

- 函数原型：

```c
string_t *string_replace(string_t *string, const str_t old_str, const str_t new_str);
```

- 功能：替换cino-string中所有指定子串。
- 参数：

| 参数    | 说明        |
| ------- | ----------- |
| string  | cino-string |
| old_str | 旧字符串    |
| new_str | 新字符串    |

- 返回值：修改后的cino-string。

---

#### string_remove()

- 函数原型：

```c
string_t *string_remove(string_t *string, const str_t substr);
```

- 功能：删除cino-string中所有指定子串。
- 参数：

| 参数   | 说明        |
| ------ | ----------- |
| string | cino-string |
| substr | 需删除子串  |

- 返回值：修改后的cino-string。
