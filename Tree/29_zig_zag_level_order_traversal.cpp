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

// Using level order traversal and reverse function.
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr;
    int i, flag = -1;
    while (!q.empty()) {
        vector<int> temp;
        i = q.size();
        flag++;
        while (!q.empty() && i--) {
            curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (flag % 2)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
    }
    return ans;
}

// Using level order traversal and without reverse function, but using reverse indexing.
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    TreeNode* curr;
    int flag = 1, size, index;
    while (!nodesQueue.empty()) {
        size = nodesQueue.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++) {
            curr = nodesQueue.front();
            nodesQueue.pop();
            index = (flag) ? i : size - i - 1;
            temp[index] = curr->val;
            if (curr->left)
                nodesQueue.push(curr->left);
            if (curr->right)
                nodesQueue.push(curr->right);
        }
        flag = !flag;
        ans.push_back(temp);
    }
    return ans;
}

// Using Deque
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
        return {};
    vector<vector<int>> ans;
    deque<TreeNode*> queueNodes;
    queueNodes.push_back(root);
    TreeNode* curr;
    int dir = 0, size;
    while (!queueNodes.empty()) {
        size = queueNodes.size();
        vector<int> temp;
        while (size--) {
            if (dir) {
                curr = queueNodes.back();
                queueNodes.pop_back();
                temp.push_back(curr->val);
                if (curr->right)
                    queueNodes.push_front(curr->right);
                if (curr->left)
                    queueNodes.push_front(curr->left);
            } else {
                curr = queueNodes.front();
                queueNodes.pop_front();
                temp.push_back(curr->val);
                if (curr->left)
                    queueNodes.push_back(curr->left);
                if (curr->right)
                    queueNodes.push_back(curr->right);
            }
        }
        dir = 1 - dir;
        ans.push_back(temp);
    }
    return ans;
}