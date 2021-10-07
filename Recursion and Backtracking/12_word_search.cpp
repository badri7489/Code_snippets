#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool helper(vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int pos, int row, int col) {
    if (pos == word.length())
        return true;
    if (pos == 0) {
        for (int i = row; i < board.size(); i++) {
            for (int j = col; j < board[i].size(); j++) {
                if (word[pos] == board[i][j]) {
                    vis[i][j] = 1;
                    if (helper(board, vis, word, pos + 1, i, j))
                        return true;
                    vis[i][j] = 0;
                }
            }
        }
    }
    if (row + 1 < board.size() && board[row + 1][col] == word[pos] && !vis[row + 1][col]) {
        vis[row + 1][col] = 1;
        if (helper(board, vis, word, pos + 1, row + 1, col))
            return true;
        vis[row + 1][col] = 0;
    }
    if (row - 1 < board.size() && board[row - 1][col] == word[pos] && !vis[row - 1][col]) {
        vis[row - 1][col] = 1;
        if (helper(board, vis, word, pos + 1, row - 1, col))
            return true;
        vis[row - 1][col] = 0;
    }
    if (col + 1 < board[row].size() && board[row][col + 1] == word[pos] && !vis[row][col + 1]) {
        vis[row][col + 1] = 1;
        if (helper(board, vis, word, pos + 1, row, col + 1))
            return true;
        vis[row][col + 1] = 0;
    }
    if (col - 1 < board[row].size() && board[row][col - 1] == word[pos] && !vis[row][col - 1]) {
        vis[row][col - 1] = 1;
        if (helper(board, vis, word, pos + 1, row, col - 1))
            return true;
        vis[row][col - 1] = 0;
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
    return helper(board, vis, word, 0, 0, 0);
}

// A bit compact and good looking code(I guess)
class Solution {
private:
    vector<vector<int>> vis;
    vector<int> x_points = { 0, 1, 0, -1 };
    vector<int> y_points = { 1, 0, -1, 0 };
    bool isValid(int x, int y) {
        return x >= 0 && x < vis.size() && y >= 0 && y < vis[0].size();
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size())
            return true;
        vis[i][j] = 1;
        int x, y;
        for (int k = 0; k < 4; k++) {
            x = i + x_points[k], y = j + y_points[k];
            if (isValid(x, y) && !vis[x][y] && board[x][y] == word[index]) {
                if (dfs(board, word, x, y, index + 1))
                    return true;
                vis[x][y] = 0;
            }
        }
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vis.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == word[0] && dfs(board, word, i, j, 1))
                    return true;
            }
        }
        return false;
    }
};