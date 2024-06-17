/*
-> graphs can be represented in 2 ways
1) adjacency matrix and 
2) adjacency list (show below)
*/
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

/*
STEPS:
1) unordered map of the type (int, list<int>);
2) 2 functions
3) addEdge function taking in the start and end vertex and directed bool var;
4) printGraph function printing the graph in nested double for loop
*/

template<typename t>
class graph{
    public:
    //have a hashmap of the type (int(v)-> list(v1,v2,v3)) 
    unordered_map<t , list<t>> adj;

    //2 functions
    //1) to add edges to your graph
    //take in the starting v and the ending vertex in order and also if its a directed vertex or not
    void addEdge(t u, t v, bool directed){
        adj[u].push_back(v);
        //if its undirected, then the reverse direction edge needs to be pushed too
        if(!directed) adj[v].push_back(u);
    }
    //2) to print the graph
    void printGraph(){
        //nested double for loop -> one for all vertices and then for all the v inside its adj list
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph<int> guna;
    int u, v;
    bool directed;
    int e;
    cout<<"Enter number of edges: ";
    cin>>e;
    for(int i=0;i<e;i++){
        cout<<"Enter the end vertices: ";
        cin>>u>>v;
        //cout<<"Is the edge directed? (0/1)";
        //cin>>directed;
        guna.addEdge(u,v,1);
    }
    guna.printGraph();
}
