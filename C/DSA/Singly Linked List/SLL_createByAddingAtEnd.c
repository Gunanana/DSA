#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *createByAddingAtEnd(){
    int item;
    struct node *start=NULL,*new,*end;
    printf("Enter node items below. Enter(-999) to exit the loop\n");
    scanf("%d",&item);
    while(item!=-999){
        new=(struct node*)malloc(sizeof(struct node));
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

void main(){
    createByAddingAtEnd();
}