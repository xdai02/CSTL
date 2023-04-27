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



## random()

- Prototype

```c
double random();
```

- Description
    - Generate a random floating point number between 0 and 1 (both inclusive).
- Return
    - The random floating point number between 0 and 1 (both inclusive).
- Usage

```c
printf("%f\n", random());
```
