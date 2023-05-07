# wrapper

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



### Character_get()

- 原型

```c
char Character_get(const Character *character);
```

- 描述
    - 返回`Character`包装类的值。
- 参数
    - `character`： 包装类指针。
- 返回值
    - 包装类的原生`char`数据。



### Character_set()

- 原型

```c
void Character_set(Character *character, char value);
```

- 描述
    - 设置`Character`包装类的值。
- 参数
    - `character`：包装类指针。
    - `value`：新值。



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



### Character_hash()

- 原型

```c
size_t Character_hash(const void *ptr);
```

- 描述
    - 返回`Character`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Character`包装类的哈希值。
- 用例

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



### UnsignedCharacter_get()

- 原型

```c
unsigned char UnsignedCharacter_get(const UnsignedCharacter *uc);
```

- 描述
    - 返回`UnsignedCharacter`包装类的值。
- 参数
    - `uc`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned char`数据。



### UnsignedCharacter_set()

- 原型

```c
void UnsignedCharacter_set(UnsignedCharacter *uc, unsigned char value);
```

- 描述
    - 设置`UnsignedCharacter`包装类的值。
- 参数
    - `uc`：包装类指针。
    - `value`：新值。



### UnsignedCharacter_equals()

- 原型

```c
bool UnsignedCharacter_equals(const UnsignedCharacter *uc1, const UnsignedCharacter *uc2);
```

- 描述
    - 检查两个`UnsignedCharacter`包装类是否相等。
- 参数
    - `uc1`： 第一个待比较的包装类指针。
    - `uc2`： 第二个待比较的包装类指针。
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



### UnsignedCharacter_hash()

- 原型

```c
size_t UnsignedCharacter_hash(const void *ptr);
```

- 描述
    - 返回`UnsignedCharacter`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`UnsignedCharacter`包装类的哈希值。
- 用例

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



### Short_get()

- 原型

```c
short Short_get(const Short *s);
```

- 描述
    - 返回`Short`包装类的值。
- 参数
    - `s`： 包装类指针。
- 返回值
    - 包装类的原生`short`数据。



### Short_set()

- 原型

```c
void Short_set(Short *s, short value);
```

- 描述
    - 设置`Short`包装类的值。
- 参数
    - `s`：包装类指针。
    - `value`：新值。



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



### Short_hash()

- 原型

```c
size_t Short_hash(const void *ptr);
```

- 描述
    - 返回`Short`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Short`包装类的哈希值。
- 用例

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



### UnsignedShort_get()

- 原型

```c
unsigned short UnsignedShort_get(const UnsignedShort *us);
```

- 描述
    - 返回`UnsignedShort`包装类的值。
- 参数
    - `us`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned short`数据。



### UnsignedShort_set()

- 原型

```c
void UnsignedShort_set(UnsignedShort *us, unsigned short value);
```

- 描述
    - 设置`UnsignedShort`包装类的值。
- 参数
    - `us`：包装类指针。
    - `value`：新值。



### UnsignedShort_equals()

- 原型

```c
bool UnsignedShort_equals(const UnsignedShort *us1, const UnsignedShort *us2);
```

- 描述
    - 检查两个`UnsignedShort`包装类是否相等。
- 参数
    - `us1`： 第一个待比较的包装类指针。
    - `us2`： 第二个待比较的包装类指针。
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



### UnsignedShort_hash()

- 原型

```c
size_t UnsignedShort_hash(const void *ptr);
```

- 描述
    - 返回`UnsignedShort`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`UnsignedShort`包装类的哈希值。
- 用例

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



### Integer_get()

- 原型

```c
int Integer_get(const Integer *integer);
```

- 描述
    - 返回`Integer`包装类的值。
- 参数
    - `integer`： 包装类指针。
- 返回值
    - 包装类的原生`int`数据。



### Integer_set()

- 原型

```c
void Integer_set(Integer *integer, int value);
```

- 描述
    - 设置`Integer`包装类的值。
- 参数
    - `integer`：包装类指针。
    - `value`：新值。



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



### Integer_hash()

- 原型

```c
size_t Integer_hash(const void *ptr);
```

- 描述
    - 返回`Integer`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Integer`包装类的哈希值。
- 用例

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



### UnsignedInteger_get()

- 原型

```c
unsigned int UnsignedInteger_get(const UnsignedInteger *ui);
```

- 描述
    - 返回`UnsignedInteger`包装类的值。
- 参数
    - `ui`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned int`数据。



### UnsignedInteger_set()

- 原型

```c
void UnsignedInteger_set(UnsignedInteger *ui, unsigned int value);
```

