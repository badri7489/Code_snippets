#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge {
    int u, v, w;
};

class Solution
{
private:
    static bool comp(edge a, edge b) {
        return a.w < b.w;
    }
    int findParent(vector<int>& parent, int node) {
        if (node == parent[node])
            return node;
        return findParent(parent, parent[node]);
    }
    void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);
        if (rank[uParent] < rank[vParent]) {
            parent[uParent] = vParent;
        } else if (rank[uParent] > rank[vParent]) {
            parent[vParent] = uParent;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        vector<edge> graph;
        // Linear ordering of all vertices.
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                graph.push_back({ i, it[0], it[1] });
            }
        }
        // Sorting the vertices according to the weight of all the edges, for greedy application of kruskal.
        sort(graph.begin(), graph.end(), comp);
        vector<int> parent(n);
        vector<int> rank(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
            parent[i] = i;
        // Going through all the edges and picking minimum, and if they are not of the same component 
        // then we join them else we find a cycle and we don't include it in the MST.
        for (auto it : graph) {
            int x = findParent(parent, it.u);
            int y = findParent(parent, it.v);
            if (x != y) {
                ans += it.w;
                unionSet(parent, rank, x, y);   // Joining two seperate components.
            }
        }
        return ans;
    }
};