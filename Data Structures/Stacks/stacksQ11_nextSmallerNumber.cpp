//return next smallest number in that array. -1 if none found

#include<bits/stdc++.h>
using namespace std;

void arrayprinter(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}

vector<int> nextSmallerNumber(vector<int>arr){
    int size=arr.size();
    stack<int>stack;
    stack.push(-1);
    vector<int>array(size);
    for(int i=size-1;i>=0;i--){
        while(stack.top()>=arr[i]) stack.pop();
        array[i]=stack.top();
        stack.push(arr[i]);
    }
    return array;
}

vector<int> prevSmallerNumber(vector<int>arr){
    int size=arr.size();
    vector<int>array(size);
    stack<int>stack;
    stack.push(-1);
    for(int i=0;i<size;i++){
        while(stack.top()>=arr[i]) stack.pop();
        array[i]=stack.top();
        stack.push(arr[i]);
    }
    return array;
}

//return indies array helpful for largest area in histogram
vector<int> nextSmallerNumberIndex(vector<int> arr){
    int size=arr.size();
    stack<int>stack;
    stack.push(-1);
    vector<int>array(size);
    for(int i=size-1;i>=0;i--){
        while(stack.top()!=-1 && arr[stack.top()]>=arr[i]) stack.pop();
        array[i]=stack.top();
        stack.push(i);
    }
    return array;
}

vector<int> prevSmallerNumberIndex(vector<int>arr){
    int size=arr.size();
    stack<int>stack;
    stack.push(-1);
    vector<int>array(size);
    for(int i=0;i<size;i++){
        while(stack.top()!=-1 && arr[stack.top()]>=arr[i]) stack.pop();
        array[i]=stack.top();
        stack.push(i);
    }
    return array;
}

int main(){
    vector<int>array={5,6,1,2,9,10,3,8,4,7};
    vector<int>hey;
    hey=prevSmallerNumberIndex(array);
    arrayprinter(hey);
    return 0;
}