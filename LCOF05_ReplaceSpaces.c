/*
* @Author: zero
* @Date:   2021-07-04 20:35:12
* @Last Modified time: 2021-07-04 22:04:57
* @Description: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"
*/
#include <stdio.h>
#include <stdlib.h>
char* replaceSpace(char* s){
    char *p = s;
    int count = 0, len = 0;
    while (*p != '\0') {
        if (*p == ' ')
            count++;
        len++;
        p++;
    }
    char* str = (char*)malloc(sizeof(char)*(len + count * 2 + 1));
    p = &s[len-1];
    char *q = &str[len+count*2-1];
    str[len+count*2] = '\0';
    while (p >= s) {
        if (*p != ' ')
            *(q--) = *(p--);
        else {
            *(q--) = '0';
            *(q--) = '2';
            *(q--) = '%';
            p--;
        }
    }
    return str;
}

int main() {
    char s[] = {'W', 'e', ' ', 'a', 'r', 'e', ' ', 'h', 'a', 'p', 'p', 'y', '.', '\0'};
    puts(replaceSpace(s));
    printf("\n");
    puts(s);
    return 0;
}