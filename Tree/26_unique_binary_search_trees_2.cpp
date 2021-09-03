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

vector<TreeNode*> helper(int start, int end) {
    vector<TreeNode*> ans;
    if (start > end) {
        ans.push_back(NULL);
        return ans;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> left = helper(start, i - 1);  // Get the left side of the tree in form of a vector, recursively.
        vector<TreeNode*> right = helper(i + 1, end);   // Get the right side of the tree in form of a vector, recursively.
        for (TreeNode* l : left) {
            for (TreeNode* r : right) {
                TreeNode* root = new TreeNode(i, l, r); // Takiing ith as root and joining the left and right side.
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);
}