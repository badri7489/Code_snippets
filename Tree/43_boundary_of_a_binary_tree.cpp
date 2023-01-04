#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(TreeNode *root, vector<int>& ans) {
        while (root) {
            if (!isLeaf(root))
                ans.push_back(root->val);
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }
    }
    
    void addLeaves(TreeNode* root, vector<int>& ans) {
        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }
        if (root->left)
            addLeaves(root->left, ans);
        if (root->right)
            addLeaves(root->right, ans);
    }
    
    void addRightBoundary(TreeNode *root, vector<int>& ans) {
        stack<int> stk;
        while (root) {
            if (!isLeaf(root))
                stk.push(root->val);
            if (root->right)
                root = root->right;
            else
                root = root->left;
        }
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
    }
public:
    vector <int> boundary(TreeNode *root) {
        if (!root)
            return {};
        vector<int> ans;
        if (!isLeaf(root))
            ans.push_back(root->val);
        addLeftBoundary(root->left, ans);
        addLeaves(root, ans);
        addRightBoundary(root->right, ans);
        return ans;
    }
};