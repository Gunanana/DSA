#include<iostream>
#include<vector>
using namespace std;

/*
-rotated's real life example is a circular array
int arr[]={0,1,2,3,4,5,6};
-if u wanna rotate this array at index 3, then the rotated array would look something like this
int arr[]={3,4,5,6,0,1,2};
-put the index number of elements to the back
*/

//function to find an element in a rotated array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //same like bs but first find the sorted half, then check if the target is inside this sorted half
        //if yes, then change high or low to that half, if not, then other half
        int low=0;
        int high= nums.size()-1;
        int mid;
        while(low<=high){
            mid=low+ (high-low)/2;
            if(nums[mid]==target) return mid;

            //check if left array is the sorted one and ie when left most is smaller than the mid element
            if(nums[low]<=nums[mid]){
                //if it was the sorted one, now check if the target is in this half or not
                if(target>= nums[low] && target<= nums[mid]) high=mid-1;
                else low=mid+1;
            }
            //checking for right half is sorted or not
            else{
                //if it was the sorted one, then check if target is inside this half
                if(target>=nums[mid] && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};