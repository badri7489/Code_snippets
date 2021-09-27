#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
private:
    void dfs(int node, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it])
                dfs(it, st, vis, adj);
        }
        st.push(node);
    }
    void revDFS(int node, vector<int>& vis, vector<vector<int>>& transpose, vector<int>& temp) {
        temp.push_back(node);
        vis[node] = 1;
        for (int it : transpose[node]) {
            if (!vis[it])
                revDFS(it, vis, transpose, temp);
        }
    }
public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int n, vector<int> adj[]) {
        stack<int> st;
        vector<int>vis(n, 0);
        // Traversing the nodes in topo sort, using DFS.
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, st, vis, adj);
        }
        // Transposing the graph, means switching all the edges.
        vector<vector<int>> transpose(n);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (int j : adj[i])
                transpose[j].push_back(i);
        }
        // Again traversing the graph in DFS manner and storing each time the nodes in one dfs call.
        // Each time a dfs is called, it means, it is visiting all the stronly connected components at once.
        vector<vector<int>> ans;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> temp;
                revDFS(node, vis, transpose, temp);
                sort(temp.begin(), temp.end()); // Sorting is not required, only to pass the test cases for GFG.
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());   // Sorting is not required, only to pass the test cases for GFG.
        return ans;
    }
};
// 8 13
// 4 4
// 3 1
// 0 2
// 6 3
// 6 5
// 1 4
// 1 7
// 3 7
// 1 0
// 3 3
// 4 3
// 1 4
// 7 6