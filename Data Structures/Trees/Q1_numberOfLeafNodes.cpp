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
    root = new tree(item);
    queue<tree*> q;
    q.push(root); 
    while(!q.empty()){
        tree* temp= q.front();
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
            temp->right= new tree(item);
            q.push(temp->right);
        }
    }
    return root;
}

int leaves=0;
//using the in/post/preOrderTraversals, instead of printing the node (ILR), check if its right and left are NULL, if yes then counter++
void leafCounter(tree* root){
    if(root==NULL)return;
    if(root->right==NULL&& root->left==NULL) leaves++;
    leafCounter(root->left);
    leafCounter(root->right);
}

int main(){
    tree* root=buildTree();
    leafCounter(root);
    cout<<"There are "<<leaves<<" leaf/leaves in your tree\n";
    return 0;
}