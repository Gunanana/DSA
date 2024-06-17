#include<iostream>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr,int s,int e){
    int count=0;
    for(int i=s+1;i<=e;i++) if(arr[s]>=arr[i]) count++;
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s;
    int j=e;
    while(i<pivotIndex&&j>pivotIndex){
        while(arr[i]<arr[pivotIndex])i++;
        while(arr[j]>arr[pivotIndex])j--;
        if((i<pivotIndex)&&(j>pivotIndex)) swap(arr[i],arr[j]);
    }
    return pivotIndex;
}

void quickSort(int *arr, int s,int e){
    if(s>=e) return; //base condition
    int p= partition(arr,s,e); 
    quickSort(arr,s,p-1); //quicksort on the left array
    quickSort(arr,p+1,e); //quicksort on the right array
}

int main(){
    int arr[10]={11,10,1,2,3,13,12,16,7,8};
    arrayPrinter(arr,10);
    quickSort(arr,0,9);
    arrayPrinter(arr,10);
}