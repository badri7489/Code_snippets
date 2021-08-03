/**
  * Checking if a graph is bipartite or not can also be done using DFS traversal also.
  * We traverse the graph depth first, check if the adjacent nodes are colored or not.
  * If the node is not colored, we color it and recurse on that node.
  * If the node is colored, then we check if the parent node is having the same color or not,
  * if yes then we return false, else we continue.
  * When we have traversed all the nodes and all are colored correctly, then at the end we return a true,
  * stating that the graph is a bipartite graph.
  * Time and space is the same as DFS.
  */

#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int src, vector<int> adj[], vector<int>& color) {
    if (color[src] == -1)
        color[src] = 1;
    for (auto it : adj[src]) {
        if (color[it] == -1) {
            color[it] = 1 - color[src];
            if (!checkBipartite(it, adj, color))
                return false;
        } else if (color[it] == color[src])
            return false;
    }
    return true;
}
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!checkBipartite(i, adj, color))
                return false;
        }
    }
    return true;
}
