#include<iostream>
#include<vector>
using namespace std;

// Bottom Up DP approach.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = m - 2; i >= 0; i--) {
            mat[i][0] += min(mat[i + 1][0], mat[i + 1][1]); // 0th index case handled.
            mat[i][n - 1] += min(mat[i + 1][n - 1], mat[i + 1][n - 2]); // (n - 1)th index case handled.
            for (int j = 1; j < n - 1; j++) // Rest of the elements are filled.
                mat[i][j] += min(mat[i + 1][j], min(mat[i + 1][j - 1], mat[i + 1][j + 1]));
        }
        int ans = INT32_MAX;
        for (int i = 0; i < n; i++) // Find the minimum of all the elements on the first row.
            ans = min(ans, mat[0][i]);
        return ans;
    }
};