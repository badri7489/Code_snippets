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

void helper(TreeNode* root, string s, vector<string>& ans) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        s += to_string(root->val);
        ans.push_back(s);
        return;
    }
    s += to_string(root->val) + "->";
    helper(root->left, s, ans);
    helper(root->right, s, ans);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    helper(root, "", ans);
    return ans;
}