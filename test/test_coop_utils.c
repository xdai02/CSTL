#include "test_coop_utils.h"
#include "coop.h"
#include <assert.h>

void test_min() {
    assert(min(5, 10) == 5);
    assert(min(-5, -10) == -10);
    assert(float_equal(min(3.14f, 1.59f), 1.59f));
    assert(float_equal(min(-3.14f, -1.59f), -3.14f));
    assert(double_equal(min(2.718, 1.414), 1.414));
    assert(double_equal(min(-2.718, -1.414), -2.718));
}

void test_max() {
    assert(max(5, 10) == 10);
    assert(max(-5, -10) == -5);
    assert(float_equal(max(3.14f, 1.59f), 3.14f));
    assert(float_equal(max(-3.14f, -1.59f), -1.59f));
    assert(double_equal(max(2.718, 1.414), 2.718));
    assert(double_equal(max(-2.718, -1.414), -1.414));
}

void test_swap() {
    int x1, y1;
    float x2, y2;
    double x3, y3;

    x1 = 5;
    y1 = 10;
    swap(x1, y1, int);
    assert(x1 == 10);
    assert(y1 == 5);

    x2 = 3.14f;
    y2 = 1.59f;
    swap(x2, y2, float);
    assert(float_equal(x2, 1.59f));
    assert(float_equal(y2, 3.14f));

    x3 = 2.718;
    y3 = 1.414;
    swap(x3, y3, double);
    assert(double_equal(x3, 1.414));
    assert(double_equal(y3, 2.718));
}

void test_float_equal() {
    assert(float_equal(0.1f + 0.2f, 0.3f));
    assert(float_equal(0.1f - 0.2f, -0.1f));
    assert(float_equal(1.0f / 3.0f, 1.0f - 2.0f / 3.0f));
    assert(float_equal(-1.0f / 3.0f, -1.0f + 2.0f / 3.0f));
}

void test_double_equal() {
    assert(double_equal(0.1 + 0.2, 0.3));
    assert(double_equal(0.1 - 0.2, -0.1));
    assert(double_equal(1.0 / 3.0, 1.0 - 2.0 / 3.0));
    assert(double_equal(-1.0 / 3.0, -1.0 + 2.0 / 3.0));
}

void test_long_double_equal() {
    assert(long_double_equal(0.1L + 0.2L, 0.3L));
    assert(long_double_equal(0.1L - 0.2L, -0.1L));
    assert(long_double_equal(1.0L / 3.0L, 1.0L - 2.0L / 3.0L));
    assert(long_double_equal(-1.0L / 3.0L, -1.0L + 2.0L / 3.0L));
}
