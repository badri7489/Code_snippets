#include<iostream>
#include<vector>
using namespace std;

// My solution
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        int row = 0, col = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row < r && col < c) {   // Simply assign.
                    ans[row][col++] = mat[i][j];
                } else if (row == r && col == c) {  // When we reach the end of the new matrix.
                    return ans;
                } else if (col == c) {  // When we reach the end of a column.
                    ++row, col = 0; // Go to new row and column starts from 0.
                    ans[row][col++] = mat[i][j];    // Assign and move ahead.
                }
            }
        }
        return ans;
    }
};

// Better Solution
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r * c; i++)
            ans[i / c][i % c] = mat[i / n][i % n];  // Directly accessing index using a bit maths and mod operator.
        return ans;
    }
};