## cino_array

- 模块功能：
    - array_int_t：提供int类型动态数组操作。
    - array_double_t：提供double类型动态数组操作。
    - array_t：提供通用类型动态数组操作。
- 类别：

[TOC]

<div style="page-break-after: always;"></div>

### array_int_t

#### array_int_create()

- 函数原型：

```c
array_int_t *array_int_create();
```

- 功能：创建cino-int-array。

- 返回值：返回cino-int-array指针，创建失败返回`NULL`。

---

#### array_int_destroy()

- 函数原型：

```c
void array_int_destroy(array_int_t *array);
```

- 功能：销毁cino-int-array。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

---

#### array_int_is_empty()

- 函数原型：

```c
bool array_int_is_empty(const array_int_t *array);
```

- 功能：判断cino-int-array是否为空。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：cino-int-array为空返回`true`，不为空返回`false`。

---

#### array_int_size()

- 函数原型：

```c
size_t array_int_size(const array_int_t *array);
```

- 功能：获取cino-int-array元素个数。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：cino-int-array元素个数。

---

#### array_int_clear()

- 函数原型：

```c
array_int_t *array_int_clear(array_int_t *array);
```

- 功能：清空cino-int-array。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：修改后的cino-int-array。

---

#### array_int_get()

- 函数原型：

```c
int array_int_get(const array_int_t *array, int index);
```

- 功能：获取cino-int-array指定下标元素。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| index | 下标           |

- 返回值：返回cino-int-array指定下标元素。

---

#### array_int_set()

- 函数原型：

```c
void array_int_set(array_int_t *array, int index, int data);
```

- 功能：设置cino-int-array指定下标元素。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| index | 下标           |
| data  | 新元素         |

---

#### array_int_append()

- 函数原型：

```c
array_int_t *array_int_append(array_int_t *array, int data);
```

- 功能：cino-int-array追加元素。
- 参数：

| 参数   | 说明        |
| ----- | -------------- |
| array | cino-int-array |
| data  | 新元素         |

- 返回值：修改后的cino-int-array。

---

#### array_int_extend()

- 函数原型：

```c
array_int_t *array_int_extend(array_int_t *array, int *arr, int arr_len);
```

- 功能：cino-int-array追加数组。
- 参数：

| 参数    | 说明           |
| ------- | -------------- |
| array   | cino-int-array |
| arr     | 数组           |
| arr_len | 数组元素个数   |

- 返回值：修改后的cino-int-array。

---

#### array_int_insert()

- 函数原型：

```c
array_int_t *array_int_insert(array_int_t *array, int index, int data);
```

- 功能：cino-int-array插入元素。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| index | 插入位置       |
| data  | 新元素         |

- 返回值：修改后的cino-int-array。

---

#### array_int_remove()

- 函数原型：

```c
array_int_t *array_int_remove(array_int_t *array, int index);
```

- 功能：删除cino-int-array中指定下标元素。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| index | 删除位置       |

- 返回值：修改后的cino-int-array。

---

#### array_int_min()

- 函数原型：

```c
int array_int_min(const array_int_t *array);
```

- 功能：获取cino-int-array最小值。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：cino-int-array最小值。

---

#### array_int_max()

- 函数原型：

```c
int array_int_max(const array_int_t *array);
```

- 功能：获取cino-int-array最大值。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：cino-int-array最大值。

---

#### array_int_index_of()

- 函数原型：

```c
int array_int_index_of(const array_int_t *array, int data);
```

- 功能：获取cino-int-array指定元素首次出现下标。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| data  | 查询元素       |

- 返回值：cino-int-array指定元素首次出现下标。

---

#### array_int_last_index_of()

- 函数原型：

```c
int array_int_last_index_of(const array_int_t *array, int data);
```

- 功能：获取cino-int-array指定元素最后一次出现下标。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| data  | 查询元素       |

- 返回值：cino-int-array指定元素最后一次出现下标。

---

#### array_int_count()

- 函数原型：

```c
int array_int_count(const array_int_t *array, int data);
```

- 功能：统计cino-int-array指定元素出现次数。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |
| data  | 查询元素       |

