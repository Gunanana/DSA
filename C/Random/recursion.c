//factorial, fibonacci, and product
#include<stdio.h>
int factorial(int n){
    if(n==1 || n==0) return 1;
    else return n*factorial(n-1);
}

int product(int a,int b){
    if(b==1) return a;
    else return a+product(a,b-1);
}

int fibonacci(int n){
    if(n==1||n==2) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);

}

int main(){
    //int fact=fibonacci(0);
    printf("%d",product(10,45));
}