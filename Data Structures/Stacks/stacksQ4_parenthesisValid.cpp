//write a function to check if a parenthesis equation is valid or not
#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string str){
    stack<char>stk;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        //check for opening or closing bracket
        if(ch=='('||ch=='['||ch=='{') stk.push(ch);
        //closing bracket
        else{
            char top=stk.top();
            //has to be not empty since u have an closing bracket unresolved
            if(!stk.empty()){
                //closing bracket matches with opening 
                if((ch==')'&& top=='(')|| (ch==']'&& top=='[') || (ch=='}'&& top=='{')) stk.pop();
                else return false;
            }
            else return false;
        }
    }
    //after loop, check if final stack is empty or not
    if(stk.empty()) return true;
    else return false;
}

int main(){
    string str;
    cout<<"Enter a parenthesis expression\n";
    cin>>str;
    if(isValidParenthesis(str)) cout<<"Its a valid expression\n";
    else cout<<"Invalid expression\n";
    return 0;
}