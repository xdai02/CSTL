#include "utils/wrapper.h"
#include "utils/exception.h"
#include "utils/numeric.h"
#include <stdint.h>

/**
 * @brief A wrapper for the primitive data type char.
 */
struct Character {
    char value;
};

/**
 * @brief Creates a new Character wrapper.
 * @param value The value of the char to be wrapped.
 * @return Returns a pointer to the newly created Character wrapper.
 */
Character *Character_new(char value) {
    Character *character = (Character *)malloc(sizeof(Character));
    return_value_if_fail(character != NULL, NULL);
    character->value = value;
    return character;
}

/**
 * @brief Destroys the given Character wrapper.
 * @param ptr The pointer to the Character wrapper to be destroyed.
 */
void Character_delete(void *ptr) {
    Character *character = NULL;
    return_if_fail(ptr != NULL);
    character = (Character *)ptr;
    free(character);
}

/**
 * @brief Returns the value of the given Character wrapper.
 * @param character The pointer to the Character wrapper.
 * @return The primitive char value of the given Character wrapper.
 */
char Character_get(const Character *character) {
    exit_if_fail(character != NULL);
    return character->value;
}

/**
 * @brief Sets the value of the given Character wrapper.
 * @param character The pointer to the wrapper.
 * @param value The new value of the wrapper.
 */
void Character_set(Character *character, char value) {
    return_if_fail(character != NULL);
    character->value = value;
}

/**
 * @brief Checks if two Character wrappers are equal.
 * @param character1 The pointer to the first Character wrapper to be compared.
 * @param character2 The pointer to the second Character wrapper to be compared.
 * @return Returns true if the primitive char values of the two Character wrappers are equal, false otherwise.
 */
bool Character_equals(const Character *character1, const Character *character2) {
    return_value_if_fail(character1 != NULL && character2 != NULL, false);
    return character1->value == character2->value;
}

/**
 * @brief Compares two Character wrappers.
 * @param ptr1 The pointer to the first Character wrapper to be compared.
 * @param ptr2 The pointer to the second Character wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Character_compare(const void *ptr1, const void *ptr2) {
    Character *character1 = NULL;
    Character *character2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    character1 = (Character *)ptr1;
    character2 = (Character *)ptr2;

    if (character1->value == character2->value) {
        return 0;
    } else if (character1->value < character2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Character wrapper.
 * @param ptr The pointer to the Character wrapper.
 * @return The hash code of the given Character wrapper.
 */
size_t Character_hash(const void *ptr) {
    Character *character = NULL;
    exit_if_fail(ptr != NULL);
    character = (Character *)ptr;
    return (size_t)character->value;
}

/**
 * @brief A wrapper for the primitive data type unsigned char.
 */
struct UnsignedCharacter {
    unsigned char value;
};

/**
 * @brief Creates a new UnsignedCharacter wrapper.
 * @param value The value of the unsigned char to be wrapped.
 * @return Returns a pointer to the newly created UnsignedCharacter wrapper.
 */
UnsignedCharacter *UnsignedCharacter_new(unsigned char value) {
    UnsignedCharacter *uc = (UnsignedCharacter *)malloc(sizeof(UnsignedCharacter));
    return_value_if_fail(uc != NULL, NULL);
    uc->value = value;
    return uc;
}

/**
 * @brief Destroys the given UnsignedCharacter wrapper.
 * @param ptr The pointer to the UnsignedCharacter wrapper to be destroyed.
 */
void UnsignedCharacter_delete(void *ptr) {
    UnsignedCharacter *uc = NULL;
    return_if_fail(ptr != NULL);
    uc = (UnsignedCharacter *)ptr;
    free(uc);
}

/**
 * @brief Returns the value of the given UnsignedCharacter wrapper.
 * @param uc The pointer to the UnsignedCharacter wrapper.
 * @return The primitive unsigned char value of the given UnsignedCharacter wrapper.
 */
