#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int key){
    if(start>end) return -1;
    int mid=start+(end-start)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]>key) return binarySearch(arr,start,mid-1,key);
    else return binarySearch(arr,mid+1,end,key);
} 

int main(){
    int arr[1]={1};
    cout<<binarySearch(arr,0,0,1);
}