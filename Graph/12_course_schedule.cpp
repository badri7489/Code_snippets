#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
private:
    void createGraph(vector<vector<int>>& arr, vector<int> adj[]) {
        for (int i = 0; i < arr.size(); i++)
            adj[arr[i][0]].push_back(arr[i][1]);
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        createGraph(prerequisites, adj);
        queue<int> q;
        vector<int> inDeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j : adj[i])
                inDeg[j]++;
        }
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
                if (!inDeg[i])
                    q.push(i);
            }
        }
        return ans.size() == n;
    }
};