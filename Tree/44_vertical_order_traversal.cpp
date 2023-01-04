#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;        // x, y, {values, in multiset because it might be similar}
        queue<pair<TreeNode*, pair<int, int>>> todo;    // node, x, y
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            // x - vertical, y - horizontal
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
                todo.push({node->left, {x - 1, y + 1}});    // x decreases by 1, y increases by 1
            if (node->right)
                todo.push({node->right, {x + 1, y + 1}});   // x increases by 1, y increases by 1
        }
        vector<vector<int>> ans;
        for (auto p: nodes) {
            vector<int> temp;
            for (auto q: p.second) {
                temp.insert(temp.end(), q.second.begin(), q.second.end());  // inserting at the end of the vector
            }
            ans.push_back(temp);
        }
        return ans;
    }
};