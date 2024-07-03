#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define  MAX 100
int front=-1;
int rear=-1;

struct tree{
    int info;
    struct tree* left;
    struct tree* right;
    int bf;
};

struct tree* q[MAX];

int max(int a, int b){return (a>b)?a:b;}

int height(struct tree* node){
    if(node==NULL) return 0;
    int left=height(node->left);
    int right=height(node->right);
    return max(left,right)+1;
}

struct tree* rightRotate(struct tree* x){
    struct tree* y=x->left;
    struct tree* c2= y->right;
    y->right=x;
    x->left=c2;
    x->bf=height(x->left)-height(x->right);
    y->bf=height(y->left)-height(y->right);
    return y;
}

struct tree* leftRotate(struct tree* y){
    struct tree* x=y->right;
    struct tree* c1=x->left;
    x->left=y;
    y->right=c1;
    y->bf=height(y->left)-height(y->right);
    x->bf=height(x->left)-height(x->right);
    return x;
}

struct tree* create(int item){
    struct tree* node=(struct tree*)malloc(sizeof(struct tree));
    node->right=NULL;
    node->left=NULL;
    node->info=item;
    node->bf=0;
    return node;
}

struct tree* insert(struct tree* node, int item){
    if(node==NULL) return create(item);
    if(item<node->info) node->left=insert(node->left, item);
    if(item>node->info) node->right=insert(node->right, item);

    node->bf=height(node->left)-height(node->right);
    //LL case -> so rotate right once
    if((node->bf>1)&&(item<node->left->info)) return rightRotate(node);
    //RR case -> rotate left once
    if((node->bf<-1)&&(item>node->right->info)) return leftRotate(node);
    //LR case -> left rotate and right rotate
    if((node->bf>1)&&(item>node->left->info)){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    //RL case -> right rotate and left rotate
    if((node->bf<-1)&&(item<node->right->info)){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrderTraversal(struct tree* root){
    if(root==NULL) return;
    printf("%d ",root->info);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

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

int main(){
    struct tree* root=NULL;
    root=insert(root,10);
    root=insert(root,70);
    root=insert(root,40);
    root=insert(root,30);
    root=insert(root,20);
    levelOrderTraversal(root);
    return 0;
}