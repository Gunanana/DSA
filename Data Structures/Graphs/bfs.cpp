#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
#include<stdlib.h>

using namespace std;

class graph{
    public:
    //adjacency list
    unordered_map<int, list<int>> adj;
    //method to add edges
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

vector<int> bfs(graph &g, int v){
    //3 containers
    //1) Queue, 2) a BFS vector, 3) Visited hashmap;
    queue<int> q;
    vector<int> bfs;
    unordered_map<int, bool> visited;

    //first push the v vertex to start the loop
    q.push(v);
    visited[v]=true;
    
    //while loop where u take out v from queue, push it into bfs array, push all its kids into the queue and die;
    while(!q.empty()){
        int x= q.front();
        bfs.push_back(x);
        q.pop();
        
        //a for loop to push all its kids into the queue and mark them visited
        for(auto i: g.adj[x]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }

    //print the bfs array or return it or both
    for(auto i: bfs) cout<<i<<" ";
    return bfs;
}



int main(){
    system("CLS");
    graph g;
    int edges,u,v;
    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    bfs(g,0); //initial vertex too
    return 0;
}



