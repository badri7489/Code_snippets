#include<iostream>
#include<vector>
using namespace std;

// Leetcode problem no 547
// Number of Provinces
// Number of strongly connected components.
class Solution {
private:
    vector<int> vis;
    void dfs(vector<vector<int>>& adj, int node) {
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            if (adj[node][i] && !vis[i])
                dfs(adj, i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vis.resize(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i);
                count++;
            }
        }
        return count;
    }
};