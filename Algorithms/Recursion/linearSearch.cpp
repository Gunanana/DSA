#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int i,int key){
    if(i==size) return -1;
    if(arr[i]==key) return i;
    return linearSearch(arr,size,i+1,key);
}

int main(){
    int arr[10]={10,9,6,7,8,4,5,3,2,1};
    cout<<linearSearch(arr,10,0,100)<<endl;
    cout<<linearSearch(arr,10,0,1);
    return 0;
}