/*
* @Author: zero
* @Date:   2021-07-06 16:05:50
* @Last Modified time: 2021-07-06 16:13:22
* @Description: 把字符串前面的若干个字符转移到字符串的尾部
*/
#include <stdio.h>
#include <string.h>

void reverseStr(char* s, int len) {
    char *left = s;
    char *right = s + len - 1;
    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        left++;
        right--;
    }
}

char* reverseLeftWords(char* s, int n) {
    reverseStr(s, n);
    reverseStr(s + n, strlen(s) - n);
    reverseStr(s, strlen(s));
    return s;
}

int main() {
    char s[] = "abcdefg";
    puts(reverseLeftWords(s, 2));
    return 0;
}