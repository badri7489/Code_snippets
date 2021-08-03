/**
  * In BFS we traverse all child nodes of a nodeand then we move forward.
  * We keep in track of the other nodes when visiting the child nodes using a queue.
  * The edges of the graph are stored in the form of adjacency list, vector of arrays in cpp.
  * A vector of visited nodes is maintained where all the nodes that have been visited are marked.
  * This is to keep in check that the traversal doesn’t move in a cycle for infinity.
  * The first node is stored in the queueand then a while loop is started till the queue is empty.
  * Then the first node is taken out from the queueand all its children are traversedand put in the queue
  * and they are also marked a visited.
  * This process goes on till all the nodes of the graph are visited.
  * If the graph is not connected, then all the other components of the graph must also be visited.
  * It can be done using a simple for loopand checking if the nodes are visited or not.
  * If nodes are not visited then we will call bfs for those nodes also.
  * Hence all the connected components are visitedand traversed.Time complexity will be O(N + 2 * E).
  * N - Number of nodes, E - Number of edges.
  * Space complexity will be O(N + E) + O(N) + O(N).
  */

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    queue<int> q;
    vector<int> bfs;
    vector<int> vis(v, 0);
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
