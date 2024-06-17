#include<bits/stdc++.h>
using namespace std;

/*
Strongly Connected Components
2 Algorithms : 1) Kosaraju's Algorithm
               2) Tarjan's Algorithm

-> Kosaraju's algo focuses more about the strongly connected components rather than the weak links connecting 2 different sccs
-> where as Tarjan's algo is focused about these very weak links

-> it also revolves around cycles in these scc

What happens in this algo ?
-> just 1 dfs traversal
-> have 2 extra attribute for each vertex, its discovery time and low link value
-> discovery time for each vertex is unique (since 2 cannot be discovered at the same time in dfs) and in increasing order (topo)
-> the low link value of a vertex is basically the discovery time of the first discovered vertex in its cycle (this low link value is same for all vertices in the same cycle or scc)
-> now comes the principle : 
    "if theres an edge who's 2 end vertices have different low link values / belong to different cycles / belong to different scc's, then this edge is the bridge or the critical edge. and upon removal of this edge, the graph will be broken into 2 components "

-> check the below implementation

ALGORITHM
1) take in adj, visited, dtime, low, time, v, parent
2) initialise visited, dtime, low for v
3) for its neighbouring vertices
    1) if neighbour is parent, then continue
    2) if neighbour is not visited
        1) call dfs function
        2) after fx call, take the low of neighbour
        3) check for bridge
    3) if visited, then take the low of neighbour

*/



void dfs(vector<list<int>> &adj,
        vector<bool> &visited,
        vector<int> &dtime,
        vector<int> &low,
        int v, int parent, int &time,
        vector<pair<int,int>> &bridges){

        visited[v]=true;
        dtime[v] = low[v] =time++; //record the discovery time for this neighbour

        for(auto neighbour: adj[v]){
            //dont let v take low from its parent
            if(neighbour == parent) continue;

            if(!visited[neighbour]){
                dfs(adj, visited, dtime, low, neighbour, v, time, bridges);

                //after dfs take the neighbour's low if its smoller
                low[v] = min(low[v], low[neighbour]);

                //after taking low, check if the edge between these both is a bridge or not
                if(low[neighbour] > dtime[v]) bridges.push_back({v, neighbour});
            }
            else{
                //if v is going to an already visited vertex, then these both are in cycle
                //hence set the low for v (the component representation)
                low[v] = min(low[v], low[neighbour]);
            }
        }
}


int main(){
    int n=10;
    vector<list<int>> adj(n);
    adj[0].push_back(1);  // 0 - 1
    adj[1].push_back(0);  // 1 - 0
    
    adj[1].push_back(2);  // 1 - 2
    adj[2].push_back(1);  // 2 - 1
    
    adj[2].push_back(0);  // 2 - 0
    adj[0].push_back(2);  // 0 - 2
    
    adj[1].push_back(3);  // 1 - 3
    adj[3].push_back(1);  // 3 - 1
    
    adj[3].push_back(4);  // 3 - 4
    adj[4].push_back(3);  // 4 - 3
    
    adj[4].push_back(5);  // 4 - 5
    adj[5].push_back(4);  // 5 - 4
    
    adj[5].push_back(3);  // 5 - 3
    adj[3].push_back(5);  // 3 - 5
    
    adj[4].push_back(6);  // 4 - 6
    adj[6].push_back(4);  // 6 - 4
    
    adj[6].push_back(7);  // 6 - 7
    adj[7].push_back(6);  // 7 - 6
    
    adj[7].push_back(8);  // 7 - 8
    adj[8].push_back(7);  // 8 - 7
    
    adj[8].push_back(6);  // 8 - 6
    adj[6].push_back(8);  // 6 - 8
    
    adj[6].push_back(9);  // 6 - 9
    adj[9].push_back(6);  // 9 - 6


    vector<bool> visited(n);
    vector<int> dtime(n,1); //discovery time
    vector<int> low(n,1); //low link for each vertex

    int time=1;
    int parent=-1;
    vector<pair<int,int>> bridges;
    dfs(adj, visited, dtime, low, 0, parent, time, bridges);

    for(auto p: bridges){
        cout<<p.first<<" <--> "<<p.second<<endl;
    }

}
