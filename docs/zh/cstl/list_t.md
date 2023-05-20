# list_t

[TOC]



## list_new()

- 原型

```c
list_t *list_new(compare_t compare, destroy_t destroy);
```

- 描述
    - 创建`list_t`对象。
- 参数
    - `compare`：用于比较两个元素的回调函数。
    - `destroy`：用于销毁元素的回调函数。
- 返回值
    - 如果成功返回`list_t`，否则返回`NULL`。
- 用例

```c
// Create an integer linked list using Integer wrapper
list_t *list1 = list_new(Integer_compare, Integer_delete);

// Create a double linked list using Double wrapper
list_t *list2 = list_new(Double_compare, Double_delete);

// Create a boolean linked list using Boolean wrapper
list_t *list3 = list_new(Boolean_compare, Boolean_delete);

// Create a character linked list using Character wrapper
list_t *list4 = list_new(Character_compare, Character_delete);
```

```c
typedef struct {
    char name[32];
    int age;
} Employee;

// Callback function for comparing two employees
int Employee_compare(const void *ptr1, const void *ptr2) {
    Employee *e1 = (Employee *)ptr1;
    Employee *e2 = (Employee *)ptr2;
    return e1->age - e2->age;
}

// Callback function for destroying an employee
void Employee_delete(void *ptr) {
    Employee *e = (Employee *)ptr;
    free(e);
}

// Create a list of employees
list_t *employees = list_new(Employee_compare, Employee_delete);

// ...
```



## list_delete()

- 原型

```c
void list_delete(list_t *list);
```

- 描述
    - 销毁`list_t`对象。
- 参数
    - `list`：`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);
list_delete(list);
```



## list_is_empty()

- 原型

```c
bool list_is_empty(const list_t *list);
```

- 描述
    - 判断`list_t`对象是否为空。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 如果`list_t`对象为空返回`true`，否则返回`false`。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);
if (list_is_empty(list)) {
    // ...
}
list_delete(list);
```



## list_size()

- 原型

```c
size_t list_size(const list_t *list);
```

- 描述
    - 获取`list_t`对象的大小。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回`list_t`对象的大小。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);
printf("%d\n", list_size(list));
list_delete(list);
```



## list_foreach()

- 原型

```c
void list_foreach(list_t *list, visit_t visit);
```

- 描述
    - 遍历`list_t`对象。
- 参数
    - `list`：`list_t`对象。
    - `visit`：用于访问元素的回调函数。
- 用例

```c
// Callback function for printing an integer
void Integer_print(T elem) {
    Integer *integer = (Integer *)elem;
    printf("%d ", Integer_get(integer));
}

// Callback function for tripling an integer
void Integer_triple(T elem) {
    Integer *integer = (Integer *)elem;
    Integer_set(integer, Integer_get(integer) * 3);
}

int main() {
    // Create a list of integers
    list_t *list = list_new(Integer_compare, Integer_delete);

    for (int i = 0; i < 10; i++) {
        // Add the integer object to the list
        list_push_back(list, Integer_new(i));
    }

    // Print the list
    list_foreach(list, Integer_print);
    printf("\n");

    // Triple the integers in the list
    list_foreach(list, Integer_triple);

    // Print the list_
    list_foreach(list, Integer_print);
    printf("\n");

    // Destroy the list
    list_delete(list);

    return 0;
}
```



## list_clear()

- 原型

```c
list_t *list_clear(list_t *list);
```

- 描述
    - 清空`list_t`对象。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_clear(list);
list_delete(list);
```



## list_get()

- 原型

```c
T list_get(const list_t *list, size_t index);
```

- 描述
    - 获取`list_t`对象指定下标的元素。
- 参数
    - `list`：`list_t`对象。
    - `index`：下标。
- 返回值
    - 返回`list_t`对象指定下标的元素。
- 用例

```c
list_t *list= list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get(list, 5);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_set()

- 原型

```c
list_t *list_set(list_t *list, size_t index, T elem);
```

- 描述
    - 设置`list_t`对象指定下标的元素。
- 参数
    - `list`：`list_t`对象。
    - `index`：下标。
    - `elem`：元素。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_set(list, 5, Integer_new(50));
list_delete(list);
```



## list_index_of()

- 原型

```c
int list_index_of(const list_t *list, T elem);
```

- 描述
    - 获取`list_t`对象指定元素的下标。
- 参数
    - `list`：`list_t`对象。
    - `elem`：元素。
- 返回值
    - 返回`list_t`对象指定元素的下标，找不到返回`-1`。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *target = Integer_new(5);
printf("%d\n", list_index_of(list, target));
Integer_delete(target);

list_delete(list);
```



## list_contains()

- 原型

```c
bool list_contains(const list_t *list, T elem);
```

- 描述
    - 判断`list_t`对象是否包含指定元素。
- 参数
    - `list`：`list_t`对象。
    - `elem`：元素。
- 返回值
    - 如果`list_t`对象包含指定元素返回`true`，否则返回`false`。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *target = Integer_new(5);
