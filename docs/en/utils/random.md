# random

[TOC]



## randint()

- Prototype

```c
int randint(int min, int max);
```

- Description
    - Generate a random integer between `min` and `max`.
- Parameters
    - `min`: The lower bound of the random number (inclusive).
    - `max`: The upper bound of the random number (inclusive).
- Return
    - The random integer.
- Usage

```c
printf("%d\n", randint(1, 100));
```



## uniform()

- Prototype

```c
double uniform(double min, double max);
```

- Description
    - Generate a random floating-point number between min and max.
- Parameters
    - `min`: The lower bound of the random number (inclusive).
    - `max`: The upper bound of the random number (inclusive).
- Return
    - The random floating-point number.
- Usage

```c
printf("%f\n", uniform(0, 1));
```
