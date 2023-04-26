#include "wrapper.h"

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
char Character_valueOf(const Character *character) {
    exit_if_fail(character != NULL);
    return character->value;
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
    return character1->value - character2->value;
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
    UnsignedCharacter *unsigned_character = (UnsignedCharacter *)malloc(sizeof(UnsignedCharacter));
    return_value_if_fail(unsigned_character != NULL, NULL);
    unsigned_character->value = value;
    return unsigned_character;
}

/**
 * @brief Destroys the given UnsignedCharacter wrapper.
 * @param ptr The pointer to the UnsignedCharacter wrapper to be destroyed.
 */
void UnsignedCharacter_delete(void *ptr) {
    UnsignedCharacter *unsigned_character = NULL;
    return_if_fail(ptr != NULL);
    unsigned_character = (UnsignedCharacter *)ptr;
    free(unsigned_character);
}

/**
 * @brief Returns the value of the given UnsignedCharacter wrapper.
 * @param unsigned_character The pointer to the UnsignedCharacter wrapper.
 * @return The primitive unsigned char value of the given UnsignedCharacter wrapper.
 */
unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character) {
    exit_if_fail(unsigned_character != NULL);
    return unsigned_character->value;
}

/**
 * @brief Checks if two UnsignedCharacter wrappers are equal.
 * @param unsigned_character1 The pointer to the first UnsignedCharacter wrapper to be compared.
 * @param unsigned_character2 The pointer to the second UnsignedCharacter wrapper to be compared.
 * @return Returns true if the primitive unsigned char values of the two UnsignedCharacter wrappers are equal, false otherwise.
 */
bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2) {
    return_value_if_fail(unsigned_character1 != NULL && unsigned_character2 != NULL, false);
    return unsigned_character1->value == unsigned_character2->value;
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
    UnsignedCharacter *unsigned_character1 = NULL;
    UnsignedCharacter *unsigned_character2 = NULL;
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    unsigned_character1 = (UnsignedCharacter *)ptr1;
    unsigned_character2 = (UnsignedCharacter *)ptr2;
    return unsigned_character1->value - unsigned_character2->value;
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
short Short_valueOf(const Short *s) {
    exit_if_fail(s != NULL);
    return s->value;
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
    return short1->value - short2->value;
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
    UnsignedShort *unsigned_short = (UnsignedShort *)malloc(sizeof(UnsignedShort));
    return_value_if_fail(unsigned_short != NULL, NULL);
    unsigned_short->value = value;
    return unsigned_short;
}

/**
 * @brief Destroys the given UnsignedShort wrapper.
 * @param ptr The pointer to the UnsignedShort wrapper to be destroyed.
 */
void UnsignedShort_delete(void *ptr) {
    UnsignedShort *unsigned_short = NULL;
    return_if_fail(ptr != NULL);
    unsigned_short = (UnsignedShort *)ptr;
    free(unsigned_short);
}

/**
 * @brief Returns the value of the given UnsignedShort wrapper.
 * @param unsigned_short The pointer to the UnsignedShort wrapper.
 * @return The primitive unsigned short value of the given UnsignedShort wrapper.
 */
unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short) {
    exit_if_fail(unsigned_short != NULL);
    return unsigned_short->value;
}

/**
 * @brief Checks if two UnsignedShort wrappers are equal.
 * @param unsigned_short1 The pointer to the first UnsignedShort wrapper to be compared.
 * @param unsigned_short2 The pointer to the second UnsignedShort wrapper to be compared.
 * @return Returns true if the primitive unsigned short values of the two UnsignedShort wrappers are equal, false otherwise.
 */
bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2) {
    return_value_if_fail(unsigned_short1 != NULL && unsigned_short2 != NULL, false);
    return unsigned_short1->value == unsigned_short2->value;
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
    UnsignedShort *unsigned_short1 = NULL;
    UnsignedShort *unsigned_short2 = NULL;
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    unsigned_short1 = (UnsignedShort *)ptr1;
    unsigned_short2 = (UnsignedShort *)ptr2;
    return unsigned_short1->value - unsigned_short2->value;
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
int Integer_valueOf(const Integer *integer) {
    exit_if_fail(integer != NULL);
    return integer->value;
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
    return integer1->value - integer2->value;
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
    UnsignedInteger *unsigned_integer = (UnsignedInteger *)malloc(sizeof(UnsignedInteger));
    return_value_if_fail(unsigned_integer != NULL, NULL);
    unsigned_integer->value = value;
    return unsigned_integer;
}

/**
 * @brief Destroys the given UnsignedInteger wrapper.
 * @param ptr The pointer to the UnsignedInteger wrapper to be destroyed.
 */
void UnsignedInteger_delete(void *ptr) {
    UnsignedInteger *unsigned_integer = NULL;
    return_if_fail(ptr != NULL);
    unsigned_integer = (UnsignedInteger *)ptr;
    free(unsigned_integer);
}

/**
 * @brief Returns the value of the given UnsignedInteger wrapper.
 * @param unsigned_integer The pointer to the UnsignedInteger wrapper.
 * @return The primitive unsigned int value of the given UnsignedInteger wrapper.
 */
unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer) {
    exit_if_fail(unsigned_integer != NULL);
    return unsigned_integer->value;
}

