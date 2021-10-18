#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    queue<pair<TreeNode*, TreeNode*>> q;
    TreeNode* temp = new TreeNode(-1);
    q.push(make_pair(root, temp));
    pair<TreeNode*, TreeNode*> node;
    TreeNode* parentX = NULL, * parentY = NULL;
    int levelSize = 0;
    while (!q.empty()) {    // Doing a level order traversal.
        levelSize = q.size();
        while (levelSize--) {
            node = q.front();
            q.pop();
            if (node.first->val == x)   // If we find x, we store its parent.
                parentX = node.second;
            if (node.first->val == y)   // If we get y, we store its parent.
                parentY = node.second;
            if (node.first->left)   // Push left of the node.
                q.push(make_pair(node.first->left, node.first));
            if (node.first->right)  // Push right of the node.
                q.push(make_pair(node.first->right, node.first));
            if (parentX && parentY) // If we find both the parents, we immediately break.
                break;
        }
        if (parentX && parentY) // If we find both the parents at this level, we check if they are same or not.
            return parentX != parentY;
        if ((parentX && !parentY) || (!parentX && parentY)) // If we find only one of them, they are not cousins.
            return false;
    }
    return false;
}