- 描述
    - 设置`UnsignedInteger`包装类的值。
- 参数
    - `ui`：包装类指针。
    - `value`：新值。



### UnsignedInteger_equals()

- 原型

```c
bool UnsignedInteger_equals(const UnsignedInteger *ui1, const UnsignedInteger *ui2);
```

- 描述
    - 检查两个`UnsignedInteger`包装类是否相等。
- 参数
    - `ui1`： 第一个待比较的包装类指针。
    - `ui2`： 第二个待比较的包装类指针。
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



### UnsignedInteger_hash()

- 原型

```c
size_t UnsignedInteger_hash(const void *ptr);
```

- 描述
    - 返回`UnsignedInteger`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`UnsignedInteger`包装类的哈希值。
- 用例

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



### Long_get()

- 原型

```c
long Long_get(const Long *l);
```

- 描述
    - 返回`Long`包装类的值。
- 参数
    - `l`： 包装类指针。
- 返回值
    - 包装类的原生`long`数据。



### Long_set()

- 原型

```c
void Long_set(Long *l, long value);
```

- 描述
    - 设置`Long`包装类的值。
- 参数
    - `l`：包装类指针。
    - `value`：新值。



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



### Long_hash()

- 原型

```c
size_t Long_hash(const void *ptr);
```

- 描述
    - 返回`Long`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Long`包装类的哈希值。
- 用例

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



### UnsignedLong_get()

- 原型

```c
unsigned long UnsignedLong_get(const UnsignedLong *ul);
```

- 描述
    - 返回`UnsignedLong`包装类的值。
- 参数
    - `ul`： 包装类指针。
- 返回值
    - 包装类的原生`unsigned long`数据。



### UnsignedLong_set()

- 原型

```c
void UnsignedLong_set(UnsignedLong *ul, unsigned long value);
```

- 描述
    - 设置`UnsignedLong`包装类的值。
- 参数
    - `ul`：包装类指针。
    - `value`：新值。



### UnsignedLong_equals()

- 原型

```c
bool UnsignedLong_equals(const UnsignedLong *ul1, const UnsignedLong *ul2);
```

- 描述
    - 检查两个`UnsignedLong`包装类是否相等。
- 参数
    - `ul1`： 第一个待比较的包装类指针。
    - `ul2`： 第二个待比较的包装类指针。
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



### UnsignedLong_hash()

- 原型

```c
size_t UnsignedLong_hash(const void *ptr);
```

- 描述
    - 返回`UnsignedLong`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`UnsignedLong`包装类的哈希值。
- 用例

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



### Float_get()

- 原型

```c
float Float_get(const Float *f);
```

- 描述
    - 返回`Float`包装类的值。
- 参数
    - `f`： 包装类指针。
- 返回值
    - 包装类的原生`float`数据。



### Float_set()

- 原型

```c
void Float_set(Float *f, float value);
```

- 描述
    - 设置`Float`包装类的值。
- 参数
    - `f`：包装类指针。
    - `value`：新值。



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



### Float_hash()

- 原型

```c
size_t Float_hash(const void *ptr);
```

- 描述
    - 返回`Float`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Float`包装类的哈希值。
- 用例

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



### Double_get()

- 原型

```c
double Double_get(const Double *d);
```

- 描述
    - 返回`Double`包装类的值。
- 参数
    - `d`： 包装类指针。
- 返回值
    - 包装类的原生`double`数据。



### Double_set()

- 原型

```c
void Double_set(Double *d, double value);
```

- 描述
    - 设置`Double`包装类的值。
- 参数
    - `d`：包装类指针。
    - `value`：新值。



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



### Double_hash()

- 原型

```c
size_t Double_hash(const void *ptr);
```

- 描述
    - 返回`Double`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Double`包装类的哈希值。
- 用例

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



### Boolean_get()

- 原型

```c
bool Boolean_get(const Boolean *boolean);
```

- 描述
    - 返回`Boolean`包装类的值。
- 参数
    - `boolean`： 包装类指针。
- 返回值
    - 包装类的原生`bool`数据。



### Boolean_set()

- 原型

```c
void Boolean_set(Boolean *boolean, bool value);
```

- 描述
    - 设置`Boolean`包装类的值。
- 参数
    - `boolean`：包装类指针。
    - `value`：新值。



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



### Boolean_hash()

- 原型

```c
size_t Boolean_hash(const void *ptr);
```

- 描述
    - 返回`Boolean`包装类的哈希值。
- 参数
    - `ptr`：包装类指针。
- 返回值
    - 返回`Boolean`包装类的哈希值。
- 用例

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

