/**
  * To detect if a cycle is present in an undirected graph or not we can use bfs traversal.
  * We traverse the nodes of the graph and mark the ones that are travelled as visited.
  * We also keep a track of the previous node while traversing the graph.
  * Then if at some point while traversing the graph we come across an adjacent node that is visited
  * and that adjacent node is not the previous node, we can say that there is a cycle present.
  * The junction point is travelled twice from two different directions.
  * Hence we can say that a cycle is present in the graph.
  * Time and Space is the same as BFS.
  */

#include<bits/stdc++.h>
using namespace std;

bool cycle(int s, vector<int>& vis, vector<int> adj[]) {
    queue<pair<int, int>> q;
    q.push({ s, -1 });
    vis[s] = 1;
    while (!q.empty()) {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({ it, node });
            } else if (it != prev)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int>adj[]) {
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (cycle(i, vis, adj))
                return true;
        }
    }
    return false;
}