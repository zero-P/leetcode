/*
* @Author: zero
* @Date:   2021-07-05 15:33:49
* @Last Modified time: 2021-07-05 23:01:01
* @Description: Given an input string s, reverse the order of the words.
* Note that s may contain leading or trailing spaces or multiple spaces between two words.
* The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
#include <stdio.h>
#include <string.h>

/**
 * 删除字符串多余空格
 * @param s 待处理字符串
 */
void removeExtraSpaces(char *s) {
    char *p, *q;
    p = q = s;
    while (*q == ' ')
        q++;
    while (*q != '\0') {
        if (*q != ' ') {
            *(p++) = *(q++);
            continue;
        }
        *(p++) = ' ';
        while (*q == ' ')
            q++;
    }
    if (*(p - 1) == ' ')
        *(p - 1) = '\0';
    else
        *p = '\0';
}

/**
 * 反转字符串
 * @param s   待处理字符串
 * @param len 串 s 的长度
 */
void reserveStr(char *s, int len) {
    char *left = s;
    char *right = &s[len - 1];
    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        left++;
        right--;
    }
}

/**
 * 翻转“规范”字符串中的单词
 * @param s 被处理的字符串
 */
void reserveWord(char *s) {
    char *p = s;
    char *head = s;
    while (*p != '\0') {
        if (*p == ' ') {
            reserveStr(head, p - head);
            p++;
            head = p;
            continue;
        }
        p++;
    }
    reserveStr(head, p - head);
}

char *reverseWords(char *s) {
    removeExtraSpaces(s);
    reserveStr(s, strlen(s));
    reserveWord(s);
    return s;
}

int main() {
    char s[] = "  Able was I  ere I   saw Elba  ";
    puts(s);
    reverseWords(s);
    puts(s);
}
