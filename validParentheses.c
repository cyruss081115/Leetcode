#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char * s){
    int len = strlen(s);
    if (len == 1) {
        return false;
    }
    char Stack[len]; int top = -1;
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            // Push
            case '(':
                Stack[++top] = '(';
                break;
            case '[':
                Stack[++top] = '[';
                break;
            case '{':
                Stack[++top] = '{';
                break;
            // Pop
            case ')':
                if (top == -1)
                    return false;
                if (Stack[top] == '(') {
                    top--;
                } else {
                    return false;
                }
                break;
            case ']':
                if (top == -1)
                        return false;
                if (Stack[top] == '[') {
                    top--;
                } else {
                    return false;
                }
                break;
            case '}':
                if (top == -1)
                    return false;
                if (Stack[top] == '{') {
                    top--;
                } else {
                    return false;
                }
                break;  

            default:
                printf("Unrecognized Symbol\n");
                return false;
                break;
        }
    }
    // If the stack is not empty
    if (top != - 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    char* str = "()";
    printf("%d\n", isValid(str));
}