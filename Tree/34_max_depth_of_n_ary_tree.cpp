#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Recursive Solution
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int maxi = 0;
        for (Node* it : root->children)
            maxi = max(maxi, maxDepth(it));
        return maxi + 1;
    }
};

// Iterative Solution
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int breadth = q.size();
            for (int i = 0; i < breadth; i++) {
                Node* temp = q.front();
                q.pop();
                for (Node* it : temp->children) {
                    if (it)
                        q.push(it);
                }
            }
        }
        return depth;
    }
};