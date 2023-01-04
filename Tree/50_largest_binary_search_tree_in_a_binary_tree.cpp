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

class NodesValue {
public:
    int size, minValue, maxValue;
    NodesValue(int size, int minValue, int maxValue) : size(size), minValue(minValue), maxValue(maxValue) {}
};

class Solution{
private:
    NodesValue helper(TreeNode* root) {
        if (!root)
            return NodesValue(0, INT_MAX, INT_MIN);
        
        NodesValue left = helper(root->left);
        NodesValue right = helper(root->right);
        
        if (left.maxValue < root->val && root->val < right.minValue) {
            return NodesValue(left.size + right.size + 1, min(left.minValue, root->val), max(right.maxValue, root->val));
        }
        return NodesValue(max(left.size, right.size), INT_MIN, INT_MAX);
    }
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(TreeNode *root) {
        return helper(root).size;
    }
};