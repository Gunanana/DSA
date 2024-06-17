#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent, size;
public:
    int totalweight;
    disjointSet(int n){
        totalweight=0;
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u]=find(parent[u]);
    }

    void Union(int u, int v, int wt){
        int pou= find(u);
        int pov= find(v);
        if(pou==pov) return;
        if(size[pou] > size[pov]){
            parent[pov]= pou;
            size[pou]+=size[pov];
        }
        else{
            parent[pou]=pou;
            size[pov]+=size[pou];
        }
        totalweight+=wt;
    }
};

int main(){
    int n,e;
    cout<<"Enter number of edges & vertices: "; cin>>e>>n;
    //{weight, src, dest}
    vector<vector<int>> edges(e, vector<int> (3));
    disjointSet mst(n);

    //first sort the vector wrt edges in ascending order
    sort(edges.begin(), edges.end(), [](const auto &it1, const auto &it2){
        return it1[0]<it2[0];
    });
    for(int i=0; i<e; i++){
        int weight= edges[i][0];
        int u= edges[i][1];
        int v= edges[i][2];
        mst.Union(u,v, weight);
    }
    cout<<"The MST's min weight is: "<<mst.totalweight<<endl;

}