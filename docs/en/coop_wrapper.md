# coop_wrapper

[TOC]



## Character

### Character_new()

- Prototype

```c
Character *Character_new(char value);
```

- Description
    - Creates a new `Character` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Character` wrapper.



### Character_delete()

- Prototype

```c
void Character_delete(void *ptr);
```

- Description
    - Destroys the given `Character` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Character_valueOf()

- Prototype

```c
char Character_valueOf(const Character *character);
```

- Description
    - Returns the value of the given `Character` wrapper.
- Parameters
    - `character`: The pointer to the wrapper.
- Return
    - The primitive `char` value of the given wrapper.



### Character_equals()

- Prototype

```c
bool Character_equals(const Character *character1, const Character *character2);
```

- Description
    - Checks if two `Character` wrappers are equal.
- Parameters
    - `character1`: The pointer to the first wrapper to be compared.
    - `character2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `char` values of the two wrappers are equal, `false` otherwise.



### Character_compare()

- Prototype

```c
int Character_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Character` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Character *a = Character_new('A');
Character *b = Character_new('B');

printf("%c\n", Character_valueOf(a));
printf("%d\n", Character_compare(a, b));
printf("%d\n", Character_equals(a, b));

Character_delete(a);
Character_delete(b);
```



## UnsignedCharacter

### UnsignedCharacter_new()

- Prototype

```c
UnsignedCharacter *UnsignedCharacter_new(unsigned char value);
```

- Description
    - Creates a new `UnsignedCharacter` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `UnsignedCharacter` wrapper.



### UnsignedCharacter_delete()

- Prototype

```c
void UnsignedCharacter_delete(void *ptr);
```

- Description
    - Destroys the given `UnsignedCharacter` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### UnsignedCharacter_valueOf()

- Prototype

```c
unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character);
```

- Description
    - Returns the value of the given `UnsignedCharacter` wrapper.
- Parameters
    - `unsigned_character`: The pointer to the wrapper.
- Return
    - The primitive `unsigned char` value of the given wrapper.



### UnsignedCharacter_equals()

- Prototype

```c
bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2);
```

- Description
    - Checks if two `UnsignedCharacter` wrappers are equal.
- Parameters
    - `unsigned_character1`: The pointer to the first wrapper to be compared.
    - `unsigned_character2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `unsigned char` values of the two wrappers are equal, `false` otherwise.



### UnsignedCharacter_compare()

- Prototype

```c
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `UnsignedCharacter` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
UnsignedCharacter *a = UnsignedCharacter_new('A');
UnsignedCharacter *b = UnsignedCharacter_new('B');

printf("%u\n", UnsignedCharacter_valueOf(a));
printf("%d\n", UnsignedCharacter_compare(a, b));
printf("%d\n", UnsignedCharacter_equals(a, b));

UnsignedCharacter_delete(a);
UnsignedCharacter_delete(b);
```



## Short

### Short_new()

- Prototype

```c
Short *Short_new(short value);
```

- Description
    - Creates a new `Short` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Short` wrapper.



### Short_delete()

- Prototype

```c
void Short_delete(void *ptr);
```

- Description
    - Destroys the given `Short` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Short_valueOf()

- Prototype

```c
short Short_valueOf(const Short *s);
```

- Description
    - Returns the value of the given `Short` wrapper.
- Parameters
    - `s`: The pointer to the wrapper.
- Return
    - The primitive `short` value of the given wrapper.



### Short_equals()

- Prototype

```c
bool Short_equals(const Short *short1, const Short *short2);
```

- Description
    - Checks if two `Short` wrappers are equal.
- Parameters
    - `short1`: The pointer to the first wrapper to be compared.
    - `short2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `short` values of the two wrappers are equal, `false` otherwise.



### Short_compare()

- Prototype

```c
int Short_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Short` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Short *a = Short_new(1);
Short *b = Short_new(2);

