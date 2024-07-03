#include<bits/stdc++.h>
using namespace std;

//a heapify function which takes in a vector and creates a maxHeap object, pushes all elements into this obj and then pops all of them back into the vector

/*
STEPS IN PUSH
1) take in number
2) size ++, place it at the bottom, initialise index
3) bring it to the correct position by comparing with the parent


STEPS IN POP
1) note the top element
2) replace the top element with the last element
3) size --, initialise the index as 1
4) take index to its correct position
*/


class maxHeap{
    vector<int> heap;
    int size;
public:
    maxHeap(int n){
        size = 0;
        heap.resize(n+1);
    }

    void push(int num){
        size++;
        heap[size] = num;
        int index = size;
        
        while(index > 1){
            int parent = index/2;
            if(heap[parent] < heap[index]){
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else break;
        }
    }

    int pop(){
        int num = heap[1];
        heap[1] = heap[size];
        size--;
        int index = 1;
        int left, right;

        while(index < size ){
            left = index*2;
            right = index*2 + 1;

            if(left <= size && heap[index] < heap[left] && heap[left] >= heap[right]){
                swap(heap[index] , heap[left]);
                index = left;
            }
            else if(right <=size && heap[index] < heap[right] && heap[right] >= heap[left]){
                swap(heap[right], heap[index]);
                index = right;
            }
            else break;
        }

        return num;
    }

};

void heapSort(vector<int> &vec){
    int n = vec.size();
    maxHeap temp(n);

    for(auto i : vec) temp.push(i);
    for(int i=0; i<n; ++i) vec[i] = temp.pop();
}


int main(){
    vector<int> vec = {0, -1, 3, -2, 5, 4, -3, 2, 1, -4};
    heapSort(vec);
    for(auto i : vec) cout<<i<<" ";
}