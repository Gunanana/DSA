//wap to insert an element at the bottom of the stack
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

//my method
void addElementAtBottom1(stack<int>stk,int item){
    stack<int>stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    stk.push(item);
    while(!stk2.empty()){
        stk.push(stk2.top());
        stk2.pop();
    }
}

//recursive by babbar
void solver(stack<int>&stk,int item){
    if(stk.empty()){
        stk.push(item);
        return;
    }
    int element=stk.top();
    stk.pop();
    solver(stk,item);
    stk.push(element);
}

void pushAtBottom(stack<int>&stk,int item){
    solver(stk,item);
}

int main(){
    stack<int>stack1;
    stack1.push(10);
    stack1.push(10);
    stack1.push(10);
    // stack1.push(10);
    // stack1.push(10);
    printer(stack1);
    pushAtBottom(stack1,20);
    cout<<endl;
    printer(stack1);
}