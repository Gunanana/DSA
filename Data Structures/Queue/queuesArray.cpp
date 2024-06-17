#include<bits/stdc++.h>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue(int x=10001){
        this->size=x;
        arr= new int[size];
        qfront =0;
        rear=0;
    }
    bool isEmpty(){
        if(qfront==rear) return 1;
        else return 0;
    }
    void enqueue(int item){
        if(rear==size) cout<<"Queue Overflow\n";
        else{
            arr[rear]=item;
            rear++;
        }
    }
    int dequeue(){
        if(isEmpty()) {
            cout<<"Queue Underflow\n";
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }
    int front(){
        if(isEmpty()) return -1;
        else return arr[qfront];
    }
};

int main(){
    Queue guna(3);
    guna.enqueue(5);
    guna.enqueue(6);
    cout<<guna.front()<<endl;
    guna.dequeue();
    cout<<guna.front()<<endl;
    cout<<guna.isEmpty()<<endl;
    guna.dequeue();
    cout<<guna.isEmpty()<<endl;
}