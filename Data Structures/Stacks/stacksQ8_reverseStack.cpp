//wap to reverse a stack using recursion
#include<bits/stdc++.h>
using namespace std;

void printer(stack<int>stk){
    if(stk.empty()) return;
    int element=stk.top();
    stk.pop();
    printer(stk);
    cout<<element<<endl;
    stk.push(element);
}

void insertAtBottom(stack<int> &stk,int element){
    if(stk.empty()){
        stk.push(element);
        return;
    }
    int e2=stk.top();
    stk.pop();
    insertAtBottom(stk,element);
    stk.push(e2);
}

void reverseStack(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int e1=stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk,e1);
}

stack<int> reverse(stack<int> &stk){
    reverseStack(stk);
    return stk;
}

int main(){
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    printer(stack1);
    printer(reverse(stack1));
}