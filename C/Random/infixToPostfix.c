#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

int top = -1;
char arr[MAX_SIZE];

void push(char c) {
    top++;
    arr[top] = c;
}

char pop() {
    char c = arr[top];
    top--;
    return c;
}

int value(char operato) {
    if (operato == '+' || operato == '-') {
        return 1;
    } else if (operato == '*' || operato == '/') {
        return 2;
    } else if (operato == '^') {
        return 3;
    }
    else{
        return -1;
    }
}



int main() {
    char s[MAX_SIZE];
    char st[MAX_SIZE];
    printf("Enter your infix expression: ");
    scanf("%s", s);

    int n = strlen(s);
    int j = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            push('(');
        } else if (s[i] >= '0' && s[i] <= '9') {
            st[j++] = s[i];
        } else if (s[i] == ')') {
            while (arr[top] != '(') {
                char op2 = pop();
                st[j++] = op2;
            }
            pop();
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            while (value(arr[top]) >= value(s[i])) {
                char op2 = pop();
                st[j++] = op2;
            }
            push(s[i]);
        }
    }
    while (top>-1) {
        char op2 = pop();
        st[j++] = op2;
    }
    st[j] = '\0';
    printf("%s", st);
    return 0;
}