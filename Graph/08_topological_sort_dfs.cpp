/** Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices
  * such that for every directed edge u v, vertex u comes before v in the ordering.
  * It is not possible if the graph is not a DAG.
  * We modify the DFS algorithm by just passing a stack which will contain the nodes after the recursion has ended.
  * This means that when we reach a node with no adjacent nodes we store it in a stack and
  * then on its top the nodes which are having some adjacent nodes.
  * Then we empty the stack and print it in the order we take out the nodes.
  */

#include<bits/stdc++.h>
using namespace std;

void topo(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it])
            topo(it, adj, vis, ans);
    }
    ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans, vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            topo(i, adj, vis, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
