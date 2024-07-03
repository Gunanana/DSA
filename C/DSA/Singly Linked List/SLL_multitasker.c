#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node*createFromBeginning();
struct node*deleteAtBeginning(struct node *start);
struct node*addAtEnd(struct node *start);
void printer(struct node *start);
struct node*insertElementIntoSorted(struct node*start);

void multitasker(){
    int x=1,y=0;
    struct node *start;
    while(x){
        printf("\nEnter what u wanna do\n");
        printf("(0) Create new Linked List\n");
        printf("(1) Delete first node\n");
        printf("(2) Add new node at the end\n");
        printf("(3) Print Linked List\n");
        printf("(4) Insert element into a sorted array\n");
        printf("(5) Exit program\n");
        scanf("%d",&y);
        switch (y){
        case 0:
            start=createFromBeginning();
            break;
        case 1:
            start=deleteAtBeginning(start);
            break;
        case 2:
            start=addAtEnd(start);
            break;
        case 3:
            printer(start);
            break;
        case 4:
            start=insertElementIntoSorted(start);
            break;
        case 5:
            x=0;
            break;
        }
    }
}

struct node *createFromBeginning(){
    struct node *start=NULL, *temp=start,*end=start;
    int item=0;
    printf("Enter your node elements\n");
    scanf("%d",&item);
    while(item!=-999){
        temp=(struct node*)malloc(sizeof(struct node));
        if(start==NULL){
            temp->info=item;
            temp->next=NULL;
            start=temp;
            end=start;
        }
        else{
            temp->info=item;
            temp->next=NULL;
            end->next=temp;
            end=temp;
        }
        scanf("%d",&item);
    }
    printf("Your Linked List was successfully created!!\n");
    return start;
}

void printer(struct node* start){
    struct node *temp=start;
    if(start==NULL) printf("Linked List does not exist. Try again\n");
    else{
        printf("Linked list elements are printed below\n");
        while(temp!=NULL){
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}

struct node *deleteAtBeginning(struct node* start){
    struct node*temp=start;
    if(start==NULL) printf("Linked List does not exist. Try again\n");
    else if(start->next==NULL){
            printf("%d is deleted\n",start->info);
            free(start);
            start=NULL;
    }
    else{
        start=start->next;
        printf("%d is deleted\n",temp->info);
        free(temp);
    }
    return start;
}

struct node *addAtEnd(struct node*start){
    struct node*temp=start,*new;
    new=(struct node*)malloc(sizeof(struct node));
    int item;
    printf("Enter the element u wanna add\n");
    scanf("%d",&item);
    if(start==NULL) printf("Linked List does not exist. Try again\n");
    else if(start->next==NULL){
            new->info=item;
            new->next=NULL;
            start->next=new;
            printf("%d was added\n",item);
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        new->info=item;
        new->next=NULL;
        temp->next=new;
        printf("%d was added\n",item);
    }
    return start;
}

struct node *insertElementIntoSorted(struct node *start){
    struct node*temp=start,*follow,*new;
    int item;
    printf("Enter the element u want to enter into the Linked List\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));

    if(start==NULL) printf("Linked List does not exist. Element not inserted\n");
    else if((start->info)>=item){
        new->info=item;
        new->next=start;
        start=temp;
        printf("%d was added\n",item);
    }
    else{
        while(temp!=NULL&&temp->info<item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            new->info=item;
            new->next=NULL;
            follow->next=new;
        }
        else{
            new->info=item;
            new->next=temp;
            follow->next=new;
        }
        printf("%d was added\n",item);
    }
    return start;

}

int main(){
    multitasker();
}