if (list_contains(list, target)) {
    // ...
}
Integer_delete(target);

list_delete(list);
```



## list_count()

- 原型

```c
size_t list_count(const list_t *list, T elem);
```

- 描述
    - 计算`list_t`对象中指定元素出现次数。
- 参数
    - `list`：`list_t`对象。
    - `elem`：元素。
- 返回值
    - 返回`list_t`对象中指定元素出现次数。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

list_push_back(list, Integer_new(1));
list_push_back(list, Integer_new(2));
list_push_back(list, Integer_new(2));
list_push_back(list, Integer_new(3));
list_push_back(list, Integer_new(2));

Integer *target = Integer_new(2);
printf("%d\n", list_count(list, target));
Integer_delete(target);

list_delete(list);
```



## list_get_front()

- 原型

```c
T list_get_front(const list_t *list);
```

- 描述
    - 获取`list_t`对象的第一个元素。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回第一个元素，失败返回`NULL`。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get_front(list);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_get_back()

- 原型

```c
T list_get_back(const list_t *list);
```

- 描述
    - 获取`list_t`对象的最后一个元素。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回最后一个元素，失败返回`NULL`。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *integer = (Integer *)list_get_back(list);
printf("%d\n", Integer_get(integer));

list_delete(list);
```



## list_push_front()

- 原型

```c
list_t *list_push_front(list_t *list, T elem);
```

- 描述
    - 在`list_t`对象开头插入一个元素。
- 参数
    - `list`：`list_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_front(list, Integer_new(i));
}

list_delete(list);
```



## list_push_back()

- 原型

```c
list_t *list_push_back(list_t *list, T elem);
```

- 描述
    - 在`list_t`对象最后插入一个元素。
- 参数
    - `list`：`list_t`对象。
    - `elem`：元素。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_delete(list);
```



## list_pop_front()

- 原型

```c
T list_pop_front(list_t *list);
```

- 描述
    - 删除`list_t`对象的第一个元素。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回被删除的元素，失败返回`NULL`。
- 注意
    - 调用者**必须**释放返回元素（如适用）。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_pop_front(list);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_pop_back()

- 原型

```c
T list_pop_back(list_t *list);
```

- 描述
    - 删除`list_t`对象的最后一个元素。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回被删除的元素，失败返回`NULL`。
- 注意
    - 调用者**必须**释放返回元素（如适用）。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_pop_back(list);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_insert()

- 原型

```c
list_t *list_insert(list_t *list, size_t index, T elem);
```

- 描述
    - 在`list_t`对象指定下标插入元素。
- 参数
    - `list`：`list_t`对象。
    - `index`：下标。
    - `elem`：元素。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);
list_insert(list, 0, Integer_new(1));
list_insert(list, 1, Integer_new(2));
list_insert(list, 0, Integer_new(3));
list_insert(list, 2, Integer_new(4));
list_delete(list);
```



## list_remove()

- 原型

```c
T list_remove(list_t *list, size_t index);
```

- 描述
    - 删除`list_t`对象指定下标的元素。
- 参数
    - `list`：`list_t`对象。
    - `index`：下标。
- 返回值
    - 返回修改后的`list_t`对象。
- 注意
    - 调用者**必须**释放返回元素（如适用）。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

Integer *value = list_remove(list, 5);
printf("%d\n", Integer_get(value));
Integer_delete(value);

list_delete(list);
```



## list_reverse()

- 原型

```c
list_t *list_reverse(list_t *list);
```

- 描述
    - 反转`list_t`对象。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回修改后的`list_t`对象。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);

for (int i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

list_reverse(list);
list_delete(list);
```



## list_iterator_new()

- 原型

```c
iterator_t *list_iterator_new(const list_t *list);
```

- 描述
    - 创建`list_t`对象的迭代器。
- 参数
    - `list`：`list_t`对象。
- 返回值
    - 返回容器的迭代器。



## list_iterator_delete()

- 原型

```c
void list_iterator_delete(iterator_t *iterator);
```

- 描述
    - 销毁迭代器。
- 参数
    - `iterator`：`iterator_t`对象。



## list_iterator_has_next()

- 原型

```c
bool list_iterator_has_next(const iterator_t *iterator);
```

- 描述
    - 判断迭代器是否存在下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 如果迭代器存在下一个元素返回`true`，否则返回`false`。



## list_iterator_next()

- 原型

```c
T list_iterator_next(iterator_t *iterator);
```

- 描述
    - 获取迭代器下一个元素。
- 参数
    - `iterator`：`iterator_t`对象。
- 返回值
    - 返回迭代器下一个元素。
- 用例

```c
list_t *list = list_new(Integer_compare, Integer_delete);
for (i = 0; i < 10; i++) {
    list_push_back(list, Integer_new(i));
}

iterator_t *iterator = list_iterator_new(list);
while (list_iterator_has_next(iterator)) {
    Integer *integer = (Integer *)list_iterator_next(iterator);
    printf("%d ", Integer_get(integer));
}

list_iterator_delete(iterator);
list_delete(list);
```