unsigned char UnsignedCharacter_get(const UnsignedCharacter *uc) {
    exit_if_fail(uc != NULL);
    return uc->value;
}

/**
 * @brief Sets the value of the given UnsignedCharacter wrapper.
 * @param uc The pointer to the wrapper.
 * @param value The new value of the wrapper.
 */
void UnsignedCharacter_set(UnsignedCharacter *uc, unsigned char value) {
    return_if_fail(uc != NULL);
    uc->value = value;
}

/**
 * @brief Checks if two UnsignedCharacter wrappers are equal.
 * @param uc1 The pointer to the first UnsignedCharacter wrapper to be compared.
 * @param uc2 The pointer to the second UnsignedCharacter wrapper to be compared.
 * @return Returns true if the primitive unsigned char values of the two UnsignedCharacter wrappers are equal, false otherwise.
 */
bool UnsignedCharacter_equals(const UnsignedCharacter *uc1, const UnsignedCharacter *uc2) {
    return_value_if_fail(uc1 != NULL && uc2 != NULL, false);
    return uc1->value == uc2->value;
}

/**
 * @brief Compares two UnsignedCharacter wrappers.
 * @param ptr1 The pointer to the first UnsignedCharacter wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedCharacter wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2) {
    UnsignedCharacter *uc1 = NULL;
    UnsignedCharacter *uc2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    uc1 = (UnsignedCharacter *)ptr1;
    uc2 = (UnsignedCharacter *)ptr2;

    if (uc1->value == uc2->value) {
        return 0;
    } else if (uc1->value < uc2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given UnsignedCharacter wrapper.
 * @param ptr The pointer to the UnsignedCharacter wrapper.
 * @return The hash code of the given UnsignedCharacter wrapper.
 */
size_t UnsignedCharacter_hash(const void *ptr) {
    UnsignedCharacter *uc = NULL;
    exit_if_fail(ptr != NULL);
    uc = (UnsignedCharacter *)ptr;
    return (size_t)uc->value;
}

/**
 * @brief A wrapper for the primitive data type short.
 */
struct Short {
    short value;
};

/**
 * @brief Creates a new Short wrapper.
 * @param value The value of the short to be wrapped.
 * @return Returns a pointer to the newly created Short wrapper.
 */
Short *Short_new(short value) {
    Short *s = (Short *)malloc(sizeof(Short));
    return_value_if_fail(s != NULL, NULL);
    s->value = value;
    return s;
}

/**
 * @brief Destroys the given Short wrapper.
 * @param ptr The pointer to the Short wrapper to be destroyed.
 */
void Short_delete(void *ptr) {
    Short *s = NULL;
    return_if_fail(ptr != NULL);
    s = (Short *)ptr;
    free(s);
}

/**
 * @brief Returns the value of the given Short wrapper.
 * @param s The pointer to the Short wrapper.
 * @return The primitive short value of the given Short wrapper.
 */
short Short_get(const Short *s) {
    exit_if_fail(s != NULL);
    return s->value;
}

/**
 * @brief Sets the value of the given Short wrapper.
 * @param s The pointer to the wrapper.
 * @param value The new value of the wrapper.
 */
void Short_set(Short *s, short value) {
    return_if_fail(s != NULL);
    s->value = value;
}

/**
 * @brief Checks if two Short wrappers are equal.
 * @param short1 The pointer to the first Short wrapper to be compared.
 * @param short2 The pointer to the second Short wrapper to be compared.
 * @return Returns true if the primitive short values of the two Short wrappers are equal, false otherwise.
 */
bool Short_equals(const Short *short1, const Short *short2) {
    return_value_if_fail(short1 != NULL && short2 != NULL, false);
    return short1->value == short2->value;
}

