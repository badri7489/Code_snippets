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

void helper(TreeNode* root, string& s) {
    if (!root)
        return;
    s += to_string(root->val);
    if (root->left) {
        s += '(';
        helper(root->left, s);
        s += ')';
    } else if (root->right) {
        s += "()";
    }
    if (root->right) {
        s += '(';
        helper(root->right, s);
        s += ')';
    }
}
string tree2str(TreeNode* root) {
    string s = "";
    helper(root, s);
    return s;
}

// Concise Code
string tree2str(TreeNode* root) {
    if (!root)
        return "";
    string s = to_string(root->val);
    if (root->left)
        s += "(" + tree2str(root->left) + ")";
    else if (root->right)
        s += "()";
    if (root->right)
        s += "(" + tree2str(root->right) + ")";
    return s;
}