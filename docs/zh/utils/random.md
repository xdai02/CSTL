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



## random()

- 原型

```c
double random();
```

- 描述
    - 生成0至1（包含）范围的随机浮点数。
- 返回值
    - 返回0至1（包含）范围的随机浮点数。
- 用例

```c
printf("%f\n", random());
```


