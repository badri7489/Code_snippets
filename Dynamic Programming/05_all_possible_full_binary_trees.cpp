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

// Recursive Approach
vector<TreeNode*> allPossibleFBT(int n) {
    if (n & 1 == 0)
        return {};
    if (n == 1)
        return { new TreeNode() };
    vector<TreeNode*> ans;
    for (int i = 1; i < n - 1; i += 2) {
        vector<TreeNode*> left = allPossibleFBT(i);             // having all the combinations in the left subtree.
        vector<TreeNode*> right = allPossibleFBT(n - i - 1);    // having all the combinations in the right subtree.
        // Iterating left and right and joining them to the root.
        for (TreeNode* l : left) {
            for (TreeNode* r : right) {
                TreeNode* root = new TreeNode(0, l, r);
                ans.push_back(root);    // Storing them in a vector.
            }
        }
    }
    return ans;
}

// Memoized Approach
unordered_map<int, vector<TreeNode*>> dp;
vector<TreeNode*> allPossibleFBT(int n) {
    if (n & 1 == 0)
        return {};
    if (n == 1)
        return { new TreeNode() };
    if (dp.find(n) != dp.end())
        return dp[n];
    vector<TreeNode*> ans;
    for (int i = 1; i < n - 1; i += 2) {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(n - i - 1);

        for (TreeNode* l : left) {
            for (TreeNode* r : right) {
                TreeNode* root = new TreeNode(0, l, r);
                ans.push_back(root);
            }
        }
    }
    dp[n] = ans;
    return dp[n];
}

// Matrix(Map) Approach
vector<TreeNode*> allPossibleFBT(int n) {
    if (n & 1 == 0)
        return {};
    unordered_map<int, vector<TreeNode*>> dp;
    dp[1] = { new TreeNode(0) };
    for (int i = 3; i <= n; i += 2) {
        for (int j = 1; j < i; j += 2) {
            vector<TreeNode*> left = dp[j];
            vector<TreeNode*> right = dp[i - j - 1];

            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(0, l, r);
                    dp[i].push_back(root);
                }
            }
        }
    }
    return dp[n];
}