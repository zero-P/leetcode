/*
* @Author: zero
* @Date:   2021-07-12 11:56:37
* @Description: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* An input string is valid if:
* 1. Open brackets must be closed by the same type of brackets.
* 2. Open brackets must be closed in the correct order.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);
    if (len % 2 || *s == ')' || *s == ']' || *s == '}')
        return false;
    char stack[strlen(s)];
    int top = -1;
    while (*s != '\0') {
        if (*s == '(' || *s == '[' || *s == '{')
            stack[++top] = *s;
        else if (*s == ')' && top > -1 && stack[top] == '(')
            top--;
        else if (*s == ']' && top > -1 && stack[top] == '[')
            top--;
        else if (*s == '}' && top > -1 && stack[top] == '{')
            top--;
        else
            return false;
        s++;
    }
    return top == -1;
}

int main() {
    char s[] = "({[]})";
    if (isValid(s))
        printf("y");
    else
        printf("n");
    return 0;
}