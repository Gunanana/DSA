#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string str,int s, int e){
    if(s>=e) return true;
    else if(str[s]!=str[e]) return false;
    return isPalindrome(str,s+1,e-1);
}

int main(){
    string str="malayalam";
    cout<<isPalindrome(str,0,str.size()-1);
}