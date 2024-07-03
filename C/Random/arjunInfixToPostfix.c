#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
 
int top = -1;
#define STACK_SIZE 100
char stack[STACK_SIZE];
 
void push(char ch)
{
    if((top + 1) >= STACK_SIZE){
        printf("Stack is full\n");
        exit(1);
    }
    stack[++top] = ch;
}
 
char pop(void)
{
    if(top == -1){
        return top;
    }
    return stack[top--];
}
 
char peek(void)
{
    return stack[top];
}
 
int priority(char ch)
{
    switch (ch)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return -1;
    }
}
 
void infix_to_postfix(char *expression)
{
    char *e = expression;
    char c;
    while(*e)
    {
        c = *e;
        if(isalnum(c))
        {
            printf("%c", c);
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while((c = pop()) != '(')
            {
                printf("%c", c);
            }
        }
        else
        {
            while(priority(peek()) >= priority(c))
            {
                printf("%c", pop());
            }
            push(c);
        }
        e++;
    }
    
    
    printf("\n");
}
 
int main()
{   
    int i=0;
    char str[10],str2[12];
    printf("Enter your infix notation below\n");
    gets(str);
    if(str[0]!='('){
        str2[0]='(';
        while(str[i]!='\0'){
            str2[i+1]=str[i];
            i++;
        }
        str2[i+1]=')';
    }
    printf("%c",str);
    //printf("%c",str2);

    //infix_to_postfix(str2);

}