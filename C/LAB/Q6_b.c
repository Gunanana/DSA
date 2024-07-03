//WACP to implement linear queue using arrays
#include<stdio.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==max-1) printf("QUEUE OVERFLOW\n");
    else if(front==-1){
        front++;rear++;
        queue[rear]=x;
    }
    else queue[++rear]=x;
}

void dequeue(){
    if(front==-1) printf("QUEUE UNDERFLOW\n");
    else if(front==rear){
        printf("%d is being deleted\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d is being deleted\n",queue[front]);
        front++;
    }
}

void queuePrinter(){
    if(front==-1) printf("QUEUE UNDERFLOW\n");
    else for(int i=front;i<=rear;i++)printf("%d ",queue[i]);
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    queuePrinter();
    printf("\n");
    dequeue();
    queuePrinter();
    return 0;
}