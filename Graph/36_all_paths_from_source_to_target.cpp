#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> vis;
    void helper(vector<vector<int>>& adj, int node) {
        if (node == adj.size() - 1) {
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        vis[node] = 1;
        temp.push_back(node);
        for (int it : adj[node]) {
            if (!vis[it])
                helper(adj, it);
        }
        vis[node] = 0;
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n, 0);
        helper(graph, 0);
        return ans;
    }
};