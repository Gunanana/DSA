#include<bits/stdc++.h>
using namespace std;

void merger(vector<int> &vec, int low, int high){
    int size = high - low + 1;
    int mid = low + (high - low)/2;
    vector<int> temp(size);

    int i = low, j = mid+1, k = 0;
    while(i<=mid && j<=high){
        if(vec[i] < vec[j]) temp[k++] = vec[i++];
        else temp[k++] = vec[j++];
    }
    while(i<=mid) temp[k++] = vec[i++];
    while(j<=high) temp[k++] = vec[j++];

    k=0;
    for(int i=low; i<=high; ++i) vec[i] = temp[k++];
}


void mergeSort(vector<int> &vec, int low, int high){
    if(low>=high) return;
    int mid = low + (high - low)/2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid+1, high);
    merger(vec, low, high);
}

int main(){
    vector<int> vec={4,3,5,7,1,2,4,64,2,34,0};
    mergeSort(vec, 0 , 10);
    for(auto i : vec ) cout<<i<<" ";
}
