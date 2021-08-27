/**
  * The capacity is the number of node that can be put in the tree. The initial value is 1, which means there can be a root.
  * When adding a node, capacity--.
  * When adding a non-NULL node, it means we obtains two more leafs, then capacity +=2.
  * The final capacity should be equal to 0.
  * Time Complexity: O(n).
  * Space Complexity: O(1).
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

bool isValidSerialization(string preorder) {
    if (preorder.empty())
        return false;
    preorder += ',';
    int x = 0, flag = 1;
    for (int i = 0; i < preorder.length(); i++) {
        if (preorder[i] != ',')
            continue;
        flag--;
        if (flag < 0)
            return false;
        if (preorder[i - 1] != '#')
            flag += 2;
    }
    return flag == 0;
}