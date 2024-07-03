#include<stdio.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int item){
    //full condition
    if(rear==max-1) printf("Queue overflow\n");
    //first element condition
    else if(front==-1){
        front++;
        queue[++rear]=item;
    }
    //normal condition
    else queue[++rear]=item;
}

void dequeue(){
    //empty condition
    if(front==-1) printf("Queue underflow\n");
    //last elemenet condition
    else if(front==rear){
        printf("%d is being deleted\n",queue[front]);
        rear=front=-1;
    }
    //normal condition
    else{
        printf("%d is being deleted\n",queue[front]);
        front++;
    }
}

void queuePrinter(){
    //empty condition
    if(front==-1) printf("Queue underflow\n");
    else for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
}

