//implement circular queues using arrays
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
    else if(front==rear){ 
        printf("%d is being deleted\n",cqueue[front]);
        front=rear=-1;
    }
    //normal condition
    else {
        printf("%d is being deleted\n",cqueue[front]);
        front=(front+1)%max;
    }
}
void cqueuePrinter(){
    //empty condition
    if(front==-1) printf("Queue underflow\n");
    //normal condition
    else{
        for(int i=front;i!=rear;i=(i+1)%max) printf("%d ",cqueue[i]);
        printf("%d\n",cqueue[rear]);
    }
}

int main(){
    enqueue(1);
    enqueue(3);
    enqueue(2);
    cqueuePrinter();
    dequeue();
    cqueuePrinter();
    return 0;
}