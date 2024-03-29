# wrapper

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



### Character_get()

- Prototype

```c
char Character_get(const Character *character);
```

- Description
    - Returns the value of the given `Character` wrapper.
- Parameters
    - `character`: The pointer to the wrapper.
- Return
    - The primitive `char` value of the given wrapper.



### Character_set()

- Prototype

```c
void Character_set(Character *character, char value);
```

- Description
    - Sets the value of the given `Character` wrapper.
- Parameters
    - `character`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Character_hash()

- Prototype

```c
size_t Character_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Character` wrapper.
- Parameters
    - `ptr`: The pointer to the `Character` wrapper.
- Return
    - The hash code of the given `Character` wrapper.
- Usage

```c
Character *c1 = Character_new('A');
Character *c2 = Character_new('B');

printf("%c\n", Character_get(c1));
printf("%d\n", Character_compare(c1, c2));

Character_set(c1, 'B');
printf("%d\n", Character_equals(c1, c2));

Character_delete(c1);
Character_delete(c2);
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



### UnsignedCharacter_get()

- Prototype

```c
unsigned char UnsignedCharacter_get(const UnsignedCharacter *uc);
```

- Description
    - Returns the value of the given `UnsignedCharacter` wrapper.
- Parameters
    - `uc`: The pointer to the wrapper.
- Return
    - The primitive `unsigned char` value of the given wrapper.



### UnsignedCharacter_set()

- Prototype

```c
void UnsignedCharacter_set(UnsignedCharacter *uc, unsigned char value);
```

- Description
    - Sets the value of the given `UnsignedCharacter` wrapper.
- Parameters
    - `uc`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



### UnsignedCharacter_equals()

- Prototype

```c
bool UnsignedCharacter_equals(const UnsignedCharacter *uc1, const UnsignedCharacter *uc2);
```

- Description
    - Checks if two `UnsignedCharacter` wrappers are equal.
- Parameters
    - `uc1`: The pointer to the first wrapper to be compared.
    - `uc2`: The pointer to the second wrapper to be compared.
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



### UnsignedCharacter_hash()

- Prototype

```c
size_t UnsignedCharacter_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `UnsignedCharacter` wrapper.
- Parameters
    - `ptr`: The pointer to the `UnsignedCharacter` wrapper.
- Return
    - The hash code of the given `UnsignedCharacter` wrapper.
- Usage

```c
UnsignedCharacter *uc1 = UnsignedCharacter_new('A');
UnsignedCharacter *uc2 = UnsignedCharacter_new('B');

printf("%u\n", UnsignedCharacter_get(uc1));
printf("%d\n", UnsignedCharacter_compare(uc1, uc2));

UnsignedCharacter_set(uc1, 'B');
printf("%d\n", UnsignedCharacter_equals(uc1, uc2));

UnsignedCharacter_delete(uc1);
UnsignedCharacter_delete(uc2);
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



### Short_get()

- Prototype

```c
short Short_get(const Short *s);
```

- Description
    - Returns the value of the given `Short` wrapper.
- Parameters
    - `s`: The pointer to the wrapper.
- Return
    - The primitive `short` value of the given wrapper.



### Short_set()

- Prototype

```c
void Short_set(Short *s, short value);
```

- Description
    - Sets the value of the given `Short` wrapper.
- Parameters
    - `uc`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Short_hash()

- Prototype

```c
size_t Short_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Short` wrapper.
- Parameters
    - `ptr`: The pointer to the `Short` wrapper.
- Return
    - The hash code of the given `Short` wrapper.
- Usage

```c
Short *s1 = Short_new(1);
Short *s2 = Short_new(2);

printf("%hi\n", Short_get(s1));
printf("%d\n", Short_compare(s1, s2));

Short_set(s1, 2);
printf("%d\n", Short_equals(s1, s2));

Short_delete(s1);
Short_delete(s2);
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



### UnsignedShort_get()

- Prototype

```c
unsigned short UnsignedShort_get(const UnsignedShort *us);
```

- Description
    - Returns the value of the given `UnsignedShort` wrapper.
- Parameters
    - `us`: The pointer to the wrapper.
- Return
    - The primitive `unsigned short` value of the given wrapper.



### UnsignedShort_set()

- Prototype

```c
void UnsignedShort_set(UnsignedShort *us, unsigned short value);
```

- Description
    - Sets the value of the given `UnsignedShort` wrapper.
- Parameters
    - `us`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



### UnsignedShort_equals()

- Prototype

```c
bool UnsignedShort_equals(const UnsignedShort *us1, const UnsignedShort *us2);
```

- Description
    - Checks if two `UnsignedShort` wrappers are equal.
- Parameters
    - `us1`: The pointer to the first wrapper to be compared.
    - `us2`: The pointer to the second wrapper to be compared.
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



