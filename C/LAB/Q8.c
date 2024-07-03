#include<stdio.h>
#include<stdlib.h>

struct tree{
    int info;
    struct tree* right;
    struct tree* left;
};

//binarySearchTree creator
struct tree* buildBST(){
    struct tree* root=NULL, *curr, *n,*follow;
    int item;
    printf("Enter elements (-999 to exit):\n");
    scanf("%d",&item);
    while(item!=-999){
        n=(struct tree*)malloc(sizeof(struct tree));
        n->info=item;
        n->left=NULL;
        n->right=NULL;
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
        scanf("%d",&item);
    }
    return root;
}
void inOrderTraversal(struct tree* root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("%d " ,root->info);
    inOrderTraversal(root->right);
}
void postOrderTraversal(struct tree* root){
    if(root==NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d " ,root->info);
}
void preOrderTraversal(struct tree* root){
    if(root==NULL) return;
    printf("%d " ,root->info);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void menu(){
    int c;
    struct tree* start;
    while(1){
        printf("\nChoose...\n1) Create BST.\n2) PreOrder Traverse.\n3) PostOrderTraverse.\n4) InOrder Traverse.\n5) Exit.\n");
        scanf("%d",&c);
        switch(c){
            case 1:
            start=buildBST();
            break;
            case 2:
            printf("\nPreOrder Traversal of your BST is given below\n");
            preOrderTraversal(start);
            break;
            case 3: 
            printf("\nPostOrder Traversal of your BST is given below:\n");
            postOrderTraversal(start);
            break;
            case 4:
            printf("\nInOrder Traversal of your BST is given below:\n");
            inOrderTraversal(start);
            break;
            case 5 : exit(0);
        }
    }
}

int main(){
    menu();
    return 0;
}
