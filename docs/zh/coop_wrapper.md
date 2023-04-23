# coop_wrapper

[TOC]



## Character

### Character_new()

- 原型

```c
Character *Character_new(char value);
```

- 描述
    - 创建 `Character` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Character` 包装类指针。



### Character_delete()

- 原型

```c
void Character_delete(void *ptr);
```

- 描述
    - 销毁`Character`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Character_valueOf()

- 原型

```c
char Character_valueOf(const Character *character);
```

- 描述
    - 返回`Character`包装类的值。
- 参数
    - `character`： 包装类指针。
- 返回值
    - 包装类的原生`char`数据。



### Character_equals()

- 原型

```c
bool Character_equals(const Character *character1, const Character *character2);
```

- 描述
    - 检查两个`Character`包装类是否相等。
- 参数
    - `character1`： 第一个待比较的包装类指针。
    - `character2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`char`数据相等返回`true`，否则返回`false`。



### Character_compare()

- 原型

```c
int Character_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Character`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
UnsignedCharacter *UnsignedCharacter_new(unsigned char value);
```

- 描述
    - 创建 `UnsignedCharacter` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`UnsignedCharacter` 包装类指针。



### UnsignedCharacter_delete()

- 原型

```c
void UnsignedCharacter_delete(void *ptr);
```

- 描述
    - 销毁`UnsignedCharacter`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### UnsignedCharacter_valueOf()

- 原型

```c
unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character);
```

- 描述
    - 返回`UnsignedCharacter`包装类的值。
- 参数
    - `unsigned_character`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned char`数据。



### UnsignedCharacter_equals()

- 原型

```c
bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2);
```

- 描述
    - 检查两个`UnsignedCharacter`包装类是否相等。
- 参数
    - `unsigned_character1`： 第一个待比较的包装类指针。
    - `unsigned_character2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`unsigned char`数据相等返回`true`，否则返回`false`。



### UnsignedCharacter_compare()

- 原型

```c
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`UnsignedCharacter`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Short *Short_new(short value);
```

- 描述
    - 创建 `Short` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Short` 包装类指针。



### Short_delete()

- 原型

```c
void Short_delete(void *ptr);
```

- 描述
    - 销毁`Short`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Short_valueOf()

- 原型

```c
short Short_valueOf(const Short *s);
```

- 描述
    - 返回`Short`包装类的值。
- 参数
    - `s`： 包装类指针。
- 返回值
    - 包装类的原生`short`数据。



### Short_equals()

- 原型

```c
bool Short_equals(const Short *short1, const Short *short2);
```

- 描述
    - 检查两个`Short`包装类是否相等。
- 参数
    - `short1`： 第一个待比较的包装类指针。
    - `short2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`short`数据相等返回`true`，否则返回`false`。



### Short_compare()

- 原型

```c
int Short_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Short`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
UnsignedShort *UnsignedShort_new(unsigned short value);
```

- 描述
    - 创建 `UnsignedShort` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`UnsignedShort` 包装类指针。



### UnsignedShort_delete()

- 原型

```c
void UnsignedShort_delete(void *ptr);
```

- 描述
    - 销毁`UnsignedShort`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### UnsignedShort_valueOf()

- 原型

```c
unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short);
```

- 描述
    - 返回`UnsignedShort`包装类的值。
- 参数
    - `unsigned_short`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned short`数据。



### UnsignedShort_equals()

- 原型

```c
bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2);
```

- 描述
    - 检查两个`UnsignedShort`包装类是否相等。
- 参数
    - `unsigned_short1`： 第一个待比较的包装类指针。
    - `unsigned_short2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`unsigned short`数据相等返回`true`，否则返回`false`。



### UnsignedShort_compare()

- 原型

```c
int UnsignedShort_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`UnsignedShort`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Integer *Integer_new(int value);
```

- 描述
    - 创建 `Integer` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Integer` 包装类指针。



### Integer_delete()

- 原型

```c
void Integer_delete(void *ptr);
```

- 描述
    - 销毁`Integer`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Integer_valueOf()

- 原型

```c
int Integer_valueOf(const Integer *integer);
```

- 描述
    - 返回`Integer`包装类的值。
- 参数
    - `integer`： 包装类指针。
- 返回值
    - 包装类的原生`int`数据。



### Integer_equals()

- 原型

```c
bool Integer_equals(const Integer *integer1, const Integer *integer2);
```

- 描述
    - 检查两个`Integer`包装类是否相等。
- 参数
    - `integer1`： 第一个待比较的包装类指针。
    - `integer2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`int`数据相等返回`true`，否则返回`false`。



### Integer_compare()

- 原型

```c
int Integer_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Integer`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
UnsignedInteger *UnsignedInteger_new(unsigned int value);
```

- 描述
    - 创建 `UnsignedInteger` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`UnsignedInteger` 包装类指针。



### UnsignedInteger_delete()

- 原型

```c
void UnsignedInteger_delete(void *ptr);
```

- 描述
    - 销毁`UnsignedInteger`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### UnsignedInteger_valueOf()

- 原型

```c
unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer);
```

- 描述
    - 返回`UnsignedInteger`包装类的值。
- 参数
    - `unsigned_integer`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned int`数据。



### UnsignedInteger_equals()

- 原型

```c
bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2);
```

- 描述
    - 检查两个`UnsignedInteger`包装类是否相等。