### UnsignedShort_hash()

- Prototype

```c
size_t UnsignedShort_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `UnsignedShort` wrapper.
- Parameters
    - `ptr`: The pointer to the `UnsignedShort` wrapper.
- Return
    - The hash code of the given `UnsignedShort` wrapper.
- Usage

```c
UnsignedShort *us1 = UnsignedShort_new(1);
UnsignedShort *us2 = UnsignedShort_new(2);

printf("%hu\n", UnsignedShort_get(us1));
printf("%d\n", UnsignedShort_compare(us1, us2));

UnsignedShort_set(us1, 2);
printf("%d\n", UnsignedShort_equals(us1, us2));

UnsignedShort_delete(us1);
UnsignedShort_delete(us2);
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



### Integer_get()

- Prototype

```c
int Integer_get(const Integer *integer);
```

- Description
    - Returns the value of the given `Integer` wrapper.
- Parameters
    - `integer`: The pointer to the wrapper.
- Return
    - The primitive `int` value of the given wrapper.



### Integer_set()

- Prototype

```c
void Integer_set(Integer *integer, int value);
```

- Description
    - Sets the value of the given `Integer` wrapper.
- Parameters
    - `integer`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Integer_hash()

- Prototype

```c
size_t Integer_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Integer` wrapper.
- Parameters
    - `ptr`: The pointer to the `Integer` wrapper.
- Return
    - The hash code of the given `Integer` wrapper.
- Usage

```c
Integer *i1 = Integer_new(1);
Integer *i2 = Integer_new(2);

printf("%d\n", Integer_get(i1));
printf("%d\n", Integer_compare(i1, i2));

Integer_set(i1, 2);
printf("%d\n", Integer_equals(i1, i2));

Integer_delete(i1);
Integer_delete(i2);
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



### UnsignedInteger_get()

- Prototype

```c
unsigned int UnsignedInteger_get(const UnsignedInteger *ui);
```

- Description
    - Returns the value of the given `UnsignedInteger` wrapper.
- Parameters
    - `ui`: The pointer to the wrapper.
- Return
    - The primitive `unsigned int` value of the given wrapper.



### UnsignedInteger_set()

- Prototype

```c
void UnsignedInteger_set(UnsignedInteger *ui, unsigned int value);
```

- Description
    - Sets the value of the given `UnsignedInteger` wrapper.
- Parameters
    - `ui`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



### UnsignedInteger_equals()

- Prototype

```c
bool UnsignedInteger_equals(const UnsignedInteger *ui1, const UnsignedInteger *ui2);
```

- Description
    - Checks if two `UnsignedInteger` wrappers are equal.
- Parameters
    - `ui1`: The pointer to the first wrapper to be compared.
    - `ui2`: The pointer to the second wrapper to be compared.
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



### UnsignedInteger_hash()

- Prototype

```c
size_t UnsignedInteger_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `UnsignedInteger` wrapper.
- Parameters
    - `ptr`: The pointer to the `UnsignedInteger` wrapper.
- Return
    - The hash code of the given `UnsignedInteger` wrapper.
- Usage

```c
UnsignedInteger *ui1 = UnsignedInteger_new(1U);
UnsignedInteger *ui2 = UnsignedInteger_new(2U);

printf("%u\n", UnsignedInteger_get(ui1));
printf("%d\n", UnsignedInteger_compare(ui1, ui2));

UnsignedInteger_set(ui1, 2U);
printf("%d\n", UnsignedInteger_equals(ui1, ui2));

UnsignedInteger_delete(ui1);
UnsignedInteger_delete(ui2);
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



### Long_get()

- Prototype

```c
long Long_get(const Long *l);
```

- Description
    - Returns the value of the given `Long` wrapper.
- Parameters
    - `l`: The pointer to the wrapper.
- Return
    - The primitive `long` value of the given wrapper.



### Long_set()

- Prototype

```c
void Long_set(Long *l, long value);
```

- Description
    - Sets the value of the given `Long` wrapper.
- Parameters
    - `l`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Long_hash()

- Prototype

```c
size_t Long_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Long` wrapper.
- Parameters
    - `ptr`: The pointer to the `Long` wrapper.
- Return
    - The hash code of the given `Long` wrapper.
- Usage

```c
Long *l1 = Long_new(1L);
Long *l2 = Long_new(2L);

printf("%ld\n", Long_get(l1));
printf("%d\n", Long_compare(l1, l2));

Long_set(l1, 2L);
printf("%d\n", Long_equals(l1, l2));

Long_delete(l1);
Long_delete(l2);
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



### UnsignedLong_get()

- Prototype

```c
unsigned long UnsignedLong_get(const UnsignedLong *ul);
```

- Description
    - Returns the value of the given `UnsignedLong` wrapper.
