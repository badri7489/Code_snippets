#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int spanningTree(int n, vector<vector<int>> adj[]) {
    vector<int> mst(n, 0);  // Storing if the node is visited or not.
    vector<int> parent(n);  // Storing the parent node.
    vector<int> key(n, INT32_MAX);  // Storing the minimum weights.
    parent[0] = -1; // Parent of 0 is -1
    key[0] = 0; // Weight of 0 is 0
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int mini = INT32_MAX, u;
        // Finding the minimum key.
        for (int j = 0; j < n; j++) {
            if (!mst[j] && key[j] < mini)
                mini = key[j], u = j;
        }
        mst[u] = 1; // Marking the minimum as visited.
        // Travelling the adjacent of u and upadating the key by checking from each path.
        for (vector<int> it : adj[u]) {
            int v = it[0];
            int w = it[1];
            if (!mst[v] && w < key[v])
                parent[v] = u, key[v] = w;
        }
    }
    for (int i = 0; i < n; i++)
        ans += key[i];
    return ans;
}

int spanningTree(int v, vector<vector<int>> adj[]) {
    // The minimum elemnt getting done in log(n) time.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> mst(v, 0);
    vector<int> key(v, INT32_MAX);
    vector<int> parent(v);
    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = 1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j][0];
            int w = adj[u][j][1];
            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({ key[v], v });
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < v; i++)
        ans += key[i];
    return ans;
}

int spanningTree(int v, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> mst(v, 0);
    pq.push({ 0, 0 });
    int ans = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (mst[u])
            continue;
        mst[u] = 1;
        ans += w;
        for (vector<int> v : adj[u]) {
            if (!mst[v[0]])
                pq.push({ v[1], v[0] });
        }
    }
    return ans;
}