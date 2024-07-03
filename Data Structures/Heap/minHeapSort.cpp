#include<bits/stdc++.h>
using namespace std;

class minHeap{
    vector<int> heap;
    int size;
public:
    minHeap(int n){
        size = 0;
        heap.resize(n+1);
    }

    void push(int num){
        size++;
        heap[size] = num;
        int index = size;
        int parent;

        while(index > 1){
            parent = index/2;
            if(heap[parent] > heap[index]){
                swap(heap[parent] , heap[index]);
                index = parent;
            }
            else return;
        }
    }

    int pop(){
        int num = heap[1];
        heap[1] = heap[size];
        size--;
        int index = 1;
        int left, right;
        while(index < size){
            left = index*2;
            right = index*2+1;
            if(left<= size && heap[index] > heap[left] && heap[left] <= heap[right]){
                swap(heap[left] , heap[index]);
                index = left;
            }
            else if(right<=size && heap[index] > heap[right] && heap[right] <= heap[left]){
                swap(heap[right] , heap[index]);
                index = right;
            }
            else break;
        }
        return num;
    }
};

void heapSort(vector<int> &vec){
    int n = vec.size();
    minHeap temp(n);
    for(auto i : vec) temp.push(i);
    for(int i=0; i<n; ++i) vec[i] = temp.pop();
}


int main(){
    vector<int> vec = {10,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,0,5,4,3,2,1};
    heapSort(vec);
    for(auto i : vec) cout<<i<<" ";
}