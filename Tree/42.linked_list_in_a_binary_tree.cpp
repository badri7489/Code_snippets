#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};