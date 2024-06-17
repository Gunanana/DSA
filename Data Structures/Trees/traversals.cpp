#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class tree{
    public:
    int info;
    tree* right;
    tree* left;
    tree(int d):info(d), right(NULL), left(NULL){}
};

tree* buildBST(){
    tree* root=NULL, *n,*follow,*curr=root;
    int item;
    cout<<"Enter the elements\n";
    cin>>item;
    while(item!=-999){
        n= new tree(item);
        if(root==NULL) root=n;
        else{
            curr=root;
            while(curr!=NULL){
                follow=curr;
                if(item>curr->info) curr=curr->right;
                else curr=curr->left;
            }
            if(item>follow->info) follow->right= n;
            else follow->left= n;
        }
        cin>>item;
    }
    return root;
}

void levelOrderTraversal(tree *root){
    queue<tree*> q; 
    q.push(root); //first push the root
    q.push(NULL); //push NULL to convey that the first level is done
    cout<<endl;
    while(!q.empty()){
        //pop and then check 2 conditions
        tree *temp=q.front();
        q.pop();
        //if null then that means that level is done hence, cout endl. 
        if(temp==NULL){
            cout<<endl;
            //then check if the queue is empty or not, if not then push another null since all of next level would have come if this null is encountered
            if(!q.empty()) q.push(NULL);
        }
        //if element, then cout the element and then take in its children
        else{
            cout<<temp->info<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

//LIR
void inOrderTraversal(tree* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    cout<<root->info<<" ";
    inOrderTraversal(root->right);
}

//ILR
void preOrderTraversal(tree* root){
    if(root==NULL) return;
    cout<<root->info<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//LRI
void postOrderTraversal(tree* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->info<<" ";
}


int main(){
    //5 3 7 2 4 6 8 -999
    tree* root= buildBST();
    levelOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    return 0;
}