/**
  * We need to check if the given binary tree is a binary search tree or not.
  * We take a recursive function, we traverse the tree in inorder fashion.
  * We send the root, minimum node, maximum node.
  * We check at each point if the root->val is lesser than the minimum or root->val is greater than the maximum.
  * If yes then its not a BST.
  * Else we check on the left and right side.
  * Time Complexity: O(n).
  * Space Complexity: O(n).
  */
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

bool helper(TreeNode* root, TreeNode* mini, TreeNode* maxi) {
    if (!root)
        return true;
    else if (mini && root->val <= mini->val || maxi && maxi->val <= root->val)
        return false;
    else
        return helper(root->left, mini, root) && helper(root->right, root, maxi);
}
bool isValidBST(TreeNode* root) {
    return helper(root, NULL, NULL);
}