//have combined Sll_createFromBeginning file so as to create a linked list

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
        printf("Linked List elements are printed below\n");
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

int numberOfElements(struct node* start){
    int count=0;
    struct node *temp;
    temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int sumOfElements(struct node *start){
    int sum=0;
    struct node *temp;
    temp=start;
    while(temp!=NULL){
        sum+=temp->info;
        temp=temp->next;
    }
    return sum;
}

int sumOfEvenElements(struct node *start){
    struct node *temp;
    temp=start;
    int evensum=0;
    while(temp!=NULL){
        if(temp->info%2==0){
            evensum+=temp->info;
        }
        temp=temp->next;
    }
    return evensum;
}

int primeCheck(int x){
    //0=not prime, 1=prime, 2=less than 2.
    int flag=0;
    if(x<=1){
        flag=2;
    }
    else{
        for(int i=2;i<=x/2;i++){
            if(x%i==0){
                flag=0;
                break;
            }
            else{
                flag=1;
            }
        }
    }
    return flag;
}

void printAllPrimeNumbers(struct node* start){
    int i=0;
    struct node* temp=start;
    printf("All the prime numbers in your Linked list are printed below\n");
    while(temp!=NULL){
        if(primeCheck(temp->info)==1){
            printf("%d\n",temp->info);
            i=1;
        }
        temp=temp->next;
    }
    if(i==0) printf("No prime elements found in the Linked List\n");
}

void editLinkedList(struct node *start){
    //subtract 10 on even numbers and add 10 to odd numbers
    struct node *temp=start;
    printf("Linked List before editing\n");
    printLinkedList(start);
    while(temp!=NULL){
        if(temp->info%2==0){
            temp->info-=10;
        }
        else{
            temp->info+=10;
        }
        temp=temp->next;
    }
    printf("Linked List after editing\n");
    printLinkedList(start);
}

void main(){
    struct node *start=createFromBeginning();
    printLinkedList(start);
    //printf("Number of elements in your Linked List is %d\n",numberOfElements(start));
    //printf("Sum of all the elements in your Linked List is %d\n",sumOfElements(start));
    //printf("Sum of all the Even elements in your Linked List is %d\n",sumOfEvenElements(start));
    printAllPrimeNumbers(start);
    //editLinkedList(start);
}