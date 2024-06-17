#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

/*
-> Unlike the method in undirected graph where we needed the parent hashmap to determine each vertices parent, here we dont need that;
-> here we need a new map, ie the samePathVisited;
-> this one keep tracks of the path, is true for all the vertices that is currently in that path
-> so if a vertex A tries to goes to a visited vertex B and it happens that B is currently in the same path as A (samePathVisited will return true for B), then cycle exists

-> we make a vertex's samePathVisited false when the function ends for that vertex, meaning that vertex is signing out of that path
*/

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
};

/*
Steps same as a normal DFS but 
1) mark visited AND samePathVisited true at beginning;
2) put for loop for all adj vertices, 
3) 2 cases: adj is not visited, is visited and also is on the same path
4) before function ends sign the vertex out of path by marking the samePathVisited as false for that vertex
*/
unordered_map<int, bool> visited;
unordered_map<int, bool> samePathVisited;
bool isCyclicDFS(graph &g, int v){
    visited[v]=true;
    samePathVisited[v]=true;
    for(auto i: g.adj[v]){
        bool cyclic=false;
        if(!visited[i]) {
            cyclic=isCyclicDFS(g,i);
            if(cyclic) return true;
        }
        else if(visited[i] && samePathVisited[i]) return true;
    }
    samePathVisited[v]=false;
    return false;
}

int main(){
    graph g;
    int u,v,vertices,edges;
    cout<<"Enter vertices <space> edges: ";
    cin>>vertices>>edges;

    cout<<"u <space> v:"<<endl;
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }

    //call fx for all vertices
    bool cyclic=false;
    for(int i=0;i<vertices;i++){
        cyclic=isCyclicDFS(g,i);
        if(cyclic) break;
    }
    cyclic? cout<<"Cyclic": cout<<"Not Cyclic";
    return 0;
}

