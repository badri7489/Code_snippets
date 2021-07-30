#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n) {
    int i = row, j = col;
    while (j >= 0) {
        if (board[i][j--] == 'Q')
            return false;
    }
    j = col;
    while (j >= 0 && i >= 0) {
        if (board[i--][j--] == 'Q')
            return false;
    }
    i = row, j = col;
    while (i < n && j >= 0) {
        if (board[i++][j--] == 'Q')
            return false;
    }
    return true;
}

void helper(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            helper(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    helper(0, board, ans, n);
    return ans;
}

// Optimal Code
void helper(int col, vector<string>& board, vector<vector<string>>& ans, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + row - col] == 0) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + row - col] = 1;
            helper(col + 1, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + row - col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    for (int i = 0; i < n; i++)
        board[i] = s;
    helper(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
    return ans;
}
