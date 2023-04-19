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
    if (character == NULL) {
        Exception("Out of memory exception");
    }
    character->value = value;
    return character;
}

void Character_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Character *character = (Character *)ptr;
    free(character);
}

int Character_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    Character *character1 = (Character *)ptr1;
    Character *character2 = (Character *)ptr2;
    return character1->value - character2->value;
}

char Character_valueOf(const Character *character) {
    if (character == NULL) {
        Exception("Null pointer exception");
    }
    return character->value;
}

bool Character_equals(const Character *character1, const Character *character2) {
    if (character1 == NULL || character2 == NULL) {
        Exception("Null pointer exception");
    }
    return character1->value == character2->value;
}

UnsignedCharacter *UnsignedCharacter_new(unsigned char value) {
    UnsignedCharacter *unsigned_character = (UnsignedCharacter *)malloc(sizeof(UnsignedCharacter));
    if (unsigned_character == NULL) {
        Exception("Out of memory exception");
    }
    unsigned_character->value = value;
    return unsigned_character;
}

void UnsignedCharacter_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedCharacter *unsigned_character = (UnsignedCharacter *)ptr;
    free(unsigned_character);
}

int UnsignedCharacter_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedCharacter *unsigned_character1 = (UnsignedCharacter *)ptr1;
    UnsignedCharacter *unsigned_character2 = (UnsignedCharacter *)ptr2;
    return unsigned_character1->value - unsigned_character2->value;
}

unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character) {
    if (unsigned_character == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_character->value;
}

bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2) {
    if (unsigned_character1 == NULL || unsigned_character2 == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_character1->value == unsigned_character2->value;
}

Short *Short_new(short value) {
    Short *s = (Short *)malloc(sizeof(Short));
    if (s == NULL) {
        Exception("Out of memory exception");
    }
    s->value = value;
    return s;
}

void Short_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Short *s = (Short *)ptr;
    free(s);
}

int Short_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    Short *short1 = (Short *)ptr1;
    Short *short2 = (Short *)ptr2;
    return short1->value - short2->value;
}

short Short_valueOf(const Short *s) {
    if (s == NULL) {
        Exception("Null pointer exception");
    }
    return s->value;
}

bool Short_equals(const Short *short1, const Short *short2) {
    if (short1 == NULL || short2 == NULL) {
        Exception("Null pointer exception");
    }
    return short1->value == short2->value;
}

UnsignedShort *UnsignedShort_new(unsigned short value) {
    UnsignedShort *unsigned_short = (UnsignedShort *)malloc(sizeof(UnsignedShort));
    if (unsigned_short == NULL) {
        Exception("Out of memory exception");
    }
    unsigned_short->value = value;
    return unsigned_short;
}

void UnsignedShort_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedShort *unsigned_short = (UnsignedShort *)ptr;
    free(unsigned_short);
}

int UnsignedShort_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedShort *unsigned_short1 = (UnsignedShort *)ptr1;
    UnsignedShort *unsigned_short2 = (UnsignedShort *)ptr2;
    return unsigned_short1->value - unsigned_short2->value;
}

unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short) {
    if (unsigned_short == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_short->value;
}

bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2) {
    if (unsigned_short1 == NULL || unsigned_short2 == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_short1->value == unsigned_short2->value;
}

Integer *Integer_new(int value) {
    Integer *integer = (Integer *)malloc(sizeof(Integer));
    if (integer == NULL) {
        Exception("Out of memory exception");
    }
    integer->value = value;
    return integer;
}

void Integer_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Integer *integer = (Integer *)ptr;
    free(integer);
}

int Integer_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    Integer *integer1 = (Integer *)ptr1;
    Integer *integer2 = (Integer *)ptr2;
    return integer1->value - integer2->value;
}

int Integer_valueOf(const Integer *integer) {
    if (integer == NULL) {
        Exception("Null pointer exception");
    }
    return integer->value;
}

bool Integer_equals(const Integer *integer1, const Integer *integer2) {
    if (integer1 == NULL || integer2 == NULL) {
        Exception("Null pointer exception");
    }
    return integer1->value == integer2->value;
}

UnsignedInteger *UnsignedInteger_new(unsigned int value) {
    UnsignedInteger *unsigned_integer = (UnsignedInteger *)malloc(sizeof(UnsignedInteger));
    if (unsigned_integer == NULL) {
        Exception("Out of memory exception");
    }
    unsigned_integer->value = value;
    return unsigned_integer;
}

void UnsignedInteger_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedInteger *unsigned_integer = (UnsignedInteger *)ptr;
    free(unsigned_integer);
}

int UnsignedInteger_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedInteger *unsigned_integer1 = (UnsignedInteger *)ptr1;
    UnsignedInteger *unsigned_integer2 = (UnsignedInteger *)ptr2;
    return unsigned_integer1->value - unsigned_integer2->value;
}

unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer) {
    if (unsigned_integer == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_integer->value;
}

bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2) {
    if (unsigned_integer1 == NULL || unsigned_integer2 == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_integer1->value == unsigned_integer2->value;
}

Long *Long_new(long value) {
    Long *l = (Long *)malloc(sizeof(Long));
    if (l == NULL) {
        Exception("Out of memory exception");
    }
    l->value = value;
    return l;
}

void Long_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Long *l = (Long *)ptr;
    free(l);
}

int Long_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    Long *long1 = (Long *)ptr1;
    Long *long2 = (Long *)ptr2;
    return long1->value - long2->value;
}

long Long_valueOf(const Long *l) {
    if (l == NULL) {
        Exception("Null pointer exception");
    }
    return l->value;
}

bool Long_equals(const Long *long1, const Long *long2) {
    if (long1 == NULL || long2 == NULL) {
        Exception("Null pointer exception");
    }
    return long1->value == long2->value;
}

UnsignedLong *UnsignedLong_new(unsigned long value) {
    UnsignedLong *unsigned_long = (UnsignedLong *)malloc(sizeof(UnsignedLong));
    if (unsigned_long == NULL) {
        Exception("Out of memory exception");
    }
    unsigned_long->value = value;
    return unsigned_long;
}

void UnsignedLong_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedLong *unsigned_long = (UnsignedLong *)ptr;
    free(unsigned_long);
}

int UnsignedLong_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    UnsignedLong *unsigned_long1 = (UnsignedLong *)ptr1;
    UnsignedLong *unsigned_long2 = (UnsignedLong *)ptr2;
    return unsigned_long1->value - unsigned_long2->value;
}

unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long) {
    if (unsigned_long == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_long->value;
}

bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2) {
    if (unsigned_long1 == NULL || unsigned_long2 == NULL) {
        Exception("Null pointer exception");
    }
    return unsigned_long1->value == unsigned_long2->value;
}

Float *Float_new(float value) {
    Float *f = (Float *)malloc(sizeof(Float));
    if (f == NULL) {
        Exception("Out of memory exception");
    }
    f->value = value;
    return f;
}

void Float_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Float *f = (Float *)ptr;
    free(f);
}

int Float_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
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
    if (f == NULL) {
        Exception("Null pointer exception");
    }
    return f->value;
}

bool Float_equals(const Float *float1, const Float *float2) {
    if (float1 == NULL || float2 == NULL) {
        Exception("Null pointer exception");
    }
    return float_equal(float1->value, float2->value);
}

Double *Double_new(double value) {
    Double *d = (Double *)malloc(sizeof(Double));
    if (d == NULL) {
        Exception("Out of memory exception");
    }
    d->value = value;
    return d;
}

void Double_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Double *d = (Double *)ptr;
    free(d);
}

int Double_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
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
    if (d == NULL) {
        Exception("Null pointer exception");
    }
    return d->value;
}

bool Double_equals(const Double *double1, const Double *double2) {
    if (double1 == NULL || double2 == NULL) {
        Exception("Null pointer exception");
    }
    return double_equal(double1->value, double2->value);
}

LongDouble *LongDouble_new(long double value) {
    LongDouble *ld = (LongDouble *)malloc(sizeof(LongDouble));
    if (ld == NULL) {
        Exception("Out of memory exception");
    }
    ld->value = value;
    return ld;
}

void LongDouble_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    LongDouble *ld = (LongDouble *)ptr;
    free(ld);
}

int LongDouble_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
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
    if (ld == NULL) {
        Exception("Null pointer exception");
    }
    return ld->value;
}

bool LongDouble_equals(const LongDouble *long_double1, const LongDouble *long_double2) {
    if (long_double1 == NULL || long_double2 == NULL) {
        Exception("Null pointer exception");
    }
    return long_double_equal(long_double1->value, long_double2->value);
}

Boolean *Boolean_new(bool value) {
    Boolean *b = (Boolean *)malloc(sizeof(Boolean));
    if (b == NULL) {
        Exception("Out of memory exception");
    }
    b->value = value;
    return b;
}

void Boolean_delete(void *ptr) {
    if (ptr == NULL) {
        Exception("Null pointer exception");
    }
    Boolean *b = (Boolean *)ptr;
    free(b);
}

int Boolean_compare(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        Exception("Null pointer exception");
    }
    Boolean *boolean1 = (Boolean *)ptr1;
    Boolean *boolean2 = (Boolean *)ptr2;
    return boolean1->value - boolean2->value;
}

bool Boolean_valueOf(const Boolean *b) {
    if (b == NULL) {
        Exception("Null pointer exception");
    }
    return b->value;
}

bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2) {
    if (boolean1 == NULL || boolean2 == NULL) {
        Exception("Null pointer exception");
    }
    return boolean1->value == boolean2->value;
}
