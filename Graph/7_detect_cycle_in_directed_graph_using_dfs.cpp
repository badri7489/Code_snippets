/** Detecting a cycle in an undirected graph is easy, but when we have a directed graph,
  * then we need to modify the algorithm.
  * We need to check if the cycle is made by traversing in only one direction and not from two sides.
  * Because all the edges here are directed.
  * Hence when we apply DFS here, we keep track of the path we are travelling.
  * We take a visited array and also a dfs_array, which marks the one which we have visited while traversing.
  * When we backtrack after getting a false then we unmark in the dfs_array.
  * This means that we travelled in that direction and didn’t find a cycle.
  * Hence we unmark them in the dfs_array.
  * We find a cycle when an adjacent node of a particular node is visited and it is also in the dfs_array, then we return true.
  * Time and space is the same as DFS.
  */

#include<bits/stdc++.h>
using namespace std;

bool cycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfs_vis) {
    vis[node] = 1;
    dfs_vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (cycle(it, adj, vis, dfs_vis))
                return true;
        } else if (dfs_vis[it])
            return true;
    }
    dfs_vis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfs_vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (cycle(i, adj, vis, dfs_vis))
                return true;
        }
    }
    return false;
}
