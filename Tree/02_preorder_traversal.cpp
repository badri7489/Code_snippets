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
void preOrder(TreeNode* root, vector<int>& ans) {
    if (!root)
        return;
    ans.push_back(root->val);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}

// Iterative Code
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> ans;
    TreeNode* temp = root;
    while (temp || !stk.empty()) {
        while (temp) {
            ans.push_back(temp->val);
            stk.push(temp);
            temp = temp->left;
        }
        temp = stk.top();
        stk.pop();
        temp = temp->right;
    }
    return ans;
}