- 返回值：指定元素出现次数。

---

#### array_int_reverse()

- 函数原型：

```c
array_int_t *array_int_reverse(array_int_t *array);
```

- 功能：反转cino-int-array。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：修改后的cino-int-array。

---

#### array_int_swap()

- 函数原型：

```c
array_int_t *array_int_swap(array_int_t *array, int index1, int index2);
```

- 功能：交换cino-int-array指定下标元素。
- 参数：

| 参数   | 说明           |
| ------ | -------------- |
| array  | cino-int-array |
| index1 | 下标1          |
| index2 | 下标2          |

- 返回值：修改后的cino-int-array。

---

#### array_int_sort()

- 函数原型：

```c
array_int_t *array_int_sort(array_int_t *array, bool reverse);
```

- 功能：cino-int-array排序。
- 参数：

| 参数    | 说明           |
| ------- | -------------- |
| array   | cino-int-array |
| reverse | 是否逆序       |

- 返回值：修改后的cino-int-array。

---

#### array_int_iter()

- 函数原型：

```c
iter_t array_int_iter(array_int_t *array);
```

- 功能：获取cino-int-array的迭代器。
- 参数：

| 参数    | 说明           |
| ------- | -------------- |
| array   | cino-int-array |

- 返回值：迭代器。

---

#### array_int_iter_has_next()

- 函数原型：

```c
bool array_int_iter_has_next(const array_int_t *array);
```

- 功能：判断是否存在下一个迭代器。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：如果存在下一个迭代器返回`true`，不存在返回`false`。

---

#### array_int_iter_next()

- 函数原型：

```c
iter_t array_int_iter_next(array_int_t *array);
```

- 功能：获取下一个迭代器。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-int-array |

- 返回值：下一个迭代器。

<div style="page-break-after: always;"></div>

### array_double_t

#### array_double_create()

- 函数原型：

```c
array_double_t *array_double_create();
```

- 功能：创建cino-double-array。

- 返回值：返回cino-double-array指针，创建失败返回`NULL`。

---

#### array_double_destroy()

- 函数原型：

```c
void array_double_destroy(array_double_t *array);
```

- 功能：销毁cino-double-array。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

---

#### array_double_is_empty()

- 函数原型：

```c
bool array_double_is_empty(const array_double_t *array);
```

- 功能：判断cino-double-array是否为空。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：cino-double-array为空返回`true`，不为空返回`false`。

---

#### array_double_size()

- 函数原型：

```c
size_t array_double_size(const array_double_t *array);
```

- 功能：获取cino-double-array元素个数。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：cino-double-array元素个数。

---

#### array_double_clear()

- 函数原型：

```c
array_double_t *array_double_clear(array_double_t *array);
```

- 功能：清空cino-double-array。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：修改后的cino-double-array。

---

#### array_double_get()

- 函数原型：

```c
double array_double_get(const array_double_t *array, int index);
```

- 功能：获取cino-double-array指定下标元素。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| index | 下标              |

- 返回值：返回cino-double-array指定下标元素。

---

#### array_double_set()

- 函数原型：

```c
void array_double_set(array_double_t *array, int index, double data);
```

- 功能：设置cino-double-array指定下标元素。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| index | 下标              |
| data  | 新元素            |

---

#### array_double_append()

- 函数原型：

```c
array_double_t *array_double_append(array_double_t *array, double data);
```

- 功能：cino-double-array追加元素。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| data  | 新元素            |

- 返回值：修改后的cino-double-array。

---

#### array_double_extend()

- 函数原型：

```c
array_double_t *array_double_extend(array_double_t *array, double *arr, int arr_len);
```

- 功能：cino-double-array追加数组。
- 参数：

| 参数    | 说明              |
| ------- | ----------------- |
| array   | cino-double-array |
| arr     | 数组              |
| arr_len | 数组元素个数      |

- 返回值：修改后的cino-double-array。

---

#### array_double_insert()

- 函数原型：

```c
array_double_t *array_double_insert(array_double_t *array, int index, double data);
```

- 功能：cino-double-array插入元素。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| index | 插入位置          |
| data  | 新元素            |

