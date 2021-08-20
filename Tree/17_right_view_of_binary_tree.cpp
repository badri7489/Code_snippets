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

// Using Extra Space and checking for next level using q.size().
// Time complexity: O(n).
// Space complexity: O(n).
vector<int> rightSideView(TreeNode* root) {
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if (i == n - 1)
                ans.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

// Recursive Method.
void helper(TreeNode* root, int level, vector<int>& ans) {
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->val);
    helper(root->right, level + 1, ans);
    helper(root->left, level + 1, ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    helper(root, 0, ans);
    return ans;
}