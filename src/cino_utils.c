#include "cino_utils.h"

/****************************************
 *              字符串操作
****************************************/

/**
 * @brief   比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool string_equal(const char *s1, const char *s2) {
    if (!s1 && !s2) {
        return true;
    }

    if (!s1 || !s2) {
        return false;
    }

    if (strlen(s1) != strlen(s2)) {
        return false;
    }

    return strncmp(s1, s2, strlen(s1)) == 0;
}

/**
 * @brief   忽略大小写比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool equals_ignore_case(const char *s1, const char *s2) {
    if (!s1 && !s2) {
        return true;
    }

    if (!s1 || !s2) {
        return false;
    }

    while (*s1) {
        if (tolower(*s1) != tolower(*s2)) {
            return false;
        }
        s1++;
        s2++;
    }

    return *s1 == *s2;
}

/**
 * @brief   清空字符串
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param str       :   字符串
 * @param str_size  :   sizeof(str)
 */
void string_clear(char *str, int str_size) {
    return_if_fail(str != NULL && str_size > 0);
    memset(str, '\0', str_size);
}

/**
 * @brief   计算字符串长度
 * @param str   :   字符串
 * @return  str为NULL返回0，否则返回字符串长度。
 */
int string_length(const char *str) {
    return_value_if_fail(str != NULL, 0);
    return strlen(str);
}

/**
 * @brief   字符串拷贝
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串。
 */
char *string_copy(char *destination, const char *source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);
    strncpy(destination, source, strlen(source));
    destination[strlen(source)] = '\0';
    return destination;
}

/****************************************
 *              类型转换
****************************************/

/**
 * @brief   string转bool
 * @param str   :   字符串
 * @return  返回false的情况：
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. equals_ignore_case(str, "false")
 *              4. str为全0字符串
 *          其它情况返回true。
 */
bool string_to_bool(const char *str) {
    if (!str || strlen(str) == 0 || equals_ignore_case(str, "false")) {
        return false;
    }

    while (*str) {
        if (*str != '0') {
            return true;
        }
        str++;
    }

    return false;
}

/**
 * @brief   bool转string
 * @param val   :   bool值
 * @return  val为true返回"true"，val为false返回"false"。
 */
const char *bool_to_string(bool val) {
    return val ? "true" : "false";
}

/**
 * @brief   string转int
 * @param str   :   字符串
 * @return  当str == NULL时返回0，其它情况返回atoi()的结果。
 */
int string_to_int(const char *str) {
    return_value_if_fail(str != NULL, 0);
    return atoi(str);
}

/**
 * @brief   int转string
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val      :   int值
 * @param  str      :   保存转换结果的字符串
 * @param  str_size :   sizeof(str)
 * @return   保存转换结果的字符串。
 */
const char *int_to_string(int val, char *str, int str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);
    memset(str, '\0', str_size);
    snprintf(str, str_size, "%d", val);
    return str;
}

/**
 * @brief   string转double
 * @param str   :   字符串
 * @return  当str == NULL时返回0.0，其它情况返回atof()的结果。
 */
double string_to_double(const char *str) {
    return_value_if_fail(str != NULL, 0.0);
    return atof(str);
}

/**
 * @brief   double转string
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val          :   double值
 * @param  precision    :   小数点后数位
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   保存转换结果的字符串。
 */
const char *double_to_string(double val, int precision, char *str, int str_size) {
    return_value_if_fail(precision >= 0 && str != NULL && str_size > 0, NULL);

    memset(str, '\0', str_size);
    char format[8] = {0};
    snprintf(format, sizeof(format), "%%.%df", precision);
    snprintf(str, str_size, format, val);
    return str;
}