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

void searchForAnElement(struct node *start,int item){
    struct node *temp;
    int flag=0;
    temp=start;
    while(temp!=NULL){
        if(temp->info==item){
            printf("Element was found\n");
            flag=1;
            break;
        }
        else flag=0;
        temp=temp->next;
    }
    if(flag==0){
        printf("Element was not found\n");
    }
}
int main(){
    int item;
    struct node* start=createFromBeginning();
    printf("Enter the element that needs to be found\n");
    scanf("%d",&item);
    searchForAnElement(start,item);
    return 0;
}