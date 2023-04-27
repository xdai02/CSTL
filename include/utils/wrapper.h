#ifndef _WRAPPER_H_
#define _WRAPPER_H_

#include "types.h"

/**
 * @brief A wrapper for the primitive data type char.
 */
typedef struct Character Character;

/**
 * @brief Creates a new Character wrapper.
 * @param value The value of the char to be wrapped.
 * @return Returns a pointer to the newly created Character wrapper.
 */
Character *Character_new(char value);

/**
 * @brief Destroys the given Character wrapper.
 * @param ptr The pointer to the Character wrapper to be destroyed.
 */
void Character_delete(void *ptr);

/**
 * @brief Returns the value of the given Character wrapper.
 * @param character The pointer to the Character wrapper.
 * @return The primitive char value of the given Character wrapper.
 */
char Character_valueOf(const Character *character);

/**
 * @brief Checks if two Character wrappers are equal.
 * @param character1 The pointer to the first Character wrapper to be compared.
 * @param character2 The pointer to the second Character wrapper to be compared.
 * @return Returns true if the primitive char values of the two Character wrappers are equal, false otherwise.
 */
bool Character_equals(const Character *character1, const Character *character2);

/**
 * @brief Compares two Character wrappers.
 * @param ptr1 The pointer to the first Character wrapper to be compared.
 * @param ptr2 The pointer to the second Character wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Character_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type unsigned char.
 */
typedef struct UnsignedCharacter UnsignedCharacter;

/**
 * @brief Creates a new UnsignedCharacter wrapper.
 * @param value The value of the unsigned char to be wrapped.
 * @return Returns a pointer to the newly created UnsignedCharacter wrapper.
 */
UnsignedCharacter *UnsignedCharacter_new(unsigned char value);

/**
 * @brief Destroys the given UnsignedCharacter wrapper.
 * @param ptr The pointer to the UnsignedCharacter wrapper to be destroyed.
 */
void UnsignedCharacter_delete(void *ptr);

/**
 * @brief Returns the value of the given UnsignedCharacter wrapper.
 * @param unsigned_character The pointer to the UnsignedCharacter wrapper.
 * @return The primitive unsigned char value of the given UnsignedCharacter wrapper.
 */
unsigned char UnsignedCharacter_valueOf(const UnsignedCharacter *unsigned_character);

/**
 * @brief Checks if two UnsignedCharacter wrappers are equal.
 * @param unsigned_character1 The pointer to the first UnsignedCharacter wrapper to be compared.
 * @param unsigned_character2 The pointer to the second UnsignedCharacter wrapper to be compared.
 * @return Returns true if the primitive unsigned char values of the two UnsignedCharacter wrappers are equal, false otherwise.
 */
bool UnsignedCharacter_equals(const UnsignedCharacter *unsigned_character1, const UnsignedCharacter *unsigned_character2);

/**
 * @brief Compares two UnsignedCharacter wrappers.
 * @param ptr1 The pointer to the first UnsignedCharacter wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedCharacter wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedCharacter_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type short.
 */
typedef struct Short Short;

/**
 * @brief Creates a new Short wrapper.
 * @param value The value of the short to be wrapped.
 * @return Returns a pointer to the newly created Short wrapper.
 */
Short *Short_new(short value);

/**
 * @brief Destroys the given Short wrapper.
 * @param ptr The pointer to the Short wrapper to be destroyed.
 */
void Short_delete(void *ptr);

/**
 * @brief Returns the value of the given Short wrapper.
 * @param s The pointer to the Short wrapper.
 * @return The primitive short value of the given Short wrapper.
 */
short Short_valueOf(const Short *s);

/**
 * @brief Checks if two Short wrappers are equal.
 * @param short1 The pointer to the first Short wrapper to be compared.
 * @param short2 The pointer to the second Short wrapper to be compared.
 * @return Returns true if the primitive short values of the two Short wrappers are equal, false otherwise.
 */
bool Short_equals(const Short *short1, const Short *short2);

/**
 * @brief Compares two Short wrappers.
 * @param ptr1 The pointer to the first Short wrapper to be compared.
 * @param ptr2 The pointer to the second Short wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Short_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type unsigned short.
 */
typedef struct UnsignedShort UnsignedShort;

/**
 * @brief Creates a new UnsignedShort wrapper.
 * @param value The value of the unsigned short to be wrapped.
 * @return Returns a pointer to the newly created UnsignedShort wrapper.
 */
UnsignedShort *UnsignedShort_new(unsigned short value);

/**
 * @brief Destroys the given UnsignedShort wrapper.
 * @param ptr The pointer to the UnsignedShort wrapper to be destroyed.
 */
void UnsignedShort_delete(void *ptr);

/**
 * @brief Returns the value of the given UnsignedShort wrapper.
 * @param unsigned_short The pointer to the UnsignedShort wrapper.
 * @return The primitive unsigned short value of the given UnsignedShort wrapper.
 */
unsigned short UnsignedShort_valueOf(const UnsignedShort *unsigned_short);

