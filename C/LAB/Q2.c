//develop a program to insert elements into a sorted SLL
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};

struct node *createFromBeginning(){
    int item;
    struct node *start=NULL,*new,*end;
    printf("Enter node items below. Enter(-999) to exit the loop\n");
    scanf("%d",&item);
    while(item!=-999){
        new= (struct node*)malloc(sizeof(struct node));
        new->info=item;
        new->next=NULL;
        if(start==NULL){
            start=new;
            end=new;
        }
        else{
            end->next=new;
            end=end->next;
        }
        scanf("%d",&item);
    }
    return start;
}

struct node* insertIntoSortedLinkedList(struct node* start,int item){
    struct node* temp=start,*follow,*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;
    new->next=NULL;
    if(start==NULL){
        start=new;
        return start;
    }
    else{
        while(temp!=NULL&&temp->info<item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            follow->next=new;
        }
        else if(temp==start){
            new->next=start;
            start=new;
        }
        else{
            follow->next=new;
            new->next=temp;
        }
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

int main(){
    struct node*start=NULL;
    start =createFromBeginning();
    printLinkedList(start);
    start=insertIntoSortedLinkedList(start, 10);
    printLinkedList(start);
    return 0;
}

