#include<iostream>

using namespace std;

class Stack{
    public:
    int top;
    int size;
    int *arr;
    Stack(int x=10001){
        size=x;
        top=-1;
        arr=new int[size];
    }
    void push(int item){
        if(top==size-1) cout<<"Stack Overflow!!\n";
        else{
            top++;
            arr[top]=item;
        }
    }
    void pop(){
        if(top==-1) cout<<"Stack Underflow!!\n";
        else{
            cout<<arr[top]<<" was popped!\n";
            top--;
        }
    }
    void display(){
        cout<<"Elements in stack are as follows\n";
        for(int i=size-1;i>=0;i--) cout<<arr[i]<<endl;
    }
    bool isEmpty(){
        if(top==-1) return 1;
        else return 0;
    }
    int peek(){
        if(top==-1) {
            cout<<"Stack Underflow!!\n";
            return -1;
        }
        else return arr[top];
    }
};

int main(){
    Stack guna(3);
    guna.pop();
    cout<<guna.peek()<<endl;
    guna.push(0);
    cout<<guna.peek()<<endl;
    guna.push(1);
    cout<<guna.peek()<<endl;
    guna.push(2);
    guna.push(3);
    guna.push(4);
    guna.display();
    return 0;
}