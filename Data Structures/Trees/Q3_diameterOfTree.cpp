#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class tree{
    public:
    int info;
    tree* right;
    tree*left;
    tree(int d):info(d),right(NULL), left(NULL){}
};

tree* buildTree(){
    tree* root=NULL;
    int item;
    cout<<"Enter root: ";
    cin>>item;
    root = new tree(item);
    queue <tree*> q;
    q.push(root);
    while(!q.empty()){
        tree* temp= q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->info<<" (-1 if no child): ";
        cin>>item;
        if(item==-1);
        else {
            temp->left= new tree(item);
            q.push(temp->left);
        }
        cout<<"Enter the right child of "<<temp->info<<" (-1 if no child): ";
        cin>>item;
        if(item==-1);
        else{
            temp->right= new tree(item);
            q.push(temp->right);
        }
    }
    return root;
}

//height finder function
int heightFinderR(tree* root){
    if(root==NULL) return 0;
    int left= heightFinderR(root -> left);
    int right= heightFinderR(root -> right);
    return max(left, right)+1;
}

//diameter is the longest distance between any two nodes
//case 1: the diameter is a part of left subtree
//case 2: the diameter is a part of right subtree
//case 3: the diameter is a part of both right and left subtree
//for case 3: u need to find the height of both left and right and add 1 (including the root itself)
//before a function ends, it has 3 values, diameter of left and right subtree, and the diameter of the left and right combined by adding the heights of left and right subtree (remember this need not be the largest all the time. if height of either side is small, then the diameter in the opposite tree can be larger). compare btw these three and return the largest one
//then compare all three find the largest one and return it;
int diameter(tree *root){
    if(root==NULL) return 0;
    int case1= diameter(root->left);
    int case2= diameter(root->right);
    int case3= heightFinderR(root->left)+heightFinderR(root->right)+1;
    return max(case2, max(case1,case3));
}

//optimised version
pair<int,int> diameterOP(tree* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left= diameterOP(root->left);
    pair<int,int> right= diameterOP(root->right);

    int case1=left.first;
    int case2=right.first;
    int case3=left.second+right.second+1;

    pair<int,int> ans;
    ans.first=max(case2, max(case3,case2));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

int diameterOptimised(tree* root){return diameterOP(root).first;}