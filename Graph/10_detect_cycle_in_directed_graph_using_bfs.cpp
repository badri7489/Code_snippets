/**
  *
  */

#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> inDeg(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i])
            inDeg[it]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (!inDeg[i])
            q.push(i);
    }
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (auto it : adj[node]) {
            inDeg[it]--;
            if (!inDeg[it])
                q.push(it);
        }
    }
    return !(count == V);
}
