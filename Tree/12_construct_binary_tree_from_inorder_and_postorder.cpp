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

// Without extra space.
TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& post, int inStart, int inEnd) {
    if (post < 0)
        return NULL;
    if (inStart > inEnd) {
        post++;
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[post]);
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (root->val == inorder[i])
            break;
    }
    root->right = helper(inorder, postorder, --post, i + 1, inEnd);
    root->left = helper(inorder, postorder, --post, inStart, i - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int i = postorder.size() - 1;
    return helper(inorder, postorder, i, 0, inorder.size() - 1);
}

// Using Extra Space.
unordered_map<int, int> mp;
TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& post, int inStart, int inEnd) {
    if (post < 0)
        return NULL;
    if (inStart > inEnd) {
        post++;
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[post]);
    int i = mp[root->val];
    root->right = helper(inorder, postorder, --post, i + 1, inEnd);
    root->left = helper(inorder, postorder, --post, inStart, i - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    int j = inorder.size() - 1;
    return helper(inorder, postorder, j, 0, inorder.size() - 1);
}