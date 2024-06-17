//use stacks to reverse a string
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string str1;
    cout<<"Enter the string u wanna reverse:\n";
    cin>>str1;
    stack<char> a;
    for(int i=0;i<str1.length();i++){
        char c= str1[i];
        a.push(c);
    }
    string revstr1="";
    while(!a.empty()){
        char c=a.top();
        revstr1.push_back(c);
        a.pop();
    }
    cout<<"Your reversed string is:\n"<<revstr1;
}
