#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

//STEPS:
//1) push all its children into queue;
//2) pop the top most, push it into bfs array and then call bfs for that
unordered_map<int, bool> visited;
vector<int> bfs;
queue<int> q;
void bfs_recursive(int v, graph &g){
    //Step 1)
    for(auto i: g.adj[v]){
        if(!visited[i]){
            q.push(i);
            visited[i]=true;
        }
    }
    //Step 2) 
    if(!q.empty()){
        int x= q.front();
        q.pop();
        bfs.push_back(x);
        bfs_recursive(x,g);
    }
}

int main(){
    graph g;
    int edges, u,v;
    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    bfs.push_back(0);
    bfs_recursive(0,g);

    for(auto i: bfs) cout<<i<<" ";
}