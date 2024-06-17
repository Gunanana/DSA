#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

vector<vector<int>>allPaths;
vector<int>path;
unordered_map<int, bool> visited;
void dfsPath(graph &g, int v, int f){
    visited[v]=true;
    path.push_back(v);
    if(v==f)allPaths.push_back(path);
    for(auto i: g.adj[v]){
            dfsPath(g,i,f);

    }
    path.pop_back();
}

int main(){
    graph g;
    int vertices, edges, u, v, initial, final;
    cin>>vertices>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cin>>initial>>final;
    dfsPath(g,initial,final);
    for(auto i: allPaths){
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}