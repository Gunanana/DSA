//have combined Sll_createFromBeginning file so as to create a linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node* createFromBeginning(){
    int item;
    struct node* start=NULL,*temp,*end;
    printf("Enter node items below. Enter(-999) to exit the loop\n");
    scanf("%d",&item);
    while(item!=-999){
        if(start==NULL){
            start=(struct node*)malloc(sizeof(struct node));
            start->info=item;
            start->next=NULL;
            end=start;
        }
        else{
            temp=(struct node*)malloc(sizeof(struct node));
            temp->info=item;
            temp->next=NULL;
            end->next=temp;
            end=temp;
        }
        scanf("%d",&item);
    }
    return start;
}

void printLinkedList(struct node *start){
    struct node *temp;
    temp=start;
    if(start==NULL){
        printf("Linked List does not exist please try again\n");
    }
    else{
        printf("Linked List is printed below\n");
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

void main(){
    printLinkedList(createFromBeginning());
}