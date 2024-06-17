#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
using namespace std;

/*
Topological sort is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering (or the dfs type displays we do for any graph). This ordering is used to represent dependencies in systems where certain tasks must precede others
*/

/*
-> this can be achieved by CHANGING ALMOST NOTHING IN A TRADITIONAL DFS fx. just have a stack after the for auto loop and push in the vertex v. and make sure to call the dfs fs for all the vertices since we have to display the entire graph and not only 1 component
-> now the reason why this is working is because, the first vertex thats gonna get pushed is the one which cant go to any other vertex anymore. and in stack, its gonna be the bottom one or the last one in our ordering.
-> this aligns with our topo sort definition
*/

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
};

unordered_map<int,bool> visited;
stack<int> ans;
vector<int> dfs;

void topologicalSortDFS(graph &g, int v){
    visited[v]=true;
    dfs.push_back(v);
    for(auto i: g.adj[v]){
        if(!visited[i]){
            topologicalSortDFS(g,i);
        }
    }
    ans.push(v);
}

int main(){
    graph g;
    int u,v,edges, vertices;
    cout<<"Enter number of vertices and edges: "; cin>>vertices>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }

    //call topological sort function for all the components
    for(int i=0;i<vertices;i++) if(!visited[i])  topologicalSortDFS(g,i);
    cout<<"Your unsorted dfs: ";
    for(auto i: dfs) cout<<i<<" ";
    cout<<endl<<"Your topologically sorted dfs: ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}