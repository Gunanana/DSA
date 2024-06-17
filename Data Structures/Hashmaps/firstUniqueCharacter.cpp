#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int firstUniqueCharacter(string s){
    unordered_map<char,int> frequency;
    for(char i:s) frequency[i]++;
    for(int i=0;i<s.size();i++) if(frequency[s[i]]==1) return i;
    return -1;
}

int main(){
    string s="uunanka";
    cout<<firstUniqueCharacter(s);
}