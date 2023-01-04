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

class Solution {
private:
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        markParents(root, mp);
        vector<int> ans;
        map<int, int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target->val] = 1;
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            if (distance++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis[node->left->val]) {
                    q.push(node->left);
                    vis[node->left->val] = 1;
                }
                if (node->right && !vis[node->right->val]) {
                    q.push(node->right);
                    vis[node->right->val] = 1;
                }
                if (mp[node] && !vis[mp[node]->val]) {
                    q.push(mp[node]);
                    vis[mp[node]->val] = 1;
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};