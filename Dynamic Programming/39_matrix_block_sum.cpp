#include<iostream>
#include<vector>
using namespace std;

// Brute Force Solution.
// Going through all of them and individually calculation for all of them.
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = max(0, i - k); p <= min(m - 1, i + k); p++) {
                    for (int q = max(0, j - k); q <= min(n - 1, j + k); q++)
                        ans[i][j] += mat[p][q];
                }
            }
        }
        return ans;
    }
};

// Using a prefix sum 2D array.
// Each point in the prefix sum array contains the sum of all the values uptil that point in the matrix.
// Go to this link for better understanding.
// https://computersciencesource.wordpress.com/2010/09/03/computer-vision-the-integral-image/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> rangeSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + mat[i][j];
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m, i + k + 1), c2 = min(n, j + k + 1);
                ans[i][j] = rangeSum[r2][c2] - rangeSum[r2][c1] - rangeSum[r1][c2] + rangeSum[r1][c1];
            }
        }
        return ans;
    }
};