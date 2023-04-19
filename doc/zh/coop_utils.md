# coop_utils

[TOC]



## float_equal()

- 原型

```c
bool float_equal(float f1, float f2)
```

- 描述
    - 在一定的容差范围内比较两个浮点数是否相等。
- 参数
    - f1：要比较的第一个浮点数。
    - f2：要比较的第二个浮点数。
- 返回值
    - 如果`f1`和`f2`之间的绝对差小于`FLT_EPSILON`，则返回`true`，否则返回`false`。



## double_equal()

- 原型

```c
bool double_equal(double d1, double d2)
```

- 描述
    - 在一定的容差范围内比较两个双精度浮点数是否相等。
- 参数
    - d1：要比较的第一个双精度数。
    - d2：要比较的第二个双精度数。
- 返回值
    - 如果`d1`和`d2`之间的绝对差小于`DBL_EPSILON`，则返回`true`，否则返回`false`。



## long_double_equal()

- 原型

```c
bool long_double_equal(long double ld1, long double ld2)
```

- 描述
    - 在一定的容差范围内比较两个长双精度浮点数是否相等。
- 参数
    - ld1：要比较的第一个长双精度数。
    - ld2：要比较的第二个长双精度数。
- 返回值
    - 如果`ld1`和`ld2`之间的绝对差小于`LDBL_EPSILON`，则返回`true`，否则返回`false`。 