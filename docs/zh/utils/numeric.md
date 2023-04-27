# numeric

[TOC]



## min()

```c
#define min(x, y) (((x) < (y)) ? (x) : (y))
```

- 描述
    - 返回两数的较小值。
- 参数
    - `x`：第一个需要比较的数。
    - `y`：第二个需要比较的数。
- 返回值
    - 返回`x`和`y`的较小值。
- 用例

```c
printf("%d\n", min(5, 10));
```



## max()

```c
#define max(x, y) (((x) > (y)) ? (x) : (y))
```

- 描述
    - 返回两数的较大值。
- 参数
    - `x`：第一个需要比较的数。
    - `y`：第二个需要比较的数。
- 返回值
    - 返回`x`和`y`的较大值。
- 用例

```c
printf("%d\n", max(5, 10));
```



## swap()

```c
#define swap(x, y, type) \
    do {                 \
        type temp = (x); \
        (x) = (y);       \
        (y) = temp;      \
    } while (0)
```

- 描述
    - 交换两个给定类型的变量
- 参数
    - `x`：第一个需要交换的变量。
    - `y`：第二个需要交换的变量。
    - `type`: 所需交换的类型。
- 用例

```c
int x = 3;
int y = 5;
printf("Before: x = %d, y = %d\n", x, y);
swap(x, y, int);
printf("After: x = %d, y = %d\n", x, y);
```



## float_equal()

- 原型

```c
bool float_equal(float f1, float f2)
```

- 描述
    - 在一定的容差范围内比较两个浮点数是否相等。
- 参数
    - `f1`：要比较的第一个浮点数。
    - `f2`：要比较的第二个浮点数。
- 返回值
    - 如果`f1`和`f2`之间的绝对差小于`FLT_EPSILON`，则返回`true`，否则返回`false`。
- 用例

```c
float x = 3.14f;
if (float_equal(x, 3.14f)) {
    // ...
}
```



## double_equal()

- 原型

```c
bool double_equal(double d1, double d2)
```

- 描述
    - 在一定的容差范围内比较两个双精度浮点数是否相等。
- 参数
    - `d1`：要比较的第一个双精度数。
    - `d2`：要比较的第二个双精度数。
- 返回值
    - 如果`d1`和`d2`之间的绝对差小于`DBL_EPSILON`，则返回`true`，否则返回`false`。
- 用例

```c
double x = 3.14;
if (double_equal(x, 3.14)) {
    // ...
}
```


