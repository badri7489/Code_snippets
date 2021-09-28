#include<iostream>
#include<vector>
using namespace std;

// It is a data structure to store the connected components of a graph.
// It's time complexity is constant.

// Find the parent of a node.
int findParent(vector<int>& parent, int node) {
    if (node == parent[node])   // If a node is its own parent.
        return node;
    // If not then we recursively try to find the parent.
    // Path Compression is that we update the parent of each node as we are traversing towards the parent.
    // 7 -> 6 -> 4 -> 3 -> 1
    // From 7 we travel recursively upwards and update parent of 7, 6, 4, 3 all as 1.
    // This is path compression, which helps us save time for the next calls.
    return parent[node] = findParent(parent, parent[node]);
}

// Unifying two sets.
void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    int uParent = findParent(parent, u);    // Parent of u
    int vParent = findParent(parent, v);    // Parent of v
    if (rank[uParent] < rank[vParent]) {    // If v's parent is of higher rank we join u to v.
        parent[uParent] = vParent;
    } else if (rank[uParent] > rank[vParent]) { // If u's parent is of higher rank we join v to u.
        parent[vParent] = uParent;
    } else {    // If both are of same rank then we join any one of our choice and increase the rank of that one.
        parent[vParent] = uParent;
        rank[uParent]++;
    }
}

int main() {
    vector<int> parent(7);
    vector<int> rank(7, 0);
    for (int i = 1; i <= 7; i++) {
        parent[i] = i;
    }
    cout << "Parent of 1: " << findParent(parent, 1) << endl;
    unionSet(parent, rank, 1, 2);
    unionSet(parent, rank, 2, 3);
    cout << "Parent of 2: " << findParent(parent, 2) << endl;
    unionSet(parent, rank, 4, 5);
    unionSet(parent, rank, 6, 7);
    cout << "Parent of 6: " << findParent(parent, 6) << endl;
    unionSet(parent, rank, 5, 6);
    unionSet(parent, rank, 3, 7);
    cout << "Parent of 7: " << findParent(parent, 7) << endl;
    cout << "Parent of 1: " << findParent(parent, 1) << endl;
}