//WAP to solve tower of hanoi using recursion
#include<stdio.h>
#include<stdlib.h>

void toh(int n, char s, char i, char d){
    if(n>0){
        toh(n-1,s,d,i);
        printf("Move %d from %c to %c\n",n,s,d);
        toh(n-1,i,s,d);
    }
}

int main(){
    toh(3, 'S', 'I', 'D');
    return 0;
}