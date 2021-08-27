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

void inorder(TreeNode* root, vector<int>& ans) {
    if (root) {
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
}
bool findTarget(TreeNode* root, int k) {
    vector<int> ans;
    inorder(root, ans);
    int l = 0, r = ans.size() - 1;
    while (l < r) {
        if (ans[l] + ans[r] == k)
            return true;
        else if (ans[l] + ans[r] > k)
            r--;
        else
            l++;
    }
    return false;
}

set<int> s;
bool findTarget(TreeNode* root, int k) {
    if (!root)
        return false;
    if (s.find(k - root->val) != s.end())
        return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
}