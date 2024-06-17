#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int info;
    node *next;
    node(int item){
        info=item;
        next=NULL;
    }
};

class stack1{
    node* top;
    public:
    stack1(){top=NULL;}
    bool isEmpty() {
        return top==NULL;
    }
    void push(int item){
        node*temp= new node(item);
        if(!temp)cout<<"Stack Overflow!!\n";
        else{
            temp->info=item;
            temp->next=top;
            top=temp;
        }
    }
    void pop(){
        node*temp;
        if(isEmpty()) cout<<"Stack Underflow!!\n";
        else{
            temp=top;
            top=top->next;
            free(temp);
        }
    }
    void display(){
        node*temp=top;
        if(isEmpty()) cout<<"Stack Underflow\n";
        else{
            while(temp!=NULL){
                cout<<temp->info<<endl;
                temp=temp->next;
            }
        }
    }
    int peek(){
        if(isEmpty()) cout<<"Stack Underflow\n";
        else{
            cout<<top->info<<endl;
            return top->info;
        }
    }
};

int main(){
    stack1 s1;
    s1.peek();
    s1.pop();
    s1.push(10);
    s1.display();
    s1.pop();
    cout<<s1.isEmpty();
    return 0;
}