/**
  * We just do Level order traversal and keep the take the first element of each level.
  * All the first element at each element is the Left View of the Binary Tree.
  * Time Complexity: O(n).
  * Space Complexity: O(n).
  */

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

// Using q.size() to check the level.
vector<int> leftView(TreeNode* root) {
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* p = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(p->val);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    return ans;
}

// Using NULL as a flag to change level.
vector<int> leftView(TreeNode* root) {
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->val);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp) {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        } else if (q.front() && !q.empty()) {
            q.push(NULL);
            ans.push_back(q.front()->val);
        }
        if (!temp && !q.front())
            break;
    }
    return ans;
}

// Recursive Method
void helper(TreeNode* root, int level, vector<int>& res) {
    if (!root)
        return;
    if (res.size() < level)
        res.push_back(root->val);
    helper(root->left, level + 1, res);
    helper(root->right, level + 1, res);
}
vector<int> leftView(TreeNode* root) {
    vector<int> res;
    helper(root, 1, res);
    return res;
}