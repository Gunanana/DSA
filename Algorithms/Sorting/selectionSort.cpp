#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&arr,int size){
    int minIndex;
    int temp;
    for(int i=0;i<size;i++){
        minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]) minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main(){
    vector<int>arr={10,9,8,7,6,5,4,3,2,1};
    selectionSort(arr,10);
    for(auto i:arr) cout<<i<<" ";
    
    
}