#include "cino_utils.h"

/****************************************
 *              类型转换
 ****************************************/

/**
 * @brief   str转bool
 * @param str   :   字符串
 * @return  返回false的情况：
 *              1. str == NULL
 *              2. strlen(str) == 0
 *              3. str_equal_ignore_case(str, "false")
 *              4. str为全0字符串
 *          其它情况返回true。
 */
bool str_to_bool(const str_t str) {
    if (!str || strlen(str) == 0 || str_equal_ignore_case(str, "false")) {
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
 * @brief   bool转str
 * @param val   :   bool值
 * @return  val为true返回"true"，val为false返回"false"。
 */
const str_t bool_to_str(bool val) {
    return val ? "true" : "false";
}

/**
 * @brief   str转char
 * @param  str  :   保存转换结果的字符串
 * @return  如果str == NULL返回'\0'，否则返回str的第一个字符。
 */
char str_to_char(const str_t str) {
    return_value_if_fail(str != NULL, '\0');
    return str[0];
}

/**
 * @brief   char转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  c            :   字符
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串
 */
str_t char_to_str(char c, str_t str, int str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);
    memset(str, '\0', str_size);
    str[0] = c;
    str[1] = '\0';
    return str;
}

/**
 * @brief   str转int
 * @param str   :   字符串
 * @return  当str == NULL时返回0，其它情况返回atoi()的结果。
 */
int str_to_int(const str_t str) {
    return_value_if_fail(str != NULL, 0);
    return atoi(str);
}

/**
 * @brief   int转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val      :   int值
 * @param  str      :   保存转换结果的字符串
 * @param  str_size :   sizeof(str)
 * @return   转换后字符串
 */
str_t int_to_str(int val, str_t str, int str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);
    memset(str, '\0', str_size);
    snprintf(str, str_size, "%d", val);
    return str;
}

/**
 * @brief   str转double
 * @param str   :   字符串
 * @return  当str == NULL时返回0.0，其它情况返回atof()的结果。
 */
double str_to_double(const str_t str) {
    return_value_if_fail(str != NULL, 0.0);
    return atof(str);
}

/**
 * @brief   double转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val          :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串
 */
str_t double_to_str(double val, int precision, str_t str, int str_size) {
    return_value_if_fail(str != NULL && str_size > 0, NULL);

    // 小数点后精度参数不合法时，默认保留2位小数
    const int MIN_PRECISION = 0;
    const int MAX_PRECISION = 16;
    const int DEFAULT_PRECISION = 2;
    if (precision < MIN_PRECISION || precision > MAX_PRECISION) {
        precision = DEFAULT_PRECISION;
    }

    memset(str, '\0', str_size);
    char format[8] = {0};
    snprintf(format, sizeof(format), "%%.%df", precision);
    snprintf(str, str_size, format, val);

    return str;
}

/****************************************
 *              字符串操作
 ****************************************/

/**
 * @brief   比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool str_equal(const str_t s1, const str_t s2) {
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
bool str_equal_ignore_case(const str_t s1, const str_t s2) {
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
 * @brief   字符串转小写
 * @param str   :   字符串
 * @return  小写字符串
 */
