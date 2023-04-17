/**************************************************
 * Module   :   cino_utils_logger
 * Function :   Status code and logger levels
 * Category :
 *              - status_t
 *              - logger_t
 **************************************************/

#ifndef _CINO_UTILS_LOGGER_H_
#define _CINO_UTILS_LOGGER_H_

#include "cino_utils_basic.h"

/****************************************
 *              status_t
 ****************************************/

typedef enum status_t {
    STATUS_OK,
    STATUS_FAIL,
    STATUS_OUT_OF_MEMORY,
    STATUS_FOUND,
    STATUS_NOT_FOUND,
    STATUS_BAD_PARAMETERS,
    STATUS_IO_ERROR,
    STATUS_OUT_OF_BOUNDS,
    STATUS_NOT_MODIFIED,
    STATUS_UNDEFINED,
} status_t;

/****************************************
 *              logger_t
 ****************************************/

typedef enum logger_t {
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
} logger_t;

#ifdef WIN32
#define LOGGER(level, format, ...)                                                                                          \
    do {                                                                                                                    \
        if (level == NONE) {                                                                                                \
            break;                                                                                                          \
        } else if (level == DEBUG) {                                                                                        \
            fprintf(stderr, "[DEBUG] >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__); \
        } else if (level == INFO) {                                                                                         \
            fprintf(stderr, "[INFO] >>> " format "\n", __VA_ARGS__);                                                        \
        } else if (level == WARNING) {                                                                                      \
            fprintf(stderr, "[WARNING] >>> " format "\n", __VA_ARGS__);                                                     \
        } else if (level == ERROR) {                                                                                        \
            fprintf(stderr, "[ERROR] >>> " format "\n", __VA_ARGS__);                                                       \
        }                                                                                                                   \
    } while (0)
#else
#define LOGGER(level, format, args...)                                                                                 \
    do {                                                                                                               \
        if (level == NONE) {                                                                                           \
            break;                                                                                                     \
        } else if (level == DEBUG) {                                                                                   \
            fprintf(stderr, "[DEBUG] >>> %s->%s()->line.%d : " format "\n", __FILE__, __FUNCTION__, __LINE__, ##args); \
        } else if (level == INFO) {                                                                                    \
            fprintf(stderr, "[INFO] >>> " format "\n", ##args);                                                        \
        } else if (level == WARNING) {                                                                                 \
            fprintf(stderr, "[WARNING] >>> " format "\n", ##args);                                                     \
        } else if (level == ERROR) {                                                                                   \
            fprintf(stderr, "[ERROR] >>> " format "\n", ##args);                                                       \
        }                                                                                                              \
    } while (0)
#endif

#endif