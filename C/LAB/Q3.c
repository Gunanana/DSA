//WACP to implement stack using array/linked list
#include<stdio.h>
#include<stdlib.h>
#define max 100

int top=-1;
int stack[max];

void push(int x){
    if(top==max-1) printf("STACK OVERFLOW\n");
    else stack[++top]=x;
}

void pop(){
    if(top==-1) printf("STACK UNDERFLOW\n");
    else top--;
}

int peek(){
    if(top==-1) printf("STACK UNDERFLOW\n");
    else return stack[top];
}

void display(){
    if(top==-1) printf("STACK UNDERFLOW\n");
    else{
        printf("\n");
        for(int i=top;i>-1;i--) printf("%d ",stack[i]);
    }
}
int main(){
    push(1);
    push(2);
    display();
    pop();
    printf("\n%d\n",peek());
    pop();
    pop();
}