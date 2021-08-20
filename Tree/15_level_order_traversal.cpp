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

// Using q.size() to check the level.
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* p = q.front();
            q.pop();
            if (p) {
                temp.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        if (temp.size() > 0)
            ans.push_back(temp);
    }
    return ans;
}

// Using NULL as a flag to change level.
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<int> temp;
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            temp.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        } else if (q.front()) {
            q.push(NULL);
            ans.push_back(temp);
            temp.clear();
        }
        if (!curr && !q.front())
            break;
    }
    return ans;
}