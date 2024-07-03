#include<bits/stdc++.h>
using namespace std;

void merger(vector<int> &vec, int s, int e){
    int mid = s + (e-s)/2;
    int ls = mid-s+1;
    int rs = e-mid;

    vector<int> rvec(rs), lvec(ls);

    int index = 0;
    for(int i=s; i<=mid; ++i) lvec[index++] = vec[i];
    index = 0;
    for(int i= mid+1; i<=e; ++i) rvec[index++] = vec[i];

    int ri = 0, li = 0;
    int k = s;
    while(ri<rs && li<ls){
        if(lvec[li] < rvec[ri]) vec[k++] = lvec[li++];
        else vec[k++] = rvec[ri++];

    }
    while(li < ls) vec[k++] = lvec[li++];
    while(ri < rs) vec[k++] = rvec[ri++];
}

void mergeSort(vector<int> &vec, int s, int e){
    if(s>=e) return;
    int mid = s+ (e-s)/2;
    mergeSort(vec, s, mid);
    mergeSort(vec, mid+1, e);
    merger(vec, s, e);
}

int main(){
    vector<int> vec={4,3,5,7,1,2,4,64,2,34,0};
    mergeSort(vec, 0 , 10);
    for(auto i : vec ) cout<<i<<" ";
}