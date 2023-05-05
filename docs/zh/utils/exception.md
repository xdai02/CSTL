# exception

[TOC]



## return_if()

- 原型

```c
return_if(expr)
```

- 描述
    - 当`expr`为`true`时，立即从当前函数返回。常用于检查函数执行的条件。
- 参数
    - `expr`: 需要判断的表达式。
- 用例

```c
void array_print(int *arr, int n) {
    return_if(arr == NULL);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```



## return_if_fail()

- 原型

```c
return_if_fail(expr)
```

- 描述
    - 当`expr`为`false`时，立即从当前函数返回。常用于检查函数执行的条件。
- 参数
    - `expr`: 需要判断的表达式。
- 用例

```c
void array_print(int *arr, int n) {
    return_if_fail(n >= 0);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```



## return_value_if()

- 原型

```c
return_value_if(expr, ret)
```

- 描述
    - 当`expr`为`true`时，立即从当前函数返回指定值。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
    - `ret`：返回值。
- 用例

```c
char *str_clear(char *str) {
    return_value_if(str == NULL, NULL);
    str[0] = '\0';
    return str;
}
```



## return_value_if_fail()

- 原型

```c
return_value_if_fail(expr, ret)
```

- 描述
    - 当`expr`为`false`时，立即从当前函数返回指定值。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
    - `ret`：返回值。
- 用例

```c
char *str_clear(char *str) {
    return_value_if_fail(str != NULL, NULL);
    str[0] = '\0';
    return str;
}
```



## exit_if()

- 原型

```c
exit_if(expr)
```

- 描述
    - 当`expr`为`true`时，立即以`EXIT_FAILURE`状态终止程序。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
- 用例

```c
float divide(int a, int b) {
    exit_if(b == 0);
    return (float)a / (float)b;
}
```



## exit_if_fail()

- 原型

```c
exit_if_fail(expr)
```

- 描述
    - 当`expr`为`false`时，立即以`EXIT_FAILURE`状态终止程序。常用于检查函数执行的条件。
- 参数
    - `expr`：需要判断的表达式。
- 用例

```c
float divide(int a, int b) {
    exit_if_fail(b != 0);
    return (float)a / (float)b;
}
```

