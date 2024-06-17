#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class trieNode{
    public:    
    char info;
    trieNode* children[26]; 
    bool isTerminal; 
    trieNode(char i):info(i){
        for(int i=0;i<26;i++) children[i]=NULL;
        isTerminal = false;
    }
};

class trie{
    trieNode* root;
    public:
    trie(){
        root = new trieNode('\0');
    }
    //INSERSION
    void insertUtil(trieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=true; 
            return;
        }
        trieNode* child;
        int index= word[0]-'a'; 
        if(root->children[index]!=NULL) child= root->children[index];
        else{
            child= new trieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child, word.substr(1));   
    }
    void insertWord(string word){insertUtil(root,word);}
    //SEARCHING
    bool searchUtil(trieNode *root, string word){
        if(word.length()==0) return root->isTerminal;
        trieNode *child;
        int index= word[0]-'a';
        if(root->children[index]!=NULL) child= root->children[index];
        else return false; 
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){return searchUtil(root, word);}
    //DELETION
    void removeUtil(trieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }
        trieNode* child;
        int index=word[0]-'a';
        child=root->children[index];
        removeUtil(child, word.substr(1));
        int count=0;
        for(int i=0;i<26;i++) if(child->children[i]!=NULL) count++;
        if(count<1){
            root->children[index]=NULL;
            delete child;
        }
    }
    void removeWord(string word){
        if(searchUtil(root,word)){
            removeUtil(root, word);
            cout<<"\""<<word<<"\" was successfully removed from the Trie\n";
        }
        else cout<<word<<" doesnt exist in the Trie\n";
    }
    //PREFIX
    bool prefixUtil(trieNode* root, string word){
        if(word.length()==0) return true;
        trieNode *child;
        int index= word[0]-'a';
        if(root->children[index]) child= root->children[index];
        else return false;
        
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string word){return prefixUtil(root, word);}
};

int main(){
    trie *t= new trie();
    // t->insertWord("wonderful");
    // cout<<t->startsWith("wond")<<endl;
    // cout<<t->searchWord("wonderful")<<endl;
    // cout<<t->searchWord("wonderfu")<<endl;
    // t->insertWord("woke");
    // t->insertWord("woken");
    // t->removeWord("wonderful");
    // cout<<t->searchWord("wonderful")<<endl;
    // cout<<t->startsWith("wonderful")<<endl;
    // cout<<t->searchWord("woken")<<endl;
    // cout<<t->startsWith("woke")<<endl;
    delete t;
    return 0;
}

