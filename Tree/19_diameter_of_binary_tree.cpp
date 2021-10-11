/**
  * So although the longest path doesn't have to go through the root node,
  * it has to pass the root node of some subtree of the tree (because it has to be from one leaf node to another leaf node,
  * otherwise we can extend it for free).
  * The longest path that passes a given node as the ROOT node is
  * T = left_height + right_height.
  * So you just calculate T for all nodes and output the max T.
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

int helper(TreeNode* root, int& diameter) {
    if (!root)
        return 0;
    int l = helper(root->left, diameter);
    int r = helper(root->right, diameter);
    diameter = max(diameter, l + r);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    helper(root, diameter);
    return diameter;
}