printf("%hi\n", Short_valueOf(a));
printf("%d\n", Short_compare(a, b));
printf("%d\n", Short_equals(a, b));

Short_delete(a);
Short_delete(b);
```



## UnsignedShort

### UnsignedShort_new()

- Prototype

```c
UnsignedShort *UnsignedShort_new(unsigned short value);
```

- Description
    - Creates a new `UnsignedShort` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `UnsignedShort` wrapper.



### UnsignedShort_delete()

- Prototype

```c
void UnsignedShort_delete(void *ptr);
```

- Description
    - Destroys the given `UnsignedShort` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### UnsignedShort_valueOf()

- Prototype

```c
unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short);
```

- Description
    - Returns the value of the given `UnsignedShort` wrapper.
- Parameters
    - `unsigned_short`: The pointer to the wrapper.
- Return
    - The primitive `unsigned short` value of the given wrapper.



### UnsignedShort_equals()

- Prototype

```c
bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2);
```

- Description
    - Checks if two `UnsignedShort` wrappers are equal.
- Parameters
    - `unsigned_short1`: The pointer to the first wrapper to be compared.
    - `unsigned_short2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `unsigned short` values of the two wrappers are equal, `false` otherwise.



### UnsignedShort_compare()

- Prototype

```c
int UnsignedShort_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `UnsignedShort` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
UnsignedShort *a = UnsignedShort_new(1);
UnsignedShort *b = UnsignedShort_new(2);

printf("%hu\n", UnsignedShort_valueOf(a));
printf("%d\n", UnsignedShort_compare(a, b));
printf("%d\n", UnsignedShort_equals(a, b));

UnsignedShort_delete(a);
UnsignedShort_delete(b);
```



## Integer

### Integer_new()

- Prototype

```c
Integer *Integer_new(int value);
```

- Description
    - Creates a new `Integer` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Integer` wrapper.



### Integer_delete()

- Prototype

```c
void Integer_delete(void *ptr);
```

- Description
    - Destroys the given `Integer` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Integer_valueOf()

- Prototype

```c
int Integer_valueOf(const Integer *integer);
```

- Description
    - Returns the value of the given `Integer` wrapper.
- Parameters
    - `integer`: The pointer to the wrapper.
- Return
    - The primitive `int` value of the given wrapper.



### Integer_equals()

- Prototype

```c
bool Integer_equals(const Integer *integer1, const Integer *integer2);
```

- Description
    - Checks if two `Integer` wrappers are equal.
- Parameters
    - `integer1`: The pointer to the first wrapper to be compared.
    - `integer2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `int` values of the two wrappers are equal, `false` otherwise.



### Integer_compare()

- Prototype

```c
int Integer_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Integer` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Integer *a = Integer_new(1);
Integer *b = Integer_new(2);

printf("%d\n", Integer_valueOf(a));
printf("%d\n", Integer_compare(a, b));
printf("%d\n", Integer_equals(a, b));

Integer_delete(a);
Integer_delete(b);
```



## UnsignedInteger

### UnsignedInteger_new()

- Prototype

```c
UnsignedInteger *UnsignedInteger_new(unsigned int value);
```

- Description
    - Creates a new `UnsignedInteger` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `UnsignedInteger` wrapper.



### UnsignedInteger_delete()

- Prototype

```c
void UnsignedInteger_delete(void *ptr);
```

- Description
    - Destroys the given `UnsignedInteger` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### UnsignedInteger_valueOf()

- Prototype

```c
unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer);
```

- Description
    - Returns the value of the given `UnsignedInteger` wrapper.
- Parameters
    - `unsigned_integer`: The pointer to the wrapper.
- Return
    - The primitive `unsigned int` value of the given wrapper.



### UnsignedInteger_equals()

- Prototype

```c
bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2);
```

- Description
    - Checks if two `UnsignedInteger` wrappers are equal.
- Parameters
    - `unsigned_integer1`: The pointer to the first wrapper to be compared.
    - `unsigned_integer2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `unsigned int` values of the two wrappers are equal, `false` otherwise.