/**
 * @brief Checks if two UnsignedShort wrappers are equal.
 * @param unsigned_short1 The pointer to the first UnsignedShort wrapper to be compared.
 * @param unsigned_short2 The pointer to the second UnsignedShort wrapper to be compared.
 * @return Returns true if the primitive unsigned short values of the two UnsignedShort wrappers are equal, false otherwise.
 */
bool UnsignedShort_equals(const UnsignedShort *unsigned_short1, const UnsignedShort *unsigned_short2);

/**
 * @brief Compares two UnsignedShort wrappers.
 * @param ptr1 The pointer to the first UnsignedShort wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedShort wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedShort_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type int.
 */
typedef struct Integer Integer;

/**
 * @brief Creates a new Integer wrapper.
 * @param value The value of the int to be wrapped.
 * @return Returns a pointer to the newly created Integer wrapper.
 */
Integer *Integer_new(int value);

/**
 * @brief Destroys the given Integer wrapper.
 * @param ptr The pointer to the Integer wrapper to be destroyed.
 */
void Integer_delete(void *ptr);

/**
 * @brief Returns the value of the given Integer wrapper.
 * @param integer The pointer to the Integer wrapper.
 * @return The primitive int value of the given Integer wrapper.
 */
int Integer_valueOf(const Integer *integer);

/**
 * @brief Checks if two Integer wrappers are equal.
 * @param integer1 The pointer to the first Integer wrapper to be compared.
 * @param integer2 The pointer to the second Integer wrapper to be compared.
 * @return Returns true if the primitive int values of the two Integer wrappers are equal, false otherwise.
 */
bool Integer_equals(const Integer *integer1, const Integer *integer2);

/**
 * @brief Compares two Integer wrappers.
 * @param ptr1 The pointer to the first Integer wrapper to be compared.
 * @param ptr2 The pointer to the second Integer wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Integer_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type unsigned int.
 */
typedef struct UnsignedInteger UnsignedInteger;

/**
 * @brief Creates a new UnsignedInteger wrapper.
 * @param value The value of the unsigned int to be wrapped.
 * @return Returns a pointer to the newly created UnsignedInteger wrapper.
 */
UnsignedInteger *UnsignedInteger_new(unsigned int value);

/**
 * @brief Destroys the given UnsignedInteger wrapper.
 * @param ptr The pointer to the UnsignedInteger wrapper to be destroyed.
 */
void UnsignedInteger_delete(void *ptr);

/**
 * @brief Returns the value of the given UnsignedInteger wrapper.
 * @param unsigned_integer The pointer to the UnsignedInteger wrapper.
 * @return The primitive unsigned int value of the given UnsignedInteger wrapper.
 */
unsigned int UnsignedInteger_valueOf(const UnsignedInteger *unsigned_integer);

/**
 * @brief Checks if two UnsignedInteger wrappers are equal.
 * @param unsigned_integer1 The pointer to the first UnsignedInteger wrapper to be compared.
 * @param unsigned_integer2 The pointer to the second UnsignedInteger wrapper to be compared.
 * @return Returns true if the primitive unsigned int values of the two UnsignedInteger wrappers are equal, false otherwise.
 */
bool UnsignedInteger_equals(const UnsignedInteger *unsigned_integer1, const UnsignedInteger *unsigned_integer2);

/**
 * @brief Compares two UnsignedInteger wrappers.
 * @param ptr1 The pointer to the first UnsignedInteger wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedInteger wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedInteger_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type long.
 */
typedef struct Long Long;

/**
 * @brief Creates a new Long wrapper.
 * @param value The value of the long to be wrapped.
 * @return Returns a pointer to the newly created Long wrapper.
 */
Long *Long_new(long value);

/**
 * @brief Destroys the given Long wrapper.
 * @param ptr The pointer to the Long wrapper to be destroyed.
 */
void Long_delete(void *ptr);

/**
 * @brief Returns the value of the given Long wrapper.
 * @param l The pointer to the Long wrapper.
 * @return The primitive long value of the given Long wrapper.
 */
long Long_valueOf(const Long *l);

/**
 * @brief Checks if two Long wrappers are equal.
 * @param long1 The pointer to the first Long wrapper to be compared.
 * @param long2 The pointer to the second Long wrapper to be compared.
 * @return Returns true if the primitive long values of the two Long wrappers are equal, false otherwise.
 */
bool Long_equals(const Long *long1, const Long *long2);

/**
 * @brief Compares two Long wrappers.
 * @param ptr1 The pointer to the first Long wrapper to be compared.
 * @param ptr2 The pointer to the second Long wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Long_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type unsigned long.
 */
typedef struct UnsignedLong UnsignedLong;

/**
 * @brief Creates a new UnsignedLong wrapper.
 * @param value The value of the unsigned long to be wrapped.
 * @return Returns a pointer to the newly created UnsignedLong wrapper.
 */
UnsignedLong *UnsignedLong_new(unsigned long value);

/**
 * @brief Destroys the given UnsignedLong wrapper.
 * @param ptr The pointer to the UnsignedLong wrapper to be destroyed.
 */
