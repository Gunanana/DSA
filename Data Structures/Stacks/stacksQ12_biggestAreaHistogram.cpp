#include<bits/stdc++.h>
using namespace std;

class solution{
private:
    vector<int>array;
    int size;
    vector<int> nextSmallerHeightIndex(vector<int>arr,int size){
        stack<int>stk;
        vector<int>array1(size);
        stk.push(-1);
        for(int i=size-1;i>=0;i--){
            while(stk.top()!=-1 && arr[stk.top()]>=arr[i]) stk.pop();
            array1[i]=stk.top();
            stk.push(i);
        }
        return array1;
    }
    vector<int> prevSmallerHeightIndex(vector<int>arr,int size){
        stack<int>stk;
        vector<int>array2(size);
        stk.push(-1);
        for(int i=0;i<size;i++){
            while(stk.top()!=-1 && arr[stk.top()]>=arr[i]) stk.pop();
            array2[i]=stk.top();
            stk.push(i);
        }
        return array2;
    }
public:
    solution(vector<int>ar){
        array=ar;
        size=ar.size();
    }
    int largestRectangleArea(){
        vector<int> next,prev;
        next=nextSmallerHeightIndex(array,size);
        prev=prevSmallerHeightIndex(array,size);
        int area=INT_MIN;
        for(int i=0;i<size;i++){
            int l=array[i];
            if(next[i]==-1) next[i]=size;
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};

int main(){
    solution histogram1({2,1,5,6,2,3});
    cout<<histogram1.largestRectangleArea();
}