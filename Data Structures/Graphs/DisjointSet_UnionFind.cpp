#include<bits/stdc++.h>
using namespace std;

/*
    "Disjoint Set or Union-Find is a data structure which is associated with the 'connectivity' of vertices..."

-> so basically, at first each vertex is in a set of its own
-> if it has an edge with another vertex, then these 2 vertices are put into the same set
-> 2 vertices are in the same set if they are in the same component
-> there are 2 functions for this ds

    -> Union: if suppose a new edge was found which connects 2 diff disjoin set, then we need to join these 2 sets
        -> Union by Rank
        -> Union by Size
    -> Find: this fx finds the parent or the representative of any set. if 2 vertices have the same parent, then that means that they belong to the same set and are connected.
*/

class disjointSet{
    vector<int> parent, size, rank;

public:
    disjointSet(int n){
        //n+1 for 1-based indexing
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        //at beginning each vertex is a disjoint set and hence its own representative
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int find(int node){
        if( parent[node] == node ) return node;
        return parent[node]= find(parent[node]); // path compression for all the nodes this function traversed through
    }

    void Union(int u, int v){
        //find the reps or their parents
        int pu= find(u);
        int pv= find(v);

        //if same parent, then they belong to the same set, hence no union
        if(pu==pv) return;

        //determine the size of the parent, join the smaller set into the bigger one
        if(size[pv] > size[pu]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else if(size[pu] > size[pv]){
            parent[pv]= pu;
            size[pu]+=size[pv];
        }
        else{
            //if same, then any order doesnt matter
            parent[pv]=pu;
            size[pu]+=pv;
        }
    }
};
