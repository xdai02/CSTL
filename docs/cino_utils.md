## cino_utils

- 模块功能：提供通用的工具和接口。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### 类型


| 类型   | 说明         |
| ------ | ------------ |
| str_t  | 等价于char * |
| byte_t | 等价于char   |

<div style="page-break-after: always;"></div>

### status_t

- 功能：状态码。

| 状态码                | 说明     |
| --------------------- | -------- |
| STATUS_OK             | 成功     |
| STATUS_FAIL           | 失败     |
| STATUS_OUT_OF_MEMORY  | 内存不足 |
| STATUS_FOUND          | 找到     |
| STATUS_NOT_FOUND      | 未找到   |
| STATUS_BAD_PARAMETERS | 无效参数 |
| STATUS_IO_ERROR       | I/O错误  |
| STATUS_OUT_OF_BOUNDS  | 越界     |
| STATUS_UNDEFINED      | 未定义   |

<div style="page-break-after: always;"></div>

### logger_t

- 函数原型：

```c
LOGGER(level, format, ...)
```

- 功能：打印日志。
- 参数：

| 参数   | 说明         |
| ------ | ------------ |
| level  | 日志等级     |
| format | 格式化字符串 |

| 日志等级 | 说明   |
| -------- | ------ |
| NONE     | 不输出 |
| DEBUG    | 调试   |
| INFO     | 信息   |
| WARNING  | 警告   |
| ERROR    | 错误   |

<div style="page-break-after: always;"></div>

### 数值操作

#### min()

- 函数原型：

```c
min(x, y)
```

- 功能：返回两数较小值。
- 参数：

| 参数 | 说明 |
| ---- | ---- |
| x    | 变量 |
| y    | 变量 |

- 返回值：较小值。

---

#### max()

- 函数原型：

```c
max(x, y)
```

- 功能：返回两数较大值。
- 参数：

| 参数 | 说明 |
| ---- | ---- |
| x    | 变量 |
| y    | 变量 |

- 返回值：较大值。

---

#### swap()

- 函数原型：

```c
swap(x, y, type)
```

- 功能：交换变量的值。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| x    | 变量     |
| y    | 变量     |
| type | 数据类型 |

<div style="page-break-after: always;"></div>

### 合法性检查

#### return_if_fail()

- 函数原型：

```c
return_if_fail(expr)
```

- 功能：判断表达式`expr`是否成立，不成立直接返回。
- 参数：

| 参数 | 说明       |
| ---- | ---------- |
| expr | 逻辑表达式 |

---

#### return_value_if_fail()

- 函数原型：

```c
return_value_if_fail(expr, ret)
```

- 功能：判断表达式`expr`是否成立，不成立返回`ret`。
- 参数：

| 参数 | 说明       |
| ---- | ---------- |
| expr | 逻辑表达式 |
| ret  | 返回值     |

---

#### call_and_return_if_fail()

- 函数原型：

```c
call_and_return_if_fail(expr, func)
```

- 功能：判断表达式`expr`是否成立，不成立调用`func`后返回。
- 参数：

| 参数 | 说明       |
| ---- | ---------- |
| expr | 逻辑表达式 |
| func | 调用函数   |

---

#### call_and_return_value_if_fail()

- 函数原型：

```c
call_and_return_value_if_fail(expr, func, ret)
```

- 功能：判断表达式`expr`是否成立，不成立调用`func`后返回`ret`。
- 参数：

| 参数 | 说明       |
| ---- | ---------- |
| expr | 逻辑表达式 |
| func | 调用函数   |
| ret  | 返回值     |

<div style="page-break-after: always;"></div>

### 数组操作

#### array_len()

- 函数原型：

```c
array_len(arr)
```

- 功能：获取C数组元素个数。
- 参数：

| 参数 | 说明  |
| ---- | ----- |
| arr  | C数组 |

- 返回值：C数组元素个数。

<div style="page-break-after: always;"></div>

### 动态内存管理

#### cino_alloc()

- 函数原型：

```c
void *cino_alloc(size_t size);
```

- 功能：动态申请空间。
- 参数：

| 参数 | 说明                       |
| ---- | -------------------------- |
| size | 申请空间大小（单位：字节） |

- 返回值：返回分配空间的首地址，分配失败返回`NULL`。

---

#### cino_realloc()

- 函数原型：

```c
void *cino_realloc(void *p, size_t old_size, size_t new_size);
```

- 功能：改变申请空间大小。
- 参数：

