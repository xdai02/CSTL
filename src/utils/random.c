#include "random.h"
#include "types.h"
#include <stdlib.h>
#include <time.h>

/**
 * @brief Generate a random integer between min and max.
 * @param min The lower bound of the random number (inclusive).
 * @param max The upper bound of the random number (inclusive).
 * @return The random integer.
 */
int randint(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    return min + rand() % (max - min + 1);
}

/**
 * @brief Generate a random floating-point number between min and max.
 * @param min The lower bound of the random number (inclusive).
 * @param max The upper bound of the random number (inclusive).
 * @return The random floating-point number.
 */
double uniform(double min, double max) {
    double scale;

    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    scale = (double)rand() / RAND_MAX;
    return min + scale * (max - min);
}
