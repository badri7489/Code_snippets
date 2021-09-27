#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#define number_of_nodes 9
using namespace std;

// Creating the adjacency list for the graph, adding both sided edges.
void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);    // u to v
    adjList[v].push_back(u);    // v to u
}

// Calculating the minimum distance from source to each node.
vector<int> shortest_path_to_all_nodes(vector<int> adj[], int n, int src) {
    vector<int> dist(n, INT32_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;  // Distance of source to itself is 0.
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int it : adj[node]) {
            // Checking if the distance is greater than the present or not
            // If yes then updating it to minumum and pushing the node to the queue.
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

int main() {
    fstream file;
    file.open("00_test_cases.txt");
    int u, v;
    vector<int> adjList[number_of_nodes];   // Adjacency List for storing graph.
    while (file >> u >> v) {    // Input of edge u to v from the test file.
        addEdge(adjList, u, v);
    }
    vector<int> ans = shortest_path_to_all_nodes(adjList, number_of_nodes, 0);
    // Printing the distances.
    for (int i = 0; i < number_of_nodes; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}