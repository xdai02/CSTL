#include "test_coop_utils.h"
#include "coop.h"
#include <assert.h>

void test_min() {
    int x1 = 5;
    int y1 = 10;
    assert(min(x1, y1) == 5);

    float x2 = 3.14f;
    float y2 = 1.59f;
    assert(float_equal(min(x2, y2), 1.59f));

    double x3 = 2.718;
    double y3 = 1.414;
    assert(double_equal(min(x3, y3), 1.414));
}

void test_max() {
    int x1 = 5;
    int y1 = 10;
    assert(max(x1, y1) == 10);

    float x2 = 3.14f;
    float y2 = 1.59f;
    assert(float_equal(max(x2, y2), 3.14f));

    double x3 = 2.718;
    double y3 = 1.414;
    assert(double_equal(max(x3, y3), 2.718));
}

void test_swap() {
    int x1 = 5;
    int y1 = 10;
    swap(x1, y1, int);
    assert(x1 == 10);
    assert(y1 == 5);

    float x2 = 3.14f;
    float y2 = 1.59f;
    swap(x2, y2, float);
    assert(float_equal(x2, 1.59f));
    assert(float_equal(y2, 3.14f));

    double x3 = 2.718;
    double y3 = 1.414;
    swap(x3, y3, double);
    assert(double_equal(x3, 1.414));
    assert(double_equal(y3, 2.718));
}

void test_float_equal() {
    float f1 = 0.1f + 0.2f;
    float f2 = 0.3f;
    assert(float_equal(f1, f2));

    float f3 = 1.0f / 3.0f;
    float f4 = 1.0f - 2.0f / 3.0f;
    assert(float_equal(f3, f4));
}

void test_double_equal() {
    double d1 = 0.1 + 0.2;
    double d2 = 0.3;
    assert(double_equal(d1, d2));

    double d3 = 1.0 / 3.0;
    double d4 = 1.0 - 2.0 / 3.0;
    assert(double_equal(d3, d4));
}

void test_long_double_equal() {
    long double ld1 = 0.1L + 0.2L;
    long double ld2 = 0.3L;
    assert(long_double_equal(ld1, ld2));

    long double ld3 = 1.0L / 3.0L;
    long double ld4 = 1.0L - 2.0L / 3.0L;
    assert(long_double_equal(ld3, ld4));
}