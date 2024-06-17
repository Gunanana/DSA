#include<bits/stdc++.h>
using namespace std;

/*
Strongly Connected Components
2 Algorithms : Kosaraju and Tarjan
-> this is for an undirected graph
-> all vertices in an scc must reach each other (hence these vertices are in a cycle) 
-> this is used for pathfinding, reachability, critical connections and for dependency analysis

STEPS:
-> 1) first find the topological order
-> 2) reverse the graph
-> 3) apply dfs

-> now is this working? 
    -> when u reverse the graph, the only components for whom the connectivity doesnt change are for the scc's, since they involve cycles and they can still reach eachother (a cycle reversed is still a cycle)
    -> the reason for reversing the graph is that now when we apply dfs for vertices in the topological order, the first scc cannot travel to the adjacent ones anymore, neither can any scc travel to their topological successors present in different scc.
    -> the connection btw the ssc's are broken and hence discoverable
*/

//toposort function using dfs
void topoSort(vector<list<int>> &adj, vector<bool> &visited, int v, stack<int> &topo){
    visited[v]=true;
    for(auto neighbour: adj[v]){
        if(!visited[neighbour]) topoSort(adj,visited, neighbour,topo);
    }
    topo.push(v);
}

//dfs function to find the components
void dfs(vector<list<int>> &adj, vector<bool> &visited, int v, vector<int> &comp, vector<vector<int>> &allcomp){
    visited[v]= true;
    comp.push_back(v);
    for(auto neighbour: adj[v]){
        if(!visited[neighbour] ) dfs(adj, visited, neighbour, comp, allcomp);
    }
}

int main(){
    int n=8;
    vector<list<int>> adj(n);
    adj[0].push_back(1);  // 0 -> 1
    adj[1].push_back(2);  // 1 -> 2
    adj[2].push_back(0);  // 2 -> 0
    adj[1].push_back(3);  // 1 -> 3
    adj[3].push_back(4);  // 3 -> 4
    adj[4].push_back(5);  // 4 -> 5
    adj[5].push_back(3);  // 5 -> 3
    adj[5].push_back(6);  // 5 -> 6
    adj[6].push_back(7);  // 6 -> 7
    adj[7].push_back(6);  // 7 -> 6

    stack<int> topo;
    vector<bool> visited(n);
    topoSort(adj, visited, 0, topo);

    //reverse the graph
    vector<list<int>> radj(n);
    for(int i=0; i<n; ++i){
        visited[i]=false; //unvisit every vertex
        for(auto neighbour: adj[i]){
            radj[neighbour].push_back(i);
        }
    }

    //call dfs again
    vector<vector<int>> allcomp;
    vector<int> comp;

    int scc=0;
    while(!topo.empty()){
        int i= topo.top();
        topo.pop();

        if(!visited[i]){
            vector<int> comp;
            dfs(radj, visited, i, comp, allcomp);
            allcomp.push_back(comp);
            scc++;
        }
    }

    for(auto component: allcomp){
        for(int v: component) cout<<v<<" ";
        cout<<endl;
    }

    return 0;
}