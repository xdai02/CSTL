#include "cino_string.h"

/**
 * @brief cino字符串结构
 */
typedef struct cino_string_t {
    char *string;  // 字符串
    int length;    // 字符串长度
    int capacity;  // 最大容量
} cino_string_t;

/****************************************
 *            cino字符串创建
 ****************************************/

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

/****************************************
 *            cino字符串销毁
 ****************************************/

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

/****************************************
 *            cino字符串操作
 ****************************************/

/**
 * @brief   获取cino字符串值
 * @param string    :   cino字符串
 * @return  cino字符串值
 */
const char *cino_string_get(const cino_string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    return string->string;
}

/**
 * @brief   设置cino字符串
 * @param string    :   cino字符串
 * @param str       :   字符串值
 * @return  cino字符串
 */
cino_string_t *cino_string_set(cino_string_t *string, const char *str) {
    return_value_if_fail(string != NULL, NULL);
    call_and_return_value_if_fail(str != NULL, cino_string_clear(string), string);

    int str_len = strlen(str);
    double ratio = 1.0 * string->capacity / str_len;  // 旧串与新串长度比

    // 长度比小于1，说明原字符串容量不足，扩容为新字符串长度
    if (ratio < 1) {
        // 如果新空间分配失败，返回原cino字符串
        char *memory = (char *)realloc(string->string, sizeof(char) * (str_len + 1));
        return_value_if_fail(memory != NULL, string);
        string->capacity = str_len;
        string->string = memory;
    }
    // 长度比大于2，说明原字符串有至少一半容量多余，按比例缩小空间
    else if (ratio >= 2) {
        while (string->capacity / 2 > str_len) {
            string->capacity /= 2;
        }
        string->string = (char *)realloc(string->string, sizeof(char) * (string->capacity + 1));
    }

    string->length = str_len;
    strncpy(string->string, str, string->length);
    string->string[string->length] = '\0';

    return string;
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
 * @return  cino字符串
 */
cino_string_t *cino_string_clear(cino_string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string->length = 0;
    string->capacity = 0;
    string->string = (char *)realloc(string->string, sizeof(char) * (string->capacity + 1));
    memset(string->string, '\0', string->capacity + 1);
    return string;
}

/**
 * @brief   比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool cino_string_equal(const cino_string_t *s1, const cino_string_t *s2) {
    if (!s1 && !s2) {
        return true;
    }

    if (!s1 || !s2) {
        return false;
    }

    return string_equal(cino_string_get(s1), cino_string_get(s2));
}

/**
 * @brief   忽略大小写比较cino字符串
 * @param s1    :   cino字符串1
 * @param s2    :   cino字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool cino_string_equal_ignore_case(const cino_string_t *s1, const cino_string_t *s2) {
    if (!s1 && !s2) {
        return true;
    }

    if (!s1 || !s2) {
        return false;
    }

    return string_equal_ignore_case(cino_string_get(s1), cino_string_get(s2));
}

/**
 * @brief   cino字符串转小写
 * @param string    :   cino字符串
 * @return  小写cino字符串
 */
cino_string_t *cino_string_tolower(cino_string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string_tolower(string->string);
    return string;
}

/**
 * @brief   cino字符串转大写
 * @param string    :   cino字符串
 * @return  cino大写字符串
 */
cino_string_t *cino_string_toupper(cino_string_t *string) {
    return_value_if_fail(string != NULL, NULL);
    string_toupper(string->string);
    return string;
}

/**
 * @brief   判断cino字符串是否以指定cino子串开头
 * @param string    :   cino字符串
 * @param prefix    :   cino子串
 * @return  如果string以prefix开头返回true，否则返回false。
 */
bool cino_string_starts_with(cino_string_t *string, cino_string_t *prefix) {
    if (!string && !prefix) {
        return true;
    }
    return_value_if_fail(string != NULL && prefix != NULL, false);
    return string_starts_with(cino_string_get(string), cino_string_get(prefix));
}

/**
 * @brief   判断cino字符串是否以指定cino子串结尾
 * @param string    :   cino字符串
 * @param postfix    :   cino子串
 * @return  如果string以postfix结尾返回true，否则返回false。
 */
bool cino_string_ends_with(cino_string_t *string, cino_string_t *postfix) {
    if (!string && !postfix) {
        return true;
    }
    return_value_if_fail(string != NULL && postfix != NULL, false);
    return string_ends_with(cino_string_get(string), cino_string_get(postfix));
}