- Parameters
    - `ul`: The pointer to the wrapper.
- Return
    - The primitive `unsigned long` value of the given wrapper.



### UnsignedLong_set()

- Prototype

```c
void UnsignedLong_set(UnsignedLong *ul, unsigned long value);
```

- Description
    - Sets the value of the given `UnsignedLong` wrapper.
- Parameters
    - `ul`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



### UnsignedLong_equals()

- Prototype

```c
bool UnsignedLong_equals(const UnsignedLong *ul1, const UnsignedLong *ul2);
```

- Description
    - Checks if two `UnsignedLong` wrappers are equal.
- Parameters
    - `ul1`: The pointer to the first wrapper to be compared.
    - `ul2`: The pointer to the second wrapper to be compared.
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



### UnsignedLong_hash()

- Prototype

```c
size_t UnsignedLong_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `UnsignedLong` wrapper.
- Parameters
    - `ptr`: The pointer to the `UnsignedLong` wrapper.
- Return
    - The hash code of the given `UnsignedLong` wrapper.
- Usage

```c
UnsignedLong *ul1 = UnsignedLong_new(1UL);
UnsignedLong *ul2 = UnsignedLong_new(2UL);

printf("%lu\n", UnsignedLong_get(ul1));
printf("%d\n", UnsignedLong_compare(ul1, ul2));

UnsignedLong_set(ul1, 2UL);
printf("%d\n", UnsignedLong_equals(ul1, ul2));

UnsignedLong_delete(a);
UnsignedLong_delete(ul2);
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



### Float_get()

- Prototype

```c
float Float_get(const Float *f);
```

- Description
    - Returns the value of the given `Float` wrapper.
- Parameters
    - `f`: The pointer to the wrapper.
- Return
    - The primitive `float` value of the given wrapper.



### Float_set()

- Prototype

```c
void Float_set(Float *f, float value);
```

- Description
    - Sets the value of the given `Float` wrapper.
- Parameters
    - `f`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Float_hash()

- Prototype

```c
size_t Float_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Float` wrapper.
- Parameters
    - `ptr`: The pointer to the `Float` wrapper.
- Return
    - The hash code of the given `Float` wrapper.
- Usage

```c
Float *f1 = Float_new(1.1f);
Float *f2 = Float_new(2.2f);

printf("%f\n", Float_get(f1));
printf("%d\n", Float_compare(f1, f2));

Float_set(f1, 2.2f);
printf("%d\n", Float_equals(f1, f2));

Float_delete(f1);
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



### Double_get()

- Prototype

```c
double Double_get(const Double *d);
```

- Description
    - Returns the value of the given `Double` wrapper.
- Parameters
    - `d`: The pointer to the wrapper.
- Return
    - The primitive `double` value of the given wrapper.



### Double_set()

- Prototype

```c
void Double_set(Double *d, double value);
```

- Description
    - Sets the value of the given `Double` wrapper.
- Parameters
    - `d`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Double_hash()

- Prototype

```c
size_t Double_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Double` wrapper.
- Parameters
    - `ptr`: The pointer to the `Double` wrapper.
- Return
    - The hash code of the given `Double` wrapper.
- Usage

```c
Double *d1 = Double_new(1.1);
Double *d2 = Double_new(2.2);

printf("%f\n", Double_get(d1));
printf("%d\n", Double_compare(d1, d2));

Double_set(d1, 2.2);
printf("%d\n", Double_equals(d1, d2));

Double_delete(d1);
Double_delete(d2);
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



### Boolean_get()

- Prototype

```c
bool Boolean_get(const Boolean *boolean);
```

- Description
    - Returns the value of the given `Boolean` wrapper.
- Parameters
    - `boolean`: The pointer to the wrapper.
- Return
    - The primitive `bool` value of the given wrapper.



### Boolean_set()

- Prototype

```c
void Boolean_set(Boolean *boolean, bool value);
```

- Description
    - Sets the value of the given `Boolean` wrapper.
- Parameters
    - `boolean`: The pointer to the wrapper.
    - `value`: The new value.
- Return
    - The new value of the wrapper.



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



### Boolean_hash()

- Prototype

```c
size_t Boolean_hash(const void *ptr);
```

- Description
    - Returns the hash code of the given `Boolean` wrapper.
- Parameters
    - `ptr`: The pointer to the `Boolean` wrapper.
- Return
    - The hash code of the given `Boolean` wrapper.
- Usage

```c
Boolean *b1 = Boolean_new(true);
Boolean *b2 = Boolean_new(false);

printf("%d\n", Boolean_get(b1));
printf("%d\n", Boolean_compare(b1, b2));

Boolean_set(b1, false);
printf("%d\n", Boolean_equals(b1, b2));

Boolean_delete(b1);
Boolean_delete(b2);
```

