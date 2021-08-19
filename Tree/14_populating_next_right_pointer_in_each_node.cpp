#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right, TreeNode* next) : val(x), left(left), right(right), next(next) {}
};

// Using a queue.
// Same as Level Order Traversal is done.
TreeNode* connect(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp) {
            temp->next = q.front();
            q.push(temp->left);
            q.push(temp->right);
        }
        if (!q.front()) {
            q.push(NULL);
        }
    }
    return root;
}

// Constant Space Solution.
// Uses the previous level as a Linked List.
TreeNode* connect(TreeNode* root) {
    TreeNode* head = root;
    while (head) {
        TreeNode* nextLevelHead = new TreeNode(0);
        TreeNode* temp = nextLevelHead;
        while (head) {
            if (head->left) {
                temp->next = head->left;
                temp = temp->next;
            }
            if (head->right) {
                temp->next = head->right;
                temp = temp->next;
            }
            head = head->next;
        }
        head = nextLevelHead->next;
    }
    return root;
}