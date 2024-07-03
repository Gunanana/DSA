#include<stdio.h>
#define max 100
int cqueue[max];
int front=-1;
int rear=-1;

void enqueue(int item){
    //full condition
    if(front==(rear+1)%max) printf("Queue overflow\n");
    //first element condition
    else if(front==-1){
        cqueue[++rear]=item;
        front++;
    }
    //normal condition
    else cqueue[(++rear)%max]=item;
}

void dequeue(){
    //empty condition
    if(front==-1) printf("Queue underflow\n");
    //last element condition
    else if(front==(rear+1)%max){
        printf("%d is being deleted\n",cqueue[front]);
        front=rear=-1;
    }
    //normal condition
    else printf("%d is being deleted\n",cqueue[(front++)%max]);
}

void cqueuePrinter(){
    //empty condition
    if(front==-1) printf("Queue underflow\n");
    //normal condition
    else{
        for(int i=front;i!=rear;(i++)%5) printf("%d ",cqueue[i]);
        printf("%d\n",cqueue[rear]);
    }
}