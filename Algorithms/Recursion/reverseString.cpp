#include<iostream>
using namespace std;

void stringPrinter(string str){
    for(int i=0;i<str.size();i++)cout<<str[i];
    cout<<endl;
}

void reverseString(string &str,int start,int end){
    if(end-start<=1) return;
    char temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    reverseString(str,start+1,end-1);
}

int main(){
    string guna="karaN";
    stringPrinter(guna);
    reverseString(guna,0,(guna.size()-1));
    stringPrinter(guna);
}