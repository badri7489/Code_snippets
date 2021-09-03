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

// Code Not Right, Please Check.
void helper(TreeNode* a, TreeNode* b, vector<int>& ans) {
    if (a || b) {
        a = a ? a->left : NULL;
        b = b ? b->left : NULL;
        helper(a, b, ans);
        if (a && b) {
            if (a->val < b->val) {
                ans.push_back(a->val);
                a = a->right;
            } else if (a->val > b->val) {
                ans.push_back(b->val);
                b = b->right;
            } else {
                ans.push_back(a->val);
                ans.push_back(b->val);
                a->right;
                b->right;
            }
        } else if (a) {
            ans.push_back(a->val);
            a = a->right;
        } else {
            ans.push_back(b->val);
            b = b->right;
        }
        helper(a, b, ans);
    }
}
vector<int> merge(TreeNode* root1, TreeNode* root2) {
    vector<int> ans;
    helper(root1, root2, ans);
    return ans;
}

// Iterative Approach Using Stack, using inorder traversal.
vector<int> merge(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> stk1, stk2;
    vector<int> ans;
    TreeNode* curr1 = root1, * curr2 = root2;
    bool flag1 = true, flag2 = true;    // To check if any one of the bst has reached the leftmost or not.
    while (!stk1.empty() || !stk2.empty() || curr1 || curr2) {
        while (curr1 && flag1) {
            stk1.push(curr1);
            curr1 = curr1->left;
        }
        while (curr2 && flag2) {
            stk2.push(curr2);
            curr2 = curr2->left;
        }
        if (!stk1.empty() && !curr1) {
            curr1 = stk1.top();
            stk1.pop();
        }
        if (!stk2.empty() && !curr2) {
            curr2 = stk2.top();
            stk2.pop();
        }
        if (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                ans.push_back(curr1->val);
                flag1 = true;
                flag2 = false;
                curr1 = curr1->right;
            } else if (curr1->val > curr2->val) {
                ans.push_back(curr2->val);
                flag1 = false;
                flag2 = true;
                curr2 = curr2->right;
            } else {
                ans.push_back(curr1->val);
                ans.push_back(curr2->val);
                flag1 = true;
                flag2 = true;
                curr1 = curr1->right;
                curr2 = curr2->right;
            }
        } else if (curr1) {
            ans.push_back(curr1->val);
            flag1 = true;
            flag2 = false;
            curr1 = curr1->right;
        } else if (curr2) {
            ans.push_back(curr2->val);
            flag1 = false;
            flag2 = true;
            curr2 = curr2->right;
        }
    }
    return ans;
}