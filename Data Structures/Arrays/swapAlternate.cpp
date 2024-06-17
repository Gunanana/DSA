#include<bits/stdc++.h>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[],int size){
    int temp;
    for(int i=0;i<size;i=i+2){
        if(i==size-1) break;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}

int main(){
    int array[]={1,2,3,4,5,6,7};
    int size=sizeof(array)/sizeof(int);
    arrayPrinter(array,size);
    swapAlternate(array,size);
    arrayPrinter(array,size);
    return 0;
}
