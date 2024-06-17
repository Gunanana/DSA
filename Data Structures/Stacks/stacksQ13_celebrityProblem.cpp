#include<bits/stdc++.h>
using namespace std;

void printerTopToBottom(stack<int>stk){
    if(stk.empty()) cout<<"Stack underflow!!"<<endl;
    else{
        while(!stk.empty()){
            cout<<stk.top()<<endl;
            stk.pop();
        }
    }
}

bool celebrityProblem(vector<vector<int>>arr){
    int size=arr.size();
    stack<int>stack;
    for(int i=0;i<size;i++) stack.push(i);
    //printerTopToBottom(stack);
    while(stack.size()>1){
        int a=stack.top();
        stack.pop();
        int b=stack.top();
        stack.pop();
        if(arr[a][b]==1){
            stack.push(b);
        }
        else stack.push(a);
    }
    int pc=stack.top();
    //row checker
    for(int i=0;i<size;i++){
        if(arr[pc][i]==1) return false;
    }
    //column checker
    for(int i=0;i<size;i++){
        if(pc==i) continue;
        else if(arr[i][pc]==0) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> array={{0,1,0},{0,0,0},{0,1,0}};
    cout<<celebrityProblem(array);
}