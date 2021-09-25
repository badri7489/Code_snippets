#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1)
        return { 0 };
    vector<vector<int>> adj(n);
    vector<int> inDeg(n);
    queue<int> q;
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][1]].push_back(edges[i][0]);    // Undirected Tree
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    for (int i = 0; i < n; i++) {
        inDeg[i] = adj[i].size();   // Indegree of each vertex.
        // Only taking those which have only one in degree.
        if (inDeg[i] == 1)
            q.push(i);
    }
    int node, l;
    // Maximum of 2 vertices are there which when taken as root will have the minimum height of the tree.
    // We remove all the leaves(edge with indegree 1), because if we consider them as root then height won't be minimum.
    // After removal we are left with some other vertices which are leaves, we iteratively remove them also.
    // Until we are left with only 2 or 1 vertices.
    // Basically, the idea is to eat up all the leaves at the same time, until one / two leaves are left.
    // Any node that has already been a leaf cannot be the root of a MHT, 
    // because its adjacent non - leaf node will always be a better candidate.
    while (n > 2) {
        l = q.size();
        n -= l;
        for (int i = 0; i < l; i++) {
            node = q.front();
            q.pop();
            for (int i : adj[node]) {
                if (--inDeg[i] == 1)
                    q.push(i);
            }
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}