/**
 * @brief Compares two Short wrappers.
 * @param ptr1 The pointer to the first Short wrapper to be compared.
 * @param ptr2 The pointer to the second Short wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Short_compare(const void *ptr1, const void *ptr2) {
    Short *short1 = NULL;
    Short *short2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    short1 = (Short *)ptr1;
    short2 = (Short *)ptr2;

    if (short1->value == short2->value) {
        return 0;
    } else if (short1->value < short2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Short wrapper.
 * @param ptr The pointer to the Short wrapper.
 * @return The hash code of the given Short wrapper.
 */
size_t Short_hash(const void *ptr) {
    Short *s = NULL;
    exit_if_fail(ptr != NULL);
    s = (Short *)ptr;
    return (size_t)s->value;
}

/**
 * @brief A wrapper for the primitive data type unsigned short.
 */
struct UnsignedShort {
    unsigned short value;
};

/**
 * @brief Creates a new UnsignedShort wrapper.
 * @param value The value of the unsigned short to be wrapped.
 * @return Returns a pointer to the newly created UnsignedShort wrapper.
 */
UnsignedShort *UnsignedShort_new(unsigned short value) {
    UnsignedShort *us = (UnsignedShort *)malloc(sizeof(UnsignedShort));
    return_value_if_fail(us != NULL, NULL);
    us->value = value;
    return us;
}

/**
 * @brief Destroys the given UnsignedShort wrapper.
 * @param ptr The pointer to the UnsignedShort wrapper to be destroyed.
 */
void UnsignedShort_delete(void *ptr) {
    UnsignedShort *us = NULL;
    return_if_fail(ptr != NULL);
    us = (UnsignedShort *)ptr;
    free(us);
}

/**
 * @brief Returns the value of the given UnsignedShort wrapper.
 * @param us The pointer to the UnsignedShort wrapper.
 * @return The primitive unsigned short value of the given UnsignedShort wrapper.
 */
unsigned short UnsignedShort_get(const UnsignedShort *us) {
    exit_if_fail(us != NULL);
    return us->value;
}

/**
 * @brief Sets the value of the given UnsignedShort wrapper.
 * @param us The pointer to the UnsignedShort wrapper.
 * @param value The new value of the UnsignedShort wrapper.
 */
void UnsignedShort_set(UnsignedShort *us, unsigned short value) {
    return_if_fail(us != NULL);
    us->value = value;
}

/**
 * @brief Checks if two UnsignedShort wrappers are equal.
 * @param us1 The pointer to the first UnsignedShort wrapper to be compared.
 * @param us2 The pointer to the second UnsignedShort wrapper to be compared.
 * @return Returns true if the primitive unsigned short values of the two UnsignedShort wrappers are equal, false otherwise.
 */
bool UnsignedShort_equals(const UnsignedShort *us1, const UnsignedShort *us2) {
    return_value_if_fail(us1 != NULL && us2 != NULL, false);
    return us1->value == us2->value;
}

/**
 * @brief Compares two UnsignedShort wrappers.
 * @param ptr1 The pointer to the first UnsignedShort wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedShort wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedShort_compare(const void *ptr1, const void *ptr2) {
    UnsignedShort *us1 = NULL;
    UnsignedShort *us2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    us1 = (UnsignedShort *)ptr1;
    us2 = (UnsignedShort *)ptr2;

    if (us1->value == us2->value) {
        return 0;
    } else if (us1->value < us2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given UnsignedShort wrapper.
 * @param ptr The pointer to the UnsignedShort wrapper.
 * @return The hash code of the given UnsignedShort wrapper.
 */
size_t UnsignedShort_hash(const void *ptr) {
    UnsignedShort *us = NULL;
    exit_if_fail(ptr != NULL);
    us = (UnsignedShort *)ptr;
    return (size_t)us->value;
}

/**
 * @brief A wrapper for the primitive data type int.
 */
struct Integer {
    int value;
};

/**
 * @brief Creates a new Integer wrapper.
 * @param value The value of the int to be wrapped.
 * @return Returns a pointer to the newly created Integer wrapper.
 */
