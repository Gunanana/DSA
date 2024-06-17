#include<bits/stdc++.h>
using namespace std;

void stackSorter(stack<int>&stk,int element){
    if(stk.empty()){
        stk.push(element);
        return;
    }
    else if(stk.top()<element){
        stk.push(element);
        return;
    }
    int e1=stk.top();
    stk.pop();
    stackSorter(stk,element);
    stk.push(e1);
}

void sortStack(stack<int> &stk){
    if(stk.empty()) return;
    int element=stk.top();
    stk.pop();
    sortStack(stk);
    stackSorter(stk,element);
}

void printerTopToBottom(stack<int>stk){
    if(stk.empty()) cout<<"Stack underflow!!"<<endl;
    else{
        while(!stk.empty()){
            cout<<stk.top()<<endl;
            stk.pop();
        }
    }
}

int main(){
    stack<int>stk;
    stk.push(25);
    stk.push(65);
    stk.push(-1);
    stk.push(-100);
    stk.push(29);
    stk.push(-98);
    printerTopToBottom(stk);
    sortStack(stk);
    cout<<endl;
    printerTopToBottom(stk);
}