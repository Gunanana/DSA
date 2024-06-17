#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class tree{
    public:
    int info;
    tree* right;
    tree* left;
    tree(int d): info(d), right(NULL), left(NULL){}
};

tree* buildTree(){
    tree* root=NULL;
    int item;
    cout<<"Enter root: ";
    cin>>item;
    root=new tree(item);
    queue<tree*>q;
    q.push(root);
    while(!q.empty()){
        tree* temp=q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->info<<": ";
        cin>>item;
        if(item==-1);
        else{
            temp->left= new tree(item);
            q.push(temp->left);
        }
        cout<<"Enter the right child of "<<temp->info<<": ";
        cin>>item;
        if(item==-1);
        else{
            temp->right=new tree(item);
            q.push(temp->right);
        }
    }
    return root;
}

//normal iterative method using levelOrder
int height=0;
//using levelOrderTraversal, whenever you encounter NULL, that means 1 level is done
void heightFinderI(tree* root){
    queue<tree*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        tree* temp= q.front();
        q.pop();
        if(temp==NULL){
            height++;
            if(!q.empty())q.push(NULL);
        }
        else{
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

//recursion using traversals
//return height of each small tree, compare with left and right and retain the largest one
//base case is hit when the prev root is a leaf so return 0
//if the function ends, then a sub tree has ended, that means both right and left are done so, compare them and return the largest+1 considering the root of the sub tree too
//a leaf node gets 0 from both right and left and it itself returns 1 to its parent
int heightFinderR(tree* root){
    if(root==NULL) return 0;
    int left= heightFinderR(root->left);
    int right=heightFinderR(root->right);
    return max(left,right)+1;
}

int main(){
    tree *root= buildTree();
    heightFinderI(root);
    cout<<endl;
    cout<<"The height of your tree is: "<<height<<endl;
    cout<<"The height of your tree is: "<<heightFinderR(root)<<endl;
    return 0;
}