- 返回值：修改后的cino-double-array。

---

#### array_double_remove()

- 函数原型：

```c
array_double_t *array_double_remove(array_double_t *array, int index);
```

- 功能：删除cino-double-array中指定下标元素。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| index | 删除位置          |

- 返回值：修改后的cino-double-array。

---

#### array_double_min()

- 函数原型：

```c
double array_double_min(const array_double_t *array);
```

- 功能：获取cino-double-array最小值。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：cino-double-array最小值。

---

#### array_double_max()

- 函数原型：

```c
double array_double_max(const array_double_t *array);
```

- 功能：获取cino-double-array最大值。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：cino-double-array最大值。

---

#### array_double_index_of()

- 函数原型：

```c
int array_double_index_of(const array_double_t *array, double data);
```

- 功能：获取cino-double-array指定元素首次出现下标。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| data  | 查询元素          |

- 返回值：cino-double-array指定元素首次出现下标。

---

#### array_double_last_index_of()

- 函数原型：

```c
int array_double_last_index_of(const array_double_t *array, double data);
```

- 功能：获取cino-double-array指定元素最后一次出现下标。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| data  | 查询元素          |

- 返回值：cino-double-array指定元素最后一次出现下标。

---

#### array_double_count()

- 函数原型：

```c
int array_double_count(const array_double_t *array, double data);
```

- 功能：统计cino-double-array指定元素出现次数。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |
| data  | 查询元素          |

- 返回值：指定元素出现次数。

---

#### array_double_reverse()

- 函数原型：

```c
array_double_t *array_double_reverse(array_double_t *array);
```

- 功能：反转cino-double-array。
- 参数：

| 参数  | 说明              |
| ----- | ----------------- |
| array | cino-double-array |

- 返回值：修改后的cino-double-array。

---

#### array_double_swap()

- 函数原型：

```c
array_double_t *array_double_swap(array_double_t *array, int index1, int index2);
```

- 功能：交换cino-double-array指定下标元素。
- 参数：

| 参数   | 说明              |
| ------ | ----------------- |
| array  | cino-double-array |
| index1 | 下标1             |
| index2 | 下标2             |

- 返回值：修改后的cino-double-array。

---

#### array_double_sort()

- 函数原型：

```c
array_double_t *array_double_sort(array_double_t *array, bool reverse);
```

- 功能：cino-double-array排序。
- 参数：

| 参数    | 说明              |
| ------- | ----------------- |
| array   | cino-double-array |
| reverse | 是否逆序          |

- 返回值：修改后的cino-double-array。

---

#### array_double_iter()

- 函数原型：

```c
iter_t array_double_iter(array_double_t *array);
```

- 功能：获取cino-double-array的迭代器。
- 参数：

| 参数    | 说明           |
| ------- | -------------- |
| array   | cino-double-array |

- 返回值：迭代器。

---

#### array_double_iter_has_next()

- 函数原型：

```c
bool array_double_iter_has_next(const array_double_t *array);
```

- 功能：判断是否存在下一个迭代器。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-double-array |

- 返回值：如果存在下一个迭代器返回`true`，不存在返回`false`。

---

#### array_double_iter_next()

- 函数原型：

```c
iter_t array_double_iter_next(array_double_t *array);
```

- 功能：获取下一个迭代器。
- 参数：

| 参数  | 说明           |
| ----- | -------------- |
| array | cino-double-array |

- 返回值：下一个迭代器。

<div style="page-break-after: always;"></div>

### array_t

#### array_create()

- 函数原型：

```c
array_t *array_create();
```

- 功能：创建cino-array。

- 返回值：返回cino-array指针，创建失败返回`NULL`。

---

#### array_destroy()

- 函数原型：

```c
void array_destroy(array_t *array);
```

- 功能：销毁cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

---

#### array_is_empty()

- 函数原型：

```c
bool array_is_empty(const array_t *array);
```

- 功能：判断cino-array是否为空。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：cino-array为空返回`true`，不为空返回`false`。

---

#### array_size()

- 函数原型：

```c
size_t array_size(const array_t *array);
```

