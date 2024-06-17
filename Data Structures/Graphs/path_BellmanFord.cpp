#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;


/*
the final shortest path algorithm - Bellman Ford
-> iterates n-1 times (n= number of vertices) and relaxes all the vertices 
-> after n-1 times the distance vector would have the shortest distance to all the vertices
-> slower than dijkstra but works for negative edges

cycle detection
-> after running the loop for n-1 times, run the loop once more time, if the if (new distance< org distance) condition is entered, then a negative weight cycle exists and hence return true

*/
class graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;
    void addEdge(int u, int v, int weight){
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
};

/*
STEPS
1) declaration
    1) take in source, v count, e count and the edges vector
2) initialisation
    1) distance vector and distance 1e9 or 1e8 for all initially
    2) set distance of source as 0
3) run the loop n-1 times
    1) for all the edges in the edges vector, relax the vertices inside if
*/

vector<int> bellmanFord(int n, int e, int src, vector<vector<int>> &edges){
    vector<int> distance(n,1e8);
    distance[src]=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int u= edges[j][0];
            int v= edges[j][1];
            int wt= edges[j][2];
            if(distance[u]!= 1e8 && (distance[u] + wt) < distance[v]){
                distance[v]=distance[u]+wt;
            }
        }
    }

    for(int j=0;j<e;j++){
        int u= edges[j][0];
        int v= edges[j][1];
        int wt= edges[j][2];
        if(distance[u]!= 1e9 && (distance[u] + wt) < distance[v]){
            return {-1};
        }
    }
    return distance;
}
