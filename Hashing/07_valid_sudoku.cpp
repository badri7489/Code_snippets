/**
  * Visualisation of k
  * 0  0  0 | 1  1  1 | 2  2  2
  * 0  0  0 | 1  1  1 | 2  2  2
  * 0  0  0 | 1  1  1 | 2  2  2
  * ------- + -------- +--------
  * 3  3  3 | 4  4  4 | 5  5  5
  * 3  3  3 | 4  4  4 | 5  5  5
  * 3  3  3 | 4  4  4 | 5  5  5
  * ------- + -------- +--------
  * 6  6  6 | 7  7  7 | 8  8  8
  * 6  6  6 | 7  7  7 | 8  8  8
  * 6  6  6 | 7  7  7 | 8  8  8
  */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Map for storing if any value has been there or not in a row, col or in a 3x3 box.
        int col[9][9] = { 0 }, row[9][9] = { 0 }, subBox[9][9] = { 0 };
        int num, k;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3; // Calculating the index for 3x3 box
                    if (row[i][num] || col[j][num] || subBox[k][num])
                        return false;
                    row[i][num] = col[j][num] = subBox[k][num] = 1;
                }
            }
        }
        return true;
    }
};