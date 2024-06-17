#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
    int info;
    node* next;
    node(int x){
        info=x;
        next=NULL;
    }
};

int sizeOf(node* start){
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

node* createFromBeginning(){
    node*start,*temp,*end;
    int item;
    cout<<"Enter Linked List elements\n";
    cin>>item;
    while(item!=-999){
        if(start==NULL){
            start=new node(item);
            end=start;
        }
        else{
            temp=new node(item);
            end->next=temp;
            end=temp;
        }
        cin>>item;
    }
    return start;

}

node* createFromEnd(){
    node*start=NULL,*temp;
    int item;
    cout<<"Enter Linked List elements\n";
    cin>>item;
    while(item!=-999){
        if(start==NULL){
            start= new node(item);
        }
        else{
            temp= new node(item);
            temp->next=start;
            start=temp;
        }
        cin>>item;
    }
    return start;
}

node* insertAtHead(node* &start,int item){
    node* temp;
    if(start==NULL){
        start =new node(item);
    }
    else{
        temp= new node(item);
        temp->next=start;
        start=temp;
    }
    return start;
}

node* insertAtTail(node* &start,int item){
    node*temp=start,*end=start;
    if(start==NULL) cout<<"Linked List does not exist :("<<endl;
    else{
        while(end->next!=NULL){
            end=end->next;
        }
        temp= new node(item);
        end->next=temp;
        end=temp;
    }
    return start;
}

void singlyLinkedListPrinter(node* start){
    node*temp=start;
    if(start==NULL) cout<<"Linked List does not exist :(\n";
    else{
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

node* insertAt(node* &start, int item, int pos){
    node*temp,*follow,*kid;
    int count=1;
    if(start==NULL) cout<<"Linked List does not exist :(\n";
    else if(pos==1){
        temp=new node(item);
        temp->next=start;
        start=temp;
    }
    else{
        temp=start;
        while(temp!=NULL&&count!=pos){
            follow=temp;
            temp=temp->next;
            count++;
        }
        if(temp==NULL&&count!=pos) cout<<"Linked List too short :/\n";
        else{
            kid=new node(item);
            follow->next=kid;
            kid->next=temp;
        }
    }
    return start;
}

node* deleteAt(node* &start, int pos){
    int count=1;
    node* temp=start,*follow;
    if(start==NULL) cout<<"Linked List does not exist :(\n";
    else if(pos<=0) cout<<"Invalid Position :|";
    else if(pos>sizeOf(start)) cout<<"Linked List too short :/\n";
    else if(pos==1){
        temp=start;
        start=start->next;
        cout<<temp->info<<" is being deleted!!"<<endl;
        delete temp;
    }
    else{
        while(temp!=NULL&&count!=pos){
            follow=temp;
            temp=temp->next;
            count++;
        }
        follow->next=temp->next;
        cout<<temp->info<<" is being deleted!!\n";
        delete temp;
    }
    return start;
}

node* deleteThis(node* &start, int item){
    node*temp=start,*follow;
    if(start==NULL) cout<<"Linked List does not exist :/"<<endl;
    else if(start->info==item){
        start=start->next;
        cout<<temp->info<<" is being deleted!!\n";
        delete temp;
    }
    else{
        while(temp!=NULL&&temp->info!=item){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL) cout<<"Element was not found :(\n";
        else{
            follow->next=temp->next;
            cout<<temp->info<<" is being deleted!!\n";
            delete temp;
        }
    }
    return start;
}

int main(){
    node*start=createFromBeginning();
    //singlyLinkedListPrinter(start);
    // insertAtHead(start,1);
    // insertAtTail(start,10);
    //insertAt(start,1,10);
    deleteThis(start,3);
    singlyLinkedListPrinter(start);
    //cout<<sizeOf(start)<<endl;
}