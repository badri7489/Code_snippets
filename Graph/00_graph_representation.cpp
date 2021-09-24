#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void bfs(vector<int> adjList[], int n) {
    queue<int> q;
    vector<int> vis(n, 0);
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int it : adjList[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

void dfsHelper(int node, vector<int> adjList[], vector<int>& vis, int n) {
    cout << node << " ";
    vis[node] = 1;
    for (int it : adjList[node]) {
        if (!vis[it])
            dfsHelper(it, adjList, vis, n);
    }
}

void dfs(vector<int> adjList[], int n) {
    vector<int> vis(n, 0);
    dfsHelper(0, adjList, vis, n);
}

int main() {
    fstream file;
    file.open("00_test_cases.txt");
    int u, v;
    vector<int> adjList[5];
    while (file >> u >> v) {
        addEdge(adjList, u, v);
    }
    cout << "BFS: ";
    bfs(adjList, 5);
    cout << "\nDFS: ";
    dfs(adjList, 5);
    return 0;
}