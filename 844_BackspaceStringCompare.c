/*
* @Author: zero
* @Date:   2021-06-27 15:59:09
* @Last Modified time: 2021-07-04 16:40:31
* @Description: 
* Given two strings s and t, return true if they are equal when both are typed into empty text editors.
* '#' means a backspace character.
* Note that after backspacing an empty text, the text will continue empty.
*/

#include <stdio.h>
#include <string.h>

void handleString(char* str) {
    int slow = 0;
    for (int fast = 0; str[fast] != '\0'; fast++) {
        if (str[fast] != '#')
            str[slow++] = str[fast];
        else
            if (slow > 0)
                slow--;
    }
    if (slow >= 0)
        str[slow] = '\0';
    else
        str[0] = '\0';
}

bool backspaceCompare(char* s, char* t) {
    handleString(s);
    handleString(t);
    if (strcmp(s, t))
        return false;
    return true;
}

int main() {
    char s[] = "";
    char t[] = "h##h";
    backspaceCompare(s, t) ? printf("y\n") : printf("n\n"); 
    printf("%s\n", s);
    printf("%s\n", t);
    return 0;
}
