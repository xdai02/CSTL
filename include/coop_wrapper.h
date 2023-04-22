#ifndef _COOP_WRAPPER_H_
#define _COOP_WRAPPER_H_

#include "coop_utils.h"

typedef struct Character Character;
typedef struct UnsignedCharacter UnsignedCharacter;
typedef struct Short Short;
typedef struct UnsignedShort UnsignedShort;
typedef struct Integer Integer;
typedef struct UnsignedInteger UnsignedInteger;
typedef struct Long Long;
typedef struct UnsignedLong UnsignedLong;
typedef struct Float Float;
typedef struct Double Double;
typedef struct LongDouble LongDouble;
typedef struct Boolean Boolean;

Character *Character_new(char value);
void Character_delete(void *ptr);
int Character_compare(const void *ptr1, const void *ptr2);
char Character_valueOf(const Character *character);
bool Character_equals(const Character *character1, const Character *character2);

UnsignedCharacter *UnsignedCharacter_new(unsigned char value);
void UnsignedCharacter_delete(void *ptr);
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2);
unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character);
bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2);

Short *Short_new(short value);
void Short_delete(void *ptr);
int Short_compare(const void *ptr1, const void *ptr2);
short Short_valueOf(const Short *s);
bool Short_equals(const Short *short1, const Short *short2);

UnsignedShort *UnsignedShort_new(unsigned short value);
void UnsignedShort_delete(void *ptr);
int UnsignedShort_compare(const void *ptr1, const void *ptr2);
unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short);
bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2);

Integer *Integer_new(int value);
void Integer_delete(void *ptr);
int Integer_compare(const void *ptr1, const void *ptr2);
int Integer_valueOf(const Integer *integer);
bool Integer_equals(const Integer *integer1, const Integer *integer2);

UnsignedInteger *UnsignedInteger_new(unsigned int value);
void UnsignedInteger_delete(void *ptr);
int UnsignedInteger_compare(const void *ptr1, const void *ptr2);
unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer);
bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2);

Long *Long_new(long value);
void Long_delete(void *ptr);
int Long_compare(const void *ptr1, const void *ptr2);
long Long_valueOf(const Long *l);
bool Long_equals(const Long *long1, const Long *long2);

UnsignedLong *UnsignedLong_new(unsigned long value);
void UnsignedLong_delete(void *ptr);
int UnsignedLong_compare(const void *ptr1, const void *ptr2);
unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long);
bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2);

Float *Float_new(float value);
void Float_delete(void *ptr);
int Float_compare(const void *ptr1, const void *ptr2);
float Float_valueOf(const Float *f);
bool Float_equals(const Float *float1, const Float *float2);

Double *Double_new(double value);
void Double_delete(void *ptr);
int Double_compare(const void *ptr1, const void *ptr2);
double Double_valueOf(const Double *d);
bool Double_equals(const Double *double1, const Double *double2);

LongDouble *LongDouble_new(long double value);
void LongDouble_delete(void *ptr);
int LongDouble_compare(const void *ptr1, const void *ptr2);
long double LongDouble_valueOf(const LongDouble *long_double);
bool LongDouble_equals(const LongDouble *long_double1, const LongDouble *long_double2);

Boolean *Boolean_new(bool value);
void Boolean_delete(void *ptr);
int Boolean_compare(const void *ptr1, const void *ptr2);
bool Boolean_valueOf(const Boolean *boolean);
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2);

#endif
