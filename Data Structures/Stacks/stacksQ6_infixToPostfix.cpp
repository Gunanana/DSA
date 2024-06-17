//write a program to convert infix expression to a postfix expression
#include<bits/stdc++.h>
using namespace std;

class operatorPrecedence{
    public:
    int precedence;
    operatorPrecedence(int x){
        precedence =x;
    }
};

void infixToPostfix(string str){
    stack<char>stk;
    //stack<char>postfixrev;
    char postfix[100];
    int j=0;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        //opening bracket
        if(ch=='(') stk.push(ch);
        //operands
        else if(ch<=57&&ch>=48) postfix[j++]=ch;
        //closing bracket
        else if(ch==')'){
            while(stk.top()!='('){
                postfix[j++]=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        //operators
        else{
            char top=stk.top();
            if(ch=='^'){
                while(top=='^'){
                    postfix[j++]=stk.top();
                    stk.pop();
                    top=stk.top();
                }
                stk.push(ch);
            }
            else if(ch=='*'||ch=='/'){
                while(top=='*'||top=='/'||top=='^'){
                    postfix[j++]=stk.top();
                    stk.pop();
                    top=stk.top();
                }
                stk.push(ch);
            }
            else if(ch=='+'||ch=='-'){
                while(top=='*'||top=='/'||top=='^'||top=='+'||top=='-'){
                    postfix[j++]=stk.top();
                    stk.pop();
                    top=stk.top();
                }
                stk.push(ch);
            }
            else stk.push(ch);
        }
    }
    cout<<"\nThe Equivalent Postfix expression is\n"<<postfix<<endl;
}

int main(){
    //operatorPrecedence ^(5);
    deque<char>arr;
    string str1;
    string str="6+2*(8-4)^(7/8)+4^8*5/9*1^(2+3)";
    // cout<<"Enter your infix expression\n";
    // cin>>str;
    if(str[0]!='('){
        for(int i=0;i<str.size();i++){
            arr.push_back(str[i]);
        }
        arr.push_front('(');
        arr.push_back(')');
        for(auto i:arr){
            str1.push_back(i);
        }
    }
    infixToPostfix(str1);
}