#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS algorithm works only for undirected graph with unit weights.
// When we have weighted graph then we need Dijkstra's algo.
vector<int> dijkstra(int v, vector<vector<int>> adj[], int src) {
    vector<int> dist(v, 1e9);
    // Priority queue stores the node with the lower distance at the top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src)); // Pushing the source with distance 0.
    dist[src] = 0;
    while (!pq.empty()) {
        int d = pq.top().first;     // The top of priority queue node's distance from the source.
        int node = pq.top().second; // The top node.
        pq.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i][0];
            int nextDist = adj[node][i][1];
            if (dist[node] + nextDist < dist[next]) {
                dist[next] = dist[node] + nextDist;     // Updating distance.
                pq.push(make_pair(dist[next], next));   // Pushing the updated distance to priority queue.
            }
        }
    }
    return dist;
}