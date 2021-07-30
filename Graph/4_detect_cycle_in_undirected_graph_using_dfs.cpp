/** Cycle in a graph can also be detected using DFS traversal.
  * We do the same, we keep track of the nodes that are visited,
  * and we also carry a parent node in each recursive call.
  * If the adjacent node is visited and it is not the same as the parent then we can say there is a cycle.
  * Time and space is the same as DFS.
  */

#include<bits/stdc++.h>
using namespace std;

bool cycle(int node, vector<int> vis, vector<int> adj[], int prev) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (cycle(it, vis, adj, node))	return true;
        } else if (it != prev)	return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (cycle(i, vis, adj, -1))	return true;
        }
    }
    return false;
}
