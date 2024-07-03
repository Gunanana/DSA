//Develop a program to create an sll by adding elements at the end and delete element from the beginning of the linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node*next;
};
struct node* createByAddingAtEnd(){
    struct node* temp, *new, *end,*start=NULL;
    int item;
    printf("Enter Elements (-999 to stop)\n");
    scanf("%d",&item);
    while(item!=-999){
        new= (struct node*)malloc(sizeof(struct node));
        new->info=item;
        new->next=NULL;
        if(start==NULL){
            start=new;
            end= new;
        }
        else{
            end->next=new;
            end=end->next;
        }
        scanf( "%d", &item);
    }
    return start;
}

struct node* deleteAtBeginning(struct node* start){
    struct node*temp=start;
    if(start==NULL) printf("SLL EMPTY\n");
    else{
        printf("%d is being deleted\n",start->info);
        temp=start;
        start=start->next;
        free(temp);
    }
    return start;
}

void menu(){
    struct node *start=NULL;
    int response;
    while (1){
        printf("\nChoose an option below\n");
        printf("1) Create SLL\n");
        printf("2) Delete first element\n");
        printf("3) Exit\n");
        scanf("%d",&response);
        switch (response){
            case 1: start=createAtEnd();
            break;
            case 2: start=deleteAtBeginning(start);
            break;
            case 3: printf("Exiting...\n");
            exit(0);
            default: printf("Invalid entry");
            break;
        }
    }
}

int main(){
    menu();
}


