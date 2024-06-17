#include<iostream>
using namespace std;

int sumOfArray(int arr[],int size,int i){
    if(i==size) return 0;
    else if(i==size-1) return arr[i];
    return arr[i]+sumOfArray(arr,size,i+1);
}

int main(){
    int arr[1]={50};
    cout<<sumOfArray(arr,1,0);
}
