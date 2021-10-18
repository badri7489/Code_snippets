#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<int>> ans;
    void helper(TreeNode* root, int tar, vector<int> temp) {
        if (!root)  // Do nothing when root is null.
            return;
        temp.push_back(root->val);  // Including the value of the root.
        if (!root->left && !root->right && tar == root->val) {  // If the node is leaf and target is achieved we push it in ans.
            ans.push_back(temp);
            return;
        }
        helper(root->left, tar - root->val, temp);  // Recurse on the left
        helper(root->right, tar - root->val, temp); // Recurse on the right
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root, targetSum, temp);
        return ans;
    }
};