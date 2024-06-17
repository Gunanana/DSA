//"those who forget their past are condemned to repeat it"


#include<bits/stdc++.h>
using namespace std;
/*
2 methods
1) memoization method
2) tabulation method
*/

//memoization method
int fibmemo(int n, vector<int> &dp){
    //base case
    if(n<=1) return 1;
    //memory case
    if(dp[n]!=-1) return dp[n];
    //store in memory
    dp[n]=fibmemo(n-1,dp)+fibmemo(n-2,dp);
    return dp[n];
}

//tabulation method
int fibtab(int n){
    //exceptional case
    if(n<=1) return n;
    vector<int> dp(n+1);
    //set base case values
    dp[0]=0;
    dp[1]=1;
    //iterate instead of function recursive call
    for(int i=2;i<n+1;i++) dp[n]=dp[n-1]+dp[n-2];
    return dp[n];
}

//tabulation with space optimisation
int fibtabop(int n){
    //exceptional case
    if(n<=1) return n;
    //set base values
    int prev1=1;
    int prev2=0;
    int curr;
    for(int i=2;i<n+1;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int main(){
    int n;
    cout<<"Enter the index: ";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"Using Memoization Method: "<<fibmemo(n,dp)<<endl;
    cout<<"Using Tabulation Method: "<<fibtab(n)<<endl;
    cout<<"Using Tabulation with Space Optimisation Method: "<<fibtabop(n)<<endl; 
    return 0;
}