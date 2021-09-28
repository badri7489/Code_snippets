#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int dfs(vector<int> adj[], vector<int>& vis, vector<int>& low, vector<int>& tin, int node, int parent, int& timer) {
    vis[node] = 1;  // Marked visited
    tin[node] = low[node] = timer++;    // Low time and insertion time.
    for (int it : adj[node]) {
        // If node is parent then we don't visit it at all.
        if (it == parent)
            continue;
        // If the node is not visited we DFS traverse it.
        if (!vis[it]) {
            dfs(adj, vis, low, tin, it, node, timer);
            low[node] = min(low[node], low[it]);    // Updating the lowest time to visit the node.
            /** If lowest time to visit any of the adjacent node of "node" is greater than the time
              * of insertion of the "node" then we can say that there is no other path which connects
              * the adjacent node it to the "node".
              * Hence the edge between "node" and "it" is a bridge edge.
              */
            if (low[it] > tin[node])
                cout << "Bridge between: " << node + 1 << " " << it + 1 << endl;
        } else {    // If the node is already visited then we need to update the lowest time, if needed.
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main() {
    int n, u, v;
    fstream file;
    file.open("25_test_cases.txt");
    file >> n;
    vector<int> adj[n];
    // Taking edges input.
    while (file >> u >> v) {
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> vis(n, 0);
    vector<int> low(n, -1); // Lowest time to visit the node.
    vector<int> tin(n, -1); // Time of insertion of the node while DFS traversal.
    int timer = 0;  // Timer
    // DFS for disconnected components.
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(adj, vis, low, tin, i, -1, timer);
    }
    return 0;
}