Integer *Integer_new(int value) {
    Integer *integer = (Integer *)malloc(sizeof(Integer));
    return_value_if_fail(integer != NULL, NULL);
    integer->value = value;
    return integer;
}

/**
 * @brief Destroys the given Integer wrapper.
 * @param ptr The pointer to the Integer wrapper to be destroyed.
 */
void Integer_delete(void *ptr) {
    Integer *integer = NULL;
    return_if_fail(ptr != NULL);
    integer = (Integer *)ptr;
    free(integer);
}

/**
 * @brief Returns the value of the given Integer wrapper.
 * @param integer The pointer to the Integer wrapper.
 * @return The primitive int value of the given Integer wrapper.
 */
int Integer_get(const Integer *integer) {
    exit_if_fail(integer != NULL);
    return integer->value;
}

/**
 * @brief Sets the value of the given Integer wrapper.
 * @param integer The pointer to the Integer wrapper.
 * @param value The new value of the Integer wrapper.
 */
void Integer_set(Integer *integer, int value) {
    return_if_fail(integer != NULL);
    integer->value = value;
}

/**
 * @brief Checks if two Integer wrappers are equal.
 * @param integer1 The pointer to the first Integer wrapper to be compared.
 * @param integer2 The pointer to the second Integer wrapper to be compared.
 * @return Returns true if the primitive int values of the two Integer wrappers are equal, false otherwise.
 */
bool Integer_equals(const Integer *integer1, const Integer *integer2) {
    return_value_if_fail(integer1 != NULL && integer2 != NULL, false);
    return integer1->value == integer2->value;
}

/**
 * @brief Compares two Integer wrappers.
 * @param ptr1 The pointer to the first Integer wrapper to be compared.
 * @param ptr2 The pointer to the second Integer wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Integer_compare(const void *ptr1, const void *ptr2) {
    Integer *integer1 = NULL;
    Integer *integer2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    integer1 = (Integer *)ptr1;
    integer2 = (Integer *)ptr2;

    if (integer1->value == integer2->value) {
        return 0;
    } else if (integer1->value < integer2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Integer wrapper.
 * @param ptr The pointer to the Integer wrapper.
 * @return The hash code of the given Integer wrapper.
 */
size_t Integer_hash(const void *ptr) {
    Integer *integer = NULL;
    exit_if_fail(ptr != NULL);
    integer = (Integer *)ptr;
    return (size_t)integer->value;
}

/**
 * @brief A wrapper for the primitive data type unsigned int.
 */
struct UnsignedInteger {
    unsigned int value;
};

/**
 * @brief Creates a new UnsignedInteger wrapper.
 * @param value The value of the unsigned int to be wrapped.
 * @return Returns a pointer to the newly created UnsignedInteger wrapper.
 */
UnsignedInteger *UnsignedInteger_new(unsigned int value) {
    UnsignedInteger *ui = (UnsignedInteger *)malloc(sizeof(UnsignedInteger));
    return_value_if_fail(ui != NULL, NULL);
    ui->value = value;
    return ui;
}

/**
 * @brief Destroys the given UnsignedInteger wrapper.
 * @param ptr The pointer to the UnsignedInteger wrapper to be destroyed.
 */
void UnsignedInteger_delete(void *ptr) {
    UnsignedInteger *ui = NULL;
    return_if_fail(ptr != NULL);
    ui = (UnsignedInteger *)ptr;
    free(ui);
}

/**
 * @brief Returns the value of the given UnsignedInteger wrapper.
 * @param ui The pointer to the UnsignedInteger wrapper.
 * @return The primitive unsigned int value of the given UnsignedInteger wrapper.
 */
unsigned int UnsignedInteger_get(const UnsignedInteger *ui) {
    exit_if_fail(ui != NULL);
    return ui->value;
}

