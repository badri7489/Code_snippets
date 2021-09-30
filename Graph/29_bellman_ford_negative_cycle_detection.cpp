#include<iostream>
#include<vector>
using namespace std;

// Bellman Ford
// Time Complexity: O(V * E)
// Worst Case Time complexity is for complete graph: O(V ^ 3).
// Bellman ford is useful for finding shortest path for a directed graph with negative edges.
// We can't find the shortest path when we find there is a negative cycle present in the given graph.
int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
    vector<int> dist(n, 1e9);   // Marking all distacnce of vertices as infinity.
    int u, v, wt;
    dist[0] = 0;    // Distance of source is 0.
    // Relaxing all the edges for n - 1 times.
    for (int i = 0; i < n - 1; i++) {
        for (vector<int>& it : edges) {
            u = it[0], v = it[1], wt = it[2];
            if (dist[u] + wt < dist[v]) // Relaxing all the vertices.
                dist[v] = dist[u] + wt;
        }
    }
    // If we can relax any one of the vertices one more time then we can say that the graph contains a negative cycle.
    for (vector<int>& it : edges) {
        u = it[0], v = it[1], wt = it[2];
        if (dist[u] + wt < dist[v])
            return 1;
    }
    return 0;
}