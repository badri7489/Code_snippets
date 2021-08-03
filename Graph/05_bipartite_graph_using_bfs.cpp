/**
  * A bipartite graph is a graph that can be coloured using only two colors,
  * its adjacent nodes are supposed to be coloured with different colors.
  * This coloring of a bipartite graph can be done using BFS traversal.
  * Everything is the same as BFS, the only thing that changes is we use a color array instead of the visited array.
  * We keep track of all the nodes that are colored.
  * If there is any adjacent node which is not colored,
  * we color it else we check if that adjacent node has the same color as its parent node then we return a false.
  * After traversing the whole graph, if we find that no false is returned then we return a true.
  * Which means that the graph can be colored using only 2 colors.
  * Hence it is a bipartite graph.
  */

#include<bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], vector<int>& color) {
    queue<int>q;
    q.push(src);
    color[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if (color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> color(n, -1);
    for (int i = 0;i < n;i++) {
        if (color[i] == -1) {
            if (!bipartiteBfs(i, adj, color))
                return false;
        }
    }
    return true;
}
