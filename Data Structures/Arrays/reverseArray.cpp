#include<bits/stdc++.h>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[],int size){
    int temp;
    for(int i=0;i<size/2;i++){
        temp=arr[size-i-1];
        arr[size-i-1]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(array)/sizeof(int);
    arrayPrinter(array,size);
    reverseArray(array,size);
    arrayPrinter(array,size);

}