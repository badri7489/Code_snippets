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