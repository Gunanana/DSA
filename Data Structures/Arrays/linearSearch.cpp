#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key) return true;
    }
    return false;
}

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(array)/sizeof(int);
    cout<<linearSearch(array,size,10)<<endl;
    cout<<linearSearch(array,size,100)<<endl;
    cout<<linearSearch(array,size,05)<<endl;
}