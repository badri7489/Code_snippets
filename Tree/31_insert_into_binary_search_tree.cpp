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

// Recursive Solution.
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return root = new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

// Iterative Solution.
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->val < val) {
                if (curr->right)
                    curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->left)
                    curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root ? root : new TreeNode(val);
    }
};