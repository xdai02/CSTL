#include "cino_string.h"

/**
 * @brief cino字符串结构
 */
typedef struct cino_string_t {
    char *string;  // 字符串
    int length;    // 字符串长度
    int capacity;  // 最大容量
} cino_string_t;

/**
 * @brief   创建cino字符串
 * @param str   :   字符串
 * @return  返回构造好的cino字符串指针，失败返回NULL。
 */
cino_string_t *cino_string_create(const char *str) {
    return_value_if_fail(str != NULL, NULL);

    cino_string_t *string = (cino_string_t *)malloc(sizeof(cino_string_t));
    return_value_if_fail(string != NULL, NULL);

    string->length = string_length(str);
    string->capacity = string_length(str);

    string->string = (char *)calloc(string->capacity + 1, sizeof(char));
    call_and_return_value_if_fail(string->string != NULL, cino_string_destroy(string), NULL);

    strncpy(string->string, str, string->length);
    string->string[string->length] = '\0';

    return string;
}

/**
 * @brief   销毁cino字符串
 * @param string    :   cino字符串
 */
void cino_string_destroy(cino_string_t *string) {
    return_if_fail(string != NULL);

    string->length = 0;
    string->capacity = 0;

    if (string->string) {
        free(string->string);
        string->string = NULL;
    }

    if (string) {
        free(string);
        string = NULL;
    }
}

/**
 * @brief   获取cino字符串值
 * @param string    :   cino字符串
 * @return  cino字符串值
 */
const char *cino_string_get(cino_string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string->string;
}

/**
 * @brief   获取cino字符串长度
 * @param string    :   cino字符串
 * @return  cino字符串长度
 */
int cino_string_length(cino_string_t *string) {
    return_value_if_fail(string != NULL && string->string != NULL, 0);
    return string->length;
}

/**
 * @brief   清空cino字符串
 * @param string    :   cino字符串
 */
void cino_string_clear(cino_string_t *string) {
    return_if_fail(string != NULL);

    string->length = 0;
    string->capacity = 0;
    string->string = (char *)realloc(string->string, sizeof(char) * (string->capacity + 1));
    call_and_return_if_fail(string->string != NULL, cino_string_destroy(string));
    memset(string->string, '\0', string->capacity + 1);
}