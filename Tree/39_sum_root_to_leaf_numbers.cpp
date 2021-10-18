#include<iostream>
#include<string>
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
    string s = "";
    int ans = 0;
    void helper(TreeNode* root) {
        if (!root)
            return;
        s += to_string(root->val);
        if (!root->left && !root->right) {  // When we reach a leaf, we add the answer.
            ans += stoi(s);
            s.pop_back();
            return;
        }
        helper(root->left); // Go left.
        helper(root->right);// Go right.
        s.pop_back();   // Backtracking my steps.
    }
public:
    int sumNumbers(TreeNode* root) {
        helper(root);
        return ans;
    }
};