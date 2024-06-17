//design a data structure which represents 2 stacks using only one array common for both stacks.
#include<bits/stdc++.h>
using namespace std;

class TwoStack{
    public:
    int top1;
    int top2;
    int size;
    int *arr;
    TwoStack(int x){
        size=x;
        top1=-1;
        top2=x;
        arr= new int[size];
    }
    void push1(int item){
        if(top2-top1>1){
            top1++;
            arr[top1]=item;
        }
        else cout<<"Stack1 Overflow\n";
    }
    void pop1(){
        if(top1==-1) cout<<"Stack1 Underflow\n";
        else{
            cout<<arr[top1]<<" was popped\n";
            top1--;
        }
    }
    void push2(int item){
        if(top2-top1>1){
            top2--;
            arr[top2]=item;
        }
        else cout<<"Stack2 Overflow\n";
    }
    void pop2(){
        if(top2==size) cout<<"Stack2 Underflow\n";
        else{
            cout<<arr[top2]<<" was popped\n";
            top2++;
        }
    }

};
