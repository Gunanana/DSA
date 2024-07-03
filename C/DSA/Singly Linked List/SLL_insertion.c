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

struct node* insertAtBeginning(struct node *start,int item){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=item;
    temp->next=start;
    start=temp;
    return start;
}

void insertAtEnd(struct node *start, int item){
    struct node *temp,*end;
    end=start;
    while(end->next!=NULL){
        end=end->next;
    }
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=item;
    temp->next=NULL;
    end->next=temp;
    end=temp;
}

struct node* insertIntoSortedLinkedList(struct node* start,int item){
    struct node* temp=start,*follow,*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;
    if(start==NULL){
        temp->next=NULL;
        start=temp;
        return start;
    }
    else{
        while(temp!=NULL&&temp->info<item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            follow->next=new;
            new->next=NULL;
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

struct node* insertBefore(struct node* start,int item, int key){
    struct node *temp=start, *new,*follow;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;
    if(start==NULL){
        printf("Linked List does not exist\n");
    }
    else{
        while(temp!=NULL&&temp->info!=key){
            follow=temp;
            temp=temp->next;
        }
        if(temp==start){
            new->next=start;
            start=new;
        }
        else if(temp==NULL){
            printf("Key was not found\n");
        }
        else{
            new->next=temp;
            follow->next=new;
        }
    }
    return start;
}

struct node* insertAfter(struct node*start, int item, int key){
    struct node  *temp=start,*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;
    if(start==NULL){
        printf("Linked List does not exist\n");
    }
    else{
        while(temp!=NULL&&temp->info!=key){
            temp=temp->next;
        }
        if(temp==start){
            new->next=start->next;
            start->next=new;
        }
        else if(temp==NULL){
            printf("Key was not found\n");
        }
        else{
            new->next=temp->next;
            temp->next=new;
        }
    }
    return start;
}

struct node* insertAt(struct node*start, int item, int at){
    struct node *temp=start,*new,*follow;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=item;
    int count=1,size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }

    if(start==NULL){
        printf("Linked List does not exist\n");
    }
    else{
        temp=start;
        while(temp!=NULL&&count!=at){
            count++;
            follow=temp;
            temp=temp->next;

        }
        if(count==1){
            new->next=start;
            start=new;
        }
        else if(count==size+1){
            follow->next=new;
            new->next=NULL;
        }
        else if(temp==NULL){
            printf("Linked List too short\n");
        }
        else{
            follow->next=new;
            new->next=temp;
        }
    }
    return start;
}

int main(){
    int element=5;
    struct node* start;
    start=createFromBeginning();
    //start=insertAt(start,20,4);
    //start=insertAfter(start,20,10);
    //start=insertBefore(start,20,40);
    // start=insertIntoSortedLinkedList(start,25);
    // printf("Enter element that needs to be inserted at the beginning\n");
    // scanf("%d",&element);
    // start=insertAtBeginning(start,element);
    // printf("Enter element that needs to be inserted at the end\n");
    // scanf("%d",&element);
    insertAtEnd(start,element);
    printLinkedList(start);
    return 0;
}