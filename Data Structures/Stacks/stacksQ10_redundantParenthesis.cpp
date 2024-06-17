#include<bits/stdc++.h>
using namespace std;

bool isRedundantParenthesis(string str){
    stack<char>stk;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        //open parenthesis
        if(ch=='(') stk.push(ch);
        //operators
        else if(ch=='*'||ch=='+'||ch=='-'||ch=='/'||ch=='^'||ch=='%') stk.push(ch);
        //closing parenthesis
        else if(ch==')'){
            if(!stk.empty()){
                //no operator between the closing and open parenthesis then redundant
                if(stk.top()=='(')
                return true;
                //keep popping all operators and then pop open parenthesis. move to next
                else{
                    while(stk.top()!='(') stk.pop();    
                    stk.pop();
                }
            }
            else return true;
        }
    }
    //if function hasnt ended then no redundant parenthesis were found
    return false;
}

int main(){
    cout<<isRedundantParenthesis("(a+b*(c))")<<endl;
    cout<<isRedundantParenthesis("(a+b+c+(d/s))")<<endl;
    cout<<isRedundantParenthesis("(x+(1+x))+1")<<endl;
    cout<<isRedundantParenthesis("(((((())))))")<<endl;
    return 0;
}