str_t str_to_lower(str_t str) {
    return_value_if_fail(str != NULL, NULL);
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

/**
 * @brief   字符串转大写
 * @param str   :   字符串
 * @return  大写字符串
 */
str_t str_to_upper(str_t str) {
    return_value_if_fail(str != NULL, NULL);
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

/**
 * @brief   判断字符串是否以指定子串开头
 * @param str       :   字符串
 * @param prefix    :   子串
 * @return  如果str以prefix开头返回true，否则返回false。
 */
bool str_starts_with(const str_t str, const str_t prefix) {
    if (!str && !prefix) {
        return true;
    }
    return_value_if_fail(str != NULL && prefix != NULL, false);
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

/**
 * @brief   判断字符串是否以指定子串结尾
 * @param str       :   字符串
 * @param postfix   :   子串
 * @return  如果str以postfix结尾返回true，否则返回false。
 */
bool str_ends_with(const str_t str, const str_t postfix) {
    if (!str && !postfix) {
        return true;
    }
    return_value_if_fail(str != NULL && postfix != NULL, false);
    int str_len = strlen(str);
    int postfix_len = strlen(postfix);
    int offset = str_len - postfix_len;
    return_value_if_fail(offset >= 0, false);
    return strncmp(str + offset, postfix, strlen(postfix)) == 0;
}

/**
 * @brief   清空字符串
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param str       :   字符串
 * @param str_size  :   sizeof(str)
 */
void str_clear(str_t str, int str_size) {
    return_if_fail(str != NULL && str_size > 0);
    memset(str, '\0', str_size);
}

/**
 * @brief   计算字符串长度
 * @param str   :   字符串
 * @return  str为NULL返回0，否则返回字符串长度。
 */
int str_length(const str_t str) {
    return_value_if_fail(str != NULL, 0);
    return strlen(str);
}

/**
 * @brief   字符串拷贝
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串
 */
str_t str_copy(str_t destination, const str_t source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);
    strncpy(destination, source, strlen(source));
    destination[strlen(source)] = '\0';
    return destination;
}

/**
 * @brief   字符串拼接
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串
 */
str_t str_concat(str_t destination, const str_t source) {
    return_value_if_fail(destination != NULL && source != NULL, destination);
    int dest_len = strlen(destination);
    int src_len = strlen(source);
    strncat(destination, source, src_len);
    destination[dest_len + src_len] = '\0';
    return destination;
}

/**
 * @brief   去除字符串首尾空白字符
 * @param str   :   字符串
 * @return  新字符串
 */
str_t str_trim(str_t str) {
    return_value_if_fail(str != NULL, NULL);

    str_t cur = str;
    str_t end = str + strlen(str) - 1;

    while (isspace(*cur)) {
        cur++;
    }

    // All whitespaces
    if (*cur == '\0') {
        memset(str, '\0', end - str + 1);
        return str;
    }

    if (cur != str) {
        memmove(str, cur, end - cur + 1);
        *end = '\0';
        end--;
    }

    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';

    return str;
}

/**
 * @brief   字符串追加字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param c     :   字符
 * @return  新字符串
 */
str_t str_append_char(str_t str, char c) {
    return_value_if_fail(str != NULL, NULL);
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
    return str;
}

/**
 * @brief   字符串追加int
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param val   :   int值
 * @return  新字符串
 */
str_t str_append_int(str_t str, int val) {
    return_value_if_fail(str != NULL, NULL);
    char str_val[12] = {0};
    int_to_str(val, str_val, sizeof(str_val));
    str_concat(str, str_val);
    return str;
}

/**
 * @brief   字符串追加double
 * @note    调用者需要确保str的长度足够。
 * @param str           :   字符串
 * @param val           :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @return  新字符串
 */
str_t str_append_double(str_t str, double val, int precision) {
    return_value_if_fail(str != NULL, NULL);

    // 小数点后精度参数不合法时，默认保留2位小数
    const int MIN_PRECISION = 0;
    const int MAX_PRECISION = 16;
    const int DEFAULT_PRECISION = 2;
    if (precision < MIN_PRECISION || precision > MAX_PRECISION) {
        precision = DEFAULT_PRECISION;
    }

    char str_val[64] = {0};
    double_to_str(val, precision, str_val, sizeof(str_val));
    str_concat(str, str_val);

    return str;
}

/**
 * @brief   在字符串指定位置插入字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param pos   :   插入位置（从0开始）
 * @param c     :   字符
 * @return  新字符串
 */
str_t str_insert_char(str_t str, int pos, char c) {
    return_value_if_fail(str != NULL && pos >= 0 && pos <= strlen(str), str);
    memmove(str + pos + 1, str + pos, strlen(str + pos));
    str[pos] = c;
    return str;
}

/**
 * @brief   在字符串指定位置插入子串
 * @note    调用者需要确保str的长度足够。
 * @param str       :   字符串
 * @param pos       :   插入位置（从0开始）
 * @param substr    :   子串
 * @return  新字符串
 */
str_t str_insert_string(str_t str, int pos, const str_t substr) {
    return_value_if_fail(str != NULL && pos >= 0 && pos <= strlen(str) && substr != NULL, str);

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    memmove(str + pos + substr_len, str + pos, strlen(str + pos));
    memcpy(str + pos, substr, substr_len);
    str[str_len + substr_len] = '\0';

    return str;
}

/**
 * @brief   截取字符串指定范围子串
 * @note    调用者需要确保substr分配了足够的空间、substr_size的长度正确。
 * @param str           :   主串
 * @param start         :   开始下标，小于0默认为0，大于主串长度默认为末尾下标
 * @param end           :   结束下标，小于0默认为0，大于主串长度默认为末尾下标
 * @param substr        :   保存子串
 * @param substr_size   :   sizeof(substr)
 * @return  返回[start, end]返回的子串，start或end不合法返回空串。
 */
str_t str_substring(str_t str, int start, int end, str_t substr, int substr_size) {
    return_value_if_fail(str != NULL && substr != NULL && substr_size > 0, NULL);

    memset(substr, '\0', substr_size);

    // 设置start、end默认值
    int str_len = strlen(str);
    start = start >= 0 ? start : 0;
    start = start < str_len ? start : str_len - 1;
    end = end < str_len ? end : str_len - 1;
    end = end >= 0 ? end : 0;

    // 截取范围不合法返回空串
    return_value_if_fail(end >= start, substr);

    strncpy(substr, str + start, end - start + 1);
    return substr;
}

/**
 * @brief   全部替换字符串中指定字符
 * @param str       :   字符串
 * @param old_char  :   被替换字符
 * @param new_char  :   新字符
 * @return  新字符串
 */
str_t str_replace_char(str_t str, char old_char, char new_char) {
    return_value_if_fail(str != NULL, NULL);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
        i++;
    }
    return str;
}

/**
 * @brief   全部替换字符串中指定子串
 * @param str       :   字符串
 * @param old_str	:   被替换子串
 * @param new_str	:   新串
 * @return  新字符串
 */
str_t str_replace(str_t str, const str_t old_str, const str_t new_str) {
    return_value_if_fail(str != NULL && old_str != NULL && new_str != NULL, str);
    str_t p = NULL;
    while ((p = strstr(str, old_str))) {
        memmove(p + strlen(new_str), p + strlen(old_str), strlen(p) - strlen(old_str) + 1);
        memcpy(p, new_str, strlen(new_str));
    }
    return str;
}

/**
 * @brief   字符串删除指定子串
 * @param str       :   字符串
 * @param substr	:   子串
 * @return  新字符串
 */
str_t str_remove(str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, str);

    int substr_len = strlen(substr);
    if (substr_len > 0) {
        str_t p = str;
        int size = 0;
        while ((p = strstr(p, substr))) {
            size = (size == 0) ? p - str + strlen(p + substr_len) + 1 : size - substr_len;
            memmove(p, p + substr_len, size - (p - str));
        }
    }

    return str;
}

