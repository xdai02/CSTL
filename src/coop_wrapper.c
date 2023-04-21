#include "coop_wrapper.h"

typedef struct Character {
    char value;
} Character;

typedef struct UnsignedCharacter {
    unsigned char value;
} UnsignedCharacter;

typedef struct Short {
    short value;
} Short;

typedef struct UnsignedShort {
    unsigned short value;
} UnsignedShort;

typedef struct Integer {
    int value;
} Integer;

typedef struct UnsignedInteger {
    unsigned int value;
} UnsignedInteger;

typedef struct Long {
    long value;
} Long;

typedef struct UnsignedLong {
    unsigned long value;
} UnsignedLong;

typedef struct LongLong {
    long long value;
} LongLong;

typedef struct UnsignedLongLong {
    unsigned long long value;
} UnsignedLongLong;

typedef struct Float {
    float value;
} Float;

typedef struct Double {
    double value;
} Double;

typedef struct LongDouble {
    long double value;
} LongDouble;

typedef struct Boolean {
    bool value;
} Boolean;

Character *Character_new(char value) {
    Character *character = (Character *)malloc(sizeof(Character));
    return_value_if_fail(character != NULL, NULL);
    character->value = value;
    return character;
}

void Character_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Character *character = (Character *)ptr;
    free(character);
}

int Character_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    Character *character1 = (Character *)ptr1;
    Character *character2 = (Character *)ptr2;
    return character1->value - character2->value;
}

char Character_valueOf(const Character *character) {
    exit_if_fail(character != NULL);
    return character->value;
}

bool Character_equals(const Character *character1, const Character *character2) {
    exit_if_fail(character1 != NULL && character2 != NULL);
    return character1->value == character2->value;
}

UnsignedCharacter *UnsignedCharacter_new(unsigned char value) {
    UnsignedCharacter *unsigned_character = (UnsignedCharacter *)malloc(sizeof(UnsignedCharacter));
    return_value_if_fail(unsigned_character != NULL, NULL);
    unsigned_character->value = value;
    return unsigned_character;
}

void UnsignedCharacter_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    UnsignedCharacter *unsigned_character = (UnsignedCharacter *)ptr;
    free(unsigned_character);
}

int UnsignedCharacter_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    UnsignedCharacter *unsigned_character1 = (UnsignedCharacter *)ptr1;
    UnsignedCharacter *unsigned_character2 = (UnsignedCharacter *)ptr2;
    return unsigned_character1->value - unsigned_character2->value;
}

unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character) {
    exit_if_fail(unsigned_character != NULL);
    return unsigned_character->value;
}

bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2) {
    exit_if_fail(unsigned_character1 != NULL && unsigned_character2 != NULL);
    return unsigned_character1->value == unsigned_character2->value;
}

Short *Short_new(short value) {
    Short *s = (Short *)malloc(sizeof(Short));
    return_value_if_fail(s != NULL, NULL);
    s->value = value;
    return s;
}

void Short_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Short *s = (Short *)ptr;
    free(s);
}

int Short_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    Short *short1 = (Short *)ptr1;
    Short *short2 = (Short *)ptr2;
    return short1->value - short2->value;
}

short Short_valueOf(const Short *s) {
    exit_if_fail(s != NULL);
    return s->value;
}

bool Short_equals(const Short *short1, const Short *short2) {
    exit_if_fail(short1 != NULL && short2 != NULL);
    return short1->value == short2->value;
}

UnsignedShort *UnsignedShort_new(unsigned short value) {
    UnsignedShort *unsigned_short = (UnsignedShort *)malloc(sizeof(UnsignedShort));
    return_value_if_fail(unsigned_short != NULL, NULL);
    unsigned_short->value = value;
    return unsigned_short;
}

void UnsignedShort_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    UnsignedShort *unsigned_short = (UnsignedShort *)ptr;
    free(unsigned_short);
}

int UnsignedShort_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    UnsignedShort *unsigned_short1 = (UnsignedShort *)ptr1;
    UnsignedShort *unsigned_short2 = (UnsignedShort *)ptr2;
    return unsigned_short1->value - unsigned_short2->value;
}

unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short) {
    exit_if_fail(unsigned_short != NULL);
    return unsigned_short->value;
}

bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2) {
    exit_if_fail(unsigned_short1 != NULL && unsigned_short2 != NULL);
    return unsigned_short1->value == unsigned_short2->value;
}

Integer *Integer_new(int value) {
    Integer *integer = (Integer *)malloc(sizeof(Integer));
    return_value_if_fail(integer != NULL, NULL);
    integer->value = value;
    return integer;
}

void Integer_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Integer *integer = (Integer *)ptr;
    free(integer);
}

int Integer_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    Integer *integer1 = (Integer *)ptr1;
    Integer *integer2 = (Integer *)ptr2;
    return integer1->value - integer2->value;
}

int Integer_valueOf(const Integer *integer) {
    exit_if_fail(integer != NULL);
    return integer->value;
}

bool Integer_equals(const Integer *integer1, const Integer *integer2) {
    exit_if_fail(integer1 != NULL && integer2 != NULL);
    return integer1->value == integer2->value;
}

UnsignedInteger *UnsignedInteger_new(unsigned int value) {
    UnsignedInteger *unsigned_integer = (UnsignedInteger *)malloc(sizeof(UnsignedInteger));
    return_value_if_fail(unsigned_integer != NULL, NULL);
    unsigned_integer->value = value;
    return unsigned_integer;
}

void UnsignedInteger_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    UnsignedInteger *unsigned_integer = (UnsignedInteger *)ptr;
    free(unsigned_integer);
}

