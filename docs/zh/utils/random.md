# random

[TOC]



## randint()

- 原型

```c
int randint(int min, int max);
```

- 描述
    - 生成`min`至`max`范围的随机整数。
- 参数
    - `min`：随机整数的下限（包含）。
    - `max`：随机整数的上限（包含）。
- 返回值
    - 随机整数。
- 用例

```c
printf("%d\n", randint(1, 100));
```



## uniform()

- 原型

```c
double uniform(double min, double max);
```

- 描述
    - 生成`min`至`max`范围的随机浮点数。
- 参数
    - `min`：随机浮点数的下限（包含）。
    - `max`：随机浮点数的上限（包含）。
- 返回值
    - 随机浮点数。
- 用例

```c
printf("%f\n", uniform(0, 1));
```



## shuffle()

- 原型

```c
shuffle(array, n, type)
```

- 描述
    - 随机打乱数组。
- Parameters
    - `array`：待打乱数组。
    - `n`：数组长度。
    - `type`：数组类型。
- 用例

```c
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);
shuffle(arr, n, int);
```

