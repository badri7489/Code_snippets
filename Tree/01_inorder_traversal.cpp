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
void inOrder(TreeNode* root, vector<int>& ans) {
    if (!root)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}

// Iterative Code
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* temp = root;
    vector<int> ans;
    while (temp || !stk.empty()) {
        while (temp) {
            stk.push(temp);
            temp = temp->left;
        }
        temp = stk.top();
        stk.pop();
        ans.push_back(temp->val);
        temp = temp->right;
    }
    return ans;
}