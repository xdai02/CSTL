#include "test_random.h"
#include "coop.h"
#include <assert.h>

void test_randint() {
    const int N = 10000;
    const int MIN = -500;
    const int MAX = 500;
    int i = 0;
    int x;

    for (i = 0; i < N; i++) {
        assert(randint(0, 0) == 0);
        assert(randint(1, 1) == 1);
        assert(randint(-1, -1) == -1);

        x = randint(0, 1);
        assert(x == 0 || x == 1);

        x = randint(-1, 0);
        assert(x == -1 || x == 0);

        x = randint(-1, 1);
        assert(x == -1 || x == 0 || x == 1);
    }

    for (i = 0; i < N; i++) {
        x = randint(MIN, MAX);
        assert(x >= MIN && x <= MAX);
    }
}

void test_uniform() {
    const int N = 1000;
    int i = 0;
    double x;

    for (i = 0; i < N; i++) {
        x = uniform(0, 1);
        assert(x >= 0.0 && x <= 1.0);
    }

    for (i = 0; i < N; i++) {
        x = uniform(10, 20);
        assert(x >= 10.0 && x <= 20.0);
    }

    for (i = 0; i < N; i++) {
        x = uniform(2000, 5000);
        assert(x >= 2000.0 && x <= 5000.0);
    }
}
