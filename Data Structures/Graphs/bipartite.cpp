#include<bits/stdc++.h>
using namespace std;

/*
Equivalent definitions of a bipartite graph:

1) There is no cycle of odd length

2) we can split the nodes of the graph(vertex set of the graph) into 2 subsets so that there is all the edges go from 1 subset to the other subset.

3.The graph should be bi-colourable.
*/


/*
-> below code is for finding every single cycle in the graph and then checking if we have any cycles with odd size
-> hence not bipartite
*/

/*
1) keep pushing all the vertices into the path and pop when the function ends
2) when a cycle is detected, its detected when a vertex v is going to neighbour n
3) find the neioghbour n and push every vertex from the neighbour till the vertex v ie the path.end() into a cycle and then push into allCyles
4) iterate through the all cycles and check if any cycle has odd length
*/

class Solution {
public:
    void isCyclicDFS(vector<vector<int>>& graph,
                     unordered_map<int, bool>& visited,
                     unordered_map<int, int>& parent,
                     vector<int>& path,
                     vector<vector<int>>& allCycles,
                     int v) {
        visited[v] = true;
        path.push_back(v);

        for (auto neighbour : graph[v]) {
            if (!visited[neighbour]) {
                parent[neighbour] = v;
                isCyclicDFS(graph, visited, parent, path, allCycles, neighbour);
            } 
            else if (neighbour != parent[v]) {
                // Cycle detected
                auto it = find(path.begin(), path.end(), neighbour);
                if (it != path.end()) {
                    vector<int> cycle(it, path.end());
                    allCycles.push_back(cycle);
                }
            }
        }

        path.pop_back();
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        vector<vector<int>> allCycles;
        vector<int> path;

        int n = graph.size();

        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                parent[v] = -1;
                isCyclicDFS(graph, visited, parent, path, allCycles, v);
            }
        }

        // Print the number of cycles found (for debugging)
        cout << allCycles.size() << endl;

        // Check if any of the found cycles are of odd length
        for (auto& vec : allCycles) {
            if (vec.size() % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