- 参数
    - `unsigned_integer1`： 第一个待比较的包装类指针。
    - `unsigned_integer2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`unsigned int`数据相等返回`true`，否则返回`false`。



### UnsignedInteger_compare()

- 原型

```c
int UnsignedInteger_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`UnsignedInteger`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Long *Long_new(long value);
```

- 描述
    - 创建 `Long` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Long` 包装类指针。



### Long_delete()

- 原型

```c
void Long_delete(void *ptr);
```

- 描述
    - 销毁`Long`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Long_valueOf()

- 原型

```c
long Long_valueOf(const Long *l);
```

- 描述
    - 返回`Long`包装类的值。
- 参数
    - `l`： 包装类指针。
- 返回值
    - 包装类的原生`long`数据。



### Long_equals()

- 原型

```c
bool Long_equals(const Long *long1, const Long *long2);
```

- 描述
    - 检查两个`Long`包装类是否相等。
- 参数
    - `long1`： 第一个待比较的包装类指针。
    - `long2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`long`数据相等返回`true`，否则返回`false`。



### Long_compare()

- 原型

```c
int Long_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Long`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
UnsignedLong *UnsignedLong_new(unsigned long value);
```

- 描述
    - 创建 `UnsignedLong` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`UnsignedLong` 包装类指针。



### UnsignedLong_delete()

- 原型

```c
void UnsignedLong_delete(void *ptr);
```

- 描述
    - 销毁`UnsignedLong`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### UnsignedLong_valueOf()

- 原型

```c
unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long);
```

- 描述
    - 返回`UnsignedLong`包装类的值。
- 参数
    - `unsigned_long`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned long`数据。



### UnsignedLong_equals()

- 原型

```c
bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2);
```

- 描述
    - 检查两个`UnsignedLong`包装类是否相等。
- 参数
    - `unsigned_long1`： 第一个待比较的包装类指针。
    - `unsigned_long2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`unsigned long`数据相等返回`true`，否则返回`false`。



### UnsignedLong_compare()

- 原型

```c
int UnsignedLong_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`UnsignedLong`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Float *Float_new(float value);
```

- 描述
    - 创建 `Float` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Float` 包装类指针。



### Float_delete()

- 原型

```c
void Float_delete(void *ptr);
```

- 描述
    - 销毁`Float`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Float_valueOf()

- 原型

```c
float Float_valueOf(const Float *f);
```

- 描述
    - 返回`Float`包装类的值。
- 参数
    - `f`： 包装类指针。
- 返回值
    - 包装类的原生`float`数据。



### Float_equals()

- 原型

```c
bool Float_equals(const Float *float1, const Float *float2);
```

- 描述
    - 检查两个`Float`包装类是否相等。
- 参数
    - `float1`： 第一个待比较的包装类指针。
    - `float2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`float`数据相等返回`true`，否则返回`false`。



### Float_compare()

- 原型

```c
int Float_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Float`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Double *Double_new(double value);
```

- 描述
    - 创建 `Double` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Double` 包装类指针。



### Double_delete()

- 原型

```c
void Double_delete(void *ptr);
```

- 描述
    - 销毁`Double`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Double_valueOf()

- 原型

```c
double Double_valueOf(const Double *d);
```

- 描述
    - 返回`Double`包装类的值。
- 参数
    - `d`： 包装类指针。
- 返回值
    - 包装类的原生`double`数据。



### Double_equals()

- 原型

```c
bool Double_equals(const Double *double1, const Double *double2);
```

- 描述
    - 检查两个`Double`包装类是否相等。
- 参数
    - `double1`： 第一个待比较的包装类指针。
    - `double2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`double`数据相等返回`true`，否则返回`false`。



### Double_compare()

- 原型

```c
int Double_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Double`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

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

- 原型

```c
Boolean *Boolean_new(bool value);
```

- 描述
    - 创建 `Boolean` 包装类。
- 参数
    - `value`： 待包装数据。
- 返回值
    - 返回`Boolean` 包装类指针。



### Boolean_delete()

- 原型

```c
void Boolean_delete(void *ptr);
```

- 描述
    - 销毁`Boolean`包装类。
- 参数
    - `ptr`： 待销毁包装类指针。



### Boolean_valueOf()

- 原型

```c
bool Boolean_valueOf(const Boolean *boolean);
```

- 描述
    - 返回`Boolean`包装类的值。
- 参数
    - `boolean`： 包装类指针。
- 返回值
    - 包装类的原生`bool`数据。



### Boolean_equals()

- 原型

```c
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2);
```

- 描述
    - 检查两个`Boolean`包装类是否相等。
- 参数
    - `boolean1`： 第一个待比较的包装类指针。
    - `boolean2`： 第二个待比较的包装类指针。
- 返回值
    - 如果两个包装类的原生`bool`数据相等返回`true`，否则返回`false`。



### Boolean_compare()

- 原型

```c
int Boolean_compare(const void *ptr1, const void *ptr2);
```

- 描述
    - 比较两个`Boolean`包装类。
- 参数
    - `ptr1`： 第一个待比较的包装类指针。
    - `ptr2`： 第二个待比较的包装类指针。
- 返回值
    - 如果`ptr1 < ptr2`，返回负整数。
    - 如果`ptr1 == ptr2`，返回0。
    - 如果`ptr1 > ptr2`，返回正整数。
- 用例

```c
Boolean *a = Boolean_new(true);
Boolean *b = Boolean_new(false);

printf("%d\n", Boolean_valueOf(a));
printf("%d\n", Boolean_compare(a, b));
printf("%d\n", Boolean_equals(a, b));

Boolean_delete(a);
Boolean_delete(b);
```

