#include <string.h>
#include <stdio.h>
#include <malloc.h>

/*
* @Author: zero
* @Date:   2021-07-13 08:49:07
* @Description: You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
* We repeatedly make duplicate removals on s until we no longer can.
* Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
*/

char *removeDuplicates(char *s) {
    char *stack = (char *) malloc(sizeof(char) * strlen(s));
    int top = -1;
    while (*s) {
        if (top == -1)
            stack[++top] = *(s++);
        else if (*s != stack[top])
            stack[++top] = *(s++);
        else {
            top--;
            s++;
        }
    }
    stack[++top] = '\0';
    return stack;
}

int main() {
    char *result = removeDuplicates("abbaca");
    puts(result);
    free(result);
    return 0;
}
