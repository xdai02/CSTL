# exception

[TOC]



## return_if()

- Prototype

```c
return_if(expr)
```

- Description
    - Returns from the current function immediately if the given expression `expr` is `true`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

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

- Prototype

```c
return_if_fail(expr)
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



## return_value_if()

- Prototype

```c
return_value_if(expr, ret)
```

- Description
    - Returns the specific value from the current function immediately if the given expression `expr` is `true`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
    - `ret`: The value to be returned.
- Usage

```c
char *str_clear(char *str) {
    return_value_if(str == NULL, NULL);
    str[0] = '\0';
    return str;
}
```



## return_value_if_fail()

- Prototype

```c
return_value_if_fail(expr, ret)
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



## exit_if()

- Prototype

```c
exit_if(expr)
```

- Description
    - Terminates the program immediately with the `EXIT_FAILURE` status if the given expression `expr` is `true`. This is useful when you want to ensure that a certain condition is met before proceeding with the rest of the function.
- Parameters
    - `expr`: The expression to be evaluated.
- Usage

```c
float divide(int a, int b) {
    exit_if(b == 0);
    return (float)a / (float)b;
}
```



## exit_if_fail()

- Prototype

```c
exit_if_fail(expr)
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

