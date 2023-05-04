#ifndef _RANDOM_H_
#define _RANDOM_H_

/**
 * @brief Generate a random integer between min and max.
 * @param min The lower bound of the random number (inclusive).
 * @param max The upper bound of the random number (inclusive).
 * @return The random integer.
 */
int randint(int min, int max);

/**
 * @brief Generate a random floating-point number between min and max.
 * @param min The lower bound of the random number (inclusive).
 * @param max The upper bound of the random number (inclusive).
 * @return The random floating-point number.
 */
double uniform(double min, double max);

/**
 * @brief Shuffle an array.
 * @param array The array to be shuffled.
 * @param n The length of the array.
 * @param type The type of the array.
 */
#define shuffle(array, n, type)                 \
    do {                                        \
        int i;                                  \
        int j;                                  \
        for (i = (n)-1; i > 0; i--) {           \
            j = randint(0, i);                  \
            swap((array)[i], (array)[j], type); \
        }                                       \
    } while (0)

#endif
