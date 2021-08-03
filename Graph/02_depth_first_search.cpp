/**
  * In DFS traversal nodes are visited at first into the depth from a source node.
  * First a source node is taken and then that node is visited,
  * then node at the next level is visited and this is recursively taken place until there are no adjacent nodes.
  * Also a visited array is taken which checks if a node is visited or not.
  * Time complexity is O(V + E). V - Number of vertices, E - Number of edges. Space is O(V) + O(V).
  */

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& ans) {
    ans.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it])	dfs(it, vis, adj, ans);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> vis(V, 0);
    dfs(0, vis, adj, ans);
    return ans;
}
