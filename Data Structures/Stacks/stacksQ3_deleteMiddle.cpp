//write a program to delete the middle element in a stack (first middle if even size)
#include<bits/stdc++.h>
using namespace std;

//using recursion babbar method
/*
void solve(stack<int>arr,int size, int count){
    //limiter
    if(count==size/2){
        arr.pop();
        return;
    }
    //iterator
    int num=arr.top();
    arr.pop();
    solve(arr,size,count+1);
    arr.push(num);
}

void deleteMiddle(stack<int>arr,int size){
    int count=0;
    solve(arr,size,count);
}
*/

//my method
void deleteMiddle(int arr[],int n){
    stack<int> a;
    stack<int> b;
    for(int i=0;i<n;i++){
        a.push(arr[i]);
    }
    if(n%2!=0){
        for(int i=0;i<=(floor(n/2)-1);i++){
            b.push(a.top());
            a.pop();
        }
        a.pop();
        for(int i=0;i<=(floor(n/2)-1);i++){
            a.push(b.top());
            b.pop();
        }
    }
    else{
        for(int i=0;i<=n/2-1;i++){
            b.push(a.top());
            a.pop();
        }
        a.pop();
        for(int i=0;i<=n/2-1;i++){
            a.push(b.top());
            b.pop();
        }
    }
    for(int i=n-2;i>=0;i--){
        arr[i]=a.top();
        a.pop();
    }
}

int main(){
    int size;
    cout<<"Enter the size of your array\n";
    cin>>size;
    int array[size];
    cout<<"Enter array elements\n";
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    deleteMiddle(array,size);
    cout<<endl;
    cout<<"Your array after deleting the middle element\n";
    for(int i=0;i<size-1;i++){
        cout<<array[i]<<endl;
    }
    return 0;
}