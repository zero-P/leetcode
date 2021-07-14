/*
* @Author: zero
* @Date:   2021-07-14 08:29:21
* @Description: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* Valid operators are +, -, *, and /.
* Each operand may be an integer or another expression.
* Division between two integers should truncate toward zero.
*/
#include <string.h>
#include <stdio.h>

int evaluate(int a, int b, char c) {
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
    return 0;
}

int stringToInt(char *s) {
    if (s[0] == '-')
        return 0 - stringToInt(++s);
    int value = 0;
    while (*s != '\0') {
        value *= 10;
        value += *s - '0';
        s++;
    }
    return value;
}

int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;
    while (tokensSize) {
        if (**tokens < '0' && strlen(*tokens) == 1) {
            top -= 1;
            stack[top] = evaluate(stack[top], stack[top + 1], **tokens);
        } else
            stack[++top] = stringToInt(*tokens);
        tokens++;
        tokensSize--;
    }
    return stack[top];
}

int main() {
    char *test[] = {"3","-200","+"};
    printf("%d", evalRPN(test, 3));
    return 0;
}