| 参数     | 说明                     |
| -------- | ------------------------ |
| p        | 原申请空间               |
| old_size | 原空间大小（单位：字节） |
| new_size | 新空间大小（单位：字节） |

- 返回值：返回分配空间的首地址，分配失败返回`NULL`。

<div style="page-break-after: always;"></div>

### 类型转换

#### str_to_bool()

- 函数原型：

```c
bool str_to_bool(const str_t str);
```

- 功能：字符串转布尔。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：
    - 返回`false`的情况：
        1. str == NULL
        2. strlen(str) == 0
        3. str_equal_ignore_case(str, "false")
        4. a string of zeroes
    - 其它情况返回`true`。

---

#### bool_to_str()

- 函数原型：

```c
const str_t bool_to_str(bool val);
```

- 功能：布尔转字符串。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| val  | 布尔值 |

- 返回值：如果`val`为true返回`"true"`，否则返回`"false"`。

---

#### str_to_char()

- 函数原型：

```c
char str_to_char(const str_t str);
```

- 功能：字符串转字符。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：如果`str`为NULL返回`'\0'`，否则返回`str`的第一个字符。

---

#### char_to_str()

- 函数原型：

```c
str_t char_to_str(char c, str_t str, int str_size);
```

- 功能：字符转字符串。
- 参数：

| 参数     | 说明                     |
| -------- | ------------------------ |
| c        | 字符                     |
| str      | 用于保存转换结果的字符串 |
| str_size | sizeof(str)              |

- 返回值：返回转换后的字符串。

> 调用者需要确保`str`和`str_size`的有效性。

---

#### str_to_int()

- 函数原型：

```c
int str_to_int(const str_t str);
```

- 功能：字符串转int。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：如果`str`为NULL返回`0`，否则返回`atoi()`的结果。

---

#### int_to_str()

- 函数原型：

```c
str_t int_to_str(int val, str_t str, int str_size);
```

- 功能：int转字符串。
- 参数：

| 参数     | 说明                     |
| -------- | ------------------------ |
| val      | int值                    |
| str      | 用于保存转换结果的字符串 |
| str_size | sizeof(str)              |

- 返回值：返回转换后的字符串。

> 调用者需要确保`str`和`str_size`的有效性。

---

#### str_to_double()

- 函数原型：

```c
double str_to_double(const str_t str);
```

- 功能：字符串转double。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：如果`str`为NULL返回`0`.0，否则返回`atof()`的结果。

---

#### double_to_str()

- 函数原型：

```c
str_t double_to_str(double val, int precision, str_t str, int str_size);
```

- 功能：double转字符串。
- 参数：

| 参数      | 说明                                        |
| --------- | ------------------------------------------- |
| val       | double值                                    |
| precision | 四舍五入小数点后保留位数，默认为2，最大为16 |
| str       | 用于保存转换结果的字符串                    |
| str_size  | sizeof(str)                                 |

- 返回值：返回转换后的字符串。

> 调用者需要确保`str`和`str_size`的有效性。

<div style="page-break-after: always;"></div>

### 字符串操作

#### str_equal()

- 函数原型：

```c
bool str_equal(const str_t s1, const str_t s2);
```

- 功能：判断字符串是否相等。
- 参数：

| 参数 | 说明    |
| ---- | ------- |
| s1   | 字符串1 |
| s2   | 字符串2 |

- 返回值：字符串相等返回`true`，不相等返回`false`。

---

#### str_equal_ignore_case()

- 函数原型：

```c
bool str_equal_ignore_case(const str_t s1, const str_t s2);
```

- 功能：忽略大小写判断字符串是否相等。
- 参数：

| 参数 | 说明    |
| ---- | ------- |
| s1   | 字符串1 |
| s2   | 字符串2 |

- 返回值：字符串忽略大小写相等返回`true`，不相等返回`false`。

---

#### str_to_lower()

- 函数原型：

```c
str_t str_to_lower(str_t str);
```

- 功能：字符串转小写。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：小写字符串。

---

#### str_to_upper()

- 函数原型：

```c
str_t str_to_upper(str_t str);
```

- 功能：字符串转大写。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：大写字符串。

---

#### str_starts_with()

- 函数原型：

```c
bool str_starts_with(const str_t str, const str_t prefix);
```

- 功能：判断字符串是否以指定子串开头。
- 参数：

| 参数   | 说明   |
| ------ | ------ |
| str    | 字符串 |
| prefix | 子串   |

- 返回值：如果`str`以`prefix`开头返回`true`，否则返回`false`。

---

#### str_ends_with()

- 函数原型：

