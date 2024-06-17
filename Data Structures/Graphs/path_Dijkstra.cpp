#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<utility>
#include<list>
#include<set>
using namespace std;
 
/*

-> "the nearest vertex to the source vertex cannot get any nearer..."
-> for shortest path finding we have 4 algorithms and all of them are required for different scenarios but the latter ones applicable for all the preceding scenarios

1) bfs (for ud, non weighted or unit weighted)
2) topo sorting (for d, weighted)
3) dijkstra's (for ud/d, non negative weighted)
4) bellman ford's (for ud/d, non negative weighted cycles)

DIJKSTRA'S ALGORITHM :
1) declaration: 
    1) take in graph g, distance vector, source vertex
    2) have a set data structure
2) initialisation: 
    1) make distance of source =0;
    2) push the <distance, vertex> pair into the set
3) while set ! empty loop
    1) pop the top
    2) run a for loop for its adjacent vertices
    3) if new distance if smaller than the old distance then: 
        1) pop the old distance from set
        2) update the new distance 
        3) push into set
    4) repeat until set empty
*/

class graph{
    public: 
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u, int v, int weight){
        adj[u].push_back({v,weight});
        //adj[v].push_back({u,weight});
    }
};

void dijkstra(graph &g, vector<int> &distance, int source){

    set<pair<int,int>> st;
    distance[source]=0;
    st.insert({distance[source],source});

    while(!st.empty()){
        //pop the top element
        pair<int,int> top=*(st.begin());
        int vertex= top.second;
        int dist= top.first;

        //erase it from the set
        st.erase(st.begin());

        for(auto adjv: g.adj[vertex]){
            
            if(distance[adjv.first] > dist+adjv.second){
                auto record= st.find({distance[adjv.first], adjv.first});

                if(record!=st.end()) st.erase(record);

                distance[adjv.first] = dist+adjv.second;
                st.insert({distance[adjv.first], adjv.first});

            }
        }
    }
}

int main(){
    graph g;
    int vc, ec, v,u,w;
    cin>>vc>>ec;
    for(int i=0;i<ec;i++){
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    vector<int>distance(vc,INT_MAX);
    cin>>v;
    dijkstra(g,distance,v);
    for(auto i: distance){
        if(i==INT_MAX) cout<<"/ ";
        else cout<<i<<" ";
    }
}