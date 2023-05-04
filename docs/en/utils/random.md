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



## shuffle()

- Prototype

```c
shuffle(array, n, type)
```

- Description
    - Shuffle an array.
- Parameters
    - `array`: The array to be shuffled.
    - `n`: The length of the array.
    - `type`: The type of the array.
- Usage

```c
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);
shuffle(arr, n, int);
```

