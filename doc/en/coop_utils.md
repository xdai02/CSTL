# coop_utils

[TOC]



## float_equal()

- Prototype

```c
bool float_equal(float f1, float f2)
```

- Description
    - Compares two floating point numbers for equality within a certain tolerance.
- Parameters
    - f1: The first float number to be compared.
    - f2: The second float number to be compared.
- Return
    - Returns `true` if the absolute difference between `f1` and `f2` is less than `FLT_EPSILON`, `false` otherwise.



## double_equal()

- Prototype

```c
bool double_equal(double d1, double d2)
```

- Description
    - Compares two double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - d1: The first double number to be compared.
    - d2: The second double number to be compared.
- Return
    - Returns `true` if the absolute difference between `d1` and `d2` is less than `DBL_EPSILON`, `false` otherwise.



## long_double_equal()

- Prototype

```c
bool long_double_equal(long double ld1, long double ld2)
```

- Description
    - Compares two long double precision floating point numbers for equality within a certain tolerance.
- Parameters
    - ld1: The first long double number to be compared.
    - ld2: The second long double number to be compared.
- Return
    - Returns `true` if the absolute difference between `ld1` and `ld2` is less than `LDBL_EPSILON`, `false` otherwise.