#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

/*
using BFS
-> basically u have a new parent map which stores the parent of each vertex;
-> after finding the parent for all the vertices, backtrack, going from the final vertex, finding its parent, and their parent and so on till u find the initial vertex.
-> now u have the shortest path.
-> this works because bfs goes level by level and the final vertex is first touched by the shortest path
*/

class graph{
    public: 
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

vector<int> shortestPathBFS(graph &g, int i, int f){
    unordered_map<int, bool> visited;
    queue<int> q;
    unordered_map<int, int> parent;
    vector<int>shortestPath;
    visited[i]=true;
    parent[i]=-1;
    q.push(i);

    //initialise the parent map
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i: g.adj[x]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=x;
                q.push(i);
            }
        }
    }
    //initialise the shortestPath vector
    int x=f;
    shortestPath.push_back(x);
    while(parent[x]!=-1){
        shortestPath.push_back(parent[x]);
        x=parent[x];
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;

}

int main(){
    graph g;
    int edges, vertices,u,v,i,f;
    cout<<"Enter number of vertices <space> edges: "; cin>>vertices>>edges;
    cout<<"u <space> v:"<<endl;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"Enter your initial and final vertices: "; cin>>i>>f;
    cout<<"The shortest path";
    for(auto stone: shortestPathBFS(g,i,f)) cout<<" -> "<<stone;
    return 0;
}