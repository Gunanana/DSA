#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
/*
-> first find the indegree of all the vertices 
-> then ini the queue with vertices having 0 indegree
-> while q not empty loop
    -> decrease the indegree for the vertices's adjacent vertices, if indegree is 0, then push into the q
*/

vector<int> topoKhan(vector<vector<int>> adj){
    int v=adj.size();
    vector<int> indeg(v,0);
    queue<int> q;
    vector<int>topo;

    for(int i=0;i<v;i++){
        for(auto neighbour: adj[i]){
            indeg[neighbour]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indeg[i]==0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int top=q.front();
        q.pop();
        topo.push_back(top);

        for(auto i: adj[top]){
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }
    return topo;
}

int main(){
    vector<vector<int>> adj= {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    vector<int> ans=topoKhan(adj);

    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}