#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
private:
    void createGraph(vector<vector<int>>& graph, vector<int> adj[], vector<int>& inDeg) {
        for (int i = 0; i < graph.size(); i++) {
            adj[graph[i][1]].push_back(graph[i][0]);
            inDeg[graph[i][0]]++;
        }
    }
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<int> adj[n];
        vector<int> inDeg(n, 0);
        createGraph(graph, adj, inDeg);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i : adj[node]) {
                inDeg[i]--;
                if (inDeg[i] == 0)
                    q.push(i);
            }
        }
        return ans.size() == n;
    }
};