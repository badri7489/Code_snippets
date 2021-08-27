/**
  * To find the kth smallest in a Binary Search Tree, we can do inorder traversal and store all of the nodes in an array.
  * Then return the kth element from the array.
  * Time Complexity: O(n).
  * Space Complexity: O(n).
  * Better approach would be to do inorder traversal and decrease the value of k until it becomes 0.
  * Then we return the value of the node at which we are.
  * We can do this using recursion or iteration.
  * We first go to the left most node of the root.
  * Then we decrease the value of k for every root != NULL.
  * We also check if k == 0 or not, if yes then we return the value of the node and if we get a value in return instead of 0,
  * then we return it else we keep on moving forward.
  * Time Complexity: O(n).
  * Space Complexity: O(1).
  * Best one would be to modify the bst.
  * We can map each node with the number of nodes present on the left side of the tree.
  * Time Complexity: O(log(n)).
  */

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

void inOrder(TreeNode* root, vector<int>& ans) {
    if (root) {
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> ans;
    inOrder(root, ans);
    return ans[k - 1];
}

int helper(TreeNode* root, int& k) {
    if (!root)
        return 0;
    int left = helper(root->left, k);
    if (left)
        return left;
    k--;
    if (k == 0)
        return root->val;
    int right = helper(root->right, k);
    return right;
}
int kthSmallest(TreeNode* root, int k) {
    return helper(root, k);
}