void UnsignedLong_delete(void *ptr);

/**
 * @brief Returns the value of the given UnsignedLong wrapper.
 * @param unsigned_long The pointer to the UnsignedLong wrapper.
 * @return The primitive unsigned long value of the given UnsignedLong wrapper.
 */
unsigned long UnsignedLong_valueOf(const UnsignedLong *unsigned_long);

/**
 * @brief Checks if two UnsignedLong wrappers are equal.
 * @param unsigned_long1 The pointer to the first UnsignedLong wrapper to be compared.
 * @param unsigned_long2 The pointer to the second UnsignedLong wrapper to be compared.
 * @return Returns true if the primitive unsigned long values of the two UnsignedLong wrappers are equal, false otherwise.
 */
bool UnsignedLong_equals(const UnsignedLong *unsigned_long1, const UnsignedLong *unsigned_long2);

/**
 * @brief Compares two UnsignedLong wrappers.
 * @param ptr1 The pointer to the first UnsignedLong wrapper to be compared.
 * @param ptr2 The pointer to the second UnsignedLong wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int UnsignedLong_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type long long.
 */
typedef struct Float Float;

/**
 * @brief Creates a new Float wrapper.
 * @param value The value of the float to be wrapped.
 * @return Returns a pointer to the newly created Float wrapper.
 */
Float *Float_new(float value);

/**
 * @brief Destroys the given Float wrapper.
 * @param ptr The pointer to the Float wrapper to be destroyed.
 */
void Float_delete(void *ptr);

/**
 * @brief Returns the value of the given Float wrapper.
 * @param f The pointer to the Float wrapper.
 * @return The primitive float value of the given Float wrapper.
 */
float Float_valueOf(const Float *f);

/**
 * @brief Checks if two Float wrappers are equal.
 * @param float1 The pointer to the first Float wrapper to be compared.
 * @param float2 The pointer to the second Float wrapper to be compared.
 * @return Returns true if the primitive float values of the two Float wrappers are equal, false otherwise.
 */
bool Float_equals(const Float *float1, const Float *float2);

/**
 * @brief Compares two Float wrappers.
 * @param ptr1 The pointer to the first Float wrapper to be compared.
 * @param ptr2 The pointer to the second Float wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Float_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type long long.
 */
typedef struct Double Double;

/**
 * @brief Creates a new Double wrapper.
 * @param value The value of the double to be wrapped.
 * @return Returns a pointer to the newly created Double wrapper.
 */
Double *Double_new(double value);

/**
 * @brief Destroys the given Double wrapper.
 * @param ptr The pointer to the Double wrapper to be destroyed.
 */
void Double_delete(void *ptr);

/**
 * @brief Returns the value of the given Double wrapper.
 * @param d The pointer to the Double wrapper.
 * @return The primitive double value of the given Double wrapper.
 */
double Double_valueOf(const Double *d);

/**
 * @brief Checks if two Double wrappers are equal.
 * @param double1 The pointer to the first Double wrapper to be compared.
 * @param double2 The pointer to the second Double wrapper to be compared.
 * @return Returns true if the primitive double values of the two Double wrappers are equal, false otherwise.
 */
bool Double_equals(const Double *double1, const Double *double2);

/**
 * @brief Compares two Double wrappers.
 * @param ptr1 The pointer to the first Double wrapper to be compared.
 * @param ptr2 The pointer to the second Double wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Double_compare(const void *ptr1, const void *ptr2);

/**
 * @brief A wrapper for the primitive data type bool.
 */
typedef struct Boolean Boolean;

/**
 * @brief Creates a new Boolean wrapper.
 * @param value The value of the bool to be wrapped.
 * @return Returns a pointer to the newly created Boolean wrapper.
 */
Boolean *Boolean_new(bool value);

/**
 * @brief Destroys the given Boolean wrapper.
 * @param ptr The pointer to the Boolean wrapper to be destroyed.
 */
void Boolean_delete(void *ptr);

/**
 * @brief Returns the value of the given Boolean wrapper.
 * @param boolean The pointer to the Boolean wrapper.
 * @return The primitive bool value of the given Boolean wrapper.
 */
bool Boolean_valueOf(const Boolean *boolean);

/**
 * @brief Checks if two Boolean wrappers are equal.
 * @param boolean1 The pointer to the first Boolean wrapper to be compared.
 * @param boolean2 The pointer to the second Boolean wrapper to be compared.
 * @return Returns true if the primitive bool values of the two Boolean wrappers are equal, false otherwise.
 */
bool Boolean_equals(const Boolean *boolean1, const Boolean *boolean2);

/**
 * @brief Compares two Boolean wrappers.
 * @param ptr1 The pointer to the first Boolean wrapper to be compared.
 * @param ptr2 The pointer to the second Boolean wrapper to be compared.
 * @return Returns a negative integer if ptr1 < ptr2.
 *         Returns 0 if ptr1 == ptr2.
 *         Returns a positive integer if ptr1 > ptr2.
 */
int Boolean_compare(const void *ptr1, const void *ptr2);

#endif
