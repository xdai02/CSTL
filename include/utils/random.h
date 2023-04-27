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

#endif
