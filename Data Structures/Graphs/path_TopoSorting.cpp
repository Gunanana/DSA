#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

/*
first i wanna start off by saying that this is a beautiful program
-> shortest path between an source vertex and all the other vertices from this
-> ALGORITHM:
    1) class graph and initialise your graph
    2) write a topo fx and initialise your topo stack
    3) shortest path function
        1) take in graph, source vertex, and distance vector (all elements are initialised to oo)
        2) distance vector (distance[i]= distance between vertex i and the source vertex src)
        3) set distance of source vertex=0
        4) put a while loop until stack not empty
        5) pop the top element, if its oo, then it can never be reached hence ignore (cuz if u get oo before the source vertex in the topo stack, then that means that this vertex comes before the source vertex and there is no means to reach it (cuz no cycle))
        6) if its not oo, then for all top's adjacent vertices update the distance by taking the minimum of previous distance and the new distance from top (new distance from top is (weight of the incident edge)+(distance of top) )
*/
class graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;
    //<vertex, adj list <vertex, weight>>
    void addEdge(int u, int v, int weight){
        adj[u].push_back({v,weight});
    }
};

stack<int> topo;
unordered_map<int, bool> visited;

void topoSortDFS(graph &g, int v){
    visited[v]=true;
    for(auto i: g.adj[v]){
        if(!visited[i.first]){
            topoSortDFS(g,i.first);
        }
    }
    topo.push(v);
}

void shortestPath(graph &g, vector<int> &distance, int source){
    distance[source]=0;
    int top;
    while(!topo.empty()){
        top=topo.top();
        topo.pop();

        if(distance[top]!=INT_MAX){
            for(auto i : g.adj[top]){
                distance[i.first]= min(distance[i.first],(distance[top]+i.second ));
            }
        }
    }
}

int main(){
    graph g;
    int u,v,vertices,edges,weight,src;
    cin>>vertices>>edges;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>weight;
        g.addEdge(u,v,weight);
    }
    cin>>src;
    //call the topo sort function to initialise the topo stack
    for(int i=0;i<vertices;i++) if(!visited[i]) topoSortDFS(g,i);
    vector<int>distance(vertices,INT_MAX);
    //call the shortestPath function to initialise this distance vector
    shortestPath(g,distance,src);

    for(auto i: distance){
        if(i==INT_MAX) cout<<"/ ";
        else cout<<i<<" ";
    }

}

