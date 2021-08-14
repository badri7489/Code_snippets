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

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
    if (preStart > preorder.size() - 1 || inStart > inEnd)
        return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val)
            break;
    }
    root->left = helper(preorder, inorder, preStart + 1, inStart, i - 1);
    root->right = helper(preorder, inorder, preStart + i - inStart + 1, i + 1, inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder, inorder, 0, 0, inorder.size() - 1);
}