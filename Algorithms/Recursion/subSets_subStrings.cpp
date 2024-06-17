#include<iostream>
#include<vector>
using namespace std;

//idk how this works but damn
//1)subSets
void solver(vector<int> arr,int index,vector<int> &output,vector<vector<int>> &ans){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solver(arr,index+1,output,ans);
    //include
    int element=arr[index];
    output.push_back(element);
    solver(arr,index+1,output,ans);
}

vector<vector<int>> powerSet(vector<int>arr){
    int index=0; //goes to next level 
    vector<vector<int>> ans; //contains the last line output
    vector<int> output; //(input,output) push elements or choose not to
    solver(arr,index,output,ans);
    return ans; //2d vector which has all the subsets
}

//2)subStrings
void solver(vector<char> arr,int index,vector<char> &output,vector<vector<char>> &ans){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solver(arr,index+1,output,ans);
    //include
    int element=arr[index];
    output.push_back(element);
    solver(arr,index+1,output,ans);
}

vector<vector<char>> powerSet(string str){
    vector<char> arr;
    for(int i=0;i<str.length();i++)arr.push_back(str[i]);
    int index=0; //goes to next level 
    vector<vector<char>> ans; //contains the last line output
    vector<char> output; //(input,output) push elements or choose not to
    solver(arr,index,output,ans);
    return ans; //2d vector which has all the subsets
}