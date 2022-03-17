/****************************************
 * 模块 :   cino_util
 * 功能 :   提供常用操作接口
 * 分类 :
 *          - 状态类型
 *          - 日志等级
 *          - 数值运算
 *          - 合法性检查
 *          - 数组操作
 *          - 类型转换
 *          - 字符串操作
 *          - 动态内存管理
 ****************************************/

#ifndef _CINO_UTILS_H_
#define _CINO_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define str_t char *  // str_t等价于char *

/****************************************
 *              状态类型
 ****************************************/

/**
 * @brief  状态类型
 */
typedef enum status_t {
    STATUS_OK,              // 成功
    STATUS_FAIL,            // 失败
    STATUS_OUT_OF_MEMORY,   // Out of Memory
    STATUS_FOUND,           // 找到
    STATUS_NOT_FOUND,       // 未找到
    STATUS_BAD_PARAMETERS,  // 无效参数
    STATUS_IO_ERROR,        // I/O错误
    STATUS_OUT_OF_BOUNDS,   // 越界
    STATUS_UNDEFINED,       // 未定义
} status_t;

/****************************************
 *              日志等级
 ****************************************/

/**
 * @brief   日志等级
 */
typedef enum log_level_t {
    NONE,     // 不输出
    DEBUG,    // 调试
    INFO,     // 信息
    WARNING,  // 警告
    ERROR,    // 错误
} log_level_t;

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

/****************************************
 *              数值运算
 ****************************************/

/**
 * @brief   返回两数的最小值
 */
#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * @brief   返回两数的最大值
 */
#define max(x, y) (((x) > (y)) ? (x) : (y))

/****************************************
 *              合法性检查
 ****************************************/

/**
 * @brief   判断表达式expr是否成立，不成立直接返回。
 */
#define return_if_fail(expr) \
    if (!(expr)) {           \
        return;              \
    }

/**
 * @brief   判断表达式expr是否成立，不成立返回ret。
 */
#define return_value_if_fail(expr, ret) \
    if (!(expr)) {                      \
        return (ret);                   \
    }

/**
 * @brief   判断表达式expr是否成立，不成立调用func后返回。
 */
#define call_and_return_if_fail(expr, func) \
    if (!(expr)) {                          \
        func;                               \
        return;                             \
    }

/**
 * @brief   判断表达式expr是否成立，不成立调用func后返回ret。
 */
#define call_and_return_value_if_fail(expr, func, ret) \
    if (!(expr)) {                                     \
        func;                                          \
        return (ret);                                  \
    }

/****************************************
 *              数组操作
 ****************************************/

/**
 * @brief   获取C数组元素个数
 */
#define array_len(arr) ((int)(sizeof(arr) / sizeof((arr)[0])))

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
bool str_to_bool(const str_t str);

/**
 * @brief   bool转str
 * @param val   :   bool值
 * @return  val为true返回"true"，val为false返回"false"。
 */
const str_t bool_to_str(bool val);

/**
 * @brief   str转char
 * @param  str  :   保存转换结果的字符串
 * @return  如果str == NULL返回'\0'，否则返回str的第一个字符。
 */
char str_to_char(const str_t str);

/**
 * @brief   char转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  c            :   字符
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串
 */
str_t char_to_str(char c, str_t str, int str_size);

/**
 * @brief   str转int
 * @param str   :   字符串
 * @return  当str == NULL时返回0，其它情况返回atoi()的结果。
 */
int str_to_int(const str_t str);

/**
 * @brief   int转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val      :   int值
 * @param  str      :   保存转换结果的字符串
 * @param  str_size :   sizeof(str)
 * @return   转换后字符串
 */
str_t int_to_str(int val, str_t str, int str_size);

/**
 * @brief   str转double
 * @param str   :   字符串
 * @return  当str == NULL时返回0.0，其它情况返回atof()的结果。
 */
double str_to_double(const str_t str);

