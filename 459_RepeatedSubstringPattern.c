/*
* @Author: zero
* @Date:   2021-07-07 15:46:52
* @Description: Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
*/

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void getNext(char *s, int *next) {
    int subLen = strlen(s);
    int j = 0, k = -1;
    next[0] = k;
    while (j < subLen) {
        if (k == -1 || s[j] == s[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    int next[len+1];
    getNext(s, next);
    if (next[len] && !(len % (len - next[len])))
        return true;
    return false;
}

int main() {
    char s[] = "aa";
    if (repeatedSubstringPattern(s))
        printf("y");
    else
        printf("n");
}
