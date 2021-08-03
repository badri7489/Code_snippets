/**
  * If we want the topological ordering of the graph using BFS then we can use the kahn's algorithm.
  * Here we keep track of the in degree of all the nodes.
  * The nodes which have indegree 0 are kept in a queue.
  * Now we loop until the queue is empty.
  * We pop the first element and store it in the answer.
  * Now going through its adjacent nodes, we decrease the degrees of each node and
  * if any one of them has a degree 0 we put them in the queue.
  * When the queue is empty we get the topo sort in the answer array.
  * The intuition for this algorithm is that a node having 0 indegrees will have no node ahead of it.
  * So nobody else is pointing towards him so it should be on the top in the topo sorted array.
  * Then after taking a node we must decrease the indegrees of all the nodes which are being pointed by that node.
  * This means that all the nodes before that node are neglected and we check if that is the node with indegree as 0 or not.
  * If yes then it is included in the ans.
  * Time and space complexity is the same as BFS.
  */

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> deg(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i])
            deg[it]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (!deg[i])
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node]) {
            deg[it]--;
            if (!deg[it])
                q.push(it);

        }
    }
    return ans;
}
