#include<iostream>
#include<stdlib.h>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merger(int *arr,const int s,const int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1; //left array size
    int len2=e-mid; //right array size
    int *larr= new int[len1]; //dynamically declare left array
    int *rarr= new int[len2]; //dynamically declare right array
    int k=s; //var to run on the main array only 
    for(int i=0;i<len1;i++)larr[i]=arr[k++]; //initialise left array
    for(int i=0;i<len2;i++)rarr[i]=arr[k++]; //initilise right array
    k=s; //reset k to start appending sorted numbers onto the main array
    int li=0; //index to run on left array
    int ri=0; //index to run on right array
    while(li<len1&&ri<len2){
        if(larr[li]<rarr[ri]) arr[k++]=larr[li++]; 
        else if(larr[li]>rarr[ri]) arr[k++] =rarr[ri++];
    }
    while(li<len1) arr[k++]=larr[li++];
    while(ri<len2) arr[k++]=rarr[ri++];
    delete[] larr;
    delete[] rarr;
}

void mergeSort(int *arr,int s,int e){
    if(s>=e)return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid); //divide left array
    mergeSort(arr,mid+1,e); //divide right array
    merger(arr,s,e); //merge both the arrays
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    arrayPrinter(arr,10);
    mergeSort(arr,0,9);
    arrayPrinter(arr,10);
    return 0;
}