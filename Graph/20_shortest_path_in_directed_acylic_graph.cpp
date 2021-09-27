#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#define number_of_nodes 6
using namespace std;

// Toposort using DFS Traversal
void toposort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& ans) {
    vis[node] = 1;
    for (pair<int, int> it : adj[node]) {
        if (!vis[it.first])
            toposort(it.first, adj, vis, ans);
    }
    ans.push(node);
}

vector<int> shortest_path_to_all_nodes(vector<pair<int, int>> adj[], int n, int src) {
    vector<int> vis(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            toposort(i, adj, vis, stk);
    }
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    // Emptying the stack one by one and calculating the distance of its adjacent vertices.
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        for (pair<int, int> it : adj[node]) {
            // Checking the weights accordingly and filling the distance array with the minimum distance.
            if (dist[node] + it.second < dist[it.first])
                dist[it.first] = dist[node] + it.second;
        }
    }
    return dist;
}

int main() {
    fstream file;
    file.open("20_test_cases.txt");
    int u, v, w;
    vector<pair<int, int>> adjList[number_of_nodes];   // Adjacency List for storing graph.
    while (file >> u >> v >> w) {    // Input of edge u to v from the test file.
        adjList[u].push_back(make_pair(v, w));
    }
    vector<int> ans = shortest_path_to_all_nodes(adjList, number_of_nodes, 0);
    // Printing the distances.
    for (int i = 0; i < number_of_nodes; i++)
        ans[i] == 1e9 ? cout << "INF" : cout << ans[i] << " ";
    cout << endl;
    return 0;
}