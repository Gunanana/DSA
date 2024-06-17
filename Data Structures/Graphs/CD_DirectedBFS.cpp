#include<bits/stdc++.h>
using namespace std;

/*
-> using khan's toposorting technique
-> if the final topo sort vector doesnt have all the vertices, then that means there exists a cycle and hence return true

*/
class Solution {
public:
    bool topoSort(int numCourses,
    unordered_map<int,list<int>> adj,
    vector<int> &indegree,
    queue<int> &q){
        int counter=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            counter++;

            for(auto i: adj[top]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        return counter==numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses);
        //initialise indegree vector
        for(auto v: adj){
            for(auto i: adj[v.first]){
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) q.push(i);
        }
        return topoSort(numCourses, adj,indegree,q);

    }
};