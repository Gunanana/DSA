//write a program to solve a postfix expression
#include<bits/stdc++.h>
using namespace std;

void postfixSolver(string str){
    stack<double>st;
    char ch;
    double res,a,b;
    for(int i=0;i<str.length();i++){
        ch=str[i];
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='^') st.push(ch-'0');
        else{
            b=st.top();
            st.pop();
            a=st.top();
            st.pop();
            if(ch=='+') res=a+b;
            else if(ch=='-') res=a-b;
            else if(ch=='*') res=a*b;
            else if(ch=='/') res=a/b;
            else if(ch=='^') res=pow(a,b);
            st.push(res);
        }
    }
    if(st.size()==1) cout<<"The final result is: "<<st.top()<<endl;
    else cout<<"Invalid postfix expression\n";
}

int main(){
    string str;
    cout<<"Enter a postfix expression:\n";
    cin>>str;
    //str="246+-7*84+-";
    postfixSolver(str);
    return 0;
}