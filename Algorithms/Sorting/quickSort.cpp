#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int low, int high){
    int i = low, j = high;
    int pivot = vec[low]; //take low element as the pivot

    while(i < j){
        //if left part of the vector has numbers smaller than or equal to pivot, then ching ching they are in their correct position, hence move i till u find a number greater than the pivot
        while(i<high && vec[i] <= pivot) i++;

        //if the right part of the vector has numbers greater than the pivot, then they are in their correct position, hence decrease j till u find a number lesser than pivot
        //and as for the >= and > controversy, >= will make the duplicates fall in the right partition, whereas the > will make the duplicates fall in the left side
        //if u are taking first element as the pivot element, its better to throw dupes to the right partition and hence use >
        while(j>low && vec[j] > pivot) j--;

        //to handle few edge cases, swap iff i is still before j
        if(i<j) swap(vec[j] , vec[i]);
    }

    swap(vec[low] , vec[j]);
    //why j?
    //because j will be pointing to the number smaller than the pivot element and rest of the numbers after j will all be more than the pivot element (because this is ascending order)
    return j;
}


void quickSort(vector<int> &vec, int low, int high){
    if(low>=high) return;
    int pivot = partition(vec, low, high);
    quickSort(vec, low, pivot-1);
    quickSort(vec, pivot+1, high);
}

int main(){
    vector<int> vec = {765,4,65,6,778865,3,4,45,3,5,6,7};
    quickSort(vec, 0 , vec.size()-1);
    for(auto i : vec) cout<<i<<" ";
}
