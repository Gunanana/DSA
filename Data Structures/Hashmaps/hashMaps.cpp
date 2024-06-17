#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    //CREATION
    unordered_map<int,int>m;


    //INSERT
    /*three ways
    1. use function make_pair to create a pair and insert the pair
    2. use pair's constructor and create a pair, then insert the pair inside the map
    3. use the [] operator with the map name and assign value to that key
    */
    //1
    pair<int,int> p=make_pair(1,100);
    m.insert(p);

    //2
    pair<int,int> p1(12,10);
    m.insert(p1);

    //3 use this for updations. do hashmap[key]++. if its the first one then first half returns 0 and gets increased to 1. no errors
    m[13]=10;


    //MISC
    //returns key at value/ error if that key doesnt exist
    m.at(13);

    //returns size
    m.size();

    //returns the max size
    m.max_size();

    //first and second parameters for the pair
    for(auto i:m){
        cout<<i.first;
        cout<<i.second;
    }

    //PRESENCE
    //2 ways. 1) using count but it returns an integer (0 or 1). 2) using find function but it returns an iterator to that key if present. returns the last iterator if absent
    //both function in logarithmic time 
    
    //1 count function
    //returns 1 if present, 0 if not disregarding the value of that key
    m.count(1);

    //2 find function. returns iterator to key 1 if present. returns iterator to the last pair otherwise it==m.end();
    m.find(1);


    //DELETION
    m.erase(13);


    //ITERATOR
    //iterator is a pointer to that one pair (key,value)
    //since its a pointer, we have to use -> op to access the key's first and second public parameters
    //or first dereference the pointer using * enclosed in parenthesis and then use the first and second functions

    //begin and end functions
    //returns an iterator to the first pair and end returns an iterator to the last pair
    m.begin(); 
    m.end();

    //initialise the pointer or iterator
    unordered_map<int,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    unordered_map<int,int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        cout<<iter->first<<" "<<iter->second<<"\n";
    }

    
}