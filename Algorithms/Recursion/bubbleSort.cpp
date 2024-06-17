#include<iostream>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSorter(int *arr,int size){
    if(size==0||size==1) return;
    for(int i=0;i<size;i++)if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
    bubbleSorter(arr,size-1);
}

int main(){
    int arr[10]={5,4,3,1,10,9,8,7,6,2};
    arrayPrinter(arr,10);
    bubbleSorter(arr,10);
    arrayPrinter(arr,10);
    return 0;
}