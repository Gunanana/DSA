#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

void freq(vector<int> &arr, int n){
    int max=-1, maxkey=0;
    map<int,int> count;
    for(int i=0;i<n;i++) count[arr[i]]++;
    for(auto i:count){
        if(max<i.second){
            max=i.second;
            maxkey=i.first;
        }
    }
    int counter=0;
    for(auto i: count) if(i.second==max) counter++;
    cout<<counter;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    freq(arr,n);
    return 0;
}