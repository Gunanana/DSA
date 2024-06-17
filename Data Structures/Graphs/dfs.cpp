#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

//dfs -> depth first search
class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

/*
STEPS:
1) class graph with adj and addEdge Method

//dfs fx
2) 2 containers 1) visited hashmap, and 2) ans vector;
3) take in graph and the initial vertex;
4) mark that vertex as visited, and push it into dfs ans vector;
5) and now for that vertex, put a for loop for all its adjacent vertices; 
6) if the adj vertex is not visited, then call dfs for that adj v;

//main fx
7) take in number of e and v
8) take in all the end vertices
9) ask where they wanna start the dfs and call dfs fx
10) print dfs vector

*/
unordered_map<int, bool> visited;
vector<int> ans;
void dfs(graph &g, int v){
    visited[v]=true;
    ans.push_back(v);
    for(auto i: g.adj[v]){
        if(!visited[i]){
            dfs(g,i);
        }
    }
}

int main(){
    graph g;
    int edges,u,v,vertices;
    cout<<"Enter number of vertices <space> edges in your graph: ";
    cin>>vertices>>edges;
    cout<<"u <space> v"<<endl;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<"Enter the vertex where u wanna start the DFS: ";
    cin>>v;
    dfs(g,v);

    cout<<"DFS: ";
    for(auto i: ans) cout<<i<<" ";

}