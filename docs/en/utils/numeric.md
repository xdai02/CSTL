# numeric

[TOC]



## min()

```c
#define min(x, y) (((x) < (y)) ? (x) : (y))
```

- Description
    - Returns the minimum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the minimum of `x` and `y`.
- Usage

```c
printf("%d\n", min(5, 10));
```



## max()

```c
#define max(x, y) (((x) > (y)) ? (x) : (y))
```

- Description
    - Returns the maximum of two numbers.
- Parameters
    - `x`: The first number to be compared.
    - `y`: The second number to be compared.
- Return
    - Returns the maximum of `x` and `y`.
- Usage

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

- Description
    - Swaps the values of two variables with the given type.
- Parameters
    - `x`: The first variable to be swapped.
    - `y`: The second variable to be swapped.
    - `type`: The type of the variables to be swapped.
- Usage

```c
int x = 3;
int y = 5;
printf("Before: x = %d, y = %d\n", x, y);
swap(x, y, int);
printf("After: x = %d, y = %d\n", x, y);
```



## float_equal()

- Prototype

```c
bool float_equal(float f1, float f2);
```

- Description
    - Compares two floating point numbers for equality within a certain tolerance.
- Parameters
    - `f1`: The first float number to be compared.
    - `f2`: The second float number to be compared.
- Return
    - Returns `true` if the absolute difference between `f1` and `f2` is less than `FLT_EPSILON`, `false` otherwise.
- Usage

```c
float x = 3.14f;
if (float_equal(x, 3.14f)) {
    // ...
}
```



## double_equal()

- Prototype

```c
bool double_equal(double d1, double d2);
```

- Description
    - Compares two double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - `d1`: The first double number to be compared.
    - `d2`: The second double number to be compared.
- Return
    - Returns `true` if the absolute difference between `d1` and `d2` is less than `DBL_EPSILON`, `false` otherwise.
- Usage

```c
double x = 3.14;
if (double_equal(x, 3.14)) {
    // ...
}
```


