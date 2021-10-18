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
private:
    bool check(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2)
            return false;
        if (root1->val != root2->val)
            return false;
        return check(root1->left, root2->right) && check(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

// Iterative Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        TreeNode* left, * right;
        while (!stk.empty()) {
            left = stk.top();
            stk.pop();
            right = stk.top();
            stk.pop();
            if (!left && !right)
                continue;
            if (!left || !right || left->val != right->val)
                return false;
            stk.push(left->left);
            stk.push(right->right);
            stk.push(left->right);
            stk.push(right->left);
        }
        return true;
    }
};