### UnsignedInteger_compare()

- Prototype

```c
int UnsignedInteger_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `UnsignedInteger` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
UnsignedInteger *a = UnsignedInteger_new(1U);
UnsignedInteger *b = UnsignedInteger_new(2U);

printf("%u\n", UnsignedInteger_valueOf(a));
printf("%d\n", UnsignedInteger_compare(a, b));
printf("%d\n", UnsignedInteger_equals(a, b));

UnsignedInteger_delete(a);
UnsignedInteger_delete(b);
```



## Long

### Long_new()

- Prototype

```c
Long *Long_new(long value);
```

- Description
    - Creates a new `Long` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Long` wrapper.



### Long_delete()

- Prototype

```c
void Long_delete(void *ptr);
```

- Description
    - Destroys the given `Long` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Long_valueOf()

- Prototype

```c
long Long_valueOf(const Long *l);
```

- Description
    - Returns the value of the given `Long` wrapper.
- Parameters
    - `l`: The pointer to the wrapper.
- Return
    - The primitive `long` value of the given wrapper.



### Long_equals()

- Prototype

```c
bool Long_equals(const Long *long1, const Long *long2);
```

- Description
    - Checks if two `Long` wrappers are equal.
- Parameters
    - `long1`: The pointer to the first wrapper to be compared.
    - `long2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `long` values of the two wrappers are equal, `false` otherwise.



### Long_compare()

- Prototype

```c
int Long_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Long` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Long *a = Long_new(1L);
Long *b = Long_new(2L);

printf("%ld\n", Long_valueOf(a));
printf("%d\n", Long_compare(a, b));
printf("%d\n", Long_equals(a, b));

Long_delete(a);
Long_delete(b);
```



## UnsignedLong

### UnsignedInteger_new()

- Prototype

```c
UnsignedLong *UnsignedLong_new(unsigned long value);
```

- Description
    - Creates a new `UnsignedLong` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `UnsignedLong` wrapper.



### UnsignedLong_delete()

- Prototype

```c
void UnsignedLong_delete(void *ptr);
```

- Description
    - Destroys the given `UnsignedLong` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### UnsignedLong_valueOf()

- Prototype

```c
unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long);
```

- Description
    - Returns the value of the given `UnsignedLong` wrapper.
- Parameters
    - `unsigned_long`: The pointer to the wrapper.
- Return
    - The primitive `unsigned long` value of the given wrapper.



### UnsignedLong_equals()

- Prototype

```c
bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2);
```

- Description
    - Checks if two `UnsignedLong` wrappers are equal.
- Parameters
    - `unsigned_long1`: The pointer to the first wrapper to be compared.
    - `unsigned_long2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `unsigned long` values of the two wrappers are equal, `false` otherwise.



### UnsignedLong_compare()

- Prototype

```c
int UnsignedLong_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `UnsignedLong` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
UnsignedLong *a = UnsignedLong_new(1UL);
UnsignedLong *b = UnsignedLong_new(2UL);

printf("%lu\n", UnsignedLong_valueOf(a));
printf("%d\n", UnsignedLong_compare(a, b));
printf("%d\n", UnsignedLong_equals(a, b));

UnsignedLong_delete(a);
UnsignedLong_delete(b);
```



## Float

### Float_new()

- Prototype

```c
Float *Float_new(float value);
```

- Description
    - Creates a new `Float` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Float` wrapper.



### Float_delete()

- Prototype

```c
void Float_delete(void *ptr);
```

- Description
    - Destroys the given `Float` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Float_valueOf()

- Prototype

```c
float Float_valueOf(const Float *f);
```

- Description
    - Returns the value of the given `Float` wrapper.
- Parameters
    - `f`: The pointer to the wrapper.
- Return
    - The primitive `float` value of the given wrapper.



### Float_equals()

- Prototype

```c
bool Float_equals(const Float *float1, const Float *float2);
```

- Description
    - Checks if two `Float` wrappers are equal.
- Parameters
    - `float1`: The pointer to the first wrapper to be compared.
    - `float2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `float` values of the two wrappers are equal, `false` otherwise.