/**
 * @brief   double转str
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param  val          :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @param  str          :   保存转换结果的字符串
 * @param  str_size     :   sizeof(str)
 * @return   转换后字符串
 */
str_t double_to_str(double val, int precision, str_t str, int str_size);

/****************************************
 *              字符串操作
 ****************************************/

/**
 * @brief   比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2相同返回true，否则返回false。
 */
bool str_equal(const str_t s1, const str_t s2);

/**
 * @brief   忽略大小写比较字符串
 * @param s1    :   字符串1
 * @param s2    :   字符串2
 * @return  如果s1和s2忽略大小写相同返回true，否则返回false。
 */
bool str_equal_ignore_case(const str_t s1, const str_t s2);

/**
 * @brief   字符串转小写
 * @param str   :   字符串
 * @return  小写字符串
 */
str_t str_to_lower(str_t str);

/**
 * @brief   字符串转大写
 * @param str   :   字符串
 * @return  大写字符串
 */
str_t str_to_upper(str_t str);

/**
 * @brief   判断字符串是否以指定子串开头
 * @param str       :   字符串
 * @param prefix    :   子串
 * @return  如果str以prefix开头返回true，否则返回false。
 */
bool str_starts_with(const str_t str, const str_t prefix);

/**
 * @brief   判断字符串是否以指定子串结尾
 * @param str       :   字符串
 * @param postfix   :   子串
 * @return  如果str以postfix结尾返回true，否则返回false。
 */
bool str_ends_with(const str_t str, const str_t postfix);

/**
 * @brief   清空字符串
 * @note    调用者需要确保str分配了足够的空间、str_size的长度正确。
 * @param str       :   字符串
 * @param str_size  :   sizeof(str)
 */
void str_clear(str_t str, int str_size);

/**
 * @brief   计算字符串长度
 * @param str   :   字符串
 * @return  str为NULL返回0，否则返回字符串长度。
 */
int str_length(const str_t str);

/**
 * @brief   字符串拷贝
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串
 */
str_t str_copy(str_t destination, const str_t source);

/**
 * @brief   字符串拼接
 * @note    调用者需要确保destination和source的长度足够。
 * @param destination   :   目标字符串
 * @param source        :   源字符串
 * @return  返回目标字符串
 */
str_t str_concat(str_t destination, const str_t source);

/**
 * @brief   去除字符串首尾空白字符
 * @param str   :   字符串
 * @return  新字符串
 */
str_t str_trim(str_t str);

/**
 * @brief   字符串追加字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param c     :   字符
 * @return  新字符串
 */
str_t str_append_char(str_t str, char c);

/**
 * @brief   字符串追加int
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param val   :   int值
 * @return  新字符串
 */
str_t str_append_int(str_t str, int val);

/**
 * @brief   字符串追加double
 * @note    调用者需要确保str的长度足够。
 * @param str           :   字符串
 * @param val           :   double值
 * @param  precision    :   四舍五入保留小数点后数位，默认保留2位，最大支持16位
 * @return  新字符串
 */
str_t str_append_double(str_t str, double val, int precision);

/**
 * @brief   在字符串指定位置插入字符
 * @note    调用者需要确保str的长度足够。
 * @param str   :   字符串
 * @param pos   :   插入位置（从0开始）
 * @param c     :   字符
 * @return  新字符串
 */
str_t str_insert_char(str_t str, int pos, char c);

/**
 * @brief   在字符串指定位置插入子串
 * @note    调用者需要确保str的长度足够。
 * @param str       :   字符串
 * @param pos       :   插入位置（从0开始）
 * @param substr    :   子串
 * @return  新字符串
 */
str_t str_insert_string(str_t str, int pos, const str_t substr);

/**
 * @brief   截取字符串指定范围子串
 * @note    调用者需要确保substr分配了足够的空间、substr_size的长度正确。
 * @param str           :   主串
 * @param start         :   开始下标
 * @param end           :   结束下标
 * @param substr        :   保存子串
 * @param substr_size   :   sizeof(substr)
 * @return  返回[start, end]返回的子串，start或end不合法返回空串。
 */
