#include<bits/stdc++.h>
using namespace std;

int power(int b, int n){
    if(n==0) return 1;
    else return b*power(b,n-1); 
}

int factorial(int n){
    if(n==0) return 1;
    else return n*factorial(n-1);
}

void counter(int n){
    if(n==0){ 
        cout<<"BOOM!!";
        exit(0);
    }
    cout<<n<<" ";
    counter(n-1);
}

int fibonacci(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

void fibSeries(int n){
    for(int i=0;i<n;i++) cout<<fibonacci(i)<<" ";
}

int nthStair(long long n){
    if(n<0) return 0;
    if(n==0) return 1;
    return nthStair(n-1)+nthStair(n-2);
}

void sayDigits(int n){
    if(n==0) return;
    string arr[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int digit=n%10;
    n=n/10;
    sayDigits(n);
    cout<<arr[digit]<<" ";
}

int main(){
    //cout<<power(2,10);
    //cout<<factorial(3);
    //counter(5);
    //cout<<fibonacci(8);
    //fibSeries(10);
    //cout<<"Number of ways you can reach the nth stair by taking either 1 or 2 steps at a time is "<<nthStair(10)<<" way(s)\n";
    //sayDigits(42069);
    return 0;
}