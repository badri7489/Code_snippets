#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void createGraph(vector<vector<int>>& graph, vector<int> adj[], vector<int>& inDeg) {
        for (int i = 0; i < graph.size(); i++) {
            adj[graph[i][1]].push_back(graph[i][0]);    // Creating Adjacency List.
            inDeg[graph[i][0]]++;   // Calculating In Degree.
        }
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> adj[n];
        vector<int> inDeg(n, 0);
        createGraph(graph, adj, inDeg);
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0)
                ans.push_back(i);   // Pushing those with indegree 0 into vector.
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j : adj[ans[i]]) {
                inDeg[j]--; // Decreasing indegree of all the vertices which are being visited.
                if (inDeg[j] == 0)  // Pushing when a node is of indegree 0.
                    ans.push_back(j);
            }
        }
        return (ans.size() == n) ? ans : vector<int>();
    }
};