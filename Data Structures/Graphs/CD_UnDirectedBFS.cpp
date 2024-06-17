#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

//"There exists a cycle iff a vertex goes to an already visited vertex, but, the visited vertex is not the parent of this vertex..."
//its not a cycle when vertex A goes to visited vertex B but prior to this, A came from B, hence it was visited
//when vertex A goes to visited vertex B but A didnt come from B its cyclic then

//normal bfs, but here we are checking if (a vertex is adj to a visited vertex && the visited vertex is not the parent of this vertex)

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

/*
STEPS:
1) 3 containers 1) visited hashmap, 2) parent hashmap, 3) queue
2) push, mark, note the initial vertex (push into q, mark as visited, note its parent)
3) put a while loop and do the following for all the vertices
4) pop vertex, call a for loop for all the adj vertices of this vertex. this x is the parent of all these adjacent vertices
                going from x-> i
5) 3 cases->1) i was not visited, so note x as p, mark and push i
            2) i was visited but i was the parent so no cycle yet
            3) i was visited but i was not x's parent, so cycle
*/

//bfs function returns true or false
unordered_map<int, bool> visited;
unordered_map<int, int> parent;
queue<int> q;

bool isCyclicBFS(graph &g, int v){
    //3 containers
    //push the initial v to q and then mark its parent are -1 since it does not exist
    visited[v]=true;
    parent[v]=-1;
    q.push(v);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i: g.adj[x]){
            if(visited[i] && parent[x]!=i){
                return true;
            }
            else if(!visited[i]){
                parent[i]=x;
                visited[i]=true;
                q.push(i);
            }
            else if(visited[i]); //neglect
        }
    }
    return false;
}


int main(){
    graph g;
    int edges, u, v;
    cin>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    if(isCyclicBFS(g,1)) cout<<"Yes";
    else cout<<"No";
}