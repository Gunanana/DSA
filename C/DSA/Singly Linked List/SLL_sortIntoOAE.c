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


void splitLinkedListIntoOAE(struct node *start,struct node **estart,struct node **ostart){
    struct node *oend=NULL,*eend=NULL,*temp=start;
    //printf("0");
    while(temp!=NULL){
        //printf("1");
        if(temp->info%2==0){
            if(*estart==NULL){
                *estart=temp;
                eend=*estart;
            }
            else{
                eend->next=temp;
                eend=temp;
            }
        }
        else{
            if(*ostart==NULL){
                *ostart=temp;
                oend=*ostart;
            }
            else{
                oend->next=temp;
                oend=temp;
            }
        }
        temp=temp->next;
    }
    //printf("3");
    oend->next=NULL;
    eend->next=NULL;
    
}

int main(){
    //struct node* estart,*ostart;
    struct node* start=createFromBeginning();
    printLinkedList(start);
    struct node* even=NULL,*odd=NULL;
    splitLinkedListIntoOAE(start,&even,&odd);
    printLinkedList(even);
    printLinkedList(odd);
    return 0;
}