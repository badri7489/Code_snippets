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
    while (!q.empty()) {
        levelSize = q.size();
        while (levelSize--) {
            node = q.front();
            q.pop();
            if (node.first->val == x)
                parentX = node.second;
            if (node.first->val == y)
                parentY = node.second;
            if (node.first->left)
                q.push(make_pair(node.first->left, node.first));
            if (node.first->right)
                q.push(make_pair(node.first->right, node.first));
            if (parentX && parentY)
                break;
        }
        if (parentX && parentY)
            return parentX != parentY;
        if ((parentX && !parentY) || (!parentX && parentY))
            return false;
    }
    return false;
}