#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '1')
            return;
        if (board[i][j] == 'O')
            board[i][j] = '1';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        if (!row)
            return;
        // Check for the first and last column
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1);
        }
        // Check for the first and last row
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[row - 1][j] == 'O')
                dfs(board, row - 1, j);
        }
        // Flipping 'O' to 'X' and '1' to 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};