```c
bool str_ends_with(const str_t str, const str_t postfix);
```

- 功能：判断字符串是否以指定子串结尾。
- 参数：

| 参数    | 说明   |
| ------- | ------ |
| str     | 字符串 |
| postfix | 子串   |

- 返回值：如果`str`以`postfix`结尾返回`true`，否则返回`false`。

---

#### str_clear()

- 函数原型：

```c
void str_clear(str_t str, int str_size);
```

- 功能：清空字符串。
- 参数：

| 参数     | 说明        |
| -------- | ----------- |
| str      | 字符串      |
| str_size | sizeof(str) |

> 调用者需要确保`str`和`str_size`的有效性。

---

#### str_length()

- 函数原型：

```c
int str_length(const str_t str);
```

- 功能：获取字符串长度。
- 参数：

| 参数    | 说明   |
| ------- | ------ |
| str     | 字符串 |

- 返回值：返回`str`长度，如果`str`为NULL返回`0`。

---

#### str_copy()

- 函数原型：

```c
str_t str_copy(str_t destination, const str_t source);
```

- 功能：字符串拷贝。
- 参数：

| 参数        | 说明       |
| ----------- | ---------- |
| destination | 目标字符串 |
| source      | 源字符串   |

- 返回值：返回目标字符串。

> 调用者需要确保`destination`和`source`的有效性。

---

#### str_concat()

- 函数原型：

```c
str_t str_concat(str_t destination, const str_t source);
```

- 功能：字符串拼接。
- 参数：

| 参数        | 说明       |
| ----------- | ---------- |
| destination | 目标字符串 |
| source      | 源字符串   |

- 返回值：返回目标字符串。

> 调用者需要确保`destination`和`source`的有效性。

---

#### str_trim()

- 函数原型：

```c
str_t str_trim(str_t str);
```

- 功能：删除字符串首尾空白字符。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |

- 返回值：返回删除首尾空白字符后的字符串。

---

#### str_append_char()

- 函数原型：

```c
str_t str_append_char(str_t str, char c);
```

- 功能：字符串追加字符。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |
| c    | 字符   |

- 返回值：修改后的字符串。

> 调用者需要确保`str`的有效性。

---

#### str_append_int()

- 函数原型：

```c
str_t str_append_int(str_t str, int val);
```

- 功能：字符串追加int。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |
| val  | int值  |

- 返回值：修改后的字符串。

> 调用者需要确保`str`的有效性。

---

#### str_append_double()

- 函数原型：

```c
str_t str_append_double(str_t str, double val, int precision);
```

- 功能：字符串追加double。
- 参数：

| 参数      | 说明                                        |
| --------- | ------------------------------------------- |
| str       | 字符串                                      |
| val       | double值                                    |
| precision | 四舍五入小数点后保留位数，默认为2，最大为16 |

- 返回值：修改后的字符串。

> 调用者需要确保`str`的有效性。

---

#### str_insert_char()

- 函数原型：

```c
str_t str_insert_char(str_t str, int index, char c);
```

- 功能：字符串插入字符。
- 参数：

| 参数  | 说明     |
| ----- | -------- |
| str   | 字符串   |
| index | 插入位置 |
| c     | 字符     |

- 返回值：修改后的字符串。

> 调用者需要确保`str`的有效性。

---

#### str_insert_string()

- 函数原型：

```c
str_t str_insert_string(str_t str, int index, const str_t substr);
```

- 功能：字符串插入字符串。
- 参数：

| 参数   | 说明       |
| ------ | ---------- |
| str    | 字符串     |
| index  | 插入位置   |
| substr | 插入字符串 |

- 返回值：修改后的字符串。

> 调用者需要确保`str`的有效性。

---

#### str_substring()

- 函数原型：

```c
str_t str_substring(str_t str, int start, int end, str_t substr, int substr_size);
```

- 功能：截取指定范围子串。
- 参数：

| 参数        | 说明                 |
| ----------- | -------------------- |
| str         | 字符串               |
| start       | 开始位置             |
| end         | 结束位置             |
| substr      | 用于保存子串的字符串 |
| substr_size | sizeof(substr_size)  |

- 返回值：修改后的字符串。

> 调用者需要确保`substr`和`substr_size`的有效性。

---

#### str_count_substring()

- 函数原型：

```c
int str_count_substring(const str_t str, const str_t substr);
```

- 功能：计算子串出现次数。
- 参数：

| 参数        | 说明                 |
| ----------- | -------------------- |
| str         | 字符串               |
| substr      | 子串 |

- 返回值：子串出现次数。

---

