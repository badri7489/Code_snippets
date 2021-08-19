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

// Without Extra Space
// Time Complexity: O(n ^ 2).
TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& pre, int postStart, int postEnd) {
    if (postStart > postEnd)
        return NULL;
    TreeNode* root = new TreeNode(preorder[pre++]);
    if (postStart == postEnd)
        return root;
    int i;
    for (i = postEnd; i >= postStart; i--) {
        if (postorder[i] == preorder[pre])
            break;
    }
    root->left = helper(preorder, postorder, pre, postStart, i);
    root->right = helper(preorder, postorder, pre, i + 1, postEnd - 1);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int pre = 0;
    return helper(preorder, postorder, pre, 0, postorder.size() - 1);
}

// Using Extra Space.
// Time Complexity: O(n).
// Space Complexity: O(n).
unordered_map<int, int> mp;
TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& pre, int postStart, int postEnd) {
    if (postStart > postEnd)
        return NULL;
    TreeNode* root = new TreeNode(preorder[pre++]);
    if (postStart == postEnd)
        return root;
    int i = mp[preorder[pre]];
    root->left = helper(preorder, postorder, pre, postStart, i);
    root->right = helper(preorder, postorder, pre, i + 1, postEnd - 1);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int pre = 0;
    for (int i = 0; i < preorder.size(); i++)
        mp[preorder[i]] = i;
    return helper(preorder, postorder, pre, 0, postorder.size() - 1);
}