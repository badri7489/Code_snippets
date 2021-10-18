#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Recursive Solution
class Solution {
private:
    void helper(Node* root, vector<int>& ans) {
        if (root) {
            ans.push_back(root->val);
            for (auto& it : root->children)
                helper(it, ans);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// Iterative Solution
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<Node*> stk;
        Node* curr;
        stk.push(root);
        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            for (int i = curr->children.size() - 1; i >= 0; i--)
                stk.push(curr->children[i]);
        }
        return ans;
    }
};