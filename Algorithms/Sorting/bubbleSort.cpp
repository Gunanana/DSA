#include<iostream>
using namespace std;

void arrayPrinter(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//in ith round the ith largest number is in its right place
void bubbleSorter(int *arr,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        bool flag=false;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(!flag){break;}
    }
}

int main(){
    int arr[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    arrayPrinter(arr,20);
    bubbleSorter(arr,20);
    arrayPrinter(arr,20);
}
