#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
    int n;

    bool isSafe(int row, int col) {
        int i = row, j = col;
        while (i >= 0 && j >= 0) {  // Check the upper left diagonal
            if (board[i--][j--] == 'Q')
                return false;
        }
        i = row, j = col;
        while (j >= 0) {    // Check the left side, in that row
            if (board[i][j--] == 'Q')
                return false;
        }
        j = col;
        while (i < n && j >= 0) {   // Check the lower left diagonal
            if (board[i++][j--] == 'Q')
                return false;
        }
        return true;
    }

    void helper(int cols) {
        if (cols == n) {    // Base condition reached
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(i, cols)) {
                board[i][cols] = 'Q';
                helper(cols + 1);
                board[i][cols] = '.';   // Backtracking steps
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int sz) {
        n = sz;
        board.resize(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        helper(0);
        return ans;
    }
};

// Optimal Code
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> leftRow;
    vector<int> upperDiagonal;
    vector<int> lowerDiagonal;
    int n;

    void helper(int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + row - col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + row - col] = 1;
                helper(col + 1);
                board[row][col] = '.';
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + row - col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int sz) {
        n = sz;
        board.resize(n);
        leftRow.resize(n, 0);
        upperDiagonal.resize(2 * n - 1, 0);
        lowerDiagonal.resize(2 * n - 1, 0);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        helper(0);
        return ans;
    }
};