/**
 * @brief Sets the value of the given UnsignedInteger wrapper.
 * @param ui The pointer to the UnsignedInteger wrapper.
 * @param value The new value of the UnsignedInteger wrapper.
 */
void UnsignedInteger_set(UnsignedInteger *ui, unsigned int value) {
    return_if_fail(ui != NULL);
    ui->value = value;
}

/**
 * @brief Checks if two UnsignedInteger wrappers are equal.
 * @param ui1 The pointer to the first UnsignedInteger wrapper to be compared.
 * @param ui2 The pointer to the second UnsignedInteger wrapper to be compared.
 * @return Returns true if the primitive unsigned int values of the two UnsignedInteger wrappers are equal, false otherwise.
 */
bool UnsignedInteger_equals(const UnsignedInteger *ui1, const UnsignedInteger *ui2) {
    return_value_if_fail(ui1 != NULL && ui2 != NULL, false);
    return ui1->value == ui2->value;
}

/**
 * @brief Compares two UnsignedInteger wrappers.
 * @param ptr1 The pointer to the first UnsignedInteger wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedInteger wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedInteger_compare(const void *ptr1, const void *ptr2) {
    UnsignedInteger *ui1 = NULL;
    UnsignedInteger *ui2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    ui1 = (UnsignedInteger *)ptr1;
    ui2 = (UnsignedInteger *)ptr2;

    if (ui1->value == ui2->value) {
        return 0;
    } else if (ui1->value < ui2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given UnsignedInteger wrapper.
 * @param ptr The pointer to the UnsignedInteger wrapper.
 * @return The hash code of the given UnsignedInteger wrapper.
 */
size_t UnsignedInteger_hash(const void *ptr) {
    UnsignedInteger *ui = NULL;
    exit_if_fail(ptr != NULL);
    ui = (UnsignedInteger *)ptr;
    return (size_t)ui->value;
}

/**
 * @brief A wrapper for the primitive data type long.
 */
struct Long {
    long value;
};

/**
 * @brief Creates a new Long wrapper.
 * @param value The value of the long to be wrapped.
 * @return Returns a pointer to the newly created Long wrapper.
 */
Long *Long_new(long value) {
    Long *l = (Long *)malloc(sizeof(Long));
    return_value_if_fail(l != NULL, NULL);
    l->value = value;
    return l;
}

/**
 * @brief Destroys the given Long wrapper.
 * @param ptr The pointer to the Long wrapper to be destroyed.
 */
void Long_delete(void *ptr) {
    Long *l = NULL;
    return_if_fail(ptr != NULL);
    l = (Long *)ptr;
    free(l);
}

/**
 * @brief Returns the value of the given Long wrapper.
 * @param l The pointer to the Long wrapper.
 * @return The primitive long value of the given Long wrapper.
 */
long Long_get(const Long *l) {
    exit_if_fail(l != NULL);
    return l->value;
}

/**
 * @brief Sets the value of the given Long wrapper.
 * @param l The pointer to the Long wrapper.
 * @param value The new value of the Long wrapper.
 */
void Long_set(Long *l, long value) {
    return_if_fail(l != NULL);
    l->value = value;
}

/**
 * @brief Checks if two Long wrappers are equal.
 * @param long1 The pointer to the first Long wrapper to be compared.
 * @param long2 The pointer to the second Long wrapper to be compared.
 * @return Returns true if the primitive long values of the two Long wrappers are equal, false otherwise.
 */
bool Long_equals(const Long *long1, const Long *long2) {
    return_value_if_fail(long1 != NULL && long2 != NULL, false);
    return long1->value == long2->value;
}

/**
 * @brief Compares two Long wrappers.
 * @param ptr1 The pointer to the first Long wrapper to be compared.
 * @param ptr2 The pointer to the second Long wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Long_compare(const void *ptr1, const void *ptr2) {
    Long *long1 = NULL;
    Long *long2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    long1 = (Long *)ptr1;
    long2 = (Long *)ptr2;

    if (long1->value == long2->value) {
        return 0;
    } else if (long1->value < long2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Long wrapper.
 * @param ptr The pointer to the Long wrapper.
 * @return The hash code of the given Long wrapper.
 */
