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

struct node *deleteAtBeginning(struct node *start){
    struct node *temp=start;
    if(start==NULL)
        printf("Linked List does not exit\n");
    else if(start->next==NULL){
        printf("%d was deleted\n",start->info);
        free(start);
        start=NULL;
    }
    else{
        start=start->next;
        //printf("%d was deleted\n",temp->info);
        free(temp);
    }
    return start;
}

struct node *deleteAtEnd(struct node *start){
    struct node*temp=start,*follow;
    if(start==NULL)
        printf("Linked List does not exist\n");
    else if(start->next==NULL){
        printf("%d was deleted\n",start->info);
        free(start);
        start=NULL;
    }
    else{
        while(temp->next!=NULL){
            follow=temp;
            temp=temp->next;
        }
        printf("%d was deleted\n",temp->info);
        follow->next=NULL;
        free(temp);
    }
    return start;
}

struct node* deleteElement(struct node *start, int item){
    struct node*temp=start,*follow;
    if(start==NULL)
        printf("Linked List does not exist\n");
    else if(start->info==item){
        if(start->next==NULL){
            printf("%d was deleted\n",start->info);
            free(start);
            start=NULL;
        }
        else{
            start=start->next;
            printf("%d was deleted\n",temp->info);
            free(temp);
        }
    }
    else{
        while(temp!=NULL&&temp->info!=item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
        printf("%d was not found in the Linked List and hence and was not deleted\n",item);
        }
        else{
            follow->next=temp->next;
            printf("%d was deleted\n",temp->info);
            free(temp);
        }
    }
    return start;

}

struct node *deleteAfterKey(struct node*start,int key){
    struct node*temp=start,*follow=temp;
    if(start==NULL)
        printf("Linked List does not exist\n");
    else if(start->info==key){
        if(start->next==NULL) printf("Nothing was found after the key\n");
        else{
            temp=start->next;
            printf("%d was deleted",temp->info);
            start->next=start->next->next;
            free(temp);
        }
    }
    else{
        while(follow->next!=NULL&&follow->info!=key){
            follow=temp;
            temp=temp->next;
        }
        if(follow->next==NULL){
            if(follow->info==key) printf("Nothing was found after key\n");
            else printf("%d was not found\n",key);
        }
        else{
            follow->next=NULL;
            printf("%d is being deleted\n",temp->info);
            free(temp);
        }
    }
    return start;
}

struct node* deleteBeforeKey(struct node *start,int key){
    struct node*follow2=start,*follow=start,*temp=start;
    if(start==NULL) printf("Linked List does not exist\n");
    else if(start->info==key) printf("Nothing before key\n");
    else if(start->next->info==key){
        start=start->next;
        free(temp);
    }
    else{
        while(temp!=NULL&&temp->info!=key){
            follow2=follow;
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL) printf("Key was not found\n");
        else{
            follow2->next=temp;
            free(follow);
        }
    }
    return start;
}

int main(){
    struct node* start= createFromBeginning();
    printLinkedList(start);
    //printf("%p\n",start);
    //deleteAtBeginning(start);
    //printf("%p\n",start);
    //start=deleteAtEnd(start);
    //start=deleteElement(start,10);
    start=deleteBeforeKey(start,20);

    printLinkedList(start);
    return 0;
}