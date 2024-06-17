#include<bits/stdc++.h>
using namespace std;

void printerBottomToTop(stack<int>stk){
    if(stk.empty()) return;
    int element=stk.top();
    stk.pop();
    printerBottomToTop(stk);
    cout<<element<<endl;
    stk.push(element);
}

void printerBottomToTop(stack<char>stk){
    if(stk.empty()) return;
    char ch=stk.top();
    stk.pop();
    printerBottomToTop(stk);
    cout<<ch<<endl;
    stk.push(ch);
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