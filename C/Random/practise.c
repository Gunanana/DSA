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

struct node* insert(struct node *start,int item){
    struct node *new,*temp=start,*follow;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;;
    if(start==NULL){
        new->next=NULL;
        start=new;
        return start;
    }
    else{
        while(temp!=NULL&&temp->info<item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            new->next=NULL;
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
int main(){
    struct node*start;
    start=createFromBeginning();
    
    return 0;
}