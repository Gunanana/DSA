#include<iostream>
using namespace std;

bool isSorted(int arr[],int size,int i){
    if(i==size-1) return true;
    else if(arr[i]>=arr[i+1]) return false;
    return isSorted(arr,size,i+1);
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<isSorted(arr,10,0);
}