### Float_compare()

- Prototype

```c
int Float_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Float` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Float *a = Float_new(1.1f);
Float *b = Float_new(2.2f);

printf("%f\n", Float_valueOf(a));
printf("%d\n", Float_compare(a, b));
printf("%d\n", Float_equals(a, b));

Float_delete(a);
Float_delete(b);
```



## Double

### Double_new()

- Prototype

```c
Double *Double_new(double value);
```

- Description
    - Creates a new `Double` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Double` wrapper.



### Double_delete()

- Prototype

```c
void Double_delete(void *ptr);
```

- Description
    - Destroys the given `Double` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Double_valueOf()

- Prototype

```c
double Double_valueOf(const Double *d);
```

- Description
    - Returns the value of the given `Double` wrapper.
- Parameters
    - `d`: The pointer to the wrapper.
- Return
    - The primitive `double` value of the given wrapper.



### Double_equals()

- Prototype

```c
bool Double_equals(const Double *double1, const Double *double2);
```

- Description
    - Checks if two `Double` wrappers are equal.
- Parameters
    - `double1`: The pointer to the first wrapper to be compared.
    - `double2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `double` values of the two wrappers are equal, `false` otherwise.



### Double_compare()

- Prototype

```c
int Double_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Double` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Double *a = Double_new(1.1);
Double *b = Double_new(2.2);

printf("%f\n", Double_valueOf(a));
printf("%d\n", Double_compare(a, b));
printf("%d\n", Double_equals(a, b));

Double_delete(a);
Double_delete(b);
```



## Boolean

### Boolean_new()

- Prototype

```c
Boolean *Boolean_new(bool value);
```

- Description
    - Creates a new `Boolean` wrapper.
- Parameters
    - `value`: The value to be wrapped.
- Return
    - Returns a pointer to the newly created `Boolean` wrapper.



### Boolean_delete()

- Prototype

```c
void Boolean_delete(void *ptr);
```

- Description
    - Destroys the given `Boolean` wrapper.
- Parameters
    - `ptr`: The pointer to the wrapper to be destroyed.



### Boolean_valueOf()

- Prototype

```c
bool Boolean_valueOf(const Boolean *boolean);
```

- Description
    - Returns the value of the given `Boolean` wrapper.
- Parameters
    - `boolean`: The pointer to the wrapper.
- Return
    - The primitive `bool` value of the given wrapper.



### Boolean_equals()

- Prototype

```c
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2);
```

- Description
    - Checks if two `Boolean` wrappers are equal.
- Parameters
    - `boolean1`: The pointer to the first wrapper to be compared.
    - `boolean2`: The pointer to the second wrapper to be compared.
- Return
    - Returns `true` if the primitive `bool` values of the two wrappers are equal, `false` otherwise.



### Boolean_compare()

- Prototype

```c
int Boolean_compare(const void *ptr1, const void *ptr2);
```

- Description
    - Compares two `Boolean` wrappers.
- Parameters
    - `ptr1`: The pointer to the first wrapper to be compared.
    - `ptr2`: The pointer to the second wrapper to be compared.
- Return
    - Returns a negative integer if `ptr1 < ptr2`.
    - Returns 0 if `ptr1 == ptr2`.
    - Returns a positive integer if `ptr1 > ptr2`.
- Usage

```c
Boolean *a = Boolean_new(true);
Boolean *b = Boolean_new(false);

printf("%d\n", Boolean_valueOf(a));
printf("%d\n", Boolean_compare(a, b));
printf("%d\n", Boolean_equals(a, b));

Boolean_delete(a);
Boolean_delete(b);
```

