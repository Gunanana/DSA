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

    //LONGEST PREFIX
    //means these letters are common to all the words inside the trie. hence these nodes must have only 1 child, ie the next letter common for all these letters + it shouldnt be a terminal node
    string longestPrefixUtil(trieNode* root, string &word){
        int noOfChild=0;
        int index=0;
        for(int i=0;i<26;i++) if(root->children[i]!=NULL){
            noOfChild++;
            index=i;
        }
        if((noOfChild>1||noOfChild==0)||root->isTerminal) return word;
        trieNode *child=root->children[index];
        word.push_back(child->info);
        return longestPrefixUtil(child,word);

    }
    string longestPrefix(){
        string word="";
        return longestPrefixUtil(root,word);}
};



int main(){
    trie *t= new trie();
    t->insertWord("wonderful");
    t->insertWord("wonder");
    t->insertWord("wonderf");
    cout<<t->longestPrefix();
    delete t;
    return 0;
}

