#include<stdio.h>
#include<stdbool.h>

#define  MAX 100
int front=-1;
int rear=-1;
int q[MAX];

struct tree{
    int info;
    struct tree* right;
    struct tree* left;
};

void push(struct tree* node){
    if(front==-1){
        front=rear=0;
        q[rear]=node;
    }
    else q[++rear]=node;
}

void pop(){
    if(front==rear) front=rear=-1;
    else front++;
}

bool isEmpty(){return front==-1?true:false;}


void levelOrderTraversal(struct tree *root){
    push(root); //first push the root
    push(NULL); //push NULL to convey that the first level is done
    printf("\n");
    while(!isEmpty()){
        //pop and then check 2 conditions
        struct tree *temp=q[front];
        pop();
        //if null then that means that level is done hence, cout endl. 
        if(temp==NULL){
            printf("\n");
            //then check if the queue is empty or not, if not then push another null since all of next level would have come if this null is encountered
            if(!isEmpty()) push(NULL);
        }
        //if element, then cout the element and then take in its children
        else{
            printf("%d ",temp->info);
            if(temp->left) push(temp->left);
            if(temp->right) push(temp->right);
        }
    }
}