/**
 * @brief   字符串中查找首次出现指定字符的下标
 * @note    空串中查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符首次出现的下标，不存在返回-1。
 */
int str_index_of_char(const str_t str, char c) {
    return_value_if_fail(str != NULL, -1);

    int str_len = strlen(str);

    // 空串中查找\0，返回0
    if (str_len == 0 && c == '\0') {
        return 0;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }

    return -1;
}

/**
 * @brief   字符串中查找从指定位置开始首次出现指定字符的下标
 * @note    空串中从0开始查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始查找下标
 * @return  返回字符从指定位置开始首次出现的下标，不存在返回-1。
 */
int str_index_of_char_from(const str_t str, char c, int from) {
    return_value_if_fail(str != NULL, -1);

    int str_len = strlen(str);

    // 空串中查找\0，返回0
    if (str_len == 0 && c == '\0' && from == 0) {
        return 0;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    int i = from;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }

    return -1;
}

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @note    空串中查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串首次出现的下标，不存在返回-1。
 */
int str_index_of_substring(const str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    // 主串和子串都为空串返回0
    if (str_len == 0 && substr_len == 0) {
        return 0;
    }
    // 主串不为空串，子串为空串，返回-1未找到
    else if (substr_len == 0) {
        return -1;
    }

    const str_t p = strstr(str, substr);
    return p ? p - str : -1;
}

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @note    空串中从0开始查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始首次出现的下标，不存在返回-1。
 */
int str_index_of_substring_from(const str_t str, const str_t substr, int from) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    // 从0开始，如果主串和子串都为空串返回0
    if (str_len == 0 && substr_len == 0 && from == 0) {
        return 0;
    }
    // 主串不为空串，子串为空串，返回-1未找到
    else if (substr_len == 0) {
        return -1;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    const str_t p = strstr(str + from, substr);
    return p ? p - str : -1;
}

