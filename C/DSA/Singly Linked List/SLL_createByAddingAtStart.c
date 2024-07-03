#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node* createByAddingAtStart(){
    struct node *start=NULL, *temp;
    int item;
    printf("Enter node items below. Enter(-999) to exit the loop\n");
    scanf("%d",&item);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=item;
    temp->next=NULL;
    while(item!=-999){
        if(start==NULL){
            start=temp;
        }
        else{
            temp->next=start;
            start=temp;
        }
        scanf("%d",&item);
    }
    return start;

}

void main(){
    createByAddingAtStart();
}