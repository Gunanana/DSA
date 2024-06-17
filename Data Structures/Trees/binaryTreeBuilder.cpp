#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

//Iteration: builder using levelOrder can recognise which level or height they are in 

//Recursion: traversal go to each and every node
//if base case is hit, then it means that the prev root is a leaf node
//if the function ends, then 1 subtree (atomic) is done (can be for a leaf or BAC tree)

//make use of this knowledge and you can solve any question ngl

class tree{
    public:
    int info;
    tree* right;
    tree* left;
    tree(int d):info(d),right(NULL),left(NULL){}
};

//binarySearchTree creator
tree* buildBST(){
    tree* root=NULL, *curr, *n,*follow;
    int item;
    cout<<"Enter elements (-999 to exit):\n";
    cin>>item;
    while(item!=-999){
        n= new tree(item);
        if(root==NULL)root=n;
        else{
            curr=root;
            while(curr!=NULL){
                follow=curr;
                if(item<=curr->info) curr=curr->left;
                else curr=curr->right;
            }
            if(item<=follow->info) follow->left=n;
            else follow->right= n;
        }
        cin>>item;
    }
    return root;
}

//binaryTree creator uisng levelOrderTraversal
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

int main(){
    tree* root =buildBST();
    levelOrderTraversal(root);
}
