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

int minDepth(TreeNode* root) {
    if (!root)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (left == 0 || right == 0)    // Skewed Tree.
        return 1 + max(left, right);
    return min(left, right) + 1;
}