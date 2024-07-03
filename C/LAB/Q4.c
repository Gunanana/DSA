//WAP to convert infix to postfix using stacks
#include<stdio.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;

void push(char c){
    if(top==max-1) printf("Stack overflow\n");
    else stack[++top]=c;
}

char pop(){
    if(top==-1) {
        printf("Stack underflow\n");
        return 'z';
    }
    else return stack[top--];
}


int precedence(char c){
    switch (c){
        case '*':case '/':
        return 2;
        break;

        case '^':
        return 3;
        break;

        case '+':case '-':
        return 1;
        break;

        case '(':
        return 0;
        break;

        default:
        return -1;
    }
}
void solver(char ch[]){
    char *e=ch;
    char c;
    while(*e){
        c=*e;
        if(c=='(') push(c);
        else if(isdigit(c)) printf("%c",c);
        else if(c==')'){
            while(stack[top]!='(')printf("%c",pop());
            pop();
        }
        else{
            while(top!=-1&&(precedence(c)<=precedence(stack[top])))printf("%c",pop());
            push(c);
        }
        e++;
    }
    while(top!=-1)printf("%c",pop());
}

int main() {
    solver("6+2*(8-4)^(7/8)+4^8*5/9*1^(2+3)");
    printf("\n");
    solver("1+2");
    return 0;
}