size_t Long_hash(const void *ptr) {
    Long *l = NULL;
    exit_if_fail(ptr != NULL);
    l = (Long *)ptr;
    return (size_t)l->value;
}

/**
 * @brief A wrapper for the primitive data type unsigned long.
 */
struct UnsignedLong {
    unsigned long value;
};

/**
 * @brief Creates a new UnsignedLong wrapper.
 * @param value The value of the unsigned long to be wrapped.
 * @return Returns a pointer to the newly created UnsignedLong wrapper.
 */
UnsignedLong *UnsignedLong_new(unsigned long value) {
    UnsignedLong *ul = (UnsignedLong *)malloc(sizeof(UnsignedLong));
    return_value_if_fail(ul != NULL, NULL);
    ul->value = value;
    return ul;
}

/**
 * @brief Destroys the given UnsignedLong wrapper.
 * @param ptr The pointer to the UnsignedLong wrapper to be destroyed.
 */
void UnsignedLong_delete(void *ptr) {
    UnsignedLong *ul = NULL;
    return_if_fail(ptr != NULL);
    ul = (UnsignedLong *)ptr;
    free(ul);
}

/**
 * @brief Returns the value of the given UnsignedLong wrapper.
 * @param ul The pointer to the UnsignedLong wrapper.
 * @return The primitive unsigned long value of the given UnsignedLong wrapper.
 */
unsigned long UnsignedLong_get(const UnsignedLong *ul) {
    exit_if_fail(ul != NULL);
    return ul->value;
}

/**
 * @brief Sets the value of the given UnsignedLong wrapper.
 * @param ul The pointer to the UnsignedLong wrapper.
 * @param value The new value of the UnsignedLong wrapper.
 */
void UnsignedLong_set(UnsignedLong *ul, unsigned long value) {
    return_if_fail(ul != NULL);
    ul->value = value;
}

/**
 * @brief Checks if two UnsignedLong wrappers are equal.
 * @param ul1 The pointer to the first UnsignedLong wrapper to be compared.
 * @param ul2 The pointer to the second UnsignedLong wrapper to be compared.
 * @return Returns true if the primitive unsigned long values of the two UnsignedLong wrappers are equal, false otherwise.
 */
bool UnsignedLong_equals(const UnsignedLong *ul1, const UnsignedLong *ul2) {
    return_value_if_fail(ul1 != NULL && ul2 != NULL, false);
    return ul1->value == ul2->value;
}

/**
 * @brief Compares two UnsignedLong wrappers.
 * @param ptr1 The pointer to the first UnsignedLong wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedLong wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedLong_compare(const void *ptr1, const void *ptr2) {
    UnsignedLong *ul1 = NULL;
    UnsignedLong *ul2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    ul1 = (UnsignedLong *)ptr1;
    ul2 = (UnsignedLong *)ptr2;

    if (ul1->value == ul2->value) {
        return 0;
    } else if (ul1->value < ul2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given UnsignedLong wrapper.
 * @param ptr The pointer to the UnsignedLong wrapper.
 * @return The hash code of the given UnsignedLong wrapper.
 */
size_t UnsignedLong_hash(const void *ptr) {
    UnsignedLong *ul = NULL;
    exit_if_fail(ptr != NULL);
    ul = (UnsignedLong *)ptr;
    return (size_t)ul->value;
}

/**
 * @brief A wrapper for the primitive data type long long.
 */
struct Float {
    float value;
};

/**
 * @brief Creates a new Float wrapper.
 * @param value The value of the float to be wrapped.
 * @return Returns a pointer to the newly created Float wrapper.
 */
Float *Float_new(float value) {
    Float *f = (Float *)malloc(sizeof(Float));
    return_value_if_fail(f != NULL, NULL);
    f->value = value;
    return f;
}

