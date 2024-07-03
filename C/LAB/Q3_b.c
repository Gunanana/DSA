#include<stdio.h>
#include<stdlib.h>
#define max 100

struct node{
    int info;
    struct node* next;
};

struct node* top=NULL;
int pos=-1;

void push(int x){
    struct node* new=NULL;
    if(pos==max-1) printf("STACK OVERFLOW\n");
    else{
        pos++;
        new=(struct node*)malloc(sizeof(struct node));
        new->info=x;
        new->next=top;
        top=new;
    }
}

void pop(){
    if(pos==-1) printf("STACK UNDERFLOW\n");
    else{
        pos--;
        struct node*temp=top;
        top=top->next;
        free(temp);
    }
}

int peek(){
    if(pos==-1) {printf("STACK UNDERFLOW\n"); return -1;}
    else return top->info;
}

void display(){
    struct node* temp= top;
    for(int i=pos;i>-1;i--){
        printf("%d ",temp->info);
        temp=temp->next;
    }
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    printf("%d\n",peek());
    pop();
    display();
}