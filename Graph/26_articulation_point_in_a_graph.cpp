#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// Similar to the bridge in a graph code.
void dfs(vector<int> adj[], vector<int>& vis, vector<int>& low_descovery_time, vector<int>& descovery_time, vector<int>& is_articulation, int node, int parent, int& timer) {
    vis[node] = 1;
    low_descovery_time[node] = descovery_time[node] = timer++;
    int child = 0;  // To have the number of child of each node.
    for (int it : adj[node]) {
        if (it == parent)
            continue;
        if (!vis[it]) {
            dfs(adj, vis, low_descovery_time, descovery_time, is_articulation, it, node, timer);
            low_descovery_time[node] = min(low_descovery_time[node], low_descovery_time[it]);
            if (low_descovery_time[it] >= descovery_time[node] && parent != -1)
                is_articulation[node] = 1;
            child++;
        } else {
            low_descovery_time[node] = min(low_descovery_time[node], descovery_time[it]);
        }
    }
    // If parent is not there and there is more than one child of that node,
    // then on removing that node, we will seperate the child nodes.
    // Hence it is also an articulation point.
    if (parent == -1 && child > 1)
        is_articulation[node] = 1;
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
    vector<int> low_descovery_time(n, -1);  // Lowest time to visit the node.
    vector<int> descovery_time(n, -1);  // Time of insertion of the node while DFS traversal.
    vector<int> is_articulation(n, 0);  // Articulation points in the graph.
    int timer = 0;  // Timer
    // DFS for disconnected components.
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(adj, vis, low_descovery_time, descovery_time, is_articulation, i, -1, timer);
    }
    for (int i = 0; i < n; i++) {
        if (is_articulation[i])
            cout << i + 1 << endl;
    }
    return 0;
}