str_t str_substring(str_t str, int start, int end, str_t substr, int substr_size);

/**
 * @brief   计算指定子串出现次数
 * @param  str      :   主串
 * @param  substr   :   子串
 * @retval  子串出现次数
 */
int str_count_substring(const str_t str, const str_t substr);

/**
 * @brief   全部替换字符串中指定字符
 * @param str       :   字符串
 * @param old_char  :   被替换字符
 * @param new_char  :   新字符
 * @return  新字符串
 */
str_t str_replace_char(str_t str, char old_char, char new_char);

/**
 * @brief   全部替换字符串中指定子串
 * @param str       :   字符串
 * @param old_str	:   被替换子串
 * @param new_str	:   新串
 * @return  新字符串
 */
str_t str_replace(str_t str, const str_t old_str, const str_t new_str);

/**
 * @brief   字符串删除指定子串
 * @param str       :   字符串
 * @param substr	:   子串
 * @return  新字符串
 */
str_t str_remove(str_t str, const str_t substr);

/**
 * @brief   字符串中查找首次出现指定字符的下标
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符首次出现的下标，不存在返回-1。
 */
int str_index_of_char(const str_t str, char c);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定字符的下标
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始查找下标
 * @return  返回字符从指定位置开始首次出现的下标，不存在返回-1。
 */
int str_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串首次出现的下标，不存在返回-1。
 */
int str_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   字符串中查找从指定位置开始首次出现指定子串的下标
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始首次出现的下标，不存在返回-1。
 */
int str_index_of_substring_from(const str_t str, const str_t substr, int from);

/**
 * @brief   字符串中查找最后一次出现指定字符的下标
 * @note    空串中查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @return  返回字符最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_char(const str_t str, char c);

/**
 * @brief   字符串中查找从开始位置向前最后一次出现指定字符的下标
 * @note    空串中从0开始查找\0，返回0
 * @param str   :   字符串
 * @param c     :   字符
 * @param from  :   开始下标
 * @return  返回字符从开始位置向前最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_char_from(const str_t str, char c, int from);

/**
 * @brief   字符串中查找最后一次出现指定子串的下标
 * @note    空串中查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @return  返回子串最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_substring(const str_t str, const str_t substr);

/**
 * @brief   字符串中查找从指定位置开始向前最后一次出现指定子串的下标
 * @note    空串中从0开始查找空串，返回0
 * @param str       :   字符串
 * @param substr    :   子串
 * @param from      :   开始查找下标
 * @return  返回子串从指定位置开始向前最后一次出现的下标，不存在返回-1。
 */
int str_last_index_of_substring_from(const str_t str, const str_t substr, int from);

/**
 * @brief   字符串分割
 * @note    调用者需要确保字符串数组items的空间分配正确。
 * @param str       :   字符串
 * @param delimiter :   分割串
 * @param items     :   保存分割后子串的二维数组
 * @return  返回分割后产生的子串数量。
 */
int str_split(const str_t str, const str_t delimiter, str_t *items);

/****************************************
 *              动态内存管理
 ****************************************/

/**
 * @brief   动态内存申请，并初始化为0。
 * @note    使用完需要通过free()释放。
 * @param size  :   申请空间大小（单位：字节）
 * @return  申请成功返回首地址，失败返回NULL。
 */
void *cino_alloc(size_t size);

/**
 * @brief   重新分配内存
 * @note    使用完需要通过free()释放。
 * @param p         :   需要重新分配内存的指针
 * @param old_size  :   原空间大小（单位：字节）
 * @param new_size  :   新空间大小（单位：字节）
 * @return  申请成功返回首地址，失败返回NULL。
 */
void *cino_realloc(void *p, size_t old_size, size_t new_size);

#endif