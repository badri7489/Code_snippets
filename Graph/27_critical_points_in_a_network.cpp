#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

// Leetcode Question 1192 Hard Question
// Find the bridge in a graph.
// Using edge map, instead of a vector because it gave TLE.
class Solution {
private:
    vector<int> descovery_time;
    vector<int> low_descovery_time;
    vector<int> vis;
    unordered_map<int, vector<int>> edge_map;
    vector<vector<int>> ans;
    int timer = 0;
    void dfs(int node, int parent) {
        vis[node] = 1;
        descovery_time[node] = low_descovery_time[node] = timer++;
        for (int it : edge_map[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                dfs(it, node);
                low_descovery_time[node] = min(low_descovery_time[node], low_descovery_time[it]);
                if (low_descovery_time[it] > descovery_time[node])
                    ans.push_back({ node, it });
            } else {
                low_descovery_time[node] = min(descovery_time[it], low_descovery_time[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (vector<int> conn : connections) {
            edge_map[conn[0]].push_back(conn[1]);
            edge_map[conn[1]].push_back(conn[0]);
        }
        vis.resize(n, 0);
        descovery_time.resize(n, -1);
        low_descovery_time.resize(n, -1);
        dfs(0, -1);
        return ans;
    }
};