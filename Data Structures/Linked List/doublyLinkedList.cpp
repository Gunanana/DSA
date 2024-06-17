#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
    int info;
    node* next;
    node* prev;
    node(int data){
        info=data;
        next=NULL;
        prev=NULL;
    }
};

int sizeOf(node*start){
    int count=1;
    node*temp=start;
    if(start==NULL) return 0;
    else{
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
    }
    return count;
}

void doublyLinkedListPrinter(node *start){
    node*temp=start;
    if(start==NULL) cout<<"Linked List does not exist :|\n";
    else{
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

node* createFromBeginning(){
    node*temp,*start,*end;
    int item;
    cout<<"Enter your Linked List elements below\n";
    cin>>item;
    while(item!=-999){
        if(start==NULL){
            start= new node(item);
            end=start;
        }
        else{
            temp= new node(item);
            end->next=temp;
            temp->prev=end;
            end=temp;
        }
        cin>>item;
    }
    return start;
}

node* insertAtBeginning(node*&start, int item){
    node*temp;
    if(start==NULL)cout<<"Linked List does not exist :(\n";
    else{
        temp= new node(item);
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    return start;
}

node* insertAtEnd(node* &start,int item){
    node*temp=start,*end=start;
    if(start==NULL) cout<<"Linked List does not exist :(\n";
    else{
        while(end->next!=NULL){
            end=end->next;
        }
        temp= new node(item);
        end->next=temp;
        temp->prev=end;
        end=temp;
    }
    return start;
}

node* insertAt(node* &start,int item,int pos){
    int count=1;
    node*temp=start,*follow,*kid;
    if(start==NULL) cout<<"Linked List does not exist :?\n";
    else if(pos<=0) cout<<"Invalid Position :o\n";
    else if(pos>sizeOf(start)) cout<<"Linked List too short :/\n";
    else if(pos==1){
        temp=new node(item);
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    else{
        while(count!=pos){
            count++;
            follow=temp;
            temp=temp->next;
        }
        kid=new node(item);
        follow->next=kid;
        kid->prev=follow;
        kid->next=temp;
        temp->prev=kid;
    }
    return start;
}

node* deleteAt(node* &start,int pos){
    node* temp=start,*follow;
    int count=1;
    if(start==NULL) cout<<"Linked List does not exist T.T\n";
    else if(pos<=0) cout<<"Invalid position :!\n";
    else if(pos>sizeOf(start)) cout<<"Linked List too short :/\n";
    else if(pos==1){
        if(start->next==NULL){
            cout<<start->info<<" is being deleted!!\n";
            start=NULL;
            delete temp;
        }
        else{
            start=start->next;
            start->prev=NULL;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
    }
    else{
        while(count!=pos){
            count++;
            follow=temp;
            temp=temp->next;
        }
        if(temp->next==NULL){
            follow->next=temp->next;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
        else{
            follow->next=temp->next;
            temp->next->prev=follow;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }

    }
    return start;
}

node* deleteThis(node* &start, int item){
    node*temp=start,*follow;
    if(start==NULL) cout<<"Linked List does not exist :(\n";
    else if(start->info==item){
        if(start->next==NULL){
            start=NULL;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
        else{
            start=start->next;
            start->prev=NULL;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
    }
    else{
        while(temp!=NULL&&temp->info!=item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL) cout<<"Item was not found T.T\n";
        else if(temp->next==NULL){
            follow->next=NULL;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
        else{
            follow->next=temp->next;
            temp->next->prev=follow;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }   
    }
    return start;
}

int main(){
    node*start=createFromBeginning();
    // insertAtBeginning(start,10);
    // insertAtEnd(start,100);
    // cout<<sizeOf(start)<<endl;
    //insertAt(start,10,100);
    //deleteAt(start,3);
    deleteThis(start,10);
    doublyLinkedListPrinter(start);
}