/**
 * @brief Destroys the given Float wrapper.
 * @param ptr The pointer to the Float wrapper to be destroyed.
 */
void Float_delete(void *ptr) {
    Float *f = NULL;
    return_if_fail(ptr != NULL);
    f = (Float *)ptr;
    free(f);
}

/**
 * @brief Returns the value of the given Float wrapper.
 * @param f The pointer to the Float wrapper.
 * @return The primitive float value of the given Float wrapper.
 */
float Float_get(const Float *f) {
    exit_if_fail(f != NULL);
    return f->value;
}

/**
 * @brief Sets the value of the given Float wrapper.
 * @param f The pointer to the Float wrapper.
 * @param value The new value of the Float wrapper.
 */
void Float_set(Float *f, float value) {
    return_if_fail(f != NULL);
    f->value = value;
}

/**
 * @brief Checks if two Float wrappers are equal.
 * @param float1 The pointer to the first Float wrapper to be compared.
 * @param float2 The pointer to the second Float wrapper to be compared.
 * @return Returns true if the primitive float values of the two Float wrappers are equal, false otherwise.
 */
bool Float_equals(const Float *float1, const Float *float2) {
    return_value_if_fail(float1 != NULL && float2 != NULL, false);
    return float_equal(float1->value, float2->value);
}

/**
 * @brief Compares two Float wrappers.
 * @param ptr1 The pointer to the first Float wrapper to be compared.
 * @param ptr2 The pointer to the second Float wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Float_compare(const void *ptr1, const void *ptr2) {
    Float *float1 = NULL;
    Float *float2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    float1 = (Float *)ptr1;
    float2 = (Float *)ptr2;

    if (float_equal(float1->value, float2->value)) {
        return 0;
    } else if (float1->value < float2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Float wrapper.
 * @param ptr The pointer to the Float wrapper.
 * @return The hash code of the given Float wrapper.
 */
size_t Float_hash(const void *ptr) {
    Float *f = NULL;
    uint32_t bits;

    exit_if_fail(ptr != NULL);
    f = (Float *)ptr;
    bits = *((uint32_t *)&f->value);
    return (size_t)bits;
}

/**
 * @brief A wrapper for the primitive data type long long.
 */
struct Double {
    double value;
};

/**
 * @brief Creates a new Double wrapper.
 * @param value The value of the double to be wrapped.
 * @return Returns a pointer to the newly created Double wrapper.
 */
Double *Double_new(double value) {
    Double *d = (Double *)malloc(sizeof(Double));
    return_value_if_fail(d != NULL, NULL);
    d->value = value;
    return d;
}

/**
 * @brief Destroys the given Double wrapper.
 * @param ptr The pointer to the Double wrapper to be destroyed.
 */
void Double_delete(void *ptr) {
    Double *d = NULL;
    return_if_fail(ptr != NULL);
    d = (Double *)ptr;
    free(d);
}

/**
 * @brief Returns the value of the given Double wrapper.
 * @param d The pointer to the Double wrapper.
 * @return The primitive double value of the given Double wrapper.
 */
double Double_get(const Double *d) {
    exit_if_fail(d != NULL);
    return d->value;
}

/**
 * @brief Sets the value of the given Double wrapper.
 * @param d The pointer to the Double wrapper.
 * @param value The new value of the Double wrapper.
 */
void Double_set(Double *d, double value) {
    return_if_fail(d != NULL);
    d->value = value;
}

/**
 * @brief Checks if two Double wrappers are equal.
 * @param double1 The pointer to the first Double wrapper to be compared.
 * @param double2 The pointer to the second Double wrapper to be compared.
 * @return Returns true if the primitive double values of the two Double wrappers are equal, false otherwise.
 */
bool Double_equals(const Double *double1, const Double *double2) {
    return_value_if_fail(double1 != NULL && double2 != NULL, false);
    return double_equal(double1->value, double2->value);
}