- 功能：获取cino-array元素个数。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：cino-array元素个数。

---

#### array_clear()

- 函数原型：

```c
array_t *array_clear(array_t *array);
```

- 功能：清空cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：修改后的cino-array。

---

#### array_get()

- 函数原型：

```c
void *array_get(const array_t *array, int index);
```

- 功能：获取cino-array指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 下标       |

- 返回值：返回cino-array指定下标元素。

---

#### array_set()

- 函数原型：

```c
void array_set(array_t *array, int index, void *data);
```

- 功能：设置cino-array指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 下标       |
| data  | 新元素     |

---

#### array_append()

- 函数原型：

```c
array_t *array_append(array_t *array, void *data);
```

- 功能：cino-array追加元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| data  | 新元素     |

- 返回值：修改后的cino-array。

---

#### array_insert()

- 函数原型：

```c
array_t *array_insert(array_t *array, int index, void *data);
```

- 功能：cino-array插入元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 插入位置   |
| data  | 新元素     |

- 返回值：修改后的cino-array。

---

#### array_remove()

- 函数原型：

```c
array_t *array_remove(array_t *array, int index);
```

- 功能：删除cino-array中指定下标元素。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |
| index | 删除位置   |

- 返回值：修改后的cino-array。

---

#### array_min()

- 函数原型：

```c
void *array_min(const array_t *array, compare_t compare);
```

- 功能：获取cino-array最小值。
- 参数：

| 参数    | 说明         |
| ------- | ------------ |
| array   | cino-array   |
| compare | 比较函数接口 |

- 返回值：cino-array最小值。

---

#### array_max()

- 函数原型：

```c
void *array_max(const array_t *array, compare_t compare);
```

- 功能：获取cino-array最大值。
- 参数：

| 参数    | 说明         |
| ------- | ------------ |
| array   | cino-array   |
| compare | 比较函数接口 |

- 返回值：cino-array最大值。

---

#### array_find()

- 函数原型：

```c
void *array_find(const array_t *array, match_t match);
```

- 功能：在cino-array查询首个满足条件的元素。
- 参数：

| 参数  | 说明                 |
| ----- | -------------------- |
| array | cino-array           |
| match | 判断条件满足函数接口 |

- 返回值：返回首个满足条件的元素，未找到返回`NULL`。

---

#### array_count()

- 函数原型：

```c
int array_count(const array_t *array, match_t match);
```

- 功能：统计cino-array满足条件元素个数。
- 参数：

| 参数  | 说明                 |
| ----- | -------------------- |
| array | cino-array           |
| match | 判断条件满足函数接口 |

- 返回值：满足条件元素个数。

---

#### array_reverse()

- 函数原型：

```c
array_t *array_reverse(array_t *array);
```

- 功能：反转cino-array。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：修改后的cino-array。

---

#### array_swap()

- 函数原型：

```c
array_t *array_swap(array_t *array, int index1, int index2);
```

- 功能：交换cino-array指定下标元素。
- 参数：

| 参数   | 说明       |
| ------ | ---------- |
| array  | cino-array |
| index1 | 下标1      |
| index2 | 下标2      |

- 返回值：修改后的cino-array。

---

#### array_sort()

- 函数原型：

```c
array_t *array_sort(array_t *array, compare_t compare);
```

- 功能：cino-int-array排序。
- 参数：

| 参数    | 说明         |
| ------- | ------------ |
| array   | cino-array   |
| compare | 比较函数接口 |

- 返回值：修改后的cino-array。

---

#### array_iter()

- 函数原型：

```c
iter_t array_iter(array_t *array);
```

- 功能：获取cino-array的迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：迭代器。

---

#### array_iter_has_next()

- 函数原型：

```c
bool array_iter_has_next(const array_t *array);
```

- 功能：判断是否存在下一个迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：如果存在下一个迭代器返回`true`，不存在返回`false`。

---

#### array_iter_next()

- 函数原型：

```c
iter_t array_iter_next(array_t *array);
```

- 功能：获取下一个迭代器。
- 参数：

| 参数  | 说明       |
| ----- | ---------- |
| array | cino-array |

- 返回值：下一个迭代器。