/**
 * @brief   字符串中查找最后一次出现指定字符的下标
 * @note    空串中查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_char(const str_t str, char c) {
    return_value_if_fail(str != NULL, -1);

    int str_len = strlen(str);

    // 空串中查找\0，返回0
    if (str_len == 0 && c == '\0') {
        return 0;
    }

    int i = str_len - 1;
    while (i >= 0 && str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i--;
    }

    return -1;
}

/**
 * @brief   字符串中查找从开始位置向前最后一次出现指定字符的下标
 * @note    空串中从0开始查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始下标
 * @return  返回字符从开始位置向前最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_char_from(const str_t str, char c, int from) {
    return_value_if_fail(str != NULL, -1);

    int str_len = strlen(str);

    // 空串中查找\0，返回0
    if (str_len == 0 && c == '\0' && from == 0) {
        return 0;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    int i = from;
    while (i >= 0 && str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i--;
    }

    return -1;
}

/**
 * @brief   字符串中查找最后一次出现指定子串的下标
 * @note    空串中查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_substring(const str_t str, const str_t substr) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    // 主串和子串都为空串返回0
    if (str_len == 0 && substr_len == 0) {
        return 0;
    }
    // 主串不为空串，子串为空串，返回-1未找到
    else if (substr_len == 0) {
        return -1;
    }

    for (const str_t p = str + str_len - substr_len; p >= str; p--) {
        if (strncmp(p, substr, substr_len) == 0) {
            return p - str;
        }
    }

    return -1;
}

/**
 * @brief   字符串中查找从指定位置开始向前最后一次出现指定子串的下标
 * @note    空串中从0开始查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始向前最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_substring_from(const str_t str, const str_t substr, int from) {
    return_value_if_fail(str != NULL && substr != NULL, -1);

    int str_len = strlen(str);
    int substr_len = strlen(substr);

    // 从0开始，如果主串和子串都为空串返回0
    if (str_len == 0 && substr_len == 0 && from == 0) {
        return 0;
    }
    // 主串不为空串，子串为空串，返回-1未找到
    else if (substr_len == 0) {
        return -1;
    }

    return_value_if_fail(from >= 0 && from < str_len, -1);

    for (const str_t p = str + from - substr_len + 1; p >= str; p--) {
        if (strncmp(p, substr, substr_len) == 0) {
            return p - str;
        }
    }

    return -1;
}

/**
 * @brief   字符串分割
 * @note    调用者需要确保字符串数组items的空间分配正确。
 * @param str       :   字符串
 * @param delimiter :   分割串
 * @param items     :   保存分割后子串的二维数组
 * @return  返回分割后产生的子串数量。
 */
int str_split(const str_t str, const str_t delimiter, str_t *items) {
    return_value_if_fail(str != NULL && delimiter != NULL && items != NULL, 0);

    int str_len = strlen(str);
    int delimiter_len = strlen(delimiter);

    int cnt = 0;  // 分割子串数量

    const str_t end = str + str_len - 1;
    const str_t p = NULL;

    while ((p = strstr(str, delimiter))) {
        if (p - str == 0) {
            str += delimiter_len;
        } else {
            strncpy(items[cnt], str, p - str);
            items[cnt][p - str] = '\0';
            cnt++;
            str = p + delimiter_len;
        }
    }

    if (str < end) {
        strncpy(items[cnt], str, end - str + 1);
        items[cnt][end - str + 1] = '\0';
        cnt++;
    }

    return cnt;
}

/****************************************
 *              动态内存管理
 ****************************************/

/**
 * @brief   动态内存申请，并初始化为0。
 * @note    使用完需要通过free()释放。
 * @param size  :   申请空间大小（单位：字节）
 * @return  申请成功返回首地址，失败返回NULL。
 */
void *cino_alloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }
    return calloc(1, size);
}

/**
 * @brief   重新分配内存
 * @note    使用完需要通过free()释放。
 * @param p         :   需要重新分配内存的指针
 * @param old_size  :   原空间大小（单位：字节）
 * @param new_size  :   新空间大小（单位：字节）
 * @return  申请成功返回首地址，失败返回NULL。
 */
void *cino_realloc(void *p, size_t old_size, size_t new_size) {
    if (new_size <= 0) {
        return NULL;
    }

    if (!p) {
        return calloc(1, new_size);
    }

    void *new_mem = calloc(1, new_size);
    memcpy(new_mem, p, min(old_size, new_size));
    free(p);
    p = NULL;
    return new_mem;
}