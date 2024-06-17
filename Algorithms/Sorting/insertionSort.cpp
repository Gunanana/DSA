#include<iostream>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int *arr,int size){
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp) arr[j+1]=arr[j];
            else{break;}
        }
        arr[j+1]=temp;
    }
}

int main(){
    int arr[6]={5,1,2,4,3,-10};
    arrayPrinter(arr,6);
    insertionSort(arr,6);
    arrayPrinter(arr,6);
}