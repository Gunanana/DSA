//find the highest frequency of a number appearing in an array and return the appearing number. if more than 1 are tied for max frequency, then return the first appearing number. use count()
#include<map>
#include<vector>
#include<iostream>
using namespace std;

int maxFrequencyElement(vector<int>arr){
    map<int,int> count;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    int max=INT_MIN;
    int maxKey;
    for(auto i:count){
        if(max<i.second) {
            max=i.second;
            maxKey=i.first;
        }
    }
    cout<<maxKey<<" has appeared for "<<max<<" times"<<endl;
    return maxKey;
}

int main(){
    vector<int>array={1,2,3,3,1,2,1,1,2,2,2,2,2,1,1,1};
    maxFrequencyElement(array);
}