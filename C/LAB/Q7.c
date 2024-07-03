//WACP to do the following on a doubly linked list
//a) insert before a given value
//b) delete the middle node

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* prev;
    struct node* next;
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
        new->prev=NULL;
        if(start==NULL){
            start=new;
            end=new;
        }
        else{
            end->next=new;
            new->prev=end;
            end=end->next;
        }
        scanf("%d",&item);
    }
    return start;
}

struct node* insertBefore(struct node* start,int item, int key){
    struct node*new, *temp=start;
    if(start==NULL) printf("Linked List Empty\n");
    else if(start->info==key){
        new=(struct node*)malloc(sizeof(struct node));
        new->info=item;
        new->next=start;
        new->prev=NULL;
        start=new;
    }
    else{
        while(temp!=NULL&&temp->info!=key){
            temp=temp->next;
        }
        if(temp==NULL) printf("Key was not found\n");
        else{
            new=(struct node*)malloc(sizeof(struct node));
            new->info=item;
            new->next=temp;
            new->prev=temp->prev;
        }
    }
    return start;
}

struct node* deleteMiddle(struct node* start){
    struct node* fast=start,*slow=start, *temp;
    //0 element condition
    if(start==NULL) printf("DLL empty\n");
    //1 element condition
    else if(start->next==NULL){
        printf("%d is being deleted\n",start->info);
        free(start);
        start=NULL;
    }
    //2 or more element condition
    else{
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        //even number of elements condition
        if(fast==NULL){
            //even numbers of elements other than 2
            if(slow->prev->prev){
                temp=slow->prev;
                slow->prev->prev->next=slow;
                slow->prev=slow->prev->prev;
                printf("%d is being deleted\n", temp->info);
                free(temp);
            }
            //2 elements condition
            else{
                temp=slow->prev;
                slow->prev=NULL;
                start=slow;
                printf("%d is being deleted\n",temp->info);
                free(temp);
            }
        }
        //odd number of elements condition
        else{
            slow->prev->next=slow->next;
            slow->next->prev=slow->prev;
            printf("%d is being deleted\n", slow->info);
            free(slow);
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

void menu(){
    int c, item, key;
    struct node* start=NULL;
    while(1){
        printf("\nChoose...\n");
        printf("1) Create DLL.\n");
        printf("2) Insert an element before another element.\n");
        printf("3) Delete the middle element.\n");
        printf("4) Display DLL.\n");
        printf("5) Exit.\n");
        scanf("%d",&c);
        switch(c){
            case 1: start=createByAddingAtEnd();
            break;
            case 2: printf("Enter the element u wanna insert: ");
            scanf("%d",&item);
            printf("\nBefore what element should this be entered? ");
            scanf("%d",&key);
            start=insertBefore(start,item,key);
            break;
            case 3: start=deleteMiddle(start);
            break;
            case 4: printLinkedList(start);
            break;
            case 5: printf("Exiting...\n");
            exit(0);
            break;
        }
    }
}

int main(){
    menu();
    return 0;
}