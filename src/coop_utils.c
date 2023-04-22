#include "coop_utils.h"
#include <math.h>
#include <float.h>

/**
 * @brief Compares two floating point numbers for equality within a certain tolerance.
 * @param f1 The first float number to be compared.
 * @param f2 The second float number to be compared.
 * @return Returns true if the absolute difference between f1 and f2 is less than
 *         FLT_EPSILON, false otherwise.
 */
bool float_equal(float f1, float f2) {
    return fabs(f1 - f2) < FLT_EPSILON;
}

/**
 * @brief Compares two double precision floating point numbers for equality within a certain tolerance.
 * @param d1 The first double number to be compared.
 * @param d2 The second double number to be compared.
 * @return Returns true if the absolute difference between d1 and d2 is less than
 *         DBL_EPSILON, false otherwise.
 */
bool double_equal(double d1, double d2) {
    return fabs(d1 - d2) < DBL_EPSILON;
}

/**
 * @brief Compares two long double precision floating point numbers for equality within a certain tolerance.
 * @param ld1 The first long double number to be compared.
 * @param ld2 The second long double number to be compared.
 * @return Returns true if the absolute difference between ld1 and ld2 is less than
 *         LDBL_EPSILON, false otherwise.
 */
bool long_double_equal(long double ld1, long double ld2) {
    return fabs(ld1 - ld2) < LDBL_EPSILON;
}