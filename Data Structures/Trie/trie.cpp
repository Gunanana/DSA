/*Object of the trie class is a collection of objects
this trie object has a root trie node object and all the functions to play with it
trie node object is all the children and root
each trie node object has data and an array of pointers (all alphabet hence 26 pointers) to point to its successors
all of these are joined together to form the trie tree
trie tree is a part of a trie object along with the functions to access it*/

#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

//create a class for the node objects of the Trie
class trieNode{
    public:
    //it has data and points to 26 of its children
    char info;
    trieNode* children[26]; //create array of pointers
    bool isTerminal; //is true only for the last node/child node
    //initialise the info and make all its children NULL
    trieNode(char i):info(i){
        for(int i=0;i<26;i++) children[i]=NULL;
        isTerminal = false;
    }
    ~trieNode(){cout<<this->info<<" node freed\n";}
};

//create class trie which handles the trie tree (all trie nodes) and the functions to operate on them too
class trie{
    //a pointer to its main root. this holds nothing. like an index page. this points to all the starting letters
    trieNode* root;
    public:
    //constructor to initialise its root part
    trie(){
        root = new trieNode('\0');
    }


    //INSERTION
    void insertUtil(trieNode* root, string word){
        //check if word is empty, if its done
        if(word.length()==0){
            root->isTerminal=true; //if word is empty then this root which came in from previous function call has the last letter and hence it's the terminal root
            return;
        }
        //if not the last letter in the word, 3 steps
        //1) create child pointer 
        trieNode* child;
        int index= word[0]-'a'; //get the index of this letter (assumed that all letters in the word are NOT capitalised)
        //2) check if that letter already exists
        //if yes then point the child pointer to it
        if(root->children[index]!=NULL) child= root->children[index];
        //if no, create a trie node object and point the child to it, do so by sending in the letter
        else{
            child= new trieNode(word[0]);
            root->children[index]=child;
        }
        //3) call the function again by sending in the child trie node object and removing the first letter in word
        insertUtil(child, word.substr(1)); //substr returns a new string which is the substring of the original string it is called upon, its synatx is: string.substr(<int pos>, <int length>);. from which position u wanna create a substring from and till how many letters. if only pos is sent, then length is assumed as str.size();
            
    }
    void insertWord(string word){insertUtil(root,word);}


    //SEARCHING
    bool searchUtil(trieNode *root, string word){
        //if word is empty, that means it has reached till there without being false for any previous letters. now check if the root is the terminal one (the last letter inside the trie). if not then word does not exist. 
        //for ex: searching for 'star' but trie has 'starfruit' but not 'star' alone as a word
        if(word.length()==0) return root->isTerminal;
        //
        trieNode *child;
        int index= word[0]-'a';
        //check if next letter exists, if yes then point the child to it and call function again
        if(root->children[index]!=NULL) child= root->children[index];
        else return false; //else if next letter does not exist in trie, then that word as a whole was not in the trie, so return false
        //call same function for the next letter in the word
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){return searchUtil(root, word);}


    //DELETION
    void removeUtil(trieNode* root, string word){
        //just make the last letter or the trie node object as not terminal and hence this will not get detected by the search function
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }
        //dont check if the next child exists (it has to exist since this function is called in the first place)
        trieNode* child;
        int index=word[0]-'a';
        child=root->children[index];
        removeUtil(child, word.substr(1));
        //to actually delete that word and not just making the last letter as not the terminating character...
        int count=0;
        for(int i=0;i<26;i++) if(child->children[i]!=NULL) count++;
        if(count<1){
            root->children[index]=NULL;
            delete child;
        }

    }
    void removeWord(string word){
        //call the function only if the word actually exists in the Trie
        if(searchUtil(root,word)){
            removeUtil(root, word);
            cout<<"\""<<word<<"\" was successfully removed from the Trie\n";
        }
        else cout<<word<<" doesnt exist in the Trie\n";
    }


    //PREFIX
    bool prefixUtil(trieNode* root, string word){
        //just check if the word is empty, need not check if its the terminal letter since we need to check if we have the prefix or not, not the entire word
        if(word.length()==0) return true;
        //if the prefix is not completed, then check if next letter of the prefix exists inside the trie, if it does, then move the child to the next letter, if not then return false
        trieNode *child;
        int index= word[0]-'a';
        if(root->children[index]) child= root->children[index];
        else return false;
        //call the function again for the next letter inside the word
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string word){return prefixUtil(root, word);}

    ~trie(){cout<<"Trie freed\n";}
};

int main(){
    trie *t= new trie();
    t->insertWord("wonderful");
    cout<<t->startsWith("wond")<<endl;
    cout<<t->searchWord("wonderful")<<endl;
    cout<<t->searchWord("wonderfu")<<endl;
    t->insertWord("woke");
    t->insertWord("woken");
    t->removeWord("wonderful");
    cout<<t->searchWord("wonderful")<<endl;
    cout<<t->startsWith("wonderful")<<endl;
    cout<<t->searchWord("woken")<<endl;
    cout<<t->startsWith("woke")<<endl;
    delete t;
    return 0;
}