/**
 * @brief Compares two Double wrappers.
 * @param ptr1 The pointer to the first Double wrapper to be compared.
 * @param ptr2 The pointer to the second Double wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Double_compare(const void *ptr1, const void *ptr2) {
    Double *double1 = NULL;
    Double *double2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    double1 = (Double *)ptr1;
    double2 = (Double *)ptr2;

    if (double_equal(double1->value, double2->value)) {
        return 0;
    } else if (double1->value < double2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Double wrapper.
 * @param ptr The pointer to the Double wrapper.
 * @return The hash code of the given Double wrapper.
 */
size_t Double_hash(const void *ptr) {
    Double *d = NULL;
    uint64_t bits;

    exit_if_fail(ptr != NULL);
    d = (Double *)ptr;
    bits = *((uint64_t *)&d->value);
    return (size_t)bits;
}

/**
 * @brief A wrapper for the primitive data type bool.
 */
struct Boolean {
    bool value;
};

/**
 * @brief Creates a new Boolean wrapper.
 * @param value The value of the bool to be wrapped.
 * @return Returns a pointer to the newly created Boolean wrapper.
 */
Boolean *Boolean_new(bool value) {
    Boolean *boolean = (Boolean *)malloc(sizeof(Boolean));
    return_value_if_fail(boolean != NULL, NULL);
    boolean->value = value;
    return boolean;
}

/**
 * @brief Destroys the given Boolean wrapper.
 * @param ptr The pointer to the Boolean wrapper to be destroyed.
 */
void Boolean_delete(void *ptr) {
    Boolean *boolean = NULL;
    return_if_fail(ptr != NULL);
    boolean = (Boolean *)ptr;
    free(boolean);
}

/**
 * @brief Returns the value of the given Boolean wrapper.
 * @param boolean The pointer to the Boolean wrapper.
 * @return The primitive bool value of the given Boolean wrapper.
 */
bool Boolean_get(const Boolean *boolean) {
    exit_if_fail(boolean != NULL);
    return boolean->value;
}

/**
 * @brief Sets the value of the given Boolean wrapper.
 * @param boolean The pointer to the Boolean wrapper.
 * @param value The new value of the Boolean wrapper.
 */
void Boolean_set(Boolean *boolean, bool value) {
    return_if_fail(boolean != NULL);
    boolean->value = value;
}

/**
 * @brief Checks if two Boolean wrappers are equal.
 * @param boolean1 The pointer to the first Boolean wrapper to be compared.
 * @param boolean2 The pointer to the second Boolean wrapper to be compared.
 * @return Returns true if the primitive bool values of the two Boolean wrappers are equal, false otherwise.
 */
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2) {
    return_value_if_fail(boolean1 != NULL && boolean2 != NULL, false);
    return boolean1->value == boolean2->value;
}

/**
 * @brief Compares two Boolean wrappers.
 * @param ptr1 The pointer to the first Boolean wrapper to be compared.
 * @param ptr2 The pointer to the second Boolean wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Boolean_compare(const void *ptr1, const void *ptr2) {
    Boolean *boolean1 = NULL;
    Boolean *boolean2 = NULL;

    exit_if_fail(ptr1 != NULL && ptr2 != NULL);

    boolean1 = (Boolean *)ptr1;
    boolean2 = (Boolean *)ptr2;

    if (boolean1->value == boolean2->value) {
        return 0;
    } else if (boolean1->value < boolean2->value) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * @brief Returns the hash code of the given Boolean wrapper.
 * @param ptr The pointer to the Boolean wrapper.
 * @return The hash code of the given Boolean wrapper.
 */
size_t Boolean_hash(const void *ptr) {
    Boolean *boolean = NULL;
    exit_if_fail(ptr != NULL);
    boolean = (Boolean *)ptr;
    return (size_t)boolean->value;
}
