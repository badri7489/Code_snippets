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

// Recursive Method using Map.
// Keeping track of the levels.
map<int, pair<int, int>> mp;
void helper(TreeNode* root, int dist, int level) {
    if (!root)
        return;
    if (mp.find(dist) == mp.end())
        mp[dist] = make_pair(root->val, level);
    else {
        pair<int, int> p = mp[dist];
        if (p.second <= level) {
            mp[dist].second = level;
            mp[dist].first = root->val;
        }
    }
    helper(root->left, dist - 1, level + 1);
    helper(root->right, dist + 1, level + 1);
}
vector <int> bottomView(TreeNode* root) {
    helper(root, 0, 0);
    vector<int> ans;
    for (auto it : mp)
        ans.push_back(it.second.first);
    return ans;
}

// Iterative Method using Map and Queue.
// Level Order Traversal.
vector <int> bottomView(TreeNode* root) {
    map<int, int> mp;
    vector<int> ans;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* p = q.front().first;
            int dist = q.front().second;
            q.pop();
            mp[dist] = p->val;
            if (p) {
                if (p->left)
                    q.push(make_pair(p->left, dist - 1));
                if (p->right)
                    q.push(make_pair(p->right, dist + 1));
            }
        }
    }
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}