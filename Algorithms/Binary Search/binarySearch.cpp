#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<binarySearch(array,10,9);
}