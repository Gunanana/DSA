#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

int value(char operator){
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator =='^'){
        return 3;
    }
    else return -1;
}

int compare(char top_op, char scanned_op) {
    if (value(top_op) >= value(scanned_op)) {
        return 1;
    } else {
        return 0;
    }
}

void calc(char *s, char *st) {
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
            if(top==-1) st[j++]=s[i];
            else{
                while (compare(arr[top], s[i])) {
                    char op2 = pop();
                    st[j++] = op2;
                }
                push(s[i]);
            }
        }
    }
    st[j] = '\0';
}


int main() {
    char s[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter your infix expression: ");
    // gets(s);
    scanf("%s",&s);

    calc(s, postfix);
    
    //for(int i=0;i<strlen(postfix);i++) printf("%c",postfix[i]);
    printf("%s",postfix);
    return 0;
}