#### str_replace_char()

- 函数原型：

```c
str_t str_replace_char(str_t str, char old_char, char new_char);
```

- 功能：替换字符串中所有指定字符。
- 参数：

| 参数     | 说明   |
| -------- | ------ |
| str      | 字符串 |
| old_char | 旧字符 |
| new_char | 新字符 |

- 返回值：修改后的字符串。

---

#### str_replace()

- 函数原型：

```c
str_t str_replace(str_t str, const str_t old_str, const str_t new_str);
```

- 功能：替换字符串中所有指定子串。
- 参数：

| 参数    | 说明     |
| ------- | -------- |
| str     | 字符串   |
| old_str | 旧字符串 |
| new_str | 新字符串 |

- 返回值：修改后的字符串。

---

#### str_remove()

- 函数原型：

```c
str_t str_remove(str_t str, const str_t substr);
```

- 功能：删除字符串中所有指定子串。
- 参数：

| 参数   | 说明       |
| ------ | ---------- |
| str    | 字符串     |
| substr | 需删除子串 |

- 返回值：修改后的字符串。

---

#### str_index_of_char()

- 函数原型：

```c
int str_index_of_char(const str_t str, char c);
```

- 功能：查找字符串中指定字符首次出现下标。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |
| c    | 字符   |

- 返回值：指定字符首次出现下标。

---

#### str_index_of_char_from()

- 函数原型：

```c
int str_index_of_char_from(const str_t str, char c, int from);
```

- 功能：查找字符串中指定字符从指定位置开始首次出现下标。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| str  | 字符串   |
| c    | 字符     |
| from | 开始位置 |

- 返回值：指定字符从指定位置开始首次出现下标。

---

#### str_index_of_substring()

- 函数原型：

```c
int str_index_of_substring(const str_t str, const str_t substr);
```

- 功能：查找字符串中指定子串首次出现下标。
- 参数：

| 参数   | 说明   |
| ------ | ------ |
| str    | 字符串 |
| substr | 子串   |

- 返回值：指定子串首次出现下标。

---

#### str_index_of_substring_from()

- 函数原型：

```c
int str_index_of_substring_from(const str_t str, const str_t substr, int from);
```

- 功能：查找字符串中指定子串从指定位置开始首次出现下标。
- 参数：

| 参数   | 说明     |
| ------ | -------- |
| str    | 字符串   |
| substr | 子串     |
| from   | 开始位置 |

- 返回值：指定子串从指定位置开始首次出现下标。

---

#### str_last_index_of_char()

- 函数原型：

```c
int str_last_index_of_char(const str_t str, char c);
```

- 功能：查找字符串中指定字符最后一次出现下标。
- 参数：

| 参数 | 说明   |
| ---- | ------ |
| str  | 字符串 |
| c    | 字符   |

- 返回值：指定字符最后一次出现下标。

---

#### str_last_index_of_char_from()

- 函数原型：

```c
int str_last_index_of_char_from(const str_t str, char c, int from);
```

- 功能：查找字符串中指定字符从指定位置向前最后一次出现下标。
- 参数：

| 参数 | 说明     |
| ---- | -------- |
| str  | 字符串   |
| c    | 字符     |
| from | 开始位置 |

- 返回值：指定字符从指定位置向前最后一次出现下标。

---

#### str_last_index_of_substring()

- 函数原型：

```c
int str_last_index_of_substring(const str_t str, const str_t substr);
```

- 功能：查找字符串中指定子串最后一次出现下标。
- 参数：

| 参数   | 说明   |
| ------ | ------ |
| str    | 字符串 |
| substr | 子串   |

- 返回值：指定子串最后一次出现下标。

---

#### str_last_index_of_substring_from()

- 函数原型：

```c
int str_last_index_of_substring_from(const str_t str, const str_t substr, int from);
```

- 功能：查找字符串中指定子串从指定位置向前最后一次出现下标。
- 参数：

| 参数   | 说明     |
| ------ | -------- |
| str    | 字符串   |
| substr | 子串     |
| from   | 开始位置 |

- 返回值：指定子串从指定位置向前最后一次出现下标。

---

#### str_split()

- 函数原型：

```c
int str_split(const str_t str, const str_t delimiter, str_t *items);
```

- 功能：字符串分割。
- 参数：

| 参数      | 说明                     |
| --------- | ------------------------ |
| str       | 字符串                   |
| delimiter | 分隔符                   |
| items     | 用于保存子串的字符串数组 |

- 返回值：分割次数。

> 调用者需要确保`items`的有效性。