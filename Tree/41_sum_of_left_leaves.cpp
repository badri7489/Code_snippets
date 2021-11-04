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

// Iterative Code
class Solution {
private:
    int helper(TreeNode* root, bool isLeft) {
        if (!root)
            return 0;
        if (!root->left && !root->right && isLeft)
            return root->val;
        return helper(root->left, true) + helper(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};

// Recursive Code
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        stack<TreeNode*> stk;
        TreeNode* node;
        stk.push(root);
        int ans = 0;
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            if (node->left) {
                if (!node->left->left && !node->left->right)
                    ans += node->left->val;
                else
                    stk.push(node->left);
            }
            if (node->right) {
                if (node->right->left || node->right->right)
                    stk.push(node->right);
            }
        }
        return ans;
    }
};