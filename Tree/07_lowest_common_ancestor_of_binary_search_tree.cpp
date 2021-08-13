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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ((root->val > p->val) && (root->val > q->val))
        return lowestCommonAncestor(root->left, p, q);
    if ((root->val < p->val) && (root->val < q->val))
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while (true) {
        if (p->val < curr->val && q->val < curr->val)
            curr = curr->left;
        else if (p->val > curr->val && q->val > curr->val)
            curr = curr->right;
        else
            break;
    }
    return curr;
}