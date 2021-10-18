#include<iostream>
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

// Recursive Solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

// Iterative Solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            if (curr) {
                stk.push(curr->left);
                stk.push(curr->right);
                swap(curr->left, curr->right);
            }
        }
        return root;
    }
};