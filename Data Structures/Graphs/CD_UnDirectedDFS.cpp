#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

/*
Is cyclic if a vertex A tries to go an already visited vertex B but A didnt come from B;
*/
class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

//normal dfs but if a vertex is adj to an visited vertex, check if the adj is a parent or not
//if not parent then its cyclic
unordered_map<int, bool> visited;
unordered_map<int, int> parent;
bool isCyclicDFS(graph &g, int v){
    visited[v]=true;
    for(auto i: g.adj[v]){
        bool cyclic=false;
        if(!visited[i]){
            parent[i]=v;
            cyclic=isCyclicDFS(g,i);
        }
        else if(visited[i] && parent[v]!=i){
            return true;
        }
        if(cyclic) return true;
    }
    return false;
}

int main(){
    graph g;
    int edges,u,v,vertices;
    cout<<"Enter number of vertices <space> edges: "; 
    cin>>vertices>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    //call the function for every single component
    bool flag=false;
    for(int i=0;i<vertices;i++){
        flag= isCyclicDFS(g,i);
        if(flag) break;
    }
    isCyclicDFS(g,0)?cout<<"Cyclic": cout<<"Not Cyclic";
    return 0;

}