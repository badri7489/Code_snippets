/**
  * We have to construct BST using Preorder Traversal.
  * First approach.
  * We copy the preorder vector to another and sort it.
  * Now this new vector is the inorder traversal of the Tree.
  * By using the inorder and preorder traversal we can create the BST.\
  * Time Complexity: O(n ^ 2).
  * Space Complexity: O(n) -> auxiliary space.
  * Second approach.
  * We know that we have to construct a binary search tree and in a BST we know that all the elements
  * on the left subtree is less than the root and all the elements on the right subtree is more than root.
  * So base case is if at any point the preorder value at i is more than the bound we return NULL.
  * Else we create a node with preorder value at i.
  * Recursively call for i + 1 and join it to the left.
  * Another recursively call for i + 1 and join it to the left.
  * We make sure we are taking the address of i so that the increment in the value of i is global.
  * Time Complexity: O(n).
  * Space Complexity: O(n) -> auxiliary space.
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

// By constructing the inorder traversal.
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd)
        return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (root->val == inorder[i])
            break;
    }
    root->left = helper(preorder, inorder, preStart + 1, inStart, i - 1);
    root->right = helper(preorder, inorder, preStart + i - inStart + 1, i + 1, inEnd);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    return helper(preorder, inorder, 0, 0, inorder.size() - 1);
}

// By having a bound to the check for left and right subtree.
TreeNode* helper(vector<int>& preorder, int& i, int bound) {
    if (i >= preorder.size() || preorder[i] > bound)
        return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return helper(preorder, i, INT_MAX);
}