/**
 * @brief Checks if two UnsignedInteger wrappers are equal.
 * @param unsigned_integer1 The pointer to the first UnsignedInteger wrapper to be compared.
 * @param unsigned_integer2 The pointer to the second UnsignedInteger wrapper to be compared.
 * @return Returns true if the primitive unsigned int values of the two UnsignedInteger wrappers are equal, false otherwise.
 */
bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2) {
    return_value_if_fail(unsigned_integer1 != NULL && unsigned_integer2 != NULL, false);
    return unsigned_integer1->value == unsigned_integer2->value;
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
    UnsignedInteger *unsigned_integer1 = NULL;
    UnsignedInteger *unsigned_integer2 = NULL;
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    unsigned_integer1 = (UnsignedInteger *)ptr1;
    unsigned_integer2 = (UnsignedInteger *)ptr2;
    return unsigned_integer1->value - unsigned_integer2->value;
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
long Long_valueOf(const Long *l) {
    exit_if_fail(l != NULL);
    return l->value;
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
    return long1->value - long2->value;
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
    UnsignedLong *unsigned_long = (UnsignedLong *)malloc(sizeof(UnsignedLong));
    return_value_if_fail(unsigned_long != NULL, NULL);
    unsigned_long->value = value;
    return unsigned_long;
}

/**
 * @brief Destroys the given UnsignedLong wrapper.
 * @param ptr The pointer to the UnsignedLong wrapper to be destroyed.
 */
void UnsignedLong_delete(void *ptr) {
    UnsignedLong *unsigned_long = NULL;
    return_if_fail(ptr != NULL);
    unsigned_long = (UnsignedLong *)ptr;
    free(unsigned_long);
}

/**
 * @brief Returns the value of the given UnsignedLong wrapper.
 * @param unsigned_long The pointer to the UnsignedLong wrapper.
 * @return The primitive unsigned long value of the given UnsignedLong wrapper.
 */
unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long) {
    exit_if_fail(unsigned_long != NULL);
    return unsigned_long->value;
}

/**
 * @brief Checks if two UnsignedLong wrappers are equal.
 * @param unsigned_long1 The pointer to the first UnsignedLong wrapper to be compared.
 * @param unsigned_long2 The pointer to the second UnsignedLong wrapper to be compared.
 * @return Returns true if the primitive unsigned long values of the two UnsignedLong wrappers are equal, false otherwise.
 */
bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2) {
    return_value_if_fail(unsigned_long1 != NULL && unsigned_long2 != NULL, false);
    return unsigned_long1->value == unsigned_long2->value;
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
    UnsignedLong *unsigned_long1 = NULL;
    UnsignedLong *unsigned_long2 = NULL;
    exit_if_fail(ptr1 != NULL && ptr2 != NULL);
    unsigned_long1 = (UnsignedLong *)ptr1;
    unsigned_long2 = (UnsignedLong *)ptr2;
    return unsigned_long1->value - unsigned_long2->value;
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
float Float_valueOf(const Float *f) {
    exit_if_fail(f != NULL);
    return f->value;
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
double Double_valueOf(const Double *d) {
    exit_if_fail(d != NULL);
    return d->value;
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
    Boolean *b = (Boolean *)malloc(sizeof(Boolean));
    return_value_if_fail(b != NULL, NULL);
    b->value = value;
    return b;
}

/**
 * @brief Destroys the given Boolean wrapper.
 * @param ptr The pointer to the Boolean wrapper to be destroyed.
 */
void Boolean_delete(void *ptr) {
    Boolean *b = NULL;
    return_if_fail(ptr != NULL);
    b = (Boolean *)ptr;
    free(b);
}

/**
 * @brief Returns the value of the given Boolean wrapper.
 * @param boolean The pointer to the Boolean wrapper.
 * @return The primitive bool value of the given Boolean wrapper.
 */
bool Boolean_valueOf(const Boolean *b) {
    exit_if_fail(b != NULL);
    return b->value;
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
    return boolean1->value - boolean2->value;
}
