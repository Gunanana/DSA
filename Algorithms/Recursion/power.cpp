#include<iostream>
using namespace std;

int aPowb(int a,int b){
    if(b==0) return 1;
    return a*aPowb(a,b-1);
}

long long aPowbOptimized(int a,int b){
    if(b==0) return 1;
    else if(b==1) return a;
    long long ans=aPowbOptimized(a,b/2);
    if(b%2==0) return ans*ans;
    else return a*ans*ans;
}

int main(){
    cout<<aPowbOptimized(2,62);
    return 0;
}