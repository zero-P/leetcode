/*
* @Author: zero
* @Date:   2021-07-06 19:37:46
* @Description: Implement strStr().
* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
* Return 0 when needle is an empty string.
*/
#include <stdio.h>
#include <string.h>

void getNext(char *needle, int next[]) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < strlen(needle)) {
        if (k == -1 || needle[j] == needle[k]) {
            if (needle[++j] != (needle[++k]))
                next[j] = k;
            else
                next[j] = next[k];
        } else
            k = next[k];
    }
}

int strStr(char *haystack, char *needle) {
    int subLen = strlen(needle);
    if (!subLen)
        return 0;
    int strLen = strlen(haystack);
    int next[subLen + 1];
    getNext(needle, next);
    int i = 0, j = 0;
    while (i < strLen && j < subLen) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j == subLen)
        return i - subLen;
    else
        return -1;
}

int main() {
    char *haystack = "hello";
    char *needle = "ll";
    printf("%d", strStr(haystack, needle));
}

