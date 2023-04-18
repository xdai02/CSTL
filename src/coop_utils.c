#include "coop_utils.h"
#include <float.h>

bool float_equal(float f1, float f2) {
    return fabs(f1 - f2) < FLT_EPSILON;
}

bool double_equal(double d1, double d2) {
    return fabs(d1 - d2) < DBL_EPSILON;
}

bool long_double_equal(long double ld1, long double ld2) {
    return fabs(ld1 - ld2) < LDBL_EPSILON;
}