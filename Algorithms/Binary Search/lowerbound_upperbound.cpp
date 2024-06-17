#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
int arr[]={1,2,4,5,5,5,6,7,7,8};
indices:   0 1 2 3 4 5 6 7 8 9 

-->lower bound is basically the first index (first appearance) of a number if it exists, if not, then its the index where it should have been.
ex: lowerbound of 5 is 3.
    lowerbound of 3 is 2
    lowerbound of 9 is 10 (the index greater than the last index for any number larger than the max element)


-->upper bound is the index after the last appearance of the number if it exists (or) which index the next same number would come and sit (or) (if it does not exist) then its index where it should have been.
ex: upperbound of 5 is 6
    upperbound of 3 is 2
    upperbound of 6 is 7
*/


//same as binary search
int lower_bound(int *arr,int low, int high, int target, int size=0){
    int mid;
    int index;
    size? index=size: index=high-low+1;
    //2 conditions. either the number maybe or is not
    while(low<=high){
        mid=low+ (high-low)/2;
        //if its maybe then update index with that index
        if(arr[mid]>=target){
            index=mid;
            high=mid-1;
        }
        //if not then just go to the right
        else low=mid+1;
    }
    return index;
}

int main(){
    int arr[]={1,2,4,5,5,5,6,7,7,8};
    // cout<<lower_bound(arr,0,9,5);

    //its included in the <alogrithm> header file
    vector<int>vec={1,2,4,5,5,5,8,9};

    //this function returns an iterator pointing to that index but when u subtract with begin, it returns the index
    int lb_index= lower_bound(vec.begin(), vec.end(), 5) - vec.begin(); //number whose beginning index u wanna find

    int up_index= upper_bound(vec.begin(),vec.end(),5) - vec.begin();
    
    cout<<lb_index<<' '<<up_index<<endl;
}