/**
 * https://leetcode-cn.com/problems/reverse-string-ii
 *
 * Given a string s and an integer k, reverse the first k characters for every 2k
 * characters counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them. If there are less
 * than 2k but greater than or equal to k characters, then reverse the first k characters
 * and leave the other as original.
 *
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 *
 * Constraints:
 * 1 <= s.length <= 104
 * s consists of only lowercase English letters.
 * 1 <= k <= 104
 */

#include "cino.h"

int main() {
    str_t s = "abcdefg";
    int k = 2;
    int length = str_length(s);
    int copy_length = str_length(s);
    char result[length + 1];
    str_clear(result, sizeof(result));
    int i = 0;
    char substring[2 * k];

    while (length - 2 * k >= 0) {
        str_substring(s, i * 2 * k, i * 2 * k + k - 1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
        str_substring(s, i * 2 * k + k, i * 2 * k + k + k - 1, substring, sizeof(substring));
        str_concat(result, substring);
        i++;
        length -= 2 * k;
    }

    if (length < k && length > 0) {
        str_substring(s, i * 2 * k, copy_length - 1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
    } else if (length >= k) {
        str_substring(s, i * 2 * k, i * 2 * k + k - 1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
        str_substring(s, i * 2 * k + k, i * 2 * k + k + k - 1, substring, sizeof(substring));
        str_concat(result, substring);
    }
    printf("%s\n", result);

    return 0;
}