#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *createFromBeginning(){
    int item;
    struct node *start=NULL,*temp,*end;
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

struct node* reverse(struct node *start){
    struct node* temp=start,*new,*rstart=NULL,*rend,*follow;
    if(start==NULL){
        printf("Linked List does not exist\n");
    }
    else if(start->next==NULL){
        printf("Linked List has only one element and cannot be reversed\n");
    }
    else{
        while(temp!=NULL){
            if(rstart==NULL){
                new=(struct node*)malloc(sizeof(struct node));
                new->info=temp->info;
                new->next=NULL;
                rstart=new;
                rend=new;
                follow=temp;
                temp=temp->next;
                free(follow);
                follow=NULL;
            }
            else{
                new=(struct node*)malloc(sizeof(struct node));
                new->info=temp->info;
                new->next=rstart;
                rstart=new;
                follow=temp;
                temp=temp->next;
                free(follow);
                follow=NULL;
            }
        }
    }
    return rstart;
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
    struct node*start;
    start=createFromBeginning(start);
    printLinkedList(start);
    start=reverse(start);
    printLinkedList(start);
    return 0;
}