int UnsignedInteger_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    UnsignedInteger *unsigned_integer1 = (UnsignedInteger *)ptr1;
    UnsignedInteger *unsigned_integer2 = (UnsignedInteger *)ptr2;
    return unsigned_integer1->value - unsigned_integer2->value;
}

unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer) {
    exit_if_fail(unsigned_integer != NULL);
    return unsigned_integer->value;
}

bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2) {
    exit_if_fail(unsigned_integer1 != NULL && unsigned_integer2 != NULL);
    return unsigned_integer1->value == unsigned_integer2->value;
}

Long *Long_new(long value) {
    Long *l = (Long *)malloc(sizeof(Long));
    return_value_if_fail(l != NULL, NULL);
    l->value = value;
    return l;
}

void Long_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Long *l = (Long *)ptr;
    free(l);
}

int Long_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    Long *long1 = (Long *)ptr1;
    Long *long2 = (Long *)ptr2;
    return long1->value - long2->value;
}

long Long_valueOf(const Long *l) {
    exit_if_fail(l != NULL);
    return l->value;
}

bool Long_equals(const Long *long1, const Long *long2) {
    exit_if_fail(long1 != NULL && long2 != NULL);
    return long1->value == long2->value;
}

UnsignedLong *UnsignedLong_new(unsigned long value) {
    UnsignedLong *unsigned_long = (UnsignedLong *)malloc(sizeof(UnsignedLong));
    return_value_if_fail(unsigned_long != NULL, NULL);
    unsigned_long->value = value;
    return unsigned_long;
}

void UnsignedLong_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    UnsignedLong *unsigned_long = (UnsignedLong *)ptr;
    free(unsigned_long);
}

int UnsignedLong_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    UnsignedLong *unsigned_long1 = (UnsignedLong *)ptr1;
    UnsignedLong *unsigned_long2 = (UnsignedLong *)ptr2;
    return unsigned_long1->value - unsigned_long2->value;
}

unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long) {
    exit_if_fail(unsigned_long != NULL);
    return unsigned_long->value;
}

bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2) {
    exit_if_fail(unsigned_long1 != NULL && unsigned_long2 != NULL);
    return unsigned_long1->value == unsigned_long2->value;
}

Float *Float_new(float value) {
    Float *f = (Float *)malloc(sizeof(Float));
    return_value_if_fail(f != NULL, NULL);
    f->value = value;
    return f;
}

void Float_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Float *f = (Float *)ptr;
    free(f);
}

int Float_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    Float *float1 = (Float *)ptr1;
    Float *float2 = (Float *)ptr2;

    if (float_equal(float1->value, float2->value)) {
        return 0;
    } else if (float1->value < float2->value) {
        return -1;
    } else {
        return 1;
    }
}

float Float_valueOf(const Float *f) {
    exit_if_fail(f != NULL);
    return f->value;
}

bool Float_equals(const Float *float1, const Float *float2) {
    exit_if_fail(float1 != NULL && float2 != NULL);
    return float_equal(float1->value, float2->value);
}

Double *Double_new(double value) {
    Double *d = (Double *)malloc(sizeof(Double));
    return_value_if_fail(d != NULL, NULL);
    d->value = value;
    return d;
}

void Double_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Double *d = (Double *)ptr;
    free(d);
}

int Double_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    Double *double1 = (Double *)ptr1;
    Double *double2 = (Double *)ptr2;

    if (double_equal(double1->value, double2->value)) {
        return 0;
    } else if (double1->value < double2->value) {
        return -1;
    } else {
        return 1;
    }
}

double Double_valueOf(const Double *d) {
    exit_if_fail(d != NULL);
    return d->value;
}

bool Double_equals(const Double *double1, const Double *double2) {
    exit_if_fail(double1 != NULL && double2 != NULL);
    return double_equal(double1->value, double2->value);
}

LongDouble *LongDouble_new(long double value) {
    LongDouble *ld = (LongDouble *)malloc(sizeof(LongDouble));
    return_value_if_fail(ld != NULL, NULL);
    ld->value = value;
    return ld;
}

void LongDouble_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    LongDouble *ld = (LongDouble *)ptr;
    free(ld);
}

int LongDouble_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    LongDouble *long_double1 = (LongDouble *)ptr1;
    LongDouble *long_double2 = (LongDouble *)ptr2;

    if (long_double_equal(long_double1->value, long_double2->value)) {
        return 0;
    } else if (long_double1->value < long_double2->value) {
        return -1;
    } else {
        return 1;
    }
}

long double LongDouble_valueOf(const LongDouble *ld) {
    exit_if_fail(ld != NULL);
    return ld->value;
}

bool LongDouble_equals(const LongDouble *long_double1, const LongDouble *long_double2) {
    exit_if_fail(long_double1 != NULL && long_double2 != NULL);
    return long_double_equal(long_double1->value, long_double2->value);
}

Boolean *Boolean_new(bool value) {
    Boolean *b = (Boolean *)malloc(sizeof(Boolean));
    return_value_if_fail(b != NULL, NULL);
    b->value = value;
    return b;
}

void Boolean_delete(void *ptr) {
    return_if_fail(ptr != NULL);
    Boolean *b = (Boolean *)ptr;
    free(b);
}

int Boolean_compare(const void *ptr1, const void *ptr2) {
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    Boolean *boolean1 = (Boolean *)ptr1;
    Boolean *boolean2 = (Boolean *)ptr2;
    return boolean1->value - boolean2->value;
}

bool Boolean_valueOf(const Boolean *b) {
    exit_if_fail(b != NULL);
    return b->value;
}

bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2) {
    exit_if_fail(boolean1 != NULL && boolean2 != NULL);
    return boolean1->value == boolean2->value;
}
