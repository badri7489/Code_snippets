#include<iostream>
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
    int count = 0;  // Total number of paths.
    void helper(TreeNode* root, int tar) {
        if (!root)  // If root is null do nothing.
            return;
        if (tar == root->val)   // If at any node, we achieve a target, we increase count.
            count++;
        helper(root->left, tar - root->val);    // Go left.
        helper(root->right, tar - root->val);   // Go right.
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)  // If root is null return 0.
            return 0;
        helper(root, targetSum);    // We include the root value.
        pathSum(root->left, targetSum); // We exclude root value and try to find on the left.
        pathSum(root->right, targetSum);// We exclude root value and try to find on the right.
        return count;
    }
};