#include<iostream>
#include<set>
#include<vector>
using namespace std;

class trieNode {
public:
    int isLeaf;
    vector<trieNode*> child;
    trieNode() {
        isLeaf = false;
        child = vector<trieNode*>(26, NULL);
    }
};

class trie {
private:
    trieNode* root;
public:
    trieNode* getRoot() {
        return root;
    }
    trie(vector<string>& words) {
        root = new trieNode();
        for (string& s : words)
            addWord(s);
    }
    void addWord(string word) {
        trieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!curr->child[index])
                curr->child[index] = new trieNode();
            curr = curr->child[index];
        }
        curr->isLeaf = true;
    }
};

class Solution {
private:
    void helper(vector<vector<char>>& board, int x, int y, trieNode* root, string word, set<string>& ans) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ')
            return;
        if (root->child[board[x][y] - 'a']) {
            word += board[x][y];
            root = root->child[board[x][y] - 'a'];
            if (root->isLeaf)
                ans.insert(word);
            char c = board[x][y];
            board[x][y] = ' ';
            helper(board, x + 1, y, root, word, ans);
            helper(board, x - 1, y, root, word, ans);
            helper(board, x, y + 1, root, word, ans);
            helper(board, x, y - 1, root, word, ans);
            board[x][y] = c;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie* t = new trie(words);
        trieNode* root = t->getRoot();
        set<string> res;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                helper(board, i, j, root, "", res);
        vector<string> ans;
        for (auto it : res)
            ans.push_back(it);
        return ans;
    }
};