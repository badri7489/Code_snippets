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

// Recursive Code
void postOrder(TreeNode* root, vector<int>& ans) {
    if (!root)
        return;
    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postOrder(root, ans);
    return ans;
}

// Iterative Code
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode* temp = root;
    while (temp || !stk.empty()) {
        if (temp) {
            stk.push(temp);
            temp = temp->left;
        } else {
            TreeNode* node = stk.top()->right;
            if (node) {
                temp = node;
            } else {
                node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                while (!stk.empty() && node == stk.top()->right) {
                    node = stk.top();
                    stk.pop();
                    ans.push_back(node->val);
                }
            }
        }
    }
    return ans;
}

// Iterative Code, reversing modified preorder traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* temp;
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            ans.push_back(temp->val);
            if (temp->left)
                stk.push(temp->left);
            if (temp->right)
                stk.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};